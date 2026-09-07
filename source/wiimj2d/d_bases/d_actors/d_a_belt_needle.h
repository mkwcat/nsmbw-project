#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBeltNeedle_c : public dActorState_c {
    SIZE_ASSERT(0x418);
    VTABLE(0x060, fBase_c, 0x80951D50);
    // 0x80951D18 g_profile_BELT_NEEDLE
    // 0x807BAC60 daBeltNeedle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBeltNeedle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x418);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807BB830
     * executeState:    0x807BB850
     * finalizeState:   0x807BB840
     */
    sState_Extern(0x80996090, daBeltNeedle_c, MoveAttach);
};
