#pragma once

#include "d_wm_demo_actor.h"

class daWmCloud_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x25C);
    VTABLE(0x060, fBase_c, 0x80982578);
    // 0x80982530 g_profile_WM_CLOUD
    // 0x808CD350 daWmCloud_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CD380 */
    daWmCloud_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x25C);
};
