#pragma once

#include "d_wm_actor.h"

class daWmTest_c : public dWmActor_c {
    SIZE_ASSERT(0x160);
    VTABLE(0x060, fBase_c, 0x8098FEB8);
    // 0x8098FEA0 g_profile_WM_TEST
    // 0x80933420 daWmTest_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmTest_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x138, 0x160);
};
