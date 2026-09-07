#pragma once

#include "d_enemy.h"

class daEnIwao_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80AF1F90);
    // 0x80AF1F80 g_profile_EN_IWAO
    // 0x80A2E6F0 daEnIwao_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnIwao_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
