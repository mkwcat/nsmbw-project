#pragma once

#include "d_base.h"

class dWiiStrap_c : public dBase_c {
    SIZE_ASSERT(0x20C);
    VTABLE(0x060, fBase_c, 0x80323118);
    // 0x80429540 g_profile_WII_STRAP
    // 0x8010F080 dWiiStrap_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8010F0B0 */
    dWiiStrap_c();

public:
    FILL(0x070, 0x208);

    /* 0x208 */ bool mReady;
    /* 0x209 */ bool mVisible;

    FILL(0x20A, 0x20C);
};
