# Wii Code Tools

This is a giant collection of Python tools and libraries I've developed while working on address and symbol maps for *New Super Mario Bros. Wii*. Much of it can probably be applied to other Wii (maybe also GameCube) games as well.

Some tools use hardcoded section name and/or executability information known to be correct for NSMBW. I think this is probably valid for most commercial Wii games, but I haven't checked. I've put a note below for each tool that does this. I might try to de-hardcode some of these in the future, where possible.

This readme will explain what each tool and library is *for* rather than exactly how to use them. All of the tools use argparse, so you can view command-line usage by running them with `-h`.

In alphabetical order:

## Tools

Some of which are also used as libraries by other tools.

### alf_export_symbol_table.py

A very simple script that exports symbol-table information from an ALF file to a text file for easy viewing. The columns are "address", "size", "raw name", "demangled name", and "data or code".

Although the "name" fields are as strings, their actual contents are just hash values (in uppercase hexadecimal ASCII, prefixed with "#") in all released Lingcod games.

### alf_hash.py

Takes a string argument and prints its hash value, using the ALF symbol table hash algorithm (the "xor" version of "djb2").

If run with no argument, starts an interactive prompt that displays the hash of each line you enter.

### alf_to_dol.py

**Assumes NSMBW section executabilities**

Convert an ALF file to a DOL file. Several other tools for this exist, but this one was written independently by me.

### alf_unhash.py

ALF hashes have the interesting property that if you know the hash of an unknown string *S = a + b*, and you know the suffix *b*, it's possible to use multiplicative inverses to "undo" *b* from the hash value to calculate the hash of *a*, even though you don't know *a* itself.

This script implements that. It takes the ALF hash value (hexadecimal number) of an unknown string, and a string which you think is a suffix of it, and "undoes" the suffix from the hash value. If the string isn't actually a suffix of the hash you provided, the output value will be meaningless.

### auto_align_by_data.py

