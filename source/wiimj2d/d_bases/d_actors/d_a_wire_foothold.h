#pragma once

#include "d_actor.h"

class daWireFoothold_c : public dActor_c {
    SIZE_ASSERT(0x4D8);
    VTABLE(0x060, fBase_c, 0x80980D00);
    // 0x80980CC8 g_profile_AC_WIRE_FOOTHOLD
    // 0x808C2BA0 daWireFoothold_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWireFoothold_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x4D8);
};
