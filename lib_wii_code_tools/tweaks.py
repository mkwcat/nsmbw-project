import dataclasses
import re
from typing import Dict, List, TextIO


class SymbolsTweaker:
    """
    Represents one section of a symbols tweak file, corresponding to one version of the game.
    """
    additions: List['Addition']
    deletions: List['Deletion']
    renames: List['Rename']

    @dataclasses.dataclass
    class Addition:
        address: int
        name: str

        def __str__(self):
            return f'{self.address:08x} {self.name}'

        def __repr__(self):
            return f'<add {self!s}>'

    @dataclasses.dataclass
    class Deletion:
        address: int
        name: str

        def __str__(self):
            return f'{self.address:08x} {self.name}'

        def __repr__(self):
            return f'<delete {self!s}>'

    @dataclasses.dataclass
    class Rename:
        address_from: int
        address_to: int
        name_from: str
        name_to: str

        def __str__(self):
            return f'{self.address_from:08x} {self.address_to:08x} {self.name_from} {self.name_to}'

        def __repr__(self):
            return f'<rename {self!s}>'

    def __init__(self):
        self.additions = []
        self.deletions = []
        self.renames = []


# Type alias
SymbolsTweakMap = Dict[str, SymbolsTweaker]


def read_symbols_tweak_file(f: TextIO) -> SymbolsTweakMap:
    """
    Read a symbols tweak.txt file
    """
    tweaks = {'default': SymbolsTweaker()}

    comment_regex = re.compile(r'^\s*#')
    empty_line_regex = re.compile(r'^\s*$')
    section_regex = re.compile(r'^\s*\[([a-zA-Z0-9_.]+)\]$')
    section_add_regex = re.compile(r'^\s*add:\s*$')
    section_delete_regex = re.compile(r'^\s*delete:\s*$')
    section_rename_regex = re.compile(r'^\s*rename:\s*$')
    line_add_regex = re.compile(r'^\s*([a-fA-F0-9]{8})\s*(\S+)\s*(?:#.*)?$')
    line_delete_regex = line_add_regex  # same syntax
    line_rename_regex = re.compile(r'^\s*([a-fA-F0-9]{8})\s*([a-fA-F0-9]{8})\s*(\S+)\s*(\S+)\s*(?:#.*)?$')

    current_version_name = None
    current_version = None
    current_mode = None

    for line in f:
        line = line.rstrip('\n')

        if empty_line_regex.match(line):
            continue
        if comment_regex.match(line):
            continue

        match = section_regex.match(line)
        if match:
            # New version
            current_version_name = match.group(1)
            if current_version_name in tweaks:
                raise ValueError(f'tweaks file contains duplicate version name {current_version_name}')

            current_version = SymbolsTweaker()
            tweaks[current_version_name] = current_version
            current_mode = None
            continue

        if current_version is not None:
            # Try to associate something with the current version

            if section_add_regex.match(line):
                current_mode = 'add'
                continue
            if section_delete_regex.match(line):
                current_mode = 'delete'
                continue
            if section_rename_regex.match(line):
                current_mode = 'rename'
                continue

            if current_mode == 'add':
                match = line_add_regex.match(line)
                if match:
                    symbol_address = int(match.group(1), 16)
                    symbol_name = match.group(2)
                    current_version.additions.append(SymbolsTweaker.Addition(symbol_address, symbol_name))
                    continue

            elif current_mode == 'delete':
                match = line_delete_regex.match(line)
                if match:
                    symbol_address = int(match.group(1), 16)
                    symbol_name = match.group(2)
                    current_version.deletions.append(SymbolsTweaker.Deletion(symbol_address, symbol_name))
                    continue

            elif current_mode == 'rename':
                match = line_rename_regex.match(line)
                if match:
                    symbol_address_a = int(match.group(1), 16)
                    symbol_address_b = int(match.group(2), 16)
                    symbol_name_a = match.group(3)
                    symbol_name_b = match.group(4)
                    current_version.renames.append(
                        SymbolsTweaker.Rename(symbol_address_a, symbol_address_b, symbol_name_a, symbol_name_b))
                    continue

            else:
                raise ValueError(f'line "{line}" in version {current_version_name} is not in any section (add/delete/rename)')

        print(f'unrecognized line in tweaks file: {line}')

    return tweaks
