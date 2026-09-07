#pragma once

#include "d_base.h"

class dWorldSelectGuide_c : public dBase_c {
    SIZE_ASSERT(0x238);
    VTABLE(0x060, fBase_c, 0x8098EAF0);
    // 0x8098E948 g_profile_WORLD_SELECT_GUIDE
    // 0x8092B3E0 dWorldSelectGuide_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8092B410 */
    dWorldSelectGuide_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x238);
};
