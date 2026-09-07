#pragma once

#include "d_wm_demo_actor.h"

class daWmKillerBullet_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x208);
    VTABLE(0x060, fBase_c, 0x80983840);
    // 0x8098369C g_profile_WM_KILLERBULLET
    // 0x808D5E50 daWmKillerBullet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D5E80 */
    daWmKillerBullet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x208);
};
