#!/usr/bin/env python3

# mangle.py
# CodeWarrior mangler, by CLF78 and RoadrunnerWMC


TYPE_ENDINGS = {
    '*',
    '&',
    ')',
    '>',
}

PREPEND_KEYWORDS = [
    'extern "C"',
    'static',
    'virtual',
    'inline',
    'explicit',
    'friend',
]

DECORS = {
    '*': 'P',
    '&': 'R',
    'const': 'C',
    'volatile': 'V',
}

BUILTIN_TYPES = {
    'void': 'v',
    'wchar_t': 'w',
    'bool': 'b',
    'char': 'c',
    'signed char': 'Sc',
    'unsigned char': 'Uc',
    'short': 's',
    'signed short': 's',
    'unsigned short': 'Us',
    'int': 'i',
    'signed int': 'i',
    'unsigned int': 'Ui',
    'long': 'l',
    'signed long': 'l',
    'unsigned long': 'Ul',
    'long long': 'x',
    'signed long long': 'x',
    'unsigned long long': 'Ux',
    'float': 'f',
    'double': 'd',
    '...': 'e',
}

OPERATORS = {
    'new': '__nw',
    'delete': '__dl',
    'new[]': '__nwa',
    'delete[]': '__dla',
    '=': '__as',
    '+': '__pl',
    '-': '__mi',
    '*': '__ml',
    '/': '__dv',
    '%': '__md',
    "^": "__er",
    "&": "__ad",
    "|": "__or",
    "~": "__co",
    "!": "__nt",
    "<": "__lt",
    ">": "__gt",
    '+=': '__apl',
    '-=': '__ami',
    "*=": "__amu",
    "/=": "__adv",
    "%=": "__amd",
    "^=": "__aer",
    "&=": "__aad",
    "|=": "__aor",
    "<<": "__ls",
    ">>": "__rs",
    "<<=": "__als",
    ">>=": "__ars",
    '==': '__eq',
    '!=': '__ne',
    "<=": "__le",
    ">=": "__ge",
    "&&": "__aa",
    "||": "__oo",
    "++": "__pp",
    "--": "__mm",
    ",": "__cm",
    "->*": "__rm",
    "->": "__rf",
    '()': '__cl',
    '[]': '__vc',
}


def renumerate(data: list):
    for i in range(len(data)-1, -1, -1):
        yield (i, data[i])


