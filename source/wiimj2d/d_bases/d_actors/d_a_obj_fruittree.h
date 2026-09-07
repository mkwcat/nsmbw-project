#pragma once

#include "d_enemy.h"

class daObjFruitTree_c : public dEn_c {
    SIZE_ASSERT(0x5C0);
    VTABLE(0x060, fBase_c, 0x809723C8);
    // 0x809722D8 g_profile_OBJ_FRUITTREE
    // 0x80875AD0 daObjFruitTree_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjFruitTree_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5C0);
};
