#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftTorideRoll_c : public dActorState_c {
    SIZE_ASSERT(0x438);
    VTABLE(0x060, fBase_c, 0x80969E88);
    // 0x80969E78 g_profile_LIFT_TORIDE_ROLL
    // 0x8084E8C0 daLiftTorideRoll_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftTorideRoll_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x438);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8084E9E0
     * executeState:    0x8084EA00
     * finalizeState:   0x8084E9F0
     */
    sState_Extern(0x8099BF28, daLiftTorideRoll_c, Search);

    /*
     * initializeState: 0x8084EA10
     * executeState:    0x8084EA30
     * finalizeState:   0x8084EA20
     */
    sState_Extern(0x8099BF68, daLiftTorideRoll_c, Move);
};
