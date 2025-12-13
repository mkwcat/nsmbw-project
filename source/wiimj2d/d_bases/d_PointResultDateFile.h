#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "state/s_FStateFct.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"
#include "state/s_State.h"

class dPointResultDateFile_c : public dBase_c
{
    SIZE_ASSERT(0x8E0);

public:
    // Structors
    // ^^^^^^

    /* 0x */
    dPointResultDateFile_c();

public:
    // Constants and Types
    // ^^^^^^

    struct Player_s {
        /* 0x00 */ u8 mCollectionCoin;
        
        FILL(0x01, 0x04);

        /* 0x04 */ u32 mScore;
        /* 0x08 */ u32 mScoreBackup;
        /* 0x0C */ u32 mCoin;
        /* 0x10 */ u32 mCoinBackup;
        /* 0x14 */ u32 mScoreCopy; ///< Unused
        /* 0x18 */ u32 mRestNum;
        /* 0x1C */ u32 mRestNumBackup;

        /* 0x20 */ u32 mRankNum;
        /* 0x24 */ u32 mPlayerType;

        /* 0x28 */ bool mPlayOutRankAnim; ///< Always set to 0, so the animation never plays
        /* 0x29 */ bool mIsPlayerEntry;
        /* 0x2A */ bool mCoinCountDone;

        FILL(0x2B, 0x2C);

        /* 0x2C */ f32 mCardTransY;
        /* 0x30 */ u32 m_30;
        /* 0x34 */ f32 m_34;
        /* 0x38 */ f32 m_38;
    };

    enum class PANE_LIST_e {
        FIRST = 0,

        NONE = 44,
    };

public:
    // Instance Methods
    // ^^^^^^

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x6A8);

    /* 0x6A8 */ sStateMgr_c<dPointResultDateFile_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    FILL(0x6E4, 0x7BC);

    /* 0x7BC */ Player_s mPlayerData[4];

    FILL(0x8AC, 0x8AF);

    /* 0x8AF */ bool mIsRankChange;

    FILL(0x8B0, 0x8E0);

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80994D20, dPointResultDateFile_c, StarOnStage);

    sState_Extern(0x80994D60, dPointResultDateFile_c, GoalDeMoEndWait);
};