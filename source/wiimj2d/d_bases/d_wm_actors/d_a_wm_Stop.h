#pragma once

#include "d_wm_actor.h"

class daWmStop_c : public dWmActor_c {
    SIZE_ASSERT(0x160);
    VTABLE(0x060, fBase_c, 0x809857D8);
    // 0x809857B0 g_profile_WM_STOP
    // 0x808E8760 daWmStop_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808E8790 */
    daWmStop_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x138, 0x160);
};
