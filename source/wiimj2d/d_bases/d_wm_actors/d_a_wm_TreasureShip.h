#pragma once

#include "d_wm_demo_actor.h"

class daWmTreasureShip_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1CC);
    VTABLE(0x060, fBase_c, 0x80986438);
    // 0x8098640C g_profile_WM_TREASURESHIP
    // 0x808F32E0 daWmTreasureShip_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F3310 */
    daWmTreasureShip_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1CC);
};
