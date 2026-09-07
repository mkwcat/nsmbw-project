#pragma once

#include "d_actor.h"

class daAwa_c : public dActor_c {
    SIZE_ASSERT(0x440);
    VTABLE(0x060, fBase_c, 0x80951440);
    // 0x80951410 g_profile_AWA
    // 0x807B8840 daAwa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daAwa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x440);
};
