#pragma once

#include "d_wm_demo_actor.h"

class daWmPeach_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x25C);
    VTABLE(0x060, fBase_c, 0x80984B38);
    // 0x80984B10 g_profile_WM_PEACH
    // 0x808E3DA0 daWmPeach_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E3DD0 */
    daWmPeach_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x25C);
};
