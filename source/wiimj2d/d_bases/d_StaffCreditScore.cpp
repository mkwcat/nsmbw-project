// d_StaffCreditScore.cpp
// NSMBW   d_bases.text:  0x807ADAD0 - 0x807AF370

#include "d_StaffCreditScore.h"
#include "d_player/d_a_player.h"
#include "d_system/d_a_player_demo_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_lyttextbox.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_message.h"
#include "sound/SndSceneMgr.h"

[[nsmbw(0x807ADAD0)]]
dStaffCreditScore_c* dStaffCreditScore_c_classInit()
{
    return new dStaffCreditScore_c();
}

[[nsmbw(0x807ADB00)]]
dStaffCreditScore_c::dStaffCreditScore_c();

[[nsmbw(0x807ADF10)]]
bool dStaffCreditScore_c::createLayout()
{
    if (!mLayout.ReadResource("staffCredit/staffCredit.arc", false)) {
        return false;
    }

    mLayout.build("staffCredit_00.brlyt", nullptr);

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.AnimeResRegister(
      StringArray{
        "staffCredit_00_inPlayerScore.brlan",
        "staffCredit_00_loopPlayerScore.brlan",
        "staffCredit_00_inHighScore.brlan",
        "staffCredit_00_winPlayer.brlan",
        "staffCredit_00_newHighScore.brlan",
      },
      5
    );

    mLayout.GroupRegister(
      StringArray{
        "A00_1P",
        "A01_2P",
        "A02_3P",
        "A03_4P",
        "A04_5P",
        "A05_6P",
        "A06_7P",
        "A07_8P",
        "A00_1P",
        "A01_2P",
        "A02_3P",
        "A03_4P",
        "A04_5P",
        "A05_6P",
        "A06_7P",
        "A07_8P",
        "B00_score",
        "A00_1P",
        "A01_2P",
        "A03_4P", // Swapped to match character order
        "A02_3P", // ^
        "A04_5P",
        "A05_6P",
        "A06_7P",
        "A07_8P",
        "B00_score",
      },
      IntArray{
        0, 0, 0, 0, 0, 0, 0, 0,
        1, 1, 1, 1, 1, 1, 1, 1,
        2,
        3, 3, 3, 3, 3, 3, 3, 3,
        4,
      },
      26
    );

    mpRootPane = mLayout.getRootPane();

    mLayout.TPaneRegister(
      mpTCoin,
      {
        "T_coin_00",
        "T_coin_01",
        "T_coin_03", // Swapped to match character order
        "T_coin_02", // ^
        "T_coin_05",
        "T_coin_06",
        "T_coin_07",
        "T_coin_08",
        }
    );

    mLayout.TPaneRegister(
      &mpTCoin04,
      {
        "T_coin_04",
        "T_highScore_00",
        }
    );

    MsgRes_c *msgRes = dMessage_c::getMesRes();
    mpTHighScore->setMessage(msgRes, 0x131, 1, 0);

    mLayout.NPaneRegister(
      mpNPlayer,
      {
        "N_mario_00",
        "N_luigi_00",
        "N_kinoY_00",
        "N_kinoB_00",
        "N_proportionL_00",
        "N_proportionR_00",
      }
    );

    // Reset winPlayerCount anims
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mLayout.ReverseAnimeStartSetup(17 + i, false);
    }

    return true;
}

[[nsmbw(0x807AE140)]]
void dStaffCreditScore_c::setCoinCount(int player)
{
    int playerType = (int)daPyMng_c::mPlayerType[player];
    dGameCom::LayoutDispNumber(mCoinNum[player], 3, mpTCoin[playerType], true);
}

[[nsmbw(0x807AE1C0)]]
void dStaffCreditScore_c::updateCoinCounts()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPrevCoinNum[i] != mCoinNum[i]) {
            mPrevCoinNum[i] = mCoinNum[i];
            setCoinCount(i);
        }
    }
}

[[nsmbw(0x807AE230)]]
void dStaffCreditScore_c::initializeState_OnStageWait()
{
    mLayout.AllAnimeEndSetup();
    mpRootPane->SetVisible(false);

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mCoinNum[i] = 0;
        mPrevCoinNum[i] = -1; // Set to -1 so the coin counters can be set
    }
    updateCoinCounts();

    mDoHighScoreCheck = false;
    mDoHighScoreAnime = false;
}

[[nsmbw(0x807AE300)]]
void dStaffCreditScore_c::initializeState_OnStageAnimeEndWait()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        // Fixing a retail bug here:
        // The credits seems to have originally only included active players. Some leftover code causes these animations
        // to only play if mPlayerActive[i] is not false, however those are never set to any value, they are ALWAYS false.
        // As such, these appear animations for the coin counters will never play in the retail game. How "fun"
        mLayout.AnimeStartSetup(i, false);
    }

    mLayout.AnimeStartSetup(16, false);
    mpRootPane->SetVisible(true);
}

[[nsmbw(0x807AE520)]]
void dStaffCreditScore_c::initializeState_HighScoreCheck()
{
    daPyDemoMng_c::mspInstance->onLandStopReq();
    mDoDemoLandPlayer = true;

    int winPlyID = -1;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mIsWinPlayer[i] = false;
        if (mMaxCoinNum <= mCoinNum[i]) {
            mMaxCoinNum = mCoinNum[i];
            winPlyID = i;
        }
    }

    mWinPlayerID = winPlyID;
    if (winPlyID > -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mMaxCoinNum == mCoinNum[i]) {
                mIsWinPlayer[i] = true;
                if (mMaxCoinNum != 0) {
                    int type = (int)daPyMng_c::mPlayerType[i];
                    mLayout.AnimeStartSetup(17 + type, false);
                }
            }
        }

        SndSceneMgr::sInstance->startStaffCreditHiscore();
    }

    if (mHighScore < mMaxCoinNum) {
        mHighScore = mMaxCoinNum;
    }
}

[[nsmbw(0x807AE750)]]
void dStaffCreditScore_c::initializeState_HighScoreAnimeEndWait()
{
    if ((mWinPlayerID > -1) && (mMaxCoinNum != 0)) {
        dGameCom::LayoutDispNumber(mHighScore, 3, mpTCoin04, true);
        mLayout.AnimeStartSetup(25, false);
    }
}

[[nsmbw(0x807AE900)]]
void dStaffCreditScore_c::initializeState_No1PlayerKiMe()
{
    if (mWinPlayerID > -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            dAcPy_c *ply = daPyMng_c::getPlayer(i);
            if (mIsWinPlayer[i] && ply != 0x0) {
                ply->UNDEF_80052290(2);
            }
        }
    }
}

[[nsmbw(0x807AE980)]]
void dStaffCreditScore_c::executeState_No1PlayerKiMe()
{
    bool delayEndWait = false;
    if (mWinPlayerID > -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            dAcPy_c *ply = daPyMng_c::getPlayer(i);
            if (mIsWinPlayer[i] && ply != 0x0) {
                // Check if we're waiting on anims
                if (ply->mPyMdlMng.mModel->mCurrentAnm != 0) {
                    delayEndWait = true;
                }
            }
        }
    }

    if (!delayEndWait) {
        mStateMgr.changeState(StateID_EndWait);
    }
}