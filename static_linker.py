#!/usr/bin/env python3

import argparse
from pathlib import Path
import struct
from typing import BinaryIO, List, Optional, Tuple

from lib_wii_code_tools import code_files
from lib_wii_code_tools.code_files import all as code_files_all
from lib_wii_code_tools.code_files import rel as code_files_rel
from lib_wii_code_tools import nsmbw_constants as lib_nsmbw_constants

# TODO: get rid of this dependency probably
import elftools.elf.enums as elf_enums  # pip install pyelftools


# Base address of mem1.raw memdump files
MEMDUMP_BASE = 0x80000000


def calculate_relocation_write_value(reloc: code_files_rel.RELRelocation, write_addr: int, addr_to_write: int, initial_value_32: int) -> Tuple[bool, int, int]:
    """
    Calculate the value and size to write to memory for the given
    relocation, given the target write address, the address to be
    written there, and the value already in memory there.

    Returns (should_write: bool, write_value: int, write_size: int).
    """
    RELRT = code_files_rel.RELRelocationType
    NO_WRITE = (False, None, None)

    rel_addr_to_write = addr_to_write - write_addr

    write_size = 4

    def verify_fits(addr_to_write: int, size: int, cleared_bottom_bits: int = 0, *, signed: bool = False) -> bool:
        """
        Verify that addr_to_write will fit into a field of size size
        which also requires that the bottom cleared_bottom_bits bits be
        cleared
        """
        if addr_to_write & ((1 << cleared_bottom_bits) - 1) != 0:
            return False
        addr_to_write >>= cleared_bottom_bits

        if signed:
            return -(1 << (size - 1)) <= addr_to_write < (1 << (size - 1))
        else:
            return 0 <= addr_to_write < (1 << size)

    def prepare_signed(value: int, size: int) -> int:
        """
        Convert a signed int to an unsigned int (two's complement) of
        arbitrary size
        """
        return value & ((1 << size) - 1)

    if reloc.type == RELRT.R_PPC_NONE:
        # No write.
        return NO_WRITE

    elif reloc.type == RELRT.R_PPC_ADDR32:
        # 32-bit write.
        new_value = addr_to_write

    elif reloc.type == RELRT.R_PPC_ADDR24:
        # 24-bit write, preserving the bottom 2 and top 6 bits of the initial u32.
        # Address must fit in that window or it's skipped
        if not verify_fits(addr_to_write, 24, 2):
            return NO_WRITE
        new_value = (initial_value_32 & 0xfc000003) | (addr_to_write & 0x03fffffc)

    elif reloc.type == RELRT.R_PPC_ADDR16:
        # 16-bit write.
        # Address must fit in 16 bits or it's skipped
        if not verify_fits(addr_to_write, 16):
            return NO_WRITE
        new_value = addr_to_write
        write_size = 2

    elif reloc.type == RELRT.R_PPC_ADDR16_LO:
        # 16-bit write.
        # Take the bottom half of the address
        new_value = addr_to_write & 0xffff
        write_size = 2

    elif reloc.type == RELRT.R_PPC_ADDR16_HI:
        # 16-bit write.
        # Take the top half of the address
        new_value = addr_to_write >> 16
        write_size = 2

    elif reloc.type == RELRT.R_PPC_ADDR16_HA:
        # 16-bit write.
        # Uses the "high adjusted" value of the address:
        # https://www.nxp.com/docs/en/reference-manual/E500ABIUG.pdf, p83
        new_value = ((addr_to_write >> 16) + (1 if (addr_to_write & 0x8000) else 0)) & 0xFFFF
        write_size = 2

    elif reloc.type in [RELRT.R_PPC_ADDR14, RELRT.R_PPC_ADDR14_BRTAKEN, RELRT.R_PPC_ADDR14_BRNTAKEN]:
        # 14-bit write, preserving the bottom 2 and top 16 bits of the initial u32.
        # Address must fit in that window or it's skipped
        if not verify_fits(addr_to_write, 14, 2):
            return NO_WRITE
        new_value = (initial_value_32 & 0xffff0003) | (addr_to_write & 0x0000fffc)

    elif reloc.type == RELRT.R_PPC_REL24:
        # 24-bit write, preserving the bottom 2 and top 6 bits of the initial u32.
        # Relative address is used instead of absolute.
        # Relative address must fit in that window or it's skipped
        if not verify_fits(rel_addr_to_write, 24, 2, signed=True):
            return NO_WRITE
        new_value = (initial_value_32 & 0xfc000003) | (prepare_signed(rel_addr_to_write, 26) & 0x03fffffc)

    elif reloc.type in [RELRT.R_PPC_REL14, RELRT.R_PPC_REL14_BRTAKEN, RELRT.R_PPC_REL14_BRNTAKEN]:
        # 14-bit write, preserving the bottom 2 and top 16 bits of the initial u32.
        # Relative address is used instead of absolute.
        # Relative address must fit in that window or it's skipped
        if not verify_fits(rel_addr_to_write, 14, 2, signed=True):
            return NO_WRITE
        new_value = (initial_value_32 & 0xffff0003) | (prepare_signed(rel_addr_to_write, 16) & 0x0000fffc)

    else:
        raise ValueError(f'Unknown relocation type: {reloc.type}')

    return True, new_value, write_size


