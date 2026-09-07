#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftLine_c : public dActorState_c {
    SIZE_ASSERT(0x680);
    VTABLE(0x060, fBase_c, 0x80967634);
    // 0x80967628 g_profile_AC_LINE_LIFT
    // 0x80839680 daLiftLine_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftLine_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x680);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80839EF0
     * executeState:    0x80839F80
     * finalizeState:   0x80839F30
     */
    sState_Extern(0x8099B210, daLiftLine_c, NoDisp);

    /*
     * initializeState: 0x80839FF0
     * executeState:    0x8083A010
     * finalizeState:   0x8083A000
     */
    sState_Extern(0x8099B250, daLiftLine_c, Wait);

    /*
     * initializeState: 0x8083A0D0
     * executeState:    0x8083A0F0
     * finalizeState:   0x8083A0E0
     */
    sState_Extern(0x8099B290, daLiftLine_c, Move);
};
