#pragma once

#include "d_actor.h"

class daChengeBlock_c : public dActor_c {
    SIZE_ASSERT(0x3C0);
    VTABLE(0x060, fBase_c, 0x809580A4);
    // 0x80958088 g_profile_AC_CHENGE_BLOCK
    // 0x807E1420 daChengeBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daChengeBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3C0);
};
