#pragma once

#include "d_a_en_lkuribo_base.h"

class daEnLargeKuribo_c : public daEnLkuriboBase_c {
    SIZE_ASSERT(0x770);
    VTABLE(0x060, fBase_c, 0x80AF8B38);
    // 0x80AF8AF0 g_profile_EN_LARGE_KURIBO
    // 0x80A5A5D0 daEnLargeKuribo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnLargeKuribo_c();
};
