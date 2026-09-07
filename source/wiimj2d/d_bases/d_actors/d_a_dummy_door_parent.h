#pragma once

#include "d_actor.h"

class daDummyDoorParent_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80958D74);
    // 0x80958D68 g_profile_DUMMY_DOOR_PARENT
    // 0x807E5310 daDummyDoorParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daDummyDoorParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
