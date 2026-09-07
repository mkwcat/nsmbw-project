#pragma once

#include "d_a_fireball_base.h"
#include "s_State.h"

class daFireBall_Bros_c : public daFireBall_Base_c {
    SIZE_ASSERT(0x558);
    VTABLE(0x060, fBase_c, 0x80959A30);
    // 0x80959A10 g_profile_BROS_FIREBALL
    // 0x807E90F0 daFireBall_Bros_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFireBall_Bros_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x554, 0x558);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x807E9600
     * executeState:    VT+0xE4 0x807E9620
     * finalizeState:   VT+0xE8 0x807E9610
     */
    sState_ExternVirtual(0x80998358, daFireBall_Bros_c, Move);
};
