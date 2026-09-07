#pragma once

#include "d_enemy.h"

class daEnKaitenHoudai_c : public dEn_c {
    SIZE_ASSERT(0xC90);
    VTABLE(0x060, fBase_c, 0x80AF49B0);
    // 0x80AF48F0 g_profile_EN_KAITEN_HOUDAI
    // 0x80A3D4A0 daEnKaitenHoudai_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKaitenHoudai_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xC90);
};
