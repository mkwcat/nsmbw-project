#pragma once

#include "d_wm_demo_actor.h"

class daWmManta_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x228);
    VTABLE(0x060, fBase_c, 0x80984620);
    // 0x809845F8 g_profile_WM_MANTA
    // 0x808DE620 daWmManta_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808DE650 */
    daWmManta_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x228);
};
