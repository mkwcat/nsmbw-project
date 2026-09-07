#pragma once

#include "d_actor.h"

class daPlyIce_c : public dActor_c {
    SIZE_ASSERT(0xD70);
    VTABLE(0x060, fBase_c, 0x8032697C);
    // 0x80326960 g_profile_PLAYER_ICE
    // 0x8014A830 daPlyIce_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daPlyIce_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0xD70);
};
