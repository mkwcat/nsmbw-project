#pragma once

#include "d_actor.h"

class daFarBG_c : public dActor_c {
    SIZE_ASSERT(0x720);
    VTABLE(0x060, fBase_c, 0x80323E88);
    // 0x80323DF8 g_profile_FAR_BG
    // 0x80115D60 daFarBG_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFarBG_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x720);
};
