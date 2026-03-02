#!/usr/bin/env python3

import argparse, struct, copy
from wii_code_tools.lib_wii_code_tools.code_files import rel
from wii_code_tools.lib_wii_code_tools import nsmbw_constants, address_maps, common
from elftools.elf.elffile import ELFFile

def find_symbol(symtab, name):
    for sym in symtab.iter_symbols():
        if sym.name == name:
            return sym
    return None

def write_rel(rel_file, mod, import_count = None):
    if import_count is None:
        import_count = len(mod.imports)
    header_sections_size = 0x4C + len(mod.sections) * 0x8
    header_sections_size = (header_sections_size + mod.alignment - 1) & ~(mod.alignment - 1)
    full_size = header_sections_size + max((section.address + section.size for section in mod.sections if section is not None and section.data is not None), default=0)
    rel_file.write(struct.pack('>IIIIIIIIIIIIBBBBIIIIII',
                               mod.id, # id
                               0, # next
                               0, # prev
                               len(mod.sections), # numSections
                               0x4c, # sectionInfoOffset
                               0, # nameOffset
                               0, # nameSize
                               mod.version, # version
                               mod.bss_size, # bssSize
                               full_size + import_count * 0x8, # relOffset
                               full_size, # impOffset
                               import_count * 0x8, # impSize
                               mod.prolog_section, # prologSection
                               mod.epilog_section, # epilogSection
                               mod.unresolved_section, # unresolvedSection
                               0, # bssSection
                               mod.prolog_offset, # prologOffset
                               mod.epilog_offset, # epilogOffset
                               mod.unresolved_offset, # unresolvedOffset
                               mod.alignment, # alignment
                               mod.bss_alignment, # bssAlignment
                               full_size # fixSize
                               ))
    for section in mod.sections:
        if section is None:
            rel_file.write(struct.pack('>II', 0, 0))
        elif section.data is not None:
            rel_file.write(struct.pack('>II', header_sections_size + section.address | (1 if section.is_executable else 0), section.size))
        else:
            rel_file.write(struct.pack('>II', 0, section.size))
    # Pad and write section data
    for section in mod.sections:
        if section is not None and section.data is not None:
            address = header_sections_size + section.address
            padding = address - rel_file.tell()
            if padding > 0:
                rel_file.write(b'\x00' * padding)
            rel_file.write(section.data)
    # Pad to full_size and write import data
    current_pos = rel_file.tell()
    if current_pos < full_size:
        rel_file.write(b'\x00' * (full_size - current_pos))
    rel_offset = full_size + import_count * 0x8
    if mod.imports is not None and len(mod.imports) > 0:
        for imp in mod.imports:
            rel_file.write(struct.pack('>II', imp.module_num, rel_offset))
            rel_offset += len(imp.relocations) * 0x8
        for imp in mod.imports:
            for reloc in imp.relocations:
                rel_file.write(struct.pack('>HBBI', reloc.offset, reloc.type.value, reloc.section, reloc.addend & 0xFFFFFFFF))

