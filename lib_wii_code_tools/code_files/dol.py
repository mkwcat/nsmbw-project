# 2020-02-07 RoadrunnerWMC
# Loosely based on Cuyler36's Ghidra GameCube Loader

import struct

from . import CodeFile, CodeFileSection


class DOLSection(CodeFileSection):
    """
    Represents a single section in a .dol file
    """
    def __init__(self, address: int, size: int, data: bytes, is_executable: bool):
        self.address = address
        self.size = size
        self.is_executable = is_executable
        self.data = data


class DOL(CodeFile):
    """
    Represents a .dol executable file
    """
    def __init__(self, data: bytes):
        self.data = data
        self.read_header_and_sections()

    def read_header_and_sections(self) -> None:
        """
        Read the DOL header and sections data
        """
        offs = 0

        section_offsets = struct.unpack_from('>18I', self.data, offs)
        offs += 18 * 4

        section_addresses = struct.unpack_from('>18I', self.data, offs)
        offs += 18 * 4

        section_sizes = struct.unpack_from('>18I', self.data, offs)
        offs += 18 * 4

        bss_address, bss_size, self.entry_point = struct.unpack_from('>3I', self.data, offs)
        offs += 3 * 4

        assert offs == 0xE4

        # Load initialized sections
        self.sections = []
        for i, (offset, address, size) in enumerate(zip(section_offsets, section_addresses, section_sizes)):

            section = DOLSection(address, size, self.data[offset : offset + size], i < 7)
            if not section.is_null():
                self.sections.append(section)

        # Sort by address (needed for the way we create BSS sections)
        self.sections.sort(key=lambda section: section.address)

        # Load BSS sections.
        # The DOL header specifies one giant chunk of memory to zero out,
        # which covers all of the logical BSS sections and also overlaps
        # with some regular sections
        bss_end_address = bss_address + bss_size
        for section in self.sections:
            if bss_address < section.address:
                new_bss_section_end = min(section.address, bss_end_address)
                new_section = DOLSection(bss_address, new_bss_section_end - bss_address, None, False)
                self.sections.append(new_section)
            if bss_address < section.address + section.size:
                bss_address = section.address + section.size

        if bss_address < bss_end_address:
            new_section = DOLSection(bss_address, bss_end_address - bss_address, None, False)
            self.sections.append(new_section)

        # And finally, sort by address again
        self.sections.sort(key=lambda section: section.address)


extension = '.dol'
file_type = DOL
section_type = DOLSection