This tool automatically generates an approximate address map (only intended as a guide for manual use -- doesn't perfectly conform to actual address-map syntax) between two provided code files. Since this script works by comparing the data of various sections, .bss sections can't be checked -- see auto_align_by_xrefs.py for a solution for that.

The addresses won't be very precise, and it may give weird output in some places, but the output is only intended to be used as a rough guide to help you make a proper address map manually, anyway. You can usually ignore small matched areas with weird/unexpected offsets, and focus on the larger ones with offsets that make more sense. The lower address of each range is meaningful, but the upper address isn't (it's just the next range's lower address minus 1).

Since this script involves comparing *random* snippets of data between the two files to help line them up, the output may vary somewhat each time you run it.

Be patient -- this script takes about 3 minutes to run for NSMBW on my machine.

### auto_align_by_xrefs.py

This tool is intended to help with creating address maps. It's particularly useful for .bss sections. It only works if you already have an address map that's at least partially finished, ideally covering all of .text at minimum.

This script provides a small Ghidra plugin in a comment at the top of the file, which exports all cross-reference information from a database to a JSON file. Run the plugin on (ideally brand-new, so they're easy to compare) databases for two game versions you'd like to create a mapping for, to get two JSON files. Then this script will compare them and output a suggested approximate address map for the address range you specify. (Usually it's pretty accurate, but not always -- be sure to check the output by hand and adjust it if needed.)

### autogen_symbol_map_from_padding.py

**Assumes NSMBW section executabilities** if reading from an ALF file

This tool helps with finding function addresses. In NSMBW (and probably at least some other games), most functions are aligned to 0x10 using null words. The null word isn't a valid PowerPC instruction, so you can scan for this null padding to infer the addresses of many (but not all) functions. That's what this script does.

### canonicalize_symbol_names_in_text_file.py

This is fairly specific to a particular task I had once, but I'm including it anyway.

This tool scans a text file for placeholder symbol names such as "`FUN_P1_802bb6c0`" and "`DAT_K_802f60a0`" (the middle part is the game version as defined in an address map), and tries to replace them with "canonical" versions by doing the following:

* It tries to match the address (via the address map) to a real symbol from one of the symbol maps you provide.
* If that fails, it maps the address to the earliest game version it exists in, and uses that as the replacement (e.g. "FUN_C_800c8fc0" -> "FUN_P1_800c8d10").

### combine_symbol_maps.py

**Assumes NSMBW section names and executabilities**

This overlays one or more symbol maps on top of each other to produce a combined symbol map. It supports all input and output formats supported by `lib_wii_code_tools.symbol_map_formats`. By providing just one symbol map, you can use this to convert a symbol map from one format to another. The maps must all be for the same game version.

### demangle_symbol.py

A frontend for `lib_wii_code_tools.demangle` which lets you demangle a symbol using either a working algorithm or a recreation of Nvidia's broken algorithm.

### find_rel_in_mem_dump.py

Scans a Wii memory dump (such as a `mem1.raw` from Dolphin Emulator) for a .rel file, and prints the address each section was loaded to.

### map_address.py

Uses an address map to map a single address from one version to another. This is probably the tool I've invoked the most times out of any of them.

### port_symbol_map.py

**Assumes NSMBW section names and executabilities**

Uses an address map and optional tweak map to port a symbol map from one game version to another, or to all other game versions at once.

### static_linker.py

**Assumes NSMBW section names and executabilities**

Statically links a DOL with one or more RELs, and produces output either in the form of an ELF file or a folder of .bin files containing section data.

### verify_address_map.py

**Assumes NSMBW section executabilities** if reading from an ALF file

Compares two game binaries through an address map and warns for any differences. Intended to help in address map development, and for proving their correctness.

For executable sections, only instruction opcodes are compared, not operands. For data sections, mismatching values that look like pointers are themselves checked against the address map, and no warning is produced if they're consistent with it. (Since forward references can be problematic when creating an address map in linear address-space order, there's an option to ignore *all* values that look like pointers, without checking them against the address map. This should be turned off once you reach the end of each DOL or REL.)

## `lib_wii_code_tools` Package

### code_files

A sub-package for loading DOL, REL and ALF files with a consistent interface.

### address_maps

An implementation of the address-map text file format used in [Kamek](https://github.com/Treeki/Kamek).

Supports both loading and saving, though formatting and comments aren't preserved.

Also supports mapping addresses between any version pair, instead of just from parents to children. An `error_handling` parameter lets you specify how you'd like to proceed if the address can't be mapped from one version along the path to the next.

This uses [intervaltree](https://pypi.org/project/intervaltree/) for speedup if it's available, but also has fallback logic if it's not.

### demangle

Provides a function to demangle a CodeWarrior-mangled symbol.

A boolean parameter lets you choose between two implementations:

- A correct (as far as we know) demangler, [from here](https://gist.github.com/aboood40091/8ce65132bf2c1abe426df91de994331d).
- A bug-for-bug (as far as we know) reimplementation of the demangler used by Nvidia for ALF symbol tables, [from here](https://gist.github.com/RootCubed/9ebecf21eec344f10164cdfabbf0bb41).

### mangle

Provides a function to mangle a symbol, with CodeWarrior's mangling scheme.

It's taken from [here](https://gist.github.com/CLF78/3b1cf5d863918e07352d9c63548cb5b6). Arrays and non-function symbols are not yet supported.

The `is_remangle_mode` parameter indicates whether the input is a demangled symbol (i.e. doesn't include argument names and a return type) or a declaration as would be written in C++ source code (i.e. does include those).

### nsmbw

A few utility functions specific to NSMBW, to try to at least keep the hardcoding mostly centralized. (Also see the next library below.)

### nsmbw_constants

A wide variety of constants specific to NSMBW, to try to at least keep the hardcoding mostly centralized. (Also see the previous library, above.)

### port_symbol_map

Provides a function `remap_symbols_to_all_versions()` that uses an address map and optional tweak map to port a symbol map to all game versions.

### symbol_map_formats

An abstract `SymbolMap` class and a variety of subclasses representing various types of symbol map files.

### tweaks

Parser for "tweak map" files, which describe how the symbols in a symbol map change across versions (for example, a function which gained or lost a parameter in some game version).
