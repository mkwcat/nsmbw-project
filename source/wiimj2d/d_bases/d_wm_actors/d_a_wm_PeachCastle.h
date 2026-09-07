#pragma once

#include "d_wm_demo_actor.h"

class daWmPeachCastle_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x2BC);
    VTABLE(0x060, fBase_c, 0x80984D40);
    // 0x80984BF4 g_profile_WM_PEACH_CASTLE
    // 0x808E4440 daWmPeachCastle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E4470 */
    daWmPeachCastle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x2BC);
};
