#pragma once

#include "d_wm_demo_actor.h"

class daWmSurrender_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x260);
    VTABLE(0x060, fBase_c, 0x809897F8);
    // 0x80989794 g_profile_WM_SURRENDER
    // 0x8090EA00 daWmSurrender_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8090EA30 */
    daWmSurrender_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x260);
};
