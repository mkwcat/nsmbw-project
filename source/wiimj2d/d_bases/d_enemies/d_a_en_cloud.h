#pragma once

#include "d_enemy.h"

class daEnCloud_c : public dEn_c {
    SIZE_ASSERT(0x9A60);
    VTABLE(0x0060, fBase_c, 0x80AE1518);
    // 0x80AE1458 g_profile_EN_CLOUD
    // 0x809DCA80 daEnCloud_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCloud_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x9A60);
};
