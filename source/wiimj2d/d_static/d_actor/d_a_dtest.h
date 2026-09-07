#pragma once

#include "d_actor.h"

class daDTest_c : public dActor_c {
    SIZE_ASSERT(0x4C8);
    VTABLE(0x060, fBase_c, 0x8098FDCC);
    // 0x8098FDA8 g_profile_DTEST
    // 0x80932F60 daDTest_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDTest_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x4C8);
};
