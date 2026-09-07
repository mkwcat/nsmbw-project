#pragma once

#include "d_wm_demo_actor.h"

class daWmSmallCloud_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1FC);
    VTABLE(0x060, fBase_c, 0x809855C8);
    // 0x8098550C g_profile_WM_SMALLCLOUD
    // 0x808E6F50 daWmSmallCloud_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E6F80 */
    daWmSmallCloud_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1FC);
};
