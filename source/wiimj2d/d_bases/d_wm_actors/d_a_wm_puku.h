#pragma once

#include "d_wm_enemy.h"

class daWmPuku_c : public dWmEnemy_c {
    SIZE_ASSERT(0x79C);
    VTABLE(0x060, fBase_c, 0x80989650);
    // 0x809894B4 g_profile_WM_PUKU
    // 0x8090D220 daWmPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8090D250 */
    daWmPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x79C);
};
