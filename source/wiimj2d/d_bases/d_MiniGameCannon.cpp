// d_MiniGameCannon.cpp
// NSMBW d_bases.text: 0x8078BC60 - 0x8078DA20

#include "d_MiniGameCannon.h"

#include "d_player/d_WarningManager.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_message.h"
#include "d_system/d_mj2d_game.h"

[[address(0x8078BC60)]]
dMiniGameCannon_c* dMiniGameCannon_c_classInit()
{
    return new dMiniGameCannon_c;
}

[[address(0x8078BC90)]]
dMiniGameCannon_c::dMiniGameCannon_c()
  : mStateMgr(*this, StateID_TitleOpenWait)
{
    mReady = false;
    mActive = false;
    mIsWindowOpen = false;
    mIsTitleOpen = false;
    mAnimationActive = false;
    mCloseTitle = false;
    mCloseOperate = false;
    mCloseResult = false;
}

[[address(0x8078BEA0)]]
dMiniGameCannon_c::~dMiniGameCannon_c()
{
    // mStateMgr.~sStateMgr_c();
    mLayout.~LytBase_c();
}

[[address(0x8078BF30)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::create()
{
    if (mReady) {
        return PACK_RESULT_e::SUCCEEDED;
    }

    if (!createLayout()) {
        return PACK_RESULT_e::FAILED;
    }

    mLayout.AllAnimeEndSetup();
    mLayout.ReverseAnimeStartSetup(0, false);
    mLayout.AnimePlay();
    mLayout.calc();

    mpRootPane->SetVisible(false);

    mCurrentState = false;
    for (std::size_t i = 0; i < std::size(mNumWon); i++) {
        mNumWon[i] = 0;
    }

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        mPlayerEntry[i] = false;
    }

    mReady = true;
    mActive = false;

    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8078C000)]]
bool dMiniGameCannon_c::createLayout()
{
    if (!mLayout.ReadResource("miniGameCannon/miniGameCannon.arc", false)) {
        return false;
    }

    mLayout.build("miniGameCannon_15.brlyt", nullptr);
    mLayout.AnimeResRegister({
      "miniGameCannon_15_inWindow.brlan",
      "miniGameCannon_15_loopWindow.brlan",
      "miniGameCannon_15_loopYokoIncline.brlan",
      "miniGameCannon_15_inPlayer.brlan",
      "miniGameCannon_15_loop1UP.brlan",
      "miniGameCannon_15_inTitle.brlan",
      "miniGameCannon_15_weitTitle.brlan",
      "miniGameCannon_15_outTitle.brlan",
      "miniGameCannon_15_outWindow.brlan",
    });
    mLayout.GroupRegister(
      {{"A00_Window", 0},
       {"A00_Window", 1},
       {"B00_Yokomochi", 2},
       {"D00_1P_00", 3},
       {"D01_2P_00", 3},
       {"D02_3P_00", 3},
       {"D03_4P_00", 3},
       {"D04_5P_00", 3},
       {"D05_6P_00", 3},
       {"D06_7P_00", 3},
       {"D07_8P_00", 3},
       {"D00_1P_00", 4},
       {"D01_2P_00", 4},
       {"D02_3P_00", 4},
       {"D03_4P_00", 4},
       {"D04_5P_00", 4},
       {"D05_6P_00", 4},
       {"D06_7P_00", 4},
       {"D07_8P_00", 4},
       {"E00_title", 5},
       {"E00_title", 6},
       {"E00_title", 7},
       {"A00_Window", 8}}
    );
    mLayout.TPaneNameRegister(
      300,
      {
        "T_info_01",
        "T_info_02",
        "T_infoS_00",
        "T_info_00",
        "T_info_03",
        "T_title_00",
      },
      {1, 2, 0, 0, 3, 5}
    );
    mpRootPane = mLayout.getRootPane();
    mLayout.NPaneRegister(
      &mpNInfo, {
                      "N_info_00",
                      "N_result_00",
                      "N_gameCannon_00",
                      "N_result_01",
                    }
    );
    mLayout.NPaneRegister(
      &mpN8pPos[0], {
                      "N_8P_Pos_00",
                      "N_8P_Pos_01",
                      "N_8P_Pos_02",
                      "N_8P_Pos_03",

                      "N_7P_Pos_00",
                      "N_7P_Pos_01",
                      "N_7P_Pos_02",

                      "N_6P_Pos_00",
                      "N_6P_Pos_01",

                      "N_5P_Pos_00",

                      "N_4P_Pos_10",
                      "N_4P_Pos_11",
                      "N_4P_Pos_12",
                      "N_4P_Pos_13",

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

                      "N_1P_00",
                      "N_2P_00",
                      "N_3P_00",
                      "N_4P_00",
                      "N_5P_00",
                      "N_6P_00",
                      "N_7P_00",
                      "N_8P_00",
                    }
    );
    mLayout.TPaneRegister(&mpTInfo, {"T_info_04", });
    mLayout.TPaneRegister(
      &mpT1up[0], {
                    "T_1Up_00",
                    "T_1Up_01",
                    "T_1Up_02",
                    "T_1Up_03",
                    "T_1Up_04",
                    "T_1Up_05",
                    "T_1Up_06",
                    "T_1Up_07",
                  }
    );
    mpTInfo->setMessage(dMessage_c::getMesRes(), 301, 7, 0);
    mLayout.PPaneRegister(&mpPBg, {"P_BG_00", "P_titleBase_00",});
    mLayout.PPaneRegister(
      &mpPPlayer[0], {
                       "P_1P_00",
                       "P_2P_00",
                       "P_3P_00",
                       "P_4P_00",
                       "P_5P_00",
                       "P_6P_00",
                       "P_7P_00",
                       "P_8P_00",
                     }
    );
    mLayout.WPaneRegister(&mpWGameCannon, {"W_gameCannon_00"});

    return true;
}

