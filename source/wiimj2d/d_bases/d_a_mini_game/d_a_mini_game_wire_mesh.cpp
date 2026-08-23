// d_a_mini_game_wire_mesh.cpp
// NSMBW d_bases.text: 0x808681B0 - 0x8086A040

#include "d_bases/d_a_mini_game_wire_mesh.h"
#include <cstring>

[[nsmbw(0x808681B0)]]
daMiniGameWireMesh_c* daMiniGameWireMesh_c_classInit()
{
    return new daMiniGameWireMesh_c();
}

daMiniGameWireMesh_c::daMiniGameWireMesh_c() ASM_METHOD(
  // clang-format off
/* 808681B0 9421FFE0 */  stwu     r1, -32(r1);
/* 808681B4 7C0802A6 */  mflr     r0;
/* 808681B8 90010024 */  stw      r0, 36(r1);
/* 808681BC 39610020 */  addi     r11, r1, 32;
/* 808681C0 4BA74EA5 */  bl       UNDEF_802dd064;
/* 808681D0 7C7C1B78 */  mr       r28, r3;
/* 808681D8 4B82CCA9 */  bl       UNDEF_80094e80; // __ct__5dEn_cFv
/* 808681DC 3C808097 */  lis      r4, UNDEF_809704f8@ha;
/* 808681E0 387C0524 */  addi     r3, r28, 1316;
/* 808681E4 388404F8 */  addi     r4, r4, UNDEF_809704f8@l;
/* 808681E8 909C0060 */  stw      r4, 96(r28);
/* 808681EC 4B800E35 */  bl       UNDEF_80069020;
/* 808681F0 3BA00000 */  li       r29, 0;
/* 808681F4 93BC0540 */  stw      r29, 1344(r28);
/* 808681F8 387C0544 */  addi     r3, r28, 1348;
/* 808681FC 4B901C15 */  bl       UNDEF_80169e10;
/* 80868200 3C608031 */  lis      r3, UNDEF_80315ef8@ha;
/* 80868204 3B7C0584 */  addi     r27, r28, 1412;
/* 80868208 38635EF8 */  addi     r3, r3, UNDEF_80315ef8@l;
/* 8086820C 907C0584 */  stw      r3, 1412(r28);
/* 80868210 387B0008 */  addi     r3, r27, 8;
/* 80868214 937B0004 */  stw      r27, 4(r27);
/* 80868218 4B800E09 */  bl       UNDEF_80069020;
/* 8086821C 93BB0024 */  stw      r29, 36(r27);
/* 80868220 387B0028 */  addi     r3, r27, 40;
/* 80868224 4B901BED */  bl       UNDEF_80169e10;
/* 80868228 3FC08077 */  lis      r30, UNDEF_8076f4e0@ha;
/* 8086822C 3FE08077 */  lis      r31, UNDEF_8076f350@ha;
/* 80868230 387B0074 */  addi     r3, r27, 116;
/* 80868234 38C0000C */  li       r6, 12;
/* 80868238 389EF4E0 */  addi     r4, r30, UNDEF_8076f4e0@l;
/* 8086823C 38BFF350 */  addi     r5, r31, UNDEF_8076f350@l;
/* 80868240 38E00008 */  li       r7, 8;
/* 80868244 4BA74A4D */  bl       UNDEF_802dcc90;
/* 80868248 387B00D4 */  addi     r3, r27, 212;
/* 8086824C 389EF4E0 */  addi     r4, r30, UNDEF_8076f4e0@l;
/* 80868250 38BFF350 */  addi     r5, r31, UNDEF_8076f350@l;
/* 80868254 38C0000C */  li       r6, 12;
/* 80868258 38E00006 */  li       r7, 6;
/* 8086825C 4BA74A35 */  bl       UNDEF_802dcc90;
/* 80868260 93BC08CC */  stw      r29, 2252(r28);
/* 80868264 3C608033 */  lis      r3, UNDEF_80329920@ha;
/* 80868268 38639920 */  addi     r3, r3, UNDEF_80329920@l;
/* 8086826C 907C08D0 */  stw      r3, 2256(r28);
/* 80868270 387C08DC */  addi     r3, r28, 2268;
/* 80868274 93BC08D4 */  stw      r29, 2260(r28);
/* 80868278 93BC08D8 */  stw      r29, 2264(r28);
/* 8086827C 4B9024A5 */  bl       UNDEF_8016a720;
/* 80868280 3C608033 */  lis      r3, UNDEF_80329890@ha;
/* 80868284 38639890 */  addi     r3, r3, UNDEF_80329890@l;
/* 80868288 907C08D0 */  stw      r3, 2256(r28);
/* 8086828C 93BC08F8 */  stw      r29, 2296(r28);
UNDEF_80868290:;
/* 80868290 39610020 */  addi     r11, r1, 32;
/* 80868294 7F83E378 */  mr       r3, r28;
/* 80868298 4BA74E19 */  bl       UNDEF_802dd0b0;
/* 8086829C 80010024 */  lwz      r0, 36(r1);
/* 808682A0 7C0803A6 */  mtlr     r0;
/* 808682A4 38210020 */  addi     r1, r1, 32;
/* 808682A8 4E800020 */  blr;
  // clang-format on
);

