#pragma once

#include "d_a_obj_move_on_base.h"

class daLiftDownOn_c : public daObjMoveOnBase_c {
    SIZE_ASSERT(0x4F0);
    VTABLE(0x060, fBase_c, 0x80966D80);
    // 0x80966CF8 g_profile_LIFT_DOWN_ON
    // 0x80836700 daLiftDownOn_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftDownOn_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4C0, 0x4F0);
};
