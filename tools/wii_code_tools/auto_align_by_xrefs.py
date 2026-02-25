#!/usr/bin/env python3

# For use with the following Ghidra script (ExportXrefs.py):

# # Exports a JSON file containing all xrefs in the program: {to: [from, from, from, ...], ...}
# # @author RoadrunnerWMC
# # @category Data
# #
#
# import json
#
# f = askFile('Choose a file to write to', 'Go!')
#
# refMgr = currentProgram.getReferenceManager()
# xrefs = {}
# for dest_addr in refMgr.getReferenceDestinationIterator(currentProgram.getMinAddress(), True):
#     dest_addr_val = dest_addr.offset
#     xrefs[dest_addr_val] = []
#     for ref in refMgr.getReferencesTo(dest_addr):
#         xrefs[dest_addr_val].append(ref.getFromAddress().offset)
#
# with file(f.absolutePath, 'w') as fd:  # note, cannot use open(), since that is in GhidraScript
#     json.dump(xrefs, fd)
#
# print(u'Exported {} xrefs'.format(sum(len(v) for v in xrefs.values())))

import argparse
import collections
import json
from pathlib import Path
from typing import Dict, List, Optional

from lib_wii_code_tools import common
from lib_wii_code_tools import address_maps as lib_address_maps


DEFAULT_ALIGNED_RANGE_START = 0x80000000


XrefsStructure = Dict[int, List[int]]


def probably_spurious(addr: int) -> bool:
    """
    Ghidra likes to invent nonexistent xrefs to addresses like 0x803b0000.
    If the bottom four digits are all zero, we should frankly ignore all xrefs.
    """
    return addr & 0xffff == 0


def load_xrefs(fp: Path) -> XrefsStructure:
    """
    Load an xrefs json, ensuring that all dict keys are ints
    """
    with fp.open('r', encoding='utf-8') as f:
        return {int(k): v for k, v in json.load(f).items()}


def auto_align_by_xrefs(
        xrefs_1: XrefsStructure,
        xrefs_2: XrefsStructure,
        mapper_1: lib_address_maps.AddressMapper,
        mapper_2: lib_address_maps.AddressMapper,
        from_range: (int, int),
        to_range: (int, int)) -> None:
    """
    Do the actual auto-alignment stuff. Results are printed.
    xrefs_1/xrefs_2: Ghidra-exported xrefs file data
    mapper_1/mapper_2: AddressMapper instances for "from" and "to" versions
    from_range: the part of the DOL you've already worked out the address map
      for. Xrefs will be considered if they point FROM anywhere in this region.
    to_range: the part of the DOL you want to align. Xrefs will be considered
      if they point TO anywhere in this region.
    """

    # General approach:
    # - look at each spot in v1
    # - look at xrefs to that spot
    # - convert each xref to a v2 addr
    # - look up where that xref goes in 2
    # - profit

    error_handling = lib_address_maps.UnmappedAddressHandling(
        common.ErrorVolume.SILENT,
        lib_address_maps.UnmappedAddressHandling.Behavior.DROP)

    # Invert the references dict for 2
    reverse_xrefs_2 = {}
    ambiguous = set()
    for to, froms in xrefs_2.items():
        if probably_spurious(to): continue
        for from_ in froms:
            if from_ in ambiguous:
                # skip
                pass
            elif from_ in reverse_xrefs_2:
                # ambiguous -- skip this one altogether
                del reverse_xrefs_2[from_]
                ambiguous.add(from_)
            else:
                reverse_xrefs_2[from_] = to

    # Find deltas and such
    current_range_start = None
    current_range_delta = None
    for to in sorted(xrefs_1):
        if not to_range[0] <= to < to_range[1]: continue

        counter = collections.Counter()
        for from_ in xrefs_1[to]:
            if not from_range[0] <= from_ < from_range[1]: continue

            from_converted = lib_address_maps.map_addr_from_to(mapper_1, mapper_2, from_, error_handling=error_handling)
            if from_converted in reverse_xrefs_2:
                counter.update([reverse_xrefs_2[from_converted]])

        if not counter: continue

        to_remapped = counter.most_common(1)[0][0]
        delta = to_remapped - to
        
        if current_range_delta is None:
            current_range_delta = delta

        if delta != current_range_delta:
            if abs(delta - current_range_delta) > 0x10000:
                # probably a mistake
                continue

            current_range_start_str = '*' if current_range_start is None else f'{current_range_start:08x}'
            delta_str = ('-' if current_range_delta < 0 else '+') + hex(abs(current_range_delta))
            print(f'{current_range_start_str}-{to-1:08x}: {delta_str}')

            current_range_start = to
            current_range_delta = delta

    if current_range_delta is None:
        print('No usable xrefs found...')
        return

    current_range_start_str = '*' if current_range_start is None else f'{current_range_start:08x}'
    delta_str = ('-' if current_range_delta < 0 else '+') + hex(abs(current_range_delta))
    print(f'{current_range_start_str}-*: {delta_str}')


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description='Try to infer a rough address map for a section based on exported Ghidra xrefs.')

    parser.add_argument('address_map', type=Path,
        help='WIP address map file')
    parser.add_argument('xrefs_file_1', type=Path,
        help='first Ghidra-exported xrefs file (json)')
    parser.add_argument('xrefs_file_2', type=Path,
        help='second Ghidra-exported xrefs file (json)')
    parser.add_argument('address_map_version_1',
        help='game version code that the first xrefs file applies to (e.g. "P1")')
    parser.add_argument('address_map_version_2',
        help='game version code that the second xrefs file applies to (e.g. "P2")')
    parser.add_argument('range',
        help='range of addresses (relative to version "1") to infer an address map for (e.g. "8076a748-8076bd44")')
    parser.add_argument('--aligned-range',
        help='range of addresses (relative to version "1") that are already correctly aligned in the address map.'
        f' If not provided, defaults to "{hex(DEFAULT_ALIGNED_RANGE_START)} to the start of `range`",'
        ' which is probably what you want.')

    parsed_args = parser.parse_args(args)

    with parsed_args.address_map.open('r', encoding='utf-8') as f:
        mappers = lib_address_maps.load_address_map(f)

    xrefs_1 = load_xrefs(parsed_args.xrefs_file_1)
    xrefs_2 = load_xrefs(parsed_args.xrefs_file_2)
    mapper_1 = mappers[parsed_args.address_map_version_1]
    mapper_2 = mappers[parsed_args.address_map_version_2]

    def parse_address_range(s: str) -> (int, int):
        """
        Parse a string like "8076a748-8076bd44" to a pair of ints
        """
        if s.count('-') != 1:
            raise ValueError(f'Address range "{s}" has invalid format')
        return [int(v, 16) for v in s.split('-')]

    to_range = parse_address_range(parsed_args.range)

    if parsed_args.aligned_range:
        from_range = parse_address_range(parsed_args.aligned_range)
    else:
        from_range = (DEFAULT_ALIGNED_RANGE_START, to_range[0])

    auto_align_by_xrefs(xrefs_1, xrefs_2, mapper_1, mapper_2, from_range, to_range)

main()
