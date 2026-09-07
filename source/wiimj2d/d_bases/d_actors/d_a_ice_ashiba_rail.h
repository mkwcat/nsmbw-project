#pragma once

#include "d_a_ice_ashiba_base.h"

class daIceAshibaRail_c : public daIceAshibaBase_c {
    SIZE_ASSERT(0x538);
    VTABLE(0x060, fBase_c, 0x8095D474);
    // 0x8095D468 g_profile_ICE_ASHIBA_RAIL
    // 0x807FEE40 daIceAshibaRail_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIceAshibaRail_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4E4, 0x538);
};
