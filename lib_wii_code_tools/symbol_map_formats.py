import enum
import io
import json
import re
from typing import ClassVar, Dict, List, Optional, TextIO, Tuple

from .nsmbw_constants import Permissions


KAMEK_LINKER_SCRIPT_EPILOGUE = """
    .text : {
        FILL (0)

        __text_start = . ;
        *(.init)
        *(.text)
        __ctor_loc = . ;
        *(.ctors)
        __ctor_end = . ;
        *(.dtors)
        *(.rodata)
        /**(.sdata)*/
        *(.data)
        /**(.sbss)*/
        *(.bss)
        *(.fini)
        *(.rodata.*)
        __text_end  = . ;
    }
"""


BasicSymbolMap = Dict[int, str]


def _categorize_symbols_as_functions_or_labels(map: BasicSymbolMap, sections_info: List[dict]) -> Tuple[BasicSymbolMap, BasicSymbolMap]:
    """
    Try to classify each symbol in the map as being either a function
    or a label. This is determined by whether it lies in an executable
    region or a data region. (This isn't a perfect metric, but it's OK).
    If a symbol is in both or neither, a warning is printed, and it
    defaults to the "labels" category.
    sections_info: list of dicts (one per section) containing keys:
    - 'address' (int)
    - 'size' (int)
    - 'permissions' (nsmbw_constants.Permissions)
    Returns two maps: the function symbols, and the label symbols.
    """
    executable_regions = set()
    data_regions = set()
    for section in sections_info:
        address_range = range(section['address'], section['address'] + section['size'])
        if section['permissions'] & Permissions.X:
            executable_regions.add(address_range)
        else:
            data_regions.add(address_range)

    function_symbols = {}
    label_symbols = {}

    for addr, name in map.items():
        is_function = any(addr in region for region in executable_regions)
        is_data = any(addr in region for region in data_regions)

        if is_function and is_data:
            print(f'WARNING: "{name}" ({addr:08x}) seems to be both a function and a label -- are there overlapping sections? (Defaulting to label)')
            is_function, is_data = False, True
        elif not is_function and not is_data:
            print(f'WARNING: Unable to determine if "{name}" ({addr:08x}) is a function or a label -- does it lie outside of all sections, or in a section with unknown executability? (Defaulting to label)')
            is_function, is_data = False, True

        if is_function:
            function_symbols[addr] = name
        else:
            label_symbols[addr] = name

    return function_symbols, label_symbols



class SymbolMap:
    """
    Base class for all symbol map types. Since their semantics vary a lot,
    this only includes stuff that's sure to be useful for all of them
    (which isn't much)
    """
    LOADABLE: ClassVar[bool] = False
    EXTENSION: ClassVar[Optional[str]] = None  # override if .txt or .map would be wrong -- e.g. '.idc'

    @classmethod
    def load(cls, f: TextIO) -> 'SymbolMap':
        """
        Read from a file-like object
        """
        raise NotImplementedError


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'SymbolMap':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: list of dicts giving info about each section.
        The exact keys that are required vary depending on subclass.
        """
        raise NotImplementedError


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Convert to a simple {address: 'name'} dict
        """
        raise NotImplementedError


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        raise NotImplementedError


    @classmethod
    def autodetect(cls, f: TextIO) -> bool:
        """
        Try to infer if the file is in this symbol map format or not
        """
        try:
            cls.load(f)
        except Exception:
            return False
        return True


    def __str__(self)-> str:
        sio = io.StringIO()
        self.write(sio)
        sio.seek(0)
        return sio.read()



class JSONSymbolMap(SymbolMap):
    """
    Represents a symbol map in a simple JSON format
    """
    LOADABLE = True
    EXTENSION = '.json'

    symbols: BasicSymbolMap  # {address: name}

    def __init__(self):
        self.symbols = {}


    @classmethod
    def load(cls, f: TextIO) -> 'JSONSymbolMap':
        """
        Read from a file-like object
        """
        self = cls()
        self.symbols = {int(a, 0): n for (a, n) in json.load(f).items()}
        return self


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'JSONSymbolMap':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: ignored
        """
        self = cls()
        self.symbols = map
        return self


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Return all symbols in an {address: name} dict format
        """
        return self.symbols


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        json.dump({f'0x{addr:08X}': name for addr, name in self.symbols.items()}, f, indent=4)



