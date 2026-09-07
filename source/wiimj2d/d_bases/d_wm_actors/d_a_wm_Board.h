#pragma once

#include "d_wm_demo_actor.h"

class daWmBoard_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1F0);
    VTABLE(0x060, fBase_c, 0x80981CE8);
    // 0x80981CA0 g_profile_WM_BOARD
    // 0x808C9970 daWmBoard_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808C99A0 */
    daWmBoard_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1F0);
};
