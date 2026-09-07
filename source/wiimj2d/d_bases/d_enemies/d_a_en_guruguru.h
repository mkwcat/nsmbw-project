#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnGuru_c : public dEn_c {
    SIZE_ASSERT(0x5D8);
    VTABLE(0x060, fBase_c, 0x80AED510);
    // 0x80AED4E0 g_profile_EN_GURUGURU
    // 0x80A11170 daEnGuru_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGuru_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A115D0
     * executeState:    0x80A11660
     * finalizeState:   0x80A11650
     */
    sState_Extern(0x80B15848, daEnGuru_c, Roll);
};
