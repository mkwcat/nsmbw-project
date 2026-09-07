#pragma once

#include "d_a_en_blockmain.h"
#include "s_State.h"

class daEnBlockCloud_c : public daEnBlockMain_c {
    SIZE_ASSERT(0x7B0);
    VTABLE(0x060, fBase_c, 0x80ADB8E4);
    // 0x80ADB898 g_profile_EN_BLOCK_CLOUD
    // 0x809C21B0 daEnBlockCloud_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlockCloud_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x698, 0x7B0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809C2960
     * executeState:    0x809C2980
     * finalizeState:   0x809C2970
     */
    sState_Extern(0x80B126F8, daEnBlockCloud_c, Wait);

    /*
     * initializeState: 0x809C29C0
     * executeState:    0x809C29E0
     * finalizeState:   0x809C29D0
     */
    sState_Extern(0x80B12738, daEnBlockCloud_c, HitWait);
};
