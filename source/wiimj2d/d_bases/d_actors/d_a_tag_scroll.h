#pragma once

#include "d_actor.h"

class daTagScroll_c : public dActor_c {
    SIZE_ASSERT(0x3A0);
    VTABLE(0x060, fBase_c, 0x8097CC54);
    // 0x8097CC48 g_profile_TAG_SCROLL
    // 0x808AC620 daTagScroll_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTagScroll_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A0);
};
