#pragma once

#include "d_wm_demo_actor.h"

class daWmHanachan_c : public dWmDemoActor_c {
    SIZE_ASSERT(0xF00);
    VTABLE(0x060, fBase_c, 0x809830C8);
    // 0x80982FD4 g_profile_WM_HANACHAN
    // 0x808D1BA0 daWmHanachan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808D1BD0 */
    daWmHanachan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0xF00);
};
