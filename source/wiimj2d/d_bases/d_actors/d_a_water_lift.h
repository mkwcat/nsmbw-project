#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWaterLift_c : public dActorState_c {
    SIZE_ASSERT(0x570);
    VTABLE(0x060, fBase_c, 0x8098020C);
    // 0x80980200 g_profile_WATER_LIFT
    // 0x808BEF40 daWaterLift_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWaterLift_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x570);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BF200
     * executeState:    0x808BF250
     * finalizeState:   0x808BF240
     */
    sState_Extern(0x8099FD50, daWaterLift_c, Waki);

    /*
     * initializeState: 0x808BF2D0
     * executeState:    0x808BF310
     * finalizeState:   0x808BF300
     */
    sState_Extern(0x8099FD90, daWaterLift_c, Move);
};
