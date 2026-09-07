#pragma once

#include "d_a_en_door.h"

class daEnTorideDoor_c : public daEnDoor_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80B0C550);
    // 0x80B0C510 g_profile_EN_TORIDEDOOR
    // 0x80AB7FD0 daEnTorideDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTorideDoor_c();
};
