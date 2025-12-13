// d_MultiCourseSelect.cpp
// NSMBW   d_bases.text:  0x80798920 - 0x8079D540

#include "d_bases/d_MultiCourseSelect.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"

[[address(0x80798920)]]
dMultiCourseSelect_c* dMultiCourseSelect_c_classInit()
{
    return new dMultiCourseSelect_c();
}

[[address(0x80798950)]]
dMultiCourseSelect_c::dMultiCourseSelect_c();

EXTERN_REPL(0x807990D0, bool dMultiCourseSelect_c::createLayout());

// Extra setup
[[address(0x807990D0)]]
bool dMultiCourseSelect_c::createLayoutExtra()
{
    if (!createLayout()) {
        return false;
    }

    mLayout.NPaneRegister(
      mpNPBase,
      {
        "N_Pbase_00",
        "N_Pbase_01",
        "N_Pbase_03",
        "N_Pbase_02",
        "N_Pbase_04",
        "N_Pbase_05",
        "N_Pbase_06",
        "N_Pbase_07",

        "N_1Player_Pos_00",

        "N_2PlayerPos_00",
        "N_2PlayerPos_01",

        "N_3Player_Pos_00",
        "N_3Player_Pos_01",
        "N_3Player_Pos_02",

        "N_4Player_Pos_00",
        "N_4Player_Pos_01",
        "N_4Player_Pos_02",
        "N_4Player_Pos_03",

        "N_5Player_Pos_00",
        "N_5Player_Pos_01",
        "N_5Player_Pos_02",
        "N_5Player_Pos_03",
        "N_5Player_Pos_04",

        "N_6Player_Pos_00",
        "N_6Player_Pos_01",
        "N_6Player_Pos_02",
        "N_6Player_Pos_03",
        "N_6Player_Pos_04",
        "N_6Player_Pos_05",

        "N_7Player_Pos_00",
        "N_7Player_Pos_01",
        "N_7Player_Pos_02",
        "N_7Player_Pos_03",
        "N_7Player_Pos_04",
        "N_7Player_Pos_05",
        "N_7Player_Pos_06",

        "N_8Player_Pos_00",
        "N_8Player_Pos_01",
        "N_8Player_Pos_02",
        "N_8Player_Pos_03",
        "N_8Player_Pos_04",
        "N_8Player_Pos_05",
        "N_8Player_Pos_06",
        "N_8Player_Pos_07",
      }
    );

    mLayout.TPaneRegister(
      mpTRankStar,
      {
            "T_rankStar_00",
            "T_rankStar_01",
            "T_rankStar_02",
            "T_rankStar_03",
            "T_rankStar_04",
            "T_rankStar_05",
            "T_rankStar_06",
            "T_rankStar_07",
        }
    );

    bool isCoin = (dInfo_c::mGameFlag & 0x20) == 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mpNPBase[i]->SetVisible(isCoin);
    }

    // Adjust position of the exit prompt for Free Mode
    if (!isCoin) {
        nw4r::lyt::Pane* N_guideViewR_00;
        mLayout.NPaneRegister(&N_guideViewR_00, {"N_guideViewR_00"});
        N_guideViewR_00->SetSRTElement(1, -175.0);
    }
    return true;
}

