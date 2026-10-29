#!/usr/bin/env python3

import argparse
from pathlib import Path
import struct
from typing import BinaryIO, List, Optional, Tuple
import json

from lib_wii_code_tools import code_files
from lib_wii_code_tools.code_files import all as code_files_all
from lib_wii_code_tools.code_files import rel as code_files_rel
from lib_wii_code_tools import nsmbw_constants as lib_nsmbw_constants

# TODO: get rid of this dependency probably
import elftools.elf.enums as elf_enums  # pip install pyelftools



def dump_all_relocations(rels: List[code_files_rel.REL]):
    """
    Apply all REL relocations, in-place
    """

    xrefs = {}

    # Make an id -> module map
    modules = {}
    for rel in rels:
        if rel.id in modules:
            raise ValueError(f'Duplicate REL ID: {rel.id}')
        modules[rel.id] = rel

    # Iterate all imports
    for rel in rels:
        for imp in rel.imports:
            if imp.module_num > 0:
                importing_from_module = modules[imp.module_num]

            section_id = 0
            write_pos = 0

            for reloc in imp.relocations:
                write_pos += reloc.offset

                # Handle meta relocation types first
                if reloc.type == code_files_rel.RELRelocationType.R_DOLPHIN_NOP:
                    continue
                elif reloc.type == code_files_rel.RELRelocationType.R_DOLPHIN_SECTION:
                    section_id = reloc.section
                    write_pos = 0
                    continue
                elif reloc.type == code_files_rel.RELRelocationType.R_DOLPHIN_END:
                    break
                elif reloc.type == code_files_rel.RELRelocationType.R_DOLPHIN_MRKREF:
                    print('WARNING: skipping R_DOLPHIN_MRKREF')
                    continue

                write_addr = rel.sections[section_id].address + write_pos

                addr_to_write = reloc.addend
                if imp.module_num > 0:
                    addr_to_write += importing_from_module.sections[reloc.section].address

                if addr_to_write not in xrefs:
                    xrefs[addr_to_write] = []
                xrefs[addr_to_write].append(write_addr)

    return xrefs



def main(args: Optional[List[str]] = None) -> None:
    """
    Main function for the application
    """

    parser = argparse.ArgumentParser(
        description='Given a DOL, some RELs, and the addresses their sections are known to end up at, apply all relocations, linking them to the DOL and to each other.')

    parser.add_argument('-o', '--output', type=Path, required=True,
        help='the output xref json file')
    parser.add_argument('--rel', nargs=2, action='append', metavar=('REL', 'ADDRS'),
        help='add a REL and specify its static section addresses.'
        ' Addresses should be comma-separated (no spaces) hex values, one per REL section.'
        ' Example: "807685a0,8076a558,8076a560,8076a570,8076a748,8076d460"')

    parsed_args = parser.parse_args(args)

    out_fp = parsed_args.output

    # Load rels and parse and assign addresses for their sections
    rels = []
    if parsed_args.rel is not None:
        for rel_fp, rel_addrs_str in parsed_args.rel:
            rel_fp = Path(rel_fp)

            rel_name = rel_fp.name.split('.')[0]

            with rel_fp.open('rb') as f:
                rel = code_files_rel.REL.from_file(f)
            rels.append((rel_name, rel))

            addrs = [int(p, 16) for p in rel_addrs_str.split(',')]

            filtered_sections = [s for s in rel.sections if not s.is_null()]

            if len(addrs) != len(filtered_sections):
                raise ValueError(
                    f'Expected {len(filtered_sections)} section addresses for REL,'
                    f' but got {len(addrs)} on the command line')

            # Apply static section addresses
            for section, addr in zip(filtered_sections, addrs):
                section.address = addr

    # Apply relocations, optionally verifying with a memdump
    xrefs = dump_all_relocations([rel for name, rel in rels])

    with open(out_fp, "w") as fd:
        json.dump(xrefs, fd)


if __name__ == '__main__':
    main()
