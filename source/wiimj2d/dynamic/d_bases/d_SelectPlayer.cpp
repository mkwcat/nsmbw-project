// d_SelectPlayer.cpp
// NSMBW: 0x807ABE10 - 0x807AD5F0

#include "d_SelectPlayer.h"

[[address(0x807AC7A0)]]
void dSelectPlayer_c::executeState_StartMemberSelect() ASM_METHOD(
  // clang-format off
/* 807AC7A0 9421FFF0 */  stwu     r1, -16(r1);
/* 807AC7A4 7C0802A6 */  mflr     r0;
/* 807AC7A8 3C808043 */  lis      r4, UNDEF_8042a230@ha;
/* 807AC7AC 90010014 */  stw      r0, 20(r1);
/* 807AC7B0 93E1000C */  stw      r31, 12(r1);
/* 807AC7B4 3FE08099 */  lis      r31, UNDEF_80995390@ha;
/* 807AC7B8 3BFF5390 */  addi     r31, r31, UNDEF_80995390@l;
/* 807AC7BC 93C10008 */  stw      r30, 8(r1);
/* 807AC7C0 7C7E1B78 */  mr       r30, r3;
/* 807AC7C4 80C3026C */  lwz      r6, 620(r3);
/* 807AC7C8 80A4A230 */  lwz      r5, UNDEF_8042a230@l(r4);
/* 807AC7CC 2C860000 */  cmpwi    cr1, r6, 0;
/* 807AC7D0 4186006C */  beq-     cr1, UNDEF_807ac83c;
/* 807AC7D4 3C808043 */  lis      r4, UNDEF_8042a744@ha;
/* 807AC7D8 8004A744 */  lwz      r0, UNDEF_8042a744@l(r4);
/* 807AC7DC 5400103A */  slwi     r0, r0, 2;
/* 807AC7E0 7C850214 */  add      r4, r5, r0;
/* 807AC7E4 80840004 */  lwz      r4, 4(r4);
/* 807AC7E8 8084001C */  lwz      r4, 28(r4);
/* 807AC7EC 548007BD */  rlwinm.  r0, r4, 0, 30, 30;
/* 807AC7F0 41820014 */  beq-     UNDEF_807ac804;
/* 807AC7F4 41860008 */  beq-     cr1, UNDEF_807ac7fc;
/* 807AC7F8 90C3027C */  stw      r6, 636(r3);
UNDEF_807ac7fc:;
/* 807AC7FC 38C00000 */  li       r6, 0;
/* 807AC800 48000060 */  b        UNDEF_807ac860;
UNDEF_807ac804:;
/* 807AC804 54800739 */  rlwinm.  r0, r4, 0, 28, 28;
/* 807AC808 41820018 */  beq-     UNDEF_807ac820;
/* 807AC80C 38C6FFFF */  subi     r6, r6, 1;
/* 807AC810 2C060001 */  cmpwi    r6, 1;
/* 807AC814 4080004C */  bge-     UNDEF_807ac860;
/* 807AC818 38C00001 */  li       r6, 1;
/* 807AC81C 48000044 */  b        UNDEF_807ac860;
UNDEF_807ac820:;
/* 807AC820 5480077B */  rlwinm.  r0, r4, 0, 29, 29;
/* 807AC824 4182003C */  beq-     UNDEF_807ac860;
/* 807AC828 38C60001 */  addi     r6, r6, 1;
/* 807AC82C 2C060003 */  cmpwi    r6, 3;
/* 807AC830 40810030 */  ble-     UNDEF_807ac860;
/* 807AC834 38C00003 */  li       r6, 3;
/* 807AC838 48000028 */  b        UNDEF_807ac860;
UNDEF_807ac83c:;
/* 807AC83C 3C808043 */  lis      r4, UNDEF_8042a744@ha;
/* 807AC840 8004A744 */  lwz      r0, UNDEF_8042a744@l(r4);
/* 807AC844 5400103A */  slwi     r0, r0, 2;
/* 807AC848 7C850214 */  add      r4, r5, r0;
/* 807AC84C 80840004 */  lwz      r4, 4(r4);
/* 807AC850 8004001C */  lwz      r0, 28(r4);
/* 807AC854 540007FF */  clrlwi.  r0, r0, 31;
/* 807AC858 41820008 */  beq-     UNDEF_807ac860;
/* 807AC85C 80C3027C */  lwz      r6, 636(r3);
UNDEF_807ac860:;
/* 807AC860 8003026C */  lwz      r0, 620(r3);
/* 807AC864 7C060000 */  cmpw     r6, r0;
/* 807AC868 41820020 */  beq-     UNDEF_807ac888;
/* 807AC86C 90C3026C */  stw      r6, 620(r3);
/* 807AC870 389F00D0 */  addi     r4, r31, 208;
/* 807AC874 85830070 */  lwzu     r12, 112(r3);
/* 807AC878 818C0018 */  lwz      r12, 24(r12);
/* 807AC87C 7D8903A6 */  mtctr    r12;
/* 807AC880 4E800421 */  bctrl;
/* 807AC884 480000B0 */  b        UNDEF_807ac934;
UNDEF_807ac888:;
/* 807AC888 3C608043 */  lis      r3, UNDEF_8042a748@ha;
/* 807AC88C 38800900 */  li       r4, 2304;
/* 807AC890 8063A748 */  lwz      r3, UNDEF_8042a748@l(r3);
/* 807AC894 81830000 */  lwz      r12, 0(r3);
/* 807AC898 818C0020 */  lwz      r12, 32(r12);
/* 807AC89C 7D8903A6 */  mtctr    r12;
/* 807AC8A0 4E800421 */  bctrl;
/* 807AC8A4 2C030000 */  cmpwi    r3, 0;
/* 807AC8A8 41820048 */  beq-     UNDEF_807ac8f0;
/* 807AC8AC 38000001 */  li       r0, 1;
/* 807AC8B0 901E0270 */  stw      r0, 624(r30);
/* 807AC8B4 387E0070 */  addi     r3, r30, 112;
/* 807AC8B8 389F0190 */  addi     r4, r31, 400;
/* 807AC8BC 819E0070 */  lwz      r12, 112(r30);
/* 807AC8C0 818C0018 */  lwz      r12, 24(r12);
/* 807AC8C4 7D8903A6 */  mtctr    r12;
/* 807AC8C8 4E800421 */  bctrl;
                         // Remove Mario's "here we go" sound
// /* 807AC8CC 801E026C */  lwz      r0, 620(r30);
// /* 807AC8D0 2C000000 */  cmpwi    r0, 0;
// /* 807AC8D4 40820060 */  bne-     UNDEF_807ac934;
// /* 807AC8D8 3C608043 */  lis      r3, UNDEF_8042a768@ha;
// /* 807AC8DC 38800323 */  li       r4, 803;
// /* 807AC8E0 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
// /* 807AC8E4 38A00001 */  li       r5, 1;
// /* 807AC8E8 4B9E8BD9 */  bl       UNDEF_801954c0;
/* 807AC8EC 48000048 */  b        UNDEF_807ac934;
UNDEF_807ac8f0:;
/* 807AC8F0 38600000 */  li       r3, 0;
/* 807AC8F4 4B908AFD */  bl       UNDEF_800b53f0;
/* 807AC8F8 2C030000 */  cmpwi    r3, 0;
/* 807AC8FC 41820038 */  beq-     UNDEF_807ac934;
/* 807AC900 3800FFFF */  li       r0, -1;
/* 807AC904 901E0270 */  stw      r0, 624(r30);
/* 807AC908 3C608043 */  lis      r3, UNDEF_8042a768@ha;
/* 807AC90C 3880007A */  li       r4, 122;
/* 807AC910 8063A768 */  lwz      r3, UNDEF_8042a768@l(r3);
/* 807AC914 38A00001 */  li       r5, 1;
/* 807AC918 4B9E8BA9 */  bl       UNDEF_801954c0;
/* 807AC91C 819E0070 */  lwz      r12, 112(r30);
/* 807AC920 387E0070 */  addi     r3, r30, 112;
/* 807AC924 389F01D0 */  addi     r4, r31, 464;
/* 807AC928 818C0018 */  lwz      r12, 24(r12);
/* 807AC92C 7D8903A6 */  mtctr    r12;
/* 807AC930 4E800421 */  bctrl;
UNDEF_807ac934:;
/* 807AC934 80010014 */  lwz      r0, 20(r1);
/* 807AC938 83E1000C */  lwz      r31, 12(r1);
/* 807AC93C 83C10008 */  lwz      r30, 8(r1);
/* 807AC940 7C0803A6 */  mtlr     r0;
/* 807AC944 38210010 */  addi     r1, r1, 16;
/* 807AC948 4E800020 */  blr;
  // clang-format on
);