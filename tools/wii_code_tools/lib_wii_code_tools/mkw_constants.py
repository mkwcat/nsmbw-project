import enum


VERSION_NAMES = ['P', 'E', 'J', 'K']
VERSION_NAMES_NO_ESHOP = VERSION_NAMES

REL_NAMES = [
    'StaticR',
]

CODE_FILE_NAMES = {
    'P': 'main.dol',
    'E': 'main.dol',
    'J': 'main.dol',
    'K': 'main.dol',
}

SECTION_ADDRESSES = {
    'P': {
        'main': {
            '.init': {0x80004000, 0x2460},
            'extab': {0x80006460, 0x5c0},
            'extabindex': {0x80006a20, 0x8a0},
            '.text': {0x800072c0, 0x23db20},
            '.ctors': {0x80244de0, 0xc0},
            '.dtors': {0x80244ea0, 0x20},
            '.rodata': {0x80244ec0, 0x136c0},
            '.data': {0x80258580, 0x4bac0},
            '.bss': {0x802a4080, 0xe0b80},
            '.sdata': {0x80384c00, 0x13c0},
            '.sbss': {0x80385fc0, 0xfe0},
            '.sdata2': {0x80386fa0, 0x21a0},
            '.sbss2': {0x80389140, 0x3c},
        },
        'StaticR': {
            '.text': (0x805103b4, 0x37f04c),
            '.ctors': (0x8088f400, 0x304),
            '.dtors': (0x8088f704, 0xc),
            '.data': (0x8088f720, 0x234b0),
            '.rodata': (0x808b2bd0, 0x2a804),
            '.bss': (0x809bd6e0, 0x78b0),
        },
    },
    'E': {
        'main': {
            '.init': {0x80004000, 0x2460},
            'extab': {0x80006460, 0x5c0},
            'extabindex': {0x80006a20, 0x8a0},
            '.text': {0x800072c0, 0x23da80},
            '.ctors': {0x80244d40, 0xc0},
            '.dtors': {0x80244e00, 0x20},
            '.rodata': {0x80244e40, 0x13420},
            '.data': {0x80258260, 0x47aa0},
            '.bss': {0x8029fd00, 0xe0b80},
            '.sdata': {0x80380880, 0x13c0},
            '.sbss': {0x80381c40, 0xfe0},
            '.sdata2': {0x80382c20, 0x21a0},
            '.sbss2': {0x80384dc0, 0x3c},
        },
        'StaticR': {
            '.text': (0x8050c034, 0x37ef9c),
            '.ctors': (0x8088afd0, 0x304),
            '.dtors': (0x8088b2d4, 0xc),
            '.data': (0x8088b2e0, 0x23240),
            '.rodata': (0x808ae520, 0x2a75c),
            '.bss': (0x809b8f20, 0x78b0),
        },
    },
    'J': {
        'main': {
            '.init': {0x80004000, 0x2460},
            'extab': {0x80006460, 0x5c0},
            'extabindex': {0x80006a20, 0x8a0},
            '.text': {0x800072c0, 0x23da40},
            '.ctors': {0x80244d00, 0xc0},
            '.dtors': {0x80244dc0, 0x20},
            '.rodata': {0x80244e00, 0x13120},
            '.data': {0x80257f20, 0x4bac0},
            '.bss': {0x802a3a00, 0xe0b80},
            '.sdata': {0x80384580, 0x13c0},
            '.sbss': {0x80385940, 0xfe0},
            '.sdata2': {0x80386920, 0x21a0},
            '.sbss2': {0x80388ac0, 0x3c},
        },
        'StaticR': {
            '.text': (0x8050fd34, 0x37ed38),
            '.ctors': (0x8088ea6c, 0x304),
            '.dtors': (0x8088ed70, 0xc),
            '.data': (0x8088ed80, 0x22fb0),
            '.rodata': (0x808b1d30, 0x2a7f4),
            '.bss': (0x809bc740, 0x78b0),
        },
    },
    'K': {
        'main': {
            '.init': {0x80004000, 0x2460},
            'extab': {0x80006460, 0x5c0},
            'extabindex': {0x80006a20, 0x8a0},
            '.text': {0x800072c0, 0x23dea0},
            '.ctors': {0x80245160, 0xc0},
            '.dtors': {0x80245220, 0x20},
            '.rodata': {0x80245240, 0x13100},
            '.data': {0x80258340, 0x39d00},
            '.bss': {0x80292080, 0xe0b80},
            '.sdata': {0x80372c00, 0x13e0},
            '.sbss': {0x80373fe0, 0xfe0},
            '.sdata2': {0x80374fc0, 0x21a0},
            '.sbss2': {0x80377160, 0x3c},
        },
        'StaticR': {
            '.text': (0x804fe3d4, 0x37f3ec),
            '.ctors': (0x8087d7c0, 0x304),
            '.dtors': (0x8087dac4, 0xc),
            '.data': (0x8087dae0, 0x23550),
            '.rodata': (0x808a1030, 0x2a83c),
            '.bss': (0x809abd20, 0x78b0),
        },
    },
}

