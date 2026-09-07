#pragma once

#include "d_enemy.h"

class daEnBoyon_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80ADEA10);
    // 0x80ADEA00 g_profile_EN_BOYON
    // 0x809CFF70 daEnBoyon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBoyon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
