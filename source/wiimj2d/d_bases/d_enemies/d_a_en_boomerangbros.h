#pragma once

#include "d_a_en_bros_base.h"

class daEnBoomerangbros_c : public daEnBrosBase_c {
    SIZE_ASSERT(0x858);
    VTABLE(0x060, fBase_c, 0x80ADE2A4);
    // 0x80ADE298 g_profile_EN_BOOMERANGBROS
    // 0x809CDE70 daEnBoomerangbros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBoomerangbros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x84C, 0x858);
};
