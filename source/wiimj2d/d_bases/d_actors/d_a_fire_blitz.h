#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFireBlitz_c : public dActorState_c {
    SIZE_ASSERT(0x540);
    VTABLE(0x060, fBase_c, 0x809597D8);
    // 0x809597A0 g_profile_FIRE_BLITZ
    // 0x807E84D0 daFireBlitz_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFireBlitz_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x540);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E8A50
     * executeState:    0x807E8A90
     * finalizeState:   0x807E8A80
     */
    sState_Extern(0x80998258, daFireBlitz_c, Move);

    /*
     * initializeState: 0x807E8AA0
     * executeState:    0x807E8AF0
     * finalizeState:   0x807E8AE0
     */
    sState_Extern(0x80998298, daFireBlitz_c, Vanish);

    /*
     * initializeState: 0x807E8B10
     * executeState:    0x807E8B30
     * finalizeState:   0x807E8B20
     */
    sState_Extern(0x809982D8, daFireBlitz_c, EatIn);

    /*
     * initializeState: 0x807E8B60
     * executeState:    0x807E8B80
     * finalizeState:   0x807E8B70
     */
    sState_Extern(0x80998318, daFireBlitz_c, EatNow);
};
