#!/usr/bin/env python3

# Changes in this fork by aboood40091:
# - Added support for arrays and functions as parameters.
# - Added support for static local variables.
# - Properly show the return type of function if applicable.
# - Added different modes. (File reading, passing symbol as argument, console)
# - Added overriding known function names.
# - Fixed several bugs.


def demangleNamespaces(node):
    if node[0] == 'Q':
        compCount = int(node[1])
        node = node[2:]
        while node.startswith('_'):
            node = node[1:]
    else:
        compCount = 1
    namespaces = []
    for _ in range(compCount):
        counter = 0
        while counter < len(node) and node[counter].isdigit():
            counter += 1
        length = int(node[:counter])
        if compCount == 1 and (counter >= len(node) or node[counter] == '>' or node[counter] == ','):
            return None, '%d' % length, node[counter:]
        namespaces.append(demangleTemplates(node[counter:counter+length]))
        node = node[counter+length:]
    return namespaces, '', node

def demangleNode(node):
    signedness = []
    qualifiers = []
    while node:
        if node[0] == 'P':
            qualifiers.append('P')
        elif node[0] == 'R':
            qualifiers.append('R')
        elif node[0] == 'C':
            qualifiers.append('C')
        elif node[0] == 'U':
            signedness.append('unsigned')
        elif node[0] == 'S':
            signedness.append('signed')
        else:
            break
        node = node[1:]
    qualifiers = ''.join(reversed(qualifiers))

    if node[0] == 'F':
        returnType, post, args, node = demangleFuncNode(node[1:], qualifiers)
        return '%s%s(%s)' % (returnType, post, args), node

    pre = ''
    while qualifiers.startswith('C'):
        pre += 'const '
        qualifiers = qualifiers[1:]

    post = ''
    for c in qualifiers:
        if c == 'P':
            post += '*'
        elif c == 'R':
            post += '&'
        else:  # c == 'C'
            post += 'const'

    if signedness:
        pre += ' '.join(signedness) + ' '

    if node[0] == 'i':
        return pre + 'int' + post, node[1:]
    elif node[0] == 'b':
        return pre + 'bool' + post, node[1:]
    elif node[0] == 'c':
        return pre + 'char' + post, node[1:]
    elif node[0] == 's':
        return pre + 'short' + post, node[1:]
    elif node[0] == 'l':
        return pre + 'long' + post, node[1:]
    elif node[0] == 'x':
        return pre + 'long long ' + post, node[1:]
    elif node[0] == 'f':
        return pre + 'float' + post, node[1:]
    elif node[0] == 'd':
        return pre + 'double' + post, node[1:]
    elif node[0] == 'w':
        return pre + 'wchar_t' + post, node[1:]
    elif node[0] == 'v':
        return pre + 'void' + post, node[1:]
    elif node[0] == 'e':
        return '...', node[1:]

    elif node[0] == 'A':
        array = ''
        while node[0] == 'A':
            counter = 1
            while counter < len( node) and node[counter].isdigit():
                counter += 1
            array += '[%s]' % node[1:counter]
            node = node[counter:]
            if node.startswith('_'):
                node = node[1:]
        arrayType, node = demangleNode(node)
        if not arrayType.endswith(' '):
            arrayType += ' '
        if post:
            post = '(%s)' % post
        return '%s%s%s%s' % (arrayType, pre, post, array), node

    elif node[0] not in 'Q0123456789':
        return node, ''

    namespaces, num, node = demangleNamespaces(node)
    if namespaces is None:
        return num, node
    return pre + '::'.join(namespaces) + post, node

def demangleFuncNode(node, qualifiers=''):
    returnType = ''
    args = ''
    while node and node[0] != '_':
        if len(args):
            args += ', '
        arg, node = demangleNode(node)
        args += arg
    node = node[1:]
    if node:
        returnType, node = demangleNode(node)
        if returnType:
            returnType += ' '
    post = ''
    if qualifiers:
        post = ''
        while qualifiers.startswith('C'):
            post += ' const'
            qualifiers = qualifiers[1:]
        post = ''
        for c in qualifiers:
            if c == 'P':
                post += '*'
            elif c == 'R':
                post += '&'
            else:  # c == 'C'
                post += 'const '
        if post:
            post = '(%s)' % post
    return returnType, post, args, node

def findSepIdx(name, idx):
    count = 0
    retval = 0
    for ch in name:
        if ch == '<' or ch == ',':
            if idx == count:
                return retval
            count += 1
        retval += 1
    return -1

def demangleTemplates(name):
    token = 0
    accum = name
    while True:
        tidx = findSepIdx(accum, token)
        token += 1
        if tidx < 0:
            return accum
        sidx = tidx + 1
        toDem = accum[sidx:]
        accum = accum[:sidx]
        dem, rem = demangleNode(toDem)
        accum += dem + rem

