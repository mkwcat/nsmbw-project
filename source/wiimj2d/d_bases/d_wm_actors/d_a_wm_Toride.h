#pragma once

#include "d_wm_demo_actor.h"

class daWmToride_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x2D8);
    VTABLE(0x060, fBase_c, 0x809861D8);
    // 0x80986144 g_profile_WM_TORIDE
    // 0x808F1F10 daWmToride_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F1F40 */
    daWmToride_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x2D8);
};
