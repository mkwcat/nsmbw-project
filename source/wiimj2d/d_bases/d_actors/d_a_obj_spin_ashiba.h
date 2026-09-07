#pragma once

#include "d_a_obj_spin_child_base.h"

class daObjSpinAshiba_c : public daObjSpinChildBase_c {
    SIZE_ASSERT(0x5B0);
    VTABLE(0x060, fBase_c, 0x809768D8);
    // 0x80976860 g_profile_OBJ_SPIN_ASHIBA
    // 0x80888ED0 daObjSpinAshiba_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjSpinAshiba_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5B0);
};
