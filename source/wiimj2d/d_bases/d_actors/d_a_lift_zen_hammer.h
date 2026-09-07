#pragma once

#include "d_actor_state.h"

class daLiftZenHammer_c : public dActorState_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x8096A608);
    // 0x8096A5D0 g_profile_LIFT_ZEN_HAMMER
    // 0x80851B30 daLiftZenHammer_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftZenHammer_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5E0);
};
