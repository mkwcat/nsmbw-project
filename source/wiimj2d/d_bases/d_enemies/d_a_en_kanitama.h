#pragma once

#include "d_enemy.h"

class daEnKanitama_c : public dEn_c {
    SIZE_ASSERT(0x5B0);
    VTABLE(0x060, fBase_c, 0x80AF5220);
    // 0x80AF51B0 g_profile_EN_KANITAMA
    // 0x80A40630 daEnKanitama_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKanitama_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5B0);
};
