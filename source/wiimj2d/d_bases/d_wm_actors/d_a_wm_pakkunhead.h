#pragma once

#include "d_wm_demo_actor.h"

class daWmPakkunHead_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x354);
    VTABLE(0x060, fBase_c, 0x80988C58);
    // 0x80988B60 g_profile_WM_PAKKUNHEAD
    // 0x809013B0 daWmPakkunHead_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x809013E0 */
    daWmPakkunHead_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x354);
};
