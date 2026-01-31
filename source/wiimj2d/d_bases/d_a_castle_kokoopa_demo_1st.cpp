// d_a_castle_kokoopa_demo_1st.cpp
// NSMBW d_bases.text: 0x807DAC10 - 0x807DCD80

#include "d_a_castle_kokoopa_demo_1st.h"

#include "d_player/d_a_player.h"
#include "d_system/d_a_player_demo_manager.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_block_mng.h"
#include "d_system/d_enemy_manager.h"
#include <algorithm>
#include <egg/math/eggMath.h>

[[nsmbw(0x807DAC10)]]
daCastleKokoopaDemo1st_c* daCastleKokoopaDemo1st_c_classInit()
{
    auto* base = new daCastleKokoopaDemo1st_c();

    // This should be done in create
    for (int i = 0; i < PLAYER_COUNT; i++) {
        base->mpPlayersInOrder[i] = nullptr;
        base->mBattleStControlStep[i] = 1;
        base->mIggyDemoScrollStep[i] = 1;
    }

    return base;
}

daCastleKokoopaDemo1st_c::daCastleKokoopaDemo1st_c() ASM_METHOD(
  // clang-format off
/* 807DAC10 9421FFE0 */  stwu     r1, -32(r1);
/* 807DAC14 7C0802A6 */  mflr     r0;
/* 807DAC1C 90010024 */  stw      r0, 36(r1);
/* 807DAC20 93E1001C */  stw      r31, 28(r1);
/* 807DAC24 93C10018 */  stw      r30, 24(r1);
/* 807DAC28 93A10014 */  stw      r29, 20(r1);
/* 807DAC34 7C7E1B78 */  mr       r30, r3;
/* 807DAC3C 4B88C385 */  bl       UNDEF_80066fc0; // __ct__13dActorState_cFv
/* 807DAC40 3BE00000 */  li       r31, 0;
/* 807DAC44 93FE03D8 */  stw      r31, 984(r30);
/* 807DAC48 3C608095 */  lis      r3, UNDEF_80956f90@ha;
/* 807DAC4C 3BBE0460 */  addi     r29, r30, 1120;
/* 807DAC50 38636F90 */  addi     r3, r3, UNDEF_80956f90@l;
/* 807DAC54 907E0060 */  stw      r3, 96(r30);
/* 807DAC58 7FA3EB78 */  mr       r3, r29;
/* 807DAC5C 4BAFD135 */  bl       UNDEF_802d7d90; // __ct__Q23EGG6EffectFv
/* 807DAC60 93FD0114 */  stw      r31, 276(r29);
/* 807DAC64 3C608031 */  lis      r3, UNDEF_803111d8@ha; // __vt__Q23dEf14dLevelEffect_c
/* 807DAC68 386311D8 */  addi     r3, r3, UNDEF_803111d8@l; // __vt__Q23dEf14dLevelEffect_c
/* 807DAC6C 93FD0118 */  stw      r31, 280(r29);
/* 807DAC70 9BFD011C */  stb      r31, 284(r29);
/* 807DAC74 9BFD011D */  stb      r31, 285(r29);
/* 807DAC78 93FD0120 */  stw      r31, 288(r29);
/* 807DAC7C 93FD0124 */  stw      r31, 292(r29);
/* 807DAC80 907D0000 */  stw      r3, 0(r29);
/* 807DAC84 7FC3F378 */  mr       r3, r30;
/* 807DAC88 83E1001C */  lwz      r31, 28(r1);
/* 807DAC8C 83C10018 */  lwz      r30, 24(r1);
/* 807DAC90 83A10014 */  lwz      r29, 20(r1);
/* 807DAC94 80010024 */  lwz      r0, 36(r1);
/* 807DAC98 7C0803A6 */  mtlr     r0;
/* 807DAC9C 38210020 */  addi     r1, r1, 32;
/* 807DACA0 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x807DACB0)]]
bool daCastleKokoopaDemo1st_c::checkBattleStDemo()
{
    switch (mCheckBattleStDemoStep) {
    case 1: {
        f32 checkPos = mPos.x - 32.0;
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (isPlayerEntry(i) && daPyMng_c::getPlayer(i)->mPos.x > checkPos) {
                daPyDemoMng_c::mspInstance->startControlDemoAll();
                dBlockMng_c::m_instance->mDisableDonutLift = 1;
                dEnemyMng_c::m_instance->m0x15C = 1;
                setFlag115();
                mCheckBattleStDemoStep++;
                return false;
            }
        }
        return false;
    }

    case 2: {
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

        killPlayerFireball();
        mCheckBattleStDemoStep++;
        return false;
    }

    case 3: {
        killPlayerFireball();
        calcBattleStDemoControl();
        return true;
    }
    }

    return false;
}

[[nsmbw(0x807DB440)]]
bool daCastleKokoopaDemo1st_c::calcBattleStDemoControl()
{
    int numPly = daPyMng_c::mNum;

    f32 playerStandArea = EGG::Math<f32>::lerp(f32(numPly - 4) / 4.0, 96.0, 140.0);
    f32 playerDist = playerStandArea / (numPly + 1);

    for (int i = 0; i < numPly; i++) {
        dAcPy_c* player = mpPlayersInOrder[i];

        switch (mBattleStControlStep[i]) {
        case 1: {
            f32& walkToPos = mWalkToPos[player->getPlrNo()];
            walkToPos = playerDist * (i + 1) + (mRightBoundary - playerStandArea / 2);

            if (!(player->m0x10D4 & 0x1)) {
                continue;
            }

            f32 xSpeed = player->mSpeed.x;
            if (xSpeed <= 0.0) {
                xSpeed = -xSpeed;
            }

            if (i >= numPly - 1) {
                f32 speed = EGG::Math<f32>::lerp(0.1, xSpeed, 2.5);
                player->setControlDemoWalk(walkToPos, speed);
                if (speed == 2.5) {
                    mBattleStControlStep[i]++;
                }
            } else if (mpPlayersInOrder[i + 1]->mPos.x - player->mPos.x < 24.0) {
                f32 speed = EGG::Math<f32>::lerp(0.1, xSpeed, 2.5 / 2);
                player->setControlDemoWalk(walkToPos, speed);
            } else {
                f32 speed = EGG::Math<f32>::lerp(0.1, xSpeed, 2.5);
                player->setControlDemoWalk(walkToPos, speed);
                if (mBattleStControlStep[i + 1] == 2 && speed == 2.5) {
                    mBattleStControlStep[i]++;
                }
            }
            break;
        }

        case 2: {
            if (player->isControlDemoWait()) {
                player->setControlDemoDir(0);
                player->setControlDemoAnm(0x91);
                mBattleStControlStep[i]++;
            }
        }
        }
    }

    return true;
}

[[nsmbw(0x807DB740)]]
bool daCastleKokoopaDemo1st_c::calcIggyDemoScroll()
{
    // Only used in World 5 Iggy castle boss

    bool ready = true;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!isPlayerEntry(i)) {
            continue;
        }

        dAcPy_c* player = daPyMng_c::getPlayer(i);

        if (mIggyDemoScrollStep[i] == 0) {
            continue;
        }

        if (mIggyDemoScrollStep[i] != 3) {
            ready = false;
        }

        switch (mIggyDemoScrollStep[i]) {
        case 1: {
            if (player->mPos.x < mLeftBoundary - 168.0) {
                break;
            }

            player->mKey.onDemoButton(0x104);
            player->setControlDemoWalk(mWalkToPos[player->getPlrNo()], 1.5);
            mIggyDemoScrollStep[i]++;
            break;
        }

        case 2: {
            f32 yDist = 112.0;
            if (player->mPlayerMode == PLAYER_MODE_e::MINI_MUSHROOM) {
                yDist = 48.0;
            }

            if (player->mPos.y > mPos.y + yDist ||
                player->mPos.x >= mWalkToPos[player->getPlrNo()]) {
                player->mKey.offDemoButton(0x104);
                mIggyDemoScrollStep[i]++;
            }
            break;
        }
        }
    }

    return ready;
}

[[nsmbw(0x807DB920)]]
bool daCastleKokoopaDemo1st_c::isPlayerEntry(int player)
{
    return daPyMng_c::mActPlayerInfo & (1 << player);
}

[[nsmbw(0x807DB950)]]
void daCastleKokoopaDemo1st_c::setFlag115()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (isPlayerEntry(i)) {
            daPyMng_c::getPlayer(i)->onStatus(115);
        }
    }
}

[[nsmbw(0x807DBA20)]]
void daCastleKokoopaDemo1st_c::killPlayerFireball();

// 0x807DBB20: daCastleKokoopaDemo1st_c::executeState_BattleStDemo patched in Four

// 0x807DBF70: daCastleKokoopaDemo1st_c::executeState_BattleEdDemo patched in Four
