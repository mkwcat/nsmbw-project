#pragma once

#include "d_actor_state.h"

class daBubble_c : public dActorState_c {
    SIZE_ASSERT(0x3D8);
    VTABLE(0x060, fBase_c, 0x80955C60);
    // 0x80955C50 g_profile_AC_WATER_BUBBLE
    // 0x807D5B00 daBubble_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBubble_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3D8);
};
