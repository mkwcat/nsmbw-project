#pragma once

#include "d_actor.h"

class daLiftIceSpring_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80967554);
    // 0x80967548 g_profile_AC_LIFT_ICE_SPRING
    // 0x808395C0 daLiftIceSpring_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftIceSpring_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
