#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftZenShiroYogan_c : public dActorState_c {
    SIZE_ASSERT(0x560);
    VTABLE(0x060, fBase_c, 0x8096AE50);
    // 0x8096AE08 g_profile_LIFT_ZEN_SHIRO_YOGAN
    // 0x80854290 daLiftZenShiroYogan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftZenShiroYogan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x560);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80854A80
     * executeState:    0x80854AA0
     * finalizeState:   0x80854A90
     */
    sState_Extern(0x8099C228, daLiftZenShiroYogan_c, Still);

    /*
     * initializeState: 0x80854AB0
     * executeState:    0x80854AD0
     * finalizeState:   0x80854AC0
     */
    sState_Extern(0x8099C268, daLiftZenShiroYogan_c, MoveNormal);
};