/* VT+0x08 */
[[nsmbw(0x808682B0)]]
fBase_c::PACK_RESULT_e daMiniGameWireMesh_c::create() ASM_METHOD(
  // clang-format off
/* 808682B0 9421FFE0 */  stwu     r1, -32(r1);
/* 808682B4 7C0802A6 */  mflr     r0;
/* 808682B8 90010024 */  stw      r0, 36(r1);
/* 808682BC 93E1001C */  stw      r31, 28(r1);
/* 808682C0 3BE00000 */  li       r31, 0;
/* 808682C4 93C10018 */  stw      r30, 24(r1);
/* 808682C8 3FC08094 */  lis      r30, UNDEF_80939a00@ha;
/* 808682CC 3BDE9A00 */  addi     r30, r30, UNDEF_80939a00@l;
/* 808682D0 93A10014 */  stw      r29, 20(r1);
/* 808682D4 7C7D1B78 */  mr       r29, r3;
/* 808682D8 C01E0030 */  lfs      f0, 48(r30);
/* 808682DC C02300AC */  lfs      f1, 172(r3);
/* 808682E0 C06300B0 */  lfs      f3, 176(r3);
/* 808682E4 EC210028 */  fsubs    f1, f1, f0;
/* 808682E8 C04300B4 */  lfs      f2, 180(r3);
/* 808682EC EC03002A */  fadds    f0, f3, f0;
/* 808682F0 D0430734 */  stfs     f2, 1844(r3);
/* 808682F4 93E308AC */  stw      r31, 2220(r3);
/* 808682F8 D023072C */  stfs     f1, 1836(r3);
/* 808682FC D0030730 */  stfs     f0, 1840(r3);
/* 80868300 48000761 */  bl       UNDEF_80868a60;
/* 80868304 C03E0034 */  lfs      f1, 52(r30);
/* 80868308 3800FFFF */  li       r0, -1;
/* 8086830C C01E0038 */  lfs      f0, 56(r30);
/* 80868310 387D0148 */  addi     r3, r29, 328;
/* 80868314 9BFD036D */  stb      r31, 877(r29);
/* 80868318 D03D00DC */  stfs     f1, 220(r29);
/* 8086831C D03D00E0 */  stfs     f1, 224(r29);
/* 80868320 D03D00E4 */  stfs     f1, 228(r29);
/* 80868324 D01D00B4 */  stfs     f0, 180(r29);

                         addi     r9, r29, OFFSET_daMiniGameWireMesh_c_mPlayerIDs - 1;
                         .rept    PLAYER_COUNT;
/* 80868328          */  stbu     r0, 1(r9);
                         stb      r31, OFFSET_daMiniGameWireMesh_c_mPlayer0x8C4 - OFFSET_daMiniGameWireMesh_c_mPlayerIDs(r9);
                         .endr;

/* 80868348 B3FD08BA */  sth      r31, 2234(r29);
/* 8086834C B3FD08B6 */  sth      r31, 2230(r29);
/* 80868350 9BFD08FC */  stb      r31, 2300(r29);
/* 80868354 9BFD08FD */  stb      r31, 2301(r29);
/* 80868358 9BFD08FE */  stb      r31, 2302(r29);
/* 8086835C 9BFD08FF */  stb      r31, 2303(r29);
/* 80868360 901D0900 */  stw      r0, 2304(r29);
/* 80868364 4B823FCD */  bl       UNDEF_8008c330;
/* 80868368 819D0060 */  lwz      r12, 96(r29);
/* 8086836C 3C80809A */  lis      r4, UNDEF_8099cd08@ha;
/* 80868370 7FA3EB78 */  mr       r3, r29;
/* 80868374 818C00D4 */  lwz      r12, 212(r12);
/* 80868378 3884CD08 */  addi     r4, r4, UNDEF_8099cd08@l;
/* 8086837C 7D8903A6 */  mtctr    r12;
/* 80868380 4E800421 */  bctrl;
/* 80868384 C01E0038 */  lfs      f0, 56(r30);
/* 80868388 38600001 */  li       r3, 1;
/* 8086838C D01D0320 */  stfs     f0, 800(r29);
/* 80868390 D01D0324 */  stfs     f0, 804(r29);
/* 80868394 83E1001C */  lwz      r31, 28(r1);
/* 80868398 83C10018 */  lwz      r30, 24(r1);
/* 8086839C 83A10014 */  lwz      r29, 20(r1);
/* 808683A0 80010024 */  lwz      r0, 36(r1);
/* 808683A4 7C0803A6 */  mtlr     r0;
/* 808683A8 38210020 */  addi     r1, r1, 32;
/* 808683AC 4E800020 */  blr;
  // clang-format on
);

