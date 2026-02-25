#!/usr/bin/env python3

import argparse
from typing import List, Optional

from lib_wii_code_tools import demangle as lib_demangle


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='Demangle a symbol.')

    parser.add_argument('symbol',
        help="the mangled symbol. It's a good idea to surround it in quotes (preferably single-quotes) so the shell doesn't eat special characters.")
    parser.add_argument('--nvidia', action='store_true',
        help="use a recreation of Nvidia's broken demangling algorithm instead of an accurate one")

    parsed_args = parser.parse_args(args)

    print(lib_demangle.demangle(parsed_args.symbol, nvidia=parsed_args.nvidia))


if __name__ == '__main__':
    main()
