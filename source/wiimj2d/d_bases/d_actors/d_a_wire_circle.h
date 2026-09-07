#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWireCircle_c : public dActorState_c {
    SIZE_ASSERT(0x518);
    VTABLE(0x060, fBase_c, 0x80980B70);
    // 0x80980B38 g_profile_AC_WIRE_CIRCLE
    // 0x808C24B0 daWireCircle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWireCircle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x518);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808C2810
     * executeState:    0x808C2830
     * finalizeState:   0x808C2820
     */
    sState_Extern(0x809A0010, daWireCircle_c, Move);
};
