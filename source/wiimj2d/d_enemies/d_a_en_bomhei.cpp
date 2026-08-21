// d_a_en_bomhei.cpp
// NSMBW d_enemies.text: 0x809C8D30 - 0x809CDE70

#include "d_a_en_bomhei.h"

#include "d_static/d_a_player/d_a_player_manager.h"

[[nsmbw(0x809C9DD0)]]
void UNDEF_809C9DD0() ASM_METHOD(
  // clang-format off
/* 809C9DD0 9421FFC0 */  stwu     r1, -64(r1);
/* 809C9DD4 7C0802A6 */  mflr     r0;
/* 809C9DD8 90010044 */  stw      r0, 68(r1);
/* 809C9DDC 39610040 */  addi     r11, r1, 64;
/* 809C9DE0 4B91327D */  bl       UNDEF_802dd05c;
/* 809C9DE4 3CC080AD */  lis      r6, UNDEF_80ace5dc@ha;
/* 809C9DE8 3FE080B1 */  lis      r31, UNDEF_80b12a38@ha;
/* 809C9DEC C0240058 */  lfs      f1, 88(r4);
/* 809C9DF0 7C7C1B78 */  mr       r28, r3;
/* 809C9DF4 C006E5DC */  lfs      f0, UNDEF_80ace5dc@l(r6);
/* 809C9DF8 7C9D2378 */  mr       r29, r4;
/* 809C9DFC 83450004 */  lwz      r26, 4(r5);
/* 809C9E00 7CBE2B78 */  mr       r30, r5;
/* 809C9E04 FC010040 */  fcmpo    cr0, f1, f0;
/* 809C9E08 3BFF2A38 */  addi     r31, r31, UNDEF_80b12a38@l;
/* 809C9E0C 4C411382 */  cror     2, 1, 2;
/* 809C9E10 7C000026 */  mfcr     r0;
/* 809C9E14 819A0060 */  lwz      r12, 96(r26);
/* 809C9E18 54001FFE */  extrwi   r0, r0, 1, 2;
/* 809C9E1C 7F43D378 */  mr       r3, r26;
/* 809C9E20 7C000034 */  cntlzw   r0, r0;
/* 809C9E24 818C006C */  lwz      r12, 108(r12);
/* 809C9E28 5419DE3E */  extrwi   r25, r0, 8, 19;
/* 809C9E2C 7D8903A6 */  mtctr    r12;
/* 809C9E30 4E800421 */  bctrl;
/* 809C9E34 8B630000 */  lbz      r27, 0(r3);
/* 809C9E38 7F83E378 */  mr       r3, r28;
/* 809C9E3C 7FA4EB78 */  mr       r4, r29;
/* 809C9E40 7FC5F378 */  mr       r5, r30;
/* 809C9E44 38C00000 */  li       r6, 0;
/* 809C9E48 4B6CC659 */  bl       UNDEF_800964a0; // Enfumi_check__5dEn_cFP5dCc_cP5dCc_ci
/* 809C9E4C 2C030000 */  cmpwi    r3, 0;
/* 809C9E50 40820140 */  bne-     UNDEF_809c9f90;
/* 809C9E54 819C0394 */  lwz      r12, 916(r28);
/* 809C9E58 387C0394 */  addi     r3, r28, 916;
/* 809C9E5C 818C0028 */  lwz      r12, 40(r12);
/* 809C9E60 7D8903A6 */  mtctr    r12;
/* 809C9E64 4E800421 */  bctrl;
/* 809C9E68 81830000 */  lwz      r12, 0(r3);
/* 809C9E6C 389F0050 */  addi     r4, r31, 80;
/* 809C9E70 818C0014 */  lwz      r12, 20(r12);
/* 809C9E74 7D8903A6 */  mtctr    r12;
/* 809C9E78 4E800421 */  bctrl;
/* 809C9E7C 7C0300D0 */  neg      r0, r3;
/* 809C9E80 7C001B78 */  or       r0, r0, r3;
/* 809C9E84 54000FFF */  srwi.    r0, r0, 31;
/* 809C9E88 40820074 */  bne-     UNDEF_809c9efc;
/* 809C9E8C 819C0394 */  lwz      r12, 916(r28);
/* 809C9E90 387C0394 */  addi     r3, r28, 916;
/* 809C9E94 818C0028 */  lwz      r12, 40(r12);
/* 809C9E98 7D8903A6 */  mtctr    r12;
/* 809C9E9C 4E800421 */  bctrl;
/* 809C9EA0 81830000 */  lwz      r12, 0(r3);
/* 809C9EA4 389F00D0 */  addi     r4, r31, 208;
/* 809C9EA8 818C0014 */  lwz      r12, 20(r12);
/* 809C9EAC 7D8903A6 */  mtctr    r12;
/* 809C9EB0 4E800421 */  bctrl;
/* 809C9EB4 7C0300D0 */  neg      r0, r3;
/* 809C9EB8 7C001B78 */  or       r0, r0, r3;
/* 809C9EBC 54000FFF */  srwi.    r0, r0, 31;
/* 809C9EC0 4082003C */  bne-     UNDEF_809c9efc;
/* 809C9EC4 819C0394 */  lwz      r12, 916(r28);
/* 809C9EC8 387C0394 */  addi     r3, r28, 916;
/* 809C9ECC 818C0028 */  lwz      r12, 40(r12);
/* 809C9ED0 7D8903A6 */  mtctr    r12;
/* 809C9ED4 4E800421 */  bctrl;
/* 809C9ED8 81830000 */  lwz      r12, 0(r3);
/* 809C9EDC 389F0110 */  addi     r4, r31, 272;
/* 809C9EE0 818C0014 */  lwz      r12, 20(r12);
/* 809C9EE4 7D8903A6 */  mtctr    r12;
/* 809C9EE8 4E800421 */  bctrl;
/* 809C9EEC 7C0300D0 */  neg      r0, r3;
/* 809C9EF0 7C001B78 */  or       r0, r0, r3;
/* 809C9EF4 54000FFF */  srwi.    r0, r0, 31;
/* 809C9EF8 41820084 */  beq-     UNDEF_809c9f7c;
UNDEF_809c9efc:;
/* 809C9EFC          */  cmplwi   r27, PLAYER_COUNT;
/* 809C9F00 408000D4 */  bge-     UNDEF_809c9fd4;

                         // Damage cooldown
                         mr       r3, r28;
                         mr       r4, r27;
                         li       r5, 32;
                         bl       setCollTimer__5dEn_cFiUc;

/* 809C9F08 9B3C0348 */  stb      r25, 840(r28);
/* 809C9F10 7F84E378 */  mr       r4, r28;
/* 809C9F14 9B7C038D */  stb      r27, 909(r28);
/* 809C9F1C 38610010 */  addi     r3, r1, 16;
/* 809C9F24 9B7C0284 */  stb      r27, 644(r28);
/* 809C9F28 4B6A2FA9 */  bl       UNDEF_8006ced0; // getCenterPos__12dBaseActor_cCFv
/* 809C9F2C 7F63DB78 */  mr       r3, r27;
/* 809C9F30 4B69F601 */  bl       UNDEF_80069530; // getRemotePlayer__6dAudioFi
/* 809C9F34 3C808043 */  lis      r4, UNDEF_8042a03c@ha;
/* 809C9F38 7C7B1B78 */  mr       r27, r3;
/* 809C9F3C 83A4A03C */  lwz      r29, UNDEF_8042a03c@l(r4);
/* 809C9F40 38610008 */  addi     r3, r1, 8;
/* 809C9F44 38810010 */  addi     r4, r1, 16;
/* 809C9F48 4B6A0569 */  bl       UNDEF_8006a4b0; // cvtSndObjctPos__6dAudioFRC7mVec3_c
/* 809C9F4C 7FA3EB78 */  mr       r3, r29;
/* 809C9F50 7F66DB78 */  mr       r6, r27;
/* 809C9F54 38A10008 */  addi     r5, r1, 8;
/* 809C9F58 38800195 */  li       r4, 405;
/* 809C9F5C 4B7CE0E5 */  bl       UNDEF_80198040; // startSound__14SndObjctCmnEmyFUlRCQ34nw4r4math4VEC2Ul
/* 809C9F60 819C0060 */  lwz      r12, 96(r28);
/* 809C9F64 7F83E378 */  mr       r3, r28;
/* 809C9F68 389F0110 */  addi     r4, r31, 272;
/* 809C9F6C 818C00D4 */  lwz      r12, 212(r12);
/* 809C9F70 7D8903A6 */  mtctr    r12;
/* 809C9F74 4E800421 */  bctrl;
/* 809C9F78 4800005C */  b        UNDEF_809c9fd4;
UNDEF_809c9f7c:;
/* 809C9F7C 7F83E378 */  mr       r3, r28;
/* 809C9F80 7FA4EB78 */  mr       r4, r29;
/* 809C9F84 7FC5F378 */  mr       r5, r30;
/* 809C9F88 4B6CBCF9 */  bl       UNDEF_80095c80; // Normal_VsYoshiHitCheck__5dEn_cFP5dCc_cP5dCc_c
/* 809C9F8C 48000048 */  b        UNDEF_809c9fd4;
UNDEF_809c9f90:;
/* 809C9F90 819C0394 */  lwz      r12, 916(r28);
/* 809C9F94 387C0394 */  addi     r3, r28, 916;
/* 809C9F98 818C0028 */  lwz      r12, 40(r12);
/* 809C9F9C 7D8903A6 */  mtctr    r12;
/* 809C9FA0 4E800421 */  bctrl;
/* 809C9FA4 81830000 */  lwz      r12, 0(r3);
/* 809C9FA8 389F01D0 */  addi     r4, r31, 464;
/* 809C9FAC 818C0014 */  lwz      r12, 20(r12);
/* 809C9FB0 7D8903A6 */  mtctr    r12;
/* 809C9FB4 4E800421 */  bctrl;
/* 809C9FB8 7C0300D0 */  neg      r0, r3;
/* 809C9FBC 7C001B78 */  or       r0, r0, r3;
/* 809C9FC0 54000FFF */  srwi.    r0, r0, 31;
/* 809C9FC4 40820010 */  bne-     UNDEF_809c9fd4;
/* 809C9FC8 7F83E378 */  mr       r3, r28;
/* 809C9FCC 7F44D378 */  mr       r4, r26;
/* 809C9FD0 4B6D6FE1 */  bl       UNDEF_800a0fb0; // setDeathInfo_YoshiFumi__5dEn_cFP8dActor_c
UNDEF_809c9fd4:;
/* 809C9FD4 39610040 */  addi     r11, r1, 64;
/* 809C9FD8 4B9130D1 */  bl       UNDEF_802dd0a8;
/* 809C9FDC 80010044 */  lwz      r0, 68(r1);
/* 809C9FE0 7C0803A6 */  mtlr     r0;
/* 809C9FE4 38210040 */  addi     r1, r1, 64;
/* 809C9FE8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x809CA8D0)]]
bool daEnBomhei_c::hitCallback_HipAttk(dCc_c* main, dCc_c* other) ASM_METHOD(
  // clang-format off
/* 809CA8D0 9421FFE0 */  stwu     r1, -32(r1);
/* 809CA8D4 7C0802A6 */  mflr     r0;
/* 809CA8D8 90010024 */  stw      r0, 36(r1);
/* 809CA8DC 93E1001C */  stw      r31, 28(r1);
/* 809CA8E0 7C7F1B78 */  mr       r31, r3;
/* 809CA8E4 93C10018 */  stw      r30, 24(r1);
/* 809CA8E8 93A10014 */  stw      r29, 20(r1);
/* 809CA8EC 83A50004 */  lwz      r29, 4(r5);
/* 809CA8F0 819D0060 */  lwz      r12, 96(r29);

/* 809CA8F4          */  mr       r4, r29;
                         bl       getCollTimer__5dEn_cCFP8dActor_c;

/* 809CA924          */  cmpwi    r3, 0;
/* 809CA928 4182000C */  beq-     UNDEF_809ca934;
/* 809CA92C 38600001 */  li       r3, 1;
/* 809CA930 480000E4 */  b        UNDEF_809caa14;
UNDEF_809ca934:;
/* 809CA934 C03F00AC */  lfs      f1, 172(r31);
/* 809CA938 C01D00AC */  lfs      f0, 172(r29);
/* 809CA93C FC010040 */  fcmpo    cr0, f1, f0;
/* 809CA940 4C411382 */  cror     2, 1, 2;
/* 809CA944 40820010 */  bne-     UNDEF_809ca954;
/* 809CA948 38000000 */  li       r0, 0;
/* 809CA94C 981F0348 */  stb      r0, 840(r31);
/* 809CA950 4800000C */  b        UNDEF_809ca95c;
UNDEF_809ca954:;
/* 809CA954 38000001 */  li       r0, 1;
/* 809CA958 981F0348 */  stb      r0, 840(r31);
UNDEF_809ca95c:;
/* 809CA95C 989F038D */  stb      r4, 909(r31);
/* 809CA960 3CA08043 */  lis      r5, UNDEF_8042a03c@ha;
/* 809CA964 38610008 */  addi     r3, r1, 8;
/* 809CA968 389F00AC */  addi     r4, r31, 172;
/* 809CA96C 83C5A03C */  lwz      r30, UNDEF_8042a03c@l(r5);
/* 809CA970 4B69FB41 */  bl       UNDEF_8006a4b0;
/* 809CA974 7FC3F378 */  mr       r3, r30;
/* 809CA978 38A10008 */  addi     r5, r1, 8;
/* 809CA97C 3880017B */  li       r4, 379;
/* 809CA980 38C00000 */  li       r6, 0;
/* 809CA984 4B7CD6BD */  bl       UNDEF_80198040;
/* 809CA988 819F0060 */  lwz      r12, 96(r31);
/* 809CA98C 7FE3FB78 */  mr       r3, r31;
/* 809CA990 389D00AC */  addi     r4, r29, 172;
/* 809CA994 818C020C */  lwz      r12, 524(r12);
/* 809CA998 7D8903A6 */  mtctr    r12;
/* 809CA99C 4E800421 */  bctrl;

                         mr       r3, r31;
/* 809CA9A0          */  lbz      r4, 909(r31);
/* 809CA9A4          */  li       r5, 16;
                         bl       setCollTimer__5dEn_cFiUc;

/* 809CA9B8 801F05EC */  lwz      r0, 1516(r31);
/* 809CA9BC 2C000000 */  cmpwi    r0, 0;
/* 809CA9C0 40800020 */  bge-     UNDEF_809ca9e0;
/* 809CA9C4 3C8080AD */  lis      r4, UNDEF_80ace5dc@ha;
/* 809CA9C8 380000F0 */  li       r0, 240;
/* 809CA9CC C024E5DC */  lfs      f1, UNDEF_80ace5dc@l(r4);
/* 809CA9D0 387F05C0 */  addi     r3, r31, 1472;
/* 809CA9D4 901F05EC */  stw      r0, 1516(r31);
/* 809CA9D8 38800000 */  li       r4, 0;
/* 809CA9DC 4B79BA55 */  bl       UNDEF_80166430;
UNDEF_809ca9e0:;
/* 809CA9E0 819F0060 */  lwz      r12, 96(r31);
/* 809CA9E4 7FE3FB78 */  mr       r3, r31;
/* 809CA9E8 818C029C */  lwz      r12, 668(r12);
/* 809CA9EC 7D8903A6 */  mtctr    r12;
/* 809CA9F0 4E800421 */  bctrl;
/* 809CA9F4 819F0060 */  lwz      r12, 96(r31);
/* 809CA9F8 3C8080B1 */  lis      r4, UNDEF_80b12b08@ha;
/* 809CA9FC 7FE3FB78 */  mr       r3, r31;
/* 809CAA00 818C00D4 */  lwz      r12, 212(r12);
/* 809CAA04 38842B08 */  addi     r4, r4, UNDEF_80b12b08@l;
/* 809CAA08 7D8903A6 */  mtctr    r12;
/* 809CAA0C 4E800421 */  bctrl;
/* 809CAA10 38600001 */  li       r3, 1;
UNDEF_809caa14:;
/* 809CAA14 80010024 */  lwz      r0, 36(r1);
/* 809CAA18 83E1001C */  lwz      r31, 28(r1);
/* 809CAA1C 83C10018 */  lwz      r30, 24(r1);
/* 809CAA20 83A10014 */  lwz      r29, 20(r1);
/* 809CAA24 7C0803A6 */  mtlr     r0;
/* 809CAA28 38210020 */  addi     r1, r1, 32;
/* 809CAA2C 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x809CBBC0)]]
void daEnBomhei_c::initializeState_Slide() ASM_METHOD(
  // clang-format off
/* 809CBBC0 9421FFE0 */  stwu     r1, -32(r1);
/* 809CBBC4 7C0802A6 */  mflr     r0;
/* 809CBBC8 3C8080AE */  lis      r4, UNDEF_80addb5c@ha;
/* 809CBBCC 90010024 */  stw      r0, 36(r1);
/* 809CBBD0 3884DB5C */  addi     r4, r4, UNDEF_80addb5c@l;
/* 809CBBD4 93E1001C */  stw      r31, 28(r1);
/* 809CBBD8 3FE080AD */  lis      r31, UNDEF_80ace508@ha;
/* 809CBBDC 3BFFE508 */  addi     r31, r31, UNDEF_80ace508@l;
/* 809CBBE0 93C10018 */  stw      r30, 24(r1);
/* 809CBBE4 7C7E1B78 */  mr       r30, r3;
/* 809CBBE8 38630544 */  addi     r3, r3, 1348;
/* 809CBBEC 4B86E605 */  bl       UNDEF_8023a1f0; // GetResAnmChr__Q34nw4r3g3d7ResFileCFPCc
/* 809CBBF0 90610008 */  stw      r3, 8(r1);
/* 809CBBF4 387E0588 */  addi     r3, r30, 1416;
/* 809CBBF8 389E0548 */  addi     r4, r30, 1352;
/* 809CBBFC 38A10008 */  addi     r5, r1, 8;
/* 809CBC00 38C00000 */  li       r6, 0;
/* 809CBC04 4B79972D */  bl       UNDEF_80165330; // setAnm__Q23m3d8anmChr_cFRQ23m3d6bmdl_cQ34nw4r3g3d9ResAnmChrQ23m3d10playMode_e
/* 809CBC08 C03F013C */  lfs      f1, 316(r31);
/* 809CBC0C 387E0548 */  addi     r3, r30, 1352;
/* 809CBC10 389E0588 */  addi     r4, r30, 1416;
/* 809CBC14 4B79E4AD */  bl       setAnm__Q23m3d5mdl_cFRQ23m3d6banm_cf;
/* 809CBC18 C03F00D0 */  lfs      f1, 208(r31);
/* 809CBC1C 387E0588 */  addi     r3, r30, 1416;
/* 809CBC20 4B79C601 */  bl       UNDEF_80168220; // setRate__Q23m3d6banm_cFf
/* 809CBC24 7FC3F378 */  mr       r3, r30;
/* 809CBC28 4B69A089 */  bl       UNDEF_80065cb0; // clrComboCnt__8dActor_cFv
/* 809CBC2C 88DE0348 */  lbz      r6, 840(r30);
/* 809CBC30 3C608043 */  lis      r3, UNDEF_8042c484@ha; // l_base_angleY

/* 809CBC38 389F01F0 */  addi     r4, r31, 496;
/* 809CBC3C 54C5103A */  slwi     r5, r6, 2;
/* 809CBC40 54C6083C */  slwi     r6, r6, 1;
/* 809CBC44 7C242C2E */  lfsx     f1, r4, r5;
/* 809CBC48 3863C484 */  addi     r3, r3, UNDEF_8042c484@l; // l_base_angleY
/* 809CBC4C 7CC332AE */  lhax     r6, r3, r6;
/* 809CBC54 C05F01C8 */  lfs      f2, 456(r31);
/* 809CBC5C C01F00D4 */  lfs      f0, 212(r31);
/* 809CBC64 D05E011C */  stfs     f2, 284(r30);
/* 809CBC6C 38000009 */  li       r0, 9;
/* 809CBC74 D03E00E8 */  stfs     f1, 232(r30);
/* 809CBC78 D01E00F4 */  stfs     f0, 244(r30);
/* 809CBC7C B0DE0102 */  sth      r6, 258(r30);
/* 809CBC84 981E0175 */  stb      r0, 373(r30);

                         mr       r3, r30;
/* 809CBC34          */  lbz      r4, 909(r30);
/* 809CBC68 38A0000A */  li       r5, 10;
                         bl       setCollTimer__5dEn_cFiUc;

/* 809CBC70 7FC3F378 */  mr       r3, r30;
/* 809CBC88 4BFFF189 */  bl       UNDEF_809cae10;
/* 809CBC8C 80010024 */  lwz      r0, 36(r1);
/* 809CBC90 83E1001C */  lwz      r31, 28(r1);
/* 809CBC94 83C10018 */  lwz      r30, 24(r1);
/* 809CBC98 7C0803A6 */  mtlr     r0;
/* 809CBC9C 38210020 */  addi     r1, r1, 32;
/* 809CBCA0 4E800020 */  blr;
  // clang-format on
);
