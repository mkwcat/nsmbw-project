#pragma once

#include "d_wm_demo_actor.h"

class daWmDirector_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1D4);
    VTABLE(0x060, fBase_c, 0x80987EB8);
    // 0x80987BD8 g_profile_WM_DIRECTOR
    // 0x808FAF40 daWmDirector_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808FAF70 */
    daWmDirector_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1D4);
};
