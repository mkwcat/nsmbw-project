// d_s_GameSetup.cpp
// NSMBW d_bases.text: 0x80917960 - 0x8091A2F0

#include "d_s_GameSetup.h"

#include "d_bases/d_CharacterChangeIndicator.h"
#include "d_bases/d_CharacterChangeSelectArrow.h"
#include "d_bases/d_CharacterChangeSelectBase.h"
#include "d_bases/d_CharacterChangeSelectContents.h"
#include "d_bases/d_DateFile.h"
#include "d_bases/d_EasyPairing.h"
#include "d_bases/d_FileSelect.h"
#include "d_bases/d_InfoWindow.h"
#include "d_bases/d_NumberOfPeopleChange.h"
#include "d_bases/d_SelectPlayer.h"
#include "d_bases/d_SequenceBG.h"
#include "d_bases/d_a_wm_2DPlayer.h"
#include "d_bases/d_s_restart_crsin.h"
#include "d_bases/d_s_world_map.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_base_actor.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_base.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_scene.h"
#include "framework/f_feature.h"
#include "machine/m_dvd.h"
#include "sound/SndSceneMgr.h"

[[nsmbw(0x80917A70)]]
bool dScGameSetup_c::Phase_LinkProfiles();

[[nsmbw(0x80917C80)]]
bool dScGameSetup_c::Phase_CreateLayoutManagers()
{
#define NEW(_TYPE, _PROFILE, _PARAM)                                                               \
    static_cast<_TYPE>(fBase_c::createChild(dProf::_PROFILE, this, _PARAM, 0))

    mpNumPyChg = NEW(dNumberOfPeopleChange_c*, NUMBER_OF_PEOPLE_CHANGE, 0);

    for (std::size_t cc = 0; cc < mpNumPyChg->mCcCount; cc++) {
        mpNumPyChg->mpCcSelBase[cc] =
          NEW(dCharacterChangeSelectBase_c*, CHARACTER_CHANGE_SELECT_BASE, cc);
        mpNumPyChg->mpCcSelContents[cc] =
          NEW(dCharacterChangeSelectContents_c*, CHARACTER_CHANGE_SELECT_CONTENTS, cc);
        mpNumPyChg->mpCcSelArrow[cc] =
          NEW(dCharacterChangeSelectArrow_c*, CHARACTER_CHANGE_SELECT_ARROW, cc);
        mpNumPyChg->mpCcIndicator[cc] =
          NEW(dCharacterChangeIndicator_c*, CHARACTER_CHANGE_INDICATOR, cc);
    }

    mpSelectPlayer = NEW(dSelectPlayer_c*, SELECT_PLAYER, 0);
    mpEasyPairing = NEW(dEasyPairing_c*, EASY_PAIRING, 0);
    mpSequenceBG = NEW(dSequenceBG_c*, SEQUENCE_BG, 0);

    mpFileSelect = NEW(dFileSelect_c*, FILE_SELECT, mParam);
    for (std::size_t i = 0; i < std::size(mpDateFile); i++) {
        mpFileSelect->mpDateFile[i] = mpDateFile[i] = NEW(dDateFile_c*, DATE_FILE, i);
    }
    mpFileSelect->mpInfoWindow = mpInfoWindow = NEW(dInfoWindow_c*, INFO_WINDOW, 0);

    return true;
#undef NEW
}

[[nsmbw(0x80917EB0)]]
bool dScGameSetup_c::Phase_Create2DPlayer()
{
    da2DPlayer_c* player = static_cast<da2DPlayer_c*>(
      dBaseActor_c::construct(dProf::WM_2D_PLAYER, this, mPlayerCreateIdx, nullptr, nullptr)
    );
    if (player == nullptr) {
        return false;
    }

    if (mPlayerCreateIdx < std::size(mpa2DPlayer)) {
        mpa2DPlayer[mPlayerCreateIdx] = player;
    }
    mpNumPyChg->mp2DPlayer[static_cast<PLAYER_TYPE_e>(mPlayerCreateIdx)] = player;

    if (++mPlayerCreateIdx < CHARACTER_LIST_COUNT) {
        return false;
    }

    mPlayerCreateIdx = 0;
    return true;
}

[[nsmbw(0x80918450)]]
bool dScGameSetup_c::executeDateFileAnimeOut();

