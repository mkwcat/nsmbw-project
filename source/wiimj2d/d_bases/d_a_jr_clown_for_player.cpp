// d_a_jr_clown_for_player.cpp
// NSMBW .text: 0x8080F910 - 0x80813760

#include "d_a_jr_clown_for_player.h"

#include "d_player/d_a_player.h"
#include "d_static/d_mj2d_game.h"
#include "machine/m_3d_fanm.h"

const char* daJrClownForPlayer_c::getStepOnEffectName(
    const dAcPy_c* py
) {
    switch (py->mPlayerType) {
    case PLAYER_TYPE_e::MARIO:
    case PLAYER_TYPE_e::TOADETTE:
        return "Wm_jr_mrstepon";
    case PLAYER_TYPE_e::LUIGI:
    default:
        return "Wm_jr_lustepon";
    case PLAYER_TYPE_e::YELLOW_TOAD:
    case PLAYER_TYPE_e::ORANGE_TOAD:
        return "Wm_jr_kystepon";
    case PLAYER_TYPE_e::BLUE_TOAD:
    case PLAYER_TYPE_e::PURPLE_TOADETTE:
    case PLAYER_TYPE_e::BLACK_TOAD:
        return "Wm_jr_kbstepon";
    }
}

[[nsmbw(0x80810D80)]]
bool daJrClownForPlayer_c::PlayerEnter(dAcPy_c* py) ASM_METHOD(
/* 80810D80 9421FFA0 */  stwu     r1, -96(r1);
/* 80810D84 7C0802A6 */  mflr     r0;
/* 80810D88 90010064 */  stw      r0, 100(r1);
/* 80810D8C 39610060 */  addi     r11, r1, 96;
/* 80810D90 4BACC2D5 */  bl       UNDEF_802dd064;
/* 80810D94 88030E94 */  lbz      r0, 3732(r3);
/* 80810D98 3FC08093 */  lis      r30, UNDEF_80937958@ha;
/* 80810D9C 7C7F1B78 */  mr       r31, r3;
/* 80810DA0 7C9B2378 */  mr       r27, r4;
/* 80810DA4 2C000000 */  cmpwi    r0, 0;
/* 80810DA8 3BDE7958 */  addi     r30, r30, UNDEF_80937958@l;
/* 80810DAC 41820218 */  beq-     UNDEF_80810fc4;
/* 80810DB0 90830738 */  stw      r4, 1848(r3);
/* 80810DB4 7F63DB78 */  mr       r3, r27;
/* 80810DB8 7FE4FB78 */  mr       r4, r31;
/* 80810DBC 819B0060 */  lwz      r12, 96(r27);
/* 80810DC0 818C03B0 */  lwz      r12, 944(r12);
/* 80810DC4 7D8903A6 */  mtctr    r12;
/* 80810DC8 4E800421 */  bctrl;
/* 80810DCC 80BF0738 */  lwz      r5, 1848(r31);
/* 80810DD0 3C808036 */  lis      r4, UNDEF_8035815c@ha;
/* 80810DD4 7FE3FB78 */  mr       r3, r31;
/* 80810DD8 A8050102 */  lha      r0, 258(r5);
/* 80810DDC 3884815C */  addi     r4, r4, UNDEF_8035815c@l;
/* 80810DE0 B01F0D4A */  sth      r0, 3402(r31);
/* 80810DE4 819F0060 */  lwz      r12, 96(r31);
/* 80810DE8 818C00D4 */  lwz      r12, 212(r12);
/* 80810DEC 7D8903A6 */  mtctr    r12;
/* 80810DF0 4E800421 */  bctrl;
/* 80810DF4 819F0060 */  lwz      r12, 96(r31);
/* 80810DF8 7FE3FB78 */  mr       r3, r31;
/* 80810DFC 809B14D4 */  lwz      r4, 5332(r27);
/* 80810E00 818C03B4 */  lwz      r12, 948(r12);
/* 80810E04 7D8903A6 */  mtctr    r12;
/* 80810E08 4E800421 */  bctrl;
/* 80810E0C 3BA00000 */  li       r29, 0;
/* 80810E10 3C808096 */  lis      r4, UNDEF_8095fe68@ha;
/* 80810E14 9BBF0E94 */  stb      r29, 3732(r31);
/* 80810E18 387F0540 */  addi     r3, r31, 1344;
/* 80810E1C 3884FE68 */  addi     r4, r4, UNDEF_8095fe68@l;
/* 80810E20 4BA293D1 */  bl       GetResAnmChr__Q34nw4r3g3d7ResFileCFPCc;
/* 80810E24 90610008 */  stw      r3, 8(r1);
/* 80810E28 387F0584 */  addi     r3, r31, 1412;
/* 80810E2C 389F0544 */  addi     r4, r31, 1348;
/* 80810E30 38A10008 */  addi     r5, r1, 8;
/* 80810E34 38C00001 */  li       r6, 1;
/* 80810E38 4B9544F9 */  bl       setAnm__Q23m3d8anmChr_cFRQ23m3d6bmdl_cQ34nw4r3g3d9ResAnmChrQ23m3d10playMode_e;
/* 80810E3C C03E00B8 */  lfs      f1, 184(r30);
/* 80810E40 387F0544 */  addi     r3, r31, 1348;
/* 80810E44 389F0584 */  addi     r4, r31, 1412;
/* 80810E48 4B959279 */  bl       setAnm__Q23m3d5mdl_cFRQ23m3d6banm_cf;
/* 80810E4C C03E00C0 */  lfs      f1, 192(r30);
/* 80810E50 387F0584 */  addi     r3, r31, 1412;
/* 80810E54 4B9573CD */  bl       setRate__Q23m3d6banm_cFf;
/* 80810E58 C03F00B0 */  lfs      f1, 176(r31);
/* 80810E60 C05F00AC */  lfs      f2, 172(r31);
/* 80810E68 C01E0100 */  lfs      f0, 256(r30);
/* 80810E70 D0410028 */  stfs     f2, 40(r1);
/* 80810E90 D021002C */  stfs     f1, 44(r1);
/* 80810E94 D0010030 */  stfs     f0, 48(r1);
                         mr       r3, r27;
                         bl       getStepOnEffectName__20daJrClownForPlayer_cFPC7dAcPy_c;
/* 80810E74 38800000 */  li       r4, 0;
/* 80810E6C 38A10028 */  addi     r5, r1, 40;
/* 80810E7C 38C00000 */  li       r6, 0;
/* 80810E84 38E00000 */  li       r7, 0;
/* 80810EB4 4B95BB1D */  bl       createEffect__3mEfFPCcUlPC7mVec3_cPC7mAng3_cPC7mVec3_c;
/* 80810EB8 3C808043 */  lis      r4, g_pSndObjEmy__6dAudio@ha;
/* 80810EBC 38610020 */  addi     r3, r1, 32;
/* 80810EC0 83C4A03C */  lwz      r30, g_pSndObjEmy__6dAudio@l(r4);
/* 80810EC4 389F00AC */  addi     r4, r31, 172;
/* 80810EC8 4B8595E9 */  bl       cvtSndObjctPos__6dAudioFRC7mVec3_c;
/* 80810ECC 7FC3F378 */  mr       r3, r30;
/* 80810ED0 38A10020 */  addi     r5, r1, 32;
/* 80810ED4 3880059F */  li       r4, 1439;
/* 80810ED8 38C00000 */  li       r6, 0;
/* 80810EDC 4B987165 */  bl       startSound__14SndObjctCmnEmyFUlRCQ34nw4r4math4VEC2Ul;
/* 80810EE0 807F0738 */  lwz      r3, 1848(r31);
/* 80810EE4 81830060 */  lwz      r12, 96(r3);
/* 80810EE8 818C006C */  lwz      r12, 108(r12);
/* 80810EEC 7D8903A6 */  mtctr    r12;
/* 80810EF0 4E800421 */  bctrl;
/* 80810EF4 88030000 */  lbz      r0, 0(r3);
/* 80810EF8 7C030774 */  extsb    r3, r0;
/* 80810EFC 4B858635 */  bl       getRemotePlayer__6dAudioFi;
/* 80810F00 3FC08043 */  lis      r30, g_pSndObjMap__6dAudio@ha;
/* 80810F04 7C7C1B78 */  mr       r28, r3;
/* 80810F08 837EA040 */  lwz      r27, g_pSndObjMap__6dAudio@l(r30);
/* 80810F0C 38610018 */  addi     r3, r1, 24;
/* 80810F10 389F00AC */  addi     r4, r31, 172;
/* 80810F14 4B85959D */  bl       cvtSndObjctPos__6dAudioFRC7mVec3_c;
/* 80810F18 7F63DB78 */  mr       r3, r27;
/* 80810F1C 7F86E378 */  mr       r6, r28;
/* 80810F20 38A10018 */  addi     r5, r1, 24;
/* 80810F24 388002A6 */  li       r4, 678;
/* 80810F28 4B987E49 */  bl       startSound__14SndObjctCmnMapFUlRCQ34nw4r4math4VEC2Ul;
/* 80810F2C 837EA040 */  lwz      r27, g_pSndObjMap__6dAudio@l(r30);
/* 80810F30 38610010 */  addi     r3, r1, 16;
/* 80810F34 389F00AC */  addi     r4, r31, 172;
/* 80810F38 4B859579 */  bl       cvtSndObjctPos__6dAudioFRC7mVec3_c;
/* 80810F3C 7F63DB78 */  mr       r3, r27;
/* 80810F40 38A10010 */  addi     r5, r1, 16;
/* 80810F44 388005B4 */  li       r4, 1460;
/* 80810F48 38C00000 */  li       r6, 0;
/* 80810F4C 4B987E25 */  bl       startSound__14SndObjctCmnMapFUlRCQ34nw4r4math4VEC2Ul;
/* 80810F50 9BBF0E95 */  stb      r29, 3733(r31);
/* 80810F54 807F0738 */  lwz      r3, 1848(r31);
/* 80810F58 93BF0E98 */  stw      r29, 3736(r31);
/* 80810F5C 9BBF0E9C */  stb      r29, 3740(r31);
/* 80810F60 93BF0EA0 */  stw      r29, 3744(r31);
/* 80810F64 81830060 */  lwz      r12, 96(r3);
/* 80810F68 818C006C */  lwz      r12, 108(r12);
/* 80810F6C 7D8903A6 */  mtctr    r12;
/* 80810F70 4E800421 */  bctrl;
/* 80810F74 88030000 */  lbz      r0, 0(r3);
/* 80810F78 38800002 */  li       r4, 2;
/* 80810F7C 7C030774 */  extsb    r3, r0;
/* 80810F80 4B8A2681 */  bl       UNDEF_800b3600;
/* 80810F84 807F0738 */  lwz      r3, 1848(r31);
/* 80810F88 3C808043 */  lis      r4, m_instance__8dQuake_c@ha;
/* 80810F8C 8364A2E8 */  lwz      r27, m_instance__8dQuake_c@l(r4);
/* 80810F90 81830060 */  lwz      r12, 96(r3);
/* 80810F94 818C006C */  lwz      r12, 108(r12);
/* 80810F98 7D8903A6 */  mtctr    r12;
/* 80810F9C 4E800421 */  bctrl;
/* 80810FA0 88030000 */  lbz      r0, 0(r3);
/* 80810FA4 7F63DB78 */  mr       r3, r27;
/* 80810FA8 38A00007 */  li       r5, 7;
/* 80810FAC 38C00000 */  li       r6, 0;
/* 80810FB0 7C040774 */  extsb    r4, r0;
/* 80810FB4 38E00000 */  li       r7, 0;
/* 80810FB8 4B8C7CE9 */  bl       shockMotor__8dQuake_cFScQ28dQuake_c12TYPE_SHOCK_eib;
/* 80810FBC 38600001 */  li       r3, 1;
/* 80810FC0 48000008 */  b        UNDEF_80810fc8;
UNDEF_80810fc4:;
/* 80810FC4 38600000 */  li       r3, 0;
UNDEF_80810fc8:;
/* 80810FC8 39610060 */  addi     r11, r1, 96;
/* 80810FCC 4BACC0E5 */  bl       UNDEF_802dd0b0;
/* 80810FD0 80010064 */  lwz      r0, 100(r1);
/* 80810FD4 7C0803A6 */  mtlr     r0;
/* 80810FD8 38210060 */  addi     r1, r1, 96;
/* 80810FDC 4E800020 */  blr;
);

[[nsmbw(0x808116B0)]]
void daJrClownForPlayer_c::setPlayerEmblem(
    int playerNo
) {
    mResPat = mRes.GetResAnmTexPat("ply_change");

    mPlyChangePat.setAnm(mModel, mResPat, 0, m3d::playMode_e::PLAY_MODE_1);
    float frame = 0.0;
    frame       = static_cast<float>(playerNo + 1);

    mPlyChangePat.setFrame(frame, 0);
    mPlyChangePat.setRate(0.0, 0);
}
