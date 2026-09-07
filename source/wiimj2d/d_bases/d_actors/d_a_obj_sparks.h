#pragma once

#include "d_enemy.h"

class daObjSparks_c : public dEn_c {
    SIZE_ASSERT(0x1310);
    VTABLE(0x0060, fBase_c, 0x80976580);
    // 0x80976538 g_profile_OBJ_SPARKS
    // 0x80888530 daObjSparks_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjSparks_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x1310);
};
