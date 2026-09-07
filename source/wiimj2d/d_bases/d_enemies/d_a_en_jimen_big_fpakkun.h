#pragma once

#include "d_a_en_jimen_pakkun_base.h"

class daEnJimenBigFpakkun_c : public daEnJimenPakkunBase_c {
    SIZE_ASSERT(0x780);
    VTABLE(0x060, fBase_c, 0x80AF27B8);
    // 0x80AF27A8 g_profile_EN_JIMEN_BIG_FPAKKUN
    // 0x80A31870 daEnJimenBigFpakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJimenBigFpakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x76C, 0x780);
};
