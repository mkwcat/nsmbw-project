// d_mask_mng.cpp
// NSMBW .text: 0x800CD290 - 0x800CD800

#include "d_system/d_mj2d_game.h"

namespace dMaskMng
{

[[nsmbw(0x800CD290)]]
void CreatePlayerMask() ASM_METHOD(
  // clang-format off
/* 800CD290 9421FFD0 */  stwu     r1, -48(r1);
/* 800CD294 7C0802A6 */  mflr     r0;
/* 800CD298 90010034 */  stw      r0, 52(r1);
/* 800CD29C DBE10020 */  stfd     f31, 32(r1);
/* 800CD2A0 F3E10028 */  .long    0xF3E10028; // psq_st   f31, 40(r1), 0, 0;
/* 800CD2A4 93E1001C */  stw      r31, 28(r1);
/* 800CD2A8 806DA730 */  lwz      r3, UNDEF_8042a0b0@sda21;
/* 800CD2AC 3C830009 */  addis    r4, r3, 9;
/* 800CD2B0 C3E4FE6C */  lfs      f31, -404(r4);
/* 800CD2B4 4BFAB6ED */  bl       UNDEF_800789a0;
/* 800CD2B8 C0029910 */  lfs      f0, UNDEF_8042cc70@sda21;
/* 800CD2BC 3BE00000 */  li       r31, 0;
/* 800CD2C0 D0210008 */  stfs     f1, 8(r1);
/* 800CD2C4 D3E1000C */  stfs     f31, 12(r1);
/* 800CD2C8 D0010010 */  stfs     f0, 16(r1);
UNDEF_800cd2cc:;
/* 800CD2CC 57E4043E */  clrlwi   r4, r31, 16;
/* 800CD2D0 38A10008 */  addi     r5, r1, 8;
/* 800CD2D4 3860025C */  li       r3, 604;
/* 800CD2D8 38C00000 */  li       r6, 0;
/* 800CD2DC 38E00000 */  li       r7, 0;
/* 800CD2E0 4BF97331 */  bl       UNDEF_80064610; // construct__8dActor_cFUsUlPC7mVec3_cPC7mAng3_cUc;
/* 800CD2E4 3BFF0001 */  addi     r31, r31, 1;
/* 800CD2E8 281F0008 */  cmplwi   r31, PLAYER_COUNT * 2;
/* 800CD2EC 4180FFE0 */  blt+     UNDEF_800cd2cc;
/* 800CD2F0 80010034 */  lwz      r0, 52(r1);
/* 800CD2F4 E3E10028 */  .long    0xE3E10028; // psq_l    f31, 40(r1), 0, 0;
/* 800CD2F8 CBE10020 */  lfd      f31, 32(r1);
/* 800CD2FC 83E1001C */  lwz      r31, 28(r1);
/* 800CD300 7C0803A6 */  mtlr     r0;
/* 800CD304 38210030 */  addi     r1, r1, 48;
/* 800CD308 4E800020 */  blr;

  // clang-format on
);

}