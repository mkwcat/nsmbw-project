#pragma once

#include "d_a_flydokan.h"

class daFlyDokan_Up_c : public daFlyDokan_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x8095BB38);
    // 0x8095BB28 g_profile_FLYDOKAN_UP
    // 0x807F55B0 daFlyDokan_Up_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFlyDokan_Up_c();
};
