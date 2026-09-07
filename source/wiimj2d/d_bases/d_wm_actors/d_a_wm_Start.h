#pragma once

#include "d_wm_demo_actor.h"

class daWmStart_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x204);
    VTABLE(0x060, fBase_c, 0x80985738);
    // 0x80985704 g_profile_WM_START
    // 0x808E7760 daWmStart_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E7790 */
    daWmStart_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x204);
};
