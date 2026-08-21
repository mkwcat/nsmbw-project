// d_SelectPlayer.cpp
// NSMBW: 0x807ABE10 - 0x807AD5F0

#include "d_SelectPlayer.h"

#include "d_player/d_SelectCursor.h"
#include "d_static/d_game_common.h"
#include "d_static/d_game_key.h"
#include "d_static/d_game_key_core.h"
#include "d_static/d_info.h"
#include "machine/m_pad.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"
#include <revolution/wpad.h>

enum ANIM_ID_e {
    ANIM_ID_inWindow = 0,
    ANIM_ID_inInfoWindow = 1,
    ANIM_ID_onPlayerButton = 2,
    ANIM_ID_hitPlayerButton = 3,
    ANIM_ID_offPlayerButton = 4,
    ANIM_ID_outUnderGuide = 5,
    ANIM_ID_outWindow = 6,
    ANIM_ID_outWindowBack = 7,
};

enum GROUP_e {
    A00_Window_a_in = 0,
    B00_info_a_inInfo = 1,
    C00_Button1_a_on,
    C01_Button2_a_on,
    C02_Button3_a_on,
    C03_Button4_a_on,
    C04_Button5_a_on,
    C05_Button6_a_on,
    C06_Button7_a_on,
    C07_Button8_a_on,
    D00_Multi2_a_on,
    D01_Multi3_a_on,
    D02_Multi4_a_on,
    C00_Button1_a_hit,
    C01_Button2_a_hit,
    C02_Button3_a_hit,
    C03_Button4_a_hit,
    C04_Button5_a_hit,
    C05_Button6_a_hit,
    C06_Button7_a_hit,
    C07_Button8_a_hit,
    D00_Multi2_a_hit,
    D01_Multi3_a_hit,
    D02_Multi4_a_hit,
    C00_Button1_a_off,
    C01_Button2_a_off,
    C02_Button3_a_off,
    C03_Button4_a_off,
    C04_Button5_a_off,
    C05_Button6_a_off,
    C06_Button7_a_off,
    C07_Button8_a_off,
    D00_Multi2_a_off,
    D01_Multi3_a_off,
    D02_Multi4_a_off,
    B01_underGuide_a_out, // Originally 23
    A00_Window_a_out,
    A00_Window_a_outBack,

    GROUP_COUNT,
};

[[nsmbw(0x807ABE10)]]
dSelectPlayer_c* dSelectPlayer_c_classInit()
{
    return new dSelectPlayer_c();
}

[[nsmbw(0x807ABE40)]]
dSelectPlayer_c::dSelectPlayer_c();