class IDASymbolMap(SymbolMap):
    """
    Represents a symbol map in the format used by exports from IDA
    """
    LOADABLE = True

    sections: list  # [(segment, offset, length, name, SectionClass_or_None), ...]
    symbols: list  # [(segment, offset, name), ...]

    class SectionClass(enum.Enum):
        CODE = 'CODE'
        DATA = 'DATA'
        BSS = 'BSS'


    def __init__(self):
        self.sections = []
        self.symbols = []


    @classmethod
    def load(cls, f: TextIO) -> 'IDASymbolMap':
        """
        Read from a file-like object
        """
        self = cls()

        header_start_regex = re.compile(
            r'Start'                          # "Start"
            r'\s+'                            # whitespace
            r'Length'                         # "Length"
            r'\s+'                            # whitespace
            r'Name'                           # "Name"
            r'\s+'                            # whitespace
            r'Class'                          # "Class"
        )
        header_line_regex = re.compile(
            r'\s*'                            # optional leading whitespace
            r'([a-fA-F0-9]+):([a-fA-F0-9]+)'  # "0123:456789AB"
            r'\s+'                            # whitespace
            r'([a-fA-F0-9]+)H'                # "012345678H"
            r'\s+'                            # whitespace
            r'(\S+)'                          # ".text"
            r'(?:'                            # (start of optional "class" column)
            r'\s+'                            # whitespace
            r'((?:CODE)|(?:DATA)|(?:BSS))'    # "CODE"|"DATA"|"BSS"
            r')?'                             # (end of optional "class" column)
        )
        symbol_line_regex = re.compile(
            r'\s*'                            # optional leading whitespace
            r'([a-fA-F0-9]+):([a-fA-F0-9]+)'  # "0123:456789AB"
            r'\s+'                            # whitespace
            r'(\S+)'                          # symbol name
        )

        reading_header = True
        for line in f:
            line = line.strip()
            if not line: continue

            if reading_header:
                if header_start_regex.fullmatch(line):
                    continue

                match = header_line_regex.fullmatch(line)
                if match:
                    segment = int(match[1], 16)
                    offset = int(match[2], 16)
                    size = int(match[3], 16)
                    name = match[4]
                    if match[5] is None:
                        class_ = None
                    else:
                        class_ = cls.SectionClass(match[5])
                    self.sections.append((segment, offset, size, name, class_))

                elif line == 'Address         Publics by Value':
                    reading_header = False
                    continue

                elif symbol_line_regex.fullmatch(line):
                    reading_header = False
                    # don't continue -- fall through and read this line

                else:
                    raise ValueError(f'Unexpected header line: "{line}"')

            if not reading_header:
                match = symbol_line_regex.fullmatch(line)
                segment = int(match[1], 16)
                offset = int(match[2], 16)
                name = match[3]
                self.symbols.append((segment, offset, name))

        return self


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Convert to a simple {address: 'name'} dict
        """
        return {a: n for (s, a, n) in self.symbols}


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'IDASymbolMap':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: list of dicts (one per section) containing keys:
        - 'name' (str)
        - 'address' (int)
        - 'size' (int)
        - 'class' (SectionClass)
        """
        self = cls()

        for section in sorted(sections_info, key=lambda s: s['address']):
            self.sections.append((0, section['address'], section['size'], section['name'], section['class']))

        for addr, name in sorted(map.items()):
            self.symbols.append((0, addr, name))

        return self


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        f.write('\n')
        f.write(' Start         Length     Name                   Class\n')

        for segment, offset, length, name, class_ in self.sections:
            class_name = '' if class_ is None else class_.value
            line = f' {segment:04X}:{offset:08X} {length:09X}H {name:22} {class_name}'.rstrip()
            f.write(f'{line}\n')

        f.write('\n')
        f.write('\n')
        f.write('  Address         Publics by Value\n')
        f.write('\n')

        for segment, addr, name in self.symbols:
            f.write(f' {segment:04X}:{addr:08X}       {name}\n')



