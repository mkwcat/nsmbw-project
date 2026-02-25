#!/usr/bin/env python3

import argparse
from pathlib import Path
from typing import List, Optional

from lib_wii_code_tools import common
from lib_wii_code_tools import tweaks as lib_tweaks
from lib_wii_code_tools import address_maps as lib_address_maps
from lib_wii_code_tools import port_symbol_map as lib_port_symbol_map
from lib_wii_code_tools import nsmbw as lib_nsmbw
from lib_wii_code_tools import symbol_map_formats as lib_symbol_map_formats
import map_address


DEFAULT_OUTPUT_FORMAT = 'dolphin'
DEFAULT_OUTPUT_PATTERN = 'symbols_$VER$.map'


ErrorVolume = common.ErrorVolume


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='Use an address map, and optionally a tweaks.txt, to port a symbol map to different game versions (by default, to all versions at once).')

    parser.add_argument('symbol_map', type=Path,
        help='input symbol map file (various formats supported)')
    parser.add_argument('symbol_map_version',
        help='game version code that the input symbol map applies to (e.g. "P1")')
    parser.add_argument('address_map', type=Path,
        help='address map file')
    parser.add_argument('output_folder', type=Path,
        help='folder to save output symbol maps to')
    parser.add_argument('tweaks', type=Path, nargs='?',
        help='"tweaks.txt" file for the symbol map')

    parser.add_argument('--output-format', choices=sorted(lib_symbol_map_formats.FORMAT_CLASSES), default=DEFAULT_OUTPUT_FORMAT,
        help=f'file format for output symbol maps (default: {DEFAULT_OUTPUT_FORMAT})')
    parser.add_argument('--output-pattern', default=DEFAULT_OUTPUT_PATTERN,
        help='filename pattern for output symbol maps.'
        ' Must contain "$VER$" somewhere, which will be replaced with each version code in the address map.'
        ' You may need to escape dollar signs with backslashes, depending on your shell.'
        f' (default: "{DEFAULT_OUTPUT_PATTERN}")')
    parser.add_argument('--single-version', metavar='VERSION',
        help='just export the result for a single version, not for all versions in the address map')

    map_address.add_error_handler_args(parser)

    parser.add_argument('--symbol-tweaking-errors',
        choices=[m.value for m in ErrorVolume],
        default=ErrorVolume.default(),
        help='how loudly to complain about various issues when tweaking symbols.'
        " error: raise an exception and stop. warning: print a warning but still continue. silent: don't even print a warning."
        f' (default: {ErrorVolume.default().value})')

    parsed_args = parser.parse_args(args)

    if '$VER$' not in parsed_args.output_pattern:
        raise ValueError('--output-pattern must contain "$VER$"')

    with parsed_args.address_map.open('r', encoding='utf-8') as f:
        mappers = lib_address_maps.load_address_map(f)

    with parsed_args.symbol_map.open('r', encoding='utf-8') as f:
        input_map = lib_symbol_map_formats.autodetect_and_load(f).to_symbol_dict()

    if parsed_args.tweaks is None:
        tweaks = {'default': lib_tweaks.SymbolsTweaker()}
    else:
        with parsed_args.tweaks.open('r', encoding='utf-8') as f:
            tweaks = lib_tweaks.read_symbols_tweak_file(f)

    error_handling = lib_port_symbol_map.PortingIssuesHandling(
        map_address.get_error_handling(parsed_args),
        ErrorVolume(parsed_args.symbol_tweaking_errors))

    all_remapped_syms = lib_port_symbol_map.remap_symbols_to_all_versions(
        input_map,
        parsed_args.symbol_map_version,
        mappers,
        tweaks,
        error_handling=error_handling,
        verbose=True)

    parsed_args.output_folder.mkdir(parents=True, exist_ok=True)

    for name, remapped_syms in all_remapped_syms.items():
        if name == 'default':
            continue

        # This is kind of inefficient, but a lot simpler and more
        # maintainable than having a completely different code path for
        # mapping the symbols as directly as possible to a single target
        # version
        if parsed_args.single_version is not None and name != parsed_args.single_version:
            continue

        lib_nsmbw.save_nsmbw_symbol_map(
            remapped_syms,
            name,
            parsed_args.output_format,
            parsed_args.output_folder / parsed_args.output_pattern.replace('$VER$', name))


if __name__ == '__main__':
    main()
