#pragma once

#include "d_enemy.h"

class daEnSlipPenguin_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80B08640);
    // 0x80B08630 g_profile_EN_SLIP_PENGUIN
    // 0x80AA2310 daEnSlipPenguin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSlipPenguin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
