// d_s_stage_static.cpp
// NSMBW .text: 0x80101A50 - 0x80102770

#include "d_s_stage.h"

#include "d_system/d_mj2d_game.h"
#include <mkwcat/Relocate.hpp>

[[address_data(0x8042A4A8)]]
dScStage_c* dScStage_c::m_instance;

[[address_data(0x8042A4DC)]]
s32 dScStage_c::m_goalType;

[[address_data(0x8042A4E0)]]
u32 dScStage_c::m_exeFrame;

[[address_data(0x8042A4E4)]]
dScStage_c::GAME_MODE_e dScStage_c::m_gameMode;

[[address_data(0x8042A4FC)]]
bool dScStage_c::m_isCourseIn;

[[address_data(0x8042A4FD)]]
bool dScStage_c::m_isCourseOut;

[[address_data(0x8042A4FE)]]
bool dScStage_c::m_isOtehonReturn;

[[address_data(0x8042A4FF)]]
bool dScStage_c::m_isStaffCredit;

[[address_data(0x8042A500)]]
s32 dScStage_c::m_miniGame;

[[address_data(0x8042A504)]]
u8 dScStage_c::m_replayMode;

[[address_data(0x8042A506)]]
bool dScStage_c::m_isReplayGoal;

[[address_data(0x803744B0)]]
PLAYER_TYPE_e dScStage_c::mCollectionCoin[COLLECTION_COIN_COUNT];

/* 0x803744D0 */
dReplayPlay_c* dScStage_c::m_replayPlay_p[PLAYER_COUNT];

[[address(0x80101A70)]]
dGameDisplay_c* dScStage_c::getGameDisplay();

[[address(0x80101AA0)]]
void dScStage_c::setLoopType() ASM_METHOD(
  // clang-format off
/* 80101AA0 9421FFE0 */  stwu     r1, -32(r1);
/* 80101AA4 7C0802A6 */  mflr     r0;
/* 80101AA8 90010024 */  stw      r0, 36(r1);
                         lis      r5, m_instance__10dScStage_c@ha;
                         lwz      r5, m_instance__10dScStage_c@l(r5);
                         lis      r3, UNDEF_8042a178@ha;
                         lwz      r3, UNDEF_8042a178@l(r3); // dCd_c::m_instance
/* 80101AB4 8805120E */  lbz      r0, 4622(r5);
/* 80101AB8 1C0003B0 */  mulli    r0, r0, 944;
/* 80101ABC 7C630214 */  add      r3, r3, r0;
/* 80101AC0 8003002C */  lwz      r0, 44(r3);
/* 80101AC4 2C000000 */  cmpwi    r0, 0;
/* 80101AC8 41820008 */  beq-     UNDEF_80101ad0;
/* 80101ACC 48000008 */  b        UNDEF_80101ad4;
UNDEF_80101ad0:;
/* 80101AD0 38600000 */  li       r3, 0;
UNDEF_80101ad4:;
/* 80101AD4 38000000 */  li       r0, 0;
                         lis      r4, UNDEF_8042a4e8@ha;
                         stw      r0, UNDEF_8042a4e8@l(r4); // dScStage_c::LoopType
/* 80101ADC 8083000C */  lwz      r4, 12(r3);
/* 80101AE0 A0040008 */  lhz      r0, 8(r4);
/* 80101AE4 540007FF */  clrlwi.  r0, r0, 31;
/* 80101AE8 418200AC */  beq-     UNDEF_80101b94;
/* 80101B1C 8885120F */  lbz      r4, 4623(r5);
/* 80101B20 4BF8CC21 */  bl       UNDEF_8008e740;
/* 80101B24 5463043E */  clrlwi   r3, r3, 16;
/* 80101B28 3C004330 */  lis      r0, 17200;
/* 80101B2C 6C638000 */  xoris    r3, r3, 32768;
/* 80101B30 9061000C */  stw      r3, 12(r1);
                         lis      r4, UNDEF_8042d408@ha;
                         lfdu     f3, UNDEF_8042d408@l(r4);
/* 80101B38 90010008 */  stw      r0, 8(r1);
/* 80101B3C          */  lfs      f1, -4(r4);
/* 80101B40 C8410008 */  lfd      f2, 8(r1);
/* 80101B44          */  lfs      f0, -8(r4);
/* 80101B48 EC421828 */  fsubs    f2, f2, f3;
/* 80101B4C EC220072 */  fmuls    f1, f2, f1;
/* 80101B50 EC00082A */  fadds    f0, f0, f1;
/* 80101B54 FC00001E */  fctiwz   f0, f0;
/* 80101B58 D8010010 */  stfd     f0, 16(r1);
/* 80101B5C 80010014 */  lwz      r0, 20(r1);
                         lis      r4, UNDEF_8042a4e8@ha;
/* 80101B60 2C00001A */  cmpwi    r0, 26;
/* 80101B64 4182001C */  beq-     UNDEF_80101b80;
/* 80101B68 2C000020 */  cmpwi    r0, 32;
/* 80101B6C 41820014 */  beq-     UNDEF_80101b80;
/* 80101B70 2C000023 */  cmpwi    r0, 35;
/* 80101B74 4182000C */  beq-     UNDEF_80101b80;
/* 80101B78 2C000025 */  cmpwi    r0, 37;
/* 80101B7C 40820010 */  bne-     UNDEF_80101b8c;
UNDEF_80101b80:;
/* 80101B80 38000001 */  li       r0, 1;
                         stw      r0, UNDEF_8042a4e8@l(r4); // dScStage_c::LoopType
/* 80101B88 4800000C */  b        UNDEF_80101b94;
UNDEF_80101b8c:;
/* 80101B8C 38000002 */  li       r0, 2;
                         stw      r0, UNDEF_8042a4e8@l(r4); // dScStage_c::LoopType
UNDEF_80101b94:;
/* 80101B94 80010024 */  lwz      r0, 36(r1);
/* 80101B98 7C0803A6 */  mtlr     r0;
/* 80101B9C 38210020 */  addi     r1, r1, 32;
/* 80101BA0 4E800020 */  blr;
  // clang-format on
);

