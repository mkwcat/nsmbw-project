#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daEnLw_c : public dActorState_c {
    SIZE_ASSERT(0x778);
    VTABLE(0x060, fBase_c, 0x8096A478);
    // 0x8096A440 g_profile_EN_LIFT_WHEEL
    // 0x80850FF0 daEnLw_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLw_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x778);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80851780
     * executeState:    0x808517A0
     * finalizeState:   0x80851790
     */
    sState_Extern(0x8099C040, daEnLw_c, Move);
};
