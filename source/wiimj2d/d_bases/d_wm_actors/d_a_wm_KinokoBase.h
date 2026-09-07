#pragma once

#include "d_wm_demo_actor.h"

class daWmKinokoBase_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x290);
    VTABLE(0x060, fBase_c, 0x80983BB8);
    // 0x80983B64 g_profile_WM_KINOKO_BASE
    // 0x808D8A40 daWmKinokoBase_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D8A70 */
    daWmKinokoBase_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x290);
};
