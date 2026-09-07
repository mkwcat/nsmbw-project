#pragma once

#include "d_actor_state.h"

class daCircleRight_c : public dActorState_c {
    SIZE_ASSERT(0x420);
    VTABLE(0x060, fBase_c, 0x80958774);
    // 0x80958768 g_profile_CIRCLE_RIGHT
    // 0x807E38A0 daCircleRight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCircleRight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x420);
};
