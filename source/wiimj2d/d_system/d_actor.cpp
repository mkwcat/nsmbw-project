// d_actor.cpp
// NSMBW .text: 0x80064110 - 0x800660C0

#include "d_actor.h"

#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"

[[nsmbw_data(0x80429FD8)]]
u8 dActor_c::mExecStopReq;

[[nsmbw_data(0x80429FDA)]]
u8 dActor_c::mExecStop;

[[nsmbw(0x80064110)]]
dActor_c::dActor_c();

[[nsmbw(0x800642B0)]]
dActor_c::~dActor_c();

[[nsmbw(0x80064350)]]
fBase_c::PACK_RESULT_e dActor_c::preCreate();

[[nsmbw(0x80064380)]]
void dActor_c::postCreate(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x80064390)]]
fBase_c::PACK_RESULT_e dActor_c::preDelete();

[[nsmbw(0x800643E0)]]
void dActor_c::postDelete(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800643F0)]]
fBase_c::PACK_RESULT_e dActor_c::preExecute();

[[nsmbw(0x80064490)]]
void dActor_c::postExecute(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x80064540)]]
fBase_c::PACK_RESULT_e dActor_c::preDraw();

[[nsmbw(0x800645E0)]]
void dActor_c::postDraw(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800645F0)]]
const char* dActor_c::getKindString() const;

[[nsmbw(0x80064600)]]
void dActor_c::setTmpCtData(u8);

[[nsmbw(0x80064610)]]
dActor_c* dActor_c::construct(
  u16 profile, u32 settings, const mVec3_c* position, const mAng3_c* rotation, u8 layer
);

[[nsmbw(0x80064680)]]
dActor_c* dActor_c::construct(
  u16 profile, dBase_c* owner, u32 settings, const mVec3_c* position, const mAng3_c* rotation,
  u8 layer
);

[[nsmbw(0x800646E0)]]
void dActor_c::setKind(u8);

[[nsmbw(0x80064720)]]
void dActor_c::setSearchNearPlayerFunc(int);

[[nsmbw(0x80064740)]]
dAcPy_c* dActor_c::searchNearPlayer(mVec2_c&);

[[nsmbw(0x80064790)]]
dAcPy_c* dActor_c::searchNearPlayer_Main(mVec2_c&, const mVec2_c&);

[[nsmbw(0x800647A0)]]
dAcPy_c* dActor_c::searchNearPlayerNormal(mVec2_c&, const mVec2_c&);

[[nsmbw(0x80064880)]]
dAcPy_c* dActor_c::searchNearPlayerLoop(mVec2_c&, const mVec2_c&);

[[nsmbw(0x80064A10)]]
void dActor_c::setGetTrgToSrcDirFunc(int);

[[nsmbw(0x80064A30)]]
bool dActor_c::getTrgToSrcDir_Main(f32, f32);

[[nsmbw(0x80064A40)]]
bool dActor_c::getTrgToSrcDirNormal(f32, f32);

[[nsmbw(0x80064A50)]]
bool dActor_c::getTrgToSrcDirLoop(f32, f32);

[[nsmbw(0x80064AF0)]]
void dActor_c::changePosAngle(mVec3_c*, mAng3_c*, int);

[[nsmbw(0x80064B00)]]
void dActor_c::setChangePosAngleFunc(int);

[[nsmbw(0x80064B10)]]
void dActor_c::setLoopFunc(int);

[[nsmbw(0x80064B50)]]
bool dActor_c::checkAreaNo();

[[nsmbw(0x80064BC0)]]
void dActor_c::setSoftLight_Player(m3d::bmdl_c&);

[[nsmbw(0x80064BD0)]]
void dActor_c::setSoftLight_Enemy(m3d::bmdl_c&);

[[nsmbw(0x80064BE0)]]
void dActor_c::setSoftLight_Map(m3d::bmdl_c&);

[[nsmbw(0x80064BF0)]]
void dActor_c::setSoftLight_MapObj(m3d::bmdl_c&);

[[nsmbw(0x80064C00)]]
void dActor_c::setSoftLight_Boss(m3d::bmdl_c&);

