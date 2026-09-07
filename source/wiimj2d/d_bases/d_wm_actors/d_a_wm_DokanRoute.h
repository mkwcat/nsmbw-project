#pragma once

#include "d_wm_demo_actor.h"

class daWmDokanRoute_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x26C);
    VTABLE(0x060, fBase_c, 0x80982BE0);
    // 0x80982B08 g_profile_WM_DOKANROUTE
    // 0x808CFCF0 daWmDokanRoute_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CFD20 */
    daWmDokanRoute_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x26C);
};
