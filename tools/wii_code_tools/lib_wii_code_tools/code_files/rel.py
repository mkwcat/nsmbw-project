# 2021-08-16 RoadrunnerWMC

import enum
import struct
from typing import BinaryIO

from . import CodeFile, CodeFileSection


def SEGMENT_OFF(x: int) -> int:
    """
    Clear the least significant bit of x. That bit is used in rel files
    to distinguish .text sections from .data, so it has to be cleared
    before you can use it as an actual offset.
    """
    return x & ~1


class RELSection(CodeFileSection):
    """
    Represents a single section in a .rel file
    """
    @classmethod
    def from_file(cls, file: BinaryIO, offset: int) -> 'RELSection':
        """
        Load a section from the given offset in the given file
        """
        self = cls()

        file.seek(offset)

        file_offset, size = struct.unpack_from('>II', file.read(8))

        self.size = size
        if file_offset == 0:
            self.data = None
        else:
            file.seek(SEGMENT_OFF(file_offset))
            self.data = file.read(size)

        self.is_executable = bool(file_offset & 1)

        return self


class RELRelocationType(enum.IntEnum):
    """
    Types of relocations.
    Names are from
    https://www.nxp.com/docs/en/reference-manual/E500ABIUG.pdf (p83)
    and
    http://wiki.tockdom.com/wiki/REL_(File_Format)#Relocation_Data
    """
    R_PPC_NONE = 0
    R_PPC_ADDR32 = 1
    R_PPC_ADDR24 = 2
    R_PPC_ADDR16 = 3
    R_PPC_ADDR16_LO = 4
    R_PPC_ADDR16_HI = 5
    R_PPC_ADDR16_HA = 6
    R_PPC_ADDR14 = 7
    R_PPC_ADDR14_BRTAKEN = 8
    R_PPC_ADDR14_BRNTAKEN = 9
    R_PPC_REL24 = 10
    R_PPC_REL14 = 11
    R_PPC_REL14_BRTAKEN = 12
    R_PPC_REL14_BRNTAKEN = 13
    R_DOLPHIN_NOP = 201
    R_DOLPHIN_SECTION = 202
    R_DOLPHIN_END = 203
    R_DOLPHIN_MRKREF = 204


class RELRelocation:
    """
    Represents a relocation in a .rel file
    """
    offset: int = 0
    type: RELRelocationType = RELRelocationType.R_PPC_NONE
    section: int = 0
    addend: int = 0

    @classmethod
    def from_file(cls, file: BinaryIO, offs: int) -> 'RELRelocation':
        """
        Load a relocation from the given offset in the given file
        """
        self = cls()

        file.seek(offs)
        self.offset, type, self.section, self.addend = struct.unpack_from('>HBBI', file.read(8))
        self.type = RELRelocationType(type)

        return self


class RELImport:
    """
    Represents an imp-table entry in a .rel file
    """
    module_num: int
    relocations: list

    def __init__(self):
        self.relocations = []

    @classmethod
    def from_file(cls, file: BinaryIO, offs: int) -> 'RELImport':
        """
        Load an import from the given offset in the given file
        """
        self = cls()

        file.seek(offs)
        self.module_num, reloc_offset = struct.unpack_from('>II', file.read(8))

        for i in range(99999):
            reloc = RELRelocation.from_file(file, reloc_offset + i * 8)
            self.relocations.append(reloc)
            if reloc.type == RELRelocationType.R_DOLPHIN_END:
                break
        else:
            print("WARNING: couldn't find the end of the imp table")

        return self


class REL(CodeFile):
    """
    Represents a .rel relocatable file
    """
    id: int
    sections: list
    name: str = None
    version: int
    bss_size: int
    imports: list

    prolog_section: int
    epilog_section: int
    unresolved_section: int
    prolog_offset: int
    epilog_offset: int
    unresolved_offset: int

    # version >= 2
    alignment: int = None
    bss_alignment: int = None
    # version >= 3
    fix_size: int = None

    def __init__(self):
        self.sections = []
        self.imports = []

    @classmethod
    def from_file(cls, file: BinaryIO) -> 'REL':
        """
        Load a REL file from a file-like object
        """
        self = cls()

        file.seek(0)

        # Read main header
        (self.id, _, _, num_sections,
            section_info_offset, name_offset, name_size, self.version,
            self.bss_size, rel_offset, imp_offset, imp_size,
            self.prolog_section, self.epilog_section, self.unresolved_section, _,
            self.prolog, self.epilog, self.unresolved) = struct.unpack_from('>12I4B3I', file.read(0x40))
        if self.version >= 2:
            self.alignment, self.bss_alignment = struct.unpack_from('>II', file.read(8))
        if self.version >= 3:
            self.fix_size = struct.unpack_from('>I', file.read(4))

        # Read name
        # note: this is just garbage in NSMBW
        if name_offset:
            file.seek(name_offset)
            self.name = file.read(name_size)
        else:
            self.name = None

        # Read sections
        for i in range(num_sections):
            section = RELSection.from_file(file, section_info_offset + i * 8)

            if not section.is_null() and (section.is_bss() and section.size != self.bss_size):
                raise ValueError(f".bss size doesn't match (expected {self.bss_size}, found {section.size})")

            self.sections.append(section)

        # Read imports
        for i in range(imp_size // 8):
            self.imports.append(RELImport.from_file(file, imp_offset + i * 8))

        return self


extension = '.rel'
file_type = REL
section_type = RELSection
