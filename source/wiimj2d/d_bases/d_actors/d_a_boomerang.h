#pragma once

#include "d_a_bullet.h"
#include "s_State.h"

class daBoomerang_c : public daBullet_c {
    SIZE_ASSERT(0x478);
    VTABLE(0x060, fBase_c, 0x80953D18);
    // 0x80953CE0 g_profile_BOOMERANG
    // 0x807C6AE0 daBoomerang_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBoomerang_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x400, 0x478);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807C7020
     * executeState:    0x807C7050
     * finalizeState:   0x807C7040
     */
    sState_Extern(0x80996A20, daBoomerang_c, Wait);

    /*
     * initializeState: 0x807C7170
     * executeState:    0x807C71E0
     * finalizeState:   0x807C71D0
     */
    sState_Extern(0x80996A60, daBoomerang_c, Go);

    /*
     * initializeState: 0x807C74F0
     * executeState:    0x807C7520
     * finalizeState:   0x807C7510
     */
    sState_Extern(0x80996AA0, daBoomerang_c, Return);

    /*
     * initializeState: 0x807C76F0
     * executeState:    0x807C7760
     * finalizeState:   0x807C7750
     */
    sState_Extern(0x80996AE0, daBoomerang_c, Fall);

    /*
     * initializeState: 0x807C7310
     * executeState:    0x807C73B0
     * finalizeState:   0x807C73A0
     */
    sState_Extern(0x80996B20, daBoomerang_c, Vanish);
};
