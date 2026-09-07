#pragma once

#include "d_wm_enemy.h"

class daWmBros_c : public dWmEnemy_c {
    SIZE_ASSERT(0x7B4);
    VTABLE(0x060, fBase_c, 0x80987920);
    // 0x809878C0 g_profile_WM_BROS
    // 0x808F98B0 daWmBros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F98E0 */
    daWmBros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x7B4);
};
