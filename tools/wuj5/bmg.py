import sys

from common import *


font_variants = [
    Variant('mario', 0x0),
    Variant('picture', 0x1),
    Variant('message', 0x2),
    Variant('number', 0x3),
    Variant('red', 0x4),
    Variant('blue', 0x5),
]

tag_variants = [
    # Adjust font size
    Variant('font size', 0x08ff0001),

    # The current world number
    Variant('world num', 0x08010000),
    # The current course number, simply displayed as a number
    Variant('course num', 0x06010001),
    # Prints the 2 or 1 button icon
    Variant('ok cancel disp', 0x08010002),
    # Total collected star coin count
    Variant('total collection coin', 0x06010003),
    # Displays a d-pad icon
    Variant('cross key disp', 0x06010004),
    # Displays the specified stage icon
    Variant('course select icon', 0x08010005),
    # Displays the current save file slot
    Variant('save file number', 0x06010006),
    # Displays a button for the world map HUD
    Variant('course select button', 0x08010007),
    # Displays a button for the menu
    Variant('menu button', 0x08010008),
    # Handles text scissor for layout panes
    Variant('scissor', 0x08010009),
    # Prints the 1 or 2 button for the pairing menu
    Variant('easy pairing' , 0x0801000a),
    # Displays an unknown variable
    Variant('unknown 0xb', 0x0601000b),
    # Does nothing
    Variant('unused tag', 0x0601000c),
    # Used to label unused BMG entries; it prints the entry ID
    Variant('debug disp', 0x0601000d),
    # Used for custom arguments passed to the tag processor. Displays the course number when no arguments are passed
    Variant('custom arg', 0x0801000e),
    Variant('custom arg 2', 0x0601000f),
    Variant('custom arg 3', 0x06010010),
    # The current player count. Does not function in singleplayer.
    Variant('play number', 0x06010011),
    # Displays ? block icon
    Variant('ok cancel disp question block', 0x06010012),
    # Displays a red block or dotted block
    Variant('red block', 0x08010013),
]

world_num_variants = [
    Variant('zero', 0x0),
    Variant('sub 1', 0x1),
    Variant('add 1', 0x2),
]

ok_cancel_disp_variants = [
    Variant('ok button', 0x0000),
    Variant('cancel button', 0x0100),
]

course_select_icon_variants = [
    Variant('castle', 0x0000),
    Variant('fortress', 0x0100),
    Variant('ghost house', 0x0200),
    Variant('cannon', 0x0300),
    Variant('airship', 0x0400),
    Variant('red toad house', 0x0500),
    Variant('start point right', 0x0600),
    Variant('start point up', 0x0700),
    Variant('stop point', 0x0800),
    Variant('peach castle', 0x0900),
    Variant('green toad house', 0x0a00),
    Variant('star toad house', 0x0b00),
    Variant('final castle', 0x0c00),
    Variant('toad rescue', 0x0d00),
    Variant('anchor', 0x0e00),
]

course_select_button_variants = [
    Variant('view map', 0x0000),
    Variant('select world', 0x0100),
    Variant('menu', 0x0200),
    Variant('items', 0x0300),
]

menu_button_variants = [
    Variant('home', 0x0000),
    Variant('plus', 0x0100),
    Variant('minus', 0x0200),
    Variant('a', 0x0300),
    Variant('b', 0x0400),
    Variant('z', 0x0500),
]

scissor_variants = [
    Variant('begin', 0x0000),
    Variant('end', 0x0100),
]

easy_pairing_variants = [
    Variant('1 button', 0x0000),
    Variant('2 button', 0x0100),
]

red_block_variants = [
    Variant('dotted', 0x0000),
    Variant('activated', 0x0100),
]

def unpack_inf1(in_data, offset):
    entry_count = unpack_u16(in_data, offset + 0x08)
    entries = []
    for i in range(entry_count):
        entries += [{
            'string offset': unpack_u32(in_data, offset + 0x10 + i * 0x8),
            'font': unpack_enum8(
                in_data,
                offset + 0x10 + i * 0x8 + 0x6,
                size = size,
                unpack = unpack,
                variants = font_variants,
            ),
            'x scale': unpack_u8(in_data, offset + 0x10 + i * 0x8 + 0x5),
        }]
    return entries

def unpack_dat1(in_data, offset):
    size = unpack_u32(in_data, offset + 0x4)
    return in_data[offset + 0x8:offset + 0x8 + size]

def unpack_mid1(in_data, offset):
    entry_count = unpack_u16(in_data, offset + 0x08)
    entries = []
    for i in range(entry_count):
        entries += [unpack_u32(in_data, offset + 0x10 + i * 0x4)]
    return entries

