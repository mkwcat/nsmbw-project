#pragma once

#include "d_a_rot_block.h"

class daRotBlockFullChika_c : public daRotBlock_c {
    SIZE_ASSERT(0x570);
    VTABLE(0x060, fBase_c, 0x80979D00);
    // 0x80979C78 g_profile_LIFT_ROTATION_FULL_CHIKA
    // 0x8089A030 daRotBlockFullChika_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotBlockFullChika_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4E0, 0x570);
};
