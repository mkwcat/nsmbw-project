// d_s_stage.cpp
// NSMBW d_bases.text: 0x80923C10 - 0x80926740

#include "d_s_stage.h"

#include "d_bases/d_MessageWindow.h"
#include "d_bases/d_MiniGameCannon.h"
#include "d_bases/d_MiniGameWire.h"
#include "d_bases/d_ModelPlayManager.h"
#include "d_bases/d_StaffCreditScore.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_cyuukan.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_start_info.h"
#include "d_system/d_wm_lib.h"

[[nsmbw(0x80924950)]]
bool dScStage_c::CreatedLayouts() const
{
    return !checkChildProcessCreateState() && (!mpMiniGameCannon || mpMiniGameCannon->mReady) &&
           (!mpMiniGameWire || mpMiniGameWire->mReady) &&
           (!mpModelPlayManager || mpModelPlayManager->mReady) &&
           (!mpMessageWindow || mpMessageWindow->mReady) &&
           (!mpStaffCreditScore || mpStaffCreditScore->mReady);
}

[[nsmbw(0x809251C0)]]
void dScStage_c::procExitMode()
{
    switch (m_exitMode) {
    case ExitMode_e::CLEAR:
        exitClear();
        break;
    case ExitMode_e::DOWN:
        exitDown();
        break;
    case ExitMode_e::CARRY_OVER_RNDIZER:
        break;
    default:
        exitRestore();
        break;
    }
}

[[nsmbw(0x809251F0)]]
void dScStage_c::exitClear()
{
    WORLD_e world = m_instance->mWorld;
    STAGE_e stage = m_instance->mStage;

    if (world >= WORLD_e::COUNT || stage >= STAGE_e::COUNT) {
        return;
    }

    dInfo_c* info = dInfo_c::m_instance;
    dCyuukan_c* cyuukan = &info->mCyuukan;
    dStartInfo_c& startInfo = info->m_startInfo;

    if (m_miniGame == 0) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            // Hacky, but it works
            // For some reason, mCreateItem will have the star flag reset by this function
            // Even though the original game's version doesn't.
            PLAYER_TYPE_e type = static_cast<PLAYER_TYPE_e>(i);
            daPyMng_c::mCreateItem[type] =
              startInfo.mCreateItem[type] & ~PLAYER_CREATE_ITEM_e::STAR_POWER;
        }
    }

    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();

    dInfo_c::StartGameInfo_s& startGameInfo = info->m_startGameInfo;

    if (startGameInfo.demoType == dInfo_c::DemoType_e::NONE) {
        if ((startGameInfo.stage1.stage < STAGE_e::KINOKO_HOUSE ||
             startGameInfo.stage1.stage > STAGE_e::KINOKO_HOUSE_7) &&
            startGameInfo.stage1.stage != STAGE_e::PEACH_CASTLE) {
            cyuukan->clear();
        }

        if (daPyMng_c::isOnePlayer()) {
            save->setDeathCount(world, stage, info->mSwitchOn, 0);
        }

        for (int i = 0; i < COLLECTION_COIN_COUNT; i++) {
            static constexpr dMj2dGame_c::COURSE_COMPLETION_e COLLECTION_COIN_FLAGS[] = {
              dMj2dGame_c::COURSE_COMPLETION_e::COIN1_COLLECTED,
              dMj2dGame_c::COURSE_COMPLETION_e::COIN2_COLLECTED,
              dMj2dGame_c::COURSE_COMPLETION_e::COIN3_COLLECTED,
            };

            if (mCollectionCoin[i] != PLAYER_TYPE_e::COUNT) {
                save->setCollectCoin(world, stage, COLLECTION_COIN_FLAGS[i]);
            }
        }

        extern u8 UNDEF_8042a458;
        extern u8 UNDEF_8042a460;

        UNDEF_8042a458 = 0;
        UNDEF_8042a460 = 0;
    }

    bool isSecretExit = m_goalType == 1;
    if (startGameInfo.demoType != dInfo_c::DemoType_e::NONE &&
        (world != WORLD_e::WORLD_3 || stage != STAGE_e::STAGE_4)) {
        isSecretExit = false;
    }

    dWmLib::procCourseClear(
      isSecretExit, startGameInfo.demoType == dInfo_c::DemoType_e::SUPER_GUIDE, world, stage
    );

    if (startGameInfo.demoType != dInfo_c::DemoType_e::NONE) {
        exitRestore();
    }
}

[[nsmbw(0x809253E0)]]
void dScStage_c::exitRestore()
{
    dInfo_c* info = dInfo_c::m_instance;
    dCyuukan_c* cyuukan = &info->mCyuukan;
    dStartInfo_c& startInfo = info->m_startInfo;

    cyuukan->mState = startInfo.mCyuukan.mState;
    cyuukan->mPlayerSetPos = startInfo.mCyuukan.mPlayerSetPos;
    cyuukan->m0x14 = startInfo.mCyuukan.m0x14;
    cyuukan->mWorld = startInfo.mCyuukan.mWorld;
    cyuukan->mStage = startInfo.mCyuukan.mStage;
    cyuukan->mCourse = startInfo.mCyuukan.mCourse;
    cyuukan->mGoto = startInfo.mCyuukan.mGoto;
    cyuukan->mIsKinopioInChukan = startInfo.mCyuukan.mIsKinopioInChukan;
    cyuukan->mCollectionCoin[0] = startInfo.mCyuukan.mCollectionCoin[0];
    cyuukan->mCollectionCoin[1] = startInfo.mCyuukan.mCollectionCoin[1];
    cyuukan->mCollectionCoin[2] = startInfo.mCyuukan.mCollectionCoin[2];
    cyuukan->m0x2C[0] = startInfo.mCyuukan.m0x2C[0];
    cyuukan->m0x2C[1] = startInfo.mCyuukan.m0x2C[1];
    info->mSwitchOn = startInfo.mSwitchOn;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        PLAYER_TYPE_e type = static_cast<PLAYER_TYPE_e>(i);
        int index = startInfo.mPlayerIndex[type];
        daPyMng_c::mPlayerType[index] = type;
        daPyMng_c::mPlayerMode[type] = startInfo.mPlayerMode[type];
        daPyMng_c::mPlayerEntry[index] = startInfo.mIsEntry[type];
        daPyMng_c::mCoin[type] = startInfo.mCoin[type];
        daPyMng_c::mRest[type] = startInfo.mRest[type];
        daPyMng_c::mCreateItem[type] = startInfo.mCreateItem[type];
    }

    daPyMng_c::mScore = startInfo.mScore;

    extern u8 UNDEF_8042a458, UNDEF_8042a459;
    extern u8 UNDEF_8042a460, UNDEF_8042a461;

    UNDEF_8042a458 = UNDEF_8042a459;
    UNDEF_8042a460 = UNDEF_8042a461;

    info->m0x06C = 0;
}

[[nsmbw(0x809255B0)]]
void dScStage_c::exitDown();
