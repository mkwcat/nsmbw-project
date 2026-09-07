#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossWendy_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x809876CC);
    // 0x809876C0 g_profile_WM_BOSS_WENDY
    // 0x808F9690 daWmBossWendy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossWendy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
