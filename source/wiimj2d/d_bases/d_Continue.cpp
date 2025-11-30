// d_Continue.cpp
// NSMBW   d_bases.text:  0x807775E0 - 0x80779650

#include "d_Continue.h"

#include "d_bases/d_profile.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_ef.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_save_manager.h"
#include "d_system/d_scene.h"
#include "framework/f_base.h"
#include "machine/m_pad.h"
#include "machine/m_vec.h"
#include "nw4r/lyt/Pane.h"
#include "nw4r/lyt/Types.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"

#include <revolution/os.h>
#include <revolution/sc.h>

[[address(0x807775E0)]]
dContinue_c* dContinue_c_classInit()
{
    return new dContinue_c();
}

[[address(0x80777610)]]
dContinue_c::dContinue_c();

[[address(0x807778A0)]]
fBase_c::PACK_RESULT_e dContinue_c::create()
{
    if (!mLayoutLoaded) {
        if (!createLayout()) {
            return PACK_RESULT_e::NOT_READY;
        }

        for (int i = 0; i < PLAYER_COUNT; i++) {
            dMj2dGame_c *save = dSaveMng_c::m_instance->getSaveGame(-1);
            mContinue[i] = save->getContinue(i);
        }

        setPlayerInfo();
        setContinue();
        mLayout.mPriority = 0x91;
        mLayout.AllAnimeEndSetup();
        mLayout.ReverseAnimeStartSetup(3, false);
        mLayout.ReverseAnimeStartSetup(0, false);
        mLayout.AnimePlay();
        mLayout.calc();

        mVisible = false;
        mLayoutLoaded = true;
        mIsGameOver = false;
    }
    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x807779D0)]]
bool dContinue_c::createLayout()
{
    if (!mLayout.ReadResource("continue/continue.arc", false)) {
        return false;
    }

    mLayout.build("continue_05.brlyt", nullptr);

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.AnimeResRegister(
      StringArray{
        "continue_05_inWindow.brlan",
        "continue_05_countContinue.brlan",
        "continue_05_zankiRecover.brlan",
        "continue_05_colorRecover.brlan",
        "continue_05_outWindow.brlan",
        "continue_05_inBG.brlan",
        "continue_05_outBG.brlan",
      },
      7
    );

    mLayout.GroupRegister(
      StringArray{
        "A00_window",
        "B00_contTime",
        "C00_zankiRecover",
        "E00_colorRecover",
        "A00_window",
        "D00_bg",
        "D00_bg",
      },
      IntArray{
        0,
        1,
        2,
        3,
        4,
        5,
        6,
      },
      7
    );

    mpRootPane = mLayout.getRootPane();

    mLayout.TPaneNameRegister(
      StringArray{
        "T_conTitle_00",
        "T_scoreTitle_01",
        "T_scoreTitle_02",
        "T_scoreTitle_03",
        "T_Time_00",
        "T_Time_01",
        "T_Time_02",
        "T_Time_03",
      },
      IntArray{
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
      },
      0x6, 8
    );

    mLayout.PPaneRegister(
      &mpP_bg_PContinue,
      {
        "P_bg_PContinue",
      }
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_conTitle_01",
        "T_scoreTitle_00",
        "T_scoreTitle_04",
        "T_scoreTitle_05",
        "T_Time_04",
        "T_Time_05",
        "T_Time_06",
        "T_Time_07",
      },
      IntArray{
        0,
        0,
        0,
        0,
        1,
        1,
        1,
        1,
      },
      0x6, 8
    );

    mLayout.NPaneRegister(
      mpNPos4P,
      {
        "N_4P_Pos_00",
        "N_4P_Pos_01",
        "N_4P_Pos_02",
        "N_4P_Pos_03",
        "N_3P_Pos_00",
        "N_3P_Pos_01",
        "N_3P_Pos_02",
        "N_2P_Pos_00",
        "N_2P_Pos_01",
        "N_1P_Pos_00",
        "N_4P_Pos_10",
        "N_4P_Pos_11",
        "N_4P_Pos_12",
        "N_4P_Pos_13",
        "N_5P_Pos_00",
        "N_6P_Pos_00",
        "N_7P_Pos_00",
        "N_8P_Pos_00",
        "N_dateFile_01P",
        "N_dateFile_02P",
        "N_dateFile_03P",
        "N_dateFile_04P",
        "N_dateFile_05P",
        "N_dateFile_06P",
        "N_dateFile_07P",
        "N_dateFile_08P",
      }
    );
    mLayout.TPaneRegister(
      mpTConTime,
      {
        "T_conTime_00",
        "T_conTime_01",
        "T_conTime_02",
        "T_conTime_03",
        "T_conTime_04",
        "T_conTime_05",
        "T_conTime_06",
        "T_conTime_07",
        "T_playerZanki_04",
        "T_playerZanki_05",
        "T_playerZanki_06",
        "T_playerZanki_07",
        "T_playerZanki_09",
        "T_playerZanki_11",
        "T_playerZanki_13",
        "T_playerZanki_15",
      }
    );

    // Rescale the layout for 4:3 mode
    if (dGameCom::GetAspectRatio() == SCAspectRatio::STANDARD) {
        nw4r::math::VEC2 scale = {0.85, 0.85};
        mLayout.getRootPane()->SetScale(scale);

        // Scale down all of the pos panes, as the cards use their scale value
        for (int i = 0; i < 18; i++) {
            mpNPos4P[i]->SetScale(scale);
        }
    }

    return true;
}

