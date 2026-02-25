from typing import Callable, Dict, List, Tuple

from . import common
from . import tweaks as lib_tweaks
from . import address_maps as lib_address_maps
from . import symbol_map_formats as lib_symbol_map_formats


ErrorVolume = common.ErrorVolume
name_for_mapper = lib_address_maps.name_for_mapper


class PortingIssuesHandling:
    """
    Describes how to handle issues with symbol-map porting
    """
    unmapped_addresses: lib_address_maps.UnmappedAddressHandling = None
    tweaks_errors: ErrorVolume = ErrorVolume.default()

    def __init__(self, unmapped_addresses=None, tweaks_errors=None):
        if unmapped_addresses is None:
            self.unmapped_addresses = lib_address_maps.UnmappedAddressHandling()
        else:
            self.unmapped_addresses = unmapped_addresses

        if tweaks_errors is not None:
            self.tweaks_errors = tweaks_errors


def handle_tweaks_error_list(
    error_list: List[str],
    error_handling: PortingIssuesHandling,
    map_from_name: str,
    map_to_name: str,
) -> None:
    """
    Handle a list of errors (strings) encountered while tweaking symbols
    """
    if error_handling is None:
        error_handling = PortingIssuesHandling()

    if error_handling.tweaks_errors == ErrorVolume.SILENT:
        return

    type_name = 'Warning' if error_handling.tweaks_errors == ErrorVolume.WARNING else 'Error'

    if len(error_list) == 1:
        msg_list = [f'{type_name} [{map_from_name} -> {map_to_name}]: {error_list[0]}']
    else:
        msg_list = [f'{type_name}s [{map_from_name} -> {map_to_name}]:']
        msg_list.extend('- ' + e for e in error_list)

    msg = '\n'.join(msg_list)

    if error_handling.tweaks_errors == ErrorVolume.ERROR:
        raise ValueError(msg)
    else:
        print(msg)


def remap_symbols_one_level(
    map_from_name: str,
    map_to_name: str,
    map: lib_symbol_map_formats.BasicSymbolMap,
    address_map_func: Callable[[int], int],
    additions: lib_symbol_map_formats.BasicSymbolMap,
    deletions: lib_symbol_map_formats.BasicSymbolMap,
    renames: Dict[int, Tuple[int, str, str]],
    *,
    error_handling: PortingIssuesHandling = None,
) -> lib_symbol_map_formats.BasicSymbolMap:
    """
    Remap a symbol table, with plenty of careful error checking. It's
    designed to be useful for both "forward" and "backward" traversal of
    the mappers graph; note that the signature doesn't even involve
    mappers at all.

    address_map_func should be a callable that converts addresses to the
        new mapping.
    additions is a dict of new symbols to add: {addr: name, ...}
    deletions is a dict of symbols to delete: {addr: name, ...}
    renames is a dict of symbols to rename:
        {addr: (expected_remapped_addr, old_name, new_name), ...}
    """
    error_list = []

    remapped = {}
    for addr, name in map.items():
        # Check if this symbol is marked for deletion; skip if so
        deletions_name = deletions.get(addr)
        if deletions_name:
            if name != deletions_name:
                error_list.append(f'tried to delete "{deletions_name}" from {addr:08X}, but it was actually called "{name}"')

            del deletions[addr]
            continue

        # Get the remapped address
        remapped_addr = address_map_func(addr)

        # If it's None, then the address can't be mapped and the user
        # elected to drop such symbols. So, skip.
        if remapped_addr is None:
            continue

        # Handle renaming info
        rename_info = renames.get(addr)
        if rename_info:
            expected_remapped_addr, old_name, new_name = rename_info
            if expected_remapped_addr != remapped_addr:
                error_list.append(f'tried to rename "{name}" at {addr:08X}, but the remapped address "{remapped_addr}" was expected to be "{expected_remapped_addr}"')
                continue
            if old_name != name:
                error_list.append(f'tried to rename "{name}" at {addr:08X}, but it was expected to be called "{old_name}"')
                continue

            name = new_name

        if remapped_addr in remapped:
            error_list.append(f'multiple symbols map to {remapped_addr:08X}: "{remapped[remapped_addr]}", "{name}"')
        else:
            remapped[remapped_addr] = name

    # Add new symbols
    for addr, name in additions.items():
        if addr in remapped:
            error_list.append(f'tried to add "{name}" at {addr:08X}, but there\'s already a symbol there ("{remapped[addr]}")')
            continue
        remapped[addr] = name

    # Ensure that we deleted everything we were supposed to
    for addr, name in deletions.items():
        error_list.append(f'did not find "{name}" at {addr:08X} to delete')

    # If there were errors, show them
    if error_list:
        handle_tweaks_error_list(error_list, error_handling, map_from_name, map_to_name)

    return remapped


