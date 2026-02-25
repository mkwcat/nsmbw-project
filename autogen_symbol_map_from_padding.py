#!/usr/bin/env python3

import argparse
from pathlib import Path
from typing import Dict, List, Optional

from lib_wii_code_tools import code_files
from lib_wii_code_tools.code_files import all as code_files_all
from lib_wii_code_tools import nsmbw as lib_nsmbw
from lib_wii_code_tools import symbol_map_formats as lib_symbol_map_formats



def generate_symbols(code_file: code_files.CodeFile, *, label: str = None) -> Dict[int, str]:
    """
    Inspect function padding, and use it to infer a symbol map.
    """
    function_addresses = set()

    # Look at every executable section
    for section in code_file.sections:
        if not section.is_executable: continue

        # Beginning of an executable section will be a function, too
        function_addresses.add(section.address)

        # Find all 4-byte-aligned null u32s in the section
        null_u32s = set()
        for addr in range(0, len(section.data), 4):
            u32 = section.data[addr : addr + 4]
            if u32 == b'\0\0\0\0':
                null_u32s.add(section.address + addr)

        # Add the address immediately following each run of null u32s as
        # a function pointer (if it's in the section address range)
        for addr in null_u32s:
            if addr + 4 not in null_u32s and addr + 4 < (section.address + section.size):
                function_addresses.add(addr + 4)

    # Assign names to the addresses (using Ghidra's convention), and return
    map = {}
    for addr in sorted(function_addresses):
        if label:
            map[addr] = f'FUN_{label}_{addr:08x}'
        else:
            map[addr] = f'FUN_{addr:08x}'
    return map


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description='Infer around 3/4 of function addresses from the null padding between functions.')

    parser.add_argument('code_file', type=Path,
        help='code file (DOL, REL, ALF) to read')
    parser.add_argument('output_map', type=Path,
        help='output symbol map (JSON format)')
    parser.add_argument('--section-addresses', metavar='ADDRS',
        help='section addresses (required if the code file is REL, ignored otherwise).'
        ' Addresses should be comma-separated (no spaces) hex values, one per REL section.'
        ' Example: "807685a0,8076a558,8076a560,8076a570,8076a748,8076d460"')

    parsed_args = parser.parse_args(args)

    code_file = code_files_all.load_by_extension(parsed_args.code_file.read_bytes(), parsed_args.code_file.suffix)

    if parsed_args.code_file.suffix == '.rel':
        if parsed_args.section_addresses is None:
            raise ValueError('--section-addresses is required if the input format is REL')

        section_addrs = [int(p, 16) for p in parsed_args.section_addresses.split(',')]

        # Verify number of them
        if len(section_addrs) != len(code_file.sections):
            raise ValueError(f'REL has {len(code_file.sections)} sections, but only {len(section_addrs)} section addresses were provided on the command line')

        # Assign to REL sections
        for section, addr in zip(code_file.sections, section_addrs):
            section.address = addr

    elif parsed_args.code_file.suffix == '.alf':
        # We need to know which sections are executable, since we limit
        # our function search to just those
        lib_nsmbw.auto_assign_alf_section_executability(code_file)

    map = generate_symbols(code_file)

    with parsed_args.output_map.open('w', encoding='utf-8') as f:
        obj = lib_symbol_map_formats.JSONSymbolMap()
        obj.symbols = map
        obj.write(f)


if __name__ == '__main__':
    main()
