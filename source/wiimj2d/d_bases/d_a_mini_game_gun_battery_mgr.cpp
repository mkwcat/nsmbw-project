// d_a_mini_game_gun_battery_mgr.cpp
// NSMBW d_bases.text: 0x808660F0 - 0x808672B0

#include "d_a_mini_game_gun_battery_mgr.h"

#include "d_bases/d_s_stage.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "machine/m_fader.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"
#include "sound/SndSceneMgr.h"

[[nsmbw(0x80866120)]]
daMiniGameGunBatteryMgrObj_c* daMiniGameGunBatteryMgrObj_c_classInit()
{
    return new daMiniGameGunBatteryMgrObj_c();
}

[[nsmbw(0x80866210)]]
daMiniGameGunBatteryMgrObj_c::daMiniGameGunBatteryMgrObj_c()
  : mStateMgr(*this, StateID_ShowRule)
{
}

[[nsmbw(0x80866450)]]
fBase_c::PACK_RESULT_e daMiniGameGunBatteryMgrObj_c::create();

[[nsmbw(0x808664B0)]]
fBase_c::PACK_RESULT_e daMiniGameGunBatteryMgrObj_c::preExecute();

[[nsmbw(0x808664F0)]]
fBase_c::PACK_RESULT_e daMiniGameGunBatteryMgrObj_c::execute();

[[nsmbw(0x80866530)]]
void daMiniGameGunBatteryMgrObj_c::hitBalloon(int player, int lives)
{
    mPlayers[player].mNumLives += lives;
    mPlayers[player].mNumHit++;
}

[[nsmbw(0x80866560)]]
void daMiniGameGunBatteryMgrObj_c::addResultRest()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (dAcPy_c* player = daPyMng_c::getPlayer(i); player && mPlayers[i].mNumLives > 0) {
            daPyMng_c::addRest(player->getPlrNo(), mPlayers[i].mNumLives, false);
        }
    }
}

[[nsmbw(0x808665F0)]]
bool daMiniGameGunBatteryMgrObj_c::checkMessageClose();

[[nsmbw(0x80866640)]]
void daMiniGameGunBatteryMgrObj_c::setMessageCloseWait(int value)
{
    mMessageCloseWaitTimer = value;
}

[[nsmbw(0x80866650)]]
void daMiniGameGunBatteryMgrObj_c::setPlayerDone(int player)
{
    if (player == -1 || mPlayers[player].mDone) {
        return;
    }

    mPlayers[player].mDone = true;
    mNumDone++;
}

[[nsmbw(0x808666E0)]]
void daMiniGameGunBatteryMgrObj_c::executeState_ShowRule()
{
    bool closed;

    switch (mMessageState) {
    case 0:
        if (--mMessageTimer > 0 || !mFader_c::mFader->isStatus(mFaderBase_c::EStatus::HIDDEN)) {
            break;
        }

        dGameCom::MiniGameCannonTitle();

        mMessageState = 1;
        mMessageTimer = 150;
        break;

    case 1:
        if (--mMessageTimer > 0) {
            break;
        }

        dGameCom::MiniGameCannonTitleCloseRequest();

        mMessageState = 2;
        mMessageTimer = 0;
        break;

    case 2:
        if (dGameCom::MiniGameCannonEndCheck()) {
            break;
        }

        dGameCom::MiniGameCannonStart();
        SndSceneMgr::sInstance->setMiniGameTrack(2);
        SndAudioMgr::sInstance->startSystemSe(SndID::SE_MG_CMN_WIN_T_OPEN, 2);

        mMessageState = 3;
        mMessageTimer = 480;
        setMessageCloseWait(61);
        break;

    case 3:
        closed = checkMessageClose();
        if (--mMessageTimer > 0 && !closed) {
            break;
        }

        dGameCom::MiniGameCannonOperateCloseRequest();
        SndAudioMgr::sInstance->startSystemSe(
          closed ? SndID::SE_MG_CMN_WIN_CLK : SndID::SE_MG_CMN_WIN_CLOSE, 1
        );

        mMessageState = 4;
        mMessageTimer = 0;
        break;

    case 4:
        if (dGameCom::MiniGameCannonEndCheck()) {
            break;
        }

        mStateMgr.changeState(StateID_Play);

        mMessageState = 5;
        mMessageTimer = 0;
        break;
    }
}

[[nsmbw(0x80866A90)]]
void daMiniGameGunBatteryMgrObj_c::executeState_ShowResult()
{
    bool win, closed;

    switch (mMessageState) {
    case 0:
        if (--mMessageTimer > 0) {
            break;
        }

        mMessageState = 1;
        mMessageTimer = 50;
        break;

    case 1:
        if (--mMessageTimer > 0) {
            break;
        }

        m0xE0 = 0;
        dGameCom::MiniGameCannonResult();

        win = false;
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayers[i].mNumLives > 0) {
                win = true;
                break;
            }
        }

        SndSceneMgr::sInstance->setMiniGameTrack(win ? 10 : 9);
        SndAudioMgr::sInstance->startSystemSe(
          win ? SndID::SE_MG_UH_NICE : SndID::SE_MG_UH_WIN_BR_OPEN, 1
        );

        mMessageState = 2;
        mMessageTimer = 300;
        break;

    case 2:
        closed = checkMessageClose();
        if (--mMessageTimer > 0 && !closed) {
            break;
        }

        dGameCom::MiniGameCannonResultCloseRequest();
        SndAudioMgr::sInstance->startSystemSe(
          closed ? SndID::SE_MG_CMN_WIN_CLK : SndID::SE_MG_CMN_WIN_CLOSE, 1
        );

        mMessageState = 3;
        mMessageTimer = 0;
        break;

    case 3:
        if (dGameCom::MiniGameCannonEndCheck()) {
            break;
        }

        dScStage_c::goToSceneAfterLevel(
          dProf::WORLD_MAP, 0, 0, dFader_c::fader_type_e::MARIO
        );

        mMessageState = 4;
    }
}

[[nsmbw(0x80866CF0)]]
daMiniGameGunBatteryMgrObj_c::~daMiniGameGunBatteryMgrObj_c()
{
}
