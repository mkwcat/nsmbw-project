#pragma once

#include "d_wm_demo_actor.h"

class daWmTower_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1B0);
    VTABLE(0x060, fBase_c, 0x80986360);
    // 0x80986334 g_profile_WM_TOWER
    // 0x808F2E80 daWmTower_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F2EB0 */
    daWmTower_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1B0);
};