def apply_all_relocations(
        dol: code_files.CodeFile, rels: List[code_files_rel.REL],
        *, memdump_file_for_verification: BinaryIO = None, dump_relocs: bool = False) -> None:
    """
    Apply all REL relocations, in-place
    """

    def verify(addr: int, value: int, write_size: int) -> None:
        """
        Verify that the value given, of specified size, appears in the
        memdump file at the specified address.
        Raises an exception if it doesn't match.
        """
        nonlocal memdump_file_for_verification
        if memdump_file_for_verification is None:
            return

        memdump_file_for_verification.seek(addr - MEMDUMP_BASE)
        real_value = int.from_bytes(memdump_file_for_verification.read(write_size), 'big')
        if value != real_value:
            raise ValueError(f'Verification via memdump: {addr:08X}: expected {value:08X} but correct value is actually {real_value:08X}')

    # Make an id -> module map
    modules = {0: dol}
    for rel in rels:
        if rel.id in modules:
            raise ValueError(f'Duplicate REL ID: {rel.id}')
        modules[rel.id] = rel

    # Switch everything to bytearrays
    for module in modules.values():
        for section in module.sections:
            if section.data:
                section.data = bytearray(section.data)

    # Apply all imports
    for rel in rels:
        for imp in rel.imports:
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
                target_bytearray = rel.sections[section_id].data

                addr_to_write = reloc.addend
                if imp.module_num > 0:
                    addr_to_write += importing_from_module.sections[reloc.section].address

                initial_value_32, = struct.unpack_from('>I', target_bytearray, write_pos)
                should_write, write_value, write_size = \
                    calculate_relocation_write_value(reloc, write_addr, addr_to_write, initial_value_32)

                if dump_relocs:
                    raw_reloc_table_data = struct.pack('>HBBI', reloc.offset, reloc.type.value, reloc.section, reloc.addend)

                    if write_size == 2:
                        write_value_str = f'    {write_value:02x}'
                    else:
                        write_value_str = f'{write_value:04x}'

                    msg = []
                    msg.append(f'{raw_reloc_table_data.hex()}:')
                    msg.append(f' "write {write_value_str} to {write_addr:08x}, linking it to {addr_to_write:08x}"')
                    if not should_write:
                        msg.append(' (invalid; skipping)')

                    print(''.join(msg))

                if should_write:
                    if memdump_file_for_verification:
                        try:
                            verify(write_addr, write_value, write_size)
                        except ValueError:
                            raise ValueError(
                                f'Memdump verification failed for reloc {reloc.type}'
                                f' (trying to write address {addr_to_write:08X} into field'
                                f' with initial value {initial_value_32:08X})')

                    struct_string = {2: '>H', 4: '>I'}[write_size]
                    struct.pack_into(struct_string, target_bytearray, write_pos, write_value)

    # Switch everything back to bytes
    for module in modules.values():
        for section in module.sections:
            if section.data:
                section.data = bytes(section.data)


