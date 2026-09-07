#pragma once

#include "d_enemy.h"

class daEnHelpos_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80AEE184);
    // 0x80AEE178 g_profile_EN_HELPOS
    // 0x80A15F00 daEnHelpos_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnHelpos_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
