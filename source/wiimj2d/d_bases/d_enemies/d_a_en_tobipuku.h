#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnTobiPuku_c : public dEn_c {
    SIZE_ASSERT(0x718);
    VTABLE(0x060, fBase_c, 0x80B0B488);
    // 0x80B0B440 g_profile_EN_TOBIPUKU
    // 0x80AB1B90 daEnTobiPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTobiPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x718);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AB2400
     * executeState:    0x80AB24A0
     * finalizeState:   0x80AB2490
     */
    sState_Extern(0x80B1B9A8, daEnTobiPuku_c, Jump);
};
