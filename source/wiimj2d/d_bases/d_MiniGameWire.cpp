// d_MiniGameWire.cpp
// NSMBW   d_bases.text:  0x8078DA20 - 0x80790450

#include "d_MiniGameWire.h"
#include "d_system/d_mj2d_game.h"

[[address(0x8078DA20)]]
dMiniGameWire_c* dMiniGameWire_c_classInit()
{
    return new dMiniGameWire_c();
}

[[address(0x8078DA50)]]
dMiniGameWire_c::dMiniGameWire_c();

[[address(0x8078DE20)]]
bool dMiniGameWire_c::createLayout() {
    if (!mLayout.ReadResource("miniGameWire/miniGameWire.arc", false)) {
        return false;
    }

    mLayout.build("miniGameWire_12.brlyt", nullptr);

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.AnimeResRegister(
      StringArray{
        "miniGameWire_12_inWindow.brlan",
        "miniGameWire_12_loopWindow.brlan",
        "miniGameWire_12_loopDokiDoki.brlan",
        "miniGameWire_12_inItem.brlan",
        "miniGameWire_12_loopGetNum.brlan",
        "miniGameWire_12_inTitle.brlan",
        "miniGameWire_12_weitTitle.brlan",
        "miniGameWire_12_outTitle.brlan",
        "miniGameWire_12_inTurnBase.brlan",
        "miniGameWire_12_loopTurnBase.brlan",
        "miniGameWire_12_inFaceIcon.brlan",
        "miniGameWire_12_loopFaceIcon.brlan",
        "miniGameWire_12_outFaceIcon.brlan",
        "miniGameWire_12_outTurnBase.brlan",
        "miniGameWire_12_outWindow.brlan",
      },
      0xF
    );

    mLayout.GroupRegister(
      StringArray{
        "A00_Window",
        "A00_Window",
        "B00_DokiDoki",
        "C00_Skino_00",
        "C01_fire_00",
        "C02_pro_00",
        "C05_ice_00",
        "C03_pen_00",
        "C04_mame_00",
        "C06_star_00",
        "C00_Skino_00",
        "C01_fire_00",
        "C02_pro_00",
        "C05_ice_00",
        "C03_pen_00",
        "C04_mame_00",
        "C06_star_00",
        "D00_title",
        "D00_title",
        "D00_title",
        "E00_turnBase",
        "E00_turnBase",
        "E01_Icon",
        "E01_Icon",
        "E01_Icon",
        "E00_turnBase",
        "A00_Window",
      },
      IntArray{
        0,
        1,
        2,
        3,
        3,
        3,
        3,
        3,
        3,
        3,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        5,
        6,
        7,
        8,
        9,
        0xA,
        0xB,
        0xC,
        0xD,
        0xE,
      },
      0x1B
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_info_02",
        "T_info_01",
        "T_info_03",
        "T_info_04",
        "T_turnS_00",
        "T_turn_00",
        "T_title_00",
        "T_itemInfo_00",
        "T_infoS_01",
      },
      IntArray{
        6,
        1,
        2,
        7,
        8,
        8,
        4,
        9,
        9,
      },
      0x12D, 9
    );

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
      mpNullPanes,
      {
        "N_6P_Pos_00", "N_6P_Pos_00", "N_6P_Pos_00", "N_6P_Pos_00", "N_6P_Pos_00", "N_6P_Pos_00", "N_6P_Pos_00",
        "N_6P_Pos_00", "N_6P_Pos_01", "N_6P_Pos_02", "N_6P_Pos_03", "N_6P_Pos_04", "N_6P_Pos_05",
        "N_5P_Pos_00", "N_5P_Pos_01", "N_5P_Pos_02", "N_5P_Pos_03", "N_5P_Pos_04",
        "N_4P_Pos_00", "N_4P_Pos_01", "N_4P_Pos_02", "N_4P_Pos_03",
        "N_3P_Pos_00", "N_3P_Pos_01", "N_3P_Pos_02",
        "N_2P_Pos_00", "N_2P_Pos_01",
        "N_1P_Pos_00",
        "N_info_00",
        "N_result_00", "N_result_01",
        "N_gameWire_00",
        "N_faceIcon_00",
        "N_Skino_00", "N_fire_00", "N_pro_00", "N_ice_00", "N_pen_00", "N_mame_00", "N_star_00",
      }
    );

    mLayout.TPaneRegister(
      mpTextBoxes,
      {
        "T_xNum_00",
        "T_xNum_01",
        "T_xNum_02",
        "T_xNum_05",
        "T_xNum_03",
        "T_xNum_04",
        "T_xNum_06",
        "T_infoS_00",
        "T_info_00",
      }
    );

    mLayout.PPaneRegister(
      mpPicturePanes,
      {
        "P_Skino_00", "P_fire_00", "P_pro_00", "P_ice_00", "P_pen_00", "P_mame_00", "P_star_00",
        "P_BG_00",
        "P_mario_00", "P_luigi_00", "P_kinoB_00", "P_kinoY_00",
        "P_titleBase_00",
        "P_dokiMark_01",
        "P_dokiMarkJr_00",
      }
    );

    mLayout.WPaneRegister(
      mpWindowPanes,
      {
        "W_turnS_00",
        "W_gameWire_00",
      }
    );

    mLayout.PPaneRegister(
      mpExFaceIcon,
      {
        "P_mario_00",
        "P_luigi_00",
        "P_kinoB_00",
        "P_kinoY_00",
        "P_kinopico_00",
        "P_Player_05",
        "P_Player_06",
        "P_Player_07",
      }
    );

    for (int i = 0; i < PLAYER_COUNT; i++) {
        mpExFaceIcon[i]->SetVisible(false);
    }

    return true;
}

[[address(0x8078E2B0)]]
void dMiniGameWire_c::setTurnFaceIcon() {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        mpExFaceIcon[i]->SetVisible(false);
    }

    mpExFaceIcon[mCurrentTurn]->SetVisible(true);
}