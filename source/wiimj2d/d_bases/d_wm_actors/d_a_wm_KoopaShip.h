#pragma once

#include "d_wm_demo_actor.h"

class daWmKoopaShip_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x4C4);
    VTABLE(0x060, fBase_c, 0x80984558);
    // 0x80984258 g_profile_WM_KOOPASHIP
    // 0x808DBCB0 daWmKoopaShip_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808DBD40 */
    daWmKoopaShip_c();

public:
    // Static Methods
    // ^^^^^^

    /* 0x808DE1A0 */
    static void setup();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x4C4);
};
