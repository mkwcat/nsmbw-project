#pragma once

#include "d_enemy.h"

class daObjSeaweed_c : public dEn_c {
    SIZE_ASSERT(0x5C8);
    VTABLE(0x060, fBase_c, 0x80975F30);
    // 0x80975EF0 g_profile_OBJ_SEAWEED
    // 0x80887380 daObjSeaweed_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjSeaweed_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5C8);
};
