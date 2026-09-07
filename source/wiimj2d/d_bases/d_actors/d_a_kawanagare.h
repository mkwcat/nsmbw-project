#pragma once

#include "d_actor.h"

class daKawangare_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80962304);
    // 0x809622F8 g_profile_KAWANAGARE
    // 0x8081D8F0 daKawangare_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKawangare_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
