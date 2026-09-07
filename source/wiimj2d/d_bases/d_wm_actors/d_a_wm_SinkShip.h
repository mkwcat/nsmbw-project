#pragma once

#include "d_wm_demo_actor.h"

class daWmSinkShip_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1B0);
    VTABLE(0x060, fBase_c, 0x80985460);
    // 0x80985434 g_profile_WM_SINKSHIP
    // 0x808E6AF0 daWmSinkShip_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E6B20 */
    daWmSinkShip_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1B0);
};
