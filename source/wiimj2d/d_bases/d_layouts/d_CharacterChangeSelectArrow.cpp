// d_CharacterChangeSelectArrow.cpp
// NSMBW d_bases.text: 0x8076DEE0 - 0x8076F350

#include "d_CharacterChangeSelectArrow.h"

[[nsmbw(0x8076E600)]]
void dCharacterChangeSelectArrow_c::executeState_OnStageWait() ASM_METHOD(
  // clang-format off
/* 8076E600 80030264 */  lwz      r0, 612(r3);
/* 8076E604          */  cmpwi    r0, -3;
/* 8076E608 40820024 */  bne-     UNDEF_8076e62c;
/* 8076E60C 38800001 */  li       r4, 1;
/* 8076E610 38000000 */  li       r0, 0;
/* 8076E614 90830254 */  stw      r4, 596(r3);
/* 8076E618 80830248 */  lwz      r4, 584(r3);
/* 8076E61C 90030250 */  stw      r0, 592(r3);
/* 8076E620 880400BB */  lbz      r0, 187(r4);
/* 8076E624 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8076E628 980400BB */  stb      r0, 187(r4);
UNDEF_8076e62c:;
/* 8076E62C 80030264 */  lwz      r0, 612(r3);
/* 8076E630          */  cmpwi    r0, 4;
/* 8076E634 40820024 */  bne-     UNDEF_8076e658;
/* 8076E638 38800000 */  li       r4, 0;
/* 8076E63C 38000001 */  li       r0, 1;
/* 8076E640 90830254 */  stw      r4, 596(r3);
/* 8076E644 8083024C */  lwz      r4, 588(r3);
/* 8076E648 90030250 */  stw      r0, 592(r3);
/* 8076E64C 880400BB */  lbz      r0, 187(r4);
/* 8076E650 5400063C */  rlwinm   r0, r0, 0, 24, 30;
/* 8076E654 980400BB */  stb      r0, 187(r4);
UNDEF_8076e658:;
/* 8076E658 80030264 */  lwz      r0, 612(r3);
/* 8076E65C 3C808099 */  lis      r4, UNDEF_80990858@ha;
/* 8076E660 90030260 */  stw      r0, 608(r3);
/* 8076E664 38840858 */  addi     r4, r4, UNDEF_80990858@l;
/* 8076E668 85830208 */  lwzu     r12, 520(r3);
/* 8076E66C 818C0018 */  lwz      r12, 24(r12);
/* 8076E670 7D8903A6 */  mtctr    r12;
/* 8076E674 4E800420 */  bctr;
  // clang-format on
);

