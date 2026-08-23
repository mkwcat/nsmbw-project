// d_a_last_actor_stage.cpp
// NSMBW d_bases.text: 0x80830690 - 0x80830C40

#include "d_a_last_actor_stage.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_WarningManager.h"
#include "d_player/d_a_player.h"
#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_actor/d_actor.h"
#include "d_static/d_actor/d_actor_mng.h"
#include "d_static/d_actorcreate_mng.h"
#include "d_static/d_attention.h"
#include "d_static/d_balloon_mng.h"
#include "d_static/d_beans_kuribo_mng.h"
#include "d_static/d_bg/d_bg_ctr.h"
#include "d_static/d_cc.h"
#include "d_static/d_coin.h"
#include "d_static/d_ef/d_effactor_mng.h"
#include "d_static/d_enemy/d_enemy_manager.h"
#include "d_static/d_game_common.h"
#include "d_static/d_game_key/d_game_key.h"
#include "d_static/d_game_key/d_game_key_core.h"
#include "d_static/d_next.h"
#include "d_static/d_pause_manager.h"
#include "d_static/d_remocon_mng.h"
#include "d_static/d_stage_timer.h"
#include "d_static/d_switchflag_mng.h"
#include "d_static/d_tencoin_mng.h"
#include "machine/m_fader.h"
#include "sound/SndAudioMgr.h"
#include <revolution/vi.h>

[[nsmbw(0x80830690)]]
daLastActorStage_c* daLastActorStage_c_classInit()
{
    return new daLastActorStage_c();
}

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x808306E0)]]
fBase_c::PACK_RESULT_e daLastActorStage_c::create()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mBtnPressed[i] = 0;
        mIsShaking[i] = false;
    }

    return PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[nsmbw(0x80830710)]]
fBase_c::PACK_RESULT_e daLastActorStage_c::doDelete();

/**
 * VT+0x20
 * do method for the execute operation.
 */
[[nsmbw(0x80830720)]]
fBase_c::PACK_RESULT_e daLastActorStage_c::execute()
{
    if (!dGameCom::isGameStop(0xFFFFFFFF)) {
        if (mFader_c::isStatus(mFader_c::EStatus::HIDDEN)) {
            dSwitchFlagMng_c::m_instance->execute();
            dCoin_c::execute();
            dBeansKuriboMng_c::m_instance->clear();
            dActorMng_c::m_instance->execute();
            dBalloonMng_c::m_instance->execute();
            dTenCoinMng_c::m_instance->execute();
        }

        dEffActorMng_c::m_instance->execute();
        dAttention_c::mspInstance->update();
        dStageTimer_c::m_instance->execute();
        dNext_c::m_instance->execute();
        daPyMng_c::executeLastPlayer();
        dCc_c::execute();
        dBg_ctr_c::updateObjBg();
        daPyMng_c::executeLastAll();
        dActorMng_c::m_instance->finalUpdate();
        dActorCreateMng_c::m_instance->execute();

        dEnemyMng_c::m_instance->m0x138 = 0;
        dEnemyMng_c::m_instance->execute();
        if (dEnemyMng_c::m_instance->mPokeyTimer > 0) {
            dEnemyMng_c::m_instance->mPokeyTimer--;
        }

        daPyMng_c::update();
    }

    dGameKey_c* gameKey = dGameKey_c::m_instance;

    if (dActor_c::mExecStop & 0x2) {
        bool isChange = false;

        for (int i = 0; i < PLAYER_COUNT; i++) {
            dAcPy_c* player = daPyMng_c::getPlayer(i);

            if (player != nullptr && player->isChange()) {
                isChange = true;
                break;
            }
        }

        if (isChange) {
            for (int i = 0; i < PLAYER_COUNT; i++) {
                mBtnPressed[i] |= gameKey->mpCores[i]->mTriggered;
                if (gameKey->mpCores[i]->mShake) {
                    mIsShaking[i] = true;
                }
            }
        }
    }

    if (!dGameCom::isGameStop(0xFFFFFFFF) && !(dActor_c::mExecStop & 0x2)) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mBtnPressed[i] != 0) {
                gameKey->mpCores[i]->m0x30 = gameKey->mpCores[i]->mHeld & mBtnPressed[i];
                mBtnPressed[i] = 0;
            }
            gameKey->mpCores[i]->mShakeOld = mIsShaking[i];
            mIsShaking[i] = false;
        }
    }

    SndAudioMgr::sInstance->setIsReplay(
      dScStage_c::m_gameMode != dScStage_c::GAME_MODE_e::UNKNOWN_0
    );

    if (!dScStage_c::isNowReplay()) {
        dScStage_c::m_replayMode &= ~1;

        if (dScStage_c::m_gameMode != dScStage_c::GAME_MODE_e::UNKNOWN_0 &&
            dScStage_c::m_gameMode != dScStage_c::GAME_MODE_e::UNKNOWN_2 &&
            !dScStage_c::m_isReplayGoal) {
            dScStage_c::m_gameMode = dScStage_c::GAME_MODE_e::UNKNOWN_0;
            if (dWarningManager_c::m_WarningForbid > 0) {
                dWarningManager_c::m_WarningForbid--;
            }

            for (int i = 0; i < PLAYER_COUNT; i++) {
                dRemoconMng_c::m_instance->mpConnect[i]->onRumbleEnable();
            }

            VIEnableDimming(1);
        }
    }

    if (!dGameCom::isGameStop(0xFFFFFFFF) && !(dActor_c::mExecStop & 0xF)) {
        if (mFader_c::isStatus(mFader_c::EStatus::HIDDEN)) {
            dScStage_c::m_exeFrame++;
        }
    }

    PauseManager_c::m_instance->setPause();

    return PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x2C
 * do method for the draw operation.
 */
[[nsmbw(0x80830BB0)]]
fBase_c::PACK_RESULT_e daLastActorStage_c::draw();
