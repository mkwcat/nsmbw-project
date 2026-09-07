#pragma once

#include "d_actor.h"

class daHanaMountain_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x8095D024);
    // 0x8095D018 g_profile_HANA_MOUNTAIN
    // 0x807FD830 daHanaMountain_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daHanaMountain_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
