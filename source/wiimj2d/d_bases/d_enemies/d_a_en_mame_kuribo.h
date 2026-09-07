#pragma once

#include "d_a_en_kuribo_base.h"

class daEnMameKuribo_c : public daEnKuriboBase_c {
    SIZE_ASSERT(0x860);
    VTABLE(0x060, fBase_c, 0x80AFA9D8);
    // 0x80AFA9C8 g_profile_EN_MAME_KURIBO
    // 0x80A5FDC0 daEnMameKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMameKuribo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x85C, 0x860);
};
