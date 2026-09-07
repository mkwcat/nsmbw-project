#pragma once

#include "d_actor.h"

class daMistIntermittent_c : public dActor_c {
    SIZE_ASSERT(0x3A8);
    VTABLE(0x060, fBase_c, 0x80970DC4);
    // 0x80970DB8 g_profile_MIST_INTERMITTENT
    // 0x8086C8F0 daMistIntermittent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMistIntermittent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A8);
};
