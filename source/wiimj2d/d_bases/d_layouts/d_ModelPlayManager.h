#pragma once

#include "d_base.h"
#include "s_State.h"

class dModelPlayManager_c : public dBase_c {
    SIZE_ASSERT(0xAC0);
    VTABLE(0x060, fBase_c, 0x80948C68);
    // 0x80948BF8 g_profile_MODEL_PLAY_MANAGER
    // 0x80795290 dModelPlayManager_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807952C0 */
    dModelPlayManager_c();

public:
    // Nested Types
    // ^^^^^^

    struct OtehonInfo_s {
        SIZE_ASSERT(0x24);

        /* 0x00 */ int WorldNo;
        /* 0x04 */ int StageNo;
        /* 0x08 */ int OtehonType;
        /* 0x0C */ int NextGotoNo;
        /* 0x10 */ int OtehonTime;
        /* 0x14 */ int CourseNo;
        /* 0x18 */ int BuyCoinCount;
        /* 0x1C */ int Condition;
        /* 0x20 */ int ConditionCoinCount;
    };

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0xA7C);

    /* 0xA7C */ bool mReady;

    FILL(0xA7D, 0xAC0);

public:
    // Static Variables
    // ^^^^^^

    /* 0x80934670 */
    static const OtehonInfo_s m_otehonInfo[];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80796020
     * executeState:    0x80796040
     * finalizeState:   0x80796080
     */
    sState_Extern(0x809939A0, dModelPlayManager_c, FadeInEndWait);

    /*
     * initializeState: 0x80796450
     * executeState:    0x80796520
     * finalizeState:   0x80796590
     */
    sState_Extern(0x809939E0, dModelPlayManager_c, OnStageEndWait);

    /*
     * initializeState: 0x807965A0
     * executeState:    0x807965F0
     * finalizeState:   0x80796820
     */
    sState_Extern(0x80993A20, dModelPlayManager_c, KeyWait);

    /*
     * initializeState: 0x80796870
     * executeState:    0x807968C0
     * finalizeState:   0x80796A60
     */
    sState_Extern(0x80993A60, dModelPlayManager_c, SuccessionKeyWait);

    /*
     * initializeState: 0x80796A70
     * executeState:    0x80796A90
     * finalizeState:   0x80796AD0
     */
    sState_Extern(0x80993AA0, dModelPlayManager_c, HitAnimeEndWait);

    /*
     * initializeState: 0x80796AE0
     * executeState:    0x80796B60
     * finalizeState:   0x80796B90
     */
    sState_Extern(0x80993AE0, dModelPlayManager_c, ConfirmationWindowOnStageWait);

    /*
     * initializeState: 0x80796BA0
     * executeState:    0x80796BB0
     * finalizeState:   0x80796D00
     */
    sState_Extern(0x80993B20, dModelPlayManager_c, ConfirmationSelect);

    /*
     * initializeState: 0x80796D10
     * executeState:    0x80796D20
     * finalizeState:   0x80796DE0
     */
    sState_Extern(0x80993B60, dModelPlayManager_c, ConfirmationSelectDecisionWait);

    /*
     * initializeState: 0x80796DF0
     * executeState:    0x80796E70
     * finalizeState:   0x80796EF0
     */
    sState_Extern(0x80993BA0, dModelPlayManager_c, CoinCountDown);

    /*
     * initializeState: 0x80796F00
     * executeState:    0x80796F10
     * finalizeState:   0x80796F50
     */
    sState_Extern(0x80993BE0, dModelPlayManager_c, CoinPayOutAnimeStartWait);

    /*
     * initializeState: 0x80796F60
     * executeState:    0x80796FC0
     * finalizeState:   0x80797000
     */
    sState_Extern(0x80993C20, dModelPlayManager_c, CoinPayOutAnimeEndWait);

    /*
     * initializeState: 0x80797040
     * executeState:    0x80797050
     * finalizeState:   0x80797090
     */
    sState_Extern(0x80993C60, dModelPlayManager_c, WipeWait);

    /*
     * initializeState: 0x807970A0
     * executeState:    0x807970B0
     * finalizeState:   0x807971B0
     */
    sState_Extern(0x80993CA0, dModelPlayManager_c, ModelPlayStartSetup);

    /*
     * initializeState: 0x807971C0
     * executeState:    0x807971D0
     * finalizeState:   0x807971E0
     */
    sState_Extern(0x80993CE0, dModelPlayManager_c, ModelPlayStartWait);

    /*
     * initializeState: 0x807971F0
     * executeState:    0x80797220
     * finalizeState:   0x80797260
     */
    sState_Extern(0x80993D20, dModelPlayManager_c, MoveBeforeActiveOff);

    /*
     * initializeState: 0x80797270
     * executeState:    0x80797400
     * finalizeState:   0x80797440
     */
    sState_Extern(0x80993D60, dModelPlayManager_c, LeftRightMoveEndWait);

    /*
     * initializeState: 0x807975B0
     * executeState:    0x807975C0
     * finalizeState:   0x80797600
     */
    sState_Extern(0x80993DA0, dModelPlayManager_c, LeftRightMoveEndAfter);

    /*
     * initializeState: 0x80797610
     * executeState:    0x80797650
     * finalizeState:   0x807976B0
     */
    sState_Extern(0x80993DE0, dModelPlayManager_c, ButtonAnimeEndWait);

    /*
     * initializeState: 0x807976C0
     * executeState:    0x80797730
     * finalizeState:   0x80797760
     */
    sState_Extern(0x80993E20, dModelPlayManager_c, ExitEndWait);
};
