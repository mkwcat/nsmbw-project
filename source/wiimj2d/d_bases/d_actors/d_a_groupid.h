#pragma once

#include "d_actor.h"

class daGroupID_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x8095CCE4);
    // 0x8095CCD8 g_profile_AC_GROUPID
    // 0x807FC750 daGroupID_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daGroupID_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