[[nsmbw(0x807AC170)]]
fBase_c::PACK_RESULT_e dSelectPlayer_c::createLayout()
{
    if (mLayoutLoaded) {
        return PACK_RESULT_e::SUCCEEDED;
    }

    using StringArray = const char*[];
    using IntArray = const int[];

    mLayout.ReadResource("fileSelectPlayer/fileSelectPlayer.arc", false);
    mLayout.build("fileSelectPlayer_23.brlyt", nullptr);

    mLayout.AnimeResRegister(
      StringArray{
        "fileSelectPlayer_23_inWindow.brlan",
        "fileSelectPlayer_23_inInfoWindow.brlan",
        "fileSelectPlayer_23_onPlayerButton.brlan",
        "fileSelectPlayer_23_hitPlayerButton.brlan",
        "fileSelectPlayer_23_offPlayerButton.brlan",
        "fileSelectPlayer_23_outUnderGuide.brlan",
        "fileSelectPlayer_23_outWindow.brlan",
        "fileSelectPlayer_23_outWindowBack.brlan",
      },
      8
    );

    mLayout.GroupRegister(
      StringArray{
        "A00_Window",  "B00_info",    "C00_Button1", "C01_Button2", "C02_Button3", "C03_Button4",
        "C04_Button5", "C05_Button6", "C06_Button7", "C07_Button8", "D00_Multi2",  "D01_Multi3",
        "D02_Multi4",  "C00_Button1", "C01_Button2", "C02_Button3", "C03_Button4", "C04_Button5",
        "C05_Button6", "C06_Button7", "C07_Button8", "D00_Multi2",  "D01_Multi3",  "D02_Multi4",
        "C00_Button1", "C01_Button2", "C02_Button3", "C03_Button4", "C04_Button5", "C05_Button6",
        "C06_Button7", "C07_Button8", "D00_Multi2",  "D01_Multi3",  "D02_Multi4",  "B01_underGuide",
        "A00_Window",  "A00_Window",
      },
      IntArray{ANIM_ID_inWindow,        ANIM_ID_inInfoWindow,    ANIM_ID_onPlayerButton,
               ANIM_ID_onPlayerButton,  ANIM_ID_onPlayerButton,  ANIM_ID_onPlayerButton,
               ANIM_ID_onPlayerButton,  ANIM_ID_onPlayerButton,  ANIM_ID_onPlayerButton,
               ANIM_ID_onPlayerButton,  ANIM_ID_onPlayerButton,  ANIM_ID_onPlayerButton,
               ANIM_ID_onPlayerButton,  ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton,
               ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton,
               ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton,
               ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton, ANIM_ID_hitPlayerButton,
               ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton,
               ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton,
               ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton,
               ANIM_ID_offPlayerButton, ANIM_ID_offPlayerButton, ANIM_ID_outUnderGuide,
               ANIM_ID_outWindow,       ANIM_ID_outWindowBack},
      GROUP_COUNT
    );

    mLayout.PPaneRegister(
      StringArray{
        "P_1_00",
        "P_2_01",
        "P_3_01",
        "P_4_01",
        "P_5_01",
        "P_6_01",
        "P_7_01",
        "P_8_01",
        "P_2_02",
        "P_3_02",
        "P_4_02",
      },
      mpaButtons, 8 + 3
    );

    mLayout.NPaneRegister(
      StringArray{
        "N_playerNum_00",
        "N_playerMulti_00",
      },
      mpaRootPanes, 2
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_1_00",
        "T_1_01",
        "T_2_00",
        "T_2_01",
        "T_3_00",
        "T_3_01",
        "T_4_00",
        "T_4_01",
        "T_info_01",
        "T_info_00",
      },
      IntArray{
        0x02,
        0x02,
        0x03,
        0x03,
        0x04,
        0x04,
        0x05,
        0x05,
        0x00,
        0x00,
      },
      0x6B, 10
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_2_02",
        "T_2_03",
        "T_3_02",
        "T_3_03",
        "T_4_02",
        "T_4_03",
        "T_title_00",
      },
      IntArray{
        0x00,
        0x00,
        0x01,
        0x01,
        0x02,
        0x02,
        0x1E,
      },
      0x6C, 7
    );

    mLayout.TPaneNameRegister(
      StringArray{
        "T_back",
      },
      IntArray{
        0x1D,
      },
      0x2, 1
    );

    mLayout.mPriority = 8;

    // Set this here for now
    mMultiMode = false;

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x807AC3D0)]]
void dSelectPlayer_c::executeState_StartWait()
{
    if (!m0x26A) {
        return;
    }

    m0x26A = false;
    m0x26B = false;
    mActDirection = 0;
    mpaRootPanes[0]->SetVisible(!mMultiMode);
    mpaRootPanes[1]->SetVisible(mMultiMode);
    if (mMultiMode && mCurrentButton == 0) {
        mCurrentButton = 1;
    }

    return mStateMgr.changeState(StateID_OnStageAnimeEndWait);
}

[[nsmbw(0x807AC4A0)]]
void dSelectPlayer_c::initializeState_OnStageAnimeEndWait()
{
    mLayout.AllAnimeEndSetup();

    for (int i = A00_Window_a_in; i < C00_Button1_a_hit; i++) {
        mLayout.ReverseAnimeStartSetup(i, false);
    }

    mLayout.AnimeStartSetup(A00_Window_a_in, false);
}

[[nsmbw(0x807AC610)]]
void dSelectPlayer_c::initializeState_ButtonChangeAnimeEndWait()
{
    mButtonAnimeOff = mButtonAnimeOn;
    if (mButtonAnimeOn >= 0) {
        mButtonAnimeOff = mButtonAnimeOn + (C00_Button1_a_off - C00_Button1_a_on);
        mLayout.AnimeStartSetup(mButtonAnimeOff, false);

        SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_CURSOR, 1);
    }

    if (mMultiMode && mCurrentButton < 4) {
        mButtonAnimeOn = (mCurrentButton - 1) + D00_Multi2_a_on;
    } else {
        mButtonAnimeOn = mCurrentButton + C00_Button1_a_on;
    }

    mLayout.AnimeStartSetup(mButtonAnimeOn, false);
}

