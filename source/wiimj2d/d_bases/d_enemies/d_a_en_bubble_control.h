#pragma once

#include "d_enemy.h"

class daEnBubbleCtrl_c : public dEn_c {
    SIZE_ASSERT(0x6950);
    VTABLE(0x0060, fBase_c, 0x80ADF4D8);
    // 0x80ADF428 g_profile_EN_BUBBLE_CONTROL
    // 0x809D26D0 daEnBubbleControl_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBubbleCtrl_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x6950);
};
