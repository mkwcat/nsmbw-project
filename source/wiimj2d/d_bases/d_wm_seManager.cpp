// d_wm_seManager.cpp
// NSMBW .text: 0x80103F50 - 0x801060E0

#include "d_wm_seManager.h"

#include "d_system/d_a_player_manager.h"
#include "d_system/d_audio.h"
#include "d_system/d_mj2d_game.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"
#include "sound/SndObjectEnemy.h"
#include "sound/SndObjectMap.h"
#include "sound/SndObjectPlayer.h"
#include <iterator>

[[nsmbw_data(0x8042A55C)]]
dWmSeManager_c* dWmSeManager_c::m_pInstance;

[[nsmbw(0x80103F50)]]
dWmSeManager_c* dWmSeManager_c::construct()
{
    dWmSeManager_c* seManager = new dWmSeManager_c();
    seManager->initialize();
    return m_pInstance = seManager;
}

[[nsmbw(0x80103FD0)]]
dWmSeManager_c::SeParam_t::SeParam_t();

[[nsmbw(0x80103FE0)]]
dWmSeManager_c::SeParam_t::~SeParam_t();

/* VT+0x8 */
[[nsmbw(0x801041E0)]]
dWmSeManager_c::~dWmSeManager_c()
{
}

[[nsmbw(0x80104250)]]
void dWmSeManager_c::initialize()
{
    for (int i = 0; i < std::size(mSeParam); i++) {
        mSeParam[i].m0x00 = 121;
        mSeParam[i].m0x04 = 0;
        mSeParam[i].m0x08 = 0;
        mSeParam[i].m0x0C = 0;
        mSeParam[i].m0x10 = mVec3_c::Zero;
        mSeParam[i].m0x1C = 0;
        mSeParam[i].m0x20 = 1;
        mSeParam[i].m0x2C = 0;
        mSeParam[i].m0x30 = 1;
    }

    for (int i = 0; i < std::size(mpObjCSPlyArray); i++) {
        mpObjCSPlyArray[i] = new dAudio::SndObjctCSPly_c();

        if (i < 4) {
            REMOVED(mpObjCSPlyArray)[i] = mpObjCSPlyArray[i];
        }

        mpObjCSPlyArray[i]->mPlayerSndIndex = static_cast<SndObjctPly::PLAYER_SOUND_INDEX_e>(i);
    }

    mpObjCSPly = new dAudio::SndObjctCSPly_c();
    mpObjCSPly->mPlayerSndIndex = SndObjctPly::PLAYER_SOUND_INDEX_e::MA;

    mpObjEmy = new SndObjctEmy(*SndAudioMgr::sInstance->mpSoundArchivePlayer);
    mpObjCmnEmy = new SndObjctCmnEmy(*SndAudioMgr::sInstance->mpSoundArchivePlayer);
    mpObjCmnMap = new SndObjctCmnMap(*SndAudioMgr::sInstance->mpSoundArchivePlayer);
}

