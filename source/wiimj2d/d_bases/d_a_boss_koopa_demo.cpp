// d_a_boss_koopa_demo.cpp
// NSMBW d_bases.text: 0x807C9500 - 0x807D0070

#include "d_a_boss_koopa_demo.h"

#include "d_en_boss/d_a_en_boss_koopa.h"
#include "d_player/d_a_player.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_enemy_manager.h"
#include "d_system/d_mj2d_game.h"
#include "sound/SndSceneMgr.h"
#include <array>
#include <bit>
#include <cmath>

[[nsmbw(0x807CCE10)]]
void daBossKoopaDemo_c::initializeState_Magic() {
    dBaseActor_c* koopa =
        static_cast<dBaseActor_c*>(fManager_c::searchBaseByProfName(dProf::EN_BOSS_KOOPA));
    koopa->mActorProperties &= ~0x8;

    dEnemyMng_c::m_instance->m0x15C = 1;

    int plrCount                    = 0;
    for (std::size_t plr = 0; plr < PLAYER_COUNT; plr++) {
        if (daPyMng_c::isPlayerActive(plr)) {
            daPyMng_c::getPlayer(plr)->offStatus(95);
            plrCount++;
        }
    }

    if (plrCount > 1) {
        for (std::size_t plr = 0; plr < PLAYER_COUNT; plr++) {
            if (daPyMng_c::isPlayerActive(plr)) {
                dAcPy_c* py = daPyMng_c::getPlayer(plr);
                py->setControlDemoAnm(0);
                py->onStatus(36);
            }
        }
    }

    SndSceneMgr::sInstance->UNDEF_8019C390(3);

    m0x3D0  = -1;
    m0x03E0 = 0;
}

constexpr float daBossKoopaDemo_c::getWalkTargetX(
    int index
) {
    float x = 17.6f;
    if (index > 1) {
        x = 36.0f;
    }
    if (index > 3) {
        x = std::lerp(
            42.0f, 0.0f,
            static_cast<float>((index - 4) >> 1) / static_cast<float>((PLAYER_COUNT - 1) >> 1)
        );
    }

    if ((index & 1) == 0) {
        x = -x;
    }
    return x;
}

static_assert([] {
    std::array<float, 4> array;
    for (std::size_t i = 0; i < array.size(); i++) {
        array[i] = daBossKoopaDemo_c::getWalkTargetX(i);
    }
    return array;
}() == std::array<float, 4>{-17.6f, 17.6f, -36.0f, 36.0f});

KEEP(std::popcount<u64>);
KEEP(daBossKoopaDemo_c::getWalkTargetX);

