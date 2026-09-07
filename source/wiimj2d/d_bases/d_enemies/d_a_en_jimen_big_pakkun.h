#pragma once

#include "d_a_en_jimen_pakkun_base.h"

class daEnJimenBigPakkun_c : public daEnJimenPakkunBase_c {
    SIZE_ASSERT(0x780);
    VTABLE(0x060, fBase_c, 0x80AF2A90);
    // 0x80AF2A80 g_profile_EN_JIMEN_BIG_PAKKUN
    // 0x80A32230 daEnJimenBigPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJimenBigPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x76C, 0x780);
};
