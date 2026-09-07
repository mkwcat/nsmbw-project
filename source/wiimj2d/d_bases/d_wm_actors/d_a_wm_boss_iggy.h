#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossIggy_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x80986B54);
    // 0x80986B48 g_profile_WM_BOSS_IGGY
    // 0x808F79D0 daWmBossIggy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossIggy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
