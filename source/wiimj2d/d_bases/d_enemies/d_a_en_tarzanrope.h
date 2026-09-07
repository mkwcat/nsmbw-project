#pragma once

#include "d_enemy.h"

class daEnTarzanrope_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80B0A950);
    // 0x80B0A940 g_profile_EN_TARZANROPE
    // 0x80AAE4B0 daEnTarzanrope_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTarzanrope_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
