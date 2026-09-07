#pragma once

#include "d_actor.h"

class daSlowQuickTag_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x8097BCCC);
    // 0x8097BCC0 g_profile_SLOW_QUICK_TAG
    // 0x808A8210 daSlowQuickTag_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daSlowQuickTag_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
