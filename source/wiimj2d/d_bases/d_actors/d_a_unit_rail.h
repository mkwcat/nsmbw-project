#pragma once

#include "d_base_actor.h"

class daUnitRail_c : public dBaseActor_c {
    SIZE_ASSERT(0x154);
    VTABLE(0x060, fBase_c, 0x8097E0D8);
    // 0x8097DE38 g_profile_UNIT_RAIL
    // 0x808B2670 daUnitRail_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daUnitRail_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x125, 0x154);
};
