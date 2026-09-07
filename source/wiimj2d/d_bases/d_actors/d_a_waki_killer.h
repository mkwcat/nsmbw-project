#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiKiller_c : public dActorState_c {
    SIZE_ASSERT(0x3F0);
    VTABLE(0x060, fBase_c, 0x8097E850);
    // 0x8097E840 g_profile_AC_WAKI_KILLER
    // 0x808B5F20 daWakiKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiKiller_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808B63B0
     * executeState:    0x808B63D0
     * finalizeState:   0x808B63C0
     */
    sState_Extern(0x8099F690, daWakiKiller_c, Move);
};
