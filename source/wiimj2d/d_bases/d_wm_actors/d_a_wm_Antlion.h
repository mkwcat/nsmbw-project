#pragma once

#include "d_wm_enemy.h"

class daWmAntlion_c : public dWmEnemy_c {
    SIZE_ASSERT(0x7B0);
    VTABLE(0x060, fBase_c, 0x80981A90);
    // 0x80981A3C g_profile_WM_ANTLION
    // 0x808C83F0 daWmAntlion_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808C8420 */
    daWmAntlion_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x7B0);
};
