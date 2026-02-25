#!/usr/bin/env python3

import argparse
from pathlib import Path
from typing import List, Optional

from lib_wii_code_tools import nsmbw as lib_nsmbw
from lib_wii_code_tools import symbol_map_formats as lib_symbol_map_formats


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='Combine symbol maps.'
        ' As a special case, this can also be used to convert a single symbol map between different formats.'
        ' If symbols conflict (same address), the name will be picked from the symbol map nearest the *end* of the command-line list.')

    parser.add_argument('input_map', type=Path, nargs='*',
        help='input symbol map file(s) (any supported format(s))')
    lib_symbol_map_formats.add_map_output_arguments(parser, 'output_map', 
        help='output symbol map file')
    parser.add_argument('game_version',
        help='game version code that the symbol map applies to (e.g. "P1")')

    parsed_args = parser.parse_args(args)

    overall_map = {}

    for input_map_path in parsed_args.input_map:
        with input_map_path.open('r', encoding='utf-8') as f:
            input_map_obj = lib_symbol_map_formats.autodetect_and_load(f)

        overall_map.update(input_map_obj.to_symbol_dict())

    lib_nsmbw.save_nsmbw_symbol_map(
        overall_map,
        parsed_args.game_version,
        parsed_args.output_map_format,
        parsed_args.output_map)


if __name__ == '__main__':
    main()
