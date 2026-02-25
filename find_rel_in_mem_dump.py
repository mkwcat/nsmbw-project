#!/usr/bin/env python3

# 2020-09-30 RoadrunnerWMC

import argparse
import random
import struct
from pathlib import Path
from typing import List, Optional

from lib_wii_code_tools.code_files import rel as code_files_rel


def find_all(haystack: bytes, needle: bytes) -> List[int]:
    """
    Return all indices at which needle appears in haystack
    """
    L = []
    offs = haystack.find(needle)
    while offs >= 0:
        L.append(offs)
        offs = haystack.find(needle, offs+1)
    return L


def find_section_address_in_memdump(section: code_files_rel.RELSection, memdump: bytes) -> Optional[int]:
    """
    Try to find the REL section in the memdump. Return None if it can't
    be found (this will happen quite often).
    """
    if section.is_null():
        return None
    if section.is_bss():
        raise NotImplementedError

    d = section.data

    for match_size in [64, 32, 24, 16, 12]:
        if match_size > len(d): continue
        for j in range(1000):
            offs = random.randint(0, len(d) - match_size)
            snippet = d[offs : offs+match_size]

            # skip if it's just null bytes
            if not any(snippet): continue

            if memdump.count(snippet) == 1:
                return memdump.find(snippet) - offs | 0x80000000


def find_all_section_addresses_in_memdump(rel: code_files_rel.REL, memdump: bytes) -> List[int]:
    """
    Return a list of the address of each REL section in the mem dump
    """
    # Try to find as many sections as possible empirically
    known_addresses = []
    for i, s in enumerate(rel.sections):
        if s.is_null() or s.is_bss():
            known_addresses.append(None)
        else:
            known_addresses.append(find_section_address_in_memdump(s, memdump))

    # Now try to locate the address table.
    # Said table is just:
    #     u32 section1_address;
    #     u32 section1_length;
    #     u32 section2_address;
    #     u32 section2_length;
    #     (etc)
    # so we can now begin to look for that pattern.
    possible_table_addrs = set()

    for i, (ka, s) in enumerate(zip(known_addresses, rel.sections)):
        if ka is None: continue

        matches = find_all(memdump, struct.pack('>II', ka, s.size))
        if len(matches) == 1:
            possible_table_addrs.add(matches[0] - 8 * i)

    if len(possible_table_addrs) != 1:
        raise RuntimeError(f"Couldn't find section table! (Possibilities: {possible_table_addrs})")

    # Now we can just read off the section addresses ~
    table_addr = next(iter(possible_table_addrs))
    all_addrs = []
    for i, s in enumerate(rel.sections):
        supposed_addr, supposed_len = struct.unpack_from('>II', memdump, table_addr + 8 * i)
        assert supposed_len == s.size
        all_addrs.append(supposed_addr)

    # Sanitize and return
    all_addrs = [code_files_rel.SEGMENT_OFF(a) for a in all_addrs]
    return all_addrs


def print_info(rel: code_files_rel.REL, memdump: bytes) -> None:
    """
    Print the REL section addresses to stdout nicely.
    """
    section_addrs = find_all_section_addresses_in_memdump(rel, memdump)

    for i, (s, addr) in enumerate(zip(rel.sections, section_addrs)):
        if s.is_null(): continue

        line = []
        if s.is_bss():
            line.append(f'Section {i} (.bss):  ')
        elif s.is_executable:
            line.append(f'Section {i} (.text): ')
        else:
            line.append(f'Section {i} (.data): ')

        line.append(f'{addr:08X}-{addr+s.size:08X}')

        print(''.join(line))


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='Find concrete REL section addresses from a memory dump.')

    parser.add_argument('rel_file', type=Path,
        help='the rel file')
    parser.add_argument('memdump', type=Path,
        help='memory dump (Dolphin: mem1.raw)')

    parsed_args = parser.parse_args(args)

    with parsed_args.rel_file.open('rb') as f:
        rel = code_files_rel.REL.from_file(f)

    with parsed_args.memdump.open('rb') as f:
        memdump = f.read()

    print_info(rel, memdump)


if __name__ == '__main__':
    main()
