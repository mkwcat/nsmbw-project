#!/usr/bin/env python3

import argparse
import readline  # provides history and stuff for REPL
from typing import List, Optional

from lib_wii_code_tools.code_files.alf import hashes as alf_hashes


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='Hash a string using the ALF hash function.')

    parser.add_argument('string', nargs='?',
        help="the string to hash. It's a good idea to surround it in quotes (preferably single-quotes) so the shell doesn't eat special characters.")
    parser.add_argument('start_hash', nargs='?',
        help='the initial hash value to start with.')

    parsed_args = parser.parse_args(args)

    seed = parsed_args.start_hash
    if seed is None: seed = 0x1505
    else: seed = int(seed, 16)

    if parsed_args.string is None:
        print('(Use Ctrl+C or Ctrl+D to exit)')
        while True:
            hash = alf_hashes.hash(input('> '), seed=seed)
            print(f'{hash:08x}')
    else:
        hash = alf_hashes.hash(parsed_args.string, seed=seed)
        print(f'{hash:08x}')


if __name__ == '__main__':
    main()
