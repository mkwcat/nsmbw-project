#pragma once

#include "d_enemy.h"

class daEnReverse_c : public dEn_c {
    SIZE_ASSERT(0x578);
    VTABLE(0x060, fBase_c, 0x80B060C0);
    // 0x80B060A0 g_profile_EN_REVERSE
    // 0x80A97B30 daEnReverse_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnReverse_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x578);
};
