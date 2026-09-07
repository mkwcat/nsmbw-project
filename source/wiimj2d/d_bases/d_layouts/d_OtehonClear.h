#pragma once

#include "d_base.h"
#include "s_State.h"

class dOtehonClear_c : public dBase_c {
    SIZE_ASSERT(0xBC);
    VTABLE(0x60, fBase_c, 0x8094BC08);
    // 0x8094BBFC g_profile_OTEHON_CLEAR
    // 0x807A2CF0 dOtehonClear_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807A2D20 */
    dOtehonClear_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x70, 0xBC);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807A30C0
     * executeState:    0x807A30D0
     * finalizeState:   0x807A3110
     */
    sState_Extern(0x809947A0, dOtehonClear_c, OtehonCheck);

    /*
     * initializeState: 0x807A3120
     * executeState:    0x807A3140
     * finalizeState:   0x807A3170
     */
    sState_Extern(0x809947E0, dOtehonClear_c, YesNoWindowOnStageWait);

    /*
     * initializeState: 0x807A3180
     * executeState:    0x807A3190
     * finalizeState:   0x807A3280
     */
    sState_Extern(0x80994820, dOtehonClear_c, YesNoWindowSelectWait);

    /*
     * initializeState: 0x807A3290
     * executeState:    0x807A32A0
     * finalizeState:   0x807A3300
     */
    sState_Extern(0x80994860, dOtehonClear_c, YesNoWindowHitAnimeEndWait);

    /*
     * initializeState: 0x807A3310
     * executeState:    0x807A3330
     * finalizeState:   0x807A3360
     */
    sState_Extern(0x809948A0, dOtehonClear_c, ClearConfirmationWindowOnStageWait);

    /*
     * initializeState: 0x807A3370
     * executeState:    0x807A3380
     * finalizeState:   0x807A34A0
     */
    sState_Extern(0x809948E0, dOtehonClear_c, ClearConfirmationSelectWait);

    /*
     * initializeState: 0x807A34B0
     * executeState:    0x807A34C0
     * finalizeState:   0x807A3510
     */
    sState_Extern(0x80994920, dOtehonClear_c, ClearConfirmationHitAnimeEndWait);

    /*
     * initializeState: 0x807A3520
     * executeState:    0x807A35C0
     * finalizeState:   0x807A35D0
     */
    sState_Extern(0x80994960, dOtehonClear_c, SceneChangeWait);
};
