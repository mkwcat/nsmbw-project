#pragma once

#include "d_actor.h"

class daBgCenter_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80951EBC);
    // 0x80951EB0 g_profile_BG_CENTER
    // 0x807BBC70 daBgCenter_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBgCenter_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
