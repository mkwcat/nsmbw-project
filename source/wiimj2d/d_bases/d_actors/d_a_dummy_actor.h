#pragma once

#include "d_actor.h"

class daDummyActor_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80958A84);
    // 0x80958A78 g_profile_DUMMY_ACTOR
    // 0x807E4DB0 daDummyActor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDummyActor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
