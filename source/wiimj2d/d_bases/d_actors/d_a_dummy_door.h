#pragma once

#include "d_actor.h"

class daDummyDoor_c : public dActor_c {
    SIZE_ASSERT(0x3F8);
    VTABLE(0x060, fBase_c, 0x80958BB0);
    // 0x80958B58 g_profile_DUMMY_DOOR
    // 0x807E4E80 daDummyDoor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDummyDoor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3F8);
};
