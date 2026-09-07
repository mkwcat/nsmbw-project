#pragma once

#include "d_a_rot_block.h"

class daRotBlockFullKinoko_c : public daRotBlock_c {
    SIZE_ASSERT(0x510);
    VTABLE(0x060, fBase_c, 0x80979F68);
    // 0x80979F18 g_profile_LIFT_ROTATION_FULL_KINOKO
    // 0x8089A840 daRotBlockFullKinoko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotBlockFullKinoko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4E0, 0x510);
};
