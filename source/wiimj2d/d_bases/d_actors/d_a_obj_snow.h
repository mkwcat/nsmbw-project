#pragma once

#include "d_enemy.h"

class daObjSnow_c : public dEn_c {
    SIZE_ASSERT(0x17C8);
    VTABLE(0x0060, fBase_c, 0x80976258);
    // 0x809761C8 g_profile_OBJ_SNOW
    // 0x80887940 daObjSnow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjSnow_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x17C8);
};