def remap_symbols_one_level_down(
    mapper_from: lib_address_maps.AddressMapper,
    mapper_to: lib_address_maps.AddressMapper,
    map: lib_symbol_map_formats.BasicSymbolMap,
    tweaks: lib_tweaks.SymbolsTweaker,
    *,
    error_handling: PortingIssuesHandling = None,
) -> lib_symbol_map_formats.BasicSymbolMap:
    """
    Remap symbols from parent mapper to child mapper
    """
    if name_for_mapper(mapper_from) == 'default':
        mapper_from = None
    if mapper_to.base is not mapper_from:
        raise ValueError('must remap symbols forwards from parent to child')

    address_map_func = lambda a: mapper_to.remap_single(a, error_handling=error_handling.unmapped_addresses)
    additions_dict = {a.address: a.name for a in tweaks.additions}
    deletions_dict = {d.address: d.name for d in tweaks.deletions}
    renames_dict = {r.address_from: (r.address_to, r.name_from, r.name_to) for r in tweaks.renames}

    return remap_symbols_one_level(
        name_for_mapper(mapper_from), name_for_mapper(mapper_to),
        map, address_map_func,
        additions_dict, deletions_dict, renames_dict,
        error_handling=error_handling,
    )


def remap_symbols_one_level_up(
    mapper_from: lib_address_maps.AddressMapper,
    mapper_to: lib_address_maps.AddressMapper,
    map: lib_symbol_map_formats.BasicSymbolMap,
    tweaks: lib_tweaks.SymbolsTweaker,
    *,
    error_handling: PortingIssuesHandling = None,
) -> lib_symbol_map_formats.BasicSymbolMap:
    """
    Remap symbols from child mapper to parent mapper
    """
    if name_for_mapper(mapper_to) == 'default':
        mapper_to = None
    if mapper_from.base is not mapper_to:
        raise ValueError('must remap symbols backwards from child to parent')

    address_map_func = lambda a: mapper_from.remap_single_reverse(a, error_handling=error_handling.unmapped_addresses)

    # Since we're moving backwards, we want to *delete* symbols that
    # the tweaker says should be added, and *add* ones it says to
    # delete. That is, we need to swap deletions and additions.
    additions_dict = {d.address: d.name for d in tweaks.deletions}
    deletions_dict = {a.address: a.name for a in tweaks.additions}

    # We also swap the "to" and "from" fields in the renames, for the
    # same reason.
    renames_dict = {r.address_to: (r.address_from, r.name_to, r.name_from) for r in tweaks.renames}

    return remap_symbols_one_level(
        name_for_mapper(mapper_from), name_for_mapper(mapper_to),
        map, address_map_func,
        additions_dict, deletions_dict, renames_dict,
        error_handling=error_handling,
    )


def remap_symbols_to_all_versions(
    map: lib_symbol_map_formats.BasicSymbolMap,
    start_mapper_name: str,
    mappers: lib_address_maps.AddressMap,
    tweaks: lib_tweaks.SymbolsTweakMap,
    *,
    error_handling: PortingIssuesHandling = None,
    verbose: bool = False,
) -> Dict[str, lib_symbol_map_formats.BasicSymbolMap]:
    """
    Remap a symbol table dictionary to all other versions
    """
    # (No remapping to do for the version the map is initially for)
    remapped_syms = {start_mapper_name: map}

    # Mappers form a directed acyclic graph, with each node containing a
    # reference to its parent (`.base`). If you consider the 'default'
    # mapper to be the parent of all nodes with .base == None, the DAG
    # is more specifically a tree.

    # List off the children for each mapper
    mapper_children = {name: [] for name in mappers}
    for name, mapper in mappers.items():
        if name == 'default': continue
        mapper_children[name_for_mapper(mapper.base)].append(name)

    # First, we remap the symbols backwards from the start mapper to the
    # root. This is the shortest path to each of those mappers.
    current = mappers[start_mapper_name]
    while current.name != 'default':
        parent = current.base if current.base else mappers['default']

        if verbose:
            print(f'    Remapping from "{current.name}" backwards to "{parent.name}"...')

        remapped_syms[parent.name] = remap_symbols_one_level_up(
            current, parent, remapped_syms[current.name],
            tweaks.get(current.name, tweaks['default']),
            error_handling=error_handling)

        current = parent

    # Next, we remap from each of those mappers down to their children,
    # recursively.

    # Start by initializing the work list with the names of the mappers
    # we can map to right away
    able_to_map_down_to = []
    for name, mapper in mappers.items():
        if name_for_mapper(mapper.base) in remapped_syms and name not in remapped_syms:
            able_to_map_down_to.append(name)

    # Now use the work list to remap the symbols forwards until there
    # are no mappers left
    while able_to_map_down_to:
        current = mappers[able_to_map_down_to.pop()]
        parent = current.base if current.base else mappers['default']

        if verbose:
            print(f'    Remapping from "{parent.name}" forwards to "{current.name}"...')

        remapped_syms[current.name] = remap_symbols_one_level_down(
            parent, current, remapped_syms[parent.name],
            tweaks.get(current.name, tweaks['default']),
            error_handling=error_handling)

        # And remap to its children, too
        able_to_map_down_to.extend(mapper_children[current.name])

    # Make sure we got everything
    # This should always be true unless there's a bug in this function
    assert remapped_syms.keys() == mappers.keys(), \
        f'missed some mappers somehow ({mappers.keys() - remapped_syms.keys()})'

    # Done!
    return remapped_syms