[[nsmbw(0x801046B0)]]
void dWmSeManager_c::execute() ASM_METHOD(
  // clang-format off
UNDEF_801046b0:;
/* 801046B0 9421FF30 */  stwu     r1, -208(r1);
/* 801046B4 7C0802A6 */  mflr     r0;
/* 801046B8 900100D4 */  stw      r0, 212(r1);
/* 801046BC 396100D0 */  addi     r11, r1, 208;
/* 801046C0 481D89A1 */  bl       UNDEF_802dd060;
/* 801046C4 808DAB00 */  lwz      r4, UNDEF_8042a480@sda21;
/* 801046C8 7C7E1B78 */  mr       r30, r3;
/* 801046CC          */  lwz      r31, OFFSET_dWmSeManager_c_mpObjCSPlyArray(r3);
/* 801046D0 38610018 */  addi     r3, r1, 24;
/* 801046D4 388400AC */  addi     r4, r4, 172;
/* 801046D8 4BF65F09 */  bl       UNDEF_8006a5e0;
/* 801046DC C0010018 */  lfs      f0, 24(r1);
/* 801046E0 3BA00000 */  li       r29, 0;
/* 801046E4 D01F00A4 */  stfs     f0, 164(r31);
/* 801046E8 C001001C */  lfs      f0, 28(r1);
/* 801046EC D01F00A8 */  stfs     f0, 168(r31);
UNDEF_801046f0:;
/* 801046F0 7FE3FB78 */  mr       r3, r31;
/* 801046F4 7FA4EB78 */  mr       r4, r29;
/* 801046F8 48170FA9 */  bl       UNDEF_802756a0;
/* 801046FC 2C030000 */  cmpwi    r3, 0;
/* 80104700 4081014C */  ble-     UNDEF_8010484c;
/* 80104704 807F005C */  lwz      r3, 92(r31);
/* 80104708 389F0064 */  addi     r4, r31, 100;
/* 8010470C 38BF00A4 */  addi     r5, r31, 164;
/* 80104710 38C00000 */  li       r6, 0;
/* 80104714 4809A70D */  bl       UNDEF_8019ee20;
/* 80104718 7FFBFB78 */  mr       r27, r31;
/* 8010471C 3BA00000 */  li       r29, 0;
/* 80104720 4800011C */  b        UNDEF_8010483c;
UNDEF_80104724:;
/* 80104724 809B0074 */  lwz      r4, 116(r27);
/* 80104728 2C040000 */  cmpwi    r4, 0;
/* 8010472C 41820108 */  beq-     UNDEF_80104834;
/* 80104730 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 80104734 4182000C */  beq-     UNDEF_80104740;
/* 80104738 8084009C */  lwz      r4, 156(r4);
/* 8010473C 48000008 */  b        UNDEF_80104744;
UNDEF_80104740:;
/* 80104740 3880FFFF */  li       r4, -1;
UNDEF_80104744:;
/* 80104744 4809205D */  bl       UNDEF_801967a0;
/* 80104748 7C7C18F8 */  not      r28, r3;
/* 8010474C 578007FF */  clrlwi.  r0, r28, 31;
/* 80104750 41820020 */  beq-     UNDEF_80104770;
/* 80104754 807B0074 */  lwz      r3, 116(r27);
/* 80104758 C03F0064 */  lfs      f1, 100(r31);
/* 8010475C 2C030000 */  cmpwi    r3, 0;
/* 80104760 4182004C */  beq-     UNDEF_801047ac;
/* 80104764 38800000 */  li       r4, 0;
/* 80104768 48162DF9 */  bl       UNDEF_80267560;
/* 8010476C 48000040 */  b        UNDEF_801047ac;
UNDEF_80104770:;
/* 80104770 806DAE08 */  lwz      r3, UNDEF_8042a788@sda21;
/* 80104774 80030014 */  lwz      r0, 20(r3);
/* 80104778 2C000003 */  cmpwi    r0, 3;
/* 8010477C 41820018 */  beq-     UNDEF_80104794;
/* 80104780 2C000002 */  cmpwi    r0, 2;
/* 80104784 40820028 */  bne-     UNDEF_801047ac;
/* 80104788 80030010 */  lwz      r0, 16(r3);
/* 8010478C 2C000003 */  cmpwi    r0, 3;
/* 80104790 4082001C */  bne-     UNDEF_801047ac;
UNDEF_80104794:;
/* 80104794 807B0074 */  lwz      r3, 116(r27);
/* 80104798 C03F0064 */  lfs      f1, 100(r31);
/* 8010479C 2C030000 */  cmpwi    r3, 0;
/* 801047A0 4182000C */  beq-     UNDEF_801047ac;
/* 801047A4 38800000 */  li       r4, 0;
/* 801047A8 48162DB9 */  bl       UNDEF_80267560;
UNDEF_801047ac:;
/* 801047AC 57800739 */  rlwinm.  r0, r28, 0, 28, 28;
/* 801047B0 41820068 */  beq-     UNDEF_80104818;
/* 801047B4 809B0074 */  lwz      r4, 116(r27);
/* 801047B8 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 801047BC 2C040000 */  cmpwi    r4, 0;
/* 801047C0 80630100 */  lwz      r3, 256(r3);
/* 801047C4 4182000C */  beq-     UNDEF_801047d0;
/* 801047C8 8084009C */  lwz      r4, 156(r4);
/* 801047CC 48000008 */  b        UNDEF_801047d4;
UNDEF_801047d0:;
/* 801047D0 3880FFFF */  li       r4, -1;
UNDEF_801047d4:;
/* 801047D4 38A10090 */  addi     r5, r1, 144;
/* 801047D8 481710E9 */  bl       UNDEF_802758c0;
/* 801047DC 809F0068 */  lwz      r4, 104(r31);
/* 801047E0 2C040000 */  cmpwi    r4, 0;
/* 801047E4 40800020 */  bge-     UNDEF_80104804;
/* 801047E8 807B0074 */  lwz      r3, 116(r27);
/* 801047EC 8001009C */  lwz      r0, 156(r1);
/* 801047F0 2C030000 */  cmpwi    r3, 0;
/* 801047F4 7C802214 */  add      r4, r0, r4;
/* 801047F8 41820020 */  beq-     UNDEF_80104818;
/* 801047FC 48162CD5 */  bl       UNDEF_802674d0;
/* 80104800 48000018 */  b        UNDEF_80104818;
UNDEF_80104804:;
/* 80104804 807B0074 */  lwz      r3, 116(r27);
/* 80104808 8081009C */  lwz      r4, 156(r1);
/* 8010480C 2C030000 */  cmpwi    r3, 0;
/* 80104810 41820008 */  beq-     UNDEF_80104818;
/* 80104814 48162CBD */  bl       UNDEF_802674d0;
UNDEF_80104818:;
/* 80104818 578007BD */  rlwinm.  r0, r28, 0, 30, 30;
/* 8010481C 41820018 */  beq-     UNDEF_80104834;
/* 80104820 807B0074 */  lwz      r3, 116(r27);
/* 80104824 C03F0070 */  lfs      f1, 112(r31);
/* 80104828 2C030000 */  cmpwi    r3, 0;
/* 8010482C 41820008 */  beq-     UNDEF_80104834;
/* 80104830 48162DD1 */  bl       UNDEF_80267600;
UNDEF_80104834:;
/* 80104834 3B7B0008 */  addi     r27, r27, 8;
/* 80104838 3BBD0001 */  addi     r29, r29, 1;
UNDEF_8010483c:;
/* 8010483C 801F0054 */  lwz      r0, 84(r31);
/* 80104840 7C1D0040 */  cmplw    r29, r0;
/* 80104844 4180FEE0 */  blt+     UNDEF_80104724;
/* 80104848 48000010 */  b        UNDEF_80104858;
UNDEF_8010484c:;
/* 8010484C 3BBD0001 */  addi     r29, r29, 1;
/* 80104850 2C1D0004 */  cmpwi    r29, PLAYER_COUNT;
/* 80104854 4180FE9C */  blt+     UNDEF_801046f0;
UNDEF_80104858:;
/* 80104858 A80DAAFE */  lha      r0, UNDEF_8042a47e@sda21;
/* 8010485C 2C000001 */  cmpwi    r0, 1;
/* 80104860 4082018C */  bne-     UNDEF_801049ec;
/* 80104864 83BE0020 */  lwz      r29, 32(r30);
/* 80104868 3BE00000 */  li       r31, 0;
/* 8010486C C002A174 */  lfs      f0, UNDEF_8042d4d4@sda21;
/* 80104870 D01D00A4 */  stfs     f0, 164(r29);
/* 80104874 D0010028 */  stfs     f0, 40(r1);
/* 80104878 D001002C */  stfs     f0, 44(r1);
/* 8010487C D01D00A8 */  stfs     f0, 168(r29);
UNDEF_80104880:;
/* 80104880 7FA3EB78 */  mr       r3, r29;
/* 80104884 7FE4FB78 */  mr       r4, r31;
/* 80104888 48170E19 */  bl       UNDEF_802756a0;
/* 8010488C 2C030000 */  cmpwi    r3, 0;
/* 80104890 4081014C */  ble-     UNDEF_801049dc;
/* 80104894 807D005C */  lwz      r3, 92(r29);
/* 80104898 389D0064 */  addi     r4, r29, 100;
/* 8010489C 38BD00A4 */  addi     r5, r29, 164;
/* 801048A0 38C00000 */  li       r6, 0;
/* 801048A4 4809A57D */  bl       UNDEF_8019ee20;
/* 801048A8 7FBBEB78 */  mr       r27, r29;
/* 801048AC 3BE00000 */  li       r31, 0;
/* 801048B0 4800011C */  b        UNDEF_801049cc;
UNDEF_801048b4:;
/* 801048B4 809B0074 */  lwz      r4, 116(r27);
/* 801048B8 2C040000 */  cmpwi    r4, 0;
/* 801048BC 41820108 */  beq-     UNDEF_801049c4;
/* 801048C0 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 801048C4 4182000C */  beq-     UNDEF_801048d0;
/* 801048C8 8084009C */  lwz      r4, 156(r4);
/* 801048CC 48000008 */  b        UNDEF_801048d4;
UNDEF_801048d0:;
/* 801048D0 3880FFFF */  li       r4, -1;
UNDEF_801048d4:;
/* 801048D4 48091ECD */  bl       UNDEF_801967a0;
/* 801048D8 7C7C18F8 */  not      r28, r3;
/* 801048DC 578007FF */  clrlwi.  r0, r28, 31;
/* 801048E0 41820020 */  beq-     UNDEF_80104900;
/* 801048E4 807B0074 */  lwz      r3, 116(r27);
/* 801048E8 C03D0064 */  lfs      f1, 100(r29);
/* 801048EC 2C030000 */  cmpwi    r3, 0;
/* 801048F0 4182004C */  beq-     UNDEF_8010493c;
/* 801048F4 38800000 */  li       r4, 0;
/* 801048F8 48162C69 */  bl       UNDEF_80267560;
/* 801048FC 48000040 */  b        UNDEF_8010493c;
UNDEF_80104900:;
/* 80104900 806DAE08 */  lwz      r3, UNDEF_8042a788@sda21;
/* 80104904 80030014 */  lwz      r0, 20(r3);
/* 80104908 2C000003 */  cmpwi    r0, 3;
/* 8010490C 41820018 */  beq-     UNDEF_80104924;
/* 80104910 2C000002 */  cmpwi    r0, 2;
/* 80104914 40820028 */  bne-     UNDEF_8010493c;
/* 80104918 80030010 */  lwz      r0, 16(r3);
/* 8010491C 2C000003 */  cmpwi    r0, 3;
/* 80104920 4082001C */  bne-     UNDEF_8010493c;
UNDEF_80104924:;
/* 80104924 807B0074 */  lwz      r3, 116(r27);
/* 80104928 C03D0064 */  lfs      f1, 100(r29);
/* 8010492C 2C030000 */  cmpwi    r3, 0;
/* 80104930 4182000C */  beq-     UNDEF_8010493c;
/* 80104934 38800000 */  li       r4, 0;
/* 80104938 48162C29 */  bl       UNDEF_80267560;
UNDEF_8010493c:;
/* 8010493C 57800739 */  rlwinm.  r0, r28, 0, 28, 28;
/* 80104940 41820068 */  beq-     UNDEF_801049a8;
/* 80104944 809B0074 */  lwz      r4, 116(r27);
/* 80104948 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 8010494C 2C040000 */  cmpwi    r4, 0;
/* 80104950 80630100 */  lwz      r3, 256(r3);
/* 80104954 4182000C */  beq-     UNDEF_80104960;
/* 80104958 8084009C */  lwz      r4, 156(r4);
/* 8010495C 48000008 */  b        UNDEF_80104964;
UNDEF_80104960:;
/* 80104960 3880FFFF */  li       r4, -1;
UNDEF_80104964:;
/* 80104964 38A10070 */  addi     r5, r1, 112;
/* 80104968 48170F59 */  bl       UNDEF_802758c0;
/* 8010496C 809D0068 */  lwz      r4, 104(r29);
/* 80104970 2C040000 */  cmpwi    r4, 0;
/* 80104974 40800020 */  bge-     UNDEF_80104994;
/* 80104978 807B0074 */  lwz      r3, 116(r27);
/* 8010497C 8001007C */  lwz      r0, 124(r1);
/* 80104980 2C030000 */  cmpwi    r3, 0;
/* 80104984 7C802214 */  add      r4, r0, r4;
/* 80104988 41820020 */  beq-     UNDEF_801049a8;
/* 8010498C 48162B45 */  bl       UNDEF_802674d0;
/* 80104990 48000018 */  b        UNDEF_801049a8;
UNDEF_80104994:;
/* 80104994 807B0074 */  lwz      r3, 116(r27);
/* 80104998 8081007C */  lwz      r4, 124(r1);
/* 8010499C 2C030000 */  cmpwi    r3, 0;
/* 801049A0 41820008 */  beq-     UNDEF_801049a8;
/* 801049A4 48162B2D */  bl       UNDEF_802674d0;
UNDEF_801049a8:;
/* 801049A8 578007BD */  rlwinm.  r0, r28, 0, 30, 30;
/* 801049AC 41820018 */  beq-     UNDEF_801049c4;
/* 801049B0 807B0074 */  lwz      r3, 116(r27);
/* 801049B4 C03D0070 */  lfs      f1, 112(r29);
/* 801049B8 2C030000 */  cmpwi    r3, 0;
/* 801049BC 41820008 */  beq-     UNDEF_801049c4;
/* 801049C0 48162C41 */  bl       UNDEF_80267600;
UNDEF_801049c4:;
/* 801049C4 3B7B0008 */  addi     r27, r27, 8;
/* 801049C8 3BFF0001 */  addi     r31, r31, 1;
UNDEF_801049cc:;
/* 801049CC 801D0054 */  lwz      r0, 84(r29);
/* 801049D0 7C1F0040 */  cmplw    r31, r0;
/* 801049D4 4180FEE0 */  blt+     UNDEF_801048b4;
/* 801049D8 480001A4 */  b        UNDEF_80104b7c;
UNDEF_801049dc:;
/* 801049DC 3BFF0001 */  addi     r31, r31, 1;
/* 801049E0 2C1F0004 */  cmpwi    r31, 4;
/* 801049E4 4180FE9C */  blt+     UNDEF_80104880;
/* 801049E8 48000194 */  b        UNDEF_80104b7c;
UNDEF_801049ec:;
/* 801049EC 808DAB00 */  lwz      r4, UNDEF_8042a480@sda21;
/* 801049F0 38610010 */  addi     r3, r1, 16;
/* 801049F4 83BE0020 */  lwz      r29, 32(r30);
/* 801049F8 388400AC */  addi     r4, r4, 172;
/* 801049FC 4BF65BE5 */  bl       UNDEF_8006a5e0;
/* 80104A00 C0010010 */  lfs      f0, 16(r1);
/* 80104A04 3BE00000 */  li       r31, 0;
/* 80104A08 D01D00A4 */  stfs     f0, 164(r29);
/* 80104A0C C0010014 */  lfs      f0, 20(r1);
/* 80104A10 D01D00A8 */  stfs     f0, 168(r29);
UNDEF_80104a14:;
/* 80104A14 7FA3EB78 */  mr       r3, r29;
/* 80104A18 7FE4FB78 */  mr       r4, r31;
/* 80104A1C 48170C85 */  bl       UNDEF_802756a0;
/* 80104A20 2C030000 */  cmpwi    r3, 0;
/* 80104A24 4081014C */  ble-     UNDEF_80104b70;
/* 80104A28 807D005C */  lwz      r3, 92(r29);
/* 80104A2C 389D0064 */  addi     r4, r29, 100;
/* 80104A30 38BD00A4 */  addi     r5, r29, 164;
/* 80104A34 38C00000 */  li       r6, 0;
/* 80104A38 4809A3E9 */  bl       UNDEF_8019ee20;
/* 80104A3C 7FBBEB78 */  mr       r27, r29;
/* 80104A40 3BE00000 */  li       r31, 0;
/* 80104A44 4800011C */  b        UNDEF_80104b60;
UNDEF_80104a48:;
/* 80104A48 809B0074 */  lwz      r4, 116(r27);
/* 80104A4C 2C040000 */  cmpwi    r4, 0;
/* 80104A50 41820108 */  beq-     UNDEF_80104b58;
/* 80104A54 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 80104A58 4182000C */  beq-     UNDEF_80104a64;
/* 80104A5C 8084009C */  lwz      r4, 156(r4);
/* 80104A60 48000008 */  b        UNDEF_80104a68;
UNDEF_80104a64:;
/* 80104A64 3880FFFF */  li       r4, -1;
UNDEF_80104a68:;
/* 80104A68 48091D39 */  bl       UNDEF_801967a0;
/* 80104A6C 7C7C18F8 */  not      r28, r3;
/* 80104A70 578007FF */  clrlwi.  r0, r28, 31;
/* 80104A74 41820020 */  beq-     UNDEF_80104a94;
/* 80104A78 807B0074 */  lwz      r3, 116(r27);
/* 80104A7C C03D0064 */  lfs      f1, 100(r29);
/* 80104A80 2C030000 */  cmpwi    r3, 0;
/* 80104A84 4182004C */  beq-     UNDEF_80104ad0;
/* 80104A88 38800000 */  li       r4, 0;
/* 80104A8C 48162AD5 */  bl       UNDEF_80267560;
/* 80104A90 48000040 */  b        UNDEF_80104ad0;
UNDEF_80104a94:;
/* 80104A94 806DAE08 */  lwz      r3, UNDEF_8042a788@sda21;
/* 80104A98 80030014 */  lwz      r0, 20(r3);
/* 80104A9C 2C000003 */  cmpwi    r0, 3;
/* 80104AA0 41820018 */  beq-     UNDEF_80104ab8;
/* 80104AA4 2C000002 */  cmpwi    r0, 2;
/* 80104AA8 40820028 */  bne-     UNDEF_80104ad0;
/* 80104AAC 80030010 */  lwz      r0, 16(r3);
/* 80104AB0 2C000003 */  cmpwi    r0, 3;
/* 80104AB4 4082001C */  bne-     UNDEF_80104ad0;
UNDEF_80104ab8:;
/* 80104AB8 807B0074 */  lwz      r3, 116(r27);
/* 80104ABC C03D0064 */  lfs      f1, 100(r29);
/* 80104AC0 2C030000 */  cmpwi    r3, 0;
/* 80104AC4 4182000C */  beq-     UNDEF_80104ad0;
/* 80104AC8 38800000 */  li       r4, 0;
/* 80104ACC 48162A95 */  bl       UNDEF_80267560;
UNDEF_80104ad0:;
/* 80104AD0 57800739 */  rlwinm.  r0, r28, 0, 28, 28;
/* 80104AD4 41820068 */  beq-     UNDEF_80104b3c;
/* 80104AD8 809B0074 */  lwz      r4, 116(r27);
/* 80104ADC 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 80104AE0 2C040000 */  cmpwi    r4, 0;
/* 80104AE4 80630100 */  lwz      r3, 256(r3);
/* 80104AE8 4182000C */  beq-     UNDEF_80104af4;
/* 80104AEC 8084009C */  lwz      r4, 156(r4);
/* 80104AF0 48000008 */  b        UNDEF_80104af8;
UNDEF_80104af4:;
/* 80104AF4 3880FFFF */  li       r4, -1;
UNDEF_80104af8:;
/* 80104AF8 38A10050 */  addi     r5, r1, 80;
/* 80104AFC 48170DC5 */  bl       UNDEF_802758c0;
/* 80104B00 809D0068 */  lwz      r4, 104(r29);
/* 80104B04 2C040000 */  cmpwi    r4, 0;
/* 80104B08 40800020 */  bge-     UNDEF_80104b28;
/* 80104B0C 807B0074 */  lwz      r3, 116(r27);
/* 80104B10 8001005C */  lwz      r0, 92(r1);
/* 80104B14 2C030000 */  cmpwi    r3, 0;
/* 80104B18 7C802214 */  add      r4, r0, r4;
/* 80104B1C 41820020 */  beq-     UNDEF_80104b3c;
/* 80104B20 481629B1 */  bl       UNDEF_802674d0;
/* 80104B24 48000018 */  b        UNDEF_80104b3c;
UNDEF_80104b28:;
/* 80104B28 807B0074 */  lwz      r3, 116(r27);
/* 80104B2C 8081005C */  lwz      r4, 92(r1);
/* 80104B30 2C030000 */  cmpwi    r3, 0;
/* 80104B34 41820008 */  beq-     UNDEF_80104b3c;
/* 80104B38 48162999 */  bl       UNDEF_802674d0;
UNDEF_80104b3c:;
/* 80104B3C 578007BD */  rlwinm.  r0, r28, 0, 30, 30;
/* 80104B40 41820018 */  beq-     UNDEF_80104b58;
/* 80104B44 807B0074 */  lwz      r3, 116(r27);
/* 80104B48 C03D0070 */  lfs      f1, 112(r29);
/* 80104B4C 2C030000 */  cmpwi    r3, 0;
/* 80104B50 41820008 */  beq-     UNDEF_80104b58;
/* 80104B54 48162AAD */  bl       UNDEF_80267600;
UNDEF_80104b58:;
/* 80104B58 3B7B0008 */  addi     r27, r27, 8;
/* 80104B5C 3BFF0001 */  addi     r31, r31, 1;
UNDEF_80104b60:;
/* 80104B60 801D0054 */  lwz      r0, 84(r29);
/* 80104B64 7C1F0040 */  cmplw    r31, r0;
/* 80104B68 4180FEE0 */  blt+     UNDEF_80104a48;
/* 80104B6C 48000010 */  b        UNDEF_80104b7c;
UNDEF_80104b70:;
/* 80104B70 3BFF0001 */  addi     r31, r31, 1;
/* 80104B74 2C1F0004 */  cmpwi    r31, 4;
/* 80104B78 4180FE9C */  blt+     UNDEF_80104a14;
UNDEF_80104b7c:;
/* 80104B7C 806DAB00 */  lwz      r3, UNDEF_8042a480@sda21;
/* 80104B80 83E30184 */  lwz      r31, 388(r3);
/* 80104B84 480001B4 */  b        UNDEF_80104d38;
UNDEF_80104b88:;
/* 80104B88 881F0124 */  lbz      r0, 292(r31);
/* 80104B8C 2C000000 */  cmpwi    r0, 0;
/* 80104B90 418201A4 */  beq-     UNDEF_80104d34;
/* 80104B94 80BF01CC */  lwz      r5, 460(r31);
/* 80104BA0 80A50004 */  lwz      r5, 4(r5);
/* 80104BA4          */  lbz      r3, 337(r5);
                         bl       getModelPlayerType__9daPyMng_cFQ211dPyMdlMng_c11ModelType_e;
/* 80104BA8          */  slwi     r0, r3, 2;
/* 80104BAC 7CBE0214 */  add      r5, r30, r0;
/* 80104BB0      n   */  lwz      r29, OFFSET_dWmSeManager_c_mpObjCSPlyArray(r5);

/* 80104B98 38610008 */  addi     r3, r1, 8;
/* 80104B9C 389F00AC */  addi     r4, r31, 172;
/* 80104BB4 4BF65A2D */  bl       UNDEF_8006a5e0;
/* 80104BB8 C0010008 */  lfs      f0, 8(r1);
/* 80104BBC 3B800000 */  li       r28, 0;
/* 80104BC0 D01D00A4 */  stfs     f0, 164(r29);
/* 80104BC4 C001000C */  lfs      f0, 12(r1);
/* 80104BC8 D01D00A8 */  stfs     f0, 168(r29);
UNDEF_80104bcc:;
/* 80104BCC 7FA3EB78 */  mr       r3, r29;
/* 80104BD0 7F84E378 */  mr       r4, r28;
/* 80104BD4 48170ACD */  bl       UNDEF_802756a0;
/* 80104BD8 2C030000 */  cmpwi    r3, 0;
/* 80104BDC 4081014C */  ble-     UNDEF_80104d28;
/* 80104BE0 807D005C */  lwz      r3, 92(r29);
/* 80104BE4 389D0064 */  addi     r4, r29, 100;
/* 80104BE8 38BD00A4 */  addi     r5, r29, 164;
/* 80104BEC 38C00000 */  li       r6, 0;
/* 80104BF0 4809A231 */  bl       UNDEF_8019ee20;
/* 80104BF4 7FBBEB78 */  mr       r27, r29;
/* 80104BF8 3B800000 */  li       r28, 0;
/* 80104BFC 4800011C */  b        UNDEF_80104d18;
UNDEF_80104c00:;
/* 80104C00 809B0074 */  lwz      r4, 116(r27);
/* 80104C04 2C040000 */  cmpwi    r4, 0;
/* 80104C08 41820108 */  beq-     UNDEF_80104d10;
/* 80104C0C 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 80104C10 4182000C */  beq-     UNDEF_80104c1c;
/* 80104C14 8084009C */  lwz      r4, 156(r4);
/* 80104C18 48000008 */  b        UNDEF_80104c20;
UNDEF_80104c1c:;
/* 80104C1C 3880FFFF */  li       r4, -1;
UNDEF_80104c20:;
/* 80104C20 48091B81 */  bl       UNDEF_801967a0;
/* 80104C24 7C7A18F8 */  not      r26, r3;
/* 80104C28 574007FF */  clrlwi.  r0, r26, 31;
/* 80104C2C 41820020 */  beq-     UNDEF_80104c4c;
/* 80104C30 807B0074 */  lwz      r3, 116(r27);
/* 80104C34 C03D0064 */  lfs      f1, 100(r29);
/* 80104C38 2C030000 */  cmpwi    r3, 0;
/* 80104C3C 4182004C */  beq-     UNDEF_80104c88;
/* 80104C40 38800000 */  li       r4, 0;
/* 80104C44 4816291D */  bl       UNDEF_80267560;
/* 80104C48 48000040 */  b        UNDEF_80104c88;
UNDEF_80104c4c:;
/* 80104C4C 806DAE08 */  lwz      r3, UNDEF_8042a788@sda21;
/* 80104C50 80030014 */  lwz      r0, 20(r3);
/* 80104C54 2C000003 */  cmpwi    r0, 3;
/* 80104C58 41820018 */  beq-     UNDEF_80104c70;
/* 80104C5C 2C000002 */  cmpwi    r0, 2;
/* 80104C60 40820028 */  bne-     UNDEF_80104c88;
/* 80104C64 80030010 */  lwz      r0, 16(r3);
/* 80104C68 2C000003 */  cmpwi    r0, 3;
/* 80104C6C 4082001C */  bne-     UNDEF_80104c88;
UNDEF_80104c70:;
/* 80104C70 807B0074 */  lwz      r3, 116(r27);
/* 80104C74 C03D0064 */  lfs      f1, 100(r29);
/* 80104C78 2C030000 */  cmpwi    r3, 0;
/* 80104C7C 4182000C */  beq-     UNDEF_80104c88;
/* 80104C80 38800000 */  li       r4, 0;
/* 80104C84 481628DD */  bl       UNDEF_80267560;
UNDEF_80104c88:;
/* 80104C88 57400739 */  rlwinm.  r0, r26, 0, 28, 28;
/* 80104C8C 41820068 */  beq-     UNDEF_80104cf4;
/* 80104C90 809B0074 */  lwz      r4, 116(r27);
/* 80104C94 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 80104C98 2C040000 */  cmpwi    r4, 0;
/* 80104C9C 80630100 */  lwz      r3, 256(r3);
/* 80104CA0 4182000C */  beq-     UNDEF_80104cac;
/* 80104CA4 8084009C */  lwz      r4, 156(r4);
/* 80104CA8 48000008 */  b        UNDEF_80104cb0;
UNDEF_80104cac:;
/* 80104CAC 3880FFFF */  li       r4, -1;
UNDEF_80104cb0:;
/* 80104CB0 38A10030 */  addi     r5, r1, 48;
/* 80104CB4 48170C0D */  bl       UNDEF_802758c0;
/* 80104CB8 809D0068 */  lwz      r4, 104(r29);
/* 80104CBC 2C040000 */  cmpwi    r4, 0;
/* 80104CC0 40800020 */  bge-     UNDEF_80104ce0;
/* 80104CC4 807B0074 */  lwz      r3, 116(r27);
/* 80104CC8 8001003C */  lwz      r0, 60(r1);
/* 80104CCC 2C030000 */  cmpwi    r3, 0;
/* 80104CD0 7C802214 */  add      r4, r0, r4;
/* 80104CD4 41820020 */  beq-     UNDEF_80104cf4;
/* 80104CD8 481627F9 */  bl       UNDEF_802674d0;
/* 80104CDC 48000018 */  b        UNDEF_80104cf4;
UNDEF_80104ce0:;
/* 80104CE0 807B0074 */  lwz      r3, 116(r27);
/* 80104CE4 8081003C */  lwz      r4, 60(r1);
/* 80104CE8 2C030000 */  cmpwi    r3, 0;
/* 80104CEC 41820008 */  beq-     UNDEF_80104cf4;
/* 80104CF0 481627E1 */  bl       UNDEF_802674d0;
UNDEF_80104cf4:;
/* 80104CF4 574007BD */  rlwinm.  r0, r26, 0, 30, 30;
/* 80104CF8 41820018 */  beq-     UNDEF_80104d10;
/* 80104CFC 807B0074 */  lwz      r3, 116(r27);
/* 80104D00 C03D0070 */  lfs      f1, 112(r29);
/* 80104D04 2C030000 */  cmpwi    r3, 0;
/* 80104D08 41820008 */  beq-     UNDEF_80104d10;
/* 80104D0C 481628F5 */  bl       UNDEF_80267600;
UNDEF_80104d10:;
/* 80104D10 3B7B0008 */  addi     r27, r27, 8;
/* 80104D14 3B9C0001 */  addi     r28, r28, 1;
UNDEF_80104d18:;
/* 80104D18 801D0054 */  lwz      r0, 84(r29);
/* 80104D1C 7C1C0040 */  cmplw    r28, r0;
/* 80104D20 4180FEE0 */  blt+     UNDEF_80104c00;
/* 80104D24 48000010 */  b        UNDEF_80104d34;
UNDEF_80104d28:;
/* 80104D28 3B9C0001 */  addi     r28, r28, 1;
/* 80104D2C 2C1C0004 */  cmpwi    r28, 4;
/* 80104D30 4180FE9C */  blt+     UNDEF_80104bcc;
UNDEF_80104d34:;
/* 80104D34 83FF0184 */  lwz      r31, 388(r31);
UNDEF_80104d38:;
/* 80104D38 2C1F0000 */  cmpwi    r31, 0;
/* 80104D3C 4082FE4C */  bne+     UNDEF_80104b88;
/* 80104D40 886DABAD */  lbz      r3, UNDEF_8042a52d@sda21;
/* 80104D44 4BFF854D */  bl       UNDEF_800fd290;
/* 80104D48 5463043E */  clrlwi   r3, r3, 16;
/* 80104D4C 38800000 */  li       r4, 0;
/* 80104D50 4805E141 */  bl       UNDEF_80162e90;
/* 80104D54 2C030000 */  cmpwi    r3, 0;
/* 80104D58 7C641B78 */  mr       r4, r3;
/* 80104D5C 41820028 */  beq-     UNDEF_80104d84;
/* 80104D60 38610020 */  addi     r3, r1, 32;
/* 80104D64 388400AC */  addi     r4, r4, 172;
/* 80104D68 4BF65879 */  bl       UNDEF_8006a5e0;
/* 80104D6C 807E0004 */  lwz      r3, 4(r30);
/* 80104D70 38810020 */  addi     r4, r1, 32;
/* 80104D74 81830000 */  lwz      r12, 0(r3);
/* 80104D78 818C0020 */  lwz      r12, 32(r12);
/* 80104D7C 7D8903A6 */  mtctr    r12;
/* 80104D80 4E800421 */  bctrl;
UNDEF_80104d84:;
/* 80104D84 7FDCF378 */  mr       r28, r30;
/* 80104D88 3B400000 */  li       r26, 0;
UNDEF_80104d8c:;
/* 80104D8C 881C0050 */  lbz      r0, 80(r28);
/* 80104D90 2C000000 */  cmpwi    r0, 0;
/* 80104D94 41820010 */  beq-     UNDEF_80104da4;
/* 80104D98 7FC3F378 */  mr       r3, r30;
/* 80104D9C 7F44D378 */  mr       r4, r26;
/* 80104DA0 48000031 */  bl       UNDEF_80104dd0;
UNDEF_80104da4:;
/* 80104DA4 3B5A0001 */  addi     r26, r26, 1;
/* 80104DA8 3B9C0034 */  addi     r28, r28, 52;
/* 80104DAC 2C1A001E */  cmpwi    r26, 30;
/* 80104DB0 4180FFDC */  blt+     UNDEF_80104d8c;
/* 80104DB4 396100D0 */  addi     r11, r1, 208;
/* 80104DB8 481D82F5 */  bl       UNDEF_802dd0ac;
/* 80104DBC 800100D4 */  lwz      r0, 212(r1);
/* 80104DC0 7C0803A6 */  mtlr     r0;
/* 80104DC4 382100D0 */  addi     r1, r1, 208;
/* 80104DC8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80104DD0)]]
void dWmSeManager_c::UNDEF_80104dd0() ASM_METHOD(
  // clang-format off
/* 80104DD0 9421FFC0 */  stwu     r1, -64(r1);
/* 80104DD4 7C0802A6 */  mflr     r0;
/* 80104DD8 C002A174 */  lfs      f0, UNDEF_8042d4d4@sda21;
/* 80104DDC 90010044 */  stw      r0, 68(r1);
/* 80104DE0 1C040034 */  mulli    r0, r4, 52;
/* 80104DE4 93E1003C */  stw      r31, 60(r1);
/* 80104DE8 7C7F1B78 */  mr       r31, r3;
/* 80104DEC 93C10038 */  stw      r30, 56(r1);
/* 80104DF0 7FC30214 */  add      r30, r3, r0;
/* 80104DF4 93A10034 */  stw      r29, 52(r1);
/* 80104DF8 D0010018 */  stfs     f0, 24(r1);
/* 80104DFC D001001C */  stfs     f0, 28(r1);
/* 80104E00 809E0028 */  lwz      r4, 40(r30);
/* 80104E04 2C040000 */  cmpwi    r4, 0;
/* 80104E08 41820050 */  beq-     UNDEF_80104e58;
/* 80104E0C 80BE002C */  lwz      r5, 44(r30);
/* 80104E10 2C050000 */  cmpwi    r5, 0;
/* 80104E14 41820044 */  beq-     UNDEF_80104e58;
/* 80104E18 38610020 */  addi     r3, r1, 32;
/* 80104E1C 4BFF77E5 */  bl       UNDEF_800fc600;
/* 80104E20 C0010020 */  lfs      f0, 32(r1);
/* 80104E24 38610010 */  addi     r3, r1, 16;
/* 80104E28 D01E0034 */  stfs     f0, 52(r30);
/* 80104E2C 389E0034 */  addi     r4, r30, 52;
/* 80104E30 C0010024 */  lfs      f0, 36(r1);
/* 80104E34 D01E0038 */  stfs     f0, 56(r30);
/* 80104E38 C0010028 */  lfs      f0, 40(r1);
/* 80104E3C D01E003C */  stfs     f0, 60(r30);
/* 80104E40 4BF657A1 */  bl       UNDEF_8006a5e0;
/* 80104E44 C0210010 */  lfs      f1, 16(r1);
/* 80104E48 C0010014 */  lfs      f0, 20(r1);
/* 80104E4C D0210018 */  stfs     f1, 24(r1);
/* 80104E50 D001001C */  stfs     f0, 28(r1);
/* 80104E54 48000044 */  b        UNDEF_80104e98;
UNDEF_80104e58:;
/* 80104E58 80BE0030 */  lwz      r5, 48(r30);
/* 80104E5C 2C050000 */  cmpwi    r5, 0;
/* 80104E60 41820038 */  beq-     UNDEF_80104e98;
/* 80104E64 C0050000 */  lfs      f0, 0(r5);
/* 80104E68 38610008 */  addi     r3, r1, 8;
/* 80104E6C D01E0034 */  stfs     f0, 52(r30);
/* 80104E70 389E0034 */  addi     r4, r30, 52;
/* 80104E74 C0050004 */  lfs      f0, 4(r5);
/* 80104E78 D01E0038 */  stfs     f0, 56(r30);
/* 80104E7C C0050008 */  lfs      f0, 8(r5);
/* 80104E80 D01E003C */  stfs     f0, 60(r30);
/* 80104E84 4BF6575D */  bl       UNDEF_8006a5e0;
/* 80104E88 C0210008 */  lfs      f1, 8(r1);
/* 80104E8C C001000C */  lfs      f0, 12(r1);
/* 80104E90 D0210018 */  stfs     f1, 24(r1);
/* 80104E94 D001001C */  stfs     f0, 28(r1);
UNDEF_80104e98:;
/* 80104E98 809E0024 */  lwz      r4, 36(r30);
/* 80104E9C 7FE3FB78 */  mr       r3, r31;
/* 80104EA0 48000931 */  bl       UNDEF_801057d0;
/* 80104EA4 2C030000 */  cmpwi    r3, 0;
/* 80104EA8 7C7D1B78 */  mr       r29, r3;
/* 80104EAC 418201F4 */  beq-     UNDEF_801050a0;
/* 80104EB0 809E0024 */  lwz      r4, 36(r30);
/* 80104EB4 7FE3FB78 */  mr       r3, r31;
/* 80104EB8 48000C79 */  bl       UNDEF_80105b30;
/* 80104EBC 2C030000 */  cmpwi    r3, 0;
/* 80104EC0 41820028 */  beq-     UNDEF_80104ee8;
/* 80104EC4 2C030002 */  cmpwi    r3, 2;
/* 80104EC8 418200F0 */  beq-     UNDEF_80104fb8;
/* 80104ECC 2C030003 */  cmpwi    r3, 3;
/* 80104ED0 41820148 */  beq-     UNDEF_80105018;
/* 80104ED4 2C030004 */  cmpwi    r3, 4;
/* 80104ED8 41820190 */  beq-     UNDEF_80105068;
/* 80104EDC 2C030005 */  cmpwi    r3, 5;
/* 80104EE0 418201B0 */  beq-     UNDEF_80105090;
/* 80104EE4 480001BC */  b        UNDEF_801050a0;
UNDEF_80104ee8:;
/* 80104EE8 801E0024 */  lwz      r0, 36(r30);
/* 80104EEC 2C00000C */  cmpwi    r0, 12;
/* 80104EF0 40820040 */  bne-     UNDEF_80104f30;
/* 80104EF4 809E004C */  lwz      r4, 76(r30);
/* 80104EF8 7FE3FB78 */  mr       r3, r31;
/* 80104EFC 48000DA5 */  bl       UNDEF_80105ca0;
/* 80104F00 80BF0020 */  lwz      r5, 32(r31);
/* 80104F04 7FA4EB78 */  mr       r4, r29;
/* 80104F08 38C00000 */  li       r6, 0;
/* 80104F0C 906500B0 */  stw      r3, 176(r5);
/* 80104F10 807F0020 */  lwz      r3, 32(r31);
/* 80104F14 80BE0040 */  lwz      r5, 64(r30);
/* 80104F18 81830000 */  lwz      r12, 0(r3);
/* 80104F1C A8A50000 */  lha      r5, 0(r5);
/* 80104F20 818C0034 */  lwz      r12, 52(r12);
/* 80104F24 7D8903A6 */  mtctr    r12;
/* 80104F28 4E800421 */  bctrl;
/* 80104F2C 48000174 */  b        UNDEF_801050a0;
UNDEF_80104f30:;
/* 80104F30 809E004C */  lwz      r4, 76(r30);
/* 80104F34 7FE3FB78 */  mr       r3, r31;
/* 80104F38 48000D69 */  bl       UNDEF_80105ca0;

/* 80104F3C          */  lwz      r3, 72(r30);
                         bl       getModelPlayerType__9daPyMng_cFQ211dPyMdlMng_c11ModelType_e;
/* 80104F40          */  slwi     r0, r3, 2;
/* 80104F44 7C9F0214 */  add      r4, r31, r0;
/* 80104F48          */  lwz      r4, OFFSET_dWmSeManager_c_mpObjCSPlyArray(r4);

/* 80104F4C 906400B0 */  stw      r3, 0xB0(r4);
/* 80104F50 807E0040 */  lwz      r3, 0x40(r30);
/* 80104F54 2C030000 */  cmpwi    r3, 0;
/* 80104F58 41820034 */  beq-     UNDEF_80104f8c;
/* 80104F64 A8A30000 */  lha      r5, 0(r3);
                         mr       r3, r4;
/* 80104F60 7FA4EB78 */  mr       r4, r29;
/* 80104F68 38C00000 */  li       r6, 0;
/* 80104F78 81830000 */  lwz      r12, 0(r3);
/* 80104F7C 818C0034 */  lwz      r12, 52(r12);
/* 80104F80 7D8903A6 */  mtctr    r12;
/* 80104F84 4E800421 */  bctrl;
/* 80104F88 48000118 */  b        UNDEF_801050a0;
UNDEF_80104f8c:;
                         mr       r3, r4;
/* 80104F90 7FA4EB78 */  mr       r4, r29;
/* 80104F94 38A00000 */  li       r5, 0;
/* 80104FA4 81830000 */  lwz      r12, 0(r3);
/* 80104FA8 818C0028 */  lwz      r12, 40(r12);
/* 80104FAC 7D8903A6 */  mtctr    r12;
/* 80104FB0 4E800421 */  bctrl;
/* 80104FB4 480000EC */  b        UNDEF_801050a0;
UNDEF_80104fb8:;
/* 80104FB8 80BE0040 */  lwz      r5, 64(r30);
/* 80104FBC 2C050000 */  cmpwi    r5, 0;
/* 80104FC0 41820030 */  beq-     UNDEF_80104ff0;
/* 80104FC4 807F000C */  lwz      r3, 12(r31);
/* 80104FC8 7FA4EB78 */  mr       r4, r29;
/* 80104FCC A8E50000 */  lha      r7, 0(r5);
/* 80104FD0 38C10018 */  addi     r6, r1, 24;
/* 80104FD4 81830000 */  lwz      r12, 0(r3);
/* 80104FD8 38A00001 */  li       r5, 1;
/* 80104FDC 811E0044 */  lwz      r8, 68(r30);
/* 80104FE0 818C0030 */  lwz      r12, 48(r12);
/* 80104FE4 7D8903A6 */  mtctr    r12;
/* 80104FE8 4E800421 */  bctrl;
/* 80104FEC 480000B4 */  b        UNDEF_801050a0;
UNDEF_80104ff0:;
/* 80104FF0 807F000C */  lwz      r3, 12(r31);
/* 80104FF4 7FA4EB78 */  mr       r4, r29;
/* 80104FF8 38C10018 */  addi     r6, r1, 24;
/* 80104FFC 80FE0044 */  lwz      r7, 68(r30);
/* 80105000 81830000 */  lwz      r12, 0(r3);
/* 80105004 38A00001 */  li       r5, 1;
/* 80105008 818C002C */  lwz      r12, 44(r12);
/* 8010500C 7D8903A6 */  mtctr    r12;
/* 80105010 4E800421 */  bctrl;
/* 80105014 4800008C */  b        UNDEF_801050a0;
UNDEF_80105018:;
/* 80105018 80BE0040 */  lwz      r5, 64(r30);
/* 8010501C 2C050000 */  cmpwi    r5, 0;
/* 80105020 41820028 */  beq-     UNDEF_80105048;
/* 80105024 807F0004 */  lwz      r3, 4(r31);
/* 80105028 7FA4EB78 */  mr       r4, r29;
/* 8010502C A8A50000 */  lha      r5, 0(r5);
/* 80105030 81830000 */  lwz      r12, 0(r3);
/* 80105034 80DE0044 */  lwz      r6, 68(r30);
/* 80105038 818C0034 */  lwz      r12, 52(r12);
/* 8010503C 7D8903A6 */  mtctr    r12;
/* 80105040 4E800421 */  bctrl;
/* 80105044 4800005C */  b        UNDEF_801050a0;
UNDEF_80105048:;
/* 80105048 807F0004 */  lwz      r3, 4(r31);
/* 8010504C 7FA4EB78 */  mr       r4, r29;
/* 80105050 80BE0044 */  lwz      r5, 68(r30);
/* 80105054 81830000 */  lwz      r12, 0(r3);
/* 80105058 818C0028 */  lwz      r12, 40(r12);
/* 8010505C 7D8903A6 */  mtctr    r12;
/* 80105060 4E800421 */  bctrl;
/* 80105064 4800003C */  b        UNDEF_801050a0;
UNDEF_80105068:;
/* 80105068 807F0008 */  lwz      r3, 8(r31);
/* 8010506C 7FA4EB78 */  mr       r4, r29;
/* 80105070 38C10018 */  addi     r6, r1, 24;
/* 80105074 80BE0054 */  lwz      r5, 84(r30);
/* 80105078 81830000 */  lwz      r12, 0(r3);
/* 8010507C 80FE0044 */  lwz      r7, 68(r30);
/* 80105080 818C002C */  lwz      r12, 44(r12);
/* 80105084 7D8903A6 */  mtctr    r12;
/* 80105088 4E800421 */  bctrl;
/* 8010508C 48000014 */  b        UNDEF_801050a0;
UNDEF_80105090:;
/* 80105090 806DADE8 */  lwz      r3, UNDEF_8042a768@sda21;
/* 80105094 7FA4EB78 */  mr       r4, r29;
/* 80105098 38A00001 */  li       r5, 1;
/* 8010509C 48090435 */  bl       UNDEF_801954d0;
UNDEF_801050a0:;
/* 801050A0 80010044 */  lwz      r0, 68(r1);
/* 801050A4 83E1003C */  lwz      r31, 60(r1);
/* 801050A8 83C10038 */  lwz      r30, 56(r1);
/* 801050AC 83A10034 */  lwz      r29, 52(r1);
/* 801050B0 7C0803A6 */  mtlr     r0;
/* 801050B4 38210040 */  addi     r1, r1, 64;
/* 801050B8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x801050E0)]]
void dWmSeManager_c::playPlyVoice(
  WmPlyVoice_e voice, dPyMdlMng_c::ModelType_e player, PLAYER_MODE_e playerMode
)
{
    SndObjctPly::PLAYER_VOICE_e voiceId = getPlyVoiceId(voice);
    if (voiceId == SndObjctPly::PLAYER_VOICE_e::COUNT) {
        return;
    }

    int plyIndex = static_cast<int>(daPyMng_c::getModelPlayerType(player));
    dAudio::SndObjctCSPly_c* playerSound = mpObjCSPlyArray[plyIndex];

    playerSound->mSoundPlyMode = getSoundPlyMode(playerMode);
    playerSound->startVoiceSound(voiceId, 0);
}

[[nsmbw(0x80105170)]]
void dWmSeManager_c::playPlySound(
  WmSound_e sound, dPyMdlMng_c::ModelType_e player, PLAYER_MODE_e playerMode, f32 param4
)
{
    SndID::Type soundId = getSoundId(sound);
    if (soundId == SndID::SE_DEMO_OP_DUMMY_U) {
        return;
    }

    int plyIndex = static_cast<int>(daPyMng_c::getModelPlayerType(player));
    dAudio::SndObjctCSPly_c* playerSound = mpObjCSPlyArray[plyIndex];

    playerSound->mSoundPlyMode = getSoundPlyMode(playerMode);

    WmSoundType_e soundType = getSoundType(sound);
    if (soundType == WmSoundType_e::PLAYER) {
        if (sound == WmSound_e::PLY_JUMP) {
            if (playerMode == PLAYER_MODE_e::NONE) {
                soundId = getSoundId(WmSound_e::PLY_JUMP_S);
            } else if (playerMode == PLAYER_MODE_e::MINI_MUSHROOM) {
                soundId = getSoundId(WmSound_e::PLY_JUMP_SS);
            }
        } else if (sound == WmSound_e::PLY_LAND_POINT &&
                   playerMode == PLAYER_MODE_e::PENGUIN_SUIT) {
            soundId = getSoundId(WmSound_e::PLY_LAND_PNGN);
        }

        playerSound->startSound(soundId, 0);
    } else if (soundType == WmSoundType_e::FOOTNOTE) {
        if (playerMode == PLAYER_MODE_e::PENGUIN_SUIT) {
            soundId = getSoundId(WmSound_e::PLY_FOOTNOTE_PNGN);
        }
        playerSound->startFootSound(soundId, param4, 0);
    }
}

[[nsmbw(0x801057D0)]]
u32 dWmSeManager_c::getSoundId(WmSound_e sound) const;

[[nsmbw(0x80105B30)]]
dWmSeManager_c::WmSoundType_e dWmSeManager_c::getSoundType(WmSound_e sound) const;

[[nsmbw(0x80105BC0)]]
SndObjctPly::PLAYER_VOICE_e dWmSeManager_c::getPlyVoiceId(WmPlyVoice_e voice) const;

[[nsmbw(0x80105CA0)]]
s32 dWmSeManager_c::getSoundPlyMode(PLAYER_MODE_e playerMode) const;

[[nsmbw(0x80105D20)]]
u32 dWmSeManager_c::getBossSoundId(WmSound_e sound) const;
