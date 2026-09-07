#pragma once

#include "d_base.h"
#include "s_State.h"

class dPointResultDateFileFree_c : public dBase_c {
    SIZE_ASSERT(0x344);
    VTABLE(0x060, fBase_c, 0x8094D5E0);
    // 0x8094D1E8 g_profile_POINT_RESULT_DATE_FILE_FREE
    // 0x807A7770 dPointResultDateFileFree_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807A77A0 */
    dPointResultDateFileFree_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x344);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807A7FD0
     * executeState:    0x807A7FE0
     * finalizeState:   0x807A8250
     */
    sState_Extern(0x80994DA0, dPointResultDateFileFree_c, Initial);

    /*
     * initializeState: 0x807A8260
     * executeState:    0x807A8310
     * finalizeState:   0x807A8340
     */
    sState_Extern(0x80994DE0, dPointResultDateFileFree_c, OnSatgeWait);

    /*
     * initializeState: 0x807A8350
     * executeState:    0x807A8360
     * finalizeState:   0x807A8380
     */
    sState_Extern(0x80994E20, dPointResultDateFileFree_c, OnSatgeAnimeEndCheck);

    /*
     * initializeState: 0x807A8390
     * executeState:    0x807A83A0
     * finalizeState:   0x807A83B0
     */
    sState_Extern(0x80994E60, dPointResultDateFileFree_c, GoalDeMoEndWait);
};
