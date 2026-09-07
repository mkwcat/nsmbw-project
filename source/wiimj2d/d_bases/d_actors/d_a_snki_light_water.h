#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLightWater_c : public dActorState_c {
    SIZE_ASSERT(0x4C0);
    VTABLE(0x060, fBase_c, 0x8097BDD8);
    // 0x8097BDA0 g_profile_AC_LIGHT_WATER
    // 0x808A8330 daLightWater_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLightWater_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A88A0
     * executeState:    0x808A88C0
     * finalizeState:   0x808A88B0
     */
    sState_Extern(0x8099F0A8, daLightWater_c, Wait);
};
