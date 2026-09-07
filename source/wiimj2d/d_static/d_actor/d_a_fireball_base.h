#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFireBall_Base_c : public dActorState_c {
    SIZE_ASSERT(0x554);
    VTABLE(0x60, fBase_c, 0x80306D20);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x554);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0E0 0x800412B0
     * executeState:    VT+0x0E4 0x800412D0
     * finalizeState:   VT+0x0E8 0x800412C0
     */
    sState_ExternVirtual(0x8035420C, daFireBall_Base_c, Move);

    /*
     * initializeState: VT+0x0EC 0x80041360
     * executeState:    VT+0x0F0 0x800413B0
     * finalizeState:   VT+0x0F4 0x800413A0
     */
    sState_ExternVirtual(0x8035424C, daFireBall_Base_c, Kill);

    /*
     * initializeState: VT+0x0F8 0x800412E0
     * executeState:    VT+0x0FC 0x80041300
     * finalizeState:   VT+0x100 0x800412F0
     */
    sState_ExternVirtual(0x8035428C, daFireBall_Base_c, EatIn);

    /*
     * initializeState: VT+0x104 0x80041330
     * executeState:    VT+0x108 0x80041350
     * finalizeState:   VT+0x10C 0x80041340
     */
    sState_ExternVirtual(0x803542CC, daFireBall_Base_c, EatNow);
};
