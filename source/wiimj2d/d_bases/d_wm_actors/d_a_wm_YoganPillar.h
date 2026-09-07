#pragma once

#include "d_wm_demo_actor.h"
#include "s_State.h"

class daWmYoganPillar_c : public dWmDemoActor_c {
    SIZE_ASSERT(0x518);
    VTABLE(0x060, fBase_c, 0x80986550);
    // 0x809864DC g_profile_WM_YOGANPILLAR
    // 0x808F3B90 daWmYoganPillar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808F3BC0 */
    daWmYoganPillar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x184, 0x518);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808F4920
     * executeState:    0x808F4950
     * finalizeState:   0x808F49A0
     */
    sState_Extern(0x809A0B90, daWmYoganPillar_c, InitializeWait);

    /*
     * initializeState: 0x808F4490
     * executeState:    0x808F4520
     * finalizeState:   0x808F4910
     */
    sState_Extern(0x809A0BD0, daWmYoganPillar_c, Wait);
};
