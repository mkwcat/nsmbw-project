#pragma once

#include "d_enemy.h"

class daEnObjPolToride_c : public dEn_c {
    SIZE_ASSERT(0x4C30);
    VTABLE(0x0060, fBase_c, 0x80B003EC);
    // 0x80B003E0 g_profile_EN_OBJ_POL_TORIDE
    // 0x80A7AB40 daEnObjPolToride_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObjPolToride_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x4C30);
};
