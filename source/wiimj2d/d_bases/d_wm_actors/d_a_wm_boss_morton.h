#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossMorton_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x809873DC);
    // 0x809873D0 g_profile_WM_BOSS_MORTON
    // 0x808F9240 daWmBossMorton_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossMorton_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
