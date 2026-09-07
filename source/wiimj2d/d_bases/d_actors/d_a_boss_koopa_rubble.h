#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daBossKoopaRubble_c : public dActorState_c {
    SIZE_ASSERT(0x530);
    VTABLE(0x060, fBase_c, 0x80955428);
    // 0x80955350 g_profile_AC_BOSS_KOOPA_RUBBLE
    // 0x807D2AC0 daBossKoopaRubble_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBossKoopaRubble_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x530);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0E0 0x807D2EF0
     * executeState:    VT+0x0E4 0x807D2F00
     * finalizeState:   VT+0x0E8 0x807D2F10
     */
    sState_ExternVirtual(0x80996F34, daBossKoopaRubble_c, Wait);

    /*
     * initializeState: VT+0x0EC 0x807D2F20
     * executeState:    VT+0x0F0 0x807D30F0
     * finalizeState:   VT+0x0F4 0x807D3210
     */
    sState_ExternVirtual(0x80996F74, daBossKoopaRubble_c, Jump);

    /*
     * initializeState: VT+0x0F8 0x807D3220
     * executeState:    VT+0x0FC 0x807D33B0
     * finalizeState:   VT+0x100 0x807D35A0
     */
    sState_ExternVirtual(0x80996FB4, daBossKoopaRubble_c, Fall);

    /*
     * initializeState: VT+0x104 0x807D35B0
     * executeState:    VT+0x108 0x807D3810
     * finalizeState:   VT+0x10C 0x807D3820
     */
    sState_ExternVirtual(0x80996FF4, daBossKoopaRubble_c, Crash);
};
