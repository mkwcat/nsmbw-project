#!/usr/bin/env python3

from sys import argv
from elftools.elf.elffile import ELFFile
import re

xml = open(argv[1], 'r').read()
elf_file = ELFFile(open(argv[2], 'rb'))
text_section = elf_file.get_section_by_name('.text')
output = open(argv[4], 'w')

# Remove indentation and newlines
xml = xml.replace('    ', '').replace('\r', '').replace('\n', '')

# Find and remove comments
xml = re.sub(r'<!--.*?-->', '', xml)

xml = xml.replace("${INSERT_VERSION}", argv[3])
xml = xml.replace("${INSERT_LOADER_DATA}", text_section.data().hex().upper())
output.write(xml)
output.close()
