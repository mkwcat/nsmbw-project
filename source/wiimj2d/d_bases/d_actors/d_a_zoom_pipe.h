#pragma once

#include "d_a_obj_pipe_base.h"

class daZoomPipe_c : public daObjPipeBase_c {
    SIZE_ASSERT(0x5E0);
    VTABLE(0x060, fBase_c, 0x8098A734);
    // 0x8098A728 g_profile_ZOOM_PIPE
    // 0x809139E0 daZoomPipe_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daZoomPipe_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x5E0);
};
