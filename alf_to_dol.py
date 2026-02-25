#!/usr/bin/env python3

import argparse
from pathlib import Path
import struct
from typing import List, Optional

from lib_wii_code_tools import nsmbw as lib_nsmbw
from lib_wii_code_tools.code_files import alf as code_files_alf


DOL_SECTION_ALIGNMENT = 0x20


def alf_to_dol(alf: code_files_alf.ALF) -> bytes:
    """
    Given an alf file, return data for an equivalent dol.
    Returns bytes instead of code_files.dol.DOL because the latter
    doesn't support saving.
    """
    # DOL requires we know the execuability of sections, so, try to guess
    lib_nsmbw.auto_assign_alf_section_executability(alf)

    # Start the dol data with an empty header
    dol_data = bytearray(0x100)

    def add_section(section: code_files_alf.ALFSection, index: int) -> None:
        """
        Add the given section to the dol data, and put its info (offset,
        address, size) at the given index number in the header.
        Indices 0-6 are for executable sections, and 7-17 (decimal) are
        for non-executable sections.
        """
        nonlocal dol_data

        offset = len(dol_data)

        # Align if necessary
        dol_data += section.data
        if len(dol_data) % DOL_SECTION_ALIGNMENT:
            pad_amt = DOL_SECTION_ALIGNMENT - (len(dol_data) % DOL_SECTION_ALIGNMENT)
            dol_data += b'\0' * pad_amt

        # Add stuff to header
        struct.pack_into('>I', dol_data, 0x00 + index * 4, offset)
        struct.pack_into('>I', dol_data, 0x48 + index * 4, section.address)
        struct.pack_into('>I', dol_data, 0x90 + index * 4, section.size)

    sorted_sections = sorted(alf.sections, key=lambda s: s.address)

    # Add executable sections
    text_section_num = 0
    for section in sorted_sections:
        if section.is_executable:
            add_section(section, text_section_num)
            text_section_num += 1

    # Add non-executable non-bss sections
    data_section_num = 0
    for section in sorted_sections:
        if not section.is_executable and section.data:
            add_section(section, 7 + data_section_num)
            data_section_num += 1

    # Combine all the bss sections into one big one
    bss_min = 0xffffffff
    bss_max = 0
    for section in sorted_sections:
        if not section.data:
            bss_min = min(bss_min, section.address)
            bss_max = max(bss_max, section.address + section.size)

    # Write the last few header values
    struct.pack_into('>III', dol_data, 0xd8,
        bss_min, bss_max - bss_min, alf.entry_point)

    # And done
    return bytes(dol_data)


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description='Convert an ALF file to an equivalent DOL file.')

    parser.add_argument('alf_file', type=Path,
        help='alf file to read')
    parser.add_argument('dol_file', type=Path,
        help='dol file to write')

    parsed_args = parser.parse_args(args)

    alf = code_files_alf.ALF(parsed_args.alf_file.read_bytes())
    dol_data = alf_to_dol(alf)
    parsed_args.dol_file.write_bytes(dol_data)


if __name__ == '__main__':
    main()
