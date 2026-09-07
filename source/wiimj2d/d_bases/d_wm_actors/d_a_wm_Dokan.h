#pragma once

#include "d_wm_demo_actor.h"

class daWmDokan_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1B0);
    VTABLE(0x060, fBase_c, 0x80982A28);
    // 0x80982A1C g_profile_WM_DOKAN
    // 0x808CFA20 daWmDokan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CFA50 */
    daWmDokan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1B0);
};
