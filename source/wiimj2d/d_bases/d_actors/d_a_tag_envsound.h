#pragma once

#include "d_enemy.h"

class daTagEnvSound_c : public dEn_c {
    SIZE_ASSERT(0x548);
    VTABLE(0x060, fBase_c, 0x8097C9C8);
    // 0x8097C9B8 g_profile_TAG_ENVSOUND
    // 0x808AC390 daTagEnvSound_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTagEnvSound_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x548);
};
