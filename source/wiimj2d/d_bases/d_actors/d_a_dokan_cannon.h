#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daDokanCannon_c : public dActorState_c {
    SIZE_ASSERT(0x658);
    VTABLE(0x060, fBase_c, 0x809588F0);
    // 0x80958868 g_profile_AC_DOKAN_CANNON
    // 0x807E3B50 daDokanCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDokanCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x658);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E49F0
     * executeState:    0x807E4A10
     * finalizeState:   0x807E4A00
     */
    sState_Extern(0x80997E98, daDokanCannon_c, Move);
};
