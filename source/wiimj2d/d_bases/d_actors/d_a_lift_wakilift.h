#pragma once

#include "d_actor.h"

class daWakiLift_c : public dActor_c {
    SIZE_ASSERT(0x3A8);
    VTABLE(0x060, fBase_c, 0x8096A060);
    // 0x8096A030 g_profile_AC_WAKILIFT
    // 0x8084EE00 daWakiLift_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiLift_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A8);
};
