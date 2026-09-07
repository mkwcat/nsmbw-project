#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossLemmy_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x809870E4);
    // 0x809870D8 g_profile_WM_BOSS_LEMMY
    // 0x808F8E00 daWmBossLemmy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossLemmy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
