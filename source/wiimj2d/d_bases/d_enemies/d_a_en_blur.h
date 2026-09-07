#pragma once

#include "d_enemy.h"

class daEnBlur_c : public dEn_c {
    SIZE_ASSERT(0x540);
    VTABLE(0x060, fBase_c, 0x80ADD8A0);
    // 0x80ADD890 g_profile_EN_BLUR
    // 0x809C8BD0 daEnBlur_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBlur_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x540);
};
