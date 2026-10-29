#!/usr/bin/env python3

# 2020-09-30 RoadrunnerWMC

import argparse
import random
import struct
from pathlib import Path
from typing import List, Optional

from lib_wii_code_tools.code_files import dol as code_files_dol
from lib_wii_code_tools.nsmbw_constants import DOL_SECTION_NAMES


def print_info(dol: code_files_dol.DOL) -> None:
    """
    Print the DOL section addresses to stdout nicely.
    """
    for i, s in enumerate(dol.sections):
        if s.is_null(): continue

        line = []
        if s.is_bss():
            line.append(f'Section {i} (.bss):  ')
        elif s.is_executable:
            line.append(f'Section {i} (.text): ')
        else:
            line.append(f'Section {i} (.data): ')

        line.append(f'{s.address:08x}-{s.address+s.size:08x} ({s.size:x})')

        print(''.join(line))

    """
    Print the DOL section addresses to stdout in the Python constants format.
    """
    for i, s in enumerate(dol.sections):
        if s.is_null(): continue

        print(f'            \'{DOL_SECTION_NAMES[i]}\': {{{s.address:#08x}, {s.size:#x}}},')


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='List DOL section memory addresses.')

    parser.add_argument('dol_file', type=Path,
        help='the dol file')

    parsed_args = parser.parse_args(args)

    with parsed_args.dol_file.open('rb') as f:
        dol = code_files_dol.DOL(f.read())

    print_info(dol)


if __name__ == '__main__':
    main()
