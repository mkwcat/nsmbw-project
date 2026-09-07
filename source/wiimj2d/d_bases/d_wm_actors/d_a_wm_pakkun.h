#pragma once

#include "d_wm_enemy.h"

class daWmPakkun_c : public dWmEnemy_c {
    SIZE_ASSERT(0x870);
    VTABLE(0x060, fBase_c, 0x809889D0);
    // 0x80988934 g_profile_WM_PAKKUN
    // 0x80900680 daWmPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x809006B0 */
    daWmPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x870);
};
