from typing import Dict, Type, Union

from . import nsmbw_constants
from . import symbol_map_formats


def auto_assign_alf_section_executability(alf: 'code_files.alf.ALF') -> None:
    """
    Automatically assign section.is_executable to each ALF
    section, assuming the ALF is NSMBW's WIIMJ2DNP.alf.
    """
    # Lazy import to minimize scope
    from .code_files import alf as code_files_alf
    if not isinstance(alf, code_files_alf.ALF): return

    for section, sec_name in zip(alf.sections, nsmbw_constants.DOL_SECTION_NAMES):
        perms = nsmbw_constants.DOL_SECTION_INFO[sec_name]['permissions']
        section.is_executable = bool(perms & nsmbw_constants.Permissions.X)


def build_nsmbw_symbol_map(
        map: symbol_map_formats.BasicSymbolMap,
        version: str,
        format: Union[str, Type[symbol_map_formats.SymbolMap]],
        *, add_kamek_linker_epilogue: bool = True,
        idc_force_gcc3_demangling: bool = True) -> symbol_map_formats.SymbolMap:
    """
    Given a NSMBW symbol map initially in {addr: name} dict form, create
    a SymbolMap instance in the indicated format by filling in
    section/executability metadata from nsmbw_constants as needed.
    "format" can be either a string name
    (symbol_map_formats.FORMAT_CLASSES key), or an uninstantiated
    SymbolMap subclass.
    """
    sections_info = []

    if isinstance(format, str):
        map_cls = symbol_map_formats.FORMAT_CLASSES[format]
    else:
        map_cls = format

    for sec_name, (addr, size) in nsmbw_constants.SECTION_ADDRESSES[version]['main'].items():
        section = {'name': sec_name, 'address': addr, 'size': size}
        section.update(nsmbw_constants.DOL_SECTION_INFO[sec_name])
        section['class'] = symbol_map_formats.IDASymbolMap.SectionClass(section['class'])
        sections_info.append(section)

    for rel_name in nsmbw_constants.REL_NAMES:
        for sec_name, (addr, size) in nsmbw_constants.SECTION_ADDRESSES[version][rel_name].items():
            section = {'name': rel_name + sec_name, 'address': addr, 'size': size}
            section.update(nsmbw_constants.REL_SECTION_INFO[sec_name])
            section['class'] = symbol_map_formats.IDASymbolMap.SectionClass(section['class'])
            sections_info.append(section)

    sections_info.sort(key=lambda entry: entry['address'])

    map_obj = map_cls.from_dict_and_sections_info(map, sections_info)

    if isinstance(map_obj, symbol_map_formats.LinkerScriptMap) and add_kamek_linker_epilogue:
        map_obj.epilogue = symbol_map_formats.KAMEK_LINKER_SCRIPT_EPILOGUE

    if isinstance(map_obj, symbol_map_formats.IDASymbolMap_IDC) and idc_force_gcc3_demangling:
        map_obj.force_gcc3_demangling = True

    return map_obj


def save_nsmbw_symbol_map(
        map: symbol_map_formats.BasicSymbolMap,
        version: str,
        format: Union[str, Type[symbol_map_formats.SymbolMap]],
        path: 'pathlib.Path',
        **kwargs) -> None:
    """
    Wrapper for build_nsmbw_symbol_map() that saves the map to a Path
    instead of returning it.
    """
    map_obj = build_nsmbw_symbol_map(map, version, format, **kwargs)

    with path.open('w', encoding='utf-8') as f:
        map_obj.write(f)
