#pragma once

#include "d_enemy.h"

class daEnEnv_c : public dEn_c {
    SIZE_ASSERT(0x548);
    VTABLE(0x060, fBase_c, 0x80AE8B28);
    // 0x80AE8B08 g_profile_EN_ENV
    // 0x809F8540 daEnEnv_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnEnv_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x548);
};