[[nsmbw(0x807AC6E0)]]
void dSelectPlayer_c::executeState_ButtonChangeAnimeEndWait()
{
    if (!mLayout.isAnime(-1)) {
        return mStateMgr.changeState(
          !mMultiMode ? StateID_StartMemberSelect : StateID_MultiStartMemberSelect
        );
    }
}

[[nsmbw(0x807AC780)]]
void dSelectPlayer_c::initializeState_StartMemberSelect()
{
    dGameCom::SelectCursorSetup(mpaButtons[mCurrentButton], 0, 0);
}

[[nsmbw(0x807AC7A0)]]
void dSelectPlayer_c::executeState_StartMemberSelect()
{
    dGameKeyCore_c* core = dGameKey_c::m_instance->mpCores[static_cast<int>(mPad::g_currentCoreID)];

    int leftBound = 0;
    int rightBound = 3;

    if (mCurrentButton >= 4) {
        leftBound = 4;
        rightBound = 7;
    }

    int nextButton = mCurrentButton;

    if (core->mTriggered & WPADButtonSideways::WPAD_SIDE_BUTTON_LEFT) {
        nextButton--;
        if (nextButton < leftBound) {
            nextButton = leftBound;
        }
    } else if (core->mTriggered & WPADButtonSideways::WPAD_SIDE_BUTTON_RIGHT) {
        nextButton++;
        if (nextButton > rightBound) {
            nextButton = rightBound;
        }
    } else if (nextButton < 4 && core->mTriggered & WPADButtonSideways::WPAD_SIDE_BUTTON_DOWN) {
        nextButton += 4;
    } else if (nextButton >= 4 && core->mTriggered & WPADButtonSideways::WPAD_SIDE_BUTTON_UP) {
        nextButton -= 4;
    }

    if (nextButton != mCurrentButton) {
        mCurrentButton = nextButton;
        mStateMgr.changeState(StateID_ButtonChangeAnimeEndWait);
        return;
    }

    if (mPad::g_currentCore->down(WPAD_BUTTON_A | WPAD_BUTTON_2)) {
        mActDirection = 1;
        mStateMgr.changeState(StateID_StartMemberButtonAnime);
        return;
    }

    if (dGameCom::chkCancelButton(0)) {
        mActDirection = -1;
        SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_BACK, 1);
        mStateMgr.changeState(StateID_ExitAnimeEndWait);
        return;
    }
}

[[nsmbw(0x807AC960)]]
void dSelectPlayer_c::initializeState_MultiStartMemberSelect()
{
    nw4r::lyt::Picture* pane;
    if (mCurrentButton > 4) {
        pane = mpaButtons[mCurrentButton];
    } else {
        pane = mpaButtons[mCurrentButton + 8];
    }

    dGameCom::SelectCursorSetup(pane, 0, 0);
}

// TODO
[[nsmbw(0x807AC980)]]
void dSelectPlayer_c::executeState_MultiStartMemberSelect();

[[nsmbw(0x807ACAD0)]]
void dSelectPlayer_c::initializeState_StartMemberButtonAnime()
{
    SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_DECIDE, 1);
    dSelectCursor_c::m_instance->Cancel(0);

    if (mMultiMode && mCurrentButton < 4) {
        mLayout.AnimeStartSetup(mCurrentButton + D00_Multi2_a_hit, false);
    } else {
        mLayout.AnimeStartSetup(mCurrentButton + C00_Button1_a_hit, false);
    }
}

[[nsmbw(0x807ACBD0)]]
void dSelectPlayer_c::initializeState_ExitAnimeEndWait()
{
    mLayout.AnimeStartSetup(B01_underGuide_a_out, false);
    if (mActDirection == 1) {
        mLayout.AnimeStartSetup(A00_Window_a_out, false);
    } else {
        mLayout.AnimeStartSetup(A00_Window_a_outBack, false);
    }
}

[[nsmbw(0x807ACC40)]]
void dSelectPlayer_c::executeState_ExitAnimeEndWait()
{
    if (!mLayout.isAnime(B01_underGuide_a_out) && !mLayout.isAnime(A00_Window_a_out) &&
        !mLayout.isAnime(A00_Window_a_outBack)) {
        mStateMgr.changeState(StateID_StartWait);
    }
}