[[address(0x801020E0)]]
void dScStage_c::setCollectionCoin(int coin, PLAYER_TYPE_e player);

[[address(0x801022C0)]]
bool dScStage_c::isNowReplay();

[[address(0x80102370)]]
void dScStage_c::goToSceneAfterLevel(int profile, int sceneParam, int exitMode, dFader_c::fader_type_e faderType) ASM_METHOD(
  // clang-format off
/* 80102370 9421FFE0 */  stwu     r1, -32(r1);
/* 80102374 7C0802A6 */  mflr     r0;
/* 80102378 90010024 */  stw      r0, 36(r1);
/* 8010237C 39610020 */  addi     r11, r1, 32;
/* 80102380 481DACE5 */  bl       UNDEF_802dd064;
/* 80102384 7C7D1B78 */  mr       r29, r3;
/* 80102388 7C9C2378 */  mr       r28, r4;
/* 8010238C 7CBB2B78 */  mr       r27, r5;
/* 80102390 7CC33378 */  mr       r3, r6;
/* 80102394 4BFAEA1D */  bl       UNDEF_800b0db0;
/* 80102398 808DAB64 */  lwz      r4, -21660(r13);
/* 8010239C 3804FFFE */  subi     r0, r4, 2;
/* 801023A0 28000001 */  cmplwi   r0, 1;
/* 801023A4 41810040 */  bgt-     UNDEF_801023e4;
/* 801023A8 281D000A */  cmplwi   r29, 10;
/* 801023AC 38000002 */  li       r0, 2;
/* 801023B0 900D999C */  stw      r0, -26212(r13);
/* 801023B4 4182001C */  beq-     UNDEF_801023d0;
/* 801023B8 281D0008 */  cmplwi   r29, 8;
/* 801023BC 41820014 */  beq-     UNDEF_801023d0;
/* 801023C0 38600000 */  li       r3, 0;
/* 801023C4 38800000 */  li       r4, 0;
/* 801023C8 4BFFF519 */  bl       UNDEF_801018e0;
/* 801023CC 480001CC */  b        UNDEF_80102598;
UNDEF_801023d0:;
/* 801023D0 7FA3EB78 */  mr       r3, r29;
/* 801023D4 7F84E378 */  mr       r4, r28;
/* 801023D8 38A00000 */  li       r5, 0;
/* 801023DC 4BFDFB75 */  bl       UNDEF_800e1f50;
/* 801023E0 480001B8 */  b        UNDEF_80102598;
UNDEF_801023e4:;
/* 801023E4 800DA8E0 */  lwz      r0, -22304(r13);
/* 801023E8 540006F7 */  rlwinm.  r0, r0, 0, 27, 27           ;
/* 801023EC 418200D4 */  beq-     UNDEF_801024c0;
/* 801023F0 83ADA910 */  lwz      r29, -22256(r13);
/* 801023F4 2C1D0000 */  cmpwi    r29, 0;
/* 801023F8 41820040 */  beq-     UNDEF_80102438;
/* 801023FC 3FC08035 */  lis      r30, UNDEF_80355160@ha;
/* 80102400 3FE08035 */  lis      r31, UNDEF_80355190@ha;
/* 80102404 3BDE5160 */  addi     r30, r30, UNDEF_80355160@l;
/* 80102408 3B800000 */  li       r28, 0;
/* 8010240C 3BFF5190 */  addi     r31, r31, UNDEF_80355190@l;
UNDEF_80102410:;
/* 80102410 801E0000 */  lwz      r0, 0(r30);
/* 80102414 7FA3EB78 */  mr       r3, r29;
/* 80102418 7F85E378 */  mr       r5, r28;
/* 8010241C 5400103A */  slwi     r0, r0, 2                 ;
/* 80102420 7C9F002E */  lwzx     r4, r31, r0;
/* 80102424 4BFCC60D */  bl       UNDEF_800cea30;
/* 80102428 3B9C0001 */  addi     r28, r28, 1;
/* 8010242C 3BDE0004 */  addi     r30, r30, 4;
/* 80102430 2C1C0004 */  cmpwi    r28, PLAYER_COUNT;
/* 80102434 4180FFDC */  blt+     UNDEF_80102410;
UNDEF_80102438:;
/* 80102438 2C1B0000 */  cmpwi    r27, 0;
/* 8010243C 38000002 */  li       r0, 2;
/* 80102440 900D999C */  stw      r0, -26212(r13);
/* 80102444 40820034 */  bne-     UNDEF_80102478;


/* 80102464 386002C7 */  li       r3, 711;
/* 80102468 38800000 */  li       r4, 0;
/* 8010246C 38A00000 */  li       r5, 0;
/* 80102470 4BFDFAE1 */  bl       UNDEF_800e1f50;
/* 80102474 48000124 */  b        UNDEF_80102598;
UNDEF_80102478:;
/* 80102478 4BFB2C19 */  bl       UNDEF_800b5090;
/* 8010247C 800DA8E0 */  lwz      r0, -22304(r13);
/* 80102480 540006B5 */  rlwinm.  r0, r0, 0, 26, 26           ;
/* 80102484 41820018 */  beq-     UNDEF_8010249c;
/* 80102488 38600009 */  li       r3, 9;
/* 8010248C 38800000 */  li       r4, 0;
/* 80102490 38A00000 */  li       r5, 0;
/* 80102494 4BFDFABD */  bl       UNDEF_800e1f50;
/* 80102498 48000100 */  b        UNDEF_80102598;
UNDEF_8010249c:;
/* 8010249C 2C1D0000 */  cmpwi    r29, 0;
/* 801024A0 4182000C */  beq-     UNDEF_801024ac;
/* 801024A4 7FA3EB78 */  mr       r3, r29;
/* 801024A8 4BFCC7C9 */  bl       UNDEF_800cec70;
UNDEF_801024ac:;
/* 801024AC 386002C7 */  li       r3, 711;
/* 801024B0 38800000 */  li       r4, 0;
/* 801024B4 38A00000 */  li       r5, 0;
/* 801024B8 4BFDFA99 */  bl       UNDEF_800e1f50;
/* 801024BC 480000DC */  b        UNDEF_80102598;
UNDEF_801024c0:;
/* 801024C0 3C608031 */  lis      r3, UNDEF_80315e90@ha;
/* 801024C4 38635E90 */  addi     r3, r3, UNDEF_80315e90@l;
/* 801024C8 80030008 */  lwz      r0, 8(r3);
/* 801024CC 2C000004 */  cmpwi    r0, 4;
/* 801024D0 40820014 */  bne-     UNDEF_801024e4;
/* 801024D4 38000002 */  li       r0, 2;
/* 801024D8 900D999C */  stw      r0, -26212(r13);
/* 801024DC 4BFFF4F5 */  bl       UNDEF_801019d0;
/* 801024E0 480000B8 */  b        UNDEF_80102598;
UNDEF_801024e4:;
/* 801024E4 2C040001 */  cmpwi    r4, 1;
/* 801024E8 936D999C */  stw      r27, -26212(r13);
                         lis      r4, m_instance__10dScStage_c@ha;
                         lwz      r4, m_instance__10dScStage_c@l(r4);
/* 801024F0 8864120C */  lbz      r3, 4620(r4);
/* 801024F4 8804120D */  lbz      r0, 4621(r4);
/* 801024F8 40820030 */  bne-     UNDEF_80102528;
/* 801024FC 2C1B0001 */  cmpwi    r27, 1;
/* 80102500 40820028 */  bne-     UNDEF_80102528;
/* 80102504 28030007 */  cmplwi   r3, 7;
/* 80102508 40820020 */  bne-     UNDEF_80102528;
/* 8010250C 28000017 */  cmplwi   r0, 23;
/* 80102510 40820018 */  bne-     UNDEF_80102528;
/* 80102514 38600008 */  li       r3, 8;
/* 80102518 38800002 */  li       r4, 2;
/* 8010251C 38A00000 */  li       r5, 0;
/* 80102520 4BFDFA31 */  bl       UNDEF_800e1f50;
/* 80102524 48000074 */  b        UNDEF_80102598;
UNDEF_80102528:;
/* 80102528 281D0003 */  cmplwi   r29, 3;
/* 8010252C 4082005C */  bne-     UNDEF_80102588;
/* 80102530 28000023 */  cmplwi   r0, 35;
/* 80102534 40820044 */  bne-     UNDEF_80102578;
/* 80102538 2C1B0000 */  cmpwi    r27, 0;
/* 8010253C 4082003C */  bne-     UNDEF_80102578;
/* 80102540 3C80802F */  lis      r4, UNDEF_802f4cf0@ha;
/* 80102544 546015BA */  clrlslwi r0, r3, 24, 2              ;
/* 80102548 38844CF0 */  addi     r4, r4, UNDEF_802f4cf0@l;
/* 8010254C 7C84002E */  lwzx     r4, r4, r0;
/* 80102550 2C04000A */  cmpwi    r4, 10;
/* 80102554 41820024 */  beq-     UNDEF_80102578;
/* 80102558 80ADA8DC */  lwz      r5, -22308(r13);
/* 8010255C 38000003 */  li       r0, 3;
/* 80102560 5483063E */  clrlwi   r3, r4, 24                ;
/* 80102564 38800000 */  li       r4, 0;
/* 80102568 90050370 */  stw      r0, 880(r5);
/* 8010256C 38A00000 */  li       r5, 0;
/* 80102570 48000231 */  bl       UNDEF_801027a0;
/* 80102574 48000024 */  b        UNDEF_80102598;
UNDEF_80102578:;
/* 80102578 888DABAE */  lbz      r4, -21586(r13);
/* 8010257C 38A00000 */  li       r5, 0;
/* 80102580 48000221 */  bl       UNDEF_801027a0;
/* 80102584 48000014 */  b        UNDEF_80102598;
UNDEF_80102588:;
/* 80102588 7FA3EB78 */  mr       r3, r29;
/* 8010258C 7F84E378 */  mr       r4, r28;
/* 80102590 38A00000 */  li       r5, 0;
/* 80102594 4BFDF9BD */  bl       UNDEF_800e1f50;
UNDEF_80102598:;
/* 80102598 39610020 */  addi     r11, r1, 32;
/* 8010259C 481DAB15 */  bl       UNDEF_802dd0b0;
/* 801025A0 80010024 */  lwz      r0, 36(r1);
/* 801025A4 7C0803A6 */  mtlr     r0;
/* 801025A8 38210020 */  addi     r1, r1, 32;
/* 801025AC 4E800020 */  blr      ;
  // clang-format on
);

