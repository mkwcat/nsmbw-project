#pragma once

#include "d_a_flydokan.h"

class daFlyDokan_Down_c : public daFlyDokan_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x8095B868);
    // 0x8095B858 g_profile_FLYDOKAN_DOWN
    // 0x807F4ED0 daFlyDokan_Down_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFlyDokan_Down_c();
};
