#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daTorchiLight_c : public dActorState_c {
    SIZE_ASSERT(0x5F8);
    VTABLE(0x060, fBase_c, 0x8097D990);
    // 0x8097D950 g_profile_TORCHILIGHT
    // 0x808B0C20 daTorchiLight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTorchiLight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808B1200
     * executeState:    0x808B1220
     * finalizeState:   0x808B1210
     */
    sState_Extern(0x8099F448, daTorchiLight_c, Still);
};
