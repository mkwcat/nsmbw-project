#pragma once

#include "d_enemy.h"

class daEnMaruta_c : public dEn_c {
    SIZE_ASSERT(0x5E8);
    VTABLE(0x060, fBase_c, 0x80AFB3C0);
    // 0x80AFB390 g_profile_EN_MARUTA
    // 0x80A63300 daEnMaruta_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMaruta_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5E8);
};