class _Mangler:
    def __init__(self, is_remangle_mode: bool):
        self.is_templated_function = False
        self.is_remangle_mode = is_remangle_mode


    def apply_changes(self, func: str, typedefs: dict[str, str], substitutions: dict[str, str]) -> str:

        # Apply substitutions first
        if substitutions is not None:
            for key, val in substitutions.items():
                func = func.replace(key, val)

        # Then apply typedefs
        if typedefs is not None:
            for key, val in typedefs.items():
                func = func.replace(key, val)

        # Return modified function
        return func


    def isolate_args(self, func: str) -> tuple[int, int]:

        # Set up loop
        start_brace_idx = -1
        end_brace_idx = -1
        curr_nest_level = 0

        # Iterate through the string in reverse to find the first ending ")" character
        # and the corresponding "(" character
        for i, c in renumerate(func):
            if c == ')':
                if curr_nest_level == 0:
                    end_brace_idx = i
                curr_nest_level += 1
            elif c == '(':
                curr_nest_level -= 1
                if curr_nest_level == 0:
                    start_brace_idx = i
                    break

        # Sanity checks
        if curr_nest_level:
            raise ValueError('Mismatched braces!')

        # Return indexes
        return (start_brace_idx, end_brace_idx)


    def split_args(self, args: str) -> list[str]:

        # Account for empty arg list
        if not args:
            return ['void']

        # Set up loop
        pieces = []
        curr_nest_level = 0
        prev_component_idx = 0

        # Iterate through the string and split by non-nested commas
        for i, c in enumerate(args):

            # Detect templates and function pointers
            if c == '<' or c == '(':
                curr_nest_level += 1
            elif c == '>' or c == ')':
                curr_nest_level -= 1

            # Detect arg splits
            elif c == ',' and curr_nest_level == 0:

                # Prevent series of comma characters
                if i == prev_component_idx:
                    raise ValueError('Empty argument!')

                # Check passed, move along
                pieces.append(args[prev_component_idx:i].strip())
                prev_component_idx = i + 1

        # Add the final piece
        pieces.append(args[prev_component_idx:].strip())

        # Detect mismatched braces
        if curr_nest_level:
            raise ValueError('Mismatched braces!')

        # Return the pieces
        return pieces


    def isolate_template(self, type: str) -> tuple[int, int]:

        # Set up loop
        start_brace_idx = -1
        end_brace_idx = -1
        curr_nest_level = 0

        # Iterate through the string to find the first non-nested "<" character
        # and the corresponding ">" character
        for i, c in enumerate(type):
            if c == '<' or c == '(':
                if curr_nest_level == 0 and c == '<':
                    start_brace_idx = i
                curr_nest_level += 1
            elif c == '>' or c == ')':
                curr_nest_level -= 1
                if curr_nest_level == 0 and c == '>':
                    end_brace_idx = i
                    break

        # If the template was nested, ignore it
        if start_brace_idx == -1 and end_brace_idx == -1:
            return (start_brace_idx, end_brace_idx)

        # Sanity checks
        if curr_nest_level:
            raise ValueError('Mismatched braces!')

        # Return indexes
        return (start_brace_idx, end_brace_idx)


    def mangle_func_ptr(self, type: str) -> tuple[int, int]:

        # Set up loop
        start_func_idx = -1
        end_func_idx = -1
        start_args_idx = -1
        end_args_idx = -1
        curr_nest_level = 0

        # Iterate through the string in reverse to find the first two non-nested ")" characters
        # and the corresponding "(" characters
        for i, c in renumerate(type):
            if c == ')':
                if curr_nest_level == 0:
                    if end_args_idx != -1:
                        end_func_idx = i
                    else:
                        end_args_idx = i
                curr_nest_level += 1
            elif c == '>':
                curr_nest_level += 1
            elif c == '(':
                curr_nest_level -= 1
                if curr_nest_level == 0:
                    if start_args_idx != -1:
                        start_func_idx = i
                        break
                    else:
                        start_args_idx = i
            elif c == '<':
                curr_nest_level -= 1

        # If the function was nested, ignore it
        if start_func_idx == start_args_idx == end_func_idx == end_args_idx == -1:
            return ''

        # Sanity checks
        if end_func_idx == -1 or curr_nest_level:
            raise ValueError('Mismatched braces!')

        # Set up result
        mangled_func = ''

        # Isolate the pieces
        func_return = type[:start_func_idx].strip()
        func_name = type[start_func_idx+1:end_func_idx].strip()
        func_args = type[start_args_idx+1:end_args_idx].strip()

        # Ensure the return type and function name are properly declared
        if not func_return or not func_name:
            raise ValueError('Invalid function pointer!')

        # Count the pointers from the function name
        ptr_count = 0
        for i, c in renumerate(func_name):

            # Count the pointers
            if c == '*':
                ptr_count += 1

            # Exit if the first of the two "::" characters are found
            elif c == ':':
                func_name = func_name[:i-1]
                break

        # Remove asterisks
        func_name = func_name.rstrip('*')

        # If it's not a pointer to member function, we can simply add PF
        if not func_name:
            mangled_func += f'{DECORS["*"] * ptr_count}F'

        # Else mangle the class
        else:
            mangled_func += f'M{self.mangle_type(func_name)}F'

        # Split and mangle the args
        func_args = self.split_args(func_args)
        for arg in func_args:
            mangled_func += self.mangle_type(arg)

        # Mangle the return type
        mangled_func += f'_{self.mangle_type(func_return)}'

        # We got it!
        return mangled_func


    def mangle_type(self, type: str, no_length: bool = False) -> str:

        # Initialize type
        mangled_type = ''

        # If the type is a simple integer, return it as is
        if type.isdigit():
            return type

        # Detect pointers and references and remove them from the type
        ref_count = 0
        ptr_count = 0
        for i, c in renumerate(type):
            if c == '*':
                ptr_count += 1
            elif c == '&':
                ref_count += 1
            elif c.isspace():
                continue
            else:
                type = type[:i+1]
                break

        # Add the mangled decorators (one per count)
        mangled_type += DECORS['&'] * ref_count
        mangled_type += DECORS['*'] * ptr_count

        # Detect initial const and remove it if found
        if type.startswith('const '):
            mangled_type += DECORS['const']
            type = type.lstrip('const').lstrip()

        # Do the same for volatile, but ensure it only adds the mangled decorator for pointer/ref types
        if type.startswith('volatile '):
            type = type.lstrip('volatile').lstrip()
            if ref_count or ptr_count:
                mangled_type += DECORS['volatile']

        # Detect built in types
        if type in BUILTIN_TYPES:
            return mangled_type + BUILTIN_TYPES[type]

        # Try to split the type into decorated types and mangle each one of them
        # Now with extra hardcode for function pointer returns
        split_types = self.split_decorated_type(type)
        if len(split_types) > 1 and '(' not in type and ')' not in type:
            mangled_type += self.mangle_decorated_type(split_types)
            return mangled_type

        # If the type contains a template, isolate it
        if '<' in type or '>' in type:
            template_start, template_end = self.isolate_template(type)

            # If the template was not nested, split the contents and mangle each piece
            if not (template_start == -1 and template_end == -1):
                template = type[template_start+1:template_end].strip()
                type = type[:template_start+1].strip()
                template_args = self.split_args(template)
                type += ','.join(map(self.mangle_type, template_args))
                type += '>'

                # If the length is to be omitted this is the function name, so mark function as templated
                if no_length:
                    self.is_templated_function = True

        # Else if the type contains a function pointer, isolate it and mangle each component properly
        elif '(' in type or ')' in type:
            mangled_func = self.mangle_func_ptr(type)

            # Don't do anything if the function was nested
            if mangled_func:
                type = mangled_func
                no_length = True

        # Prepend the length if wanted
        if not no_length:
            mangled_type += str(len(type))

        # Append the type itself (might be mangled or not mangled)
        return mangled_type + type


    def mangle_arg(self, arg: str) -> str:

        # Set up loop
        type_end = len(arg)

        # Remove arg names before mangling, if found
        for i, c in renumerate(arg):
            if c in TYPE_ENDINGS or c.isspace():
                type_end = i
                break

        # Ensure we don't cut off built in types
        arg_name = arg[type_end:].strip()
        arg_type = arg
        if arg_name not in BUILTIN_TYPES:
            arg_type = arg[:type_end+1].strip()

        # Mangle the type
        return self.mangle_type(arg_type)


    def isolate_func_name(self, func: str) -> int:

        # Set up loop
        func_start = -1
        curr_nest_level = 0

        # Iterate through the string in reverse to find the first non-nested split character
        # Only detect templates since function names cannot contain function pointers
        for i, c in renumerate(func):
            if c == '>':
                curr_nest_level += 1
            elif c == '<':
                curr_nest_level -= 1
            elif (c in TYPE_ENDINGS or c.isspace()) and curr_nest_level == 0:
                func_start = i
                break

        # Detect mismatched braces
        if curr_nest_level:
            raise ValueError('Mismatched braces!')

        # Detect missing return type
        if func_start == -1 and not self.is_remangle_mode:
            raise ValueError('Missing return type!')

        # Return index
        return func_start + 1


    def split_decorated_type(self, type: str) -> list[str]:

        # Set up loop
        pieces = []
        curr_nest_level = 0
        prev_component_idx = 0

        # Iterate through the string and split by non-nested :: characters
        for i, c in enumerate(type):

            # Detect templates and function pointers
            if c == '<' or c == '(':
                curr_nest_level += 1
            elif c == '>' or c == ')':
                curr_nest_level -= 1

            # Detect name splits
            elif type[i:i+2] == '::' and curr_nest_level == 0:

                # Prevent series of more than two :: characters
                if i <= prev_component_idx:
                    raise ValueError('Invalid type provided!')

                # Check passed, move along
                pieces.append(type[prev_component_idx:i])
                prev_component_idx = i + 2

        # Add the final piece
        pieces.append(type[prev_component_idx:])

        # Failsafe
        if not pieces or not pieces[-1]:
            raise ValueError('Invalid type provided!')

        # Detect mismatched braces
        if curr_nest_level:
            raise ValueError('Mismatched braces!')

        # Return the pieces
        return pieces


    def mangle_decorated_type(self, types: list[str]):

        # Set up string
        mangled_types = ''

        # Add Q if there are multiple pieces
        if len(types) > 1:
            mangled_types += f'Q{len(types)}'

        # Mangle each piece
        for type in types:
            mangled_types += self.mangle_type(type)

        # Return result
        return mangled_types


    def mangle_operator(self, operator: str) -> str:

        # Check for default operators
        if operator in OPERATORS:
            return OPERATORS[operator]

        # If it's not a cast operator, blame the user
        if not operator.endswith('()'):
            raise ValueError('Invalid operator!')

        # Isolate the type and mangle it
        operator_type = operator[:-2]
        return f'__op{self.mangle_type(operator_type)}'


    def mangle_function_name(self, pieces: list[str], is_const: bool) -> str:

        # Initialize string
        mangled_name = ''

        # Isolate the last piece
        last_piece = pieces.pop()

        # Check for special names
        if pieces:

            # If the last piece is the same as the previous it's a constructor, use the dedicated keyword
            if last_piece == pieces[-1]:
                mangled_name += '__ct'

            # If the last piece starts with a "~" it's a destructor, use the dedicated keyword
            elif last_piece.startswith('~'):
                mangled_name += '__dt'

            # If the piece starts with "operator", get the operator
            elif last_piece.startswith('operator'):
                last_piece = last_piece.split('operator', 1)[-1].strip()
                mangled_name += self.mangle_operator(last_piece)

            # No special cases, add the name as is
            else:
                mangled_name += self.mangle_type(last_piece, True)

        # It's a regular function, add the name as is
        else:
            mangled_name += self.mangle_type(last_piece, True)

        # Add the separator
        mangled_name += '__'

        # Mangle the rest of the function
        if pieces:
            mangled_name += self.mangle_decorated_type(pieces)

        # Add the const function identifier
        if is_const:
            mangled_name += DECORS['const']

        # Terminate the function name
        mangled_name += 'F'
        return mangled_name


    def mangle_function(self, func: str, typedefs: dict[str, str] = None, substitutions: dict[str, str] = None) -> str:

        # Apply typedefs and substitutions and strip excess whitespace
        func = self.apply_changes(func, typedefs, substitutions)
        func = ' '.join(func.split())

        # Bail on any array argument
        if '[' in func or ']' in func:
            raise NotImplementedError('Array types are not supported!')

        # Ensure the function ends with a valid keyword
        if not (func.endswith(')') or func.endswith('const') or func.endswith('override')) and not self.is_remangle_mode:
            raise ValueError('Invalid function ending!')

        # Isolate the arguments from the function
        # Do so by finding the first ending ")" and the corresponding "(" characters
        arg_start, arg_end = self.isolate_args(func)

        # If the arguments were not found, return function as is
        if arg_start == arg_end == -1:
            return func

        # Split the arguments off
        func_end = func[arg_end+1:].strip()
        func_args = func[arg_start+1:arg_end].strip()

        # Check for const at the end of the function
        is_const_func = 'const' in func_end

        # Isolate the function name from the return type
        func_ret_plus_name = func[:arg_start].strip()
        name_start = self.isolate_func_name(func_ret_plus_name)
        func_name = func_ret_plus_name[name_start:]
        func_ret = func_ret_plus_name[:name_start].strip()

        # Check if the return type contains extern "C"
        # If it's a C function, return the name without mangling it
        if 'extern "C" ' in func_ret and '::' not in func_name:
            return func_name

        # Remove all keywords from the return type
        for keyword in PREPEND_KEYWORDS:
            func_ret = func_ret.replace(f'{keyword} ', '').strip()

        # Prepare the final string
        mangled_name = ''

        # Split the function name and mangle it
        func_name_split = self.split_decorated_type(func_name)
        mangled_name += self.mangle_function_name(func_name_split, is_const_func)

        # Split the arguments and mangle them
        split_args = self.split_args(func_args)
        for arg in split_args:
            mangled_name += self.mangle_arg(arg)

        # If the function is templated, add the mangled return type too
        if self.is_templated_function:
            mangled_name += f'_{self.mangle_type(func_ret)}'

        # Return result
        return mangled_name


