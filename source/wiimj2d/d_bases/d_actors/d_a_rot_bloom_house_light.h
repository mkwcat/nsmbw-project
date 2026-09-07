#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daHouseLight_c : public dActorState_c {
    SIZE_ASSERT(0x460);
    VTABLE(0x060, fBase_c, 0x8097A098);
    // 0x8097A070 g_profile_AC_HOUSE_LIGHT
    // 0x8089AB90 daHouseLight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daHouseLight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x460);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8089AF40
     * executeState:    0x8089AF60
     * finalizeState:   0x8089AF50
     */
    sState_Extern(0x8099E898, daHouseLight_c, Wait);
};
