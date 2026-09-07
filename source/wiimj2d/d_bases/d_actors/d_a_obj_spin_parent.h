#pragma once

#include "d_actor.h"

class daObjSpinParent_c : public dActor_c {
    SIZE_ASSERT(0x440);
    VTABLE(0x060, fBase_c, 0x80976AE4);
    // 0x80976AC0 g_profile_OBJ_SPIN_PARENT
    // 0x80889530 daObjSpinParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjSpinParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x440);
};
