#pragma once

#include "d_enemy.h"

class daEnWallInsect_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80B0DFB0);
    // 0x80B0DFA0 g_profile_EN_WALLINSECT
    // 0x80ABF390 daEnWallInsect_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnWallInsect_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
