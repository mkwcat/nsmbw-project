import dataclasses
import enum
import re
from typing import Dict, Iterator, List, Optional, TextIO, Tuple

from . import common


# Optional import (`pip install intervaltree`), makes address lookups faster
try:
    from intervaltree import IntervalTree
except ImportError:
    IntervalTree = None


class UnmappedAddressHandling:
    """
    Describes how to handle unmapped addresses
    """

    class Behavior(enum.Enum):
        """
        How to map addresses that aren't covered by the address map
        """
        DROP = 'drop'
        PASSTHROUGH = 'passthrough'
        PREV_RANGE = 'prev_range'

        @classmethod
        def default(cls) -> 'Behavior':
            return cls.PASSTHROUGH

    errors: common.ErrorVolume = common.ErrorVolume.default()
    behavior: Behavior = Behavior.default()

    def __init__(self, errors:common.ErrorVolume=None, behavior:Behavior=None):
        if errors is not None:
            self.errors = errors
        if behavior is not None:
            self.behavior = behavior


class AddressMapper:
    """
    Represents one section of an address map file, corresponding to one version of the game.
    """
    base: Optional['AddressMapper'] = None

    # This is the same as its dict key. Redundant, yes, but super super
    # helpful in practice, so included anyway.
    # Usually you should use name_for_mapper() instead of accessing this directly.
    name: str = None

    itree_forwards: Optional[IntervalTree] = None
    itree_backwards: Optional[IntervalTree] = None

    @dataclasses.dataclass
    class Mapping:
        """
        A single line in the address mapping.
        Range is inclusive on both ends.
        """
        start: int = None
        end: int = None
        delta: int = None

        def overlaps(self, other: 'Mapping') -> bool:
            return (self.end >= other.start) and (self.start <= other.end)

        def __str__(self):
            return f'{self.start:08X}-{self.end:08X}: {"+" if self.delta >= 0 else "-"}0x{abs(self.delta):X}'

        def __repr__(self):
            return f'<mapping {self!s}>'

    mappings: List[Mapping]


    def __init__(self, base=None):
        self.base = base
        self.mappings = []

        if IntervalTree is not None:
            self.itree_forwards = IntervalTree()
            self.itree_backwards = IntervalTree()


    _mappings_sorted = None
    @property
    def mappings_sorted(self) -> List[Mapping]:
        if self._mappings_sorted is None:
            self._mappings_sorted = sorted(self.mappings, key=(lambda m: m.start))
        return self._mappings_sorted


    _mappings_sorted_reverse = None
    @property
    def mappings_sorted_reverse(self) -> List[Mapping]:
        if self._mappings_sorted_reverse is None:
            self._mappings_sorted_reverse = sorted(self.mappings, key=(lambda m: m.start + m.delta))
        return self._mappings_sorted_reverse


    def _invalidate_sorted_mappings(self) -> None:
        self._mappings_sorted = None
        self._mappings_sorted_reverse = None


    def add_mapping(self, start: int, end: int, delta: int) -> None:
        """
        Add a new mapping
        """
        if start > end:
            raise ValueError(f'cannot map {start:08X}-{end:08X} as start is higher than end')

        new_mapping = self.Mapping(start, end, delta)

        for mapping in self.mappings:
            if mapping.overlaps(new_mapping):
                raise ValueError(f'mapping "{new_mapping}" overlaps with earlier mapping "{mapping}"')

        self.mappings.append(new_mapping)
        self._invalidate_sorted_mappings()

        if IntervalTree is not None:
            self.itree_forwards[start : end + 1] = new_mapping
            self.itree_backwards[start + delta : end + delta + 1] = new_mapping


    def remap_single(self, address: int, *, error_handling=None) -> Optional[int]:
        """
        Map an address from self.base to self
        """
        if address is None: return None

        if IntervalTree is not None:
            result_set = self.itree_forwards[address]
            if result_set:
                assert len(result_set) == 1
                return address + next(iter(result_set)).data.delta

        else:
            # Fallback slow path
            mappings = self.mappings_sorted

            low = 0
            high = len(mappings) - 1
            while low <= high:
                mid = (low + high) // 2

                mapping = mappings[mid]
                if address < mapping.start:
                    high = mid - 1
                elif address > mapping.end:
                    low = mid + 1
                else:
                    return address + mapping.delta

        return self.handle_unmapped(address, error_handling)


    def remap_single_reverse(self, address: int, *, error_handling=None) -> Optional[int]:
        """
        Map an address from self to self.base
        """
        if address is None: return None

        if IntervalTree is not None:
            result_set = self.itree_backwards[address]
            if result_set:
                return address - next(iter(result_set)).data.delta

        else:
            # Fallback slow path
            mappings = self.mappings_sorted_reverse

            low = 0
            high = len(mappings) - 1
            while low <= high:
                mid = (low + high) // 2

                mapping = mappings[mid]
                if address < mapping.start + mapping.delta:
                    high = mid - 1
                elif address > mapping.end + mapping.delta:
                    low = mid + 1
                else:
                    return address - mapping.delta

        return self.handle_unmapped(address, error_handling, reverse_map=True)


    def remap(self, address: int, *, error_handling=None) -> int:
        """
        Map an address from default to self
        """
        if self.base is not None:
            address = self.base.remap(address, error_handling=error_handling)
        return self.remap_single(address, error_handling=error_handling)


    def remap_reverse(self, address: int, *, error_handling=None) -> int:
        """
        Map an address from self to default
        """
        address = self.remap_single_reverse(address, error_handling=error_handling)
        if self.base is not None:
            address = self.base.remap_reverse(address, error_handling=error_handling)
        return address


    def handle_unmapped(
            self,
            address: int,
            error_handling: UnmappedAddressHandling,
            *, reverse_map:bool=False) -> Optional[int]:
        """
        Handle fallback logic for when an address can't be mapped
        """
        if error_handling is None:
            error_handling = UnmappedAddressHandling()

        type_name = 'Warning' if error_handling.errors == common.ErrorVolume.WARNING else 'Error'

        map_from = self.base
        map_to = self

        if reverse_map:
            map_from, map_to = map_to, map_from

        map_from_name = name_for_mapper(map_from)
        map_to_name = name_for_mapper(map_to)

        if error_handling.errors != common.ErrorVolume.SILENT:
            # Find "before" and "after" mappings
            before = after = None
            if reverse_map:
                before = [x for x in self.mappings_sorted_reverse if x.end+x.delta < address]
                after = [x for x in self.mappings_sorted_reverse if x.start+x.delta > address]
            else:
                before = [x for x in self.mappings_sorted if x.end < address]
                after = [x for x in self.mappings_sorted if x.start > address]
            if before:
                before = before[-1]
            else:
                before = None
            if after:
                after = after[0]
            else:
                after = None

            # Build message
            msg = f'{type_name} [{map_from_name} -> {map_to_name}]: {address:08X} '
            if before is None and after is None:
                msg += "can't be mapped because there are no address ranges"
            elif before is None:
                msg += 'falls before first address range'
            elif after is None:
                msg += 'falls after last address range'
            else:
                rev = 'images of ' if reverse_map else ''
                msg += f'falls between {rev}"{before}" and "{after}"'

            if error_handling.errors == common.ErrorVolume.ERROR:
                raise ValueError(msg)
            elif error_handling.errors == common.ErrorVolume.WARNING:
                print(msg)

        # Assuming we didn't error out, return appropriate result
        if error_handling.behavior == UnmappedAddressHandling.Behavior.DROP:
            return None
        elif error_handling.behavior == UnmappedAddressHandling.Behavior.PASSTHROUGH:
            return address
        else:  # UnmappedAddressHandling.Behavior.PREV_RANGE
            if before is None:
                return address  # delta is implicitly +0x0 before the first address range
            else:
                if reverse_map:
                    return address - before.delta
                else:
                    return address + before.delta

    def is_identity(self) -> bool:
        """
        Return True if this mapper maps the entire 80000000-* address
        space to itself with no changes.
        """
        # First, check if any mappings in the meaningful range have
        # nonzero delta
        for mapper in self.mappings:
            if mapper.end >= 0x80000000 and mapper.delta != 0:
                return False

        # Now for a trickier problem: checking whether the mappings
        # actually cover the entire address space. There's probably a
        # fancy efficient algorithm for this, but I don't know it.

        # Instead, I just do this with the naive algorithm where you
        # just mark every byte that gets covered. But I keep it
        # practical by using a compressed address space that only
        # represents meaningful address values.

        meaningful_addresses = {0x80000000, 0xffffffff}
        for mapper in self.mappings:
            if mapper.start is not None and mapper.start > 0x80000000:
                meaningful_addresses.add(mapper.start - 1)
                meaningful_addresses.add(mapper.start)
            if mapper.end is not None:
                meaningful_addresses.add(mapper.end)
                meaningful_addresses.add(mapper.end + 1)

        compressed_addr_space = {}
        for i, addr in enumerate(sorted(meaningful_addresses)):
            compressed_addr_space[addr] = i

        compressed_memory_space = bytearray(len(meaningful_addresses))

        for mapper in self.mappings:
            start = compressed_addr_space[mapper.start or 0x80000000]
            end = compressed_addr_space[mapper.end or 0xffffffff]
            for caddr in range(start, end + 1):
                compressed_memory_space[caddr] = 1

        return all(compressed_memory_space)

    def is_default_equivalent(self) -> bool:
        """
        Return True if this mapper is equivalent to the "default" version.
        """
        return self.base is None and self.is_identity()


