#pragma once

#include "d_wm_demo_actor.h"

class daWmBubble_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x898);
    VTABLE(0x060, fBase_c, 0x809820C0);
    // 0x80981E0C g_profile_WM_BUBBLE
    // 0x808CA1E0 daWmBubble_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CA210 */
    daWmBubble_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x898);
};
