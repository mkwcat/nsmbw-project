#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftRideOff_c : public dActorState_c {
    SIZE_ASSERT(0xF10);
    VTABLE(0x060, fBase_c, 0x80968768);
    // 0x80968700 g_profile_LIFT_RIDE_OFF
    // 0x80842910 daLiftRideOff_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftRideOff_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xF10);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808444E0
     * executeState:    0x80844510
     * finalizeState:   0x80844500
     */
    sState_Extern(0x8099B690, daLiftRideOff_c, Wait);

    /*
     * initializeState: 0x80844570
     * executeState:    0x808445A0
     * finalizeState:   0x80844590
     */
    sState_Extern(0x8099B6D0, daLiftRideOff_c, Move);

    /*
     * initializeState: 0x80844620
     * executeState:    0x80844650
     * finalizeState:   0x80844640
     */
    sState_Extern(0x8099B710, daLiftRideOff_c, Stop);
};
