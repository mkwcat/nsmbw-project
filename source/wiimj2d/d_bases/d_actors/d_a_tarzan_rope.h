#pragma once

#include "d_actor.h"

class daTarzanRope_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x8097CFD4);
    // 0x8097CFC8 g_profile_TARZAN_ROPE
    // 0x808ACCD0 daTarzanRope_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTarzanRope_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
