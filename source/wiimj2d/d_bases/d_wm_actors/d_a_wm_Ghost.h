#pragma once

#include "d_wm_demo_actor.h"

class daWmGhost_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x3D8);
    VTABLE(0x060, fBase_c, 0x80982DF8);
    // 0x80982D1C g_profile_WM_GHOST
    // 0x808D0D90 daWmGhost_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D0DC0 */
    daWmGhost_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x3D8);
};