[[address(0x8078C140)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::preExecute()
{
    if (dBase_c::preExecute() == PACK_RESULT_e::NOT_READY) {
        return PACK_RESULT_e::NOT_READY;
    }

    return !dWarningManager_c::isWarning() ? PACK_RESULT_e::SUCCEEDED : PACK_RESULT_e::NOT_READY;
}

[[address(0x8078C180)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::execute()
{
    if (mReady && mActive) {
        mStateMgr.executeState();
        mLayout.AnimePlay();
        mLayout.calc();
    }
    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8078C200)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::draw()
{
    if (mReady && mActive) {
        mLayout.entry();
    }
    return PACK_RESULT_e::SUCCEEDED;
}

[[address(0x8078C240)]]
fBase_c::PACK_RESULT_e dMiniGameCannon_c::doDelete()
{
    return mLayout.doDelete();
}

[[address(0x8078C250)]]
int dMiniGameCannon_c::getPosPaneIdx(int player)
{
    int paneIdxArray[PLAYER_COUNT][PLAYER_COUNT] = {
        {23, 24, 24, 24, 24, 24, 24, 24},
        {21, 22, 24, 24, 24, 24, 24, 24},
        {18, 19, 20, 24, 24, 24, 24, 24},
        {14, 15, 16, 17, 24, 24, 24, 24},
        {10, 11, 12, 13, 9,  24, 24, 24},
        {10, 11, 12, 13, 7,  8,  24, 24},
        {10, 11, 12, 13, 4,  5,  6,  24},
        {10, 11, 12, 13, 0,  1,  2,  3},
    };
    return paneIdxArray[mNumPlayers-1][player];
}

[[address(0x8078C280)]]
void dMiniGameCannon_c::setPlayerPanePositions()
{
    for (std::size_t i = 0, j = 0; i < PLAYER_COUNT; i++) {
        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= 8) {
            continue;
        }

        int paneIdx = getPosPaneIdx(j);
        if (mPlayerEntry[i] && paneIdx != 24) {
            j++;

            nw4r::lyt::Pane* posPane = mpN8pPos[paneIdx];
            const auto& gmtx = posPane->GetGlobalMtx();
            mpNPlayer[playerType]->SetTranslate(nw4r::math::VEC3(gmtx[0][3], gmtx[1][3], 0.0));
            mpNPlayer[playerType]->SetScale(nw4r::math::VEC2(gmtx[0][0], gmtx[1][1]));
            mpT1up[playerType]->SetAlpha(posPane->GetGlobalAlpha());
            mpPPlayer[playerType]->SetAlpha(posPane->GetGlobalAlpha());
        }
    }
}

[[address(0x8078C3F0)]]
void dMiniGameCannon_c::setAllText()
{
    MsgRes_c* msgRes = dMessage_c::getMesRes();

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!mPlayerEntry[i]) {
            continue;
        }

        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= 8) {
            continue;
        }

        int rest = mNumWon[playerType];
        int digits = 1;
        for (int r = rest; r >= 10; digits++) {
            r /= 10;
        }
        wchar_t restStr[16];
        dMessage_c::itoaCustom(rest, restStr, std::size(restStr), digits, 0);
        mpT1up[playerType]->setMessage(msgRes, 300, 4, 1, restStr);
    }
}

