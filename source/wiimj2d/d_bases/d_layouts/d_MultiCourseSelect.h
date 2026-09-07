#pragma once

#include "d_2d.h"
#include "d_base.h"
#include "d_game_common.h"
#include "d_lytbase.h"
#include "d_lyttextbox.h"
#include "d_mj2d_game.h"
#include "s_FStateFct.h"
#include "s_State.h"
#include "s_StateMethodUsr_FI.h"
#include "s_StateMgr.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Window.h>

class dMultiCourseSelectContents_c;

class dMultiCourseSelect_c : public dBase_c {
    // Original size: 0x524
    VTABLE(0x060, fBase_c, 0x80949BD0);
    // 0x80949450 g_profile_MULTI_COURSE_SELECT
    // 0x80798920 dMultiCourseSelect_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80798950 */
    dMultiCourseSelect_c();

public:
    // Constants and Types
    // ^^^^^^

    enum class PANE_LIST_e {
        FIRST            = 0,

        N_1Player_Pos_00 = 8,

        N_2PlayerPos_00  = 9,
        N_2PlayerPos_01  = 10,

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

        NONE             = 44,
    };

    struct FavoriteCourse_s {
    public:
        SIZE_ASSERT(0x10);

        /* 0x00 */ int mWorldNo;
        /* 0x04 */ int mStageNo;
        /* 0x08 */ u16 mPlayCount;
        /* 0x0C */ int mClearState;

        void initialize() {
            mWorldNo   = WORLD_COUNT;
            mStageNo   = STAGE_COUNT;
            mPlayCount = 0;
        }
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

    /* 0x80799DF0 */
    void setFavoriteCourse(int worldNo, int courseNo, int playCount);

    PANE_LIST_e getPosPane(int playerCount, int player);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c                     mLayout;
    /* 0x208 */ d2d::ResAccMultLoader_c       mContentsRes;
    /* 0x2DC */ dMultiCourseSelectContents_c* mpContents[20];
    /* 0x32C */ sStateMgr_c<dMultiCourseSelect_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
                                    mStateMgr;

    /* 0x368 */ nw4r::lyt::Pane*    mpRootPane;
    /* 0x36C */ nw4r::lyt::Picture* mpPicturePanes[5];
    /* 0x380 */ nw4r::lyt::Pane*    mpNullPanes[35];
    /* 0x40C */ LytTextBox_c*       mpTextBoxes[7];
    /* 0x428 */ nw4r::lyt::Window*  mpWindowPanes[5];

    FILL(0x43C, 0x440);

    /* 0x400 */ FavoriteCourse_s mFavorites[10];

    FILL(0x4E0, 0x4F4);

    /* 0x4F4 */ int mCurrButton;

    FILL(0x4F8, 0x500);

    /* 0x500 */ int mCurrPage;

    FILL(0x504, 0x50F);

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
    /* 0x5D4 */ LytTextBox_c*    mpTRankStar[8];

    FILL(0x070, 0x524);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80799F60
     * executeState:    0x8079A670
     * finalizeState:   0x8079A7A0
     */
    sState_Extern(0x80993E88, dMultiCourseSelect_c, DispWait);

    /*
     * initializeState: 0x8079A840
     * executeState:    0x8079A880
     * finalizeState:   0x8079A960
     */
    sState_Extern(0x80993EC8, dMultiCourseSelect_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x8079A980
     * executeState:    0x8079A9A0
     * finalizeState:   0x8079A9E0
     */
    sState_Extern(0x80993F08, dMultiCourseSelect_c, ClearWaKuAnimeEndWait);

    /*
     * initializeState: 0x8079A9F0
     * executeState:    0x8079ABC0
     * finalizeState:   0x8079ACE0
     */
    sState_Extern(0x80993F48, dMultiCourseSelect_c, ArrowOnStageExitAnimeEndWait);

    /*
     * initializeState: 0x8079AE60
     * executeState:    0x8079AEE0
     * finalizeState:   0x8079AF40
     */
    sState_Extern(0x80993F88, dMultiCourseSelect_c, ChangeAnimeEndWait);

    /*
     * initializeState: 0x8079AF50
     * executeState:    0x8079AF70
     * finalizeState:   0x8079B190
     */
    sState_Extern(0x80993FC8, dMultiCourseSelect_c, keyWait);

    /*
     * initializeState: 0x8079B1B0
     * executeState:    0x8079B1C0
     * finalizeState:   0x8079B320
     */
    sState_Extern(0x80994008, dMultiCourseSelect_c, SuccessionKeyWait);

    /*
     * initializeState: 0x8079B340
     * executeState:    0x8079B450
     * finalizeState:   0x8079B510
     */
    sState_Extern(0x80994048, dMultiCourseSelect_c, WorldSelectBeforeButtonReturn);

    /*
     * initializeState: 0x8079B5C0
     * executeState:    0x8079B5D0
     * finalizeState:   0x8079B730
     */
    sState_Extern(0x80994088, dMultiCourseSelect_c, WorldSelect);

    /*
     * initializeState: 0x8079B750
     * executeState:    0x8079B760
     * finalizeState:   0x8079B920
     */
    sState_Extern(0x809940C8, dMultiCourseSelect_c, SuccessionWorldSelect);

    /*
     * initializeState: 0x8079B930
     * executeState:    0x8079BA20
     * finalizeState:   0x8079BAC0
     */
    sState_Extern(0x80994108, dMultiCourseSelect_c, CrossMarkToReturnArrow);

    /*
     * initializeState: 0x8079BB50
     * executeState:    0x8079BB80
     * finalizeState:   0x8079BBF0
     */
    sState_Extern(0x80994148, dMultiCourseSelect_c, WorldSelectArrowAnimeEndWait);

    /*
     * initializeState: 0x8079BC00
     * executeState:    0x8079BC70
     * finalizeState:   0x8079BD10
     */
    sState_Extern(0x80994188, dMultiCourseSelect_c, NextPageBeforeButtonReturn);

    /*
     * initializeState: 0x8079BD20
     * executeState:    0x8079BDC0
     * finalizeState:   0x8079BEB0
     */
    sState_Extern(0x809941C8, dMultiCourseSelect_c, NextPageScroll);

    /*
     * initializeState: 0x8079BF80
     * executeState:    0x8079BFB0
     * finalizeState:   0x8079BFF0
     */
    sState_Extern(0x80994208, dMultiCourseSelect_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8079C000
     * executeState:    0x8079C010
     * finalizeState:   0x8079C100
     */
    sState_Extern(0x80994248, dMultiCourseSelect_c, ExitAnimeEndWait);

    /*
     * initializeState: 0x8079C110
     * executeState:    0x8079C1E0
     * finalizeState:   0x8079C1F0
     */
    sState_Extern(0x80994288, dMultiCourseSelect_c, NextSceneWait);

    /*
     * initializeState: 0x8079C200
     * executeState:    0x8079C2B0
     * finalizeState:   0x8079C3D0
     */
    sState_Extern(0x809942C8, dMultiCourseSelect_c, PauseWait);
};
