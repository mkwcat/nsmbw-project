#pragma once

#include "d_enemy.h"

class daEnZoom_c : public dEn_c {
    SIZE_ASSERT(0x530);
    VTABLE(0x060, fBase_c, 0x80B10E58);
    // 0x80B10E48 g_profile_EN_ZOOM
    // 0x80ACCE70 daEnZoom_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnZoom_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x530);
};
