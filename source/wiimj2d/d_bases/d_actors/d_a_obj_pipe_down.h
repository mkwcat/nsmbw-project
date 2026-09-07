#pragma once

#include "d_a_obj_pipe_base.h"

class daObjPipeDown_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5D0);
    VTABLE(0x060, fBase_c, 0x80975574);
    // 0x80975568 g_profile_OBJ_PIPE_DOWN
    // 0x808856D0 daObjPipeDown_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjPipeDown_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5D0);
};
