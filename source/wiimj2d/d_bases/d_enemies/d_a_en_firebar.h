#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnFireBar_c : public dEn_c {
    SIZE_ASSERT(0x2490);
    VTABLE(0x0060, fBase_c, 0x80AE9148);
    // 0x80AE90D8 g_profile_EN_FIREBAR
    // 0x809F8BA0 daEnFireBar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnFireBar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x2490);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809F95A0
     * executeState:    0x809F95C0
     * finalizeState:   0x809F95B0
     */
    sState_Extern(0x80B145D0, daEnFireBar_c, Roll);
};