[[nsmbw(0x807CCF90)]]
void daBossKoopaDemo_c::executeState_Magic() ASM_METHOD(
    /* 807CCF90 9421FF50 */  stwu     r1, -176(r1);
    /* 807CCF94 7C0802A6 */  mflr     r0;
    /* 807CCF98 900100B4 */  stw      r0, 180(r1);
    /* 807CCF9C 39610090 */  addi     r11, r1, 144;
    /* 807CCFA0 DBE100A0 */  stfd     f31, 160(r1);
    /* 807CCFA4 F3E100A8 */  .long    0xF3E100A8; // psq_st   f31, 168(r1), 0, 0;
    /* 807CCFA8 DBC10090 */  stfd     f30, 144(r1);
    /* 807CCFAC F3C10098 */  .long    0xF3C10098; // psq_st   f30, 152(r1), 0, 0;
    /* 807CCFB0 4BB100A9 */  bl       UNDEF_802dd058;
    /* 807CCFB4 3C808095 */  lis      r4, UNDEF_80954540@ha;
    /* 807CCFB8 3FA08093 */  lis      r29, UNDEF_80936168@ha;
    /* 807CCFBC 3BC44540 */  addi     r30, r4, UNDEF_80954540@l;
    /* 807CCFC0 7C7A1B78 */  mr       r26, r3;
    /* 807CCFC4 889E04A4 */  lbz      r4, 1188(r30);
    /* 807CCFC8 3BBD6168 */  addi     r29, r29, UNDEF_80936168@l;
    /* 807CCFCC 7C0400D0 */  neg      r0, r4;
    /* 807CCFD0 7C002378 */  or       r0, r0, r4;
    /* 807CCFD4 541F0FFE */  srwi     r31, r0, 31;
    /* 807CCFD8 4BFFC7A9 */  bl       UNDEF_807c9780;
    /* 807CCFDC 7F43D378 */  mr       r3, r26;
    /* 807CCFE0 4BFFC901 */  bl       UNDEF_807c98e0;
    /* 807CCFE4 801A03E0 */  lwz      r0, 992(r26);
    /* 807CCFE8 2C000000 */  cmpwi    r0, 0;
    /* 807CCFEC 40820188 */  bne-     UNDEF_807cd174;
    /* 807CCFF0 3C808043 */  lis      r4, mActPlayerInfo__9daPyMng_c@ha;
    /* 807CCFFC          */  lwzu     r3, mActPlayerInfo__9daPyMng_c@l(r4);
                             lwz      r4, 0x4(r4);
                             bl       popcount$LUq$R__3stdFUq;
                             mr       r5, r3;
    /* 807CD04C 3C608095 */  lis      r3, UNDEF_80954540@ha;
    /* 807CD050 2C050001 */  cmpwi    r5, 1;
    /* 807CD054 38634540 */  addi     r3, r3, UNDEF_80954540@l;
    /* 807CD058 80830434 */  lwz      r4, 1076(r3);
    /* 807CD05C 40810008 */  ble-     UNDEF_807cd064;
    /* 807CD060 80830438 */  lwz      r4, 1080(r3);
    UNDEF_807cd064:;
    /* 807CD064 801A03D0 */  lwz      r0, 976(r26);
    /* 807CD068 7C002000 */  cmpw     r0, r4;
    /* 807CD06C 40820064 */  bne-     UNDEF_807cd0d0;
    /* 807CD070 3C608095 */  lis      r3, UNDEF_80954540@ha;
    /* 807CD074 38634540 */  addi     r3, r3, UNDEF_80954540@l;
    /* 807CD078 88030431 */  lbz      r0, 1073(r3);
    /* 807CD07C 2C000000 */  cmpwi    r0, 0;
    /* 807CD080 41820040 */  beq-     UNDEF_807cd0c0;
    /* 807CD084 3BA00000 */  li       r29, 0;
    /* 807CD088 3F808043 */  lis      r28, (mActPlayerInfo__9daPyMng_c+4)@ha;
    /* 807CD08C 3B600001 */  li       r27, 1;
    UNDEF_807cd090:;
                             // TODO: 64-bit support
    /* 807CD094          */  lwz      r3, (mActPlayerInfo__9daPyMng_c+4)@l(r28);
    /* 807CD098          */  slw      r0, r27, r29;
    /* 807CD09C 7C600039 */  and.     r0, r3, r0;
    /* 807CD0A0 41820014 */  beq-     UNDEF_807cd0b4;
    /* 807CD0A4 7FA3EB78 */  mr       r3, r29;
    /* 807CD0A8 4B892859 */  bl       getPlayer__9daPyMng_cFi;
    /* 807CD0AC 38800024 */  li       r4, 36;
    /* 807CD0B0 4B889C01 */  bl       offStatus__10daPlBase_cFi;
    UNDEF_807cd0b4:;
    /* 807CD0B4 3BBD0001 */  addi     r29, r29, 1;
    /* 807CD0B8 2C1D0004 */  cmpwi    r29, PLAYER_COUNT;
    /* 807CD0BC 4180FFD4 */  blt+     UNDEF_807cd090;
    UNDEF_807cd0c0:;
    /* 807CD0C0 3C608043 */  lis      r3, mspInstance__13daPyDemoMng_c@ha;
    /* 807CD0C4 38800002 */  li       r4, 2;
    /* 807CD0C8 80639F74 */  lwz      r3, mspInstance__13daPyDemoMng_c@l(r3);
    /* 807CD0CC 4B88FD85 */  bl       UNDEF_8005ce50;
    UNDEF_807cd0d0:;
    /* 807CD0D0 3C608095 */  lis      r3, UNDEF_80954540@ha;
    /* 807CD0D4 809A03D0 */  lwz      r4, 976(r26);
    /* 807CD0D8 38634540 */  addi     r3, r3, UNDEF_80954540@l;
    /* 807CD0DC 8003043C */  lwz      r0, 1084(r3);
    /* 807CD0E0 7C040000 */  cmpw     r4, r0;
    /* 807CD0E4 4080000C */  bge-     UNDEF_807cd0f0;
    /* 807CD0E8 2C1F0000 */  cmpwi    r31, 0;
    /* 807CD0EC 41820718 */  beq-     UNDEF_807cd804;
    UNDEF_807cd0f0:;
    /* 807CD0F0 3860001A */  li       r3, 26;
    /* 807CD0F4 38800000 */  li       r4, 0;
    /* 807CD0F8 4B89D639 */  bl       UNDEF_8006a730; // prepareGameBGM__6dAudioFib
    /* 807CD0FC 38600102 */  li       r3, 258;
    /* 807CD100 38800000 */  li       r4, 0;
    /* 807CD104 4B995D8D */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD108 80830120 */  lwz      r4, 288(r3);
    /* 807CD10C 38000003 */  li       r0, 3;
    /* 807CD110 7C7B1B78 */  mr       r27, r3;
    /* 807CD114 60840008 */  ori      r4, r4, 8;
    /* 807CD118 90830120 */  stw      r4, 288(r3);
    /* 807CD11C 90030380 */  stw      r0, 896(r3);
    /* 807CD120 7F43D378 */  mr       r3, r26;
    /* 807CD124 4BFFE1FD */  bl       UNDEF_807cb320;
    /* 807CD128 2C030000 */  cmpwi    r3, 0;
    /* 807CD12C 41820034 */  beq-     UNDEF_807cd160;
    /* 807CD130 819B0060 */  lwz      r12, 96(r27);
    /* 807CD134 3C8080B9 */  lis      r4, UNDEF_80b8c2bc@ha;
    /* 807CD138 7F63DB78 */  mr       r3, r27;
    /* 807CD13C 818C00D4 */  lwz      r12, 212(r12);
    /* 807CD140 3884C2BC */  addi     r4, r4, UNDEF_80b8c2bc@l;
    /* 807CD144 7D8903A6 */  mtctr    r12;
    /* 807CD148 4E800421 */  bctrl;
    /* 807CD14C 3860FFFF */  li       r3, -1;
    /* 807CD150 38000002 */  li       r0, 2;
    /* 807CD154 907A03D0 */  stw      r3, 976(r26);
    /* 807CD158 901A03E0 */  stw      r0, 992(r26);
    /* 807CD15C 480006A8 */  b        UNDEF_807cd804;
    UNDEF_807cd160:;
    /* 807CD160 3860FFFF */  li       r3, -1;
    /* 807CD164 38000001 */  li       r0, 1;
    /* 807CD168 907A03D0 */  stw      r3, 976(r26);
    /* 807CD16C 901A03E0 */  stw      r0, 992(r26);
    /* 807CD170 48000694 */  b        UNDEF_807cd804;
    UNDEF_807cd174:;
    /* 807CD174 2C000001 */  cmpwi    r0, 1;
    /* 807CD178 40820128 */  bne-     UNDEF_807cd2a0;
    /* 807CD17C 38600102 */  li       r3, 258;
    /* 807CD180 38800000 */  li       r4, 0;
    /* 807CD184 4B995D0D */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD188 881E0440 */  lbz      r0, 1088(r30);
    /* 807CD18C 7C7F1B78 */  mr       r31, r3;
    /* 807CD190 3B200001 */  li       r25, 1;
    /* 807CD194 2C000000 */  cmpwi    r0, 0;
    /* 807CD198 418200A8 */  beq-     UNDEF_807cd240;
    /* 807CD19C C3FD0000 */  lfs      f31, 0(r29);
    /* 807CD1A0          */  li       r29, 0;
    /* 807CD1A4 3B000000 */  li       r24, 0;
    /* 807CD1A8 3F808043 */  lis      r28, (mActPlayerInfo__9daPyMng_c+4)@ha;
    /* 807CD1AC 3B600001 */  li       r27, 1;
    UNDEF_807cd1b0:;
    /* 807CD1B4          */  lwz      r3, (mActPlayerInfo__9daPyMng_c+4)@l(r28);
    /* 807CD1B8          */  slw      r0, r27, r24;
    /* 807CD1BC 7C600039 */  and.     r0, r3, r0;
    /* 807CD1C0 41820074 */  beq-     UNDEF_807cd234;
                             mr       r3, r29;
                             bl       getWalkTargetX__17daBossKoopaDemo_cFi;
                             fmr      f30, f1;
    /* 807CD1C4 7F03C378 */  mr       r3, r24;
    /* 807CD1C8 4B892739 */  bl       getPlayer__9daPyMng_cFi;
    /* 807CD1D0          */  fcmpo    cr0, f30, f31;
    /* 807CD1D4 4080000C */  bge-     UNDEF_807cd1e0;
    /* 807CD1D8 38800000 */  li       r4, 0;
    /* 807CD1DC 48000008 */  b        UNDEF_807cd1e4;
    UNDEF_807cd1e0:;
    /* 807CD1E0 38800001 */  li       r4, 1;
    UNDEF_807cd1e4:;
    /* 807CD1E4 C01F00AC */  lfs      f0, 172(r31);
    /* 807CD1E8 C02300AC */  lfs      f1, 172(r3);
    /* 807CD1EC          */  fadds    f0, f30, f0;
    /* 807CD1F0 FC010000 */  fcmpu    cr0, f1, f0;
    /* 807CD1F4 4182002C */  beq-     UNDEF_807cd220;
    /* 807CD1F8 C01E0454 */  lfs      f0, 1108(r30);
    /* 807CD1FC 3881000C */  addi     r4, r1, 12;
    /* 807CD200 D0010014 */  stfs     f0, 20(r1);
    /* 807CD204 38A10014 */  addi     r5, r1, 20;
    /* 807CD208 C01F00AC */  lfs      f0, 172(r31);
    /* 807CD20C          */  fadds    f0, f30, f0;
    /* 807CD210 D001000C */  stfs     f0, 12(r1);
    /* 807CD214 4B884E6D */  bl       setControlDemoWalk__10daPlBase_cFRCfRCf;
    /* 807CD218 3B200000 */  li       r25, 0;
    /* 807CD21C 48000014 */  b        UNDEF_807cd230;
    UNDEF_807cd220:;
    /* 807CD220 88030348 */  lbz      r0, 840(r3);
    /* 807CD224 7C040040 */  cmplw    r4, r0;
    /* 807CD228 41820008 */  beq-     UNDEF_807cd230;
    /* 807CD22C 4B884D05 */  bl       setControlDemoDir__10daPlBase_cFUc;
    UNDEF_807cd230:;
    /* 807CD230          */  addi     r29, r29, 1;
    UNDEF_807cd234:;
    /* 807CD234 3B180001 */  addi     r24, r24, 1;
    /* 807CD238          */  cmpwi    r24, PLAYER_COUNT;
    /* 807CD23C 4180FF74 */  blt+     UNDEF_807cd1b0;
    UNDEF_807cd240:;
    /* 807CD240 3C608095 */  lis      r3, UNDEF_80954540@ha;
    /* 807CD244 2C190000 */  cmpwi    r25, 0;
    /* 807CD248 38634540 */  addi     r3, r3, UNDEF_80954540@l;
    /* 807CD24C 80630458 */  lwz      r3, 1112(r3);
    /* 807CD250 418205B4 */  beq-     UNDEF_807cd804;
    /* 807CD254 801A03D0 */  lwz      r0, 976(r26);
    /* 807CD258 7C001800 */  cmpw     r0, r3;
    /* 807CD25C 418005A8 */  blt-     UNDEF_807cd804;
    /* 807CD260 819F0060 */  lwz      r12, 96(r31);
    /* 807CD264 3C8080B9 */  lis      r4, UNDEF_80b8c2bc@ha;
    /* 807CD268 7FE3FB78 */  mr       r3, r31;
    /* 807CD26C 818C00D4 */  lwz      r12, 212(r12);
    /* 807CD270 3884C2BC */  addi     r4, r4, UNDEF_80b8c2bc@l;
    /* 807CD274 7D8903A6 */  mtctr    r12;
    /* 807CD278 4E800421 */  bctrl;
    /* 807CD27C 3C608043 */  lis      r3, sInstance__11SndSceneMgr@ha;
    /* 807CD280 38800005 */  li       r4, 5;
    /* 807CD284 8063A788 */  lwz      r3, sInstance__11SndSceneMgr@l(r3);
    /* 807CD288 4B9CF109 */  bl       UNDEF_8019c390;
    /* 807CD28C 3860FFFF */  li       r3, -1;
    /* 807CD290 38000002 */  li       r0, 2;
    /* 807CD294 907A03D0 */  stw      r3, 976(r26);
    /* 807CD298 901A03E0 */  stw      r0, 992(r26);
    /* 807CD29C 48000568 */  b        UNDEF_807cd804;
    UNDEF_807cd2a0:;
    /* 807CD2A0 2C000002 */  cmpwi    r0, 2;
    /* 807CD2A4 40820370 */  bne-     UNDEF_807cd614;
    /* 807CD2A8 38600102 */  li       r3, 258;
    /* 807CD2AC 38800000 */  li       r4, 0;
    /* 807CD2B0 4B995BE1 */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD2B4 7C7C1B78 */  mr       r28, r3;
    /* 807CD2B8 38600101 */  li       r3, 257;
    /* 807CD2BC 38800000 */  li       r4, 0;
    /* 807CD2C0 4B995BD1 */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD2C4 C03C0778 */  lfs      f1, 1912(r28);
    /* 807CD2C8 7C7B1B78 */  mr       r27, r3;
    /* 807CD2CC C01D0000 */  lfs      f0, 0(r29);
    /* 807CD2D0 FC010040 */  fcmpo    cr0, f1, f0;
    /* 807CD2D4 408100B4 */  ble-     UNDEF_807cd388;
    /* 807CD2D8 C05E0468 */  lfs      f2, 1128(r30);
    /* 807CD2DC 3C808095 */  lis      r4, UNDEF_809544cc@ha;
    /* 807CD2E0 C07E0464 */  lfs      f3, 1124(r30);
    /* 807CD2E4 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD2E8 C01A00B0 */  lfs      f0, 176(r26);
    /* 807CD2EC 388444CC */  addi     r4, r4, UNDEF_809544cc@l;
    /* 807CD2F0 C03A00AC */  lfs      f1, 172(r26);
    /* 807CD2F4 38C10054 */  addi     r6, r1, 84;
    /* 807CD2F8 EC82002A */  fadds    f4, f2, f0;
    /* 807CD2FC C01D0024 */  lfs      f0, 36(r29);
    /* 807CD300 EC23082A */  fadds    f1, f3, f1;
    /* 807CD304 D001005C */  stfs     f0, 92(r1);
    /* 807CD308 38A00000 */  li       r5, 0;
    /* 807CD30C 38E00000 */  li       r7, 0;
    /* 807CD310 D0210054 */  stfs     f1, 84(r1);
    /* 807CD314 39000000 */  li       r8, 0;
    /* 807CD318 D0810058 */  stfs     f4, 88(r1);
    /* 807CD31C 85839AF8 */  lwzu     r12, -25864(r3);
    /* 807CD320 D0610028 */  stfs     f3, 40(r1);
    /* 807CD324 818C00A0 */  lwz      r12, 160(r12);
    /* 807CD328 D041002C */  stfs     f2, 44(r1);
    /* 807CD32C 7D8903A6 */  mtctr    r12;
    /* 807CD330 4E800421 */  bctrl;
    /* 807CD334 C01E0480 */  lfs      f0, 1152(r30);
    /* 807CD338 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD33C C03E047C */  lfs      f1, 1148(r30);
    /* 807CD340 38810048 */  addi     r4, r1, 72;
    /* 807CD344 C05E0478 */  lfs      f2, 1144(r30);
    /* 807CD348 38A00000 */  li       r5, 0;
    /* 807CD34C D0410048 */  stfs     f2, 72(r1);
    /* 807CD350 38C00003 */  li       r6, 3;
    /* 807CD354 D021004C */  stfs     f1, 76(r1);
    /* 807CD358 D0010050 */  stfs     f0, 80(r1);
    /* 807CD35C 85839AF8 */  lwzu     r12, -25864(r3);
    /* 807CD360 818C0074 */  lwz      r12, 116(r12);
    /* 807CD364 7D8903A6 */  mtctr    r12;
    /* 807CD368 4E800421 */  bctrl;
    /* 807CD36C 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD370 85839AF8 */  lwzu     r12, -25864(r3);
    /* 807CD374 C03E0484 */  lfs      f1, 1156(r30);
    /* 807CD378 38800003 */  li       r4, 3;
    /* 807CD37C 818C002C */  lwz      r12, 44(r12);
    /* 807CD380 7D8903A6 */  mtctr    r12;
    /* 807CD384 4E800421 */  bctrl;
    UNDEF_807cd388:;
    /* 807CD388 3C608095 */  lis      r3, UNDEF_80954540@ha;
    /* 807CD38C 801A03D0 */  lwz      r0, 976(r26);
    /* 807CD390 38634540 */  addi     r3, r3, UNDEF_80954540@l;
    /* 807CD394 C0030460 */  lfs      f0, 1120(r3);
    /* 807CD398 FC00001E */  fctiwz   f0, f0;
    /* 807CD39C D8010060 */  stfd     f0, 96(r1);
    /* 807CD3A0 80610064 */  lwz      r3, 100(r1);
    /* 807CD3A4 7C001800 */  cmpw     r0, r3;
    /* 807CD3A8 40820058 */  bne-     UNDEF_807cd400;
    /* 807CD3AC 3C608043 */  lis      r3, m_instance__8dQuake_c@ha;
    /* 807CD3B0 38800005 */  li       r4, 5;
    /* 807CD3B4 8063A2E8 */  lwz      r3, m_instance__8dQuake_c@l(r3);
    /* 807CD3B8 38A00001 */  li       r5, 1;
    /* 807CD3BC 38C00000 */  li       r6, 0;
    /* 807CD3C0 4B90B691 */  bl       UNDEF_800d8a50; // startQuakeAll__8dQuake_cFQ28dQuake_c12TYPE_QUAKE_eib
    /* 807CD3C4 4B8E5D1D */  bl       UNDEF_800b30e0; // getDispCenterY__8dGameComFv
    /* 807CD3C8 FFE00890 */  fmr      f31, f1;
    /* 807CD3CC 4B8E5CF5 */  bl       UNDEF_800b30c0; // getDispCenterX__8dGameComFv
    /* 807CD3D0 3C608043 */  lis      r3, g_pSndObjMap__6dAudio@ha;
    /* 807CD3D4 D0210020 */  stfs     f1, 32(r1);
    /* 807CD3D8 83C3A040 */  lwz      r30, g_pSndObjMap__6dAudio@l(r3);
    /* 807CD3DC 38610018 */  addi     r3, r1, 24;
    /* 807CD3E0 D3E10024 */  stfs     f31, 36(r1);
    /* 807CD3E4 38810020 */  addi     r4, r1, 32;
    UNDEF_807cd3e8:;
    /* 807CD3E8 4B89D009 */  bl       cvtSndObjctPos__6dAudioFRC7mVec2_c;
    /* 807CD3EC 7FC3F378 */  mr       r3, r30;
    /* 807CD3F0 38A10018 */  addi     r5, r1, 24;
    /* 807CD3F4 388005D4 */  li       r4, 1492;
    /* 807CD3F8 38C00000 */  li       r6, 0;
    UNDEF_807cd3fc:;
    /* 807CD3FC 4B9CB975 */  bl       startSound__14SndObjctCmnMapFUlRCQ34nw4r4math4VEC2Ul;
    UNDEF_807cd400:;
    /* 807CD400 819C0394 */  lwz      r12, 916(r28);
    /* 807CD404 387C0394 */  addi     r3, r28, 916;
    /* 807CD408 3BC00000 */  li       r30, 0;
    /* 807CD40C 818C0028 */  lwz      r12, 40(r12);
    /* 807CD410 7D8903A6 */  mtctr    r12;
    /* 807CD414 4E800421 */  bctrl;
    /* 807CD418 81830000 */  lwz      r12, 0(r3);
    /* 807CD41C 3C8080B9 */  lis      r4, UNDEF_80b8c2bc@ha;
    /* 807CD420 3884C2BC */  addi     r4, r4, UNDEF_80b8c2bc@l;
    /* 807CD424 818C0014 */  lwz      r12, 20(r12);
    /* 807CD428 7D8903A6 */  mtctr    r12;
    /* 807CD42C 4E800421 */  bctrl;
    /* 807CD430 7C0300D0 */  neg      r0, r3;
    /* 807CD434 7C001B78 */  or       r0, r0, r3;
    /* 807CD438 54000FFF */  srwi.    r0, r0, 31;
    /* 807CD43C 41820014 */  beq-     UNDEF_807cd450;
    /* 807CD440 801C0540 */  lwz      r0, 1344(r28);
    /* 807CD444 2C00000E */  cmpwi    r0, 14;
    /* 807CD448 40820008 */  bne-     UNDEF_807cd450;
    /* 807CD44C 3BC00001 */  li       r30, 1;
    UNDEF_807cd450:;
    /* 807CD450 2C1E0000 */  cmpwi    r30, 0;
    /* 807CD454 4082000C */  bne-     UNDEF_807cd460;
    /* 807CD458 2C1F0000 */  cmpwi    r31, 0;
    /* 807CD45C 418203A8 */  beq-     UNDEF_807cd804;
    UNDEF_807cd460:;
    /* 807CD460 3C608043 */  lis      r3, sInstance__11SndSceneMgr@ha;
    /* 807CD464 38800001 */  li       r4, 1;
    /* 807CD468 8063A788 */  lwz      r3, sInstance__11SndSceneMgr@l(r3);
    /* 807CD46C 4B9CE925 */  bl       UNDEF_8019bd90;
    /* 807CD470 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD474 C01D0000 */  lfs      f0, 0(r29);
    /* 807CD478 D0039CC4 */  stfs     f0, -25404(r3);
    /* 807CD47C 3FC08095 */  lis      r30, UNDEF_80954540@ha;
    /* 807CD480 3BDE4540 */  addi     r30, r30, UNDEF_80954540@l;
    /* 807CD484 38600101 */  li       r3, 257;
    /* 807CD488 801C0120 */  lwz      r0, 288(r28);
    /* 807CD48C 38800000 */  li       r4, 0;
    /* 807CD490 54000776 */  rlwinm   r0, r0, 0, 29, 27;
    /* 807CD494 901C0120 */  stw      r0, 288(r28);
    /* 807CD498 C09E046C */  lfs      f4, 1132(r30);
    /* 807CD49C C01A00AC */  lfs      f0, 172(r26);
    /* 807CD4A0 C05E0474 */  lfs      f2, 1140(r30);
    /* 807CD4A4 ECC0202A */  fadds    f6, f0, f4;
    /* 807CD4A8 C07E0470 */  lfs      f3, 1136(r30);
    /* 807CD4AC C03A00B4 */  lfs      f1, 180(r26);
    /* 807CD4B0 C01A00B0 */  lfs      f0, 176(r26);
    UNDEF_807cd4b4:;
    /* 807CD4B4 EC21102A */  fadds    f1, f1, f2;
    /* 807CD4B8 C0FE04B8 */  lfs      f7, 1208(r30);
    /* 807CD4BC ECA0182A */  fadds    f5, f0, f3;
    /* 807CD4C0 C11E04C4 */  lfs      f8, 1220(r30);
    /* 807CD4C4 C13E04BC */  lfs      f9, 1212(r30);
    /* 807CD4C8 C15E04C0 */  lfs      f10, 1216(r30);
    /* 807CD4CC D081003C */  stfs     f4, 60(r1);
    /* 807CD4D0 D0DB00AC */  stfs     f6, 172(r27);
    /* 807CD4D4 D0BB00B0 */  stfs     f5, 176(r27);
    /* 807CD4D8 D03B00B4 */  stfs     f1, 180(r27);
    /* 807CD4DC C01A00AC */  lfs      f0, 172(r26);
    /* 807CD4E0 D0610040 */  stfs     f3, 64(r1);
    /* 807CD4E4 EC07002A */  fadds    f0, f7, f0;
    /* 807CD4E8 D0410044 */  stfs     f2, 68(r1);
    /* 807CD4EC D01B0758 */  stfs     f0, 1880(r27);
    /* 807CD4F0 C01A00AC */  lfs      f0, 172(r26);
    /* 807CD4F4 D0C10030 */  stfs     f6, 48(r1);
    /* 807CD4F8 EC08002A */  fadds    f0, f8, f0;
    /* 807CD4FC D0A10034 */  stfs     f5, 52(r1);
    /* 807CD500 D01B075C */  stfs     f0, 1884(r27);
    /* 807CD504 C01A00B0 */  lfs      f0, 176(r26);
    /* 807CD508 D0210038 */  stfs     f1, 56(r1);
    /* 807CD50C EC03002A */  fadds    f0, f3, f0;
    /* 807CD510 D01B0764 */  stfs     f0, 1892(r27);
    /* 807CD514 C01A00B0 */  lfs      f0, 176(r26);
    /* 807CD518 EC09002A */  fadds    f0, f9, f0;
    /* 807CD51C D01B0768 */  stfs     f0, 1896(r27);
    /* 807CD520 C01A00AC */  lfs      f0, 172(r26);
    /* 807CD524 EC0A002A */  fadds    f0, f10, f0;
    /* 807CD528 D01B0760 */  stfs     f0, 1888(r27);
    /* 807CD52C 4B995965 */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD530 81830060 */  lwz      r12, 96(r3);
    /* 807CD534 3C8080B9 */  lis      r4, UNDEF_80b8bfec@ha;
    /* 807CD538 7C781B78 */  mr       r24, r3;
    /* 807CD53C 818C00D4 */  lwz      r12, 212(r12);
    /* 807CD540 3884BFEC */  addi     r4, r4, UNDEF_80b8bfec@l;
    /* 807CD544 7D8903A6 */  mtctr    r12;
    /* 807CD548 4E800421 */  bctrl;
    /* 807CD54C 80980120 */  lwz      r4, 288(r24);
    /* 807CD550 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD554 38000002 */  li       r0, 2;
    /* 807CD558 60840008 */  ori      r4, r4, 8;
    /* 807CD55C 90980120 */  stw      r4, 288(r24);
    /* 807CD560 38639C20 */  subi     r3, r3, 25568;
    /* 807CD564 90180380 */  stw      r0, 896(r24);
    /* 807CD568 4B91A9C9 */  bl       getSizeY__Q24Util7dDisp_cFv;
    /* 807CD56C 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD570 C01D0038 */  lfs      f0, 56(r29);
    /* 807CD574 D0239C2C */  stfs     f1, -25556(r3);
    /* 807CD578 D0039C30 */  stfs     f0, -25552(r3);
    /* 807CD57C 38639C20 */  subi     r3, r3, 25568;
    /* 807CD580 4B91AA71 */  bl       getBaseX__Q24Util7dDisp_cFv;
    /* 807CD584 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD588 C01D003C */  lfs      f0, 60(r29);
    /* 807CD58C C0439C30 */  lfs      f2, -25552(r3);
    /* 807CD590 D0239C34 */  stfs     f1, -25548(r3);
    /* 807CD594 38639C20 */  subi     r3, r3, 25568;
    /* 807CD598 EFC000B2 */  fmuls    f30, f0, f2;
    /* 807CD59C 4B91A9A5 */  bl       getSizeX__Q24Util7dDisp_cFv;
    /* 807CD5A0 FFE00890 */  fmr      f31, f1;
    /* 807CD5A4 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD5A8 38639C20 */  subi     r3, r3, 25568;
    /* 807CD5AC 4B91AA45 */  bl       getBaseX__Q24Util7dDisp_cFv;
    /* 807CD5B0 EC01F82A */  fadds    f0, f1, f31;
    /* 807CD5B4 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD5B8 EC00F028 */  fsubs    f0, f0, f30;
    /* 807CD5BC D0039C38 */  stfs     f0, -25544(r3);
    /* 807CD5C0 38639C20 */  subi     r3, r3, 25568;
    /* 807CD5C4 4B91AC1D */  bl       getBaseY__Q24Util7dDisp_cFv;
    /* 807CD5C8 3CBA0001 */  addis    r5, r26, 1;
    /* 807CD5CC C05A00B0 */  lfs      f2, 176(r26);
    /* 807CD5D0 D0259C44 */  stfs     f1, -25532(r5);
    /* 807CD5D4 3C608043 */  lis      r3, mspInstance__13daPyDemoMng_c@ha;
    /* 807CD5D8 38800001 */  li       r4, 1;
    /* 807CD5DC C01E0490 */  lfs      f0, 1168(r30);
    /* 807CD5E0 EC02002A */  fadds    f0, f2, f0;
    /* 807CD5E4 D0059C48 */  stfs     f0, -25528(r5);
    /* 807CD5E8 80639F74 */  lwz      r3, mspInstance__13daPyDemoMng_c@l(r3);
    /* 807CD5EC 4B88DFE5 */  bl       UNDEF_8005b5d0; // releaseDemoMode__13daPyDemoMng_cFi
    /* 807CD5F0 3C608043 */  lis      r3, m_instance__13dStageTimer_c@ha;
    /* 807CD5F4 38A00000 */  li       r5, 0;
    /* 807CD5F8 8083A350 */  lwz      r4, m_instance__13dStageTimer_c@l(r3);
    /* 807CD5FC 3860FFFF */  li       r3, -1;
    /* 807CD600 38000006 */  li       r0, 6;
    /* 807CD604 98A4000C */  stb      r5, 12(r4);
    /* 807CD608 907A03D0 */  stw      r3, 976(r26);
    /* 807CD60C 901A03E0 */  stw      r0, 992(r26);
    /* 807CD610 480001F4 */  b        UNDEF_807cd804;
    UNDEF_807cd614:;
    /* 807CD614 2C000006 */  cmpwi    r0, 6;
    /* 807CD618 408201EC */  bne-     UNDEF_807cd804;
    /* 807CD61C 807A03D0 */  lwz      r3, 976(r26);
    /* 807CD620 801E0488 */  lwz      r0, 1160(r30);
    /* 807CD624 7C030000 */  cmpw     r3, r0;
    /* 807CD628 40820028 */  bne-     UNDEF_807cd650;
    /* 807CD62C 38600102 */  li       r3, 258;
    /* 807CD630 38800000 */  li       r4, 0;
    /* 807CD634 4B99585D */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD638 81830060 */  lwz      r12, 96(r3);
    /* 807CD63C 3C8080B9 */  lis      r4, UNDEF_80b8c2fc@ha;
    /* 807CD640 3884C2FC */  addi     r4, r4, UNDEF_80b8c2fc@l;
    /* 807CD644 818C00D4 */  lwz      r12, 212(r12);
    /* 807CD648 7D8903A6 */  mtctr    r12;
    /* 807CD64C 4E800421 */  bctrl;
    UNDEF_807cd650:;
    /* 807CD650 3C608095 */  lis      r3, UNDEF_80954540@ha;
    /* 807CD654 809A03D0 */  lwz      r4, 976(r26);
    /* 807CD658 38634540 */  addi     r3, r3, UNDEF_80954540@l;
    /* 807CD65C 8003048C */  lwz      r0, 1164(r3);
    /* 807CD660 7C040000 */  cmpw     r4, r0;
    /* 807CD664 40820014 */  bne-     UNDEF_807cd678;
    /* 807CD668 38600021 */  li       r3, 33;
    /* 807CD66C 38800000 */  li       r4, 0;
    /* 807CD670 4B995821 */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD674 4B994FDD */  bl       UNDEF_80162650;
    UNDEF_807cd678:;
    /* 807CD678 3800003C */  li       r0, 60;
    /* 807CD67C 90010010 */  stw      r0, 16(r1);
    /* 807CD680 3C808095 */  lis      r4, UNDEF_809544c8@ha;
    /* 807CD684 38610008 */  addi     r3, r1, 8;
    /* 807CD688 801A03D0 */  lwz      r0, 976(r26);
    /* 807CD68C 388444C8 */  addi     r4, r4, UNDEF_809544c8@l;
    /* 807CD690 90010008 */  stw      r0, 8(r1);
    /* 807CD694 38A10010 */  addi     r5, r1, 16;
    /* 807CD698 48000199 */  bl       UNDEF_807cd830;
    /* 807CD69C 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD6A0 FFC00890 */  fmr      f30, f1;
    /* 807CD6A4 7C641B78 */  mr       r4, r3;
    /* 807CD6A8 38849C30 */  subi     r4, r4, 25552;
    /* 807CD6AC 38639C2C */  subi     r3, r3, 25556;
    /* 807CD6B0 4BFFC1E1 */  bl       UNDEF_807c9890;
    /* 807CD6B4 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD6B8 38639C20 */  subi     r3, r3, 25568;
    /* 807CD6BC 4B91A835 */  bl       UNDEF_800e7ef0;
    /* 807CD6C0 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD6C4 FC20F090 */  fmr      f1, f30;
    /* 807CD6C8 7C641B78 */  mr       r4, r3;
    /* 807CD6CC 38639C34 */  subi     r3, r3, 25548;
    /* 807CD6D0 38849C38 */  subi     r4, r4, 25544;
    /* 807CD6D4 4BFFC1BD */  bl       UNDEF_807c9890;
    /* 807CD6D8 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD6DC 38639C20 */  subi     r3, r3, 25568;
    /* 807CD6E0 4B91A901 */  bl       UNDEF_800e7fe0;
    /* 807CD6E4 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD6E8 FC20F090 */  fmr      f1, f30;
    /* 807CD6EC 7C641B78 */  mr       r4, r3;
    /* 807CD6F0 38639C44 */  subi     r3, r3, 25532;
    /* 807CD6F4 38849C48 */  subi     r4, r4, 25528;
    /* 807CD6F8 4BFFC199 */  bl       UNDEF_807c9890;
    /* 807CD6FC 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD700 38639C20 */  subi     r3, r3, 25568;
    /* 807CD704 4B91AACD */  bl       UNDEF_800e81d0;
    /* 807CD708 80FA03D0 */  lwz      r7, 976(r26);
    /* 807CD70C 38600101 */  li       r3, 257;
    /* 807CD710 80010010 */  lwz      r0, 16(r1);
    /* 807CD714 38800000 */  li       r4, 0;
    /* 807CD718 7CE6FE70 */  srawi    r6, r7, 31;
    /* 807CD71C 54050FFE */  srwi     r5, r0, 31;
    /* 807CD720 7C003810 */  subc     r0, r7, r0;
    /* 807CD724 7F062914 */  adde     r24, r6, r5;
    /* 807CD728 4B995769 */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD72C 2C180000 */  cmpwi    r24, 0;
    /* 807CD730 7C7B1B78 */  mr       r27, r3;
    /* 807CD734 41820058 */  beq-     UNDEF_807cd78c;
    /* 807CD738 85830394 */  lwzu     r12, 916(r3);
    /* 807CD73C 3B800000 */  li       r28, 0;
    /* 807CD740 818C0028 */  lwz      r12, 40(r12);
    /* 807CD744 7D8903A6 */  mtctr    r12;
    /* 807CD748 4E800421 */  bctrl;
    /* 807CD74C 81830000 */  lwz      r12, 0(r3);
    /* 807CD750 3C8080B9 */  lis      r4, UNDEF_80b8bfec@ha;
    /* 807CD754 3884BFEC */  addi     r4, r4, UNDEF_80b8bfec@l;
    /* 807CD758 818C0014 */  lwz      r12, 20(r12);
    /* 807CD75C 7D8903A6 */  mtctr    r12;
    /* 807CD760 4E800421 */  bctrl;
    /* 807CD764 7C0300D0 */  neg      r0, r3;
    /* 807CD768 7C001B78 */  or       r0, r0, r3;
    /* 807CD76C 54000FFF */  srwi.    r0, r0, 31;
    /* 807CD770 41820014 */  beq-     UNDEF_807cd784;
    /* 807CD774 801B0778 */  lwz      r0, 1912(r27);
    /* 807CD778 2C000001 */  cmpwi    r0, 1;
    /* 807CD77C 40800008 */  bge-     UNDEF_807cd784;
    /* 807CD780 3B800001 */  li       r28, 1;
    UNDEF_807cd784:;
    /* 807CD784 2C1C0000 */  cmpwi    r28, 0;
    /* 807CD788 4182000C */  beq-     UNDEF_807cd794;
    UNDEF_807cd78c:;
    /* 807CD78C 2C1F0000 */  cmpwi    r31, 0;
    /* 807CD790 41820074 */  beq-     UNDEF_807cd804;
    UNDEF_807cd794:;
    /* 807CD794 3C608043 */  lis      r3, m_instance__8dQuake_c@ha;
    /* 807CD798 8063A2E8 */  lwz      r3, m_instance__8dQuake_c@l(r3);
    /* 807CD79C 4B90B3D5 */  bl       UNDEF_800d8b70; // stopQuake__8dQuake_cFv
    /* 807CD7A0 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD7A4 C0239C30 */  lfs      f1, -25552(r3);
    /* 807CD7A8 38639C20 */  subi     r3, r3, 25568;
    /* 807CD7AC 4B91A745 */  bl       setSizeY__Q24Util7dDisp_cFf;
    /* 807CD7B0 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD7B4 C0239C38 */  lfs      f1, -25544(r3);
    /* 807CD7B8 38639C20 */  subi     r3, r3, 25568;
    /* 807CD7BC 4B91A825 */  bl       setBaseX__Q24Util7dDisp_cFf;
    /* 807CD7C0 3C7A0001 */  addis    r3, r26, 1;
    /* 807CD7C4 C0239C48 */  lfs      f1, -25528(r3);
    /* 807CD7C8 38639C20 */  subi     r3, r3, 25568;
    /* 807CD7CC 4B91AA05 */  bl       setBaseY__Q24Util7dDisp_cFf;
    /* 807CD7D0 2C1F0000 */  cmpwi    r31, 0;
    /* 807CD7D4 41820014 */  beq-     UNDEF_807cd7e8;
    /* 807CD7D8 38600102 */  li       r3, 258;
    /* 807CD7DC 38800000 */  li       r4, 0;
    /* 807CD7E0 4B9956B1 */  bl       searchBaseByProfName__10fManager_cFUsPC7fBase_c;
    /* 807CD7E4 4B994E6D */  bl       deleteRequest__7fBase_cFv;
    UNDEF_807cd7e8:;
    /* 807CD7E8 819A0394 */  lwz      r12, 916(r26);
    /* 807CD7EC 3C808099 */  lis      r4, UNDEF_80996d5c@ha;
    /* 807CD7F0 387A0394 */  addi     r3, r26, 916;
    /* 807CD7F4 818C0018 */  lwz      r12, 24(r12);
    /* 807CD7F8 38846D5C */  addi     r4, r4, UNDEF_80996d5c@l;
    /* 807CD7FC 7D8903A6 */  mtctr    r12;
    /* 807CD800 4E800421 */  bctrl;
    UNDEF_807cd804:;
    /* 807CD804 39610090 */  addi     r11, r1, 144;
    /* 807CD808 E3E100A8 */  .long    0xE3E100A8; // psq_l    f31, 168(r1), 0, 0;
    /* 807CD80C CBE100A0 */  lfd      f31, 160(r1);
    /* 807CD810 E3C10098 */  .long    0xE3C10098; // psq_l    f30, 152(r1), 0, 0;
    /* 807CD814 CBC10090 */  lfd      f30, 144(r1);
    /* 807CD818 4BB0F88D */  bl       UNDEF_802dd0a4;
    /* 807CD81C 800100B4 */  lwz      r0, 180(r1);
    /* 807CD820 7C0803A6 */  mtlr     r0;
    /* 807CD824 382100B0 */  addi     r1, r1, 176;
    /* 807CD828 4E800020 */  blr;
);