/* VT+0x20 */
[[nsmbw(0x80868420)]]
fBase_c::PACK_RESULT_e daMiniGameWireMesh_c::execute()
{
    mStateMgr.executeState();

    std::memset(mPlayerIDs, -1, sizeof(mPlayerIDs));
    std::memset(m0x6A4, 0, sizeof(m0x6A4));
    m0x8B6 = 0;

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80868590)]]
void daMiniGameWireMesh_c::ccCallback(dCc_c* me, dCc_c* other) ASM_METHOD(
  // clang-format off
/* 80868590 9421FFE0 */  stwu     r1, -32(r1);
/* 80868594 7C0802A6 */  mflr     r0;
/* 80868598 90010024 */  stw      r0, 36(r1);
/* 8086859C 93E1001C */  stw      r31, 28(r1);
/* 808685A0 93C10018 */  stw      r30, 24(r1);
/* 808685A4 93A10014 */  stw      r29, 20(r1);
/* 808685A8 7C9D2378 */  mr       r29, r4;
/* 808685AC 93810010 */  stw      r28, 16(r1);
/* 808685B0 7C7C1B78 */  mr       r28, r3;
/* 808685B4 83E30004 */  lwz      r31, 4(r3);
/* 808685B8 83C40004 */  lwz      r30, 4(r4);
/* 808685BC 881F08FC */  lbz      r0, 2300(r31);
/* 808685C0 2C000000 */  cmpwi    r0, 0;
/* 808685C4 40820198 */  bne-     UNDEF_8086875c;
/* 808685C8 881E038C */  lbz      r0, 908(r30);
/* 808685CC 28000001 */  cmplwi   r0, 1;
/* 808685D0 408201B4 */  bne-     UNDEF_80868784;
/* 808685D4 389E0148 */  addi     r4, r30, 328;
/* 808685D8 4B823FB9 */  bl       UNDEF_8008c590;
/* 808685DC 2C030000 */  cmpwi    r3, 0;
/* 808685E0 41820104 */  beq-     UNDEF_808686e4;
/* 808685E4 819E0060 */  lwz      r12, 96(r30);
/* 808685E8 7FC3F378 */  mr       r3, r30;
/* 808685EC 818C006C */  lwz      r12, 108(r12);
/* 808685F0 7D8903A6 */  mtctr    r12;
/* 808685F4 4E800421 */  bctrl;
/* 808685F8 88830000 */  lbz      r4, 0(r3);
/* 808685FC 7C800774 */  extsb    r0, r4;
/* 80868600 7C7F0214 */  add      r3, r31, r0;
/* 80868604          */  stb      r4, OFFSET_daMiniGameWireMesh_c_mPlayerIDs(r3);
/* 80868608 A01F08BA */  lhz      r0, 2234(r31);
/* 8086860C 2C000000 */  cmpwi    r0, 0;
/* 80868610 40820174 */  bne-     UNDEF_80868784;
/* 80868614 819E0060 */  lwz      r12, 96(r30);
/* 80868618 3C80809A */  lis      r4, UNDEF_8099cf78@ha;
/* 8086861C 8084CF78 */  lwz      r4, UNDEF_8099cf78@l(r4);
/* 80868620 7FC3F378 */  mr       r3, r30;
/* 80868624 818C006C */  lwz      r12, 108(r12);
/* 80868628 83A40208 */  lwz      r29, 520(r4);
/* 8086862C 7D8903A6 */  mtctr    r12;
/* 80868630 4E800421 */  bctrl;
/* 80868634 88030000 */  lbz      r0, 0(r3);
/* 80868638 7C000774 */  extsb    r0, r0;
/* 8086863C 7C00E800 */  cmpw     r0, r29;
/* 80868640 40820094 */  bne-     UNDEF_808686d4;
/* 80868644 7FC3F378 */  mr       r3, r30;
/* 80868648 4B8CB139 */  bl       UNDEF_80133780;
/* 8086864C 2C030000 */  cmpwi    r3, 0;
/* 80868650 41820134 */  beq-     UNDEF_80868784;
/* 80868654 881E1035 */  lbz      r0, 4149(r30);
/* 80868658 C03E00AC */  lfs      f1, 172(r30);
/* 8086865C C01F00AC */  lfs      f0, 172(r31);
/* 80868660 28000002 */  cmplwi   r0, 2;
/* 80868664 EC210028 */  fsubs    f1, f1, f0;
/* 80868668 40820030 */  bne-     UNDEF_80868698;
/* 8086866C 3C608094 */  lis      r3, UNDEF_80939a38@ha;
/* 80868670 C0039A38 */  lfs      f0, UNDEF_80939a38@l(r3);
/* 80868674 FC010040 */  fcmpo    cr0, f1, f0;
/* 80868678 4C411382 */  cror     2, 1, 2;
/* 8086867C 40820010 */  bne-     UNDEF_8086868c;
/* 80868680 38000001 */  li       r0, 1;
/* 80868684 B01F08B8 */  sth      r0, 2232(r31);
/* 80868688 48000038 */  b        UNDEF_808686c0;
UNDEF_8086868c:;
/* 8086868C 38000000 */  li       r0, 0;
/* 80868690 B01F08B8 */  sth      r0, 2232(r31);
/* 80868694 4800002C */  b        UNDEF_808686c0;
UNDEF_80868698:;
/* 80868698 3C608094 */  lis      r3, UNDEF_80939a38@ha;
/* 8086869C C0039A38 */  lfs      f0, UNDEF_80939a38@l(r3);
/* 808686A0 FC010040 */  fcmpo    cr0, f1, f0;
/* 808686A4 4C411382 */  cror     2, 1, 2;
/* 808686A8 40820010 */  bne-     UNDEF_808686b8;
/* 808686AC 38000000 */  li       r0, 0;
/* 808686B0 B01F08B8 */  sth      r0, 2232(r31);
/* 808686B4 4800000C */  b        UNDEF_808686c0;
UNDEF_808686b8:;
/* 808686B8 38000001 */  li       r0, 1;
/* 808686BC B01F08B8 */  sth      r0, 2232(r31);
UNDEF_808686c0:;
/* 808686C0 38000001 */  li       r0, 1;
/* 808686C4 B01F08BA */  sth      r0, 2234(r31);
/* 808686C8 38600001 */  li       r3, 1;
/* 808686CC 4B7DC3F5 */  bl       UNDEF_80044ac0;
/* 808686D0 480000B4 */  b        UNDEF_80868784;
UNDEF_808686d4:;
/* 808686D4 7FC3F378 */  mr       r3, r30;
/* 808686D8 38800049 */  li       r4, 73;
/* 808686DC 4B7EE615 */  bl       UNDEF_80056cf0;
/* 808686E0 480000A4 */  b        UNDEF_80868784;
UNDEF_808686e4:;
/* 808686E4 881E038C */  lbz      r0, 908(r30);
/* 808686E8 28000003 */  cmplwi   r0, 3;
/* 808686EC 40820098 */  bne-     UNDEF_80868784;
/* 808686F0 7F83E378 */  mr       r3, r28;
/* 808686F4 7FA4EB78 */  mr       r4, r29;
/* 808686F8 4B823E99 */  bl       UNDEF_8008c590;
/* 808686FC 2C030000 */  cmpwi    r3, 0;
/* 80868700 41820084 */  beq-     UNDEF_80868784;
/* 80868704 A07E0008 */  lhz      r3, 8(r30);
/* 80868708 2803008D */  cmplwi   r3, 141;
/* 8086870C 41820018 */  beq-     UNDEF_80868724;
/* 80868710 3C630001 */  addis    r3, r3, 1;
/* 80868714 3803FF56 */  subi     r0, r3, 170;
/* 80868718 5400043E */  clrlwi   r0, r0, 16;
/* 8086871C 28000001 */  cmplwi   r0, 1;
/* 80868720 41810064 */  bgt-     UNDEF_80868784;
UNDEF_80868724:;
/* 80868724 A01F08B6 */  lhz      r0, 2230(r31);
/* 80868728 809E0000 */  lwz      r4, 0(r30);
/* 8086872C 5400103A */  slwi     r0, r0, 2;
/* 80868730 7C7F0214 */  add      r3, r31, r0;
/* 80868734 908306A4 */  stw      r4, 1700(r3);
/* 80868738 A07F08B6 */  lhz      r3, 2230(r31);
/* 8086873C 38030001 */  addi     r0, r3, 1;
/* 80868740 B01F08B6 */  sth      r0, 2230(r31);
/* 80868744 5400043E */  clrlwi   r0, r0, 16;
/* 80868748 28000011 */  cmplwi   r0, 17;
/* 8086874C 41800038 */  blt-     UNDEF_80868784;
/* 80868750 38000000 */  li       r0, 0;
/* 80868754 B01F08B6 */  sth      r0, 2230(r31);
/* 80868758 4800002C */  b        UNDEF_80868784;
UNDEF_8086875c:;
/* 8086875C 881E038C */  lbz      r0, 908(r30);
/* 80868760 28000001 */  cmplwi   r0, 1;
/* 80868764 40820020 */  bne-     UNDEF_80868784;
/* 80868768 389E0148 */  addi     r4, r30, 328;
/* 8086876C 4B823E25 */  bl       UNDEF_8008c590;
/* 80868770 2C030000 */  cmpwi    r3, 0;
/* 80868774 41820010 */  beq-     UNDEF_80868784;
/* 80868778 7FC3F378 */  mr       r3, r30;
/* 8086877C 38800049 */  li       r4, 73;
/* 80868780 4B7EE571 */  bl       UNDEF_80056cf0;
UNDEF_80868784:;
/* 80868784 80010024 */  lwz      r0, 36(r1);
/* 80868788 83E1001C */  lwz      r31, 28(r1);
/* 8086878C 83C10018 */  lwz      r30, 24(r1);
/* 80868790 83A10014 */  lwz      r29, 20(r1);
/* 80868794 83810010 */  lwz      r28, 16(r1);
/* 80868798 7C0803A6 */  mtlr     r0;
/* 8086879C 38210020 */  addi     r1, r1, 32;
/* 808687A0 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x808687B0)]]
void daMiniGameWireMesh_c::updatePlayerAmiRoll(int index) ASM_METHOD(
  // clang-format off
UNDEF_808687b0:;
/* 808687B0 9421FFD0 */  stwu     r1, -48(r1);
/* 808687B4 7C0802A6 */  mflr     r0;
/* 808687B8 90010034 */  stw      r0, 52(r1);
/* 808687BC 93E1002C */  stw      r31, 44(r1);
/* 808687C0 93C10028 */  stw      r30, 40(r1);
/* 808687C4 7C9E2378 */  mr       r30, r4;
/* 808687C8 93A10024 */  stw      r29, 36(r1);
/* 808687CC 7C7D1B78 */  mr       r29, r3;
/* 808687D0 7C830774 */  extsb    r3, r4;
/* 808687D4 4B7F712D */  bl       getPlayer__9daPyMng_cFi;
/* 808687D8 7C7F1B78 */  mr       r31, r3;
/* 808687DC 389D00AC */  addi     r4, r29, 172;
/* 808687E0 4B8CB041 */  bl       UNDEF_80133820;
/* 808687E4 2C030000 */  cmpwi    r3, 0;
/* 808687E8 41820078 */  beq-     UNDEF_80868860;
/* 808687EC 3C608094 */  lis      r3, UNDEF_80939a38@ha;
/* 808687F0 7FC00774 */  extsb    r0, r30;
/* 808687F4 C0439A38 */  lfs      f2, UNDEF_80939a38@l(r3);
/* 808687F8 5403103A */  slwi     r3, r0, 2;
/* 808687FC D05F010C */  stfs     f2, 268(r31);
/* 80868800 7C9D1A14 */  add      r4, r29, r3;
/* 80868804 7C7D0214 */  add      r3, r29, r0;
/* 80868808 38000001 */  li       r0, 1;
/* 8086880C D05F00E8 */  stfs     f2, 232(r31);
/* 80868810 D05F00EC */  stfs     f2, 236(r31);
/* 80868814 D05F00F0 */  stfs     f2, 240(r31);
/* 80868818 C03F00AC */  lfs      f1, 172(r31);
/* 8086881C C01D00AC */  lfs      f0, 172(r29);
/* 80868820 D0410008 */  stfs     f2, 8(r1);
/* 80868824 EC010028 */  fsubs    f0, f1, f0;
/* 80868828 D041000C */  stfs     f2, 12(r1);
/* 8086882C          */  stfs     f0, OFFSET_daMiniGameWireMesh_c_mPlayerX(r4);
/* 80868830 C03F00B0 */  lfs      f1, 176(r31);
/* 80868834 C01D00B0 */  lfs      f0, 176(r29);
/* 80868838 D0410010 */  stfs     f2, 16(r1);
/* 8086883C EC010028 */  fsubs    f0, f1, f0;
/* 80868840          */  stfs     f0, OFFSET_daMiniGameWireMesh_c_mPlayerY(r4);
/* 80868844 C03F00B4 */  lfs      f1, 180(r31);
/* 80868848 C01D00B4 */  lfs      f0, 180(r29);
/* 8086884C EC010028 */  fsubs    f0, f1, f0;
/* 80868850          */  stfs     f0, OFFSET_daMiniGameWireMesh_c_mPlayerZ(r4);
/* 80868854 889F1035 */  lbz      r4, 4149(r31);
/* 80868858          */  stb      r4, OFFSET_daMiniGameWireMesh_c_mPlayerChainlinkMode(r3);
/* 8086885C          */  stb      r0, OFFSET_daMiniGameWireMesh_c_mPlayer0x8C4(r3);
UNDEF_80868860:;
/* 80868860 80010034 */  lwz      r0, 52(r1);
/* 80868864 83E1002C */  lwz      r31, 44(r1);
/* 80868868 83C10028 */  lwz      r30, 40(r1);
/* 8086886C 83A10024 */  lwz      r29, 36(r1);
/* 80868870 7C0803A6 */  mtlr     r0;
/* 80868874 38210030 */  addi     r1, r1, 48;
/* 80868878 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80868880)]]
void daMiniGameWireMesh_c::updateAll() ASM_METHOD(
  // clang-format off
/* 80868880 9421FFD0 */  stwu     r1, -48(r1);
/* 80868884 7C0802A6 */  mflr     r0;
/* 80868888 90010034 */  stw      r0, 52(r1);
/* 8086888C 39610030 */  addi     r11, r1, 48;
/* 80868890 4BA747C9 */  bl       UNDEF_802dd058;
/* 80868894 A00308BA */  lhz      r0, 2234(r3);
/* 80868898 7C7F1B78 */  mr       r31, r3;
/* 8086889C 2C000000 */  cmpwi    r0, 0;
/* 808688A0 4182018C */  beq-     UNDEF_80868a2c;
/* 808688A4 3B000000 */  li       r24, 0;
UNDEF_808688a8:;
/* 808688A8 7C7FC214 */  add      r3, r31, r24;
/* 808688AC 880308C8 */  lbz      r0, OFFSET_daMiniGameWireMesh_c_mPlayerIDs(r3);
/* 808688B4          */  cmpwi    r0, 0xff;
/* 808688B8 41820010 */  beq-     UNDEF_808688c8;
/* 808688BC 7FE3FB78 */  mr       r3, r31;
/* 808688C0 7F040774 */  extsb    r4, r24;
/* 808688C4 4BFFFEED */  bl       UNDEF_808687b0;
UNDEF_808688c8:;
/* 808688C8 3B180001 */  addi     r24, r24, 1;
/* 808688CC          */  cmpwi    r24, PLAYER_COUNT;
/* 808688D0 4180FFD8 */  blt+     UNDEF_808688a8;
/* 808688D4 3B800000 */  li       r28, 0;
/* 808688D8 939F06E8 */  stw      r28, 1768(r31);
/* 808688DC 3C608094 */  lis      r3, UNDEF_80939a40@ha;
/* 808688E0 7FFBFB78 */  mr       r27, r31;
/* 808688E4 939F06EC */  stw      r28, 1772(r31);
/* 808688E8 7FFAFB78 */  mr       r26, r31;
/* 808688EC 7FF9FB78 */  mr       r25, r31;
/* 808688F0 3BA39A40 */  addi     r29, r3, UNDEF_80939a40@l;
/* 808688F4 939F06F0 */  stw      r28, 1776(r31);
/* 808688F8 3B000000 */  li       r24, 0;
/* 808688FC 3BC00001 */  li       r30, 1;
/* 80868900 939F06F4 */  stw      r28, 1780(r31);
/* 80868904 939F06F8 */  stw      r28, 1784(r31);
/* 80868908 939F06FC */  stw      r28, 1788(r31);
/* 8086890C 939F0700 */  stw      r28, 1792(r31);
/* 80868910 939F0704 */  stw      r28, 1796(r31);
/* 80868914 939F0708 */  stw      r28, 1800(r31);
/* 80868918 939F070C */  stw      r28, 1804(r31);
/* 8086891C 939F0710 */  stw      r28, 1808(r31);
/* 80868920 939F0714 */  stw      r28, 1812(r31);
/* 80868924 939F0718 */  stw      r28, 1816(r31);
/* 80868928 939F071C */  stw      r28, 1820(r31);
/* 8086892C 939F0720 */  stw      r28, 1824(r31);
/* 80868930 939F0724 */  stw      r28, 1828(r31);
/* 80868934 939F0728 */  stw      r28, 1832(r31);
UNDEF_80868938:;
/* 80868938 807B06A4 */  lwz      r3, 1700(r27);
/* 8086893C 2C030000 */  cmpwi    r3, 0;
/* 80868940 418200A8 */  beq-     UNDEF_808689e8;
/* 80868944 4B8FA4FD */  bl       UNDEF_80162e40;
/* 80868948 2C030000 */  cmpwi    r3, 0;
/* 8086894C 4182009C */  beq-     UNDEF_808689e8;
/* 80868950 801B06A4 */  lwz      r0, 1700(r27);
/* 80868954 38800000 */  li       r4, 0;
/* 80868958 901A06E8 */  stw      r0, 1768(r26);
/* 8086895C A0030008 */  lhz      r0, 8(r3);
/* 80868960 2800008D */  cmplwi   r0, 141;
/* 80868964 40820008 */  bne-     UNDEF_8086896c;
/* 80868968 38800001 */  li       r4, 1;
UNDEF_8086896c:;
/* 8086896C 88030391 */  lbz      r0, 913(r3);
/* 80868970 28000001 */  cmplwi   r0, 1;
/* 80868974 40820018 */  bne-     UNDEF_8086898c;
/* 80868978 548015BA */  clrlslwi r0, r4, 24, 2;
/* 8086897C 7C1D042E */  lfsx     f0, r29, r0;
/* 80868980 FC000050 */  fneg     f0, f0;
/* 80868984 D00300B4 */  stfs     f0, 180(r3);
/* 80868988 48000010 */  b        UNDEF_80868998;
UNDEF_8086898c:;
/* 8086898C 548015BA */  clrlslwi r0, r4, 24, 2;
/* 80868990 7C1D042E */  lfsx     f0, r29, r0;
/* 80868994 D00300B4 */  stfs     f0, 180(r3);
UNDEF_80868998:;
/* 80868998 C02300AC */  lfs      f1, 172(r3);
/* 8086899C C01F00AC */  lfs      f0, 172(r31);
/* 808689A0 EC010028 */  fsubs    f0, f1, f0;
/* 808689A4 D01A0774 */  stfs     f0, 1908(r26);
/* 808689A8 C02300B0 */  lfs      f1, 176(r3);
/* 808689AC C01F00B0 */  lfs      f0, 176(r31);
/* 808689B0 EC010028 */  fsubs    f0, f1, f0;
/* 808689B4 D01A07B8 */  stfs     f0, 1976(r26);
/* 808689B8 C02300B4 */  lfs      f1, 180(r3);
/* 808689BC C01F00B4 */  lfs      f0, 180(r31);
/* 808689C0 EC010028 */  fsubs    f0, f1, f0;
/* 808689C4 D01A07FC */  stfs     f0, 2044(r26);
/* 808689C8 3B5A0004 */  addi     r26, r26, 4;
/* 808689CC C00300B0 */  lfs      f0, 176(r3);
/* 808689D0 D01B0840 */  stfs     f0, 2112(r27);
/* 808689D4 A8030102 */  lha      r0, 258(r3);
/* 808689D8 B0190884 */  sth      r0, 2180(r25);
/* 808689DC 3B390002 */  addi     r25, r25, 2;
/* 808689E0 93C30524 */  stw      r30, 1316(r3);
/* 808689E4 93830184 */  stw      r28, 388(r3);
UNDEF_808689e8:;
/* 808689E8 3B180001 */  addi     r24, r24, 1;
/* 808689EC 3B7B0004 */  addi     r27, r27, 4;
/* 808689F0 2C180011 */  cmpwi    r24, 17;
/* 808689F4 4180FF44 */  blt+     UNDEF_80868938;
/* 808689F8 C05F00AC */  lfs      f2, 172(r31);
/* 808689FC 3C80809A */  lis      r4, UNDEF_8099cd88@ha;
/* 80868A00 C03F00B0 */  lfs      f1, 176(r31);
/* 80868A04 7FE3FB78 */  mr       r3, r31;
/* 80868A08 C01F00B4 */  lfs      f0, 180(r31);
/* 80868A0C 3884CD88 */  addi     r4, r4, UNDEF_8099cd88@l;
/* 80868A10 D05F0738 */  stfs     f2, 1848(r31);
/* 80868A14 D03F073C */  stfs     f1, 1852(r31);
/* 80868A18 D01F0740 */  stfs     f0, 1856(r31);
/* 80868A1C 819F0060 */  lwz      r12, 96(r31);
/* 80868A20 818C00D4 */  lwz      r12, 212(r12);
/* 80868A24 7D8903A6 */  mtctr    r12;
/* 80868A28 4E800421 */  bctrl;
UNDEF_80868a2c:;
/* 80868A2C 39610030 */  addi     r11, r1, 48;
/* 80868A30 4BA74675 */  bl       UNDEF_802dd0a4;
/* 80868A34 80010034 */  lwz      r0, 52(r1);
/* 80868A38 7C0803A6 */  mtlr     r0;
/* 80868A3C 38210030 */  addi     r1, r1, 48;
/* 80868A40 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80868F00)]]
void daMiniGameWireMesh_c::setAmiRollPos() ASM_METHOD(
  // clang-format off
/* 80868F00 9421FFE0 */  stwu     r1, -32(r1);
/* 80868F04 7C0802A6 */  mflr     r0;
/* 80868F08 90010024 */  stw      r0, 36(r1);
/* 80868F0C 93E1001C */  stw      r31, 28(r1);
/* 80868F10 93C10018 */  stw      r30, 24(r1);
/* 80868F14 93A10014 */  stw      r29, 20(r1);
/* 80868F18 3BA00000 */  li       r29, 0;
/* 80868F1C 93810010 */  stw      r28, 16(r1);
/* 80868F20 7C7C1B78 */  mr       r28, r3;
/* 80868F24 7F9FE378 */  mr       r31, r28;
UNDEF_80868f28:;
/* 80868F28 7C7CEA14 */  add      r3, r28, r29;
/* 80868F2C 880308C4 */  lbz      r0, OFFSET_daMiniGameWireMesh_c_mPlayer0x8C4(r3);
/* 80868F30 2C000000 */  cmpwi    r0, 0;
/* 80868F34 4182002C */  beq-     UNDEF_80868f60;
/* 80868F38 7FA3EB78 */  mr       r3, r29;
/* 80868F3C 4B7F69C5 */  bl       getPlayer__9daPyMng_cFi;
/* 80868F40          */  lfs      f1, OFFSET_daMiniGameWireMesh_c_mPlayerX(r31);
/* 80868F44 7C7E1B78 */  mr       r30, r3;
/* 80868F48 A89C0102 */  lha      r4, 258(r28);
/* 80868F4C 7F83E378 */  mr       r3, r28;
/* 80868F50 4BFFFC71 */  bl       UNDEF_80868bc0;
/* 80868F54 A89C08B4 */  lha      r4, 2228(r28);
/* 80868F58 7FC3F378 */  mr       r3, r30;
/* 80868F5C 4B8CAA45 */  bl       UNDEF_801339a0; // setAmiRollPos__7dAcPy_cFsf
UNDEF_80868f60:;
/* 80868F60 3BBD0001 */  addi     r29, r29, 1;
/* 80868F64 3BFF0004 */  addi     r31, r31, 4;
/* 80868F68          */  cmpwi    r29, PLAYER_COUNT;
/* 80868F6C 4180FFBC */  blt+     UNDEF_80868f28;
/* 80868F70 80010024 */  lwz      r0, 36(r1);
/* 80868F74 83E1001C */  lwz      r31, 28(r1);
/* 80868F78 83C10018 */  lwz      r30, 24(r1);
/* 80868F7C 83A10014 */  lwz      r29, 20(r1);
/* 80868F80 83810010 */  lwz      r28, 16(r1);
/* 80868F84 7C0803A6 */  mtlr     r0;
/* 80868F88 38210020 */  addi     r1, r1, 32;
/* 80868F8C 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80868F90)]]
void daMiniGameWireMesh_c::endAmiRollAction() ASM_METHOD(
  // clang-format off
/* 80868F90 9421FFF0 */  stwu     r1, -16(r1);
/* 80868F94 7C0802A6 */  mflr     r0;
/* 80868F98 90010014 */  stw      r0, 20(r1);
/* 80868F9C 93E1000C */  stw      r31, 12(r1);
/* 80868FA0 3BE00000 */  li       r31, 0;
/* 80868FA4 93C10008 */  stw      r30, 8(r1);
/* 80868FA8 7C7E1B78 */  mr       r30, r3;
UNDEF_80868fac:;
/* 80868FAC 7C7EFA14 */  add      r3, r30, r31;
/* 80868FB0 880308C4 */  lbz      r0, OFFSET_daMiniGameWireMesh_c_mPlayer0x8C4(r3);
/* 80868FB4 2C000000 */  cmpwi    r0, 0;
/* 80868FB8 41820014 */  beq-     UNDEF_80868fcc;
/* 80868FBC 7FE3FB78 */  mr       r3, r31;
/* 80868FC0 4B7F6941 */  bl       getPlayer__9daPyMng_cFi;
/* 80868FC4 A89E08B4 */  lha      r4, 2228(r30);
/* 80868FC8 4B8CAB59 */  bl       UNDEF_80133b20; // endAmiRollAction__7dAcPy_cFs
UNDEF_80868fcc:;
/* 80868FCC 3BFF0001 */  addi     r31, r31, 1;
/* 80868FD0          */  cmpwi    r31, PLAYER_COUNT;
/* 80868FD4 4180FFD8 */  blt+     UNDEF_80868fac;
/* 80868FD8 80010014 */  lwz      r0, 20(r1);
/* 80868FDC 83E1000C */  lwz      r31, 12(r1);
/* 80868FE0 83C10008 */  lwz      r30, 8(r1);
/* 80868FE4 7C0803A6 */  mtlr     r0;
/* 80868FE8 38210010 */  addi     r1, r1, 16;
/* 80868FEC 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80868FF0)]]
void daMiniGameWireMesh_c::initializeState_PlayWait()
{
    m0x8BA = 0;
    std::memset(&mPlayer0x8C4, 0, sizeof(mPlayer0x8C4));
}

[[nsmbw(0x80869050)]]
void daMiniGameWireMesh_c::initializeState_PlayMove() ASM_METHOD(
  // clang-format off
/* 80869050 9421FFE0 */  stwu     r1, -32(r1);
/* 80869054 7C0802A6 */  mflr     r0;
/* 80869058 3CA08043 */  lis      r5, g_pSndObjMap__6dAudio@ha;
/* 8086905C 90010024 */  stw      r0, 36(r1);
/* 80869060 38000000 */  li       r0, 0;
/* 80869064 93E1001C */  stw      r31, 28(r1);
/* 80869068 93C10018 */  stw      r30, 24(r1);
/* 8086906C 7C7E1B78 */  mr       r30, r3;
/* 80869070 389E00AC */  addi     r4, r30, 172;
/* 80869074 B00308B4 */  sth      r0, 2228(r3);
/* 80869078 900308B0 */  stw      r0, 2224(r3);

                         addi     r9, r3, OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC - 1;
                         .rept    PLAYER_COUNT;
/* 8086907C          */  stbu     r0, 1(r9);
                         .endr;

/* 8086908C 38610008 */  addi     r3, r1, 8;
/* 80869090 83E5A040 */  lwz      r31, g_pSndObjMap__6dAudio@l(r5);
/* 80869094 4B80141D */  bl       UNDEF_8006a4b0;
/* 80869098 7FE3FB78 */  mr       r3, r31;
/* 8086909C 38A10008 */  addi     r5, r1, 8;
/* 808690A0 388005EA */  li       r4, 1514;
/* 808690A4 38C00000 */  li       r6, 0;
/* 808690A8 4B92FCC9 */  bl       UNDEF_80198d70;
/* 808690AC 3CC0809A */  lis      r6, UNDEF_8099cf78@ha;
/* 808690B0 8006CF78 */  lwz      r0, UNDEF_8099cf78@l(r6);
/* 808690B4 2C000000 */  cmpwi    r0, 0;
/* 808690B8 4182002C */  beq-     UNDEF_808690e4;
/* 808690BC 38A00001 */  li       r5, 1;
/* 808690C0 98BE08FC */  stb      r5, 2300(r30);
/* 808690C4 801E0004 */  lwz      r0, 4(r30);
/* 808690C8 38800000 */  li       r4, 0;
/* 808690CC 8066CF78 */  lwz      r3, UNDEF_8099cf78@l(r6);
/* 808690D0 54002536 */  clrlslwi r0, r0, 24, 4;
/* 808690D4 7C630214 */  add      r3, r3, r0;
/* 808690D8 98A3007D */  stb      r5, 125(r3);
/* 808690DC 8066CF78 */  lwz      r3, UNDEF_8099cf78@l(r6);
/* 808690E0 480019E1 */  bl       UNDEF_8086aac0;
UNDEF_808690e4:;
/* 808690E4 80010024 */  lwz      r0, 36(r1);
/* 808690E8 83E1001C */  lwz      r31, 28(r1);
/* 808690EC 83C10018 */  lwz      r30, 24(r1);
/* 808690F0 7C0803A6 */  mtlr     r0;
/* 808690F4 38210020 */  addi     r1, r1, 32;
/* 808690F8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80869110)]]
void daMiniGameWireMesh_c::executeState_PlayMove() ASM_METHOD(
  // clang-format off
/* 80869110 9421FFD0 */  stwu     r1, -48(r1);
/* 80869114 7C0802A6 */  mflr     r0;
/* 80869118 90010034 */  stw      r0, 52(r1);
/* 8086911C 39610030 */  addi     r11, r1, 48;
/* 80869120 4BA73F41 */  bl       UNDEF_802dd060;
/* 80869124 A00308B8 */  lhz      r0, 2232(r3);
/* 80869128 3C808094 */  lis      r4, UNDEF_80939a74@ha;
/* 8086912C 38849A74 */  addi     r4, r4, UNDEF_80939a74@l;
/* 80869130 A8C308B4 */  lha      r6, 2228(r3);
/* 80869134 5405083C */  slwi     r5, r0, 1;
/* 80869138 A8030102 */  lha      r0, 258(r3);
/* 8086913C 7CA42AAE */  lhax     r5, r4, r5;
/* 80869140 7C7F1B78 */  mr       r31, r3;
/* 80869144 7C862A14 */  add      r4, r6, r5;
/* 80869148 7C002A14 */  add      r0, r0, r5;
/* 8086914C B08308B4 */  sth      r4, 2228(r3);
/* 80869150 B0030102 */  sth      r0, 258(r3);
/* 80869154 7CA32B78 */  mr       r3, r5;
/* 80869158 4BA756AD */  bl       UNDEF_802de804;
/* 8086915C 801F08B0 */  lwz      r0, 2224(r31);
/* 80869160 3B600000 */  li       r27, 0;
/* 80869164 7C001A14 */  add      r0, r0, r3;
/* 80869168 901F08B0 */  stw      r0, 2224(r31);
/* 8086916C 2800071C */  cmplwi   r0, 1820;
/* 80869170 41800008 */  blt-     UNDEF_80869178;
/* 80869174 3B600001 */  li       r27, 1;
UNDEF_80869178:;
/* 80869178 28002000 */  cmplwi   r0, 8192;
/* 8086917C 41800008 */  blt-     UNDEF_80869184;
/* 80869180 3B600002 */  li       r27, 2;
UNDEF_80869184:;
/* 80869184 28004000 */  cmplwi   r0, 16384;
/* 80869188 41800020 */  blt-     UNDEF_808691a8;
/* 8086918C 881F08FD */  lbz      r0, 2301(r31);
/* 80869190 2C000000 */  cmpwi    r0, 0;
/* 80869194 40820014 */  bne-     UNDEF_808691a8;
/* 80869198 38000001 */  li       r0, 1;
/* 8086919C 981F08FD */  stb      r0, 2301(r31);
/* 808691A0 7FE3FB78 */  mr       r3, r31;
/* 808691A4 4800019D */  bl       UNDEF_80869340;
UNDEF_808691a8:;
/* 808691A8 2C1B0000 */  cmpwi    r27, 0;
/* 808691AC 41820068 */  beq-     UNDEF_80869214;
/* 808691B0 3B400000 */  li       r26, 0;
/* 808691B4 3BC00001 */  li       r30, 1;
/* 808691B8 3BA00002 */  li       r29, 2;
UNDEF_808691bc:;
/* 808691BC 7F9FD214 */  add      r28, r31, r26;
/* 808691C0          */  lbz      r0, OFFSET_daMiniGameWireMesh_c_mPlayer0x8C4(r28);
/* 808691C4 2C000000 */  cmpwi    r0, 0;
/* 808691C8 41820040 */  beq-     UNDEF_80869208;
/* 808691CC          */  lbz      r0, OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC(r28);
/* 808691D0 2C000000 */  cmpwi    r0, 0;
/* 808691D4 40820034 */  bne-     UNDEF_80869208;
/* 808691D8 7F43D378 */  mr       r3, r26;
/* 808691DC 4B7F6725 */  bl       getPlayer__9daPyMng_cFi;
/* 808691E0          */  lbz      r0, OFFSET_daMiniGameWireMesh_c_mPlayerChainlinkMode(r28);
/* 808691E4 28000001 */  cmplwi   r0, 1;
/* 808691E8 40820010 */  bne-     UNDEF_808691f8;
/* 808691EC 9BA31035 */  stb      r29, 4149(r3);
/* 808691F0          */  stb      r30, OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC(r28);
/* 808691F4 48000014 */  b        UNDEF_80869208;
UNDEF_808691f8:;
/* 808691F8 281B0002 */  cmplwi   r27, 2;
/* 808691FC 4082000C */  bne-     UNDEF_80869208;
/* 80869200 9BC31035 */  stb      r30, 4149(r3);
/* 80869204          */  stb      r30, OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC(r28);
UNDEF_80869208:;
/* 80869208 3B5A0001 */  addi     r26, r26, 1;
/* 8086920C          */  cmpwi    r26, PLAYER_COUNT;
/* 80869210 4180FFAC */  blt+     UNDEF_808691bc;
UNDEF_80869214:;
/* 80869214 7FE3FB78 */  mr       r3, r31;
/* 80869218 4BFFFCE9 */  bl       UNDEF_80868f00;
/* 8086921C A89F08B4 */  lha      r4, 2228(r31);
/* 80869220 7FE3FB78 */  mr       r3, r31;
/* 80869224 4BFFFB9D */  bl       UNDEF_80868dc0;
/* 80869228 801F08B0 */  lwz      r0, 2224(r31);
/* 8086922C 38600000 */  li       r3, 0;
/* 80869230 2800FFFF */  cmplwi   r0, 65535;
/* 80869234 41800008 */  blt-     UNDEF_8086923c;
/* 80869238 38600001 */  li       r3, 1;
UNDEF_8086923c:;
/* 8086923C 2C030000 */  cmpwi    r3, 0;
/* 80869240 418200E8 */  beq-     UNDEF_80869328;
/* 80869244 3BC00000 */  li       r30, 0;
/* 80869248 B3DF08B4 */  sth      r30, 2228(r31);
/* 8086924C 7FE3FB78 */  mr       r3, r31;
/* 80869250 93DF08B0 */  stw      r30, 2224(r31);
/* 80869254 4BFFFD3D */  bl       UNDEF_80868f90;
/* 80869258 A89F08B4 */  lha      r4, 2228(r31);
/* 8086925C 7FE3FB78 */  mr       r3, r31;
/* 80869260 4BFFFBE1 */  bl       UNDEF_80868e40;
/* 80869268 A87F0102 */  lha      r3, 258(r31);

                         addi     r9, r31, OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC - 1;
                         .rept    PLAYER_COUNT;
/* 80869264          */  stbu     r30, 1(r9);
                         .endr;

/* 80869278 4BA7558D */  bl       UNDEF_802de804;
/* 8086927C 2C034000 */  cmpwi    r3, 16384;
/* 80869280 41800010 */  blt-     UNDEF_80869290;
/* 80869284 38008000 */  li       r0, -32768;
/* 80869288 B01F0102 */  sth      r0, 258(r31);
/* 8086928C 48000008 */  b        UNDEF_80869294;
UNDEF_80869290:;
/* 80869290 B3DF0102 */  sth      r30, 258(r31);
UNDEF_80869294:;
/* 80869294 3FC0809A */  lis      r30, UNDEF_8099cf78@ha;
/* 80869298 3B400000 */  li       r26, 0;
/* 8086929C 807ECF78 */  lwz      r3, UNDEF_8099cf78@l(r30);
/* 808692A0 2C030000 */  cmpwi    r3, 0;
/* 808692A4 41820028 */  beq-     UNDEF_808692cc;
/* 808692A8 801F0004 */  lwz      r0, 4(r31);
/* 808692AC 5404063E */  clrlwi   r4, r0, 24;
/* 808692B0 480013C1 */  bl       UNDEF_8086a670;
/* 808692B4 7C7A1B78 */  mr       r26, r3;
/* 808692B8 807ECF78 */  lwz      r3, UNDEF_8099cf78@l(r30);
/* 808692BC 48002535 */  bl       UNDEF_8086b7f0;
/* 808692C0 807ECF78 */  lwz      r3, UNDEF_8099cf78@l(r30);
/* 808692C4 38800001 */  li       r4, 1;
/* 808692C8 480017F9 */  bl       UNDEF_8086aac0;
UNDEF_808692cc:;
/* 808692CC 2C1A0000 */  cmpwi    r26, 0;
/* 808692D0 4082003C */  bne-     UNDEF_8086930c;
/* 808692D4 3C808094 */  lis      r4, UNDEF_80939a78@ha;
/* 808692D8 C05F00B0 */  lfs      f2, 176(r31);
/* 808692DC C03F00AC */  lfs      f1, 172(r31);
/* 808692E0 3C608097 */  lis      r3, UNDEF_809703a0@ha;
/* 808692E4 C0049A78 */  lfs      f0, UNDEF_80939a78@l(r4);
/* 808692E8 386303A0 */  addi     r3, r3, UNDEF_809703a0@l;
/* 808692EC D0210008 */  stfs     f1, 8(r1);
/* 808692F0 38A10008 */  addi     r5, r1, 8;
/* 808692F4 38800000 */  li       r4, 0;
/* 808692F8 38C00000 */  li       r6, 0;
/* 808692FC D041000C */  stfs     f2, 12(r1);
/* 80869300 38E00000 */  li       r7, 0;
/* 80869304 D0010010 */  stfs     f0, 16(r1);
/* 80869308 4B9036C9 */  bl       UNDEF_8016c9d0;
UNDEF_8086930c:;
/* 8086930C 819F0060 */  lwz      r12, 96(r31);
/* 80869310 3C80809A */  lis      r4, UNDEF_8099cd48@ha;
/* 80869314 7FE3FB78 */  mr       r3, r31;
/* 80869318 818C00D4 */  lwz      r12, 212(r12);
/* 8086931C 3884CD48 */  addi     r4, r4, UNDEF_8099cd48@l;
/* 80869320 7D8903A6 */  mtctr    r12;
/* 80869324 4E800421 */  bctrl;
UNDEF_80869328:;
/* 80869328 39610030 */  addi     r11, r1, 48;
/* 8086932C 4BA73D81 */  bl       UNDEF_802dd0ac;
/* 80869330 80010034 */  lwz      r0, 52(r1);
/* 80869334 7C0803A6 */  mtlr     r0;
/* 80869338 38210030 */  addi     r1, r1, 48;
/* 8086933C 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80869680)]]
void daMiniGameWireMesh_c::initializeState_ForceTurnUp()
{
    m0x8B4 = 0;
    m0x8B0 = 0;
    std::memset(mPlayer0x8BC, 0, sizeof(mPlayer0x8BC));
}

[[nsmbw(0x808696A0)]]
void daMiniGameWireMesh_c::executeState_ForceTurnUp() ASM_METHOD(
  // clang-format off
/* 808696A0 9421FFF0 */  stwu     r1, -16(r1);
/* 808696A4 7C0802A6 */  mflr     r0;
/* 808696A8 3C808094 */  lis      r4, UNDEF_80939a7c@ha;
/* 808696AC 90010014 */  stw      r0, 20(r1);
/* 808696B0 38849A7C */  addi     r4, r4, UNDEF_80939a7c@l;
/* 808696B4 93E1000C */  stw      r31, 12(r1);
/* 808696B8 7C7F1B78 */  mr       r31, r3;
/* 808696BC 93C10008 */  stw      r30, 8(r1);
/* 808696C0 A00308B8 */  lhz      r0, 2232(r3);
/* 808696C4 A8C308B4 */  lha      r6, 2228(r3);
/* 808696C8 5405083C */  slwi     r5, r0, 1;
/* 808696CC A8030102 */  lha      r0, 258(r3);
/* 808696D0 7CA42AAE */  lhax     r5, r4, r5;
/* 808696D4 7C862A14 */  add      r4, r6, r5;
/* 808696D8 7C002A14 */  add      r0, r0, r5;
/* 808696DC B08308B4 */  sth      r4, 2228(r3);
/* 808696E0 B0030102 */  sth      r0, 258(r3);
/* 808696E4 7CA32B78 */  mr       r3, r5;
/* 808696E8 4BA7511D */  bl       UNDEF_802de804;
/* 808696EC 801F08B0 */  lwz      r0, 2224(r31);
/* 808696F0 7C001A14 */  add      r0, r0, r3;
/* 808696F4 901F08B0 */  stw      r0, 2224(r31);
/* 808696F8 28004000 */  cmplwi   r0, 16384;
/* 808696FC 41800020 */  blt-     UNDEF_8086971c;
/* 80869700 881F08FD */  lbz      r0, 2301(r31);
/* 80869704 2C000000 */  cmpwi    r0, 0;
/* 80869708 40820014 */  bne-     UNDEF_8086971c;
/* 8086970C 38000001 */  li       r0, 1;
/* 80869710 981F08FD */  stb      r0, 2301(r31);
/* 80869714 7FE3FB78 */  mr       r3, r31;
/* 80869718 4BFFFC29 */  bl       UNDEF_80869340;
UNDEF_8086971c:;
/* 8086971C 7FE3FB78 */  mr       r3, r31;
/* 80869720 4BFFF7E1 */  bl       UNDEF_80868f00;
/* 80869724 A89F08B4 */  lha      r4, 2228(r31);
/* 80869728 7FE3FB78 */  mr       r3, r31;
/* 8086972C 4BFFF695 */  bl       UNDEF_80868dc0;
/* 80869730 801F08B0 */  lwz      r0, 2224(r31);
/* 80869734 38600000 */  li       r3, 0;
/* 80869738 2800FFFF */  cmplwi   r0, 65535;
/* 8086973C 41800008 */  blt-     UNDEF_80869744;
/* 80869740 38600001 */  li       r3, 1;
UNDEF_80869744:;
/* 80869744 2C030000 */  cmpwi    r3, 0;
/* 80869748 4182009C */  beq-     UNDEF_808697e4;
/* 8086974C 3BC00000 */  li       r30, 0;
/* 80869750 B3DF08B4 */  sth      r30, 2228(r31);
/* 80869754 7FE3FB78 */  mr       r3, r31;
/* 80869758 93DF08B0 */  stw      r30, 2224(r31);
/* 8086975C 4BFFF835 */  bl       UNDEF_80868f90;
/* 80869760 A89F08B4 */  lha      r4, 2228(r31);
/* 80869764 7FE3FB78 */  mr       r3, r31;
/* 80869768 4BFFF6D9 */  bl       UNDEF_80868e40;
/* 80869770 A87F0102 */  lha      r3, 258(r31);

                         addi     r9, r31, OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC - 1;
                         .rept    PLAYER_COUNT;
/* 8086976C          */  stbu     r30, 1(r9);
                         .endr;

/* 80869780 4BA75085 */  bl       UNDEF_802de804;
/* 80869784 2C034000 */  cmpwi    r3, 16384;
/* 80869788 41800010 */  blt-     UNDEF_80869798;
/* 8086978C 38008000 */  li       r0, -32768;
/* 80869790 B01F0102 */  sth      r0, 258(r31);
/* 80869794 48000008 */  b        UNDEF_8086979c;
UNDEF_80869798:;
/* 80869798 B3DF0102 */  sth      r30, 258(r31);
UNDEF_8086979c:;
/* 8086979C 3C60809A */  lis      r3, UNDEF_8099cf78@ha;
/* 808697A0 8003CF78 */  lwz      r0, UNDEF_8099cf78@l(r3);
/* 808697A4 2C000000 */  cmpwi    r0, 0;
/* 808697A8 41820020 */  beq-     UNDEF_808697c8;
/* 808697AC 38800001 */  li       r4, 1;
/* 808697B0 989F08FC */  stb      r4, 2300(r31);
/* 808697B4 801F0004 */  lwz      r0, 4(r31);
/* 808697B8 8063CF78 */  lwz      r3, UNDEF_8099cf78@l(r3);
/* 808697BC 54002536 */  clrlslwi r0, r0, 24, 4;
/* 808697C0 7C630214 */  add      r3, r3, r0;
/* 808697C4 9883007D */  stb      r4, 125(r3);
UNDEF_808697c8:;
/* 808697C8 819F0060 */  lwz      r12, 96(r31);
/* 808697CC 3C80809A */  lis      r4, UNDEF_8099ce08@ha;
/* 808697D0 7FE3FB78 */  mr       r3, r31;
/* 808697D4 818C00D4 */  lwz      r12, 212(r12);
/* 808697D8 3884CE08 */  addi     r4, r4, UNDEF_8099ce08@l;
/* 808697DC 7D8903A6 */  mtctr    r12;
/* 808697E0 4E800421 */  bctrl;
UNDEF_808697e4:;
/* 808697E4 80010014 */  lwz      r0, 20(r1);
/* 808697E8 83E1000C */  lwz      r31, 12(r1);
/* 808697EC 83C10008 */  lwz      r30, 8(r1);
/* 808697F0 7C0803A6 */  mtlr     r0;
/* 808697F4 38210010 */  addi     r1, r1, 16;
/* 808697F8 4E800020 */  blr;
  // clang-format on
);
