#pragma once

#include "d_enemy.h"

class daEnYajirushi_c : public dEn_c {
    SIZE_ASSERT(0x550);
    VTABLE(0x060, fBase_c, 0x80B10BC8);
    // 0x80B10BA0 g_profile_EN_YAJIRUSHI
    // 0x80ACCA70 daEnYajirushi_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnYajirushi_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x550);
};
