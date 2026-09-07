#pragma once

#include "d_wm_demo_actor.h"

class daWmKiller_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x23C);
    VTABLE(0x060, fBase_c, 0x80983560);
    // 0x809834F0 g_profile_WM_KILLER
    // 0x808D50B0 daWmKiller_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D50E0 */
    daWmKiller_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x23C);
};
