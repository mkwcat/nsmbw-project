#pragma once

#include "d_actor.h"
#include "s_State.h"

class daLudwigFire_c : public dActor_c {
    SIZE_ASSERT(0x3C0);
    VTABLE(0x060, fBase_c, 0x8096BE60);
    // 0x8096BE54 g_profile_CASTLE_LUDWIG_BLITZ_MGR
    // 0x8085BDC0 daLudwigFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8085C240 */
    daLudwigFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x3C0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xEC 0x8085BE00
     * executeState:    VT+0xF0 0x80064390
     * finalizeState:   VT+0xF4 0x800643E0
     */
    sState_ExternVirtual(0x8099C6E4, daLudwigFire_c, Move);
};
