#pragma once

#include "d_base.h"

class daFloorJrB_c : public dBase_c {
    SIZE_ASSERT(0x8A8);
    VTABLE(0x060, fBase_c, 0x8095AEBC);
    // 0x8095AEB0 g_profile_FLOOR_JR_B
    // 0x807F1950 daFloorJrB_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFloorJrB_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x8A8);
};
