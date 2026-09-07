#pragma once

#include "d_enemy.h"

class daEnLiftBuranko_c : public dEn_c {
    SIZE_ASSERT(0x5C0);
    VTABLE(0x060, fBase_c, 0x80AF8E78);
    // 0x80AF8E40 g_profile_EN_LIFT_BURANKO
    // 0x80A5B060 daEnLiftBuranko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLiftBuranko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5C0);
};
