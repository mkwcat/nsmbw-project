#pragma once

#include "d_wm_actor.h"

class daWmTest2_c : public dWmActor_c {
    SIZE_ASSERT(0x160);
    VTABLE(0x060, fBase_c, 0x8098FEB8);
    // 0x8098FEAC g_profile_WM_TEST2
    // 0x80933480 daWmTest2_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWmTest2_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x138, 0x160);
};
