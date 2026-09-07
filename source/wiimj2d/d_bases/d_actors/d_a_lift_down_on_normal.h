#pragma once

#include "d_actor_state.h"

class daLiftDownOnNormal_c : public dActorState_c {
    SIZE_ASSERT(0x628);
    VTABLE(0x060, fBase_c, 0x80966EB8);
    // 0x80966EA8 g_profile_LIFT_DOWN_ON_NORMAL
    // 0x80836B20 daLiftDownOnNormal_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftDownOnNormal_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x628);
};
