#!/usr/bin/env python3

import argparse
from typing import List, Optional


def unhash_one(h: int, c: str) -> int:
    return ((h ^ ord(c)) * 1041204193) & 0xFFFFFFFF


def unhash(h: int, s: str) -> int:
    for c in reversed(s):
        h = unhash_one(h, c)
    return h


def main(args: Optional[List[str]] = None) -> None:
    """
    Main function
    """
    parser = argparse.ArgumentParser(
        description='Remove a suffix from an ALF hash.')

    parser.add_argument('hash',
        help="the initial hash value")

    parser.add_argument('string',
        help="the suffix to remove. It's a good idea to surround it in quotes (preferably single-quotes) so the shell doesn't eat special characters.")

    parsed_args = parser.parse_args(args)

    hash = unhash(int(parsed_args.hash, 16), parsed_args.string)
    print(f'{hash:08x}')


if __name__ == '__main__':
    main()