class IDASymbolMap_IDC(SymbolMap):
    """
    An .idc file that can be used to import symbols into IDA.
    Since .idc is an actual scripting format, this class only supports
    exporting and not importing.
    """
    EXTENSION = '.idc'

    symbols: list  # [(address, name, is_function), ...]
    force_gcc3_demangling: bool

    def __init__(self):
        self.symbols = []
        self.force_gcc3_demangling = False


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Convert to a simple {address: 'name'} dict
        """
        return {a: n for (a, n, i_f) in self.symbols}


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'IDASymbolMap_IDC':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: list of dicts (one per section) containing keys:
        - 'address' (int)
        - 'size' (int)
        - 'permissions' (nsmbw_constants.Permissions)
        """
        self = cls()

        function_symbols, label_symbols = _categorize_symbols_as_functions_or_labels(map, sections_info)

        for addr, name in function_symbols.items():
            self.symbols.append((addr, name, True))
        for addr, name in label_symbols.items():
            self.symbols.append((addr, name, False))

        self.symbols.sort(key=lambda item: item[0])

        return self


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        f.write('#include <idc.idc>\n')
        f.write('\n')
        f.write('static main(void) {\n')

        if self.force_gcc3_demangling:
            f.write('    // Force-enable "Options -> Demangled names... -> Assume GCC v3.x names" checkbox\n')
            f.write('    set_inf_attr(INF_DEMNAMES, get_inf_attr(INF_DEMNAMES) | DEMNAM_GCC3);\n\n')

        for addr, name, is_function in self.symbols:
            if is_function:
                f.write(f'    add_func(0x{addr:08X}, BADADDR);')
            else:
                f.write(' ' * 34)
            f.write(f' set_name(0x{addr:08X}, "{repr(name)[1:-1]}");\n')

        f.write('}\n')



class GhidraSymbolsScript(SymbolMap):
    """
    Represents a "symbols script" Ghidra can import
    (Window -> Scripts Manager -> ImportSymbolsScript.py)
    """
    LOADABLE = True

    symbols: list  # [(name, address, SymbolType), ...]

    class SymbolType(enum.Enum):
        FUNCTION = 'f'
        LABEL = 'l'


    def __init__(self):
        self.symbols = []


    @classmethod
    def load(cls, f: TextIO) -> 'GhidraSymbolsScript':
        """
        Read from a file-like object
        """
        self = cls()

        symbol_line_regex = re.compile(
            r'^'                 # (start of string)
            r'(\S+)'             # symbol name
            r'\s+'               # whitespace
            r'0x([a-fA-F0-9]+)'  # 0xADDRESS
            r'\s+'               # whitespace
            r'([lf])'            # "l"|"f"
        )

        for line in f:
            line = line.rstrip('\n')
            if not line: continue

            match = symbol_line_regex.match(line)
            name = match[1]
            address = int(match[2], 16)
            sym_type = cls.SymbolType(match[3])

            self.symbols.append((name, address, sym_type))

        return self


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Convert to a simple {address: 'name'} dict
        """
        return {a: n for (n, a, t) in self.symbols}


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'GhidraSymbolsScript':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: list of dicts (one per section) containing keys:
        - 'address' (int)
        - 'size' (int)
        - 'permissions' (nsmbw_constants.Permissions)
        """
        self = cls()

        function_symbols, label_symbols = _categorize_symbols_as_functions_or_labels(map, sections_info)

        for addr, name in function_symbols.items():
            self.symbols.append((name, addr, self.SymbolType.FUNCTION))
        for addr, name in label_symbols.items():
            self.symbols.append((name, addr, self.SymbolType.LABEL))

        self.symbols.sort(key=lambda item: item[1])

        return self


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        COLUMN_2 = 32
        COLUMN_3 = 48

        for name, addr, sym_type in self.symbols:

            line = name
            line += ' ' * max(COLUMN_2 - len(line), 1)
            line += f'0x{addr:08X}'
            line += ' ' * max(COLUMN_3 - len(line), 1)
            line += sym_type.value

            f.write(line + '\n')



