#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftWaterWheel_c : public dActorState_c {
    SIZE_ASSERT(0x8D0);
    VTABLE(0x060, fBase_c, 0x8096A298);
    // 0x8096A228 g_profile_AC_LIFT_WATERWHEEL
    // 0x8084F6A0 daLiftWaterWheel_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftWaterWheel_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x8D0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808505D0
     * executeState:    0x80850600
     * finalizeState:   0x808505F0
     */
    sState_Extern(0x8099BFB0, daLiftWaterWheel_c, NoDisp);

    /*
     * initializeState: 0x80850650
     * executeState:    0x80850710
     * finalizeState:   0x80850700
     */
    sState_Extern(0x8099BFF0, daLiftWaterWheel_c, Move);
};
