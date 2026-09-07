#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daYoganIntermittent_c : public dActorState_c {
    SIZE_ASSERT(0xA90);
    VTABLE(0x060, fBase_c, 0x80989950);
    // 0x80989900 g_profile_YOGAN_INTERMITTENT
    // 0x8090F380 daYoganIntermittent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daYoganIntermittent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xA90);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8090FBB0
     * executeState:    0x8090FC20
     * finalizeState:   0x8090FC10
     */
    sState_Extern(0x809A0E20, daYoganIntermittent_c, Appear);

    /*
     * initializeState: 0x8090FCB0
     * executeState:    0x8090FD20
     * finalizeState:   0x8090FD10
     */
    sState_Extern(0x809A0E60, daYoganIntermittent_c, Wait);

    /*
     * initializeState: 0x8090FDB0
     * executeState:    0x8090FE50
     * finalizeState:   0x8090FE40
     */
    sState_Extern(0x809A0EA0, daYoganIntermittent_c, SplushBegin);

    /*
     * initializeState: 0x8090FED0
     * executeState:    0x8090FF30
     * finalizeState:   0x8090FF20
     */
    sState_Extern(0x809A0EE0, daYoganIntermittent_c, SplushReady);

    /*
     * initializeState: 0x809100F0
     * executeState:    0x80910140
     * finalizeState:   0x80910130
     */
    sState_Extern(0x809A0F20, daYoganIntermittent_c, SplushMid);

    /*
     * initializeState: 0x809102D0
     * executeState:    0x80910320
     * finalizeState:   0x80910310
     */
    sState_Extern(0x809A0F60, daYoganIntermittent_c, Splush);

    /*
     * initializeState: 0x80910520
     * executeState:    0x80910560
     * finalizeState:   0x80910550
     */
    sState_Extern(0x809A0FA0, daYoganIntermittent_c, SplushEnd);
};
