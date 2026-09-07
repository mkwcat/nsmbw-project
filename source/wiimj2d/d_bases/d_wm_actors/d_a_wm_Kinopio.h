#pragma once

#include "d_wm_demo_actor.h"

class daWmKinopio_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1BC);
    VTABLE(0x060, fBase_c, 0x80983FE8);
    // 0x80983F40 g_profile_WM_KINOPIO
    // 0x808D98C0 daWmKinopio_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D98F0 */
    daWmKinopio_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1BC);
};
