#pragma once

#include "d_wm_demo_actor.h"

class daWmIbara_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x2C4);
    VTABLE(0x060, fBase_c, 0x80988278);
    // 0x80987F5C g_profile_WM_IBARA
    // 0x808FCB50 daWmIbara_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808FCB80 */
    daWmIbara_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x2C4);
};