[[address(0x8078C4D0)]]
bool dMiniGameCannon_c::isWin() const
{
    for (std::size_t i = 0; i < std::size(mNumWon); i++) {
        if (mNumWon[i] != 0) {
            return true;
        }
    }
    return false;
}

[[address(0x8078C530)]]
void dMiniGameCannon_c::initializeState_TitleOpenWait()
{
    mpRootPane->SetVisible(false);
    mAnimationActive = false;
    mCloseTitle = false;
}

[[address(0x8078C550)]]
void dMiniGameCannon_c::executeState_TitleOpenWait()
{
    if (!mIsTitleOpen) {
        return;
    }
    mIsTitleOpen = false;
    return mStateMgr.changeState(StateID_TitleOpenAnimeEndWait);
}

[[address(0x8078C590)]]
void dMiniGameCannon_c::finalizeState_TitleOpenWait()
{
}

[[address(0x8078C5A0)]]
void dMiniGameCannon_c::initializeState_TitleOpenAnimeEndWait()
{
    mpRootPane->SetVisible(true);
    mpPBg->SetVisible(false);
    mpNInfo->SetVisible(false);
    mpNResult->SetVisible(false);
    mpNResult2->SetVisible(false);
    mpWGameCannon->SetVisible(false);
    mpPTitleBase->SetVisible(true);
    for (std::size_t i = 0; i < std::size(mpNPlayer); i++) {
        mpNPlayer[i]->SetVisible(false);
    }
    mpNGameCannon->SetAlpha(255);
    mLayout.AllAnimeEndSetup();
    mLayout.AnimeStartSetup(19, false);
    mAnimationActive = true;
}

[[address(0x8078C6B0)]]
void dMiniGameCannon_c::executeState_TitleOpenAnimeEndWait()
{
    if (!mLayout.isAnime(-1)) {
        return mStateMgr.changeState(StateID_TitleDisp);
    }
}

[[address(0x8078C710)]]
void dMiniGameCannon_c::finalizeState_TitleOpenAnimeEndWait()
{
    mAnimationActive = false;
}

[[address(0x8078C720)]]
void dMiniGameCannon_c::initializeState_TitleDisp()
{
    mLayout.LoopAnimeStartSetup(20);
}

[[address(0x8078C730)]]
void dMiniGameCannon_c::executeState_TitleDisp()
{
    if (!mCloseTitle) {
        return;
    }
    return mStateMgr.changeState(StateID_TitleExitAnimeEndWait);
}

[[address(0x8078C760)]]
void dMiniGameCannon_c::finalizeState_TitleDisp()
{
    mLayout.AnimeEndSetup(20);
}

[[address(0x8078C770)]]
void dMiniGameCannon_c::initializeState_TitleExitAnimeEndWait()
{
    mLayout.AnimeStartSetup(21, false);
    mAnimationActive = true;
}

[[address(0x8078C7B0)]]
void dMiniGameCannon_c::executeState_TitleExitAnimeEndWait()
{
    if (!mLayout.isAnime(-1)) {
        mActive = false;
        return mStateMgr.changeState(StateID_StartWait);
    }
}

[[address(0x8078C810)]]
void dMiniGameCannon_c::finalizeState_TitleExitAnimeEndWait()
{
    mpRootPane->SetVisible(false);
    mpPBg->SetVisible(true);
    mpNInfo->SetVisible(true);
    mpNResult->SetVisible(true);
    mpWGameCannon->SetVisible(true);
    mpPTitleBase->SetVisible(false);
    mAnimationActive = false;
    mCloseOperate = false;
    mCloseResult = false;
}

[[address(0x8078C8A0)]]
void dMiniGameCannon_c::initializeState_StartWait()
{
}

[[address(0x8078C8B0)]]
void dMiniGameCannon_c::executeState_StartWait()
{
    if (!mIsWindowOpen) {
        return;
    }

    mIsWindowOpen = 0;
    return mStateMgr.changeState(StateID_OpenAnimeEndWait);
}

[[address(0x8078C8E0)]]
void dMiniGameCannon_c::finalizeState_StartWait()
{
    mNumPlayers = 0;
    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        if (dGameCom::PlayerEnterCheck(i)) {
            mPlayerEntry[i] = true;
            mNumPlayers++;
        } else {
            mPlayerEntry[i] = false;
        }
    }
}

