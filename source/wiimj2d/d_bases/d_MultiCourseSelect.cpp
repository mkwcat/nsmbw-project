// d_MultiCourseSelect.cpp
// NSMBW   d_bases.text:  0x80798920 - 0x8079D540

#include "d_bases/d_MultiCourseSelect.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_mj2d_header.h"
#include "d_system/d_save_manager.h"

[[nsmbw(0x80798920)]]
dMultiCourseSelect_c* dMultiCourseSelect_c_classInit()
{
    return new dMultiCourseSelect_c();
}

[[nsmbw(0x80798950)]]
dMultiCourseSelect_c::dMultiCourseSelect_c();

EXTERN_REPL(0x807990D0, bool dMultiCourseSelect_c::createLayout());

// Extra setup
[[nsmbw(0x807990D0)]]
bool dMultiCourseSelect_c::createLayoutExtra()
{
    if (!createLayout()) {
        return false;
    }

    mLayout.NPaneRegister(
      mpNPBase, //
      {
        "N_Pbase_00",       "N_Pbase_01",       "N_Pbase_03",       "N_Pbase_02",
        "N_Pbase_04",       "N_Pbase_05",       "N_Pbase_06",       "N_Pbase_07",

        "N_1Player_Pos_00",

        "N_2PlayerPos_00",  "N_2PlayerPos_01",

        "N_3Player_Pos_00", "N_3Player_Pos_01", "N_3Player_Pos_02",

        "N_4Player_Pos_00", "N_4Player_Pos_01", "N_4Player_Pos_02", "N_4Player_Pos_03",

        "N_5Player_Pos_00", "N_5Player_Pos_01", "N_5Player_Pos_02", "N_5Player_Pos_03",
        "N_5Player_Pos_04",

        "N_6Player_Pos_00", "N_6Player_Pos_01", "N_6Player_Pos_02", "N_6Player_Pos_03",
        "N_6Player_Pos_04", "N_6Player_Pos_05",

        "N_7Player_Pos_00", "N_7Player_Pos_01", "N_7Player_Pos_02", "N_7Player_Pos_03",
        "N_7Player_Pos_04", "N_7Player_Pos_05", "N_7Player_Pos_06",

        "N_8Player_Pos_00", "N_8Player_Pos_01", "N_8Player_Pos_02", "N_8Player_Pos_03",
        "N_8Player_Pos_04", "N_8Player_Pos_05", "N_8Player_Pos_06", "N_8Player_Pos_07",
      }
    );

    mLayout.TPaneRegister(
      mpTRankStar, //
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

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mpNPBase[i]->SetVisible(!!(dInfo_c::mGameFlag & dInfo_c::GameFlag_e::COIN_BATTLE));
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

[[nsmbw(0x80799730)]]
void dMultiCourseSelect_c::setPlayerPos()
{
    int playerCount = 0;
    int playerIdx = 0;

    // Get how many we have
    for (int type = 0; type < CHARACTER_COUNT; type++) {
        int player = daPyMng_c::findPlayerWithType(static_cast<PLAYER_TYPE_e>(type));
        bool isActive = dGameCom::PlayerEnterCheck(player);

        if (isActive) {
            playerCount++;
            mpNPBase[type]->SetVisible(true);
        } else {
            mpNPBase[type]->SetVisible(false);
        }
    }

    for (int type = 0; type < CHARACTER_COUNT; type++) {
        int paneIdx = static_cast<int>(getPosPane(playerCount, playerIdx));
        int player = daPyMng_c::findPlayerWithType(static_cast<PLAYER_TYPE_e>(type));
        bool isActive = dGameCom::PlayerEnterCheck(player);

        if (isActive && (paneIdx != static_cast<int>(PANE_LIST_e::NONE))) {
            playerIdx++;
            mpNPBase[type]->SetTranslate(mpNPBase[paneIdx]->GetTranslate());
        }
    }

    // New, move the guide text if we have more than 5 players
    if (playerCount > 5) {
        nw4r::lyt::Pane* N_guideViewR_00;
        mLayout.NPaneRegister(&N_guideViewR_00, {"N_guideViewR_00"});
        N_guideViewR_00->SetSRTElement(1, -212.0);
    }
}

[[nsmbw(0x80799F60)]]
void dMultiCourseSelect_c::initializeState_DispWait()
{
    mLayout.AllAnimeEndSetup();
    mLayout.ReverseAnimeStartSetup(3);  // IN_ARROW_L
    mLayout.ReverseAnimeStartSetup(4);  // IN_ARROW_R
    mLayout.ReverseAnimeStartSetup(5);  // IN_ARROW_CL
    mLayout.ReverseAnimeStartSetup(6);  // IN_ARROW_CR
    mLayout.ReverseAnimeStartSetup(1);  // IN_PAUSE
    mLayout.ReverseAnimeStartSetup(0);  // IN_WINDOW
    mLayout.ReverseAnimeStartSetup(28); // TO_PAGE_NEXT
    mLayout.LoopAnimeStartSetup(30);    // LOOP_BG

    // Backup player types
    PLAYER_TYPE_e plyTypeBackup[PLAYER_COUNT] = {};
    for (int i = 0; i < PLAYER_COUNT; i++) {
        plyTypeBackup[i] = daPyMng_c::mPlayerType[i];
    }

    // Refresh save data
    dSaveMng_c *saveMng = dSaveMng_c::m_instance;
    u8 slot = saveMng->mData.mHeader.getSelectFileNo();
    dMj2dGame_c *save = saveMng->getSaveGame(slot);
    save->initialize();
    saveMng->initLoadGame(slot);

    // Restore them
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPyMng_c::mPlayerType[i] = plyTypeBackup[i];
    }

    // Init favorites (dummy data that tells them to be invisible)
    for (int i = 0; i < 10; i++) {
        mFavorites[i].initialize();
    }

    dInfo_c *info = dInfo_c::m_instance;
    mCurrPage = info->mMultiCurrPage;
    mCurrButton = info->mMultiCurrButton;

    // Populate favorites
    int playCount;
    dMj2dHeader_c saveHeader = dSaveMng_c::m_instance->mData.mHeader;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 38; j++) {
            if (!(info->mGameFlag & dInfo_c::GameFlag_e::FREE_FOR_ALL)) {
                playCount = saveHeader.getPlayCountCoinBattle(static_cast<WORLD_e>(i), static_cast<STAGE_e>(j));
            } else {
                playCount = saveHeader.getPlayCountFreeMode(static_cast<WORLD_e>(i), static_cast<STAGE_e>(j));
            }

            if (playCount != 0) {
                dMultiCourseSelect_c::setFavoriteCourse(i, j, playCount);
            }
        }
    }

    int world;
    int level;
    dInfo_c::MultiCourse_s backupFavs[10] = {};
    if (!(info->mGameFlag & dInfo_c::GameFlag_e::COIN_BATTLE)) {
        world = info->mFreeCourse[mCurrPage][mCurrButton].mWorld;
        level = info->mFreeCourse[mCurrPage][mCurrButton].mLevel;

        for (int i = 0; i < 10; i++) {
            backupFavs[i].mWorld = info->mFreeFavorite[i].mWorld;
            backupFavs[i].mLevel = info->mFreeFavorite[i].mLevel;
            backupFavs[i].mClearState = info->mFreeFavorite[i].mClearState;

            info->mFreeFavorite[i].mWorld = WORLD_COUNT;
            info->mFreeFavorite[i].mLevel = STAGE_COUNT;
            info->mFreeFavorite[i].mClearState = dInfo_c::MultiClearState_e::NONE;
        }
    } else {
        world = info->mCoinCourse[mCurrPage][mCurrButton].mWorld;
        level = info->mCoinCourse[mCurrPage][mCurrButton].mLevel;

        for (int i = 0; i < 10; i++) {
            backupFavs[i].mWorld = info->mCoinFavorite[i].mWorld;
            backupFavs[i].mLevel = info->mCoinFavorite[i].mLevel;
            backupFavs[i].mClearState = info->mCoinFavorite[i].mClearState;

            info->mCoinFavorite[i].mWorld = WORLD_COUNT;
            info->mCoinFavorite[i].mLevel = STAGE_COUNT;
            info->mCoinFavorite[i].mClearState = dInfo_c::MultiClearState_e::NONE;
        }
    }

    // If returning from a favorited course, select the one we played
    if (mCurrPage == 10) {
        for (int i = 0; i < 10; i++) {
            if (world == mFavorites[i].mWorldNo && level == mFavorites[i].mStageNo) {
                mCurrButton = i;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        world = mFavorites[i].mWorldNo;
        level = mFavorites[i].mStageNo;
        mFavorites[i].mClearState = 0;

        for (int j = 0; j < 10; j++) {
            if (world == backupFavs[j].mWorld && level == backupFavs[j].mLevel) {
                mFavorites[i].mClearState = static_cast<int>(backupFavs[j].mClearState);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        world = mFavorites[i].mWorldNo;
        level = mFavorites[i].mStageNo;
        int clearState = mFavorites[i].mClearState;

        if (!(dInfo_c::mGameFlag & dInfo_c::GameFlag_e::COIN_BATTLE)) {
            info->mFreeCourse[0][i].mWorld = world;
            info->mFreeCourse[0][i].mLevel = level;
            info->mFreeCourse[0][i].mClearState = static_cast<dInfo_c::MultiClearState_e>(clearState);
        } else {
            info->mCoinCourse[0][i].mWorld = world;
            info->mCoinCourse[0][i].mLevel = level;
            info->mCoinCourse[0][i].mClearState = static_cast<dInfo_c::MultiClearState_e>(clearState);
        }
    }

    setContentCourseNo(0, 0x14);
}

[[nsmbw(0x8079A7A0)]]
void dMultiCourseSelect_c::finalizeState_DispWait()
{
    dInfo_c* info = dInfo_c::m_instance;

    for (int playerType = 0; playerType < CHARACTER_COUNT; playerType++) {
        int winCount = 0;

        if (playerType < 4) {
            winCount = info->mCoinBattleWin[playerType];
        } else {
            winCount = info->mExCoinBattleWin[playerType - 4];
        }

        dGameCom::LayoutDispNumberDigit(winCount, mpTRankStar[playerType], false);
    }

    setContentCourseNo(0, 0x14);
}

[[nsmbw(0x80799E80)]]
void dMultiCourseSelect_c::setContentCourseNo(int index, int count);

[[nsmbw(0x8079C410)]]
void dMultiCourseSelect_c::getContentCourseNo(u8* worldNo, u8* courseNo, int index);

[[nsmbw(0x80799DF0)]]
void dMultiCourseSelect_c::setFavoriteCourse(int worldNo, int courseNo, int playCount);
