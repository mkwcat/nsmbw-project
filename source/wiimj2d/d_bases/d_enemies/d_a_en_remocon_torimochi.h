#pragma once

#include "d_enemy.h"

class daEnRemoconTorimochi_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80B05E20);
    // 0x80B05E10 g_profile_EN_REMOCON_TORIMOCHI
    // 0x80A97A10 daEnRemoconTorimochi_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnRemoconTorimochi_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
