#pragma once

#include "d_enemy.h"

class daEnMadopu_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80AFA748);
    // 0x80AFA738 g_profile_EN_MADOPU
    // 0x80A5FCA0 daEnMadopu_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMadopu_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
