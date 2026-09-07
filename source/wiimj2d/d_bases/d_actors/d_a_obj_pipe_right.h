#pragma once

#include "d_a_obj_pipe_base.h"

class daObjPipeRight_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5D0);
    VTABLE(0x060, fBase_c, 0x80975734);
    // 0x80975728 g_profile_OBJ_PIPE_RIGHT
    // 0x80885AF0 daObjPipeRight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjPipeRight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5D0);
};
