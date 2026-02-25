#!/usr/bin/env python3

# 2021-02-07 RoadrunnerWMC

# This is only good for making an approximate address map for non-bss
# sections as a starting point. For bss sections, use
# auto_align_by_xrefs.py. To *verify* that a manually written address
# map is accurate, use verify_address_map.py.

import argparse
from pathlib import Path
import random
from typing import List, Optional

from lib_wii_code_tools.code_files import CodeFile
from lib_wii_code_tools.code_files.all import load_by_extension


def check_match_at(data_a: bytes, data_b: bytes, offset: int, size: int) -> int:
    snippet = data_a[offset : offset + size]

    # skip if it's just null bytes
    if not any(snippet):
        return None

    # skip if there aren't exactly the right number of matches in b
    if data_b.count(snippet) != 1:
        return None

    return data_b.find(snippet)


def find_random_match(data_a: bytes, data_b: bytes, start: int, end: int) -> tuple[int, int]:
    """
    Find a random matching bit of data in the two bytes objects, and
    return the corresponding offsets
    """
    for match_size in [128, 64]:
        if match_size > min(len(data_a), len(data_b), end - start):
            continue

        for j in range(50):
            offs = random.randint(start, end - match_size)

            match = check_match_at(data_a, data_b, offs, match_size)
            if match is not None:
                return offs, match

    return -1, -1


class DifferencesTracker:
    """
    Class that keeps track of offsets at various code addresses.
    """
    def __init__(self, first_address: int, first_offset: int, last_address: int, last_offset: int):
        # Addresses are to be pushed as far left as possible.
        self.known_address_offsets = [(first_address, first_offset), (last_address, last_offset)]
        self.last_address = last_address
        self.last_offset = last_offset

    @property
    def first_address(self) -> int:
        return self.known_address_offsets[0][0]

    @property
    def first_offset(self) -> int:
        return self.known_address_offsets[0][1]

    def expected_offset_at(self, address: int) -> int | None:
        """
        Based on previously reported offsets, determine what the offset
        at this address is currently expected to be. (Specifically,
        that'll be the offset of the largest address smaller than the
        one passed to this function.)
        """
        for i, (addr, offs) in enumerate(self.known_address_offsets):
            if addr > address:
                return self.known_address_offsets[i - 1][1]

    def report_offset_at_address(self, address: int, offset: int) -> bool:
        """
        Report the offset for a particular address, to be added to the
        tracker.

        *YOU SHOULD MAKE THE ADDRESS AS SMALL AS POSSIBLE.* That is, if
        you call this function with address X and offset Y, that should
        imply that you're *not* confident that address X - 1 also has
        offset value Y. (This improves the precision of the output at
        the end.)

        Returns True if this created a new division point.
        """
        if not (self.first_address <= address < self.last_address):
            raise ValueError(f'{address:08x} is out of bounds ({self.first_address:08x}-{self.last_address:08x})')

        # Find the index of the entry which would come just after this one...
        entry_index_from_end = None
        for i, (other_addr, other_offs) in enumerate(reversed(self.known_address_offsets)):
            if other_addr > address:
                entry_index_from_end = i
            else:
                break

        if entry_index_from_end is None:
            # Next entry would be at the end of the list
            prev_offset = self.known_address_offsets[-1][1]
            next_entry_id = len(self.known_address_offsets)

        else:
            # Found the entry
            next_entry_id = len(self.known_address_offsets) - entry_index_from_end - 1
            next_offset = self.known_address_offsets[next_entry_id][1]
            prev_offset = self.known_address_offsets[next_entry_id - 1][1]

            if offset == next_offset:
                # Push it forward
                self.known_address_offsets[next_entry_id] = (address, offset)
                return False

        if offset == prev_offset:
            # Ignore
            return False
        else:
            # Create a new division here
            self.known_address_offsets.insert(next_entry_id, (address, offset))
            return True

    def print_results(self) -> None:
        kao_copy = list(self.known_address_offsets)

        # Delete redundant ranges
        for i in range(len(kao_copy) - 2, -1, -1):
            if kao_copy[i][1] == kao_copy[i + 1][1]:
                del kao_copy[i + 1]

        for i, (addr, offs) in enumerate(kao_copy):
            if i + 1 < len(kao_copy):
                next_addr = f'{kao_copy[i + 1][0] - 1:08x}'
            else:
                next_addr = '*'

            offs_str = ('-' if offs < 0 else '+') + hex(abs(offs))

            print(f'{addr:08x}-{next_addr}: {offs_str}')

        print()


