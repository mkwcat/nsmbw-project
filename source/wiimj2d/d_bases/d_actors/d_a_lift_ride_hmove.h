#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftRideHMove_c : public dActorState_c {
    SIZE_ASSERT(0x5C8);
    VTABLE(0x060, fBase_c, 0x80968514);
    // 0x809684F8 g_profile_AC_LIFT_RIDE_HMOVE
    // 0x80841B30 daLiftRideHMove_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftRideHMove_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80842170
     * executeState:    0x808421D0
     * finalizeState:   0x808421B0
     */
    sState_Extern(0x8099B590, daLiftRideHMove_c, NoDisp);

    /*
     * initializeState: 0x80842270
     * executeState:    0x80842290
     * finalizeState:   0x80842280
     */
    sState_Extern(0x8099B5D0, daLiftRideHMove_c, Move);

    /*
     * initializeState: 0x80842370
     * executeState:    0x808423B0
     * finalizeState:   0x808423A0
     */
    sState_Extern(0x8099B610, daLiftRideHMove_c, Fall);
};