[[nsmbw(0x80064C10)]]
void dActor_c::setSoftLight_Item(m3d::bmdl_c& model);

[[nsmbw(0x80064D10)]]
void dActor_c::deleteActor(u8);

[[nsmbw(0x80064DA0)]]
bool dActor_c::checkOutOfArea(const mVec3_c& pos, const nw4r::ut::Rect& rect, u8 area);

[[nsmbw(0x80065080)]]
bool dActor_c::ActorDrawCullCheck();

[[nsmbw(0x80064F50)]]
void dActor_c::ActorScrOutCheck(u16);

[[nsmbw(0x800651C0)]]
void dActor_c::carryFukidashiCheck(int param1, mVec2_c param2) ASM_METHOD(
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
/* 80065244          */  cmplwi   r0, PLAYER_COUNT - 1;
/* 80065248 41810028 */  bgt-     UNDEF_80065270;
                         cmpwi    r0, 4;
/* 8006524C 1C000016 */  mulli    r0, r0, 22;
/* 80065250 806DA8DC */  lwz      r3, UNDEF_8042a25c@sda21;
/* 80065254 7C030214 */  add      r0, r3, r0;
/* 80065258 7C60E214 */  add      r3, r0, r28;

                         blt      L_dActor_c_carryFukidashiCheck_SkipAFEAdjust;
                         addi     r3, r3, ADJUST_dInfo_c_mEx0xAFE;
L_dActor_c_carryFukidashiCheck_SkipAFEAdjust:;
/* 8006525C 88030AFE */  lbz      r0, 0xAFE(r3);

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
/* 800652CC C0428AC0 */  lfs      f2, UNDEF_8042be20@sda21;
/* 800652D0 EC640028 */  fsubs    f3, f4, f0;
/* 800652D4 D3C10054 */  stfs     f30, 84(r1);
/* 800652D8 EC04002A */  fadds    f0, f4, f0;
/* 800652DC 808DAC80 */  lwz      r4, UNDEF_8042a600@sda21;
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
/* 80065330 C0228AAC */  lfs      f1, UNDEF_8042be0c@sda21;
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
/* 800653E4 C0228AAC */  lfs      f1, UNDEF_8042be0c@sda21;
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

[[nsmbw(0x80065480)]]
void dActor_c::carryFukidashiCancel(int param1, int param2) ASM_METHOD(
  // clang-format off
/* 80065480 9421FFE0 */  stwu     r1, -32(r1);
/* 80065484 7C0802A6 */  mflr     r0;
/* 80065488 90010024 */  stw      r0, 36(r1);
/* 8006548C 93E1001C */  stw      r31, 28(r1);
/* 80065490 3BE00000 */  li       r31, 0;
/* 80065494 93C10018 */  stw      r30, 24(r1);
/* 80065498 7CBE2B78 */  mr       r30, r5;
/* 8006549C 93A10014 */  stw      r29, 20(r1);
/* 800654A0 7C9D2378 */  mr       r29, r4;
/* 800654A4 93810010 */  stw      r28, 16(r1);
/* 800654A8 7C7C1B78 */  mr       r28, r3;
UNDEF_800654ac:;
/* 800654AC 7C1FF000 */  cmpw     r31, r30;
/* 800654B0 40820024 */  bne-     UNDEF_800654d4;
/* 800654B4 7FE3FB78 */  mr       r3, r31;
/* 800654B8 7FA4EB78 */  mr       r4, r29;
/* 800654BC 38A00000 */  li       r5, 0;
/* 800654C0 4804E261 */  bl       UNDEF_800b3720;
/* 800654C4 7FE3FB78 */  mr       r3, r31;
/* 800654C8 7FA4EB78 */  mr       r4, r29;
/* 800654CC 4804E2B5 */  bl       UNDEF_800b3780;
/* 800654D0 48000014 */  b        UNDEF_800654e4;
UNDEF_800654d4:;
/* 800654D4 7FE3FB78 */  mr       r3, r31;
/* 800654D8 7FA4EB78 */  mr       r4, r29;
/* 800654DC 38A00000 */  li       r5, 0;
/* 800654E0 4804E271 */  bl       UNDEF_800b3750;
UNDEF_800654e4:;
/* 800654E4 3BFF0001 */  addi     r31, r31, 1;
/* 800654E8          */  cmpwi    r31, PLAYER_COUNT;
/* 800654EC 4180FFC0 */  blt+     UNDEF_800654ac;
/* 800654F0 3800FFFF */  li       r0, -1;
/* 800654F4 901C0128 */  stw      r0, 296(r28);
/* 800654F8 83E1001C */  lwz      r31, 28(r1);
/* 800654FC 83C10018 */  lwz      r30, 24(r1);
/* 80065500 83A10014 */  lwz      r29, 20(r1);
/* 80065504 83810010 */  lwz      r28, 16(r1);
/* 80065508 80010024 */  lwz      r0, 36(r1);
/* 8006550C 7C0803A6 */  mtlr     r0;
/* 80065510 38210020 */  addi     r1, r1, 32;
/* 80065514 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80065520)]]
dAcPy_c* dActor_c::searchCarryFukidashiPlayer(int param1) ASM_METHOD(
  // clang-format off
/* 80065520 9421FFC0 */  stwu     r1, -64(r1);
/* 80065524 7C0802A6 */  mflr     r0;
/* 80065528 90010044 */  stw      r0, 68(r1);
/* 8006552C 39610030 */  addi     r11, r1, 48;
/* 80065530 DBE10030 */  stfd     f31, 48(r1);
/* 80065534 F3E10038 */  .long    0xF3E10038; // psq_st   f31, 56(r1), 0, 0;
/* 80065538 48277B2D */  bl       UNDEF_802dd064;
/* 8006553C 7C9B2378 */  mr       r27, r4;
/* 80065540 7C641B78 */  mr       r4, r3;
/* 80065544 38610008 */  addi     r3, r1, 8;
/* 80065548 48007989 */  bl       UNDEF_8006ced0;
/* 8006554C C3E28AB8 */  lfs      f31, UNDEF_8042be18@sda21;
/* 80065550 3BA00000 */  li       r29, 0;
/* 80065554 3B800000 */  li       r28, 0;
/* 80065558 3BC00000 */  li       r30, 0;
/* 8006555C 3BE00001 */  li       r31, 1;
UNDEF_80065560:;
/* 80065560 5780063E */  clrlwi   r0, r28, 24;
/* 80065564 886DA608 */  lbz      r3, UNDEF_80429f88@sda21;
/* 80065568 7FE00030 */  slw      r0, r31, r0;
/* 8006556C 7C600039 */  and.     r0, r3, r0;
/* 80065570 41820070 */  beq-     UNDEF_800655e0;
/* 80065574 806DA8DC */  lwz      r3, UNDEF_8042a25c@sda21;
/* 80065578 7C1EDA14 */  add      r0, r30, r27;
/* 8006557C 7C630214 */  add      r3, r3, r0;
/* 80065580 88030AFE */  lbz      r0, 2814(r3);
/* 80065584 2C000000 */  cmpwi    r0, 0;
/* 80065588 40820058 */  bne-     UNDEF_800655e0;
/* 8006558C 7F83E378 */  mr       r3, r28;
/* 80065590 4BFFA371 */  bl       UNDEF_8005f900;
/* 80065594 2C030000 */  cmpwi    r3, 0;
/* 80065598 41820048 */  beq-     UNDEF_800655e0;
/* 8006559C C06300AC */  lfs      f3, 172(r3);
/* 800655A0 C04300D0 */  lfs      f2, 208(r3);
/* 800655A4 C02300B0 */  lfs      f1, 176(r3);
/* 800655A8 C00300D4 */  lfs      f0, 212(r3);
/* 800655AC EC63102A */  fadds    f3, f3, f2;
/* 800655B0 C0410008 */  lfs      f2, 8(r1);
/* 800655B4 EC21002A */  fadds    f1, f1, f0;
/* 800655B8 C001000C */  lfs      f0, 12(r1);
/* 800655BC EC431028 */  fsubs    f2, f3, f2;
/* 800655C0 EC010028 */  fsubs    f0, f1, f0;
/* 800655C4 EC2200B2 */  fmuls    f1, f2, f2;
/* 800655C8 EC000032 */  fmuls    f0, f0, f0;
/* 800655CC EC01002A */  fadds    f0, f1, f0;
/* 800655D0 FC1F0040 */  fcmpo    cr0, f31, f0;
/* 800655D4 4081000C */  ble-     UNDEF_800655e0;
/* 800655D8 7C7D1B78 */  mr       r29, r3;
/* 800655DC FFE00090 */  fmr      f31, f0;
UNDEF_800655e0:;
/* 800655E0 3B9C0001 */  addi     r28, r28, 1;
/* 800655E4 3BDE0016 */  addi     r30, r30, 22;

                         cmpwi    r28, 4;
                         blt-     L_dActor_c_searchCarryFukidashiPlayer_SkipAFEAdjust;
                         addi     r30, r30, ADJUST_dInfo_c_mEx0xAFE;
L_dActor_c_searchCarryFukidashiPlayer_SkipAFEAdjust:;

/* 800655E8          */  cmpwi    r28, PLAYER_COUNT;
/* 800655EC 4180FF74 */  blt+     UNDEF_80065560;
/* 800655F0 E3E10038 */  .long    0xE3E10038; // psq_l    f31, 56(r1), 0, 0;
/* 800655F4 7FA3EB78 */  mr       r3, r29;
/* 800655F8 CBE10030 */  lfd      f31, 48(r1);
/* 800655FC 39610030 */  addi     r11, r1, 48;
/* 80065600 48277AB1 */  bl       UNDEF_802dd0b0;
/* 80065604 80010044 */  lwz      r0, 68(r1);
/* 80065608 7C0803A6 */  mtlr     r0;
/* 8006560C 38210040 */  addi     r1, r1, 64;
/* 80065610 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80065620)]]
mVec3_c dActor_c::getLookatPos() const;

[[nsmbw(0x80065650)]]
void dActor_c::block_hit_init();

[[nsmbw(0x80065660)]]
bool dActor_c::allEnemyDeathEffSet();

[[nsmbw(0x80065820)]]
void dActor_c::setSpinLiftUpActor(dActor_c* actor);

[[nsmbw(0x80065830)]]
void dActor_c::setEatTongue(dActor_c* actor);

[[nsmbw(0x80065850)]]
void dActor_c::setEatTongueOff(dActor_c* actor);

[[nsmbw(0x80065860)]]
void dActor_c::setEatMouth(dActor_c* actor);

[[nsmbw(0x80065870)]]
bool dActor_c::setEatSpitOut(dActor_c* actor);

[[nsmbw(0x80065880)]]
bool dActor_c::setEatGlupDown(dActor_c* actor);

[[nsmbw(0x80065950)]]
void dActor_c::setAfterEatScale();

[[nsmbw(0x80065970)]]
void dActor_c::calcSpitOutPos(dActor_c* actor);

[[nsmbw(0x80065A00)]]
float dActor_c::calcEatScaleRate(dActor_c* yoshi);

[[nsmbw(0x80065A40)]]
void dActor_c::calcEatInScale(dActor_c* yoshi);

[[nsmbw(0x80065AC0)]]
void dActor_c::eatMove(dActor_c* actor);

[[nsmbw(0x80065B40)]]
void dActor_c::VT_0xB4();

[[nsmbw(0x80065B50)]]
void dActor_c::cancelFunsuiActUpper();

[[nsmbw(0x80065B60)]]
void dActor_c::cancelFunsuiActSide();

[[nsmbw(0x80065B70)]]
void dActor_c::cancelFunsuiActVanish();

[[nsmbw(0x80065CC0)]]
void dActor_c::waterSplashEffect(const mVec3_c& position, float scale);

[[nsmbw(0x80065DC0)]]
void dActor_c::yoganSplashEffect(const mVec3_c& position, float scale);

[[nsmbw(0x80065EC0)]]
void dActor_c::poisonSplashEffect(const mVec3_c& position, float scale);

[[nsmbw(0x80066080)]]
void dActor_c::removeCc();

[[nsmbw(0x80066090)]]
void dActor_c::reviveCc();


const u8 l_Ami_Line[] = { 1, 2 };
