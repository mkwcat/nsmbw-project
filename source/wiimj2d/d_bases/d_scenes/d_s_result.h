#pragma once

#include "d_scene.h"
#include "s_State.h"

class dScResult_c : public dScene_c {
    SIZE_ASSERT(0x1D8);
    VTABLE(0x060, fBase_c, 0x8098BA90);
    // 0x8098B9F8 g_profile_RESULT
    // 0x8091BA50 dScResult_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8091BDA0 */
    dScResult_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x074, 0x1D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8091C2A0
     * executeState:    0x8091C2B0
     * finalizeState:   0x8091C2F0
     */
    sState_Extern(0x809A18A0, dScResult_c, ResultStartWait);

    /*
     * initializeState: 0x8091C300
     * executeState:    0x8091C310
     * finalizeState:   0x8091C320
     */
    sState_Extern(0x809A18E0, dScResult_c, ResultEndWait);
};
