#pragma once

#include "d_actor.h"
#include "s_State.h"

class daBullet_c : public dActor_c {
    SIZE_ASSERT(0x400);
    VTABLE(0x060, fBase_c, 0x80301AD0);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x400);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0E0 0x8001E870
     * executeState:    VT+0x0E4 0x8001E890
     * finalizeState:   VT+0x0E8 0x8001E880
     */
    sState_ExternVirtual(0x80352A74, daBullet_c, EatIn);

    /*
     * initializeState: VT+0x0EC 0x8001E8C0
     * executeState:    VT+0x0F0 0x8001E8E0
     * finalizeState:   VT+0x0F4 0x8001E8D0
     */
    sState_ExternVirtual(0x80352AB4, daBullet_c, EatNow);

    /*
     * initializeState: VT+0x0F8 0x8001E8F0
     * executeState:    VT+0x0FC 0x8001E910
     * finalizeState:   VT+0x100 0x8001E900
     */
    sState_ExternVirtual(0x80352AF4, daBullet_c, SpiteMove);

    /*
     * initializeState: VT+0x104 0x8001E9A0
     * executeState:    VT+0x108 0x8001E9C0
     * finalizeState:   VT+0x10C 0x8001E9B0
     */
    sState_ExternVirtual(0x80352B34, daBullet_c, Reflect);

    /*
     * initializeState: VT+0x110 0x8001EA00
     * executeState:    VT+0x114 0x8001EA20
     * finalizeState:   VT+0x118 0x8001EA10
     */
    sState_ExternVirtual(0x80352B74, daBullet_c, HitReflect);

    /*
     * initializeState: VT+0x11C 0x8001EAB0
     * executeState:    VT+0x120 0x8001EAD0
     * finalizeState:   VT+0x124 0x8001EAC0
     */
    sState_ExternVirtual(0x80352BB4, daBullet_c, HitStar);

    /*
     * initializeState: VT+0x128 0x8001EB20
     * executeState:    VT+0x12C 0x8001EB40
     * finalizeState:   VT+0x130 0x8001EB30
     */
    sState_ExternVirtual(0x80352BF4, daBullet_c, HitShell);

    /*
     * initializeState: VT+0x134 0x8001EB90
     * executeState:    VT+0x138 0x8001EBB0
     * finalizeState:   VT+0x13C 0x8001EBA0
     */
    sState_ExternVirtual(0x80352C34, daBullet_c, HitYoshiBullet);
};
