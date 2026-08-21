// d_a_fireball_player.cpp
// NSMBW .text: 0x8011A5B0 - 0x8011B640

#include "d_static/d_mj2d_game.h"
#include <mkwcat/Relocate.hpp>

/* 0x80375840 */
int daFireBall_Player_c_m_limit1[PLAYER_COUNT];

/* 0x80375850 */
int daFireBall_Player_c_m_limit2[PLAYER_COUNT];

[[nsmbw(0x8011A6B0)]]
void daFireBall_Player_c_createCheck(void* this_) ASM_METHOD(
  // clang-format off
/* 8011A6B0 9421FFF0 */  stwu     r1, -16(r1);
/* 8011A6B4 7C0802A6 */  mflr     r0;
/* 8011A6B8 90010014 */  stw      r0, 20(r1);
/* 8011A6BC 93E1000C */  stw      r31, 12(r1);
/* 8011A6C0 7C7F1B78 */  mr       r31, r3;
/* 8011A6C4 80030004 */  lwz      r0, 4(r3);
/* 8011A6C8          */  rlwinm   r3, r0, 0, 0xF;
/* 8011A6CC 540487BE */  extrwi   r4, r0, 2, 14;
/* 8011A6D0 48000991 */  bl       UNDEF_8011b060;
/* 8011A6D4 80DF0004 */  lwz      r6, 4(r31);
/* 8011A6D8 3CE08037 */  lis      r7, daFireBall_Player_c_m_limit1@ha;
/* 8011A6DC 3CA08037 */  lis      r5, daFireBall_Player_c_m_limit2@ha;
/* 8011A6E0 3800003C */  li       r0, 60;
/* 8011A6E4          */  rlwinm   r4, r6, 0, 0xF;
/* 8011A6E8 989F038D */  stb      r4, 909(r31);
/* 8011A6EC          */  rlwinm   r8, r6, 2, 0xF << 2;
/* 8011A6F0 38E75840 */  addi     r7, r7, daFireBall_Player_c_m_limit1@l;
/* 8011A6F4 909F0554 */  stw      r4, 1364(r31);
/* 8011A6F8 38A55850 */  addi     r5, r5, daFireBall_Player_c_m_limit2@l;
/* 8011A6FC 7CC7402E */  lwzx     r6, r7, r8;
/* 8011A700 7C85402E */  lwzx     r4, r5, r8;
/* 8011A704 38C60001 */  addi     r6, r6, 1;
/* 8011A708 7CC7412E */  stwx     r6, r7, r8;
/* 8011A70C 38840001 */  addi     r4, r4, 1;
/* 8011A710 7C85412E */  stwx     r4, r5, r8;
/* 8011A714 901F0558 */  stw      r0, 1368(r31);
/* 8011A718 83E1000C */  lwz      r31, 12(r1);
/* 8011A71C 80010014 */  lwz      r0, 20(r1);
/* 8011A720 7C0803A6 */  mtlr     r0;
/* 8011A724 38210010 */  addi     r1, r1, 16;
/* 8011A728 4E800020 */  blr;
  // clang-format on
);

PATCH_REFERENCES(
  &daFireBall_Player_c_m_limit1, //
  {
    {0x8011A6DA, R_PPC_ADDR16_HA},
    {0x8011A6F2, R_PPC_ADDR16_LO},
    {0x8011AC96, R_PPC_ADDR16_HA},
    {0x8011AC9A, R_PPC_ADDR16_LO},
    {0x8011B062, R_PPC_ADDR16_HA},
    {0x8011B06A, R_PPC_ADDR16_LO},
  }
);

PATCH_REFERENCES(
  &daFireBall_Player_c_m_limit2, //
  {
    {0x8011A6DE, R_PPC_ADDR16_HA},
    {0x8011A6FA, R_PPC_ADDR16_LO},
    {0x8011ACCA, R_PPC_ADDR16_HA},
    {0x8011ACCE, R_PPC_ADDR16_LO},
    {0x8011AD46, R_PPC_ADDR16_HA},
    {0x8011AD4A, R_PPC_ADDR16_LO},
    {0x8011B08A, R_PPC_ADDR16_HA},
    {0x8011B08E, R_PPC_ADDR16_LO},
  }
);