class LinkerScriptMap(SymbolMap):
    """
    Represents a .x symbol map type
    """
    EXTENSION = '.x'

    symbols: list  # [(name, address), ...]
    epilogue: str

    def __init__(self):
        self.symbols = []
        self.epilogue = ''


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Convert to a simple {address: 'name'} dict
        """
        return {a: n for (n, a) in self.symbols}


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'LinkerScriptMap':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: ignored
        """
        self = cls()

        for addr, name in sorted(map.items()):
            self.symbols.append((name, addr))

        return self


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        f.write('SECTIONS {\n')

        for name, address in self.symbols:
            f.write(f'    {name} = 0x{address:08X};\n')

        f.write(self.epilogue); f.write('\n')

        f.write('}\n')



class DolphinSymbolMap(SymbolMap):
    """
    Represents a Dolphin Emulator symbol map
    """
    LOADABLE = True

    sections: list  # [(name, [(phys_address, size, virt_address, alignment, name), ...]), ...]


    def __init__(self):
        self.sections = []


    @classmethod
    def load(cls, f: TextIO) -> 'DolphinSymbolMap':
        """
        Read from a file-like object
        """
        self = cls()

        DEFAULT_SECTION_NAME = ''

        section_header_regex = re.compile(
            r'(\S+)'            # ".text"
            r' section layout'  # " section layout"
        )
        symbol_line_regex_no_dol_offset = re.compile(
            r'^'               # (start of string)
            r'\s*'             # optional leading whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'(\d+)'           # decimal number
            r'\s+'             # whitespace
            r'(\S+)'           # symbol name
        )
        symbol_line_regex_with_dol_offset = re.compile(
            r'^'               # (start of string)
            r'\s*'             # optional leading whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'([a-fA-F0-9]+)'  # hex number
            r'\s+'             # whitespace
            r'(\d+)'           # decimal number
            r'\s+'             # whitespace
            r'(\S+)'           # symbol name
        )

        current_section_name = None
        current_section = []
        for line in f:
            line = line.rstrip('\n')
            if not line: continue

            match = section_header_regex.fullmatch(line)
            if match:
                section_name = match[1]

                if current_section_name is not None:
                    self.sections.append((current_section_name, current_section))

                current_section_name = section_name
                current_section = []
                continue

            if match := symbol_line_regex_no_dol_offset.match(line):
                phys_address = int(match[1], 16)
                size = int(match[2], 16)
                virt_address = int(match[3], 16)
                alignment = int(match[4])
                name = match[5]

                if current_section_name is None:
                    print(f'WARNING: "{name}" doesn\'t belong to any section')
                    current_section_name = DEFAULT_SECTION_NAME

                current_section.append((phys_address, size, virt_address, alignment, name))

            # This technically isn't part of Dolphin's symbol map
            # format, but Dolphin's map format is based on
            # CodeWarrior's, and the CodeWarrior maps in Super Mario
            # Galaxy for Nvidia Shield use this slight variation
            elif match := symbol_line_regex_with_dol_offset.match(line):
                phys_address = int(match[1], 16)
                size = int(match[2], 16)
                virt_address = int(match[3], 16)
                dol_offset = int(match[4], 16)  # we ignore this
                alignment = int(match[5])
                name = match[6]

                if current_section_name is None:
                    print(f'WARNING: "{name}" doesn\'t belong to any section')
                    current_section_name = DEFAULT_SECTION_NAME

                current_section.append((phys_address, size, virt_address, alignment, name))

            else:
                raise ValueError(f'Can\'t parse line: "{line}"')

        if current_section_name is not None:
            self.sections.append((current_section_name, current_section))

        return self


    def to_symbol_dict(self) -> BasicSymbolMap:
        """
        Convert to a simple {address: 'name'} dict
        """
        new_symbols = {}
        for section_name, section_symbols in self.sections:
            for pa, s, va, a, n in section_symbols:
                new_symbols[pa] = n
        return new_symbols


    @classmethod
    def from_dict_and_sections_info(cls, map: BasicSymbolMap, sections_info: List[dict]) -> 'DolphinSymbolMap':
        """
        Load from objects in memory, rather than from a file object.
        map: {address: 'name'}
        sections_info: list of dicts (one per section) containing keys:
        - 'name' (str)
        - 'address' (int)
        - 'size' (int)
        """
        self = cls()

        DEFAULT_SECTION_NAME = '.unknown'

        sections_info = sorted(sections_info, key=lambda s: s['address'])

        # First: populate a {name: symbols_list, ...} dict
        self_sections_dict = {}

        for addr, name in sorted(map.items()):
            for section in sections_info:
                if section['address'] <= addr < section['address'] + section['size']:
                    section_name = section['name']
                    break
            else:

                section_name = DEFAULT_SECTION_NAME

            if section_name not in self_sections_dict:
                self_sections_dict[section_name] = []
            section_list = self_sections_dict[section_name]

            section_list.append((addr, 0, addr, 0, name))

        # Now convert that to a [(name, symbols_list), ...] list
        for name, L in sorted(self_sections_dict.items(), key=lambda item: item[1][0][0]):  # sort by section's first address
            self.sections.append((name, L))

        return self


    def write(self, f: TextIO) -> None:
        """
        Write to a file-like object
        """
        for section_name, symbols in self.sections:
            f.write(f'{section_name} section layout\n')

            for phys_address, size, virt_address, alignment, name in symbols:
                f.write(f'{phys_address:08x} {size:08x} {virt_address:08x} {alignment} {name}\n')

            f.write('\n')



