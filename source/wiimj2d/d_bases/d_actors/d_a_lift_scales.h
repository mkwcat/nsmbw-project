#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftScales_c : public dActorState_c {
    SIZE_ASSERT(0x5C0);
    VTABLE(0x060, fBase_c, 0x80968E30);
    // 0x80968DA8 g_profile_AC_LIFT_SCALES
    // 0x808468E0 daLiftScales_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftScales_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80847870
     * executeState:    0x808478A0
     * finalizeState:   0x80847890
     */
    sState_Extern(0x8099B8E8, daLiftScales_c, NoDisp);

    /*
     * initializeState: 0x80847920
     * executeState:    0x80847960
     * finalizeState:   0x80847950
     */
    sState_Extern(0x8099B928, daLiftScales_c, HoldStop);

    /*
     * initializeState: 0x80847A70
     * executeState:    0x80847A90
     * finalizeState:   0x80847A80
     */
    sState_Extern(0x8099B968, daLiftScales_c, HoldStopMove);

    /*
     * initializeState: 0x80847B80
     * executeState:    0x80847BA0
     * finalizeState:   0x80847B90
     */
    sState_Extern(0x8099B9A8, daLiftScales_c, HoldMove);

    /*
     * initializeState: 0x80847ED0
     * executeState:    0x80847F10
     * finalizeState:   0x80847EE0
     */
    sState_Extern(0x8099B9E8, daLiftScales_c, Still);

    /*
     * initializeState: 0x80847FC0
     * executeState:    0x80847FE0
     * finalizeState:   0x80847FD0
     */
    sState_Extern(0x8099BA28, daLiftScales_c, Release);
};