dMultiCourseSelect_c::PANE_LIST_e dMultiCourseSelect_c::getPosPane(int playerCount, int player)
{
    using PaneList = PANE_LIST_e[8][8];

    PANE_LIST_e posPane = PaneList{
      {
        PANE_LIST_e::N_1Player_Pos_00,
      },
      {
        PANE_LIST_e::N_2PlayerPos_00,
        PANE_LIST_e::N_2PlayerPos_01,
      },
      {
        PANE_LIST_e::N_3Player_Pos_00,
        PANE_LIST_e::N_3Player_Pos_01,
        PANE_LIST_e::N_3Player_Pos_02,
      },
      {
        PANE_LIST_e::N_4Player_Pos_00,
        PANE_LIST_e::N_4Player_Pos_01,
        PANE_LIST_e::N_4Player_Pos_02,
        PANE_LIST_e::N_4Player_Pos_03,
      },
      {
        PANE_LIST_e::N_5Player_Pos_00,
        PANE_LIST_e::N_5Player_Pos_01,
        PANE_LIST_e::N_5Player_Pos_02,
        PANE_LIST_e::N_5Player_Pos_03,
        PANE_LIST_e::N_5Player_Pos_04,
      },
      {
        PANE_LIST_e::N_6Player_Pos_00,
        PANE_LIST_e::N_6Player_Pos_01,
        PANE_LIST_e::N_6Player_Pos_02,
        PANE_LIST_e::N_6Player_Pos_03,
        PANE_LIST_e::N_6Player_Pos_04,
        PANE_LIST_e::N_6Player_Pos_05,
      },
      {
        PANE_LIST_e::N_7Player_Pos_00,
        PANE_LIST_e::N_7Player_Pos_01,
        PANE_LIST_e::N_7Player_Pos_02,
        PANE_LIST_e::N_7Player_Pos_03,
        PANE_LIST_e::N_7Player_Pos_04,
        PANE_LIST_e::N_7Player_Pos_05,
        PANE_LIST_e::N_7Player_Pos_06,
      },
      {
        PANE_LIST_e::N_8Player_Pos_00,
        PANE_LIST_e::N_8Player_Pos_01,
        PANE_LIST_e::N_8Player_Pos_02,
        PANE_LIST_e::N_8Player_Pos_03,
        PANE_LIST_e::N_8Player_Pos_04,
        PANE_LIST_e::N_8Player_Pos_05,
        PANE_LIST_e::N_8Player_Pos_06,
        PANE_LIST_e::N_8Player_Pos_07,
      },
    }[playerCount - 1][player];

    if (posPane == PANE_LIST_e::FIRST) {
        posPane = PANE_LIST_e::NONE;
    }

    return posPane;
}

[[address(0x80799730)]]
void dMultiCourseSelect_c::setPlayerPos()
{
    int playerCount = 0;
    int playerIdx = 0;

    // Get how many we have
    for (int i = 0; i < PLAYER_COUNT; i++) {
        int player = daPyMng_c::findPlayerWithType((PLAYER_TYPE_e)i);
        bool isActive = dGameCom::PlayerEnterCheck(player);

        if (isActive) {
            playerCount++;
            mpNPBase[i]->SetVisible(true);
        } else {
            mpNPBase[i]->SetVisible(false);
        }
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        int paneIdx = static_cast<int>(getPosPane(playerCount, playerIdx));
        int player = daPyMng_c::findPlayerWithType((PLAYER_TYPE_e)i);
        bool isActive = dGameCom::PlayerEnterCheck(player);

        if (isActive && (paneIdx != static_cast<int>(PANE_LIST_e::NONE))) {
            playerIdx++;
            mpNPBase[i]->SetTranslate(mpNPBase[paneIdx]->GetTranslate());
        }
    }

    // New, move the guide text if we have more than 5 players
    nw4r::lyt::Pane* N_guideViewR_00;
    mLayout.NPaneRegister(&N_guideViewR_00, {"N_guideViewR_00"});

    f32 transY = -175.0;
    if (playerCount > 5) {
        transY = -212.0;
    }
    N_guideViewR_00->SetSRTElement(1, transY);
}

[[address(0x8079A7A0)]]
void dMultiCourseSelect_c::finalizeState_DispWait()
{
    dInfo_c* info = dInfo_c::m_instance;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        int winCount = 0;
        int playerType = daPyMng_c::mPlayerType[i];

        if (playerType < 4) {
            winCount = info->mCoinBattleWin[playerType];
        } else {
            winCount = info->mExCoinBattleWin[playerType - 4];
        }

        dGameCom::LayoutDispNumberDigit(winCount, mpTRankStar[playerType], false);
    }

    setContentCourseNo(0, 0x14);
}

[[address(0x80799E80)]]
void dMultiCourseSelect_c::setContentCourseNo(int index, int count);

[[address(0x8079C410)]]
void dMultiCourseSelect_c::getContentCourseNo(u8* worldNo, u8* courseNo, int index);