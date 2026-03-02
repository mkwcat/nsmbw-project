#!/usr/bin/env python3

from argparse import ArgumentParser
from elftools.elf.elffile import ELFFile
from demangle import *

argument_parser = ArgumentParser()
argument_parser.add_argument('elf_file_path')
argument_parser.add_argument('smap_file_path')
# optional dolphin map path
argument_parser.add_argument('dolphin_map_file_path', nargs='?')
args = argument_parser.parse_args()

with open(args.elf_file_path, 'rb') as elf_file_stream:
    elf_file = ELFFile(elf_file_stream)
    symtab_section = elf_file.get_section_by_name('.symtab')

    symbols = ""
    symbols_dolphin = ".text section layout\n"
    for symbol in symtab_section.iter_symbols():
        if symbol.entry['st_info']['type'] != 'STT_FUNC':
            continue

        st_shndx = symbol.entry['st_shndx']
        if st_shndx == 'ST_UNDEF':
            continue

        st_value = symbol.entry['st_value']
        length = 4

        section_name = elf_file.get_section(st_shndx).name
        if section_name.startswith('.external.'):
            st_value = int(section_name[10:], 0)
        else:
            # where the module block happens to be allocated
            st_value += 0x80B8E3B0
            length = symbol.entry['st_size']

        symbol_name = symbol.name

        if symbol_name.startswith('_MRel_extern_func'):
            continue

        try:
            p = ParseCtx(symbol_name)
            p.demangle()
            if p.to_str() != '':
                symbol_name = p.to_str()
        except:
            pass

        symbols += f"0x{st_value:08X} {symbol_name}\n"
        # Workaround for Dolphin HLE thing
        if symbol_name == 'OSPanic':
            symbol_name = 'OSPanic_'
        symbols_dolphin += f"{st_value:08x} {length:08x} {st_value:08x} 0 {symbol_name}\n"

with open(args.smap_file_path, 'w', newline='\n') as smap_file_stream:
    for item in sorted(symbols.split('\n')):
        smap_file_stream.write(item + '\n')

if args.dolphin_map_file_path and args.dolphin_map_file_path != "":
    with open(args.dolphin_map_file_path, 'w', newline='\n') as dolphin_map_file_stream:
        dolphin_map_file_stream.write(symbols_dolphin)