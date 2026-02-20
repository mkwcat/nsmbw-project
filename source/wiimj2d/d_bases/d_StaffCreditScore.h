#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "d_system/d_lyttextbox.h"
#include <nw4r/lyt/Pane.h>
#include <nw4r/lyt/Picture.h>
#include "state/s_FStateFct.h"
#include "state/s_StateInterfaces.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"
#include "state/s_State.h"

class dStaffCreditScore_c : public dBase_c
{
    SIZE_ASSERT(0x2B8 + 0x68);

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
    /* 0x208 */ sStateMgr_c<dStaffCreditScore_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane* mpRootPane;
    /* 0x248 */ LytTextBox_c* REMOVED(mpTCoin)[4];
    /* 0x258 */ LytTextBox_c* mpTCoin04;
    /* 0x25C */ LytTextBox_c* mpTHighScore;
    /* 0x260 */ nw4r::lyt::Pane* mpNPlayer[4]; // Unused
    /* 0x270 */ nw4r::lyt::Pane* mpNProportionL;
    /* 0x274 */ nw4r::lyt::Pane* mpNProportionR;

    /* 0x278 */ bool mReady;
    /* 0x279 */ bool mIsVisible;
    /* 0x27A */ bool mPlayerActive[4]; // Partially unused
    /* 0x27E */ bool mDoHighScoreCheck;
    /* 0x27F */ bool mDoHighScoreAnime;
    /* 0x280 */ bool mIsPlayerKiMe;
    /* 0x281 */ bool REMOVED(mIsWinPlayer)[4];
    /* 0x285 */ bool mDoDemoLandPlayer;
    /* 0x286 */ bool mIsAllPlayerControl_maybe;

    /* 0x288 */ int REMOVED(mCoinNum)[4];
    /* 0x298 */ int REMOVED(mPrevCoinNum)[4];
    /* 0x2A8 */ int mInitialHighScore;
    /* 0x2AC */ int mHighScore;
    /* 0x2B0 */ int mMaxCoinNum;
    /* 0x2B4 */ int mWinPlayerID;

    // New (added 0x68 bytes)
    /* 0x2B8 */ LytTextBox_c* mpTCoin[8];
    /* 0x2D8 */ int mCoinNum[8];
    /* 0x2F8 */ int mPrevCoinNum[8];
    /* 0x318 */ bool mIsWinPlayer[8];

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x809955C0, dStaffCreditScore_c, OnStageWait);

    sState_Extern(0x80995600, dStaffCreditScore_c, OnStageAnimeEndWait);

    sState_Extern(0x80995680, dStaffCreditScore_c, HighScoreCheck);

    sState_Extern(0x809956C0, dStaffCreditScore_c, HighScoreAnimeEndWait);

    sState_Extern(0x80995740, dStaffCreditScore_c, No1PlayerKiMe);

    sState_Extern(0x80995780, dStaffCreditScore_c, EndWait);
};
