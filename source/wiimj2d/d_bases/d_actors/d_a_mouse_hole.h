#pragma once

#include "d_actor.h"

class daMouseHole_c : public dActor_c {
    SIZE_ASSERT(0x4A8);
    VTABLE(0x060, fBase_c, 0x80970EC8);
    // 0x80970E98 g_profile_MOUSE_HOLE
    // 0x8086CAD0 daMouseHole_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daMouseHole_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x4A8);
};
