#!/usr/bin/env python3

# 2020-02-12 RoadrunnerWMC

import argparse
from pathlib import Path
from typing import List, Optional

from lib_wii_code_tools import common
from lib_wii_code_tools import address_maps as lib_address_maps


def add_error_handler_args(parser: argparse.ArgumentParser) -> None:
    """
    Add arguments to an ArgumentParser for configuring an
    UnmappedAddressHandling.
    This is a separate function because port_symbol_map.py uses it too.
    """
    parser.add_argument('--unmapped-address-errors',
        choices=[m.value for m in common.ErrorVolume],
        default=common.ErrorVolume.default(),
        help='how loudly to complain about symbols in unmapped address ranges.'
        " error: raise an exception and stop. warning: print a warning but still continue. silent: don't even print a warning."
        f' (default: {common.ErrorVolume.default().value})')
    parser.add_argument('--unmapped-address-behavior',
        choices=[m.value for m in lib_address_maps.UnmappedAddressHandling.Behavior],
        default=lib_address_maps.UnmappedAddressHandling.Behavior.default(),
        help='how to handle symbols in unmapped address ranges.'
        ' Note: a symbol that passes through multiple game versions may be unmapped in more than one of them, or in some but not all of them.'
        ' drop: delete them. passthrough: leave them alone. prev_range: use the offset from the previous mapped address range.'
        f' (default: {lib_address_maps.UnmappedAddressHandling.Behavior.default().value})')


def get_error_handling(parsed_args: argparse.Namespace) -> lib_address_maps.UnmappedAddressHandling:
    """
    Get an UnmappedAddressHandling instance from the argparse result.
    This is a separate function because port_symbol_map.py uses it too.
    """
    return lib_address_maps.UnmappedAddressHandling(
        common.ErrorVolume(parsed_args.unmapped_address_errors),
        lib_address_maps.UnmappedAddressHandling.Behavior(parsed_args.unmapped_address_behavior))


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """

    parser = argparse.ArgumentParser(
        description='Map an address from one version to another.')

    parser.add_argument('address_map', type=Path,
        help='address map file')
    parser.add_argument('version_1',
        help='the "from" version code')
    parser.add_argument('version_2',
        help='the "to" version code')
    parser.add_argument('address',
        help='the address to convert')

    add_error_handler_args(parser)

    parsed_args = parser.parse_args(args)

    with parsed_args.address_map.open('r', encoding='utf-8') as f:
        mappers = lib_address_maps.load_address_map(f)

    if parsed_args.version_1 not in mappers:
        raise ValueError(f'Error: unknown region "{parsed_args.version_1}" (available regions: {", ".join(mappers)})')
    if parsed_args.version_2 not in mappers:
        raise ValueError(f'Error: unknown region "{parsed_args.version_2}" (available regions: {", ".join(mappers)})')

    mapper_from = mappers[parsed_args.version_1]
    mapper_to = mappers[parsed_args.version_2]

    try:
        address = int(parsed_args.address, 16)
    except ValueError:
        print(f'Error: can\'t read "{parsed_args.address}" as an address')
        raise ValueError

    new_address = lib_address_maps.map_addr_from_to(
        mapper_from,
        mapper_to,
        address,
        error_handling=get_error_handling(parsed_args))

    if new_address is None:
        print('The address could not be mapped.')
    else:
        print(f'{new_address:08x}')


if __name__ == '__main__':
    main()
