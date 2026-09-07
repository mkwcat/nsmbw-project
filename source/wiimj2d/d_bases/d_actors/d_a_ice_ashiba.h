#pragma once

#include "d_a_ice_ashiba_base.h"

class daIceAshiba_c : public daIceAshibaBase_c {
    SIZE_ASSERT(0x508);
    VTABLE(0x060, fBase_c, 0x8095D37C);
    // 0x8095D370 g_profile_ICE_ASHIBA
    // 0x807FEAD0 daIceAshiba_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIceAshiba_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4E4, 0x508);
};
