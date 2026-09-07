#pragma once

#include "d_enemy.h"

class daEnRailPolyIce_c : public dEn_c {
    SIZE_ASSERT(0x730);
    VTABLE(0x060, fBase_c, 0x80B04418);
    // 0x80B043F0 g_profile_EN_RAIL_POLY_ICE
    // 0x80A8FC90 daEnRailPolyIce_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRailPolyIce_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x730);
};
