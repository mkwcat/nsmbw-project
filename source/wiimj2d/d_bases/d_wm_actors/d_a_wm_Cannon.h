#pragma once

#include "d_wm_demo_actor.h"

class daWmCannon_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1B4);
    VTABLE(0x060, fBase_c, 0x809821D8);
    // 0x809821AC g_profile_WM_CANNON
    // 0x808CBF50 daWmCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CBF80 */
    daWmCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1B4);
};