[[address(0x80777C20)]]
int dContinue_c::getPaneIdx(int playerID)
{
    int paneIdxArray[PLAYER_COUNT][PLAYER_COUNT] = {
      {9,  18, 18, 18, 18, 18, 18, 18}, 
      {7,  8,  18, 18, 18, 18, 18, 18},
      {4,  5,  6,  18, 18, 18, 18, 18},   
      {0,  1,  2,  3,  18, 18, 18, 18},
      {10, 11, 12, 13, 14, 18, 18, 18},        
      {10, 11, 12, 13, 14, 15, 18, 18},
      {10, 11, 12, 13, 14, 15, 16, 18},        
      {10, 11, 12, 13, 14, 15, 16, 17},
    };
    return paneIdxArray[mPlayCount - 1][playerID];
}

[[address(0x80777C50)]]
void dContinue_c::setCardPosition()
{
    int paneIdx = 0;
    int playerID = 0;
    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= LytPlayerCount) {
            continue;
        }

        paneIdx = getPaneIdx(playerID);
        if (mMustRevive[i] && paneIdx != 18) {
            playerID++;

            const nw4r::math::MTX34& dfMtx = mpNPos4P[paneIdx]->GetGlobalMtx();
            nw4r::math::VEC3 trans = {dfMtx[0][3], dfMtx[1][3], 0.0};
            mpNDateFile[i]->SetTranslate(trans);
            mpNDateFile[i]->SetScale(mpNPos4P[paneIdx]->GetScale());
        }
    }
}

[[address(0x80777DA0)]]
void dContinue_c::setContinue()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mMustRevive[i]) {
            const int &continues = mContinue[i];
            dGameCom::LayoutDispNumberDigit(continues, mpTConTime[i], false);
        }
    }
}

[[address(0x80777E30)]]
void dContinue_c::setRest()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mMustRevive[i]) {
            const int &restNum = mRestNum[i];
            dGameCom::LayoutDispNumberDigit(restNum, mpTPlyZanki[i], false);
        }
    }
}

[[address(0x80777EC0)]]
void dContinue_c::setPlayerInfo()
{
    mPlayCount = 0;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        int player = daPyMng_c::findPlayerWithType((PLAYER_TYPE_e)i);
        mRestNum[i] = daPyMng_c::mRest[daPyMng_c::mPlayerType[player]];

        bool isActive = dGameCom::PlayerEnterCheck(player);

        nw4r::lyt::Pane *dateFile = mpNDateFile[i];
        if (isActive && (mRestNum[i] < 1)) {
            dateFile->SetVisible(true);
            mMustRevive[i] = true;
            mPlayCount += 1;
        } else {
            dateFile->SetVisible(false);
            mMustRevive[i] = false;
        }
    }
}

