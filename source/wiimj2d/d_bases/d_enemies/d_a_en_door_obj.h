#pragma once

#include "d_a_en_door.h"

class daEnDoorObj_c : public daEnDoor_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x80AE7E88);
    // 0x80AE7E50 g_profile_EN_DOOR
    // 0x809F5620 daEnDoorObj_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnDoorObj_c();
};
