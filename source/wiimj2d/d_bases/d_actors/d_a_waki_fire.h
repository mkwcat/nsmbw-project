#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiFire_c : public dActorState_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x8097E448);
    // 0x8097E438 g_profile_WAKI_FIRE
    // 0x808B4EB0 daWakiFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808B5290
     * executeState:    0x808B52B0
     * finalizeState:   0x808B52A0
     */
    sState_Extern(0x8099F5E0, daWakiFire_c, Waki);
};
