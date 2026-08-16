// d_a_boss_koopa_jr_demo.cpp
// NSMBW d_bases.text: 0x807D0070 - 0x807D2AC0

#include "d_a_boss_koopa_jr_demo.h"

#include "d_bases/d_a_jr_clown_for_player.h"
#include "d_player/d_a_player.h"
#include "d_player/d_bg_gm.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_bg.h"
#include "d_system/d_bg_parameter.h"
#include "d_system/d_cc.h"
#include "d_system/d_util.h"
#include <algorithm>
#include <mkwcat/Relocate.hpp>

[[nsmbw(0x807D0070)]]
daBossKoopaJrDemo_c* daBossKoopaJrDemo_c_classInit() {
    return new daBossKoopaJrDemo_c;
}

daBossKoopaJrDemo_c::daBossKoopaJrDemo_c() ASM_METHOD(
  // clang-format off
/* 807D0070 9421FFF0 */  stwu     r1, -16(r1);
/* 807D0074 7C0802A6 */  mflr     r0;
/* 807D007C 90010014 */  stw      r0, 20(r1);
/* 807D0080 93E1000C */  stw      r31, 12(r1);
/* 807D008C 7C7F1B78 */  mr       r31, r3;
/* 807D0094 4B896F2D */  bl       UNDEF_80066fc0;
/* 807D0098 38000000 */  li       r0, 0;
/* 807D009C 901F03D8 */  stw      r0, 984(r31);
/* 807D00A0 3C808095 */  lis      r4, UNDEF_80955024@ha;
/* 807D00A4 387F043C */  addi     r3, r31, 1084;
/* 807D00A8 38845024 */  addi     r4, r4, UNDEF_80955024@l;
/* 807D00AC 909F0060 */  stw      r4, 96(r31);
/* 807D00B0 4B917C01 */  bl       UNDEF_800e7cb0;
UNDEF_807d00b4:;
/* 807D00B4 7FE3FB78 */  mr       r3, r31;
/* 807D00B8 83E1000C */  lwz      r31, 12(r1);
/* 807D00BC 80010014 */  lwz      r0, 20(r1);
/* 807D00C0 7C0803A6 */  mtlr     r0;
/* 807D00C4 38210010 */  addi     r1, r1, 16;
/* 807D00C8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x807D00D0)]]
void daBossKoopaJrDemo_c::initialize() {
    static const mVec3_c sc_doomship_offset[] = {
        {28.0f, 16.0f, -5.5f},
        {28.0f, 16.0f, -8.5f},
        {28.0f, 16.0f, -9.0f},
        {22.0f, 10.0f, -2.5f},
    };

    mDemoNum      = mParam & 0xF;
    mAirshipDemoX = mXBased = mPos.x + sc_doomship_offset[mDemoNum].x / 2.0f * 16.0f;
    mAirshipDemoY           = mPos.y - sc_doomship_offset[mDemoNum].y / 2.0f * 16.0f;
    mPlayerStandCenter      = mXBased + sc_doomship_offset[mDemoNum].z * 16.0f;

    m0x404                  = 0;

    int numPly              = daPyMng_c::mNum;
    f32 playerStandArea     = EGG::Math<f32>::lerp(f32(numPly - 4) / 4.0f, 96.0f, 140.0f);
    f32 playerDist          = playerStandArea / (numPly + 1);
    f32 playerStandRight    = mPlayerStandCenter + playerStandArea / 2;

    int i;
    for (i = 0; i < PLAYER_COUNT; i++) {
        mpPlayersInOrder[i] = nullptr;
        mPlrYPos[i]         = -100000.0f;
        m0x438[i]           = false;
        if (i < numPly) {
            mPlayerWalkPos[i] = playerStandRight - playerDist * (i + 1);
        } else {
            mPlayerWalkPos[i] = mXBased;
        }
    }

    m0x418  = 0;
    m0x41C  = 0;
    mpKamek = nullptr;
    mpPeach = nullptr;

    mpKamek = static_cast<daKameckForAirshipDemo_c*>(dActor_c::construct(
        dProf::KAMECK_FOR_AIRSHIP_DEMO, this, 0,
        (const mVec3_c[]) {{mAirshipDemoX, mAirshipDemoY, 3256.0f}}, nullptr, 0
    ));
    if (mDemoNum == 3) {
        auto* bg            = dBg_c::m_bg_p;
        bg->m0x00110        = m0x418;
        bg->m0x00114        = 18;
        mpPeach             = static_cast<daPeachForAirshipDemo_c*>(dActor_c::construct(
            dProf::PEACH_FOR_AIRSHIP_DEMO, this, 0,
            (const mVec3_c[]) {{mAirshipDemoX + 2.5f * 16.0f, mAirshipDemoY, 3256.0f}}, nullptr, 0
        ));
        mpKamek->mBossDemoX = mpPeach->mPos.x;
        dActor_c::construct(
            dProf::KOOPA_SHIP_FOR_AIRSHIP_DEMO, this, 0,
            (const mVec3_c[]) {{mAirshipDemoX + 2.5f * 16.0f, mAirshipDemoY - 56.0f, 0.0f}},
            nullptr, 0
        );
    }

    mpFirstPlr = nullptr;
    mBaseX2    = 0;
    mBaseX     = 0;
    mScreenTop = 0;
    mBaseY     = 0;
    m0x484     = 0;
}

[[nsmbw(0x807D03B0)]]
void daBossKoopaJrDemo_c::sortPlayers() {
    int count = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!isPlayerEntry(i)) {
            continue;
        }

        mpPlayersInOrder[count++] = daPyMng_c::getPlayer(i);
    }

    // Sort the players by X position
    std::sort(mpPlayersInOrder, mpPlayersInOrder + count, [](dAcPy_c* a, dAcPy_c* b) {
        return a->mPos.x < b->mPos.x;
    });
}

[[nsmbw(0x807D0490)]]
void daBossKoopaJrDemo_c::calcPlayerWalkPos() {
    int numPly          = daPyMng_c::mNum;
    f32 playerStandArea = EGG::Math<f32>::lerp(f32(numPly - 4) / 4.0f, 96.0f, 140.0f);
    f32 playerDist      = playerStandArea / (numPly + 1);

    int i;
    for (i = 0; i < PLAYER_COUNT; i++) {
        if (i < numPly) {
            mPlayerWalkPos[i] = mPlayerStandCenter - playerDist * i;
            mpPlayersInOrder[numPly - i - 1]->setControlDemoWalk(mPlayerWalkPos[i], 2.4f);
        } else {
            mPlayerWalkPos[i] = mXBased;
        }
    }

    mpFirstPlr = mpPlayersInOrder[numPly - 1];
}

[[nsmbw(0x807D0800)]]
bool daBossKoopaJrDemo_c::isPlayerEntry(
    int player
) {
    return daPyMng_c::mActPlayerInfo & (1 << player);
}

[[nsmbw(0x807D0910)]]
bool daBossKoopaJrDemo_c::checkRestart();

[[nsmbw(0x807D1570)]]
void daBossKoopaJrDemo_c::initializeState_BattleStDemo() {
    mpFirstPlr = daPyMng_c::getPlayer(daPyMng_c::getCourseInListPlrNo(0));
    mScreenTop = mBaseY = dBgParameter_c::ms_Instance_p->mScreenTop;

    float sizeY         = 224.0f;
    if (mDemoNum == 2) {
        if (!checkRestart()) {
            mBaseX2 = mBaseX = 6182.0f;
            sizeY            = 168.0f;
        }
        m0x360 = 0;
    } else {
        m0x360 = 1;
    }

    mDisp.setBaseY(mBaseY);
    mScreenTopCopy = mScreenTop;
    mBaseYCopy     = mBaseY;

    mDisp.setSizeY(sizeY);
    mSizeY = sizeY;
    m0x44C = 272.0f;

    if (mDemoNum == 2 && !checkRestart()) {
        mDisp.setBaseX(mBaseX);
        mBaseXCopy = mBaseX;
    }

    if (daPyMng_c::mNum > 4) {
        // Temporarily disable collision for player clown cars
        for (fBase_c* base = nullptr;
             (base = fManager_c::searchBaseByProfName(dProf::JR_CLOWN_FOR_PLAYER, base));) {
            daJrClownForPlayer_c* actor  = static_cast<daJrClownForPlayer_c*>(base);
            actor->mCc.mAmiLine          = 0;
            actor->mPlrCollider.mAmiLine = 0;
        }
    }
}

[[nsmbw(0x807D1690)]]
void daBossKoopaJrDemo_c::finalizeState_BattleStDemo() {
    if (daPyMng_c::mNum > 4) {
        // Restore collision for player clown cars
        for (fBase_c* base = nullptr;
             (base = fManager_c::searchBaseByProfName(dProf::JR_CLOWN_FOR_PLAYER, base));) {
            daJrClownForPlayer_c* actor  = static_cast<daJrClownForPlayer_c*>(base);
            actor->mCc.mAmiLine          = 0x01;
            actor->mPlrCollider.mAmiLine = 0x1D;
        }
    }
}

PATCH_REFERENCES(
    offsetof(daBossKoopaJrDemo_c, mPlayerWalkPos), //
    {
        {0x807D0620 + 2, R_PPC_ADDR16_LO},

        {0x807D0688 + 2, R_PPC_ADDR16_LO},

        {0x807D0728 + 2, R_PPC_ADDR16_LO},
        {0x807D0748 + 2, R_PPC_ADDR16_LO},

        {0x807D0A84 + 2, R_PPC_ADDR16_LO},

        {0x807D0D64 + 2, R_PPC_ADDR16_LO},

        {0x807D10B4 + 2, R_PPC_ADDR16_LO},

    }
);

PATCH_REFERENCES(
    offsetof(daBossKoopaJrDemo_c, mpPlayersInOrder), //
    {
        {0x807D063C + 2, R_PPC_ADDR16_LO},

        {0x807D0758 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daBossKoopaJrDemo_c, mPlrYPos), //
    {
        {0x807D1938 + 2, R_PPC_ADDR16_LO},
    }
);

PATCH_REFERENCES(
    offsetof(daBossKoopaJrDemo_c, m0x438), //
    {
        {0x807D1B40 + 2, R_PPC_ADDR16_LO},
        {0x807D1B68 + 2, R_PPC_ADDR16_LO},
    }
);
