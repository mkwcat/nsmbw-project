#pragma once

#include "d_a_rot_block.h"

class daRotBlockFullColor_c : public daRotBlock_c {
    SIZE_ASSERT(0x4A38);
    VTABLE(0x0060, fBase_c, 0x80979E14);
    // 0x80979E08 g_profile_LIFT_ROTATION_FULL_COLOR
    // 0x8089A430 daRotBlockFullColor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotBlockFullColor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x04E0, 0x4A38);
};
