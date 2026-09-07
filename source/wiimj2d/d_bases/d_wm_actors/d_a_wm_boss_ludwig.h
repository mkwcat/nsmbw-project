#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossLudwig_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x80987264);
    // 0x80987258 g_profile_WM_BOSS_LUDWIG
    // 0x808F9020 daWmBossLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossLudwig_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
