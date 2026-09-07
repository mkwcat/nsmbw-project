#pragma once

#include "d_actor.h"

class daUnteiRope_c : public dActor_c {
    SIZE_ASSERT(0x640);
    VTABLE(0x060, fBase_c, 0x8097E17C);
    // 0x8097E138 g_profile_UNTEI_ROPE
    // 0x808B3100 daUnteiRope_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daUnteiRope_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x640);
};
