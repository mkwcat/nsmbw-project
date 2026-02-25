# Replication of the CW ABI demangler used by NVIDIA for the NVIDIA Shield ports
# written by RootCubed, ported from the C++ version:
# https://gist.github.com/RootCubed/d7e2629f4576059853505b7931ffd105

import ctypes
from io import StringIO, TextIOBase
import re
import sys

# Demangler bug: Doesn't support types like x (long long)
BASIC_TYPES = {
    'v': 'void',
    'b': 'bool',
    'c': 'char',
    's': 'short',
    'i': 'int',
    'l': 'long',
    'f': 'float',
    'd': 'double',
    'w': 'wchar_t'
}

def parse_class_or_basic_type(mangled: str, out: TextIOBase, pos: ctypes.c_int) -> None:
    if mangled[pos.value] == 'Q':
        pos.value += 1
        parse_Q_class(mangled, out, pos)

    elif mangled[pos.value].isdigit():
        parse_simple_class(mangled, out, pos)

    else:
        if mangled[pos.value] == 'U':
            pos.value += 1
            out.write('unsigned ' + BASIC_TYPES[mangled[pos.value]])
        else:
            out.write(BASIC_TYPES[mangled[pos.value]])
        pos.value += 1

def parse_Q_class(mangled: str, out: TextIOBase, pos: ctypes.c_int) -> None:
    count = int(mangled[pos.value])
    pos.value += 1
    for i in range(count):
        parse_simple_class(mangled, out, pos)
        if i < count - 1:
            out.write('::')

def parse_simple_class(mangled: str, out: TextIOBase, pos: ctypes.c_int) -> None:
    size = 0
    while mangled[pos.value].isdigit():
        size = size * 10 + int(mangled[pos.value])
        pos.value += 1

    end = pos.value + size
    while pos.value < end:
        c = mangled[pos.value]
        out.write(c)
        pos.value += 1
        if c == '<':
            # Demangler bug: The demangler assumes one template parameter only
            # Demangler bug: No checks for literal values as template arguments
            parse_arg_type(mangled, out, pos)

def parse_arg_type(mangled: str, out: TextIOBase, pos: ctypes.c_int) -> None:
    # Demangler bug: type modifiers are handled incorrectly
    is_const = False
    is_ptr = False
    is_ref = False
    while pos.value < len(mangled):
        c = mangled[pos.value]

        # Demangler bug: M (PTMFS) and A (arrays) are not handled
        if c == 'C':
            is_const = True
        elif c == 'P':
            is_ptr = True
        elif c == 'R':
            is_ref = True
        elif c == 'F':
            # Demangler bug: Demangler was built without function pointers in mind, so they are incorrectly handled
            out.write('( ')
            pos.value += 1
            try:
                parse_function(mangled, out, pos)
            except Exception as e:
                out.write(' )')
                raise e
            out.write(' )')
            break
        else:
            break
        pos.value += 1
    
    if is_const:
        out.write('const ')
    type_name = StringIO()
    try:
        parse_class_or_basic_type(mangled, type_name, pos)
    except Exception as e:
        if type_name.tell() != 0:
            type_name.seek(0)
            out.write(type_name.read())
            if is_ptr:
                out.write('*')
            if is_ref:
                out.write('&')
        raise e
    # Demangler bug: The order of R and P does not matter
    type_name.seek(0)
    out.write(type_name.read())
    if is_ptr:
        out.write('*')
    if is_ref:
        out.write('&')

def parse_function(mangled: str, out: TextIOBase, pos: ctypes.c_int) -> None:
    while pos.value < len(mangled):
        parse_arg_type(mangled, out, pos)
        if pos.value < len(mangled):
            out.write(', ')

def demangle(mangled: str) -> str:
    func_name = StringIO()
    i = ctypes.c_int(0)
    while i.value < len(mangled):
        func_name.write(mangled[i.value])
        i.value += 1
        if re.match('^__([CFQ0-9].+)', mangled[i.value:]) is not None:
            break
    if i.value == len(mangled):
        func_name.seek(0)
        return func_name.read()

    # Skip past __
    i.value += 2

    res = StringIO()

    try:
        # Check if class method or global function
        if mangled[i.value] != 'F' and mangled[i.value] != 'C':
            parse_class_or_basic_type(mangled, res, i)
            res.write('::')
        func_name.seek(0)
        res.write(func_name.read())
    except:
        pass

    if i.value == len(mangled):
        res.seek(0)
        return res.read()

    # Probably not how NVIDIA did it, but I can't get it to work by supporting const functions in parse_arg_type
    is_const = False
    if mangled[i.value] == 'C':
        is_const = True
        i.value += 1

    try:
        parse_arg_type(mangled, res, i)
    except:
        pass
    if is_const:
        res.write(' const')

    res.seek(0)
    return res.read()

def main() -> None:
    if len(sys.argv) < 2:
        try:
            while True:
                print(demangle(input()))
        except EOFError:
            pass
    else:
        print(demangle(sys.argv[1]))

if __name__ == '__main__':
    main()