def find_division_points_in_range(
    data_a: bytes,
    data_b: bytes,
    address_a: int,
    address_b: int,
    start_offset: int,
    end_offset: int,
    tracker: DifferencesTracker,
) -> None:

    # Try to push the upper boundary about as far left as possible
    expected_offset = tracker.expected_offset_at(end_offset)
    moved_left = True
    while moved_left:
        moved_left = False
        for pow2 in [10, 9.5, 9, 8.5, 8, 7]:  # 1024 through 128
            jump_amount = int(2 ** pow2)
            new_end_offset = end_offset - jump_amount
            match = check_match_at(data_a, data_b, new_end_offset, jump_amount // 4)
            if match is not None:
                offs_there = match - new_end_offset
                if offs_there == expected_offset:
                    moved_left = True
                    end_offset = new_end_offset

    # Crawl left a little more
    while (end_offset < len(data_a)
            and end_offset + expected_offset < len(data_b)
            and data_a[end_offset] == data_b[end_offset + expected_offset]):
        end_offset -= 1

    # Find some initial division points
    division_points = {address_a + start_offset, address_a + end_offset}
    for i in range(max((end_offset - start_offset) // 50, 100)):
        match_pos_a, match_pos_b = find_random_match(data_a, data_b, start_offset, end_offset)
        if match_pos_a != -1:
            addr = address_a + match_pos_a
            created_new_division = tracker.report_offset_at_address(
                addr,
                (match_pos_b - match_pos_a) + (address_b - address_a))
            if created_new_division:
                division_points.add(addr)

    if len(division_points) > 2:
        # Recurse on each subdivision
        sorted_points = sorted(division_points)
        for i in range(len(sorted_points) - 1):
            a, b = sorted_points[i : i + 2]
            find_division_points_in_range(
                data_a, data_b, address_a, address_b,
                a, b,
                tracker,
            )


def diff(code_file_a: CodeFile, code_file_b: CodeFile) -> None:
    """
    Find differences in files A and B
    """
    sections_A = sorted(code_file_a.sections, key=lambda s: s.address)
    sections_B = sorted(code_file_b.sections, key=lambda s: s.address)

    # Assumption: each section in A corresponds to one section in B,
    # and their addresses line up
    assert len(sections_A) == len(sections_B)

    for i, (section_A, section_B) in enumerate(zip(sections_A, sections_B)):
        assert section_A.is_bss() == section_B.is_bss()
        # don't also compare is_executable, since that makes it hard to
        # diff DOL with ALF

        if section_A.is_bss():
            # Can't handle .bss sections in this script since there's
            # no data to compare
            continue

        assert section_A.size == len(section_A.data)

        # Initialize tracker with start and end addresses and offsets
        tracker = DifferencesTracker(
            section_A.address,
            section_B.address - section_A.address,
            section_A.address + section_A.size,
            (section_B.address + section_B.size) - (section_A.address + section_A.size))
        print(f'Section {i}')

        find_division_points_in_range(
            section_A.data, section_B.data,
            section_A.address, section_B.address,
            0, section_A.size,
            tracker)

        tracker.print_results()


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description='Automatically generate a rough address map between'
        ' two versions of a code file with a Monte Carlo method.')

    parser.add_argument('code_file_1', type=Path,
        help='first code file (DOL, REL, ALF)')
    parser.add_argument('code_file_2', type=Path,
        help='second code file (DOL, REL, ALF)')

    parsed_args = parser.parse_args(args)

    cf_1 = load_by_extension(parsed_args.code_file_1.read_bytes(), parsed_args.code_file_1.suffix)
    if cf_1 is None:
        print(f'Unknown file extension: {parsed_args.code_file_1.suffix}')
        return

    cf_2 = load_by_extension(parsed_args.code_file_2.read_bytes(), parsed_args.code_file_2.suffix)
    if cf_2 is None:
        print(f'Unknown file extension: {parsed_args.code_file_2.suffix}')
        return

    diff(cf_1, cf_2)


if __name__ == '__main__':
    main()