def unpack_bmg(in_data):
    offset = 0x20
    sections = {}
    while offset < len(in_data):
        magic = unpack_magic(in_data, offset + 0x00)
        size = unpack_u32(in_data, offset + 0x04)
        if magic in sections:
            sys.exit(f'Duplicate bmg section {magic}.')
        section = {
            'INF1': unpack_inf1,
            'DAT1': unpack_dat1,
            'MID1': unpack_mid1,
        }[magic](in_data, offset)
        sections[magic] = section
        offset += size

    messages = {}
    for index, message_id in enumerate(sections['MID1']):
        inf1 = sections['INF1']
        font = inf1[index]['font']
        x_scale = inf1[index]['x scale']
        string_start = inf1[index]['string offset']
        dat1 = sections['DAT1']
        offset = string_start
        if offset == 0x0:
            string = None
        else:
            string = ''
            while unpack_u16(dat1, offset) != 0x0:
                if unpack_u16(dat1, offset) == 0x1a:
                    tag = unpack_enum32(
                        dat1,
                        offset + 0x2,
                        size = size,
                        unpack = unpack,
                        variants = tag_variants,
                    )
                    if tag == 'world num':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = world_num_variants)
                    elif tag == 'ok cancel disp':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = ok_cancel_disp_variants)
                    elif tag == 'course select icon':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = course_select_icon_variants)
                    elif tag == 'course select button':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = course_select_button_variants)
                    elif tag == 'menu button':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = menu_button_variants)
                    elif tag == 'scissor':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = scissor_variants)
                    elif tag == 'easy pairing':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = easy_pairing_variants)
                    elif tag == 'red block':
                        val = unpack_enum16(dat1, offset + 0x6, size = size, unpack = unpack, variants = red_block_variants)
                    elif unpack_u8(dat1, offset + 0x2) == 0x8:
                        data = unpack_u16(dat1, offset + 0x6)
                        val = f'0x{data:04x}'
                    else:
                        val = None

                    if val is not None:
                        string += f'{{{tag}|{val}}}'
                    else:
                        string += f'{{{tag}}}'
                    offset += unpack_u8(dat1, offset + 0x2)
                else:
                    string += dat1[offset:offset + 0x2].decode('utf-16-be')
                    offset += 0x2
        messages[message_id] = {
            'font': font,
            'x scale': x_scale,
            'string': string,
        }
    return messages

def pack_inf1(entries):
    entries_data = b''
    for entry in entries:
        entries_data += b''.join([
            pack_u32(entry['string offset']),
            pack_pad8(None),
            pack_u8(entry['x scale']),
            pack_enum8(
                entry['font'],
                pack = pack,
                variants = font_variants,
            ),
            pack_pad8(None),
        ])

    return b''.join([
        pack_magic('INF1'),
        pack_pad32(None),
        pack_u16(len(entries)),
        pack_u16(0x8),
        pack_pad32(None),
        entries_data,
    ])

def pack_dat1(strings_data):
    return b''.join([
        pack_magic('DAT1'),
        pack_pad32(None),
        strings_data,
    ])

def pack_mid1(entries):
    entries_data = b''
    for entry in entries:
        entries_data += pack_u32(entry)

    return b''.join([
        pack_magic('MID1'),
        pack_pad32(None),
        pack_u16(len(entries)),
        pack_u16(0x1001),
        pack_pad32(None),
        entries_data,
    ])

def pack_bmg(messages):
    inf1 = []
    mid1 = []
    strings = Buffer(0x0)
    strings.buffer = b'\0\0'
    for message_id in messages:
        in_string = messages[message_id]['string']
        if in_string is None:
            string_offset = 0x0
        else:
            out_string = b''
            parts = in_string.split('{', maxsplit = 1)
            while len(parts) > 1:
                out_string += parts[0].encode('utf-16-be')
                pattern, in_string = parts[1].split('}', maxsplit = 1)
                out_string += pack_u16(0x1a)
                if '|' in pattern:
                    tag, val = pattern.split('|')
                    out_string += pack_enum32(
                        tag,
                        pack = pack,
                        variants = tag_variants,
                    )
                    if tag == 'world num':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = world_num_variants,
                        )
                    elif tag == 'ok cancel disp':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = ok_cancel_disp_variants,
                        )
                    elif tag == 'course select icon':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = course_select_icon_variants,
                        )
                    elif tag == 'course select button':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = course_select_button_variants,
                        )
                    elif tag == 'menu button':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = menu_button_variants,
                        )
                    elif tag == 'scissor':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = scissor_variants,
                        )
                    elif tag == 'easy pairing':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = easy_pairing_variants,
                        )
                    elif tag == 'red block':
                        out_string += pack_enum16(
                            val,
                            pack = pack,
                            variants = red_block_variants,
                        )
                    else:
                        out_string += pack_u16(int(val, 0))
                else:
                    out_string += pack_enum32(
                        pattern,
                        pack = pack,
                        variants = tag_variants,
                    )
                parts = in_string.split('{', maxsplit = 1)
            out_string += in_string.encode('utf-16-be')
            out_string += b'\0\0'
            string_offset = strings.push(out_string)
        inf1 += [{
            'string offset': string_offset,
            'font': messages[message_id]['font'],
            'x scale': messages[message_id]['x scale'],
        }]
        mid1 += [int(message_id, 0)]

    sections = {
        'INF1': inf1,
        'DAT1': strings.buffer,
        'MID1': mid1,
    }

    sections_data = b''
    for magic in sections:
        section_data = {
            'INF1': pack_inf1,
            'DAT1': pack_dat1,
            'MID1': pack_mid1,
        }[magic](sections[magic])
        section_data = section_data.ljust((len(section_data) + 0x1f) & ~0x1f, b'\0')
        section_data = section_data[0x0:0x4] + pack_u32(len(section_data)) + section_data[0x8:]
        sections_data += section_data

    return b''.join([
        pack_magic('MESG'),
        pack_magic('bmg1'),
        pack_u32(0x20 + len(sections_data)),
        pack_u32(0x3),
        pack_u8(0x2),
        pack_pad24(None),
        pack_pad32(None),
        pack_pad32(None),
        pack_pad32(None),
        sections_data,
    ])
