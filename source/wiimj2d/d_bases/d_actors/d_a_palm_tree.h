#pragma once

#include "d_actor.h"

class daPalmTree_c : public dActor_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x80977084);
    // 0x80977008 g_profile_PALM_TREE
    // 0x8088C2A0 daPalmTree_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daPalmTree_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x560);
};