def create_import_table(self_module_id, module_id, imports, out_sections, mapper_from = None, mapper_to = None):
    # Port all addresses in the relocations to the new region
    input_table = imports[module_id]
    if mapper_from is not None and mapper_to is not None and module_id != self_module_id:
        if module_id != 0:
            # Obtain address of import
            rel_name = nsmbw_constants.REL_NAMES[module_id - 1]
            target_sections_from = []
            target_sections_to = []
            for section in nsmbw_constants.REL_SECTION_NAMES:
                target_sections_from.append(nsmbw_constants.SECTION_ADDRESSES[mapper_from.name][rel_name][section][0])
                target_sections_to.append(nsmbw_constants.SECTION_ADDRESSES[mapper_to.name][rel_name][section][0])

        input_table = copy.deepcopy(input_table)
        for section in input_table:
            for reloc in input_table[section]:
                if module_id != 0:
                    assert (reloc.addend & 0x80000000) == 0
                reloc.addend += target_sections_from[reloc.section - 1] if module_id != 0 else 0
                reloc.addend = address_maps.map_addr_from_to(mapper_from, mapper_to, reloc.addend, error_handling=address_maps.UnmappedAddressHandling(errors=common.ErrorVolume.SILENT))
                reloc.addend -= target_sections_to[reloc.section - 1] if module_id != 0 else 0

    # Sort relocations by offset and then convert to REL format
    for section in input_table:
        input_table[section].sort(key=lambda r: r.offset)
    rel_import = rel.RELImport()
    rel_import.module_num = module_id
    for section in input_table:
        # Write change section relocation
        change_section_reloc = rel.RELRelocation()
        change_section_reloc.offset = 0
        change_section_reloc.type = rel.RELRelocationType.R_DOLPHIN_SECTION
        change_section_reloc.section = section
        change_section_reloc.addend = 0
        rel_import.relocations.append(change_section_reloc)
        current_offset = 0
        for reloc in input_table[section]:
            # Convert offset to adaptive
            adaptive_reloc = rel.RELRelocation()
            assert(reloc.offset < out_sections[section].size)
            offset = reloc.offset - current_offset
            while offset > 0xFFFF:
                # Add nop relocation to skip 0xFFFF bytes 
                nop_reloc = rel.RELRelocation()
                nop_reloc.offset = 0xFFFF
                nop_reloc.type = rel.RELRelocationType.R_DOLPHIN_NOP
                nop_reloc.section = 0
                nop_reloc.addend = 0
                rel_import.relocations.append(nop_reloc)
                offset -= 0xFFFF
            adaptive_reloc.offset = offset
            adaptive_reloc.section = reloc.section
            if reloc.type == rel.RELRelocationType.R_DOLPHIN_NOP:
                # Final fix for SDA21 relocations
                adaptive_reloc.type = rel.RELRelocationType.R_PPC_ADDR16_LO
                adaptive_reloc.addend = reloc.addend - nsmbw_constants.R2_R13_VALUES[mapper_to.name if mapper_to is not None else 'P1'][1]
            elif reloc.type == rel.RELRelocationType.R_DOLPHIN_END:
                adaptive_reloc.type = rel.RELRelocationType.R_PPC_ADDR16_LO
                adaptive_reloc.addend = reloc.addend - nsmbw_constants.R2_R13_VALUES[mapper_to.name if mapper_to is not None else 'P1'][0]
            else:
                adaptive_reloc.type = rel.RELRelocationType(reloc.type)
                adaptive_reloc.addend = reloc.addend
            rel_import.relocations.append(adaptive_reloc)
            current_offset = reloc.offset
    # Add end relocation
    end_reloc = rel.RELRelocation()
    end_reloc.offset = 0
    end_reloc.type = rel.RELRelocationType.R_DOLPHIN_END
    end_reloc.section = 0
    end_reloc.addend = 0
    rel_import.relocations.append(end_reloc)
    return rel_import

