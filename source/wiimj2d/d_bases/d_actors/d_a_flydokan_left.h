#pragma once

#include "d_a_flydokan.h"

class daFlyDokan_Left_c : public daFlyDokan_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x8095B958);
    // 0x8095B948 g_profile_FLYDOKAN_LEFT
    // 0x807F50D0 daFlyDokan_Left_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFlyDokan_Left_c();
};
