#pragma once

#include "d_a_obj_pipe_base.h"

class daObjPipeUp_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5D0);
    VTABLE(0x060, fBase_c, 0x80975814);
    // 0x80975808 g_profile_OBJ_PIPE_UP
    // 0x80885D00 daObjPipeUp_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjPipeUp_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5D0);
};
