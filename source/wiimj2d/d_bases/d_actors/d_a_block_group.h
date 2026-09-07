#pragma once

#include "d_actor.h"

class daBlockGroup_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80952E1C);
    // 0x80952E10 g_profile_AC_BLOCK_GROUP
    // 0x807C00A0 daBlockGroup_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBlockGroup_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