PATCH_REFERENCES(
  &dScStage_c::m_replayPlay_p, //
  {
    {0x8006A18A, R_PPC_ADDR16_HA}, {0x8006A18E, R_PPC_ADDR16_LO}, {0x800B5CBA, R_PPC_ADDR16_HA},
    {0x800B5CC2, R_PPC_ADDR16_LO}, {0x800B61FA, R_PPC_ADDR16_HA}, {0x800B6202, R_PPC_ADDR16_LO},
    {0x800B62A6, R_PPC_ADDR16_HA}, {0x800B62AA, R_PPC_ADDR16_LO}, {0x80102142, R_PPC_ADDR16_HA},
    {0x8010214A, R_PPC_ADDR16_LO}, {0x80102182, R_PPC_ADDR16_HA}, {0x80102186, R_PPC_ADDR16_LO},
    {0x8010226A, R_PPC_ADDR16_HA}, {0x8010226E, R_PPC_ADDR16_LO}, {0x801022C2, R_PPC_ADDR16_HA},
    {0x801022C6, R_PPC_ADDR16_LO}, {0x8091F6FE, R_PPC_ADDR16_HA}, {0x8091F706, R_PPC_ADDR16_LO},
    {0x8091F79A, R_PPC_ADDR16_HA}, {0x8091F7B6, R_PPC_ADDR16_LO}, {0x809246AE, R_PPC_ADDR16_HA},
    {0x809246B6, R_PPC_ADDR16_LO},
  }
);
