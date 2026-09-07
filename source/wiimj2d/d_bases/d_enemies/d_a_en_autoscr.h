#pragma once

#include "d_enemy.h"

class daEnAutoscr_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80AD6088);
    // 0x80AD6078 g_profile_EN_AUTOSCR
    // 0x809A5F70 daEnAutoscr_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnAutoscr_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