[[nsmbw(0x8076EA00)]]
void dCharacterChangeSelectArrow_c::executeState_HitAnimeEndWait() ASM_METHOD(
  // clang-format off
/* 8076EA00 9421FFF0 */  stwu     r1, -16(r1);
/* 8076EA04 7C0802A6 */  mflr     r0;
/* 8076EA08 3880FFFF */  li       r4, -1;
/* 8076EA0C 90010014 */  stw      r0, 20(r1);
/* 8076EA10 93E1000C */  stw      r31, 12(r1);
/* 8076EA14 7C7F1B78 */  mr       r31, r3;
/* 8076EA18 38630070 */  addi     r3, r3, 112;
/* 8076EA1C 4B95ACE5 */  bl       UNDEF_800c9700;
/* 8076EA20 2C030000 */  cmpwi    r3, 0;
/* 8076EA24 4082012C */  bne-     UNDEF_8076eb50;
/* 8076EA28 807F0264 */  lwz      r3, 612(r31);
/* 8076EA2C 801F0260 */  lwz      r0, 608(r31);
/* 8076EA30 7C001800 */  cmpw     r0, r3;
/* 8076EA34 41820100 */  beq-     UNDEF_8076eb34;
/* 8076EA38          */  cmpwi    r3, -3;
/* 8076EA3C 907F0260 */  stw      r3, 608(r31);
/* 8076EA40 40820044 */  bne-     UNDEF_8076ea84;
/* 8076EA44 801F0250 */  lwz      r0, 592(r31);
/* 8076EA48 2C000002 */  cmpwi    r0, 2;
/* 8076EA4C 4082006C */  bne-     UNDEF_8076eab8;
/* 8076EA50 387F0070 */  addi     r3, r31, 112;
/* 8076EA54 38800002 */  li       r4, 2;
/* 8076EA58 4B95AB29 */  bl       UNDEF_800c9580;
/* 8076EA5C 38000003 */  li       r0, 3;
/* 8076EA60 901F0250 */  stw      r0, 592(r31);
/* 8076EA64 3C808099 */  lis      r4, UNDEF_80990858@ha;
/* 8076EA70 38840858 */  addi     r4, r4, UNDEF_80990858@l;
// /* 8076EA68 387F0208 */  addi     r3, r31, 520;
// /* 8076EA6C 819F0208 */  lwz      r12, 520(r31);
// /* 8076EA74 818C0018 */  lwz      r12, 24(r12);
// /* 8076EA78 7D8903A6 */  mtctr    r12;
// /* 8076EA7C 4E800421 */  bctrl;
/* 8076EA80          */  b        L_executeState_HitAnimeEndWait_CallChangeState;
UNDEF_8076ea84:;
/* 8076EA84 801F0254 */  lwz      r0, 596(r31);
/* 8076EA88 2C000000 */  cmpwi    r0, 0;
/* 8076EA8C 4082002C */  bne-     UNDEF_8076eab8;
/* 8076EA90 38000001 */  li       r0, 1;
/* 8076EA94 901F0254 */  stw      r0, 596(r31);
/* 8076EA98 3C808099 */  lis      r4, UNDEF_80990858@ha;
/* 8076EAA4 38840858 */  addi     r4, r4, UNDEF_80990858@l;
// /* 8076EA9C 387F0208 */  addi     r3, r31, 520;
// /* 8076EAA0 819F0208 */  lwz      r12, 520(r31);
// /* 8076EAA8 818C0018 */  lwz      r12, 24(r12);
// /* 8076EAAC 7D8903A6 */  mtctr    r12;
// /* 8076EAB0 4E800421 */  bctrl;
/* 8076EAB4          */  b        L_executeState_HitAnimeEndWait_CallChangeState;
UNDEF_8076eab8:;
/* 8076EAB8          */  cmpwi    r3, 4;
/* 8076EABC 40820044 */  bne-     UNDEF_8076eb00;
/* 8076EAC0 801F0254 */  lwz      r0, 596(r31);
/* 8076EAC4 2C000002 */  cmpwi    r0, 2;
/* 8076EAC8 4082006C */  bne-     UNDEF_8076eb34;
/* 8076EACC 387F0070 */  addi     r3, r31, 112;
/* 8076EAD0 38800003 */  li       r4, 3;
/* 8076EAD4 4B95AAAD */  bl       UNDEF_800c9580;
/* 8076EAD8 38000003 */  li       r0, 3;
/* 8076EADC 901F0254 */  stw      r0, 596(r31);
/* 8076EAE0 3C808099 */  lis      r4, UNDEF_80990858@ha;
/* 8076EAEC 38840858 */  addi     r4, r4, UNDEF_80990858@l;
// /* 8076EAE4 387F0208 */  addi     r3, r31, 520;
// /* 8076EAE8 819F0208 */  lwz      r12, 520(r31);
// /* 8076EAF0 818C0018 */  lwz      r12, 24(r12);
// /* 8076EAF4 7D8903A6 */  mtctr    r12;
// /* 8076EAF8 4E800421 */  bctrl;
/* 8076EAFC          */  b        L_executeState_HitAnimeEndWait_CallChangeState;
UNDEF_8076eb00:;
/* 8076EB00 801F0250 */  lwz      r0, 592(r31);
/* 8076EB04 2C000000 */  cmpwi    r0, 0;
/* 8076EB08 4082002C */  bne-     UNDEF_8076eb34;
/* 8076EB0C 38000001 */  li       r0, 1;
/* 8076EB10 901F0250 */  stw      r0, 592(r31);
/* 8076EB14 3C808099 */  lis      r4, UNDEF_80990858@ha;
/* 8076EB20 38840858 */  addi     r4, r4, UNDEF_80990858@l;
// /* 8076EB18 387F0208 */  addi     r3, r31, 520;
// /* 8076EB1C 819F0208 */  lwz      r12, 520(r31);
// /* 8076EB24 818C0018 */  lwz      r12, 24(r12);
// /* 8076EB28 7D8903A6 */  mtctr    r12;
// /* 8076EB2C 4E800421 */  bctrl;
/* 8076EB30          */  b        L_executeState_HitAnimeEndWait_CallChangeState;
UNDEF_8076eb34:;
/* 8076EB38 3C808099 */  lis      r4, UNDEF_80990898@ha;
/* 8076EB44 38840898 */  addi     r4, r4, UNDEF_80990898@l;
L_executeState_HitAnimeEndWait_CallChangeState:;
/* 8076EB34 819F0208 */  lwz      r12, 520(r31);
/* 8076EB3C 387F0208 */  addi     r3, r31, 520;
/* 8076EB40 818C0018 */  lwz      r12, 24(r12);
/* 8076EB48 7D8903A6 */  mtctr    r12;
/* 8076EB4C 4E800421 */  bctrl;
UNDEF_8076eb50:;
/* 8076EB50 80010014 */  lwz      r0, 20(r1);
/* 8076EB54 83E1000C */  lwz      r31, 12(r1);
/* 8076EB58 7C0803A6 */  mtlr     r0;
/* 8076EB5C 38210010 */  addi     r1, r1, 16;
/* 8076EB60 4E800020 */  blr;
  // clang-format on
);
