#pragma once

#include "d_base_actor.h"

class daUnitChikuwa_c : public dBaseActor_c {
    SIZE_ASSERT(0x18C);
    VTABLE(0x060, fBase_c, 0x8097DDD8);
    // 0x8097DD78 g_profile_UNIT_CHIKUWA
    // 0x808B2190 daUnitChikuwa_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daUnitChikuwa_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x125, 0x18C);
};
