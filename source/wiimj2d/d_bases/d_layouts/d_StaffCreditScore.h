#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "d_lyttextbox.h"
#include "s_FStateFct.h"
#include "s_State.h"
#include "s_StateInterfaces.h"
#include "s_StateMethodUsr_FI.h"
#include "s_StateMgr.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>

class dStaffCreditScore_c : public dBase_c {
    // Original size: 0x2B8
    VTABLE(0x060, fBase_c, 0x8094F328);
    // 0x8094F0D8 g_profile_STAFF_CREDIT_SCORE
    // 0x807ADAD0 dStaffCreditScore_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807ADB00 */
    dStaffCreditScore_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x807ADF10 */
    bool createLayout();

    /* 0x807AE140 */
    void setCoinCount(int player);

    /* 0x807AE1C0 */
    void updateCoinCounts();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ sStateMgr_c<dStaffCreditScore_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
                                 mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane* mpRootPane;
    /* 0x248 */ LytTextBox_c*    REMOVED(mpTCoin)[4];
    /* 0x258 */ LytTextBox_c*    mpTCoin04;
    /* 0x25C */ LytTextBox_c*    mpTHighScore;
    /* 0x260 */ nw4r::lyt::Pane* mpNPlayer[4]; // Unused
    /* 0x270 */ nw4r::lyt::Pane* mpNProportionL;
    /* 0x274 */ nw4r::lyt::Pane* mpNProportionR;

    /* 0x278 */ bool             mReady;
    /* 0x279 */ bool             mIsVisible;
    /* 0x27A */ bool             mPlayerActive[4]; // Partially unused
    /* 0x27E */ bool             mDoHighScoreCheck;
    /* 0x27F */ bool             mDoHighScoreAnime;
    /* 0x280 */ bool             mIsPlayerKiMe;
    /* 0x281 */ bool             REMOVED(mIsWinPlayer)[4];
    /* 0x285 */ bool             mDoDemoLandPlayer;
    /* 0x286 */ bool             mIsAllPlayerControl_maybe;

    /* 0x288 */ int              REMOVED(mCoinNum)[4];
    /* 0x298 */ int              REMOVED(mPrevCoinNum)[4];
    /* 0x2A8 */ int              mInitialHighScore;
    /* 0x2AC */ int              mHighScore;
    /* 0x2B0 */ int              mMaxCoinNum;
    /* 0x2B4 */ int              mWinPlayerID;

    OFFSET_ASSERT(0x2B8);

    // Instance Variables
    // ++++++

    // New (added 0x68 bytes)
    /* 0x2B8 */ LytTextBox_c* mpTCoin[8];
    /* 0x2D8 */ int           mCoinNum[8];
    /* 0x2F8 */ int           mPrevCoinNum[8];
    /* 0x318 */ bool          mIsWinPlayer[8];
    FILL(0x070, 0x2B8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807AE230
     * executeState:    0x807AE2B0
     * finalizeState:   0x807AE2F0
     */
    sState_Extern(0x809955C0, dStaffCreditScore_c, OnStageWait);

    /*
     * initializeState: 0x807AE300
     * executeState:    0x807AE390
     * finalizeState:   0x807AE3F0
     */
    sState_Extern(0x80995600, dStaffCreditScore_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x807AE400
     * executeState:    0x807AE460
     * finalizeState:   0x807AE510
     */
    sState_Extern(0x80995640, dStaffCreditScore_c, NowDisp);

    /*
     * initializeState: 0x807AE520
     * executeState:    0x807AE6C0
     * finalizeState:   0x807AE740
     */
    sState_Extern(0x80995680, dStaffCreditScore_c, HighScoreCheck);

    /*
     * initializeState: 0x807AE750
     * executeState:    0x807AE7C0
     * finalizeState:   0x807AE850
     */
    sState_Extern(0x809956C0, dStaffCreditScore_c, HighScoreAnimeEndWait);

    /*
     * initializeState: 0x807AE8B0
     * executeState:    0x807AE8C0
     * finalizeState:   0x807AE8F0
     */
    sState_Extern(0x80995700, dStaffCreditScore_c, No1PlayerKiMeStartWait);

    /*
     * initializeState: 0x807AE900
     * executeState:    0x807AE980
     * finalizeState:   0x807AEA40
     */
    sState_Extern(0x80995740, dStaffCreditScore_c, No1PlayerKiMe);

    /*
     * initializeState: 0x807AEA50
     * executeState:    0x807AEA60
     * finalizeState:   0x807AEA70
     */
    sState_Extern(0x80995780, dStaffCreditScore_c, EndWait);
};
