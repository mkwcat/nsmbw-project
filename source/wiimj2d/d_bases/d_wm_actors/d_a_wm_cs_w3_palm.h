#pragma once

#include "d_wm_demo_actor.h"

class daWmCsW3Palm_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1F8);
    VTABLE(0x060, fBase_c, 0x80987A98);
    // 0x80987A64 g_profile_WM_CS_W3_PALM
    // 0x808FA8E0 daWmCsW3Palm_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808FA910 */
    daWmCsW3Palm_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1F8);
};
