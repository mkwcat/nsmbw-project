#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"

class dMiniGameCannon_c : public dBase_c {
    // Original size: 0x2E8
    VTABLE(0x060, fBase_c, 0x80946268);
    // 0x80945DF8 g_profile_MINI_GAME_CANNON
    // 0x8078BC60 dMiniGameCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8078BC90 */
    dMiniGameCannon_c();

    /**
     * VT+0x48 0x8078BEA0
     * Destroys the base.
     */
    ~dMiniGameCannon_c() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8078C000 */
    bool createLayout();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x8078BF30
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x14 0x8078C240
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20 0x8078C180
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

    /**
     * VT+0x24 0x8078C140
     * pre method for the execute operation.
     */
    PACK_RESULT_e preExecute() override;

    /**
     * VT+0x2C 0x8078C200
     * do method for the draw operation.
     */
    PACK_RESULT_e draw() override;

public:
    // Instance Variables
    // ^^^^^^

    /* 0x8078C250 */
    int getPosPaneIdx(int player);

    /* 0x8078C280 */
    void setPlayerPanePositions();

    /* 0x8078C3F0 */
    void setAllText();

    /* 0x8078C4D0 */
    bool isWin() const;

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c                             mLayout;
    /* 0x208 */ sStateMgrDefault_c<dMiniGameCannon_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane*                      mpRootPane;

    /* 0x248 */ nw4r::lyt::Pane*                      REMOVED(mpN4pPos)[4];
    /* 0x258 */ nw4r::lyt::Pane*                      REMOVED(mpN3pPos)[3];
    /* 0x264 */ nw4r::lyt::Pane*                      REMOVED(mpN2pPos)[2];
    /* 0x26C */ nw4r::lyt::Pane*                      REMOVED(mpN1pPos);
    /* 0x270 */ nw4r::lyt::Pane*                      mpNInfo;
    /* 0x274 */ nw4r::lyt::Pane*                      mpNResult;
    /* 0x278 */ nw4r::lyt::Pane*                      mpNGameCannon;
    /* 0x27C */ nw4r::lyt::Pane*                      mpNResult2;
    /* 0x280 */ nw4r::lyt::Pane*                      REMOVED(mpNPlayer)[4];

    /* 0x290 */ LytTextBox_c*                         REMOVED(mpT1up)[4];
    /* 0x2A0 */ LytTextBox_c*                         mpTInfo;

    /* 0x2A4 */ nw4r::lyt::Picture*                   REMOVED(mpPPlayer)[4];
    /* 0x2B4 */ nw4r::lyt::Picture*                   mpPBg;
    /* 0x2B8 */ nw4r::lyt::Picture*                   mpPTitleBase;

    /* 0x2BC */ nw4r::lyt::Window*                    mpWGameCannon;

    // Offsets assume PLAYER_COUNT is 4. We can completely rework this structure as we replace
    // everything that uses it.

    /* 0x2C0 */ int  mCurrentState;
    /* 0x2C4 */ int  REMOVED(mWonRestNum)[4];
    /* 0x2D4 */ int  mNumPlayers;

    /* 0x2D8 */ bool mReady;
    /* 0x2D9 */ bool mActive;
    /* 0x2DA */ bool mIsWindowOpen;
    /* 0x2DB */ bool REMOVED(mPlayerEntry)[4];
    /* 0x2DF */ bool m_2DF;
    /* 0x2E0 */ bool mIsTitleOpen;
    /* 0x2E1 */ bool mAnimationActive;
    /* 0x2E2 */ bool mCloseTitle;
    /* 0x2E3 */ bool mCloseOperate;
    /* 0x2E4 */ bool mCloseResult;

    FILL(0x2E5, 0x2E8);

    // New (added 0xE8 bytes)
    /* 0x2E8 */ nw4r::lyt::Pane*    mpN8pPos[4];   // 0
    /* 0x2F8 */ nw4r::lyt::Pane*    mpN7pPos[3];   // 4
    /* 0x304 */ nw4r::lyt::Pane*    mpN6pPos[2];   // 7
    /* 0x30C */ nw4r::lyt::Pane*    mpN5pPos;      // 9
    /* 0x310 */ nw4r::lyt::Pane*    mpN4pPosEx[4]; // 10
    /* 0x320 */ nw4r::lyt::Pane*    mpN4pPos[4];   // 14
    /* 0x330 */ nw4r::lyt::Pane*    mpN3pPos[3];   // 18
    /* 0x33C */ nw4r::lyt::Pane*    mpN2pPos[2];   // 21
    /* 0x344 */ nw4r::lyt::Pane*    mpN1pPos;      // 23

    /* 0x348 */ nw4r::lyt::Pane*    mpNPlayer[8]; // 24
    /* 0x368 */ LytTextBox_c*       mpT1up[8];
    /* 0x388 */ nw4r::lyt::Picture* mpPPlayer[8];
    /* 0x3A8 */ int                 mNumWon[8];
    /* 0x3C8 */ bool                mPlayerEntry[8];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8078C530
     * executeState:    0x8078C550
     * finalizeState:   0x8078C590
     */
    sState_Extern(0x80992DC0, dMiniGameCannon_c, TitleOpenWait);

    /*
     * initializeState: 0x8078C5A0
     * executeState:    0x8078C6B0
     * finalizeState:   0x8078C710
     */
    sState_Extern(0x80992E00, dMiniGameCannon_c, TitleOpenAnimeEndWait);

    /*
     * initializeState: 0x8078C720
     * executeState:    0x8078C730
     * finalizeState:   0x8078C760
     */
    sState_Extern(0x80992E40, dMiniGameCannon_c, TitleDisp);

    /*
     * initializeState: 0x8078C770
     * executeState:    0x8078C7B0
     * finalizeState:   0x8078C810
     */
    sState_Extern(0x80992E80, dMiniGameCannon_c, TitleExitAnimeEndWait);

    /*
     * initializeState: 0x8078C8A0
     * executeState:    0x8078C8B0
     * finalizeState:   0x8078C8E0
     */
    sState_Extern(0x80992EC0, dMiniGameCannon_c, StartWait);

    /*
     * initializeState: 0x8078C970
     * executeState:    0x8078CB80
     * finalizeState:   0x8078CC40
     */
    sState_Extern(0x80992F00, dMiniGameCannon_c, OpenAnimeEndWait);

    /*
     * initializeState: 0x8078CC50
     * executeState:    0x8078CC60
     * finalizeState:   0x8078CC90
     */
    sState_Extern(0x80992F40, dMiniGameCannon_c, NowDisp);

    /*
     * initializeState: 0x8078CCA0
     * executeState:    0x8078CD70
     * finalizeState:   0x8078CDD0
     */
    sState_Extern(0x80992F80, dMiniGameCannon_c, ResultDispAnimeEndWait);

    /*
     * initializeState: 0x8078CE10
     * executeState:    0x8078CE90
     * finalizeState:   0x8078CEC0
     */
    sState_Extern(0x80992FC0, dMiniGameCannon_c, ResultNowDisp);

    /*
     * initializeState: 0x8078CF00
     * executeState:    0x8078CF40
     * finalizeState:   0x8078CFB0
     */
    sState_Extern(0x80993000, dMiniGameCannon_c, ExitAnimeEndWait);
};