[[address(0x80777FD0)]]
void dContinue_c::EffectContinueInc(int playerID, int numLen)
{
    nw4r::lyt::Pane* conTime = mpTConTime[playerID];
    const nw4r::math::MTX34& mtx = conTime->GetGlobalMtx();

    float modifier = conTime->GetSize().width * 0.16 * numLen * 0.5;
    mVec3_c pos = {mtx[0][3] - modifier, mtx[1][3], 0.0};

    if (dScene_c::m_nowScene == dProf::WORLD_MAP) {
        mVec3_c effectPos = dGameCom::ScalePosForAspectRatio(pos);
        dEf::createPlayerEffect(0, "Wm_2d_continue", 0, &effectPos, nullptr, nullptr);
    } else {
        dGameCom::ScalePosForLayoutEffect(pos, false);
        mEf::createEffect("Wm_2d_continue", 0, &pos, nullptr, nullptr);
    }
}

[[address(0x807783E0)]]
void dContinue_c::executeState_ContinueCountUp()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        int numLen = 1;
        if (mMustRevive[i]) {
            // Increment all continues
            int con = mContinue[i] + 1;
            if (con > 99) { con = 99; }
            mContinue[i] = con;

            // Now find the length of the number, then play our effect
            for (int val = con; val > 9; val -= (val >> 0x1f)) {
                numLen = numLen + 1;
                val = val / 10 + (val >> 0x1f);
            }
            EffectContinueInc(i, numLen);
        }
    }

    setContinue();
    SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_COUNT_CONTINUE, 1);
    mLayout.AnimeStartSetup(1, false);
}

[[address(0x807785A0)]]
void dContinue_c::executeState_RestCountUp()
{
    if (!mLayout.isAnime(2)) {
        if (mRestInc < 5) {
            SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_COUNT_ZANKI, 1);
            for (int i = 0; i < PLAYER_COUNT; i++) {
                // Increment lives
                if (mMustRevive[i]) {
                    mRestNum[i]++;
                }
            }
            setRest();
            mRestInc++;
            mLayout.AnimeStartSetup(2, false);
        } else {
            mStateMgr.changeState(StateID_ColorRecover);
        }
    }
}

static int ContinueReviveSE[] = {
    SndID::SE_VOC_MA_CONTINUE, SndID::SE_VOC_LU_CONTINUE,
    SndID::SE_VOC_KO_CONTINUE, SndID::SE_VOC_KO2_CONTINUE,
    SndID::SE_VOC_KC_CONTINUE, SndID::SE_VOC_KC_CONTINUE,
    SndID::SE_VOC_KO_CONTINUE, SndID::SE_VOC_KO2_CONTINUE,
};

[[address(0x807786A0)]]
void dContinue_c::finalizeState_RestCountUp()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mMustRevive[i]) {
            SndAudioMgr::sInstance->startSystemSe(ContinueReviveSE[i], 1);
        }
        daPyMng_c::mRest[i] = 5;
        daPyMng_c::mCreateItem[i] = PLAYER_CREATE_ITEM_e::NONE;
        daPyMng_c::mPlayerMode[i] = PLAYER_MODE_e::NONE;
    }
}

[[address(0x80778860)]]
void dContinue_c::executeState_EndWait()
{
    if (mExitDelay == 0) {
        // Check if the user cancelled the menu on their own
        int isPress = mPad::g_currentCore->downTrigger(WPAD_BUTTON_2|WPAD_BUTTON_A);
        if ((isPress != 0) && (mDelay != 0)) {
            mDelay = 0;
        }

        if (mDelay == 0) {
            // Wait for sounds to complete before exiting
            for (int i = 0; i < PLAYER_COUNT; i++) {
                bool isSndActive = SndAudioMgr::sInstance->isSndPlaying(ContinueReviveSE[i]);
                if (isSndActive)
                    return;
            }

            if (!mIsGameOver) {
                mStateMgr.changeState(StateID_ExitAnimeEndWait);
            } else {
                mDoExit = true;
                mStateMgr.changeState(StateID_StartWait);
            }
        } else {
            mDelay--;
        }
    } else {
        mExitDelay--;
        mDelay--;
    }
}

[[address(0x807789B0)]]
void dContinue_c::finalizeState_EndWait()
{
    dMj2dGame_c *save = dSaveMng_c::m_instance->getSaveGame();
    for (int i = 0; i < PLAYER_COUNT; i++) {
        s8 newContinue = mContinue[i];
        save->setContinue(i, newContinue);
    }
}