[[address(0x8078C970)]]
void dMiniGameCannon_c::initializeState_OpenAnimeEndWait()
{
    mLayout.AllAnimeEndSetup();

    mpRootPane->SetVisible(true);
    if (mCurrentState == 0) {
        mpNInfo->SetVisible(true);
        mpNResult->SetVisible(false);
        mpNResult2->SetVisible(false);
        for (int i = 0; i < PLAYER_COUNT; i++) {
            mpNPlayer[i]->SetVisible(false);
        }
    } else {
        mpNInfo->SetVisible(false);
        if (isWin()) {
            for (int i = 0; i < PLAYER_COUNT; i++) {
                int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
                if (playerType >= 8) {
                    continue;
                }

                mpNPlayer[playerType]->SetVisible(true);
                mLayout.ReverseAnimeStartSetup(playerType + 3, false);
            }
            mpNResult->SetVisible(true);
            mpNResult2->SetVisible(false);
        } else {
            mpNResult->SetVisible(false);
            mpNResult2->SetVisible(true);
            for (int i = 0; i < PLAYER_COUNT; i++) {
                mpNPlayer[i]->SetVisible(false);
            }
        }
    }

    mLayout.AnimeStartSetup(0, false);
    mAnimationActive = true;
}

[[address(0x8078CB80)]]
void dMiniGameCannon_c::executeState_OpenAnimeEndWait()
{
    if (mLayout.isAllAnime()) {
        return;
    }

    const auto* id = &StateID_NowDisp;
    if (mCurrentState != 0) {
        if (isWin()) {
            id = &StateID_ResultDispAnimeEndWait;
        } else {
            id = &StateID_ResultNowDisp;
        }
    }

    return mStateMgr.changeState(*id);
}

[[address(0x8078CC40)]]
void dMiniGameCannon_c::finalizeState_OpenAnimeEndWait()
{
    mAnimationActive = false;
}

[[address(0x8078CC50)]]
void dMiniGameCannon_c::initializeState_NowDisp()
{
    mLayout.LoopAnimeStartSetup(2);
}

[[address(0x8078CC60)]]
void dMiniGameCannon_c::executeState_NowDisp()
{
    if (!mCloseOperate) {
        return;
    }

    return mStateMgr.changeState(StateID_ExitAnimeEndWait);
}

[[address(0x8078CC90)]]
void dMiniGameCannon_c::finalizeState_NowDisp()
{
    mLayout.AnimeEndSetup(2);
}

[[address(0x8078CCA0)]]
void dMiniGameCannon_c::initializeState_ResultDispAnimeEndWait()
{
    setPlayerPanePositions();
    setAllText();

    for (int i = 0; i < PLAYER_COUNT; i++) {
        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= 8) {
            continue;
        }

        if (!mPlayerEntry[playerType]) {
            mpNPlayer[playerType]->SetVisible(false);
            continue;
        }

        dGameCom::Player1upColor(mpT1up[playerType], playerType);
        mLayout.AnimeStartSetup(playerType + 3, false);
        mpNPlayer[playerType]->SetVisible(true);
    }

    mAnimationActive = true;
}

[[address(0x8078CE10)]]
void dMiniGameCannon_c::initializeState_ResultNowDisp()
{
    if (!isWin()) {
        return;
    }

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerEntry[i]) {
            int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
            if (playerType < 8) {
                mLayout.LoopAnimeStartSetup(playerType + 11);
            }
        }
    }
}

[[address(0x8078CE90)]]
void dMiniGameCannon_c::executeState_ResultNowDisp()
{
    if (!mCloseResult) {
        return;
    }
    return mStateMgr.changeState(StateID_ExitAnimeEndWait);
}

[[address(0x8078CEC0)]]
void dMiniGameCannon_c::finalizeState_ResultNowDisp()
{
    if (isWin()) {
        mLayout.AllAnimeEndSetup();
    }
}

[[address(0x8078CF00)]]
void dMiniGameCannon_c::initializeState_ExitAnimeEndWait()
{
    mLayout.AnimeStartSetup(22, false);
    mAnimationActive = true;
}

[[address(0x8078CF40)]]
void dMiniGameCannon_c::executeState_ExitAnimeEndWait()
{
    setPlayerPanePositions();
    if (!mLayout.isAnime(-1)) {
        mActive = false;
        return mStateMgr.changeState(StateID_StartWait);
    }
}

[[address(0x8078CFB0)]]
void dMiniGameCannon_c::finalizeState_ExitAnimeEndWait()
{
    mAnimationActive = false;
}
