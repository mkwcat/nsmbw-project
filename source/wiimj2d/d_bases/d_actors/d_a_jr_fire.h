#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daJrFire_c : public dActorState_c {
    SIZE_ASSERT(0x738);
    VTABLE(0x060, fBase_c, 0x809605D8);
    // 0x80960568 g_profile_JR_FIRE
    // 0x80813760 daJrFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daJrFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x738);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80814B20
     * executeState:    0x80814C30
     * finalizeState:   0x80814C20
     */
    sState_Extern(0x809999C8, daJrFire_c, BurnFloor);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xEC 0x80814DC0
     * executeState:    VT+0xF0 0x80814E50
     * finalizeState:   VT+0xF4 0x80814E40
     */
    sState_ExternVirtual(0x80999A04, daJrFire_c, Move);
};
