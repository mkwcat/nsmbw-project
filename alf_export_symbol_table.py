#!/usr/bin/env python3

import argparse
from pathlib import Path
from typing import List, Optional

from lib_wii_code_tools.code_files import alf as code_files_alf


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description='Export symbol hashes from an ALF file to a text file.')

    parser.add_argument('alf_file', type=Path,
        help='alf file to read')
    parser.add_argument('output_file', type=Path,
        help='text file to write output to')

    parsed_args = parser.parse_args(args)

    alf = code_files_alf.ALF(parsed_args.alf_file.read_bytes())

    with parsed_args.output_file.open('w', encoding='utf-8') as f:
        for section in alf.sections:
            for symbol in section.symbols:
                line_contents = [
                    f'0x{symbol.address:08x}',
                    f'0x{symbol.size:08x}',
                    symbol.raw_name,
                    symbol.demangled_name,
                    'data' if symbol.is_data else 'code',
                ]
                if symbol.unk10 is not None:
                    line_contents.append(str(symbol.unk10))
                f.write(' '.join(line_contents) + '\n')


if __name__ == '__main__':
    main()