def create_elf_from_sections(sections: List[code_files.CodeFileSection], section_names: List[str], section_perms: List[lib_nsmbw_constants.Permissions], *, entry_point:int=0) -> bytes:
    """
    Given sections, section names, and section permissions, create an
    ELF file out of them.
    Relocatable sections are unsupported -- all sections must have
    static addresses.
    """
    # Make copies of the input lists because we'll be modifying them
    # (.shrtrtab)
    sections = list(sections)
    section_names = list(section_names)
    section_perms = list(section_perms)

    # Ghidra's Program Trees pane is in reverse order unless we do this??
    sections.reverse()
    section_names.reverse()
    section_perms.reverse()

    # Quick sanity check
    for section in sections:
        if section.address is None:
            raise ValueError('create_elf_from_sections() requires all sections to have static addresses')

    # Let's start by building .shrtrtab
    section_names.append('.shrtrtab')

    shrtrtab_data = bytearray()

    shrtrtab_offsets = []
    for name in section_names:
        shrtrtab_offsets.append(len(shrtrtab_data))
        shrtrtab_data += name.encode('ascii') + b'\0'

    shrtrtab = code_files.CodeFileSection()
    shrtrtab.address = 0
    shrtrtab.data = bytes(shrtrtab_data)
    shrtrtab.size = len(shrtrtab_data)
    shrtrtab.is_executable = False

    e_shstrndx = len(sections)
    sections.append(shrtrtab)
    section_perms.append(lib_nsmbw_constants.Permissions.none())

    # Start the elf data
    elf = bytearray()

    def align_elf(alignment):
        nonlocal elf
        if len(elf) % alignment:
            elf += b'\0' * (alignment - (len(elf) % alignment))
        assert len(elf) % alignment == 0

    # Skip the header for now, we'll come back to it when we have
    # offsets and stuff
    elf += b'\0' * 0x40

    # Skip the program headers, too
    e_phoff = len(elf)
    e_phentsize = 0x20

    elf += b'\0' * (e_phentsize * len(sections))

    # Add section data
    section_offsets = []
    for section in sections:
        if section.is_bss():
            section_offsets.append(0)
        else:
            section_offsets.append(len(elf))
            elf += section.data
            align_elf(0x10)

    # Fill in the program headers
    PF_X = 1
    PF_W = 2
    PF_R = 4
    for i, (offset, section, perms) in enumerate(zip(section_offsets, sections, section_perms)):
        if section is shrtrtab:
            # Don't want .shrtrtab to be loaded at all
            continue

        p_flags = 0
        if perms & lib_nsmbw_constants.Permissions.R:
            p_flags |= PF_R
        if perms & lib_nsmbw_constants.Permissions.W:
            p_flags |= PF_W
        if perms & lib_nsmbw_constants.Permissions.X:
            p_flags |= PF_X

        struct.pack_into('>8I', elf, e_phoff + e_phentsize * i,
            # ==== 0x00 ====
            elf_enums.ENUM_P_TYPE_BASE['PT_LOAD'],
            offset,
            section.address,
            0,
            # ==== 0x10 ====
            0 if section.is_bss() else len(section.data),
            section.size,
            p_flags,
            0,
        )

    # Add the section headers
    SHF_WRITE = 0x1
    SHF_ALLOC = 0x2
    SHF_EXECINSTR = 0x4
    SHF_STRINGS = 0x20
    e_shoff = len(elf)
    e_shentsize = 0x28
    for offset, sh_name, section, perms in zip(section_offsets, shrtrtab_offsets, sections, section_perms):

        if section is shrtrtab:
            sh_type = elf_enums.ENUM_SH_TYPE_BASE['SHT_STRTAB']
        elif section.is_bss():
            sh_type = elf_enums.ENUM_SH_TYPE_BASE['SHT_NOBITS']
        else:
            sh_type = elf_enums.ENUM_SH_TYPE_BASE['SHT_PROGBITS']

        sh_flags = 0
        if perms & lib_nsmbw_constants.Permissions.R:
            sh_flags |= SHF_ALLOC
        if perms & lib_nsmbw_constants.Permissions.W:
            sh_flags |= SHF_WRITE
        if perms & lib_nsmbw_constants.Permissions.X:
            sh_flags |= SHF_EXECINSTR
        if section is shrtrtab:
            sh_flags |= SHF_STRINGS

        elf += struct.pack('>10I',
            # ==== 0x00 ====
            sh_name,
            sh_type,
            sh_flags,
            section.address,
            # ==== 0x10 ====
            offset,
            section.size,
            0,
            0,
            # ==== 0x20 ====
            4,
            0,
        )

    # Now go back and fill in the elf header

    #                     0x00       0x10    0x20    0x30
    struct.pack_into('>' '4s 5B 7x' '2H 3I' '2I 4H' '2H 12x', elf, 0,
        # ==== 0x00 ====
        b'\x7fELF',
        elf_enums.ENUM_EI_CLASS['ELFCLASS32'],
        elf_enums.ENUM_EI_DATA['ELFDATA2MSB'],
        elf_enums.ENUM_E_VERSION['EV_CURRENT'],
        elf_enums.ENUM_EI_OSABI['ELFOSABI_SYSV'],  # aka ELFOSABI_NONE
        0,  # EI_ABIVERSION
        # ==== 0x10 ====
        elf_enums.ENUM_E_TYPE['ET_NONE'],
        elf_enums.ENUM_E_MACHINE['EM_PPC'],
        elf_enums.ENUM_E_VERSION['EV_CURRENT'],
        entry_point,
        e_phoff,
        # ==== 0x20 ====
        e_shoff,
        0,  # e_flags
        0x34,
        e_phentsize,
        len(sections),
        e_shentsize,
        # ==== 0x30 ====
        len(sections),
        e_shstrndx,
    )

    return bytes(elf)


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function for the application
    """

    parser = argparse.ArgumentParser(
        description='Given a DOL, some RELs, and the addresses their sections are known to end up at, apply all relocations, linking them to the DOL and to each other.')

    parser.add_argument('main_code_file', type=Path,
        help='input DOL or ALF file')
    # "elf" is more convenient, but "binfolder" produces better Ghidra
    # projects and I kind of want to push people towards that option,
    # so... not sure what the default should be. So I defer for now by
    # requiring the user to pick one explicitly
    parser.add_argument('-f', '--output-format', choices=['elf', 'binfolder'], required=True,
        help='whether to save output as an ELF file, or as a folder of bin files')
    parser.add_argument('-o', '--output', type=Path,
        help='the output ELF file, or folder to save bin files to (will be created if nonexistent)')
    parser.add_argument('--memdump', type=Path,
        help='optional memory dump (Dolphin: mem1.raw) to verify that relocations are applied correctly')
    parser.add_argument('--rel', nargs=2, action='append', metavar=('REL', 'ADDRS'),
        help='add a REL and specify its static section addresses.'
        ' Addresses should be comma-separated (no spaces) hex values, one per REL section.'
        ' Example: "807685a0,8076a558,8076a560,8076a570,8076a748,8076d460"')
    parser.add_argument('--debug-dump-relocs', action='store_true',
        help='for debugging: print info about the relocations table')

    parsed_args = parser.parse_args(args)

    if parsed_args.output is None:
        if parsed_args.output_format == 'elf':
            out_fp = parsed_args.main_code_file.with_suffix('.elf')
        else:
            out_fp = parsed_args.main_code_file.with_suffix('.out')
    else:
        out_fp = parsed_args.output

    # Load dol
    dol = code_files_all.load_by_extension(parsed_args.main_code_file.read_bytes(), parsed_args.main_code_file.suffix)

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
    aar_args = [dol, [rel for name, rel in rels]]
    aar_kwargs = {}
    if parsed_args.debug_dump_relocs:
        aar_kwargs['dump_relocs'] = True

    if parsed_args.memdump:
        with parsed_args.memdump.open('rb') as f:
            apply_all_relocations(*aar_args, memdump_file_for_verification=f, **aar_kwargs)
    else:
        apply_all_relocations(*aar_args, **aar_kwargs)

    # Gather all sections and their names and permissions
    sections = []
    section_names = []
    section_perms = []

    sections.extend(dol.sections)
    for sec_name in lib_nsmbw_constants.DOL_SECTION_NAMES:
        section_names.append(sec_name)
        section_perms.append(lib_nsmbw_constants.DOL_SECTION_INFO[sec_name]['permissions'])

    for rel_name, rel in rels:
        sections.extend(s for s in rel.sections if not s.is_null())
        for sec_name in lib_nsmbw_constants.REL_SECTION_NAMES:
            section_names.append(rel_name + sec_name)
            section_perms.append(lib_nsmbw_constants.REL_SECTION_INFO[sec_name]['permissions'])

    # The user already has most of this info, but print it in a nice
    # table anyway for convenience
    for i, (section, name, perms) in enumerate(zip(sections, section_names, section_perms)):
        perms_r = 'R' if perms & lib_nsmbw_constants.Permissions.R else ' '
        perms_w = 'W' if perms & lib_nsmbw_constants.Permissions.W else ' '
        perms_x = 'X' if perms & lib_nsmbw_constants.Permissions.X else ' '
        initialized = ' ' if section.is_bss() else 'I'
        print(f'{i:02d}  {section.address:08x}-{section.address+section.size:08x}  {perms_r}{perms_w}{perms_x}  {initialized}  {name}')

    if parsed_args.output_format == 'elf':
        elf = create_elf_from_sections(sections, section_names, section_perms, entry_point=dol.entry_point)
        out_fp.write_bytes(elf)

    else:
        out_fp.mkdir(parents=True, exist_ok=True)

        for i, (section, name) in enumerate(zip(sections, section_names)):
            if section.is_bss():
                section_data = b'\0' * section.size
            else:
                section_data = section.data

            (out_fp / f'{i:02d}_{name}.bin').write_bytes(section_data)


if __name__ == '__main__':
    main()
