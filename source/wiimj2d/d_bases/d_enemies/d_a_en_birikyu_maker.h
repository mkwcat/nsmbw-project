#pragma once

#include "d_enemy.h"

class daEnBirikyuMaker_c : public dEn_c {
    SIZE_ASSERT(0x630);
    VTABLE(0x060, fBase_c, 0x80ADA9A8);
    // 0x80ADA998 g_profile_EN_BIRIKYU_MAKER
    // 0x809BDA40 daEnBirikyuMaker_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBirikyuMaker_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x630);
};
