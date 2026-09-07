#pragma once

#include "d_a_flydokan.h"

class daFlyDokan_Right_c : public daFlyDokan_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x8095BA48);
    // 0x8095BA38 g_profile_FLYDOKAN_RIGHT
    // 0x807F53A0 daFlyDokan_Right_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFlyDokan_Right_c();
};
