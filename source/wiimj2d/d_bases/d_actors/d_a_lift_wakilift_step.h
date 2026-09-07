#pragma once

#include "d_actor_state.h"

class daWakiLiftStep_c : public dActorState_c {
    SIZE_ASSERT(0x580);
    VTABLE(0x060, fBase_c, 0x8096A144);
    // 0x8096A138 g_profile_AC_WAKILIFT_STEP
    // 0x8084F1A0 daWakiLiftStep_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiLiftStep_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x580);
};
