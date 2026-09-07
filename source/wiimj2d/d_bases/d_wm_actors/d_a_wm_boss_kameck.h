#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossKameck_c : public daWmBossBase_c {
    SIZE_ASSERT(0x668);
    VTABLE(0x060, fBase_c, 0x80986DD0);
    // 0x80986D64 g_profile_WM_BOSS_KAMECK
    // 0x808F7BF0 daWmBossKameck_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossKameck_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x668);
};
