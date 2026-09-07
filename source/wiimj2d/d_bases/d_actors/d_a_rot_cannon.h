#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRotCannon_c : public dActorState_c {
    SIZE_ASSERT(0x958);
    VTABLE(0x060, fBase_c, 0x8097A270);
    // 0x8097A1F0 g_profile_AC_ROT_CANNON
    // 0x8089B280 daRotCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x958);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8089C220
     * executeState:    0x8089C240
     * finalizeState:   0x8089C230
     */
    sState_Extern(0x8099E8D8, daRotCannon_c, RotationWait);

    /*
     * initializeState: 0x8089C2D0
     * executeState:    0x8089C300
     * finalizeState:   0x8089C2F0
     */
    sState_Extern(0x8099E918, daRotCannon_c, RotationMove);

    /*
     * initializeState: 0x8089C390
     * executeState:    0x8089C3B0
     * finalizeState:   0x8089C3A0
     */
    sState_Extern(0x8099E958, daRotCannon_c, ReturnRotationMove);
};
