#pragma once

#include "d_actor_state.h"

class daLiftZenSuisya_c : public dActorState_c {
    SIZE_ASSERT(0x890);
    VTABLE(0x060, fBase_c, 0x8096B148);
    // 0x8096B110 g_profile_LIFT_ZEN_SUISYA
    // 0x80854EF0 daLiftZenSuisya_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftZenSuisya_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x890);
};
