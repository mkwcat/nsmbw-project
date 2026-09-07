#pragma once

#include "d_a_obj_pipe_base.h"

class daObjPipeUpNg_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5D0);
    VTABLE(0x060, fBase_c, 0x809758F4);
    // 0x809758E8 g_profile_OBJ_PIPE_UP_NG
    // 0x80885F10 daObjPipeUpNg_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjPipeUpNg_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5D0);
};
