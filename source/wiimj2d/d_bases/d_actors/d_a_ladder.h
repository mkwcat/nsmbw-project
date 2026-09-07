#pragma once

#include "d_actor.h"

class daLadder_c : public dActor_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80965000);
    // 0x80964F30 g_profile_LADDER
    // 0x8082E1F0 daLadder_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLadder_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x528);
};
