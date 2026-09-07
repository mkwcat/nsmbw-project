#pragma once

#include "d_actor.h"

class daTagThunder_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x8097CD34);
    // 0x8097CD28 g_profile_TAG_THUNDER
    // 0x808AC770 daTagThunder_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTagThunder_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
