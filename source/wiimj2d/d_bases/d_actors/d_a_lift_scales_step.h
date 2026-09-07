#pragma once

#include "d_actor.h"
#include "s_State.h"

class daLiftScalesStep_c : public dActor_c {
    SIZE_ASSERT(0x608);
    VTABLE(0x060, fBase_c, 0x809690FC);
    // 0x809690F0 g_profile_AC_LIFT_SCALES_STEP
    // 0x80848730 daLiftScalesStep_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80848760 */
    daLiftScalesStep_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x608);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808490E0
     * executeState:    0x80849100
     * finalizeState:   0x808490F0
     */
    sState_Extern(0x8099BA68, daLiftScalesStep_c, Hold);

    /*
     * initializeState: 0x80849110
     * executeState:    0x80849160
     * finalizeState:   0x80849150
     */
    sState_Extern(0x8099BAA8, daLiftScalesStep_c, Release);

    /*
     * initializeState: 0x808491A0
     * executeState:    0x808491F0
     * finalizeState:   0x808491E0
     */
    sState_Extern(0x8099BAE8, daLiftScalesStep_c, NoDisp);

    /*
     * initializeState: 0x80849200
     * executeState:    0x80849250
     * finalizeState:   0x80849240
     */
    sState_Extern(0x8099BB28, daLiftScalesStep_c, Disp);
};
