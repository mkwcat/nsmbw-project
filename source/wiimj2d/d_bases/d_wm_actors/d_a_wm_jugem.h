#pragma once

#include "d_wm_enemy.h"

class daWmJugem_c : public dWmEnemy_c {
    SIZE_ASSERT(0x804);
    VTABLE(0x060, fBase_c, 0x80988430);
    // 0x809883B4 g_profile_WM_JUGEM
    // 0x808FDAC0 daWmJugem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808FDAF0 */
    daWmJugem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x804);
};
