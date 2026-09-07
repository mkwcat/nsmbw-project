#pragma once

#include "d_wm_demo_actor.h"

class daWmKoopaJr_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x360);
    VTABLE(0x060, fBase_c, 0x80984188);
    // 0x8098408C g_profile_WM_KOOPAJR
    // 0x808DAA00 daWmKoopaJr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808DAA30 */
    daWmKoopaJr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x360);
};
