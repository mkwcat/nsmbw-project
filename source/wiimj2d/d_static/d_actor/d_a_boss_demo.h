#pragma once

#include "d_static/d_actor/d_actor_state.h"
#include "framework/f_base_id.h"
#include "state/s_State.h"

class daBossDemo_c : public dActorState_c {
    SIZE_ASSERT(0x3DC);
    VTABLE(0x060, fBase_c, 0x80301804);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x3D0 */ int       m0x3D0;
    /* 0x3D4 */ int       mIsBattleEndDemo;
    /* 0x3D8 */ fBaseID_e mBossId;

public:
    // Virtual State IDs
    // ^^^^^^

    /**
     * initializeState: VT+0x0E0 0x8001CF50
     * executeState:    VT+0x0E4 0x8001CF70
     * finalizeState:   VT+0x0E8 0x8001CF60
     */
    sState_ExternVirtual(0x80352970, daBossDemo_c, Ready);

    /**
     * initializeState: VT+0x0EC 0x8001D060
     * executeState:    VT+0x0F0 0x8001D080
     * finalizeState:   VT+0x0F4 0x8001D070
     */
    sState_ExternVirtual(0x803529B0, daBossDemo_c, BattleStDemo);

    /**
     * initializeState: VT+0x0F8 0x8001D090
     * executeState:    VT+0x0FC 0x8001D110
     * finalizeState:   VT+0x100 0x8001D100
     */
    sState_ExternVirtual(0x803529F0, daBossDemo_c, BattleIn);

    /**
     * initializeState: VT+0x104 0x8001D180
     * executeState:    VT+0x108 0x8001D1A0
     * finalizeState:   VT+0x10C 0x8001D190
     */
    sState_ExternVirtual(0x80352A30, daBossDemo_c, BattleEdDemo);
};
