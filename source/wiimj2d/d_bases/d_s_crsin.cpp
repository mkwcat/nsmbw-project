// d_s_crsin.cpp
// NSMBW d_bases.text: 0x8091EC10 - 0x80921060

#include "d_s_crsin.h"

#include "component/c_random.h"
#include "d_bases/d_s_stage.h"
#include "d_player/d_WarningManager.h"
#include "d_project/d_nextgoto_list.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_fader.h"
#include "d_system/d_game_common.h"
#include "d_system/d_game_key.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_remocon_mng.h"
#include "d_system/d_resource_mng.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_scene.h"
#include "d_system/d_stage.h"
#include "machine/m_fader.h"

[[nsmbw(0x8091EC50)]]
int dScCrsin_c::loadDefaultObjectResPhase()
{
    static const char* l_objectRes[] = {
      "Mario",
      "Luigi",
      "Kinopio",
      "Kinopico", // Added
      "Yoshi",
      "P_rcha",
      "L_rcha",
      "K_rcha",
      "C_rcha", // Added
      "Y_rcha",
      "Y_TexGreen",
      "Y_TexRed",
      "Y_TexYellow",
      "Y_TexBlue",
      "Y_TexCrimson", // Added
      "Y_TexOrange", // Added
      "Y_TexPurple", // Added
      "Y_TexAzure", // Added
      "obj_coin",
      "balloon",
      "I_kinoko",
      "I_fireflower",
      "I_iceflower",
      "I_star",
      "I_propeller",
      "I_penguin",
      "I_yoshi_egg",
      "block_tsuta",
      "teresa",
      "jump_step",
      "ice",
      "ice_piece",
      "obj_dokan",
      "obj_door",
      "obj_kusa",
      "obj_hana",
      "obj_hana_daishizen",
      "block_jump",
      "obj_chikuwa_block",
      "lift_rakka_ashiba",
      "Mask",
    };

    dResMng_c::m_instance->setRes(
      "Object", l_objectRes, sizeof(l_objectRes) / sizeof(l_objectRes[0]), nullptr
    );

    return 1;
}

[[nsmbw(0x8091EFD0)]]
dScCrsin_c::~dScCrsin_c()
{
    mPreGameLyt.~dPreGameLyt_c();
}

[[nsmbw(0x8091F560)]]
bool dScCrsin_c::isDoneLoading();

[[nsmbw(0x8091F940)]]
void dScCrsin_c::initializeState_loadCourseProc()
{
    dYoshiMdl_c::setDefaultColors();
}

[[nsmbw(0x8091FE20)]]
void dScCrsin_c::executeState_resWaitProc2()
{
    if (!isDoneLoading()) {
        return;
    }

    const auto& startGameInfo = dInfo_c::m_instance->m_startGameInfo;
    if (startGameInfo.demoType == dInfo_c::DemoType_e::TITLE) {
        // Setup players for title screen
        int powerupMode = dGameCom::rndInt(128);
        for (int i = 0; i < 8; i++) {
            daPyMng_c::mPlayerType[i] = dMj2dGame_c::scDefaultPlayerTypes[i];
            daPyMng_c::mPlayerEntry[i] = true;

            PLAYER_TYPE_e plrType = dMj2dGame_c::scDefaultPlayerTypes[i];

            if (powerupMode < 4) {
                daPyMng_c::mPlayerMode[plrType] = PLAYER_MODE_e::NONE;
            } else if (powerupMode == 4) {
                daPyMng_c::mPlayerMode[plrType] = PLAYER_MODE_e::MINI_MUSHROOM;
            } else {
                int mode = dGameCom::rndInt(PLAYER_MODE_COUNT - 2) + 1;
                if (mode >= static_cast<int>(PLAYER_MODE_e::MINI_MUSHROOM)) {
                    mode++;
                }
                daPyMng_c::mPlayerMode[plrType] = static_cast<PLAYER_MODE_e>(mode);
            }

            daPyMng_c::mCreateItem[plrType] = PLAYER_CREATE_ITEM_e::NONE;
        }
    } else if (dScStage_c::m_isStaffCredit) {
        // Setup players for credits
        for (int i = 0; i < PLAYER_COUNT; i++) {
            daPyMng_c::mPlayerEntry[i] = true;

            dRemoconMng_c::m_instance->mpConnect[i]->setAllowConnect(true);

            PLAYER_TYPE_e plrType = daPyMng_c::mPlayerType[i];

            daPyMng_c::mPlayerMode[plrType] = PLAYER_MODE_e::MUSHROOM;
            if (daPyMng_c::mRest[plrType] < daPyMng_c::START_REST) {
                daPyMng_c::mRest[plrType] = daPyMng_c::START_REST;
            }

            daPyMng_c::mCreateItem[plrType] = PLAYER_CREATE_ITEM_e::NONE;
        }
    } else if (auto& game = *dSaveMng_c::m_instance->getSaveGame();
               game.getPipeRandomizerMode() != dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::DISABLED) {
        dNextGotoList_c::create();
        auto mode = game.getPipeRandomizerMode();
        if (mode == dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::PER_GAME) {
            if (dNextGotoList_c::ms_lookup.empty() ||
                dNextGotoList_c::ms_instance.getSeed() != game.getPipeRandomizerSeed()) {
                dNextGotoList_c::ms_instance.randomize(game.getPipeRandomizerSeed());
            }
        } else if (mode == dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::PER_COURSE) {
            u32 seed = static_cast<u32>(game.getPipeRandomizerSeed());
            u32 add = static_cast<u32>(startGameInfo.stage1.stage) << 24;
            add += static_cast<u32>(startGameInfo.stage1.world) << 16;
            cRnd_c rnd(seed);
            (void) rnd.next();
            rnd.mSeed += add;
            (void) rnd.next();
            rnd.mSeed += add;
            (void) rnd.next();
            rnd.mSeed += add;
            seed = rnd.next();

            if (dNextGotoList_c::ms_lookup.empty() ||
                dNextGotoList_c::ms_instance.getSeed() != seed) {
                dNextGotoList_c::ms_instance.randomize(seed);
            }
        }
    }

    mStateMgr.changeState(StateID_createReplayHeapProc);
}

[[nsmbw(0x80920550)]]
void dScCrsin_c::executeState_DispEndCheck()
{
    if (m_isDispOff) {
        mFader_c::mFader->setStatus(mFader_c::EStatus::OPAQUE);
        return dStage_c::setNextStage(0, mParam);
    }

    if (mPreGameLyt.m0x2E1) {
        return;
    }
    if (dWarningManager_c::isWarning() || dWarningManager_c::m_instance->m0xB8E) {
        return;
    }
    if (mPreGameLyt.m_dispEndTimer == 0 || dGameKey_c::getCurrentCore()->isTrig(0xF0F)) {
        return dStage_c::setNextStage(0, mParam);
    }
}