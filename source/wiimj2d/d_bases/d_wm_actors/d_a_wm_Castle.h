#pragma once

#include "d_wm_demo_actor.h"

class daWmCastle_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x2B8);
    VTABLE(0x060, fBase_c, 0x80982328);
    // 0x80982284 g_profile_WM_CASTLE
    // 0x808CC430 daWmCastle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CC460 */
    daWmCastle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x2B8);
};
