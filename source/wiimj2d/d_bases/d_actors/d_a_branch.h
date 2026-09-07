#pragma once

#include "d_actor.h"

class daBranch_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80955984);
    // 0x80955978 g_profile_BRANCH
    // 0x807D4E60 daBranch_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBranch_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
