#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftDokan_c : public dActorState_c {
    SIZE_ASSERT(0x568);
    VTABLE(0x060, fBase_c, 0x80966A48);
    // 0x809669E8 g_profile_LIFT_DOKAN
    // 0x80835A00 daLiftDokan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftDokan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x568);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80836100
     * executeState:    0x80836120
     * finalizeState:   0x80836110
     */
    sState_Extern(0x8099B048, daLiftDokan_c, Still);

    /*
     * initializeState: 0x80836130
     * executeState:    0x80836150
     * finalizeState:   0x80836140
     */
    sState_Extern(0x8099B088, daLiftDokan_c, MoveNormal);
};
