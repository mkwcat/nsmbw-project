#pragma once

#include "d_actor.h"

class daWakiIceAshiba_c : public dActor_c {
    SIZE_ASSERT(0x3A0);
    VTABLE(0x060, fBase_c, 0x8097E5AC);
    // 0x8097E5A0 g_profile_WAKI_ICE_ASHIBA
    // 0x808B5620 daWakiIceAshiba_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiIceAshiba_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A0);
};
