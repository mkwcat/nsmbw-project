#pragma once

#include "d_actor.h"

class daLiftHurikoCenter_c : public dActor_c {
    SIZE_ASSERT(0x3F8);
    VTABLE(0x060, fBase_c, 0x80967474);
    // 0x80967430 g_profile_LIFT_HURIKO_CENTER
    // 0x808392F0 daLiftHurikoCenter_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftHurikoCenter_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3F8);
};