def demangle(sym):
    sym = sym.strip()
    if ' ' in sym:
        return sym
    variable = ''
    guard = ''
    if sym.startswith('@LOCAL@') or sym.startswith('@GUARD@'):
        if sym.startswith('@GUARD@'):
            guard = ' guard variable'
        sym = sym[7:]
        variableStart = sym.rfind('@')
        if variableStart != -1 and sym[variableStart+1:].isdecimal():
            sym = sym[:variableStart]
            variableStart = sym.rfind('@')
        if variableStart != -1:
            variable = '::' + sym[variableStart+1:]
            sym = sym[:variableStart]
    typeSplit = 0
    while sym.startswith('_', typeSplit):
        typeSplit += 1
    if typeSplit == len(sym):
        return sym
    while True:
        typeSplit = sym.find('__', typeSplit)
        if typeSplit == -1:
            return sym
        while sym.startswith('___', typeSplit):
            typeSplit += 1
        typeSplit += 2
        if typeSplit == len(sym):
            return sym
        if sym[typeSplit] in 'FQ0123456789':
            break
    if typeSplit == 2:
        return sym
    funcName = demangleTemplates(sym[:typeSplit-2])
    rem = sym[typeSplit:]
    pre = ''
    post = ''
    funcTypes = []
    if rem[0] in 'Q0123456789':
        funcTypes, _, rem = demangleNamespaces(rem)
        objType = rem[0] if rem else ""
        if objType == 'S':
            pre = 'static '
            objType = rem[1]
            rem = rem[1:]
        elif objType == 'C':
            post = ' const'
            objType = rem[1]
            rem = rem[1:]
    rem = rem[1:]
    funcReturnType, _, funcArgs, rem  = demangleFuncNode(rem)
    if funcName.startswith('__'):
        if   funcName == "__nw":  funcName = "operator new"
        elif funcName == "__nwa": funcName = "operator new[]"
        elif funcName == "__dl":  funcName = "operator delete"
        elif funcName == "__dla": funcName = "operator delete[]"
        elif funcName == "__pl":  funcName = "operator+"
        elif funcName == "__mi":  funcName = "operator-"
        elif funcName == "__ml":  funcName = "operator*"
        elif funcName == "__dv":  funcName = "operator/"
        elif funcName == "__md":  funcName = "operator%"
        elif funcName == "__er":  funcName = "operator^"
        elif funcName == "__ad":  funcName = "operator&"
        elif funcName == "__or":  funcName = "operator|"
        elif funcName == "__co":  funcName = "operator~"
        elif funcName == "__nt":  funcName = "operator!"
        elif funcName == "__as":  funcName = "operator="
        elif funcName == "__lt":  funcName = "operator<"
        elif funcName == "__gt":  funcName = "operator>"
        elif funcName == "__apl": funcName = "operator+="
        elif funcName == "__ami": funcName = "operator-="
        elif funcName == "__amu": funcName = "operator*="
        elif funcName == "__adv": funcName = "operator/="
        elif funcName == "__amd": funcName = "operator%="
        elif funcName == "__aer": funcName = "operator^="
        elif funcName == "__aad": funcName = "operator&="
        elif funcName == "__aor": funcName = "operator|="
        elif funcName == "__ls":  funcName = "operator<<"
        elif funcName == "__rs":  funcName = "operator>>"
        elif funcName == "__ars": funcName = "operator>>="
        elif funcName == "__als": funcName = "operator<<="
        elif funcName == "__eq":  funcName = "operator=="
        elif funcName == "__ne":  funcName = "operator!="
        elif funcName == "__le":  funcName = "operator<="
        elif funcName == "__ge":  funcName = "operator>="
        elif funcName == "__aa":  funcName = "operator&&"
        elif funcName == "__oo":  funcName = "operator||"
        elif funcName == "__pp":  funcName = "operator++"
        elif funcName == "__mm":  funcName = "operator--"
        elif funcName == "__cm":  funcName = "operator,"
        elif funcName == "__rm":  funcName = "operator->*"
        elif funcName == "__rf":  funcName = "operator->"
        elif funcName == "__cl":  funcName = "operator()"
        elif funcName == "__vc":  funcName = "operator[]"
        elif funcName.startswith("__op"):
            mangledReturnType = funcName[4:]
            returnType, returnTypeRem = demangleNode(mangledReturnType)
            if returnType != mangledReturnType and not returnTypeRem:
                funcName = "operator %s" % returnType
    funcType = '::'.join(funcTypes)
    if funcType:
        if funcName == '__vt':
            funcName = " virtual table"
        else:
            funcType = "%s::" % funcType
            if funcName in ("__ct", "__dt"):
                funcName = ('~' + funcTypes[-1]) if funcName == "__dt" else funcTypes[-1]
                templateStart = funcName.find('<')
                if templateStart != -1:
                    funcName = funcName[:templateStart]
    if funcArgs:
        if funcArgs == 'void':
            funcArgs = '()'
        else:
            funcArgs = '(%s)' % funcArgs
    return '%s%s%s%s%s%s%s%s%s' % (pre, funcReturnType, funcType, funcName, funcArgs, post, variable, guard, rem)
