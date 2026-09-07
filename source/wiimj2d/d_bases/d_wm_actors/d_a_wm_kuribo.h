#pragma once

#include "d_wm_enemy.h"

class daWmKuribo_c : public dWmEnemy_c {
    SIZE_ASSERT(0x7C0);
    VTABLE(0x060, fBase_c, 0x809887F0);
    // 0x8098872C g_profile_WM_KURIBO
    // 0x808FF4B0 daWmKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808FF4E0 */
    daWmKuribo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x7C0);
};