# Type alias
AddressMap = Dict[str, AddressMapper]


def load_address_map(f: TextIO) -> AddressMap:
    """
    Load an address map file, and return a dict of AddressMappers
    """
    mappers = {'default': AddressMapper()}

    comment_regex = re.compile(r'^\s*#')
    empty_line_regex = re.compile(r'^\s*$')
    section_regex = re.compile(r'^\s*\[([a-zA-Z0-9_.]+)\]$')
    extend_regex = re.compile(r'^\s*extend ([a-zA-Z0-9_.]+)\s*(#.*)?$')
    mapping_regex = re.compile(r'^\s*([a-fA-F0-9]{8})-((?:[a-fA-F0-9]{8})|\*)\s*:\s*([-+])0x([a-fA-F0-9]+)\s*(#.*)?$')
    current_version_name = None
    current_version = None

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
            if current_version_name in mappers:
                raise ValueError(f'versions file contains duplicate version name {current_version_name}')

            current_version = AddressMapper()
            mappers[current_version_name] = current_version
            continue

        if current_version is not None:
            # Try to associate something with the current version
            match = extend_regex.match(line)
            if match:
                base_name = match.group(1)
                if base_name not in mappers:
                    raise ValueError(f'version {current_version_name} extends unknown version {base_name}')
                if current_version.base is not None:
                    raise ValueError(f'version {current_version_name} already extends a version')

                current_version.base = mappers[base_name]
                continue

            match = mapping_regex.match(line)
            if match:
                start_address = int(match.group(1), 16)
                if match.group(2) == '*':
                    end_address = 0xFFFFFFFF
                else:
                    end_address = int(match.group(2), 16)

                delta = int(match.group(4), 16)
                if match.group(3) == '-':
                    delta = -delta

                current_version.add_mapping(start_address, end_address, delta)
                continue

        print(f'unrecognized line in versions file: {line}')

    for name, mapper in mappers.items():
        mapper.name = name

    return mappers


