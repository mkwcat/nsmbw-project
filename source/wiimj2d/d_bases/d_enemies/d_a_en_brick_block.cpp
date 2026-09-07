// d_a_en_brick_block.cpp
// NSMBW d_enemies.text: 0x809D0090 - 0x809D0450

#include "d_a_en_brick_block.h"

[[nsmbw(0x809D0120)]]
fBase_c::PACK_RESULT_e daEnBrickBlock_c::create() ASM_METHOD(
/* 809D0120 9421FFE0 */  stwu     r1, -32(r1);
/* 809D0124 7C0802A6 */  mflr     r0;
/* 809D0128 90010024 */  stw      r0, 36(r1);
/* 809D012C 39610020 */  addi     r11, r1, 32;
/* 809D0130 4B90CF35 */  bl       UNDEF_802dd064;
/* 809D0134 3F6080AD */  lis      r27, UNDEF_80ace888@ha;
/* 809D0138 83E30004 */  lwz      r31, 4(r3);
/* 809D013C 3B7BE888 */  addi     r27, r27, UNDEF_80ace888@l;
/* 809D0140 C06300AC */  lfs      f3, 172(r3);
/* 809D0144 C05B0018 */  lfs      f2, 24(r27);
/* 809D0148          */  extrwi.  r0, r31, 1, 2; // isSolid
/* 809D014C C02300B0 */  lfs      f1, 176(r3);
/* 809D0150 57FEE7BE */  extrwi   r30, r31, 2, 26;
/* 809D0154 C01B001C */  lfs      f0, 28(r27);
/* 809D0158 EC43102A */  fadds    f2, f3, f2;
/* 809D015C 57E047BE */  extrwi   r0, r31, 2, 6;
/* 809D0160 9BC306C6 */  stb      r30, 1734(r3);
/* 809D0164 EC010028 */  fsubs    f0, f1, f0;
/* 809D0168 7C7C1B78 */  mr       r28, r3;
/* 809D016C 98030666 */  stb      r0, 1638(r3);
/* 809D0170 D04300AC */  stfs     f2, 172(r3);
/* 809D0174 D00300B0 */  stfs     f0, 176(r3);
/* 809D0178 40820020 */  bne-     UNDEF_809d0198;
/* 809D017C 7F84E378 */  mr       r4, r28;
/* 809D0180 38DB0000 */  addi     r6, r27, 0;
/* 809D0184 38A00000 */  li       r5, 0;
/* 809D0188 38E00000 */  li       r7, 0;
/* 809D018C 386301EC */  addi     r3, r3, 492;
/* 809D0190 4B69CF01 */  bl       UNDEF_8006d090;
/* 809D0194 4800001C */  b        UNDEF_809d01b0;
UNDEF_809d0198:;
/* 809D0198 7F84E378 */  mr       r4, r28;
/* 809D019C 38DB000C */  addi     r6, r27, 12;
/* 809D01A0 38A00000 */  li       r5, 0;
/* 809D01A4 38E00000 */  li       r7, 0;
/* 809D01A8 386301EC */  addi     r3, r3, 492;
/* 809D01AC 4B69CEE5 */  bl       UNDEF_8006d090;
UNDEF_809d01b0:;
/* 809D01B0 57E0A73F */  extrwi.  r0, r31, 4, 16;
/* 809D01B4          */  extrwi   r29, r31, 4, 12; // Player ID
/* 809D01B8 39600000 */  li       r11, 0;
/* 809D01BC 9BBC038D */  stb      r29, 909(r28);
/* 809D01C0 38000001 */  li       r0, 1;
/* 809D01C4 9BBC0284 */  stb      r29, 644(r28);
/* 809D01C8 B17C06C4 */  sth      r11, 1732(r28);
/* 809D01CC 901C0134 */  stw      r0, 308(r28);
/* 809D01D0 408200DC */  bne-     UNDEF_809d02ac;
/* 809D01D4 881C06C6 */  lbz      r0, 1734(r28);
/* 809D01D8 C09B0020 */  lfs      f4, 32(r27);
/* 809D01DC 28000003 */  cmplwi   r0, 3;
/* 809D01E0 D09C00DC */  stfs     f4, 220(r28);
/* 809D01E4 D09C00E0 */  stfs     f4, 224(r28);
/* 809D01E8 D09C00E4 */  stfs     f4, 228(r28);
/* 809D01EC 418200C0 */  beq-     UNDEF_809d02ac;
/* 809D01F0 C07B0024 */  lfs      f3, 36(r27);
/* 809D01F4 3D408002 */  lis      r10, UNDEF_80020bf0@ha; // callBackF__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D01F8 C05B001C */  lfs      f2, 28(r27);
/* 809D01FC 3D208002 */  lis      r9, UNDEF_80020e70@ha; // callBackH__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0200 C03B0018 */  lfs      f1, 24(r27);
/* 809D0204 394A0BF0 */  addi     r10, r10, UNDEF_80020bf0@l; // callBackF__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0208 C01B0028 */  lfs      f0, 40(r27);
/* 809D020C 39290E70 */  addi     r9, r9, UNDEF_80020e70@l; // callBackH__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0210 D09C06B4 */  stfs     f4, 1716(r28);
/* 809D0214 7F84E378 */  mr       r4, r28;
/* 809D0218 88FC038F */  lbz      r7, 911(r28);
/* 809D021C 387C0534 */  addi     r3, r28, 1332;
/* 809D0220 D09C06B8 */  stfs     f4, 1720(r28);
/* 809D0224 38BC0698 */  addi     r5, r28, 1688;
/* 809D0228 391C06B4 */  addi     r8, r28, 1716;
/* 809D022C 38C00003 */  li       r6, 3;
/* 809D0230 D09C06BC */  stfs     f4, 1724(r28);
/* 809D0234 D07C0698 */  stfs     f3, 1688(r28);
/* 809D0238 D05C069C */  stfs     f2, 1692(r28);
/* 809D023C D03C06A0 */  stfs     f1, 1696(r28);
/* 809D0240 D01C06A4 */  stfs     f0, 1700(r28);
/* 809D0244 915C06A8 */  stw      r10, 1704(r28);
/* 809D0248 913C06AC */  stw      r9, 1708(r28);
/* 809D024C 917C06B0 */  stw      r11, 1712(r28);
/* 809D0250 4B6AF8C1 */  bl       UNDEF_8007fb10; // set__9dBg_ctr_cFP8dActor_cPC10sBgSetInfoUcUcP7mVec3_c
/* 809D0254 38000003 */  li       r0, 3;
/* 809D0258 901C0600 */  stw      r0, 1536(r28);
/* 809D025C 7FA3EB78 */  mr       r3, r29;
/* 809D0260 4B68F931 */  bl       getCtrlPlayer__9daPyMng_cFi;
/* 809D0264 2C030000 */  cmpwi    r3, 0;
/* 809D0268 41820008 */  beq-     UNDEF_809d0270;
/* 809D026C 907C056C */  stw      r3, 1388(r28);
UNDEF_809d0270:;
/* 809D0270 3CC08002 */  lis      r6, UNDEF_80021180@ha; // checkRevFoot__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0274 3CA08002 */  lis      r5, UNDEF_80021170@ha; // checkRevHead__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0278 3C808002 */  lis      r4, UNDEF_800211a0@ha; // checkRevWall__15daEnBlockMain_cFP8dActor_cP8dActor_cUc
/* 809D027C 387C0534 */  addi     r3, r28, 1332;
/* 809D0280 38C61180 */  addi     r6, r6, UNDEF_80021180@l; // checkRevFoot__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0284 38A51170 */  addi     r5, r5, UNDEF_80021170@l; // checkRevHead__15daEnBlockMain_cFP8dActor_cP8dActor_c
/* 809D0288 388411A0 */  addi     r4, r4, UNDEF_800211a0@l; // checkRevWall__15daEnBlockMain_cFP8dActor_cP8dActor_cUc
/* 809D028C 90DC0580 */  stw      r6, 1408(r28);
/* 809D0290 90BC0584 */  stw      r5, 1412(r28);
/* 809D0294 909C0588 */  stw      r4, 1416(r28);
/* 809D0298 4B6AF669 */  bl       UNDEF_8007f900; // entry__9dBg_ctr_cFv
/* 809D029C C01B0020 */  lfs      f0, 32(r27);
/* 809D02A0 38000001 */  li       r0, 1;
/* 809D02A4 D01C00EC */  stfs     f0, 236(r28);
/* 809D02A8 B01C06C4 */  sth      r0, 1732(r28);
UNDEF_809d02ac:;
/* 809D02AC C03C00B0 */  lfs      f1, 176(r28);
/* 809D02B0 7F83E378 */  mr       r3, r28;
/* 809D02B4 4B6513DD */  bl       UNDEF_80021690; // Block_CreateClearSet__15daEnBlockMain_cFf
/* 809D02B8 38000004 */  li       r0, 4;
/* 809D02BC 38A00001 */  li       r5, 1;
/* 809D02C0 B01C06C0 */  sth      r0, 1728(r28);
/* 809D02C4 3C608043 */  lis      r3, UNDEF_8042a1c8@ha; // m_instance__14dEffActorMng_c
/* 809D02C8 57E0A52E */  rlwinm   r0, r31, 20, 20, 23;
/* 809D02CC 389C00AC */  addi     r4, r28, 172;
/* 809D02D0 98BC067F */  stb      r5, 1663(r28);
/* 809D02D4 7FC50378 */  or       r5, r30, r0;
/* 809D02D8 7FA60774 */  extsb    r6, r29;
/* 809D02DC 8063A1C8 */  lwz      r3, UNDEF_8042a1c8@l(r3); // m_instance__14dEffActorMng_c
/* 809D02E0 4B6C2311 */  bl       UNDEF_800925f0; // createBlockFragEff__14dEffActorMng_cFR7mVec3_cUlSc
/* 809D02E4 39610020 */  addi     r11, r1, 32;
/* 809D02E8 38600001 */  li       r3, 1;
/* 809D02EC 4B90CDC5 */  bl       UNDEF_802dd0b0;
/* 809D02F0 80010024 */  lwz      r0, 36(r1);
/* 809D02F4 7C0803A6 */  mtlr     r0;
/* 809D02F8 38210020 */  addi     r1, r1, 32;
/* 809D02FC 4E800020 */  blr;
)
