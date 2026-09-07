#pragma once

#include "d_wm_demo_actor.h"

class daWmCourse_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x254);
    VTABLE(0x060, fBase_c, 0x80982720);
    // 0x809826B4 g_profile_WM_COURSE
    // 0x808CDC10 daWmCourse_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808CDC40 */
    daWmCourse_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x254);
};
