#pragma once

#include "d_wm_demo_actor.h"

class daWmNote_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1C8);
    VTABLE(0x060, fBase_c, 0x80984A48);
    // 0x80984A24 g_profile_WM_NOTE
    // 0x808E3700 daWmNote_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E3730 */
    daWmNote_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1C8);
};
