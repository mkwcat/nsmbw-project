#pragma once

#include "d_enemy.h"

class daEnTrplnWall_c : public dEn_c {
    SIZE_ASSERT(0x640);
    VTABLE(0x060, fBase_c, 0x80B0C838);
    // 0x80B0C808 g_profile_EN_TRPLN_WALL
    // 0x80AB8500 daEnTrplnWall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTrplnWall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x640);
};
