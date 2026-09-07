#pragma once

#include "d_actor.h"

class daBlockOneUp_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x809530FC);
    // 0x809530F0 g_profile_AC_BLOCK_ONEUP
    // 0x807C0E60 daBlockOneUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBlockOneUp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
