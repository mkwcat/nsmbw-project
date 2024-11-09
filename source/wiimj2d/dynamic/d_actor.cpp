// d_actor.cpp
// NSMBW: 0x80064110 - 0x800660C0

#include "d_actor.h"

#include <dynamic/actor/d_a_player_manager.h>

[[address_data(0x80429FD8)]]
u8 dActor_c::mExecStopReq;

[[address(0x800651C0)]]
void FUN_800651C0() ASM_METHOD(
    // clang-format off
/* 800651C0 9421FF30 */  stwu     r1, -208(r1);
/* 800651C4 7C0802A6 */  mflr     r0;
/* 800651C8 900100D4 */  stw      r0, 212(r1);
/* 800651CC DBE100C0 */  stfd     f31, 192(r1);
/* 800651D0 F3E100C8 */  .long    0xF3E100C8; // psq_st   f31, 200(r1), 0, 0;
/* 800651D4 DBC100B0 */  stfd     f30, 176(r1);
/* 800651D8 F3C100B8 */  .long    0xF3C100B8; // psq_st   f30, 184(r1), 0, 0;
/* 800651DC 93E100AC */  stw      r31, 172(r1);
/* 800651E0 7C7F1B78 */  mr       r31, r3;
/* 800651E4 38610090 */  addi     r3, r1, 144;
/* 800651E8 93C100A8 */  stw      r30, 168(r1);
/* 800651EC 93A100A4 */  stw      r29, 164(r1);
/* 800651F0 7CBD2B78 */  mr       r29, r5;
/* 800651F4 938100A0 */  stw      r28, 160(r1);
/* 800651F8 7C9C2378 */  mr       r28, r4;
/* 800651FC 7FE4FB78 */  mr       r4, r31;
/* 80065200 48007CD1 */  bl       UNDEF_8006ced0; // getCenterPos__12dBaseActor_cCFv
/* 80065204 C0610094 */  lfs      f3, 148(r1);
/* 80065208 C05D0004 */  lfs      f2, 4(r29);
/* 8006520C C0210090 */  lfs      f1, 144(r1);
/* 80065210 EC831028 */  fsubs    f4, f3, f2;
/* 80065214 C01D0000 */  lfs      f0, 0(r29);
/* 80065218 C0BF00B4 */  lfs      f5, 180(r31);
/* 8006521C EC63102A */  fadds    f3, f3, f2;
/* 80065220 EC410028 */  fsubs    f2, f1, f0;
/* 80065224 D0A1008C */  stfs     f5, 140(r1);
/* 80065228 EC01002A */  fadds    f0, f1, f0;
/* 8006522C D0410084 */  stfs     f2, 132(r1);
/* 80065230 D0810088 */  stfs     f4, 136(r1);
/* 80065234 D0010078 */  stfs     f0, 120(r1);
/* 80065238 D061007C */  stfs     f3, 124(r1);
/* 8006523C D0A10080 */  stfs     f5, 128(r1);
/* 80065240 801F0128 */  lwz      r0, 296(r31);
/* 80065244 28000003 */  cmplwi   r0, 3;
/* 80065248 41810028 */  bgt-     UNDEF_80065270;
/* 8006524C 1C000016 */  mulli    r0, r0, 22;
/* 80065250 806DA8DC */  lwz      r3, -22308(r13);
/* 80065254 7C030214 */  add      r0, r3, r0;
/* 80065258 7C60E214 */  add      r3, r0, r28;
/* 8006525C 88030AFE */  lbz      r0, 2814(r3);
/* 80065260 2C000000 */  cmpwi    r0, 0;
/* 80065264 4182000C */  beq-     UNDEF_80065270;
/* 80065268 3800FFFF */  li       r0, -1;
/* 8006526C 901F0128 */  stw      r0, 296(r31);
UNDEF_80065270:;
/* 80065270 807F0128 */  lwz      r3, 296(r31);
/* 80065274          */  cmplwi   r3, PLAYER_COUNT - 1;
/* 80065278 418100FC */  bgt-     UNDEF_80065374;
/* 8006527C 4BFFA685 */  bl       getPlayer__9daPyMng_cFi;
/* 80065280 2C030000 */  cmpwi    r3, 0;
/* 80065284 7C7D1B78 */  mr       r29, r3;
/* 80065288 418201C0 */  beq-     UNDEF_80065448;
/* 8006528C 480E2A15 */  bl       UNDEF_80147ca0;
/* 80065290 7C7E1B78 */  mr       r30, r3;
/* 80065294 7FA3EB78 */  mr       r3, r29;
/* 80065298 38810068 */  addi     r4, r1, 104;
/* 8006529C 480DCE15 */  bl       UNDEF_801420b0;
/* 800652A0 C061006C */  lfs      f3, 108(r1);
/* 800652A4 C05D00B0 */  lfs      f2, 176(r29);
/* 800652A8 C0210068 */  lfs      f1, 104(r1);
/* 800652AC C01D00AC */  lfs      f0, 172(r29);
/* 800652B0 EFE3102A */  fadds    f31, f3, f2;
/* 800652B4 C3DD00B4 */  lfs      f30, 180(r29);
/* 800652B8 EC21002A */  fadds    f1, f1, f0;
/* 800652BC 4809C8F5 */  bl       UNDEF_80101bb0;
/* 800652C0 FC800818 */  frsp     f4, f1;
/* 800652C4 C0010070 */  lfs      f0, 112(r1);
/* 800652C8 C0A10074 */  lfs      f5, 116(r1);
/* 800652CC C0428AC0 */  lfs      f2, -30016(r2);
/* 800652D0 EC640028 */  fsubs    f3, f4, f0;
/* 800652D4 D3C10054 */  stfs     f30, 84(r1);
/* 800652D8 EC04002A */  fadds    f0, f4, f0;
/* 800652DC 808DAC80 */  lwz      r4, -21376(r13);
/* 800652E0 EC9F2828 */  fsubs    f4, f31, f5;
/* 800652E4 D3C10048 */  stfs     f30, 72(r1);
/* 800652E8 EC631028 */  fsubs    f3, f3, f2;
/* 800652EC D0810050 */  stfs     f4, 80(r1);
/* 800652F0 EC9F282A */  fadds    f4, f31, f5;
/* 800652F4 EC02002A */  fadds    f0, f2, f0;
/* 800652F8 D061004C */  stfs     f3, 76(r1);
/* 800652FC D0010040 */  stfs     f0, 64(r1);
/* 80065300 D0810044 */  stfs     f4, 68(r1);
/* 80065304 807F0128 */  lwz      r3, 296(r31);
/* 80065308 D0210058 */  stfs     f1, 88(r1);
/* 8006530C 1C03023C */  mulli    r0, r3, 572;
/* 80065310 D3E1005C */  stfs     f31, 92(r1);
/* 80065314 7C840214 */  add      r4, r4, r0;
/* 80065318 D3C10060 */  stfs     f30, 96(r1);
/* 8006531C 88040381 */  lbz      r0, 897(r4);
/* 80065320 2C000000 */  cmpwi    r0, 0;
/* 80065324 4082000C */  bne-     UNDEF_80065330;
/* 80065328 7F84E378 */  mr       r4, r28;
/* 8006532C 4804E2D5 */  bl       UNDEF_800b3600;
UNDEF_80065330:;
/* 80065330 C0228AAC */  lfs      f1, -30036(r2);
/* 80065334 38610084 */  addi     r3, r1, 132;
/* 80065338 38810078 */  addi     r4, r1, 120;
/* 8006533C 38A1004C */  addi     r5, r1, 76;
/* 80065340 38C10040 */  addi     r6, r1, 64;
/* 80065344 4804DDBD */  bl       UNDEF_800b3100;
/* 80065348 2C1E0000 */  cmpwi    r30, 0;
/* 8006534C 4182000C */  beq-     UNDEF_80065358;
/* 80065350 2C030000 */  cmpwi    r3, 0;
/* 80065354 408200F4 */  bne-     UNDEF_80065448;
UNDEF_80065358:;
/* 80065358 807F0128 */  lwz      r3, 296(r31);
/* 8006535C 7F84E378 */  mr       r4, r28;
/* 80065360 38A00000 */  li       r5, 0;
/* 80065364 4804E3ED */  bl       UNDEF_800b3750;
/* 80065368 3800FFFF */  li       r0, -1;
/* 8006536C 901F0128 */  stw      r0, 296(r31);
/* 80065370 480000D8 */  b        UNDEF_80065448;
UNDEF_80065374:;
/* 80065374 7FE3FB78 */  mr       r3, r31;
/* 80065378 7F84E378 */  mr       r4, r28;
/* 8006537C 480001A5 */  bl       UNDEF_80065520;
/* 80065380 2C030000 */  cmpwi    r3, 0;
/* 80065384 7C7D1B78 */  mr       r29, r3;
/* 80065388 418200C0 */  beq-     UNDEF_80065448;
/* 8006538C 480E2915 */  bl       UNDEF_80147ca0;
/* 80065390 7C7E1B78 */  mr       r30, r3;
/* 80065394 7FA3EB78 */  mr       r3, r29;
/* 80065398 38810030 */  addi     r4, r1, 48;
/* 8006539C 480DCD15 */  bl       UNDEF_801420b0;
/* 800653A0 C0610034 */  lfs      f3, 52(r1);
/* 800653A4 C05D00B0 */  lfs      f2, 176(r29);
/* 800653A8 C0210030 */  lfs      f1, 48(r1);
/* 800653AC C01D00AC */  lfs      f0, 172(r29);
/* 800653B0 EFC3102A */  fadds    f30, f3, f2;
/* 800653B4 C3FD00B4 */  lfs      f31, 180(r29);
/* 800653B8 EC21002A */  fadds    f1, f1, f0;
/* 800653BC 4809C7F5 */  bl       UNDEF_80101bb0;
/* 800653C0 FC400818 */  frsp     f2, f1;
/* 800653C4 C061003C */  lfs      f3, 60(r1);
/* 800653C8 C0010038 */  lfs      f0, 56(r1);
/* 800653CC 38610084 */  addi     r3, r1, 132;
/* 800653D0 ECBE1828 */  fsubs    f5, f30, f3;
/* 800653D4 D0210020 */  stfs     f1, 32(r1);
/* 800653D8 EC820028 */  fsubs    f4, f2, f0;
/* 800653DC D3C10024 */  stfs     f30, 36(r1);
/* 800653E0 EC7E182A */  fadds    f3, f30, f3;
/* 800653E4 C0228AAC */  lfs      f1, -30036(r2);
/* 800653E8 EC02002A */  fadds    f0, f2, f0;
/* 800653EC D3E10028 */  stfs     f31, 40(r1);
/* 800653F0 D0810014 */  stfs     f4, 20(r1);
/* 800653F4 38810078 */  addi     r4, r1, 120;
/* 800653F8 38A10014 */  addi     r5, r1, 20;
/* 800653FC 38C10008 */  addi     r6, r1, 8;
/* 80065400 D0A10018 */  stfs     f5, 24(r1);
/* 80065404 D3E1001C */  stfs     f31, 28(r1);
/* 80065408 D0010008 */  stfs     f0, 8(r1);
/* 8006540C D061000C */  stfs     f3, 12(r1);
/* 80065410 D3E10010 */  stfs     f31, 16(r1);
/* 80065414 4804DCED */  bl       UNDEF_800b3100;
/* 80065418 2C1E0000 */  cmpwi    r30, 0;
/* 8006541C 4182002C */  beq-     UNDEF_80065448;
/* 80065420 2C030000 */  cmpwi    r3, 0;
/* 80065424 41820024 */  beq-     UNDEF_80065448;
/* 80065428 819D0060 */  lwz      r12, 96(r29);
/* 8006542C 7FA3EB78 */  mr       r3, r29;
/* 80065430 818C006C */  lwz      r12, 108(r12);
/* 80065434 7D8903A6 */  mtctr    r12;
/* 80065438 4E800421 */  bctrl;
/* 8006543C 88030000 */  lbz      r0, 0(r3);
/* 80065440 7C000774 */  extsb    r0, r0;
/* 80065444 901F0128 */  stw      r0, 296(r31);
UNDEF_80065448:;
/* 80065448 E3E100C8 */  .long    0xE3E100C8; // psq_l    f31, 200(r1), 0, 0;
/* 8006544C 38600000 */  li       r3, 0;
/* 80065450 CBE100C0 */  lfd      f31, 192(r1);
/* 80065454 E3C100B8 */  .long    0xE3C100B8; // psq_l    f30, 184(r1), 0, 0;
/* 80065458 CBC100B0 */  lfd      f30, 176(r1);
/* 8006545C 83E100AC */  lwz      r31, 172(r1);
/* 80065460 83C100A8 */  lwz      r30, 168(r1);
/* 80065464 83A100A4 */  lwz      r29, 164(r1);
/* 80065468 838100A0 */  lwz      r28, 160(r1);
/* 8006546C 800100D4 */  lwz      r0, 212(r1);
/* 80065470 7C0803A6 */  mtlr     r0;
/* 80065474 382100D0 */  addi     r1, r1, 208;
/* 80065478 4E800020 */  blr;
    // clang-format on
);