FORMAT_CLASSES = {
    'json': JSONSymbolMap,
    'ida': IDASymbolMap,
    'idc': IDASymbolMap_IDC,
    'ghidra': GhidraSymbolsScript,
    'linker': LinkerScriptMap,
    'dolphin': DolphinSymbolMap,
}


def autodetect_and_load(f: TextIO) -> SymbolMap:
    """
    Auto-detect the symbol map format, and load a SymbolMap
    """
    options = set()
    for name, cls in FORMAT_CLASSES.items():
        if cls.LOADABLE:
            f.seek(0)
            if cls.autodetect(f):
                options.add(name)

    if not options:
        raise ValueError('Unrecognized symbol map format')
    elif len(options) > 1:
        raise ValueError(f'Uncertain symbol map format: could be {", ".join(options)}')

    f.seek(0)
    return FORMAT_CLASSES[next(iter(options))].load(f)


def add_map_output_arguments(parser: 'argparse.ArgumentParser', base_name, *args, **kwargs) -> None:
    """
    Add positional arguments for an output symbol map and its format.
    args.{{base_name}} will be a pathlib.Path, and
    args.{{base_name}}_format will be a SymbolMap subclass (uninstantiated).
    """
    # Lazy imports to minimize scope
    import argparse
    from pathlib import Path

    class FormatClassCastingAction(argparse.Action):
        """
        Subclass of argparse.Action that converts the value to a
        SymbolMap subclass.
        We can't use "type=" instead, because that's applied *before*
        the value is compared against "choices", resulting in stuff like
        "invalid choice: <class
          'symbol_map_formats.GhidraSymbolsScript'> (choose from
          'dolphin', 'ghidra', 'ida', 'idc', 'json', 'linker')"
        """
        def __call__(self, parser, namespace, values, option_string):
            setattr(namespace, self.dest, FORMAT_CLASSES[values])

    parser.add_argument(base_name, type=Path, *args, **kwargs)

    if 'help' in kwargs:
        kwargs['help'] += ' (file format)'

    parser.add_argument(
        base_name + '_format',
        action=FormatClassCastingAction,
        choices=sorted(FORMAT_CLASSES),
        *args, **kwargs)
