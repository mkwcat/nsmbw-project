#pragma once

#include "d_a_bullet.h"
#include "s_State.h"

class daHammer_c : public daBullet_c {
    SIZE_ASSERT(0x458);
    VTABLE(0x060, fBase_c, 0x8095CDE8);
    // 0x8095CDB8 g_profile_HAMMER
    // 0x807FCBA0 daHammer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daHammer_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x400, 0x458);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807FD0B0
     * executeState:    0x807FD0E0
     * finalizeState:   0x807FD0D0
     */
    sState_Extern(0x80998DB0, daHammer_c, Wait);

    /*
     * initializeState: 0x807FD200
     * executeState:    0x807FD2C0
     * finalizeState:   0x807FD2B0
     */
    sState_Extern(0x80998DF0, daHammer_c, Move);
};
