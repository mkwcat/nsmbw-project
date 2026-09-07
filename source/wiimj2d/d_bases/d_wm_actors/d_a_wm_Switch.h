#pragma once

#include "d_wm_demo_actor.h"

class daWmSwitch_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x218);
    VTABLE(0x060, fBase_c, 0x80985CE0);
    // 0x80985C8C g_profile_WM_SWITCH
    // 0x808EF8D0 daWmSwitch_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808EF900 */
    daWmSwitch_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x218);
};
