#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKoopaFire_c : public dActorState_c {
    SIZE_ASSERT(0x718);
    VTABLE(0x060, fBase_c, 0x80963D48);
    // 0x80963C20 g_profile_KOOPA_FIRE
    // 0x80828020 daKoopaFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKoopaFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x718);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0E0 0x80828A80
     * executeState:    VT+0x0E4 0x80828AA0
     * finalizeState:   VT+0x0E8 0x80828AE0
     */
    sState_ExternVirtual(0x8099A67C, daKoopaFire_c, Wait);

    /*
     * initializeState: VT+0x0EC 0x80828AF0
     * executeState:    VT+0x0F0 0x80828C40
     * finalizeState:   VT+0x0F4 0x80829190
     */
    sState_ExternVirtual(0x8099A6BC, daKoopaFire_c, Move);

    /*
     * initializeState: VT+0x168 0x808291A0
     * executeState:    VT+0x16C 0x80829210
     * finalizeState:   VT+0x170 0x80829350
     */
    sState_ExternVirtual(0x8099A6FC, daKoopaFire_c, Chase);

    /*
     * initializeState: VT+0x104 0x80829360
     * executeState:    VT+0x108 0x808293E0
     * finalizeState:   VT+0x10C 0x808293F0
     */
    sState_ExternVirtual(0x8099A73C, daKoopaFire_c, Hit);
};