def name_for_mapper(mapper: AddressMapper) -> str:
    """
    bleh
    """
    if mapper is None:
        return 'default'
    return mapper.name


def lowest_common_ancestor(
        mapper_a: AddressMapper,
        mapper_b: AddressMapper,
        root:AddressMapper=None) -> AddressMapper:
    """
    Return the lowest common ancestor of the two mappers.
    """

    path_from_a_to_root = []
    current = mapper_a
    while current is not None:
        path_from_a_to_root.append(current)
        current = current.base

    current = mapper_b
    while current is not None:
        if current in path_from_a_to_root:
            return current
        current = current.base

    return root


def map_addr_from_to(
        mapper_from: AddressMapper,
        mapper_to: AddressMapper,
        address: int,
        *, error_handling=None) -> Optional[int]:
    """
    Map an address from one AddressMapper to another, as accurately as
    possible
    """
    if address is None: return None

    lca = lowest_common_ancestor(mapper_from, mapper_to)
    
    # Map the address backwards to the LCA
    current = mapper_from
    while current is not lca:
        address = current.remap_single_reverse(address, error_handling=error_handling)
        current = current.base

    # Map the address forwards from the LCA
    chain = []
    current = mapper_to
    while current is not lca:
        chain.append(current)
        current = current.base
    for current in reversed(chain):
        address = current.remap_single(address, error_handling=error_handling)

    return address


def iter_natural_chrono_order(map: AddressMap) -> Iterator[Tuple[str, AddressMapper]]:
    """
    Iterate over AddressMappers in a breadth-first-search-type order,
    starting at the default version. The mappers within each level are
    sorted alphabetically.
    """
    start = next(iter(map.values()))
    while start.base is not None:
        start = start.base

    base_names_to_children = {k: set() for k in map.keys()}
    for version, mapper in map.items():
        if mapper.name == 'default': continue
        base_names_to_children[name_for_mapper(mapper.base)].add(mapper)

    next_layer = {start}

    while next_layer:
        this_layer = next_layer
        for mapper in sorted(this_layer, key=lambda mapper: mapper.name):
            yield mapper.name, mapper

        next_layer = set()
        for mapper in this_layer:
            next_layer |= base_names_to_children[name_for_mapper(mapper)]
