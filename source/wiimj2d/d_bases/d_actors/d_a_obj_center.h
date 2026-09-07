#pragma once

#include "d_actor.h"

class daObjCenter_c : public dActor_c {
    SIZE_ASSERT(0x3A0);
    VTABLE(0x060, fBase_c, 0x80971E9C);
    // 0x80971E90 g_profile_OBJ_CENTER
    // 0x808743D0 daObjCenter_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjCenter_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3A0);
};
