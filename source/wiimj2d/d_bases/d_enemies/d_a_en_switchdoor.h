#pragma once

#include "d_a_en_door.h"

class daEnSwitchDoor_c : public daEnDoor_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80B0A24C);
    // 0x80B0A240 g_profile_EN_SWITCHDOOR
    // 0x80AAD0B0 daEnSwitchDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSwitchDoor_c();
};
