#pragma once

#include "d_actor.h"

class daDummyDoorChild_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80958C94);
    // 0x80958C88 g_profile_DUMMY_DOOR_CHILD
    // 0x807E5260 daDummyDoorChild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDummyDoorChild_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
