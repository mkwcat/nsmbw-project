#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnRotBlock_c : public dEn_c {
    SIZE_ASSERT(0x650);
    VTABLE(0x060, fBase_c, 0x80B06628);
    // 0x80B065F8 g_profile_EN_LIFT_ROTATION_FULL
    // 0x80A98410 daEnRotBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A98440 */
    daEnRotBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x650);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A98860
     * executeState:    0x80A98880
     * finalizeState:   0x80A98870
     */
    sState_Extern(0x80B1AA90, daEnRotBlock_c, Search);

    /*
     * initializeState: 0x80A988E0
     * executeState:    0x80A98900
     * finalizeState:   0x80A988F0
     */
    sState_Extern(0x80B1AAD0, daEnRotBlock_c, Move);
};
