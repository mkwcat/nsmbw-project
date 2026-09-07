#pragma once

#include "d_base.h"

class dAcCursor_c : public dBase_c {
    SIZE_ASSERT(0x60C);
    VTABLE(0x060, fBase_c, 0x80323238);
    // 0x80323168 g_profile_CURSOR
    // 0x8010F530 dAcCursor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    dAcCursor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x60C);
};
