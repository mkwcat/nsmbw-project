// d_balloon_mng.cpp
// NSMBW .text: 0x8006C0B0 - 0x8006C420

#include "d_balloon_mng.h"

#include "d_player/d_a_en_hatena_balloon.h"
#include "d_player/d_a_player.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_boss_demo.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_actor.h"
#include "d_system/d_actor_mng.h"
#include "d_system/d_actorcreate_mng.h"
#include "d_system/d_enemy_boss.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "egg/math/eggMath.h"
#include "framework/f_feature.h"
#include "framework/f_manager.h"
#include "framework/f_param.h"
#include <cstddef>
#include <iterator>

[[nsmbw_data(0x8042A068)]]
dBalloonMng_c* dBalloonMng_c::m_instance;

[[nsmbw(0x8006C0B0)]]
void dBalloonMng_c::BalloonInfoClear()
{
    *this = {};
}

[[nsmbw(0x8006C0E0)]]
void dBalloonMng_c::setItemId(fBaseID_e id)
{
    for (std::size_t item = 0; item < std::size(mItemId); item++) {
        if (mItemId[item] == fBaseID_e::NONE) {
            mItemId[item] = id;
            return;
        }
    }
}

[[nsmbw(0x8006C120)]]
bool dBalloonMng_c::item_max_check()
{
    std::size_t count = 0;
    for (std::size_t item = 0; item < std::size(mItemId); item++) {
        if (mItemId[item] != fBaseID_e::NONE && !fManager_c::searchBaseByID(mItemId[item])) {
            mItemId[item] = fBaseID_e::NONE;
        } else if (mItemId[item] != fBaseID_e::NONE) {
            count++;
        }
    }
    return count == std::size(mItemId);
}

[[nsmbw(0x8006C1C0)]]
void dBalloonMng_c::execute()
{
    if (mBossDead) {
        return;
    }

    if (dActorCreateMng_c::m_instance->mIsEndingDemo) {
        return;
    }

    if (daBossDemo_c* bossDemo = dActorMng_c::m_instance->mpBossDemo) {
        if (dEnBoss_c* boss =
              static_cast<dEnBoss_c*>(fManager_c::searchBaseByID(bossDemo->mBossId));
            boss && boss->mpBossLife->mLife <= 0) {
            mBossDead = true;
            return;
        }
    }

    if (fFeat::bubble_swarm_mode) {
        return execute1UpSwarm();
    }

    if (!(dInfo_c::mGameFlag & 0x10) || daPyMng_c::isOnePlayerInGame()) {
        return;
    }

    if (mPlyAvailable == false) {
        for (int ply = 0; ply < PLAYER_COUNT; ply++) {
            if (!daPyMng_c::isPlayerActive(ply)) {
                continue;
            }

            if (dAcPy_c* player = daPyMng_c::getPlayer(ply);
                player && (player->isStatus(4) || player->isChange())) {
                mPlyAvailable = true;
            }
        }
        return;
    }

    if (++mCreateTimer >= TIMER_MAX) {
        mCreateTimer = TIMER_MAX;
    }

    if (mLastBalloonId != fBaseID_e::NONE && fManager_c::searchBaseByID(mLastBalloonId)) {
        return;
    }
    mLastBalloonId = fBaseID_e::NONE;

    if (item_max_check()) {
        return;
    }

    int noPowerPlayersCount = 0;
    for (int ply = 0; ply < PLAYER_COUNT; ply++) {
        if (!daPyMng_c::isPlayerActive(ply)) {
            continue;
        }
        if (dAcPy_c* player = daPyMng_c::getPlayer(ply);
            player && player->mPlayerMode == PLAYER_MODE_e::NONE) {
            noPowerPlayersCount++;
        }
    }

    int timer;
    if (noPowerPlayersCount == 0) {
        return;
    } else if (noPowerPlayersCount == 1) {
        timer = 1200;
    } else if (noPowerPlayersCount == 2) {
        timer = 900;
    } else {
        timer = 600;
    }
    if (mCreateTimer < timer) {
        return;
    }

    if (dActor_c* balloon = dActor_c::construct(
          dProf::EN_HATENA_BALLOON, fParam_c<daEnHatenaBalloon_c>({.has_item = 1}),
          (const mVec3_c[1]) {{0.0f, 0.0f, 7300.0f}}, nullptr, 0
        )) {
        mLastBalloonId = balloon->mUniqueID;
    }
}

void dBalloonMng_c::execute1UpSwarm()
{
    if (mNoCloneTimer != 0) {
        mNoCloneTimer--;
    }

    int rampUp =
      EGG::Math<int>().lerp(float(mTotalTimer++) / float(SWARM_TIMER_MAX), 60 * 16, 60 * 4);
    if (++mSwarmTimer < rampUp && mSwarmTimer != 1) {
        return;
    }
    mSwarmTimer = 1;

    createSwarmBalloon();
}

void dBalloonMng_c::createSwarmBalloon()
{
    if (dActor_c* balloon = dActor_c::construct(
          dProf::EN_HATENA_BALLOON,
          fParam_c<daEnHatenaBalloon_c>(
            {.item_type = static_cast<u32>(ITEM_e::ONE_UP), .has_item = 1}
          ),
          (const mVec3_c[1]) {{0.0f, 0.0f, 7300.0f}}, nullptr, 0
        )) {
        mLastBalloonId = balloon->mUniqueID;
    }
}

void dBalloonMng_c::popAll()
{
    mNoCloneTimer = 60;

    for (fBase_c* base = nullptr;
         (base = fManager_c::searchBaseByProfName(dProf::EN_HATENA_BALLOON, base));) {
        auto* balloon = dProf::cast<daEnHatenaBalloon_c>(base);
        if (!balloon) {
            continue;
        }
        balloon->PlYsHitCheck(balloon, balloon);
        balloon->mBalloonPopPos = balloon->getCenterPos();
        balloon->mPopReady = true;
    }

    createSwarmBalloon();

    mSwarmTimer = 1;
}