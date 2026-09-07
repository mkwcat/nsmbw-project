#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnTestman_c : public dEn_c {
    SIZE_ASSERT(0x5C0);
    VTABLE(0x060, fBase_c, 0x80B0B0E8);
    // 0x80B0B090 g_profile_EN_TESTMAN
    // 0x80AB1130 daEnTestman_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTestman_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AB1560
     * executeState:    0x80AB1610
     * finalizeState:   0x80AB1600
     */
    sState_Extern(0x80B1B928, daEnTestman_c, ReadySt);

    /*
     * initializeState: 0x80AB16B0
     * executeState:    0x80AB1750
     * finalizeState:   0x80AB1740
     */
    sState_Extern(0x80B1B968, daEnTestman_c, Ready);
};