[[nsmbw(0x80918780)]]
void dScGameSetup_c::executeState_FileSelect()
{
    executeDateFileAnimeOut();

    if (!mpFileSelect->mChoiceDone) {
        return;
    }

    if (mpFileSelect->mChoiceBack) {
        dScRestartCrsin_c::startTitle(0, false);
        return mStateMgr.changeState(StateID_NextSceneWait);
    }

    mpSelectPlayer->mCurrentButton = 0;
    mInPlayerSelect = true;

    int choice = mpFileSelect->mChoice;
    if (choice < SAVE_SLOT_COUNT) {
        if (mpFileSelect->mChoiceTempFile) {
            dSaveMng_c::m_instance->loadQuickSaveData(choice);
        }
        dSaveMng_c::m_instance->initLoadGame(choice);
    } else {
        for (int& rest : daPyMng_c::mRest) {
            rest = daPyMng_c::START_REST;
        }
        daPyMng_c::checkBonusNoCap();
        if (choice == 3) {
            dInfo_c::mGameFlag &= ~dInfo_c::GameFlag_e::COIN_BATTLE;
            dInfo_c::mGameFlag |=
              dInfo_c::GameFlag_e::MULTI_MODE | dInfo_c::GameFlag_e::FREE_FOR_ALL;
        } else {
            dInfo_c::mGameFlag &= ~dInfo_c::GameFlag_e::FREE_FOR_ALL;
            dInfo_c::mGameFlag |=
              dInfo_c::GameFlag_e::MULTI_MODE | dInfo_c::GameFlag_e::COIN_BATTLE;
        }
        mDvd::setOverlayRes(false);
    }

    return mStateMgr.changeState(StateID_FadeOut);
}

[[nsmbw(0x809188E0)]]
void dScGameSetup_c::finalizeState_FileSelect()
{
    for (int i = 0; i < CHARACTER_COUNT; i++) {
        daPyMng_c::mPlayerType[i] = dMj2dGame_c::scDefaultPlayerTypes[i];
    }
}

[[nsmbw(0x80918B00)]]
void dScGameSetup_c::executeState_StartMember()
{
    dSelectPlayer_c* selPly = mpSelectPlayer;

    if (selPly->m0x26B == 0) {
        return;
    }

    if (selPly->mActDirection == -1) {
        // Back
        mInPlayerSelect = false;
        return mStateMgr.changeState(dScGameSetup_c::StateID_FadeOut);
    } else if (selPly->mActDirection != 1) {
        return;
    }

    dInfo_c* info = dInfo_c::m_instance;
    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        info->setPlyConnectStage(i, dInfo_c::PlyConnectStage_e::OFF);
    }

    // Switch to dNumberOfPeopleChange_c
    dNumberOfPeopleChange_c* numPyChg = mpNumPyChg;
    numPyChg->m0x67E = true;
    numPyChg->mPlayerCount = selPly->mCurrentButton + 1;

    mStateMgr.changeState(dScGameSetup_c::StateID_ConnectionCheck);
}

[[nsmbw(0x80918C10)]]
void dScGameSetup_c::initializeState_ConnectionCheck()
{
    if (!!(dInfo_c::mGameFlag & dInfo_c::GameFlag_e::MULTI_MODE)) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            PLAYER_TYPE_e type = daPyMng_c::mPlayerType[i];
            daPyMng_c::mPlayerMode[type] = PLAYER_MODE_e::NONE;

            dPyMdlBase_c* mdl = mpNumPyChg->mp2DPlayer[type]->mModelMng->mModel;
            if ((mdl->mVisibilityFlags & 0x100) != 0) {
                mdl->offStarAnm();
            }
            if ((mdl->mVisibilityFlags & 0x200) != 0) {
                mdl->offStarEffect();
            }

            if ((int) (daPyMng_c::mCreateItem[type] & PLAYER_CREATE_ITEM_e::STAR_POWER) != 0) {
                daPyMng_c::mCreateItem[type] &= (PLAYER_CREATE_ITEM_e) 0xFFFFFFFE;
            }
        }
    }
    SndSceneMgr::sInstance->setGameSetupTrack(2);
}

[[nsmbw(0x80918DC0)]]
void dScGameSetup_c::initializeState_EasyPairingWait()
{
    mpNumPyChg->setEasyPairingWait(true);
    mpEasyPairing->m0x279 = true;
}

[[nsmbw(0x80918E70)]]
void dScGameSetup_c::finalizeState_EasyPairingWait()
{
    mpNumPyChg->setEasyPairingWait(false);
}

[[nsmbw(0x80919190)]]
void dScGameSetup_c::finalizeState_VoiceEndWait()
{
    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();
    if (save->isEmpty() && !fFeat::disable_opening_movie) {
        dScene_c::setNextScene(dProf::MOVIE, 0, false);
    } else {
        dScene_c::setNextScene(dProf::WORLD_MAP, dScWMap_c::CreateBootParam(), false);
    }
}
