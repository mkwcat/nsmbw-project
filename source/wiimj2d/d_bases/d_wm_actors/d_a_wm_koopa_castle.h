#pragma once

#include "d_wm_demo_actor.h"

class daWmKoopaCastle_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x288);
    VTABLE(0x060, fBase_c, 0x809885F0);
    // 0x80988574 g_profile_WM_KOOPA_CASTLE
    // 0x808FE840 daWmKoopaCastle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808FE870 */
    daWmKoopaCastle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x288);
};
