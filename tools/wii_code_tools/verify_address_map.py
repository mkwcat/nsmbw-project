#!/usr/bin/env python3

import argparse
import functools
from pathlib import Path
from typing import Callable, Iterator, List, Optional, Tuple

from lib_wii_code_tools import code_files
from lib_wii_code_tools.code_files import all as code_files_all
from lib_wii_code_tools.code_files import rel as code_files_rel
from lib_wii_code_tools import common
from lib_wii_code_tools import address_maps as lib_address_maps
from lib_wii_code_tools import nsmbw as lib_nsmbw

# Zero fields and reserved fields should both be included in the masks:
# "If a reserved field does not have all bits cleared, or if a field
# that must contain a particular value does not contain that value, the
# instruction form is invalid and the results are as described in
# Chapter 4, “Addressing Modes and Instruction set Summary."
PPC_OPCODES = [
    (0xfc0007ff, (31 << 26)         | (266 << 1),     'add'),
    (0xfc0007ff, (31 << 26)         | (266 << 1) | 1, 'add.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (266 << 1),     'addo'),
    (0xfc0007ff, (31 << 26) | 0x400 | (266 << 1) | 1, 'addo.'),
    (0xfc0007ff, (31 << 26)         |  (10 << 1),     'addc'),
    (0xfc0007ff, (31 << 26)         |  (10 << 1) | 1, 'addc.'),
    (0xfc0007ff, (31 << 26) | 0x400 |  (10 << 1),     'addco'),
    (0xfc0007ff, (31 << 26) | 0x400 |  (10 << 1) | 1, 'addco.'),
    (0xfc0007ff, (31 << 26)         | (138 << 1),     'adde'),
    (0xfc0007ff, (31 << 26)         | (138 << 1) | 1, 'adde.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (138 << 1),     'addeo'),
    (0xfc0007ff, (31 << 26) | 0x400 | (138 << 1) | 1, 'addeo.'),
    (0xfc000000, (14 << 26),                          'addi'),
    (0xfc000000, (12 << 26),                          'addic'),
    (0xfc000000, (13 << 26),                          'addic.'),
    (0xfc000000, (15 << 26),                          'addis'),
    (0xfc00ffff, (31 << 26)         | (234 << 1),     'addme'),
    (0xfc00ffff, (31 << 26)         | (234 << 1) | 1, 'addme.'),
    (0xfc00ffff, (31 << 26) | 0x400 | (234 << 1),     'addmeo'),
    (0xfc00ffff, (31 << 26) | 0x400 | (234 << 1) | 1, 'addmeo.'),
    (0xfc00ffff, (31 << 26)         | (202 << 1),     'addze'),
    (0xfc00ffff, (31 << 26)         | (202 << 1) | 1, 'addze.'),
    (0xfc00ffff, (31 << 26) | 0x400 | (202 << 1),     'addzeo'),
    (0xfc00ffff, (31 << 26) | 0x400 | (202 << 1) | 1, 'addzeo.'),
    (0xfc0007ff, (31 << 26)         |  (28 << 1),     'and'),
    (0xfc0007ff, (31 << 26)         |  (28 << 1) | 1, 'and.'),
    (0xfc0007ff, (31 << 26)         |  (60 << 1),     'andc'),
    (0xfc0007ff, (31 << 26)         |  (60 << 1) | 1, 'andc.'),
    (0xfc000000, (28 << 26),                          'andi.'),
    (0xfc000000, (29 << 26),                          'andis.'),
    (0xfc000003, (18 << 26),                          'b'),
    (0xfc000003, (18 << 26) | 2,                      'ba'),
    (0xfc000003, (18 << 26) | 1,                      'bl'),
    (0xfc000003, (18 << 26) | 3,                      'bla'),
    (0xfc000003, (16 << 26),                          'bc'),
    (0xfc000003, (16 << 26) | 2,                      'bca'),
    (0xfc000003, (16 << 26) | 1,                      'bcl'),
    (0xfc000003, (16 << 26) | 3,                      'bcla'),
    (0xfc00ffff, (19 << 26) | (528 << 1),             'bcctr'),
    (0xfc00ffff, (19 << 26) | (528 << 1) | 1,         'bcctrl'),
    (0xfc00ffff, (19 << 26) |  (16 << 1),             'bclr'),
    (0xfc00ffff, (19 << 26) |  (16 << 1) | 1,         'bclrl'),
    (0xfc4007ff, (31 << 26),                          'cmp'),
    (0xfc400000, (11 << 26),                          'cmpi'),
    (0xfc4007ff, (31 << 26) |  (32 << 1),             'cmpl'),
    (0xfc400000, (10 << 26),                          'cmpli'),
    (0xfc00ffff, (31 << 26) |  (26 << 1),             'cntlzw'),
    (0xfc00ffff, (31 << 26) |  (26 << 1) | 1,         'cntlzw.'),
    (0xfc0007ff, (19 << 26) | (257 << 1),             'crand'),
    (0xfc0007ff, (19 << 26) | (129 << 1),             'crandc'),
    (0xfc0007ff, (19 << 26) | (289 << 1),             'creqv'),
    (0xfc0007ff, (19 << 26) | (225 << 1),             'crnand'),
    (0xfc0007ff, (19 << 26) |  (33 << 1),             'crnor'),
    (0xfc0007ff, (19 << 26) | (449 << 1),             'cror'),
    (0xfc0007ff, (19 << 26) | (417 << 1),             'crorc'),
    (0xfc0007ff, (19 << 26) | (193 << 1),             'crxor'),
    (0xffe007ff, (31 << 26) |  (758 << 1),            'dcba'),
    (0xffe007ff, (31 << 26) |   (86 << 1),            'dcbf'),
    (0xffe007ff, (31 << 26) |  (470 << 1),            'dcbi'),
    (0xffe007ff, (31 << 26) |   (54 << 1),            'dcbst'),
    (0xffe007ff, (31 << 26) |  (278 << 1),            'dcbt'),
    (0xffe007ff, (31 << 26) |  (246 << 1),            'dcbtst'),
    (0xffe007ff, (31 << 26) | (1014 << 1),            'dcbz'),
    (0xfc0007ff, (31 << 26)         | (491 << 1),     'divw'),
    (0xfc0007ff, (31 << 26)         | (491 << 1) | 1, 'divw.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (491 << 1),     'divwo'),
    (0xfc0007ff, (31 << 26) | 0x400 | (491 << 1) | 1, 'divwo.'),
    (0xfc0007ff, (31 << 26)         | (459 << 1),     'divwu'),
    (0xfc0007ff, (31 << 26)         | (459 << 1) | 1, 'divwu.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (459 << 1),     'divwuo'),
    (0xfc0007ff, (31 << 26) | 0x400 | (459 << 1) | 1, 'divwuo.'),
    (0xfc0007ff, (31 << 26) | (310 << 1),             'eciwx'),
    (0xfc0007ff, (31 << 26) | (438 << 1),             'ecowx'),
    (0xffffffff, (31 << 26) | (854 << 1),             'eieio'),
    (0xfc0003ff, (31 << 26) | (284 << 1),             'eqv'),
    (0xfc0003ff, (31 << 26) | (284 << 1) | 1,         'eqv.'),
    (0xfc00ffff, (31 << 26) | (954 << 1),             'extsb'),
    (0xfc00ffff, (31 << 26) | (954 << 1) | 1,         'extsb.'),
    (0xfc00ffff, (31 << 26) | (922 << 1),             'extsh'),
    (0xfc00ffff, (31 << 26) | (922 << 1) | 1,         'extsh.'),
    (0xfc1f07ff, (63 << 26) | (264 << 1),             'fabs'),
    (0xfc1f07ff, (63 << 26) | (264 << 1) | 1,         'fabs.'),
    (0xfc0007ff, (63 << 26) |  (21 << 1),             'fadd'),
    (0xfc0007ff, (63 << 26) |  (21 << 1) | 1,         'fadd.'),
    (0xfc0007ff, (59 << 26) |  (21 << 1),             'fadds'),
    (0xfc0007ff, (59 << 26) |  (21 << 1) | 1,         'fadds.'),
    (0xfc6007ff, (63 << 26) |  (32 << 1),             'fcmpo'),
    (0xfc6007ff, (63 << 26),                          'fcmpu'),
    (0xfc1f07ff, (63 << 26) |  (14 << 1),             'fctiw'),
    (0xfc1f07ff, (63 << 26) |  (14 << 1) | 1,         'fctiw.'),
    (0xfc1f07ff, (63 << 26) |  (15 << 1),             'fctiwz'),
    (0xfc1f07ff, (63 << 26) |  (15 << 1) | 1,         'fctiwz.'),
    (0xfc0007ff, (63 << 26) |  (18 << 1),             'fdiv'),
    (0xfc0007ff, (63 << 26) |  (18 << 1) | 1,         'fdiv.'),
    (0xfc0007ff, (59 << 26) |  (18 << 1),             'fdivs'),
    (0xfc0007ff, (59 << 26) |  (18 << 1) | 1,         'fdivs.'),
    (0xfc00003f, (63 << 26) |  (29 << 1),             'fmadd.'),
    (0xfc00003f, (63 << 26) |  (29 << 1) | 1,         'fmadd.'),
    (0xfc00003f, (59 << 26) |  (29 << 1),             'fmadds.'),
    (0xfc00003f, (59 << 26) |  (29 << 1) | 1,         'fmadds.'),
    (0xfc1f07ff, (63 << 26) |  (72 << 1),             'fmr'),
    (0xfc1f07ff, (63 << 26) |  (72 << 1) | 1,         'fmr.'),
    (0xfc00003f, (63 << 26) |  (28 << 1),             'fmsub.'),
    (0xfc00003f, (63 << 26) |  (28 << 1) | 1,         'fmsub.'),
    (0xfc00003f, (59 << 26) |  (28 << 1),             'fmsubs.'),
    (0xfc00003f, (59 << 26) |  (28 << 1) | 1,         'fmsubs.'),
    (0xfc00f83f, (63 << 26) |  (25 << 1),             'fmul'),
    (0xfc00f83f, (63 << 26) |  (25 << 1) | 1,         'fmul.'),
    (0xfc00f83f, (59 << 26) |  (25 << 1),             'fmuls'),
    (0xfc00f83f, (59 << 26) |  (25 << 1) | 1,         'fmuls.'),
    (0xfc1f07ff, (63 << 26) | (136 << 1),             'fnabs'),
    (0xfc1f07ff, (63 << 26) | (136 << 1) | 1,         'fnabs.'),
    (0xfc1f07ff, (63 << 26) |  (40 << 1),             'fneg'),
    (0xfc1f07ff, (63 << 26) |  (40 << 1) | 1,         'fneg.'),
    (0xfc00003f, (63 << 26) |  (31 << 1),             'fnmadd.'),
    (0xfc00003f, (63 << 26) |  (31 << 1) | 1,         'fnmadd.'),
    (0xfc00003f, (59 << 26) |  (31 << 1),             'fnmadds.'),
    (0xfc00003f, (59 << 26) |  (31 << 1) | 1,         'fnmadds.'),
    (0xfc00003f, (63 << 26) |  (30 << 1),             'fnmsub.'),
    (0xfc00003f, (63 << 26) |  (30 << 1) | 1,         'fnmsub.'),
    (0xfc00003f, (59 << 26) |  (30 << 1),             'fnmsubs.'),
    (0xfc00003f, (59 << 26) |  (30 << 1) | 1,         'fnmsubs.'),
    (0xfc1f07ff, (59 << 26) |  (24 << 1),             'fres'),
    (0xfc1f07ff, (59 << 26) |  (24 << 1) | 1,         'fres.'),
    (0xfc1f07ff, (63 << 26) |  (12 << 1),             'frsp'),
    (0xfc1f07ff, (63 << 26) |  (12 << 1) | 1,         'frsp.'),
    (0xfc1f07ff, (63 << 26) |  (26 << 1),             'frsqrte'),
    (0xfc1f07ff, (63 << 26) |  (26 << 1) | 1,         'frsqrte.'),
    (0xfc00003f, (63 << 26) |  (23 << 1),             'fsel.'),
    (0xfc00003f, (63 << 26) |  (23 << 1) | 1,         'fsel.'),
    (0xfc1f07ff, (63 << 26) |  (22 << 1),             'frsqrt'),
    (0xfc1f07ff, (63 << 26) |  (22 << 1) | 1,         'frsqrt.'),
    (0xfc1f07ff, (59 << 26) |  (22 << 1),             'frsqrts'),
    (0xfc1f07ff, (59 << 26) |  (22 << 1) | 1,         'frsqrts.'),
    (0xfc0007ff, (63 << 26) |  (20 << 1),             'fsub'),
    (0xfc0007ff, (63 << 26) |  (20 << 1) | 1,         'fsub.'),
    (0xfc0007ff, (59 << 26) |  (20 << 1),             'fsubs'),
    (0xfc0007ff, (59 << 26) |  (20 << 1) | 1,         'fsubs.'),
    (0xffe007ff, (31 << 26) | (982 << 1),             'icbi'),
    (0xffffffff, (19 << 26) | (150 << 1),             'isync'),
    (0xfc000000, (34 << 26),                          'lbz'),
    (0xfc000000, (35 << 26),                          'lbzu'),
    (0xfc0007ff, (31 << 26) | (119 << 1),             'lbzux'),
    (0xfc0007ff, (31 << 26) |  (87 << 1),             'lbzx'),
    (0xfc000000, (50 << 26),                          'lfd'),
    (0xfc000000, (51 << 26),                          'lfdu'),
    (0xfc0007ff, (31 << 26) | (631 << 1),             'lfdux'),
    (0xfc0007ff, (31 << 26) | (599 << 1),             'lfdx'),
    (0xfc000000, (48 << 26),                          'lfs'),
    (0xfc000000, (49 << 26),                          'lfsu'),
    (0xfc0007ff, (31 << 26) | (567 << 1),             'lfsux'),
    (0xfc0007ff, (31 << 26) | (535 << 1),             'lfsx'),
    (0xfc000000, (42 << 26),                          'lha'),
    (0xfc000000, (43 << 26),                          'lhau'),
    (0xfc0007ff, (31 << 26) | (375 << 1),             'lhaux'),
    (0xfc0007ff, (31 << 26) | (343 << 1),             'lhax'),
    (0xfc0007ff, (31 << 26) | (790 << 1),             'lhbrx'),
    (0xfc000000, (40 << 26),                          'lhz'),
    (0xfc000000, (41 << 26),                          'lhzu'),
    (0xfc0007ff, (31 << 26) | (311 << 1),             'lhzux'),
    (0xfc0007ff, (31 << 26) | (279 << 1),             'lhzx'),
    (0xfc000000, (46 << 26),                          'lmw'),
    (0xfc0007ff, (31 << 26) | (597 << 1),             'lswi'),
    (0xfc0007ff, (31 << 26) | (533 << 1),             'lswx'),
    (0xfc0007ff, (31 << 26) |  (20 << 1),             'lwarx'),
    (0xfc0007ff, (31 << 26) | (534 << 1),             'lwbrx'),
    (0xfc000000, (32 << 26),                          'lwz'),
    (0xfc000000, (33 << 26),                          'lwzu'),
    (0xfc0007ff, (31 << 26) |  (55 << 1),             'lwzux'),
    (0xfc0007ff, (31 << 26) |  (23 << 1),             'lwzx'),
    (0xfc63ffff, (19 << 26),                          'mcrf'),
    (0xfc63ffff, (63 << 26) |  (64 << 1),             'mcrfs'),
    (0xfc7fffff, (31 << 26) | (512 << 1),             'mcrxr'),
    (0xfc1fffff, (31 << 26) |  (19 << 1),             'mfcr'),
    (0xfc1fffff, (63 << 26) | (583 << 1),             'mffs'),
    (0xfc1fffff, (63 << 26) | (583 << 1) | 1,         'mffs.'),
    (0xfc1fffff, (31 << 26) |  (83 << 1),             'mfmsr'),
    (0xfc0007ff, (31 << 26) | (339 << 1),             'mfspr'),
    (0xfc10ffff, (31 << 26) | (595 << 1),             'mfsr'),
    (0xfc1f07ff, (31 << 26) | (659 << 1),             'mfsrin'),
    (0xfc0007ff, (31 << 26) | (371 << 1),             'mftb'),
    (0xfc100fff, (31 << 26) | (144 << 1),             'mtcrf'),
    (0xfc1fffff, (63 << 26) |  (70 << 1),             'mtfsb0'),
    (0xfc1fffff, (63 << 26) |  (70 << 1) | 1,         'mtfsb0.'),
    (0xfc1fffff, (63 << 26) |  (38 << 1),             'mtfsb1'),
    (0xfc1fffff, (63 << 26) |  (38 << 1) | 1,         'mtfsb1.'),
    (0xfe0107ff, (63 << 26) | (711 << 1),             'mtfsf'),
    (0xfe0107ff, (63 << 26) | (711 << 1) | 1,         'mtfsf.'),
    (0xfc7f0fff, (63 << 26) | (134 << 1),             'mtfsfi'),
    (0xfc7f0fff, (63 << 26) | (134 << 1) | 1,         'mtfsfi.'),
    (0xfc1f07ff, (31 << 26) | (146 << 1),             'mtmsr'),
    (0xfc0007ff, (31 << 26) | (467 << 1),             'mtspr'),
    (0xfc10ffff, (31 << 26) | (210 << 1),             'mtsr'),
    (0xfc1f07ff, (31 << 26) | (242 << 1),             'mtsrin'),
    (0xfc0007ff, (31 << 26)         |  (75 << 1),     'mulhw'),
    (0xfc0007ff, (31 << 26)         |  (75 << 1) | 1, 'mulhw.'),
    (0xfc0007ff, (31 << 26)         |  (11 << 1),     'mulhwu'),
    (0xfc0007ff, (31 << 26)         |  (11 << 1) | 1, 'mulhwu.'),
    (0xfc000000,  (7 << 26),                          'mulli'),
    (0xfc0007ff, (31 << 26)         | (235 << 1),     'mullw'),
    (0xfc0007ff, (31 << 26)         | (235 << 1) | 1, 'mullw.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (235 << 1),     'mullwo'),
    (0xfc0007ff, (31 << 26) | 0x400 | (235 << 1) | 1, 'mullwo.'),
    (0xfc0007ff, (31 << 26)         | (476 << 1),     'nand'),
    (0xfc0007ff, (31 << 26)         | (476 << 1) | 1, 'nand.'),
    (0xfc0007ff, (31 << 26)         | (104 << 1),     'neg'),
    (0xfc0007ff, (31 << 26)         | (104 << 1) | 1, 'neg.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (104 << 1),     'nego'),
    (0xfc0007ff, (31 << 26) | 0x400 | (104 << 1) | 1, 'nego.'),
    (0xfc0007ff, (31 << 26)         | (124 << 1),     'nor'),
    (0xfc0007ff, (31 << 26)         | (124 << 1) | 1, 'nor.'),
    (0xfc0007ff, (31 << 26)         | (444 << 1),     'or'),
    (0xfc0007ff, (31 << 26)         | (444 << 1) | 1, 'or.'),
    (0xfc0007ff, (31 << 26)         | (412 << 1),     'orc'),
    (0xfc0007ff, (31 << 26)         | (412 << 1) | 1, 'orc.'),
    (0xfc000000, (24 << 26),                          'ori'),
    (0xfc000000, (25 << 26),                          'oris'),
    (0xffffffff, (19 << 26) |  (50 << 1),             'rfi'),
    (0xfc000001, (20 << 26),                          'rlwimi'),
    (0xfc000001, (20 << 26) | 1,                      'rlwimi.'),
    (0xfc000001, (21 << 26),                          'rlwinm'),
    (0xfc000001, (21 << 26) | 1,                      'rlwinm.'),
    (0xfc000001, (23 << 26),                          'rlwnm'),
    (0xfc000001, (23 << 26) | 1,                      'rlwnm.'),
    (0xffffffff, (17 << 26) | (1 << 1),               'sc'),
    (0xfc0007ff, (31 << 26)         |  (24 << 1),     'slw'),
    (0xfc0007ff, (31 << 26)         |  (24 << 1) | 1, 'slw.'),
    (0xfc0007ff, (31 << 26)         | (792 << 1),     'sraw'),
    (0xfc0007ff, (31 << 26)         | (792 << 1) | 1, 'sraw.'),
    (0xfc0007ff, (31 << 26)         | (824 << 1),     'srawi'),
    (0xfc0007ff, (31 << 26)         | (824 << 1) | 1, 'srawi.'),
    (0xfc0007ff, (31 << 26)         | (536 << 1),     'srw'),
    (0xfc0007ff, (31 << 26)         | (536 << 1) | 1, 'srw.'),
    (0xfc000000, (38 << 26),                          'stb'),
    (0xfc000000, (39 << 26),                          'stbu'),
    (0xfc0003ff, (31 << 26) | (247 << 1),             'stbux'),
    (0xfc0003ff, (31 << 26) | (215 << 1),             'stbx'),
    (0xfc000000, (54 << 26),                          'stfd'),
    (0xfc000000, (55 << 26),                          'stfdu'),
    (0xfc0007ff, (31 << 26) | (759 << 1),             'stfdux'),
    (0xfc0007ff, (31 << 26) | (727 << 1),             'stfdx'),
    (0xfc0007ff, (31 << 26) | (983 << 1),             'stfiwx'),
    (0xfc000000, (52 << 26),                          'stfs'),
    (0xfc000000, (53 << 26),                          'stfsu'),
    (0xfc0007ff, (31 << 26) | (695 << 1),             'stfsux'),
    (0xfc0007ff, (31 << 26) | (663 << 1),             'stfsx'),
    (0xfc000000, (44 << 26),                          'sth'),
    (0xfc0007ff, (31 << 26) | (918 << 1),             'sthbrx'),
    (0xfc000000, (45 << 26),                          'sthu'),
    (0xfc0007ff, (31 << 26) | (439 << 1),             'sthux'),
    (0xfc0007ff, (31 << 26) | (407 << 1),             'sthx'),
    (0xfc000000, (47 << 26),                          'stmw'),
    (0xfc0007ff, (31 << 26) | (725 << 1),             'stswi'),
    (0xfc0007ff, (31 << 26) | (661 << 1),             'stswx'),
    (0xfc000000, (36 << 26),                          'stw'),
    (0xfc0007ff, (31 << 26) | (662 << 1),             'stwbrx'),
    (0xfc0007ff, (31 << 26) | (150 << 1) | 1,         'stwcx.'),
    (0xfc000000, (37 << 26),                          'stwu'),
    (0xfc0007ff, (31 << 26) | (183 << 1),             'stwux'),
    (0xfc0007ff, (31 << 26) | (151 << 1),             'stwx'),
    (0xfc0007ff, (31 << 26)         |  (40 << 1),     'subf'),
    (0xfc0007ff, (31 << 26)         |  (40 << 1) | 1, 'subf.'),
    (0xfc0007ff, (31 << 26) | 0x400 |  (40 << 1),     'subfo'),
    (0xfc0007ff, (31 << 26) | 0x400 |  (40 << 1) | 1, 'subfo.'),
    (0xfc0007ff, (31 << 26)         |   (8 << 1),     'subfc'),
    (0xfc0007ff, (31 << 26)         |   (8 << 1) | 1, 'subfc.'),
    (0xfc0007ff, (31 << 26) | 0x400 |   (8 << 1),     'subfco'),
    (0xfc0007ff, (31 << 26) | 0x400 |   (8 << 1) | 1, 'subfco.'),
    (0xfc0007ff, (31 << 26)         | (136 << 1),     'subfe'),
    (0xfc0007ff, (31 << 26)         | (136 << 1) | 1, 'subfe.'),
    (0xfc0007ff, (31 << 26) | 0x400 | (136 << 1),     'subfeo'),
    (0xfc0007ff, (31 << 26) | 0x400 | (136 << 1) | 1, 'subfeo.'),
    (0xfc000000,  (8 << 26),                          'subfic'),
    (0xfc00ffff, (31 << 26)         | (232 << 1),     'subfme'),
    (0xfc00ffff, (31 << 26)         | (232 << 1) | 1, 'subfme.'),
    (0xfc00ffff, (31 << 26) | 0x400 | (232 << 1),     'subfmeo'),
    (0xfc00ffff, (31 << 26) | 0x400 | (232 << 1) | 1, 'subfmeo.'),
    (0xfc00ffff, (31 << 26)         | (200 << 1),     'subfze'),
    (0xfc00ffff, (31 << 26)         | (200 << 1) | 1, 'subfze.'),
    (0xfc00ffff, (31 << 26) | 0x400 | (200 << 1),     'subfzeo'),
    (0xfc00ffff, (31 << 26) | 0x400 | (200 << 1) | 1, 'subfzeo.'),
    (0xffffffff, (31 << 26) | (598 << 1),             'sync'),
    (0xffffffff, (31 << 26) | (370 << 1),             'tlbia'),
    (0xffff07ff, (31 << 26) | (306 << 1),             'tlbie'),
    (0xffffffff, (31 << 26) | (566 << 1),             'tlbsync'),
    (0xfc0007ff, (31 << 26) |   (4 << 1),             'tw'),
    (0xfc000000,  (3 << 26),                          'twi'),
    (0xfc0007ff, (31 << 26)         | (316 << 1),     'xor'),
    (0xfc0007ff, (31 << 26)         | (316 << 1) | 1, 'xor.'),
    (0xfc000000, (26 << 26),                          'xori'),
    (0xfc000000, (27 << 26),                          'xoris'),
]


def create_instruction_name_lookup_func() -> Callable[[int], str]:
    """
    Return a function that lets you look up instruction names.
    This involves creating and keeping a restructured version of
    PPC_OPCODES in a closure.
    """

    # Restructure PPC_OPCODES to make it faster to search through.
    # Using this rather than looping over PPC_OPCODES makes this program
    # about 2x as fast.
    # mask_to_values structure: {mask: {value: name, ...}, ...}
    mask_to_values = {}
    for mask, masked_val, name in PPC_OPCODES:
        if mask not in mask_to_values:
            mask_to_values[mask] = {}
        mask_to_values[mask][masked_val] = name

    # Now sort that by dict size, so the dicts are checked roughly in
    # order of most- to least-likely to have a particular instruction.
    # This doesn't provide a measurable speedup, but seems like it *should* be more efficient, so...
    mask_values_pairs = []
    for mask, mask_dict in sorted(mask_to_values.items(), key=lambda elem: len(elem[1]), reverse=True):
        mask_values_pairs.append((mask, mask_dict))

    # Tried a bunch of cache sizes, 2048 seemed to work the best
    @functools.lru_cache(maxsize=2048)
    def get_inst_name(inst: int) -> str:
        """
        Get the instruction name for a particular instruction
        """
        nonlocal mask_values_pairs

        if inst == 0:
            return '(null)'

        for mask, mask_dict in mask_values_pairs:
            name = mask_dict.get(inst & mask)
            if name:
                return name

        # terminology here from 6xx_pem
        # also, this is necessarily an approximation
        opcode_primary = inst >> 26
        if opcode_primary in {19, 31, 59, 63}:
            opcode_extended = inst & 0x7ff
            return f'inst_{opcode_primary}_{opcode_extended}'
        else:
            return f'inst_{opcode_primary}'

    return get_inst_name


def find_section_containing(address: int, sections: List[code_files.CodeFileSection], *,
        executable: bool = None) -> code_files.CodeFileSection:
    """
    Find the section containing a particular address.
    If executable is True or False, only consider sections with
    matching executability.
    """
    for section in sections:
        if executable is not None:
            if section.is_executable != executable: continue
        if section.address is None: continue
        if section.address <= address < section.address + section.size:
            return section


def iter_addresses_from_sections(sections: List[code_files.CodeFileSection], *,
        executable: bool = None, align_to: int = 1, ignore_ranges: List[range] = (),
        ) -> Iterator[Tuple[int, code_files.CodeFileSection]]:
    """
    Iterate over addresses (and their respective sections, for
    convenience) from a list of code file sections.
    If executable is True or False, only consider sections with
    matching executability.
    Only addresses aligned to align_to (a power of 2) will be yielded.
    """
    prev_address = -1

    for section in sections:
        if executable is not None:
            if section.is_executable != executable: continue
        if section.address is None: continue
        if section.data is None: continue  # bss

        for offset in range(section.size):
            address = section.address + offset

            if align_to != 1:
                address = address & ~(align_to - 1)
                if address == prev_address:
                    continue

            if not any(address in r for r in ignore_ranges):
                yield address, section

            prev_address = address


def compare_opcodes_across_versions(
        code_file_1: code_files.CodeFile,
        code_file_2: code_files.CodeFile,
        rels_1: List[code_files_rel.REL],
        rels_2: List[code_files_rel.REL],
        mapper_1: lib_address_maps.AddressMapper,
        mapper_2: lib_address_maps.AddressMapper,
        *,
        limit: int = None,
        ignore_ranges: List[range] = (),
        initial_num_warnings: int = 0) -> None:
    """
    Do the opcode comparison stuff
    """

    error_handling = lib_address_maps.UnmappedAddressHandling(
        common.ErrorVolume.SILENT,
        lib_address_maps.UnmappedAddressHandling.Behavior.DROP)

    get_inst_name = create_instruction_name_lookup_func()

    all_sections_1 = list(code_file_1.sections)
    for rel_name, rel in rels_1:
        all_sections_1.extend(rel.sections)

    all_sections_2 = list(code_file_2.sections)
    for rel_name, rel in rels_2:
        all_sections_2.extend(rel.sections)

    num_warnings_printed = initial_num_warnings
    if limit is not None and num_warnings_printed >= limit:
        return

    for address_1, section_1 in iter_addresses_from_sections(
            all_sections_1, executable=True, align_to=4, ignore_ranges=ignore_ranges):
        offset_1 = address_1 - section_1.address

        # There were a few cases where they added something to the start
        # of a function, so the symbol should map one way but the
        # instructions map differently. As a convention, I mapped
        # address+1 by instruction in these cases. So, we map
        # address_1+1 here and subtract 1, instead of just mapping
        # address_1.

        address_2 = lib_address_maps.map_addr_from_to(mapper_1, mapper_2, address_1+1, error_handling=error_handling)
        if address_2 is None:
            continue
        address_2 -= 1

        section_2 = find_section_containing(address_2, all_sections_2, executable=True)
        if section_2 is None:
            print(f"{address_1:08x} -> {address_2:08x}: mapped address isn't in any section in code file 2")

            num_warnings_printed += 1
            if limit is not None and num_warnings_printed >= limit:
                break
            else:
                continue

        offset_2 = address_2 - section_2.address

        inst_1 = int.from_bytes(section_1.data[offset_1 : offset_1+4], 'big')
        inst_2 = int.from_bytes(section_2.data[offset_2 : offset_2+4], 'big')

        inst_name_1 = get_inst_name(inst_1)
        inst_name_2 = get_inst_name(inst_2)

        if inst_name_1 != inst_name_2:
            print(f'{address_1:08x} -> {address_2:08x}: {inst_name_1} -> {inst_name_2}')
            num_warnings_printed += 1

            num_warnings_printed += 1
            if limit is not None and num_warnings_printed >= limit:
                break

    if limit is not None and num_warnings_printed >= limit:
        print(f'Reached user-selected limit of {limit} warnings -- stopping here')

    return num_warnings_printed


def compare_data_across_versions(
        code_file_1: code_files.CodeFile,
        code_file_2: code_files.CodeFile,
        rels_1: List[code_files_rel.REL],
        rels_2: List[code_files_rel.REL],
        mapper_1: lib_address_maps.AddressMapper,
        mapper_2: lib_address_maps.AddressMapper,
        *,
        limit: int = None,
        ignore_pointers: bool = False,
        ignore_ranges: List[range] = (),
        initial_num_warnings: int = 0) -> None:
    """
    Do the data comparison stuff
    """

    error_handling = lib_address_maps.UnmappedAddressHandling(
        common.ErrorVolume.SILENT,
        lib_address_maps.UnmappedAddressHandling.Behavior.DROP)

    all_sections_1 = list(code_file_1.sections)
    for rel_name, rel in rels_1:
        all_sections_1.extend(rel.sections)

    all_sections_2 = list(code_file_2.sections)
    for rel_name, rel in rels_2:
        all_sections_2.extend(rel.sections)

    num_warnings_printed = initial_num_warnings
    if limit is not None and num_warnings_printed >= limit:
        return

    def iter_mismatched_bytes() -> Iterator[Tuple[int, bytes, int, bytes]]:
        """
        Iterate over (address_1, byte_1, address_2, byte_2) tuples
        """
        nonlocal num_warnings_printed

        for address_1, section_1 in iter_addresses_from_sections(
                all_sections_1, executable=False, ignore_ranges=ignore_ranges):
            offset_1 = address_1 - section_1.address

            address_2 = lib_address_maps.map_addr_from_to(mapper_1, mapper_2, address_1, error_handling=error_handling)
            if address_2 is None:
                continue

            section_2 = find_section_containing(address_2, all_sections_2, executable=False)

            if section_2 is None:
                print(f"{address_1:08x} -> {address_2:08x}: mapped address isn't in any section in code file 2")

                num_warnings_printed += 1
                if limit is not None and num_warnings_printed >= limit:
                    break
                else:
                    continue

            offset_2 = address_2 - section_2.address

            byte_1 = section_1.data[offset_1] if section_1.data is not None else 0
            byte_2 = section_2.data[offset_2] if section_2.data is not None else 0

            if byte_1 != byte_2:

                # Maybe it's part of an address!
                aligned_offset_1 = offset_1 & ~3
                aligned_offset_2 = offset_2 & ~3
                if section_1.data is None:
                    aligned_value_1 = 0
                else:
                    aligned_value_1 = int.from_bytes(section_1.data[aligned_offset_1 : aligned_offset_1+4], 'big')
                if section_2.data is None:
                    aligned_value_2 = 0
                else:
                    aligned_value_2 = int.from_bytes(section_2.data[aligned_offset_2 : aligned_offset_2+4], 'big')

                is_mismatch_explained = False

                if ignore_pointers:
                    # With this flag, "forgive" the mismatch if it looks
                    # like a pointer on both sides (i.e. we can identify
                    # which sections they'd point to)
                    is_mismatch_explained = (find_section_containing(aligned_value_1, all_sections_1) is not None
                        and find_section_containing(aligned_value_2, all_sections_2) is not None)

                else:
                    hypothetical_mapped_addr = lib_address_maps.map_addr_from_to(
                        mapper_1, mapper_2, aligned_value_1, error_handling=error_handling)
                    is_mismatch_explained = (hypothetical_mapped_addr is not None
                        and hypothetical_mapped_addr == aligned_value_2)

                if not is_mismatch_explained:
                    yield address_1, bytes([byte_1]), address_2, bytes([byte_2])

    def iter_consolidated_mismatched_bytes() -> Iterator[Tuple[int, bytes, int, bytes]]:
        """
        Iterate over (address_1, bytes_1, address_2, bytes_2) tuples,
        i.e. consolidate consecutive mismatched bytes into bytestrings
        """
        running_address_1 = None
        running_bytes_1 = None
        running_address_2 = None
        running_bytes_2 = None
        for address_1, byte_1, address_2, byte_2 in iter_mismatched_bytes():
            if running_address_1 is None:
                # No running mismatch yet -- start one
                running_address_1 = address_1
                running_bytes_1 = bytearray(byte_1)
                running_address_2 = address_2
                running_bytes_2 = bytearray(byte_2)
            elif address_1 == running_address_1 + len(running_bytes_1) \
                    and address_2 == running_address_2 + len(running_bytes_2):
                # Continue the current mismatch
                running_bytes_1 += byte_1
                running_bytes_2 += byte_2
            else:
                # Previous mismatch has ended
                yield running_address_1, bytes(running_bytes_1), running_address_2, bytes(running_bytes_2)
                running_address_1 = address_1
                running_bytes_1 = bytearray(byte_1)
                running_address_2 = address_2
                running_bytes_2 = bytearray(byte_2)

        if running_address_1 is not None:
            yield running_address_1, bytes(running_bytes_1), running_address_2, bytes(running_bytes_2)

    for address_1, bytes_1, address_2, bytes_2 in iter_consolidated_mismatched_bytes():
        print(f'{address_1:08x} -> {address_2:08x}: {bytes(bytes_1)} -> {bytes(bytes_2)}')

        num_warnings_printed += 1
        if limit is not None and num_warnings_printed >= limit:
            break

    # We keep this separate because iter_consolidated_mismatched_bytes()
    # *also* modifies and monitors num_warnings_printed, and exits early
    # if it's the first to see it go over the limit
    if limit is not None and num_warnings_printed >= limit:
        print(f'Reached user-selected limit of {limit} warnings -- stopping here')


def main(args: Optional[List[str]] = None) -> None:
    parser = argparse.ArgumentParser(
        description="Check an address map's accuracy by comparing instructions or data across two versions.")

    parser.add_argument('address_map', type=Path,
        help='address map file to use')
    parser.add_argument('name_1',
        help='game version code (e.g. "P1") that the first code file is for')
    parser.add_argument('name_2',
        help='game version code (e.g. "P2") that the second code file is for')
    parser.add_argument('code_file_1', type=Path,
        help='first code file (DOL, REL, ALF)')
    parser.add_argument('code_file_2', type=Path,
        help='second code file (DOL, REL, ALF)')
    parser.add_argument('--limit', type=int, metavar='N',
        help='stop after the first N warnings')
    parser.add_argument('--no-check-text', action='store_true',
        help="skip comparing instructions across the two versions' executable sections")
    parser.add_argument('--no-check-data', action='store_true',
        help="skip comparing data across the two versions' non-executable sections")
    parser.add_argument('--ignore-data-pointers', action='store_true',
        help="in data sections, ignore any mismatched bytes that look like pointers (useful while you're still writing the address map and there are forward references) (inclusive on both ends, same as in address map files)")
    parser.add_argument('--ignore-range', action='append',
        help='a range of addresses (relative to the first code file) to ignore')

    for num in [1, 2]:
        parser.add_argument(f'--rel-{num}', nargs=2, action='append', metavar=('REL', 'ADDRS'),
            help=f'add a REL for code file {num} and specify its static section addresses.'
            ' Addresses should be comma-separated (no spaces) hex values, one per REL section.'
            ' Example: "807685a0,8076a558,8076a560,8076a570,8076a748,8076d460"')

    parsed_args = parser.parse_args(args)

    with parsed_args.address_map.open('r', encoding='utf-8') as f:
        mappers = lib_address_maps.load_address_map(f)

    def load_code_file(path: Path) -> code_files.CodeFile:
        cf = code_files_all.load_by_extension(path.read_bytes(), path.suffix)
        if cf is not None:
            lib_nsmbw.auto_assign_alf_section_executability(cf)
            return cf
        else:
            print(f'Unknown file extension: {path.suffix}')

    def load_rels(arg: List[Tuple[str, str]]) -> List[code_files_rel.REL]:
        if arg is None:
            return []

        # Load rels and parse and assign addresses for their sections
        rels = []
        for rel_fp, rel_addrs_str in arg:
            rel_fp = Path(rel_fp)

            rel_name = rel_fp.name.split('.')[0]

            with rel_fp.open('rb') as f:
                rel = code_files_rel.REL.from_file(f)
            rels.append((rel_name, rel))

            addrs = [int(p, 16) for p in rel_addrs_str.split(',')]

            filtered_sections = [s for s in rel.sections if not s.is_null()]

            if len(addrs) != len(filtered_sections):
                raise ValueError(
                    f'Expected {len(filtered_sections)} section addresses for REL,'
                    f' but got {len(addrs)} on the command line')

            # Apply static section addresses
            for section, addr in zip(filtered_sections, addrs):
                section.address = addr

        return rels

    code_file_1 = load_code_file(parsed_args.code_file_1)
    code_file_2 = load_code_file(parsed_args.code_file_2)
    rels_1 = load_rels(parsed_args.rel_1)
    rels_2 = load_rels(parsed_args.rel_2)

    ignore_ranges = []
    if parsed_args.ignore_range is not None:
        for range_str in parsed_args.ignore_range:
            if range_str.count('-') != 1:
                raise ValueError(f'Address range "{range_str}" has invalid format')
            range_vals = [int(v, 16) for v in range_str.split('-')]
            ignore_ranges.append(range(range_vals[0], range_vals[1] + 1))

    num_warnings_so_far = 0

    if not parsed_args.no_check_text:
        num_warnings_so_far = compare_opcodes_across_versions(
            code_file_1, code_file_2,
            rels_1, rels_2,
            mappers[parsed_args.name_1], mappers[parsed_args.name_2],
            limit=parsed_args.limit,
            ignore_ranges=ignore_ranges,
            initial_num_warnings=num_warnings_so_far)

    if not parsed_args.no_check_data:
        compare_data_across_versions(
            code_file_1, code_file_2,
            rels_1, rels_2,
            mappers[parsed_args.name_1], mappers[parsed_args.name_2],
            limit=parsed_args.limit,
            ignore_pointers=parsed_args.ignore_data_pointers,
            ignore_ranges=ignore_ranges,
            initial_num_warnings=num_warnings_so_far)


if __name__ == '__main__':
    main()
