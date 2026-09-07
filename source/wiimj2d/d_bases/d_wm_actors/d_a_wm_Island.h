#pragma once

#include "d_base_actor.h"

class daWmIsland_c : public dBaseActor_c {
    SIZE_ASSERT(0x2D4);
    VTABLE(0x060, fBase_c, 0x80983238);
    // 0x80983190 g_profile_WM_ISLAND
    // 0x808D33E0 daWmIsland_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D3410 */
    daWmIsland_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x125, 0x2D4);
};