def main():
    parser = argparse.ArgumentParser(description="Make a .rel file from a .elf file")
    parser.add_argument("input", help="The .elf file to convert")
    parser.add_argument("output", help="The .rel file to output")
    parser.add_argument("module_id", type=int, help="The REL module ID")
    parser.add_argument("--imp", help="Port the import table to the specified region and output it as \"<output>.<region>.imp\"", action='append')
    parser.add_argument("--address-map", help="The address map to use when porting the import table (required if --imp is used)", nargs='?')
    args = parser.parse_args()

    elf = ELFFile(open(args.input, 'rb'))

    rela_sections = []
    symtab_section = None
    for section in elf.iter_sections():
        if section['sh_type'] == 'SHT_SYMTAB' and symtab_section is None:
            symtab_section = section
        elif section['sh_type'] == 'SHT_RELA':
            rela_sections.append(section)
    assert symtab_section is not None, "Couldn't find a symbol table in the ELF file"

    input_sections = [None]
    out_sections = [None]
    section_data_alignment = 0x4
    section_data_size = 0
    bss_alignment = 0
    bss_size = 0
    last_bss_section_index = 0
    for section_name in nsmbw_constants.REL_SECTION_NAMES:
        section = elf.get_section_by_name(section_name)
        if section is None or section['sh_size'] == 0:
            continue
        input_sections.append(section)
        if section['sh_type'] == 'SHT_NOBITS':
            rel_section = rel.RELSection()
            rel_section.data = None
            rel_section.size = section['sh_size']
            alignment = max(section['sh_addralign'], 4)
            bss_alignment = max(bss_alignment, alignment)
            bss_size_aligned = (bss_size + alignment - 1) & ~(alignment - 1)
            assert bss_alignment <= 0x20, "REL only loads with 0x20 alignment"
            if last_bss_section_index != 0:
                # Pad previous bss section to the alignment of this one
                out_sections[last_bss_section_index].size += bss_size_aligned - bss_size
            bss_size = bss_size_aligned + rel_section.size
            out_sections.append(rel_section)
            last_bss_section_index = len(out_sections) - 1
        else:
            rel_section = rel.RELSection()
            rel_section.data = section.data()
            rel_section.size = section['sh_size']
            alignment = max(section['sh_addralign'], 4)
            section_data_alignment = max(section_data_alignment, alignment)
            assert section_data_alignment <= 0x20, "REL only loads with 0x20 alignment"
            rel_section.address = (section_data_size + alignment - 1) & ~(alignment - 1)
            section_data_size = rel_section.address + rel_section.size
            rel_section.is_executable = (section['sh_flags'] & 0x4) != 0
            out_sections.append(rel_section)

    prolog = find_symbol(symtab_section, "_prolog")
    assert prolog is not None, "Couldn't find _prolog symbol in the ELF file"
    assert prolog['st_shndx'] != 'SHN_UNDEF', "_prolog symbol is in undefined section"
    assert elf.get_section(prolog['st_shndx']) is not None and elf.get_section(prolog['st_shndx']).name in nsmbw_constants.REL_SECTION_NAMES, "_prolog symbol is an unwritten section"
   
    epilog = find_symbol(symtab_section, "_epilog")
    assert epilog is not None, "Couldn't find _epilog symbol in the ELF file"
    assert epilog['st_shndx'] != 'SHN_UNDEF', "_epilog symbol is in undefined section"
    assert elf.get_section(epilog['st_shndx']) is not None and elf.get_section(epilog['st_shndx']).name in nsmbw_constants.REL_SECTION_NAMES, "_epilog symbol is an unwritten section"
   
    unresolved = find_symbol(symtab_section, "_unresolved")
    assert unresolved is not None, "Couldn't find _unresolved symbol in the ELF file"
    assert unresolved['st_shndx'] != 'SHN_UNDEF', "_unresolved symbol is in undefined section"
    assert elf.get_section(unresolved['st_shndx']) is not None and elf.get_section(unresolved['st_shndx']).name in nsmbw_constants.REL_SECTION_NAMES, "_unresolved symbol is an unwritten section"

    imports = {}
    for rela_section in rela_sections:
        relocated_section = elf.get_section(rela_section['sh_info'])
        if relocated_section is None or relocated_section not in input_sections:
            continue
        input_section_index = input_sections.index(relocated_section)
        rel_section = out_sections[input_section_index]
        for rela in rela_section.iter_relocations():
            symbol = symtab_section.get_symbol(rela['r_info_sym'])
            section_index = symbol['st_shndx']
            if section_index == 'SHN_UNDEF':
                section_index = None
                section = None
            else:
                section_index = int(section_index)
                section = elf.get_section(section_index)
            module_id = None
            relocation = None
            if section is not None and section in input_sections:
                module_id = args.module_id
                # Check if this relocation can be resolved now
                if section.data is not None and rela['r_info_type'] == rel.RELRelocationType.R_PPC_REL24 and input_section_index == input_sections.index(section):
                    target_offset = rela['r_addend'] + symbol['st_value']
                    instruction = struct.unpack_from('>I', rel_section.data, rela['r_offset'])[0]
                    instruction &= ~0x3FFFFFC
                    instruction |= (target_offset - rela['r_offset']) & 0x3FFFFFC
                    rel_section.data = rel_section.data[:rela['r_offset']] + struct.pack('>I', instruction) + rel_section.data[rela['r_offset']+4:]
                    continue

                relocation = rel.RELRelocation()
                relocation.offset = rela['r_offset']
                relocation.type = rela['r_info_type']
                relocation.section = input_sections.index(section)
                relocation.addend = rela['r_addend'] + symbol['st_value']
            else:
                addr = None
                # Check .external.<addr> sections
                if section is not None and section.name.startswith('.external.'):
                    try:
                        addr = int(section.name[10:], 0)
                    except:
                        print('Warning: Invalid .external section name: ' + section.name)
                        addr = None
                elif symbol.name.startswith('UNDEF_'):
                    try:
                        addr = int(symbol.name.split('_')[1], 16)
                    except:
                        print('Warning: Invalid UNDEF symbol name: ' + symbol.name)
                        addr = None
                elif symbol.name.startswith('ext_'):
                    try:
                        addr = int(symbol.name.split('_')[1], 16)
                    except:
                        print('Warning: Invalid ext symbol name: ' + symbol.name)
                        addr = None
                else:
                    print(f"Warning: Relocation to symbol {symbol.name} resolves to an unwritten section {section.name if section is not None else 'None'}")
                    continue

                if addr is None:
                    continue

                relocation = rel.RELRelocation()
                relocation.offset = rela['r_offset']
                addr += rela['r_addend']

                module_id = 0
                relocation.section = 0
                relocation.addend = addr

                # Check if the target address is inside a REL
                for rel_name in nsmbw_constants.SECTION_ADDRESSES['P1']:
                    if rel_name == 'main':
                        continue
                    rel_sections_info = nsmbw_constants.SECTION_ADDRESSES['P1'][rel_name]
                    for rel_section_name in nsmbw_constants.REL_SECTION_NAMES:
                        if rel_section_name not in rel_sections_info:
                            continue
                        rel_section_addr = rel_sections_info[rel_section_name][0]
                        rel_section_size = rel_sections_info[rel_section_name][1]
                        if addr >= rel_section_addr and addr < rel_section_addr + rel_section_size:
                            module_id = nsmbw_constants.REL_NAMES.index(rel_name) + 1
                            relocation.section = nsmbw_constants.REL_SECTION_NAMES.index(rel_section_name) + 1
                            relocation.addend = addr - rel_section_addr
                            break
                    if module_id != 0:
                        break
                
                if rela['r_info_type'] == 47: # R_PPC_TOC
                    # Use this relocation type to mimick SDA21, patched more later
                    instruction = struct.unpack_from('>I', rel_section.data, relocation.offset-2)[0]
                    # Find if closer to r13 or r2
                    r2 = nsmbw_constants.R2_R13_VALUES['P1'][0]
                    r13 = nsmbw_constants.R2_R13_VALUES['P1'][1]
                    if addr >= r13 - 0x8000 and addr < r13 + 0x8000:
                        reg = 13
                        relocation.type=rel.RELRelocationType.R_DOLPHIN_NOP # Temporary
                    elif addr >= r2 - 0x8000 and addr < r2 + 0x8000:
                        reg = 2
                        relocation.type=rel.RELRelocationType.R_DOLPHIN_END # Temporary
                    else:
                        print(f"Warning: Relocation to symbol {symbol.name} with address {addr:08x} is out of range of SDA21 access")
                        continue
                    
                    instruction |= (reg << 16)
                    rel_section.data = rel_section.data[:relocation.offset-2] + struct.pack('>I', instruction) + rel_section.data[relocation.offset+2:]
                else:
                    relocation.type = rela['r_info_type']

            if module_id is not None and relocation is not None:
                if module_id not in imports:
                    imports[module_id] = {}
                if input_section_index not in imports[module_id]:
                    imports[module_id][input_section_index] = []
                imports[module_id][input_section_index].append(relocation)

    # Port relocations
    address_map = address_maps.load_address_map(open(args.address_map, 'r'))
    default_imports = []
    regional_imports = {}
    for module_id in imports:
        if module_id != args.module_id and args.imp is not None and len(args.imp) > 0:
            mapper_from = address_map["P1"]
            for region in args.imp:
                mapper_to = address_map[region]
                if region not in regional_imports:
                    regional_imports[region] = []
                regional_imports[region].append(create_import_table(args.module_id, module_id, imports, out_sections, mapper_from, mapper_to))
        else:
            default_imports.append(create_import_table(args.module_id, module_id, imports, out_sections))

    mod = rel.REL()
    mod.id = args.module_id
    mod.sections = out_sections
    mod.version = 3
    mod.bss_size = bss_size
    mod.imports = []
    mod.prolog_section = input_sections.index(elf.get_section(prolog['st_shndx']))
    mod.epilog_section = input_sections.index(elf.get_section(epilog['st_shndx']))
    mod.unresolved_section = input_sections.index(elf.get_section(unresolved['st_shndx']))
    mod.prolog_offset = prolog['st_value']
    mod.epilog_offset = epilog['st_value']
    mod.unresolved_offset = unresolved['st_value']
    mod.alignment = section_data_alignment
    mod.bss_alignment = bss_alignment

    if len(regional_imports) == 0:
        mod.imports = default_imports
    else:
        mod.imports = []
    import_count = len(default_imports) + max(len(regional_imports[region]) for region in regional_imports if len(regional_imports[region]) > 0) if len(regional_imports) > 0 else 0

    with open(args.output, 'wb') as rel_file:
        write_rel(rel_file, mod, import_count)
        if len(regional_imports) != 0:
            import_table_module_ids = []
            import_table_sizes = []
            for regional in regional_imports:
                for index, import_entry in enumerate(regional_imports[regional]):
                    if len(import_table_sizes) <= index:
                        import_table_sizes.append(0)
                        import_table_module_ids.append(import_entry.module_num)
                    import_table_sizes[index] = max(import_table_sizes[index], len(import_entry.relocations) * 0x8)

            # Write import table
            imp_offset = rel_file.tell()
            rel_offset = imp_offset + import_count * 0x8
            for imp in default_imports:
                rel_file.write(struct.pack('>II', imp.module_num, rel_offset))
                rel_offset += len(imp.relocations) * 0x8
            for size_index, size in enumerate(import_table_sizes):
                rel_file.write(struct.pack('>II', import_table_module_ids[size_index], rel_offset))
                rel_offset += size

            # Write relocation entries for default imports
            for imp in default_imports:
                for reloc in imp.relocations:
                    rel_file.write(struct.pack('>HBBI', reloc.offset, reloc.type.value, reloc.section, reloc.addend & 0xFFFFFFFF))

            # Write relocation entries for regional imports to separate files
            for region in regional_imports:
                with open(f"{args.output}.{region}.imp", 'wb') as imp_file:
                    for index, imp in enumerate(regional_imports[region]):
                        for reloc in imp.relocations:
                            imp_file.write(struct.pack('>HBBI', reloc.offset, reloc.type.value, reloc.section, reloc.addend & 0xFFFFFFFF))
                        written = len(imp.relocations) * 0x8
                        if written < import_table_sizes[index]:
                            imp_file.write(b'\x00' * (import_table_sizes[index] - written))
        
main()