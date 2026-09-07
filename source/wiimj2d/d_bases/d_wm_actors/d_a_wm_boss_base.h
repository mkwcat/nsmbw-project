#pragma once

#include "d_wm_demo_actor.h"

class daWmBossBase_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x440);
    VTABLE(0x060, fBase_c, 0x80986974);
    // 0x8098687C g_profile_WM_BOSS_BASE
    // 0x808F4FE0 daWmBossBase_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F5010 */
    daWmBossBase_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x440);
};
