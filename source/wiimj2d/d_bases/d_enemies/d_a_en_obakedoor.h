#pragma once

#include "d_a_en_door.h"

class daEnObakeDoor_c : public daEnDoor_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80AFE478);
    // 0x80AFE430 g_profile_EN_OBAKEDOOR
    // 0x80A756C0 daEnObakeDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnObakeDoor_c();
};
