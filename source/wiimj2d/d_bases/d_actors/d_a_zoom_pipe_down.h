#pragma once

#include "d_a_obj_pipe_base.h"

class daZoomPipeDown_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x8098A814);
    // 0x8098A808 g_profile_ZOOM_PIPE_DOWN
    // 0x80913BF0 daZoomPipeDown_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daZoomPipeDown_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5E0);
};
