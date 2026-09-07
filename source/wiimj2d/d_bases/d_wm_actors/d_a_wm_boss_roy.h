#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossRoy_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x80987550);
    // 0x80987544 g_profile_WM_BOSS_ROY
    // 0x808F9460 daWmBossRoy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossRoy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
