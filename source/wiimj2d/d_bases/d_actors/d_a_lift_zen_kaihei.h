#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftZenKaihei_c : public dActorState_c {
    SIZE_ASSERT(0x590);
    VTABLE(0x060, fBase_c, 0x8096A898);
    // 0x8096A860 g_profile_LIFT_ZEN_KAIHEI
    // 0x80852230 daLiftZenKaihei_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftZenKaihei_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x590);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80852CB0
     * executeState:    0x80852CD0
     * finalizeState:   0x80852CC0
     */
    sState_Extern(0x8099C0D0, daLiftZenKaihei_c, Still);

    /*
     * initializeState: 0x80852CE0
     * executeState:    0x80852D00
     * finalizeState:   0x80852CF0
     */
    sState_Extern(0x8099C110, daLiftZenKaihei_c, MoveNormal);
};
