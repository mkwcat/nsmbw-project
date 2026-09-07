#pragma once

#include "d_a_bullet.h"
#include "s_State.h"

class daSpana_c : public daBullet_c {
    SIZE_ASSERT(0x468);
    VTABLE(0x060, fBase_c, 0x8097BF80);
    // 0x8097BF48 g_profile_SPANA
    // 0x808A8C40 daSpana_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daSpana_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x400, 0x468);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A91A0
     * executeState:    0x808A91D0
     * finalizeState:   0x808A91C0
     */
    sState_Extern(0x8099F0E8, daSpana_c, Wait);

    /*
     * initializeState: 0x808A9280
     * executeState:    0x808A9340
     * finalizeState:   0x808A9330
     */
    sState_Extern(0x8099F128, daSpana_c, Move);
};
