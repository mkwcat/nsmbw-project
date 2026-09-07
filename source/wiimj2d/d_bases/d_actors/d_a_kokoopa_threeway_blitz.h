#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKokoopaThreewayBlitz_c : public dActorState_c {
    SIZE_ASSERT(0x3D8);
    VTABLE(0x060, fBase_c, 0x80963AC0);
    // 0x80963AB0 g_profile_KOKOOPA_THREEWAY_BLITZ
    // 0x80827980 daKokoopaThreewayBlitz_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKokoopaThreewayBlitz_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80827CC0
     * executeState:    0x80827CE0
     * finalizeState:   0x80827CD0
     */
    sState_Extern(0x8099A640, daKokoopaThreewayBlitz_c, Move);
};
