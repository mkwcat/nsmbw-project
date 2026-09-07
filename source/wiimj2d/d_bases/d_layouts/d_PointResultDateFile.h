#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "s_FStateFct.h"
#include "s_State.h"
#include "s_StateMethodUsr_FI.h"
#include "s_StateMgr.h"

class dPointResultDateFile_c : public dBase_c {
    SIZE_ASSERT(0x8E0);
    VTABLE(0x060, fBase_c, 0x8094CAF0);
    // 0x8094C050 g_profile_POINT_RESULT_DATE_FILE
    // 0x807A3F50 dPointResultDateFile_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807A3F80 */
    dPointResultDateFile_c();

public:
    // Constants and Types
    // ^^^^^^

    struct Player_s {
        /* 0x00 */ u8   mCollectionCoin;

        /* 0x04 */ u32  mScore;
        /* 0x08 */ u32  mScoreBackup;
        /* 0x0C */ u32  mCoin;
        /* 0x10 */ u32  mCoinBackup;
        /* 0x14 */ u32  mScoreCopy; // Unused
        /* 0x18 */ u32  mRestNum;
        /* 0x1C */ u32  mRestNumBackup;

        /* 0x20 */ u32  mRankNum;
        /* 0x24 */ u32  mPlayerType;

        /* 0x28 */ bool mPlayOutRankAnim; // Always set to 0, so the animation never plays
        /* 0x29 */ bool mIsPlayerEntry;
        /* 0x2A */ bool mCoinCountDone;

        /* 0x2C */ f32  mCardTransY;
        /* 0x30 */ u32  m_30;
        /* 0x34 */ f32  m_34;
        /* 0x38 */ f32  m_38;
    };

    enum class PANE_LIST_e {
        FIRST = 0,

        NONE  = 44,
    };

public:
    // Instance Methods
    // ^^^^^^

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x6A8);

    /* 0x6A8 */ sStateMgr_c<
        dPointResultDateFile_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>
        mStateMgr;

    FILL(0x6E4, 0x7BC);

    /* 0x7BC */ Player_s mPlayerData[4];

    FILL(0x8AC, 0x8AF);

    /* 0x8AF */ bool mIsRankChange;

    FILL(0x8B0, 0x8E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807A5330
     * executeState:    0x807A53A0
     * finalizeState:   0x807A5540
     */
    sState_Extern(0x809949A0, dPointResultDateFile_c, Initial);

    /*
     * initializeState: 0x807A5550
     * executeState:    0x807A5640
     * finalizeState:   0x807A5670
     */
    sState_Extern(0x809949E0, dPointResultDateFile_c, OnSatgeWait);

    /*
     * initializeState: 0x807A5680
     * executeState:    0x807A56D0
     * finalizeState:   0x807A5730
     */
    sState_Extern(0x80994A20, dPointResultDateFile_c, OnSatgeAnimeEndCheck);

    /*
     * initializeState: 0x807A5740
     * executeState:    0x807A5750
     * finalizeState:   0x807A5780
     */
    sState_Extern(0x80994A60, dPointResultDateFile_c, ScoreCalcStartWait);

    /*
     * initializeState: 0x807A5790
     * executeState:    0x807A57A0
     * finalizeState:   0x807A5A30
     */
    sState_Extern(0x80994AA0, dPointResultDateFile_c, CoinAdd);

    /*
     * initializeState: 0x807A5A60
     * executeState:    0x807A5A70
     * finalizeState:   0x807A5AA0
     */
    sState_Extern(0x80994AE0, dPointResultDateFile_c, StarCoinToScoreStartWait);

    /*
     * initializeState: 0x807A5AB0
     * executeState:    0x807A5AC0
     * finalizeState:   0x807A5BF0
     */
    sState_Extern(0x80994B20, dPointResultDateFile_c, StarCoinAdd);

    /*
     * initializeState: 0x807A5C00
     * executeState:    0x807A5C20
     * finalizeState:   0x807A5CE0
     */
    sState_Extern(0x80994B60, dPointResultDateFile_c, StarCoinAnimeEndWait);

    /*
     * initializeState: 0x807A5CF0
     * executeState:    0x807A5D00
     * finalizeState:   0x807A5D90
     */
    sState_Extern(0x80994BA0, dPointResultDateFile_c, RankChangeStartWait);

    /*
     * initializeState: 0x807A5DA0
     * executeState:    0x807A5E20
     * finalizeState:   0x807A5E90
     */
    sState_Extern(0x80994BE0, dPointResultDateFile_c, RankExitAnimeEndWait);

    /*
     * initializeState: 0x807A5EA0
     * executeState:    0x807A5FE0
     * finalizeState:   0x807A6140
     */
    sState_Extern(0x80994C20, dPointResultDateFile_c, RankChange);

    /*
     * initializeState: 0x807A6150
     * executeState:    0x807A61F0
     * finalizeState:   0x807A62F0
     */
    sState_Extern(0x80994C60, dPointResultDateFile_c, BigSmallAnimeEndWait);

    /*
     * initializeState: 0x807A6300
     * executeState:    0x807A6410
     * finalizeState:   0x807A6510
     */
    sState_Extern(0x80994CA0, dPointResultDateFile_c, RankOnStageAnimeEndWait);

    /*
     * initializeState: 0x807A6520
     * executeState:    0x807A6530
     * finalizeState:   0x807A6570
     */
    sState_Extern(0x80994CE0, dPointResultDateFile_c, StarDispWait);

    /*
     * initializeState: 0x807A6580
     * executeState:    0x807A6680
     * finalizeState:   0x807A6860
     */
    sState_Extern(0x80994D20, dPointResultDateFile_c, StarOnStage);

    /*
     * initializeState: 0x807A6870
     * executeState:    0x807A6880
     * finalizeState:   0x807A6890
     */
    sState_Extern(0x80994D60, dPointResultDateFile_c, GoalDeMoEndWait);
};
