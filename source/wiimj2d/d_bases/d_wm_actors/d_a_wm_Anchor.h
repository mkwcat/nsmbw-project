#pragma once

#include "d_wm_demo_actor.h"

class daWmAnchor_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1F4);
    VTABLE(0x060, fBase_c, 0x80981990);
    // 0x80981960 g_profile_WM_ANCHOR
    // 0x808C7D10 daWmAnchor_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808C7D40 */
    daWmAnchor_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1F4);
};