R2_R13_VALUES = {
    'P': (0x8038efa0, 0x8038cc00),
    'E': (0x8038ac20, 0x80388880),
    'J': (0x8038e920, 0x8038c580),
    'K': (0x8037cfc0, 0x8037ac00),
}

class Permissions(enum.Flag):
    R = enum.auto()
    W = enum.auto()
    X = enum.auto()

    @classmethod
    def none(cls) -> 'Permissions':
        return cls.R & cls.W

# In order of increasing start address
DOL_SECTION_NAMES = [
    '.init',
    'extab',
    'extabindex',
    '.text',
    '.ctors',
    '.dtors',
    '.rodata',
    '.data',
    '.bss',
    '.sdata',
    '.sbss',
    '.sdata2',
    '.sbss2',
]
DOL_SECTION_INFO = {
    '.init':      {'class': 'CODE', 'permissions': Permissions.R | Permissions.X},
    'extab':      {'class': 'DATA', 'permissions': Permissions.R | Permissions.W},
    'extabindex': {'class': 'DATA', 'permissions': Permissions.R | Permissions.W},
    '.text':      {'class': 'CODE', 'permissions': Permissions.R | Permissions.X},
    '.ctors':     {'class': 'DATA', 'permissions': Permissions.R},
    '.dtors':     {'class': 'DATA', 'permissions': Permissions.R},
    '.rodata':    {'class': 'DATA', 'permissions': Permissions.R},
    '.data':      {'class': 'DATA', 'permissions': Permissions.R | Permissions.W},
    '.bss':       {'class': 'BSS',  'permissions': Permissions.R | Permissions.W},
    '.sdata':     {'class': 'DATA', 'permissions': Permissions.R | Permissions.W},
    '.sbss':      {'class': 'BSS',  'permissions': Permissions.R | Permissions.W},
    '.sdata2':    {'class': 'DATA', 'permissions': Permissions.R | Permissions.W},
    '.sbss2':     {'class': 'BSS',  'permissions': Permissions.R | Permissions.W},
}

REL_SECTION_NAMES = [
    '.text',
    '.ctors',
    '.dtors',
    '.data',
    '.rodata',
    '.bss',
]
REL_SECTION_INFO = {
    '.text':   {'class': 'CODE', 'permissions': Permissions.R | Permissions.X},
    '.ctors':  {'class': 'DATA', 'permissions': Permissions.R},
    '.dtors':  {'class': 'DATA', 'permissions': Permissions.R},
    '.data':   {'class': 'DATA', 'permissions': Permissions.R | Permissions.W},
    '.rodata': {'class': 'DATA', 'permissions': Permissions.R},
    '.bss':    {'class': 'BSS',  'permissions': Permissions.R | Permissions.W},
}
