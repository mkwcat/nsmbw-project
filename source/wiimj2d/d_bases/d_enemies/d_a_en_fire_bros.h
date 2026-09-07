#pragma once

#include "d_a_en_bros_base.h"

class daEnFireBros_c : public daEnBrosBase_c {
    SIZE_ASSERT(0x850);
    VTABLE(0x060, fBase_c, 0x80AE8DB4);
    // 0x80AE8DA8 g_profile_EN_FIREBROS
    // 0x809F86B0 daEnFireBros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnFireBros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x84C, 0x850);
};
