#pragma once

#include "d_system/d_2d.h"
#include "d_system/d_base.h"
#include "d_system/d_game_common.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include "d_system/d_mj2d_game.h"
#include "nw4r/lyt/Pane.h"
#include "nw4r/lyt/Window.h"
#include "state/s_FStateFct.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"
#include "state/s_State.h"

class dMultiCourseSelectContents_c;

class dMultiCourseSelect_c : public dBase_c
{
    SIZE_ASSERT(0x524 + 0xD0);

public:
    // Structors
    // ^^^^^^

    /* 0x80798950 */
    dMultiCourseSelect_c();

public:
    // Constants and Types
    // ^^^^^^

    enum class PANE_LIST_e {
        FIRST = 0,

        N_1Player_Pos_00 = 8,

        N_2PlayerPos_00 = 9,
        N_2PlayerPos_01 = 10,

        N_3Player_Pos_00 = 11,
        N_3Player_Pos_01 = 12,
        N_3Player_Pos_02 = 13,

        N_4Player_Pos_00 = 14,
        N_4Player_Pos_01 = 15,
        N_4Player_Pos_02 = 16,
        N_4Player_Pos_03 = 17,

        N_5Player_Pos_00 = 18,
        N_5Player_Pos_01 = 19,
        N_5Player_Pos_02 = 20,
        N_5Player_Pos_03 = 21,
        N_5Player_Pos_04 = 22,

        N_6Player_Pos_00 = 23,
        N_6Player_Pos_01 = 24,
        N_6Player_Pos_02 = 25,
        N_6Player_Pos_03 = 26,
        N_6Player_Pos_04 = 27,
        N_6Player_Pos_05 = 28,

        N_7Player_Pos_00 = 29,
        N_7Player_Pos_01 = 30,
        N_7Player_Pos_02 = 31,
        N_7Player_Pos_03 = 32,
        N_7Player_Pos_04 = 33,
        N_7Player_Pos_05 = 34,
        N_7Player_Pos_06 = 35,

        N_8Player_Pos_00 = 36,
        N_8Player_Pos_01 = 37,
        N_8Player_Pos_02 = 38,
        N_8Player_Pos_03 = 39,
        N_8Player_Pos_04 = 40,
        N_8Player_Pos_05 = 41,
        N_8Player_Pos_06 = 42,
        N_8Player_Pos_07 = 43,

        NONE = 44,
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807990D0 */
    bool createLayout();

    /* 0x807990D0.x */
    bool createLayoutExtra();

    /* 0x80799730 */
    void setPlayerPos();

    /* 0x80799E80 */
    void setContentCourseNo(int index, int count);

    /* 0x8079C410 */
    void getContentCourseNo(u8* worldNo, u8* courseNo, int index);

    PANE_LIST_e getPosPane(int playerCount, int player);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ d2d::ResAccMultLoader_c mContentsRes;
    /* 0x2DC */ dMultiCourseSelectContents_c* mpContents[20];
    /* 0x32C */ sStateMgr_c<dMultiCourseSelect_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    /* 0x368 */ nw4r::lyt::Pane* mpRootPane;
    /* 0x36C */ nw4r::lyt::Picture* mpPicturePanes[5];
    /* 0x380 */ nw4r::lyt::Pane* mpNullPanes[35];
    /* 0x40C */ LytTextBox_c* mpTextBoxes[7];
    /* 0x428 */ nw4r::lyt::Window* mpWindowPanes[5];

    FILL(0x43C, 0x4F4);

    /* 0x4F4 */ int mCurrentSelection;

    FILL(0x4F8, 0x50F);

    /* 0x50F */ bool mBeginCourse;
    /* 0x510 */ bool mExitWindowActive;

    FILL(0x511, 0x524);

    // New (added 0xD0 bytes)
    /* 0x524 */ nw4r::lyt::Pane* mpNPBase[PLAYER_COUNT];
    /* 0x544 */ nw4r::lyt::Pane* mpNPos1P;
    /* 0x548 */ nw4r::lyt::Pane* mpNPos2P[2];
    /* 0x550 */ nw4r::lyt::Pane* mpNPos3P[3];
    /* 0x55C */ nw4r::lyt::Pane* mpNPos4P[4];
    /* 0x56C */ nw4r::lyt::Pane* mpNPos5P[5];
    /* 0x580 */ nw4r::lyt::Pane* mpNPos6P[6];
    /* 0x598 */ nw4r::lyt::Pane* mpNPos7P[7];
    /* 0x5B4 */ nw4r::lyt::Pane* mpNPos8P[8];
    /* 0x5D4 */ LytTextBox_c* mpTRankStar[8];

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80993E88, dMultiCourseSelect_c, DispWait);
};