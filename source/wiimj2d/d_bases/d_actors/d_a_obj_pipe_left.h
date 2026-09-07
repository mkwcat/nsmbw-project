#pragma once

#include "d_a_obj_pipe_base.h"

class daObjPipeLeft_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5D0);
    VTABLE(0x060, fBase_c, 0x80975654);
    // 0x80975648 g_profile_OBJ_PIPE_LEFT
    // 0x808858E0 daObjPipeLeft_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjPipeLeft_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5D0);
};
