#pragma once

#include "d_a_obj_move_on_base.h"

class daObjMoveOnGhost_c : public daObjMoveOnBase_c {
    SIZE_ASSERT(0x4A10);
    VTABLE(0x0060, fBase_c, 0x80975440);
    // 0x80975430 g_profile_OBJ_MOVE_ON_GHOST
    // 0x80885160 daObjMoveOnGhost_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjMoveOnGhost_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x04C0, 0x4A10);
};
