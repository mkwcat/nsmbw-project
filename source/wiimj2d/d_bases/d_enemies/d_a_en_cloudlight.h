#pragma once

#include "d_enemy.h"

class daEnCloudLight_c : public dEn_c {
    SIZE_ASSERT(0x1C30);
    VTABLE(0x0060, fBase_c, 0x80AE1848);
    // 0x80AE17F8 g_profile_EN_CLOUDLT
    // 0x809DF860 daEnCloudLight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCloudLight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x1C30);
};