def mangle(func: str, *, is_remangle_mode: bool = False, typedefs: dict[str, str] = None, substitutions: dict[str, str] = None) -> str:
    return _Mangler(is_remangle_mode).mangle_function(func, typedefs, substitutions)


def main():
    TESTS = [
        ('void *EGG::TSystem<EGG::Video, EGG::AsyncDisplay, EGG::XfbManager, EGG::SimpleAudioMgr, EGG::SceneManager, EGG::ProcessMeter>::Configuration::getVideo(sStateIf_c*& state, int (fBase_c::*func1)(const void*, void*), int (fBase_c::*func2)(const void*, void*), void (fBase_c::*)(const void*, void*, fBase_c::MAIN_STATE)) const',
         'getVideo__Q33EGG126TSystem<Q23EGG5Video,Q23EGG12AsyncDisplay,Q23EGG10XfbManager,Q23EGG14SimpleAudioMgr,Q23EGG12SceneManager,Q23EGG12ProcessMeter>13ConfigurationCFRP10sStateIf_cM7fBase_cFPCvPv_iM7fBase_cFPCvPv_iM7fBase_cFPCvPvQ27fBase_c10MAIN_STATE_v'),
        ('void std::__sort132<bool (*)( const nw4r::g3d::detail::workmem::MdlZ&, const nw4r::g3d::detail::workmem::MdlZ& )&, nw4r::g3d::detail::workmem::MdlZ*>( nw4r::g3d::detail::workmem::MdlZ*, nw4r::g3d::detail::workmem::MdlZ*, nw4r::g3d::detail::workmem::MdlZ*, bool (*)( const nw4r::g3d::detail::workmem::MdlZ&, const nw4r::g3d::detail::workmem::MdlZ& )& )',
         '__sort132<RPFRCQ54nw4r3g3d6detail7workmem4MdlZRCQ54nw4r3g3d6detail7workmem4MdlZ_b,PQ54nw4r3g3d6detail7workmem4MdlZ>__3stdFPQ54nw4r3g3d6detail7workmem4MdlZPQ54nw4r3g3d6detail7workmem4MdlZPQ54nw4r3g3d6detail7workmem4MdlZRPFRCQ54nw4r3g3d6detail7workmem4MdlZRCQ54nw4r3g3d6detail7workmem4MdlZ_b_v'),
        ('virtual void nw4r::snd::detail::AxfxImpl::HookAlloc( void* (**)( unsigned long ), void (**)( void* ) )',
         'HookAlloc__Q44nw4r3snd6detail8AxfxImplFPPFUl_PvPPFPv_v'),
        ('void nw4r::snd::detail::Test(volatile unsigned int* x) override', 'Test__Q34nw4r3snd6detailFPVUi'),
        ('extern "C" void DWCi_ProcessPacket(int value)', 'DWCi_ProcessPacket'),
        ('__check_pad3', '__check_pad3'),
        ('NMSndObject<4>::SoundHandlePrm::SoundHandlePrm()', '__ct__Q214NMSndObject<4>14SoundHandlePrmFv'),
        ('nw4r::g3d::ScnLeaf::ForEach( nw4r::g3d::ScnObj::ForEachResult (*)( nw4r::g3d::ScnObj*, void* ), void*, bool )', 'ForEach__Q34nw4r3g3d7ScnLeafFPFPQ34nw4r3g3d6ScnObjPv_Q44nw4r3g3d6ScnObj13ForEachResultPvb'),
        ('EGG::DrawPathDOF::@24@SetBinaryInner( const EGG::IBinary<EGG::DrawPathDOF>::Bin& )', '@24@SetBinaryInner__Q23EGG11DrawPathDOFFRCQ33EGG28IBinary<Q23EGG11DrawPathDOF>3Bin')
    ]

    print('Running tests...')
    for src, mangled in TESTS:
        print('Mangling', src, end=' -> ')
        result = mangle_function(src, True)
        print(result)
        if mangled != result:
            raise AssertionError('Test failed!')
    print('All tests passed!')


if __name__ == '__main__':
    main()
