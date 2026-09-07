#pragma once

#include "d_wm_demo_actor.h"

class daWmAntlionMng_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x1B0);
    VTABLE(0x060, fBase_c, 0x80981BE8);
    // 0x80981BD4 g_profile_WM_ANTLION_MNG
    // 0x808C8D00 daWmAntlionMng_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808C8D30 */
    daWmAntlionMng_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x1B0);
};
