# 2020-02-07 RoadrunnerWMC
# Based on Ninji's ALF loader for IDA

import struct
from typing import Optional

from .. import CodeFile, CodeFileSection


class ALFSection(CodeFileSection):
    """
    Represents a single section in a .alf file
    """
    def __init__(self, address: int, size: int, data: bytes):
        self.address = address
        self.size = size
        self.data = data
        self.symbols = []


class ALFSymbol:
    """
    Represents a symbol table entry from a .alf file
    """
    def __init__(self, address: int, size: int, raw_name: str, demangled_name: str, is_data: bool, unk10: Optional[int] = None):
        self.address = address
        self.size = size
        self.raw_name = raw_name
        self.demangled_name = demangled_name
        self.is_data = is_data
        self.unk10 = unk10


class ALF(CodeFile):
    """
    Represents a .alf executable file
    """
    def __init__(self, data: bytes):
        self.data = data
        sections_start_offset = self.read_header()
        symbol_table_offset = self.read_sections(sections_start_offset)
        self.read_symbol_table(symbol_table_offset)

    def read_header(self) -> int:
        """
        Read ALF header data and return the offset to the start of the
        sections table
        """
        (self.magic, self.version, self.entry_point, self.num_sections) = \
            struct.unpack_from('<4I', self.data, 0)

        # Check magic
        if self.magic != 0x464F4252:
            raise ValueError(f'ALF: Wrong magic (0x{self.magic:08x})')

        # Check for absurd amount of sections
        if not 1 <= self.num_sections < 32:
            raise ValueError(f'ALF: Unlikely number of sections ({self.num_sections})')

        # Check version
        if self.version not in {104, 105}:
            raise ValueError(f'ALF: Unknown version ({self.version})')

        return 16

    def read_sections(self, start_offset: int) -> int:
        """
        Read the sections table, and return the offset to the start of
        the symbol table
        """
        self.sections = []

        offs = start_offset
        for i in range(self.num_sections):
            address, stored_size, virtual_size = struct.unpack_from('<III', self.data, offs)
            offs += 12

            if stored_size == 0:
                section_data = None
            else:
                section_data = self.data[offs : offs + stored_size]
                offs += stored_size

            section = ALFSection(address, virtual_size, section_data)

            if not section.is_null():
                self.sections.append(section)

        return offs

    def read_symbol_table(self, start_offset: int) -> None:
        """
        Read the symbol table
        """
        offs = start_offset

        table_size, num_symbols = struct.unpack_from('<II', self.data, offs)
        offs += 4
        assert table_size == (len(self.data) - offs)  # should go to the end of the file
        offs += 4

        for i in range(num_symbols):
            raw_name_len, = struct.unpack_from('<I', self.data, offs)
            offs += 4

            raw_name = self.data[offs : offs + raw_name_len].decode('ascii')
            offs += raw_name_len

            demangled_name_len, = struct.unpack_from('<I', self.data, offs)
            offs += 4

            demangled_name = self.data[offs : offs + demangled_name_len].decode('ascii')
            offs += demangled_name_len

            address, size, is_data, section_id = struct.unpack_from('<4I', self.data, offs)
            offs += 16

            if self.version == 105:
                unk10, = struct.unpack_from('<I', self.data, offs)
                offs += 4
            else:
                unk10 = None

            symbol = ALFSymbol(address, size, raw_name, demangled_name, bool(is_data), unk10)

            section = self.sections[section_id - 1]
            assert section.address <= address and address + size <= section.address + section.size
            section.symbols.append(symbol)


extension = '.alf'
file_type = ALF
section_type = ALFSection
