#pragma once

#include "d_a_en_door.h"

class daEnCastleDoor_c : public daEnDoor_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80ADFB28);
    // 0x80ADFAE8 g_profile_EN_CASTLEDOOR
    // 0x809D4620 daEnCastleDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnCastleDoor_c();
};
