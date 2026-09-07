#pragma once

#include "d_enemy.h"

class daEnRotPakkun_c : public dEn_c {
    SIZE_ASSERT(0x588);
    VTABLE(0x060, fBase_c, 0x80B06978);
    // 0x80B06968 g_profile_EN_ROT_PAKKUN
    // 0x80A98FB0 daEnRotPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRotPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x588);
};
