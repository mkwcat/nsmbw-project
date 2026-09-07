#pragma once

#include "d_a_obj_spin_child_base.h"

class daObjSpinChild_c : public daObjSpinChildBase_c {
    SIZE_ASSERT(0x4A18);
    VTABLE(0x0060, fBase_c, 0x809769D4);
    // 0x809769C8 g_profile_OBJ_SPIN_CHILD
    // 0x80889230 daObjSpinChild_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjSpinChild_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x4A18);
};
