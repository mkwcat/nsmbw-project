#pragma once

#include "d_a_fireball_base.h"
#include "s_State.h"

class daFireBall_Pakkun_c : public daFireBall_Base_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x80959C50);
    // 0x80959C30 g_profile_PAKKUN_FIREBALL
    // 0x807E9D10 daFireBall_Pakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFireBall_Pakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x554, 0x560);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x807EA4A0
     * executeState:    VT+0xE4 0x807EA4C0
     * finalizeState:   VT+0xE8 0x807EA4B0
     */
    sState_ExternVirtual(0x80998424, daFireBall_Pakkun_c, Move);
};
