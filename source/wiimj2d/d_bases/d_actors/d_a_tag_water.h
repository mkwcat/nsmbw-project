#pragma once

#include "d_actor.h"

class daTagWater_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x8097CE14);
    // 0x8097CE08 g_profile_TAG_WATER
    // 0x808AC870 daTagWater_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTagWater_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
