#pragma once

#include "d_a_wm_BossBase.h"

class daWmBossLarry_c : public daWmBossBase_c {
    SIZE_ASSERT(0x444);
    VTABLE(0x060, fBase_c, 0x80986F64);
    // 0x80986F58 g_profile_WM_BOSS_LARRY
    // 0x808F8BE0 daWmBossLarry_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmBossLarry_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x440, 0x444);
};
