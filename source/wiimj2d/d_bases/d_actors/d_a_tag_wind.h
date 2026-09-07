#pragma once

#include "d_actor.h"

class daTagWind_c : public dActor_c {
    SIZE_ASSERT(0x3B8);
    VTABLE(0x060, fBase_c, 0x8097CEF4);
    // 0x8097CEE8 g_profile_TAG_WIND
    // 0x808AC9A0 daTagWind_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTagWind_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3B8);
};
