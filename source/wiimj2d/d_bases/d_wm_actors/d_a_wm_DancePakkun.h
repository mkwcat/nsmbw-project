#pragma once

#include "d_wm_demo_actor.h"

class daWmDancePakkun_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x2E0);
    VTABLE(0x060, fBase_c, 0x809828C8);
    // 0x80982844 g_profile_WM_DANCE_PAKKUN
    // 0x808CF0B0 daWmDancePakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CF0E0 */
    daWmDancePakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x2E0);
};
