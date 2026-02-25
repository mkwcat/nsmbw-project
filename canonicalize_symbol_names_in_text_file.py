#!/usr/bin/env python3

import argparse
from pathlib import Path
import re
from typing import Dict, List, Optional

from lib_wii_code_tools import common
from lib_wii_code_tools import address_maps as lib_address_maps
from lib_wii_code_tools import demangle as lib_demangle
from lib_wii_code_tools import symbol_map_formats as lib_symbol_map_formats
from lib_wii_code_tools import tweaks as lib_tweaks



def get_canonical_name_for_symbol(
        item_type: str,
        version: str,
        address: int,
        mappers: lib_address_maps.AddressMap,
        tweakers: lib_tweaks.SymbolsTweakMap,
        *,
        symbol_map_dicts: Dict[str, Dict[int, str]] = (),
        demangle: bool = False,
        default_version_name: Optional[str] = None) -> str:
    """
    Get the canonical name for the specified symbol
    """
    error_handling = lib_address_maps.UnmappedAddressHandling(
        common.ErrorVolume.SILENT,
        lib_address_maps.UnmappedAddressHandling.Behavior.DROP)

    # Step 1: can we map it to any version we have a symbol map for?
    for sym_map_version, sym_map_dict in symbol_map_dicts.items():
        mapped = lib_address_maps.map_addr_from_to(
            mappers[version], mappers[sym_map_version], address, error_handling=error_handling)
        if mapped is not None:
            sym = sym_map_dict.get(mapped)
            if sym is not None:
                if demangle:
                    return lib_demangle.demangle(sym)
                else:
                    return sym

    # Step 2: if not, let's map it backwards as far as possible
    while True:
        map_to_cross = mappers[version]
        if map_to_cross is None: break
        remapped = map_to_cross.remap_single_reverse(address, error_handling=error_handling)
        if remapped is None: break

        version = lib_address_maps.name_for_mapper(map_to_cross.base)
        address = remapped

    if version == 'default' and default_version_name is not None:
        version = default_version_name

    return f'{item_type}_{version}_{address:08x}'


def look_for_symbol_names(
        file_data: str,
        mappers: lib_address_maps.AddressMap,
        tweakers: lib_tweaks.SymbolsTweakMap,
        *,
        symbol_maps: Dict[str, lib_symbol_map_formats.SymbolMap] = (),
        demangle: bool = False,
        default_version_name: Optional[str] = None) -> None:
    """
    Perform the scan and write the output to stdout
    """
    symbol_map_dicts = {k: v.to_symbol_dict() for k, v in symbol_maps.items()}

    search_regex = re.compile(r'(FUN|DAT)_([a-zA-Z0-9]+)_([a-fA-F0-9]{8})')

    new_file_data = file_data

    already_covered = set()
    for match in search_regex.finditer(file_data):
        item_type = match.group(1)
        version = match.group(2)
        address = int(match.group(3), 16)

        current_name = match.group(0)
        if current_name in already_covered:
            continue
        already_covered.add(current_name)

        best_name = get_canonical_name_for_symbol(
            item_type, version, address,
            mappers, tweakers, symbol_map_dicts=symbol_map_dicts, demangle=demangle, default_version_name=default_version_name)

        if current_name != best_name:
            new_file_data = new_file_data.replace(current_name, best_name)
            # print(f'{current_name} -> {best_name}')

    print(new_file_data)


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description='Scan for symbol names in a text file, and try to map them to corresponding canonical names.')

    parser.add_argument('file', type=Path,
        help='text file to scan')
    parser.add_argument('address_map', type=Path,
        help='address map file')
    parser.add_argument('tweaks_file', type=Path,
        help='symtweaks file')
    parser.add_argument('--symbol-map', action='append', nargs=2, metavar=('FILE', 'VERSION'),
        help='symbols that can be mapped to this version will be given these names instead. Also specify the version the symbol map applies to (e.g. "P1")')
    parser.add_argument('--default-version-name',
        help='an alternative name to use instead of "default" (e.g. "P1")')
    parser.add_argument('--demangle', action='store_true',
        help='output demangled symbols')

    parsed_args = parser.parse_args(args)

    with parsed_args.file.open('r', encoding='utf-8') as f:
        file_data = f.read()

    with parsed_args.address_map.open('r', encoding='utf-8') as f:
        mappers = lib_address_maps.load_address_map(f)

    with parsed_args.tweaks_file.open('r', encoding='utf-8') as f:
        tweakers = lib_tweaks.read_symbols_tweak_file(f)

    symbol_maps = {}
    if parsed_args.symbol_map:  # default is None rather than [], ugh
        for fp, version in parsed_args.symbol_map:
            with open(fp, encoding='utf-8') as f:
                symbol_maps[version] = lib_symbol_map_formats.autodetect_and_load(f)

    look_for_symbol_names(
        file_data, mappers, tweakers,
        symbol_maps=symbol_maps,
        demangle=parsed_args.demangle,
        default_version_name=parsed_args.default_version_name)


if __name__ == '__main__':
    main()
