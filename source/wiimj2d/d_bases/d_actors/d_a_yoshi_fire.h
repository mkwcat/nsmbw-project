#pragma once

#include "d_actor.h"

class daYoshiFire_c : public dActor_c {
    SIZE_ASSERT(0x500);
    VTABLE(0x060, fBase_c, 0x8098A28C);
    // 0x8098A230 g_profile_YOSHI_FIRE
    // 0x809125E0 daYoshiFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daYoshiFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x500);
};
