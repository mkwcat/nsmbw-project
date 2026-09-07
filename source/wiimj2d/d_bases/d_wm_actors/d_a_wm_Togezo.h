#pragma once

#include "d_wm_demo_actor.h"

class daWmTogezo_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x228);
    VTABLE(0x060, fBase_c, 0x809860A0);
    // 0x80986074 g_profile_WM_TOGEZO
    // 0x808F1740 daWmTogezo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F1770 */
    daWmTogezo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x228);
};
