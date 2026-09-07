#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLiftSlideKinoko_c : public dActorState_c {
    SIZE_ASSERT(0x728);
    VTABLE(0x060, fBase_c, 0x80969690);
    // 0x80969620 g_profile_AC_LIFT_SLIDE_KINOKO
    // 0x8084A4C0 daLiftSlideKinoko_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftSlideKinoko_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x728);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8084B5A0
     * executeState:    0x8084B5D0
     * finalizeState:   0x8084B5B0
     */
    sState_Extern(0x8099BBE8, daLiftSlideKinoko_c, StretchMove);

    /*
     * initializeState: 0x8084B6A0
     * executeState:    0x8084B6D0
     * finalizeState:   0x8084B6B0
     */
    sState_Extern(0x8099BC28, daLiftSlideKinoko_c, StretchWait);

    /*
     * initializeState: 0x8084B700
     * executeState:    0x8084B730
     * finalizeState:   0x8084B710
     */
    sState_Extern(0x8099BC68, daLiftSlideKinoko_c, ShrinkReady);

    /*
     * initializeState: 0x8084B7C0
     * executeState:    0x8084B7E0
     * finalizeState:   0x8084B7D0
     */
    sState_Extern(0x8099BCA8, daLiftSlideKinoko_c, ShrinkReadyWait);

    /*
     * initializeState: 0x8084B810
     * executeState:    0x8084B840
     * finalizeState:   0x8084B820
     */
    sState_Extern(0x8099BCE8, daLiftSlideKinoko_c, ShrinkMove);

    /*
     * initializeState: 0x8084B910
     * executeState:    0x8084B940
     * finalizeState:   0x8084B920
     */
    sState_Extern(0x8099BD28, daLiftSlideKinoko_c, ShrinkWait);

    /*
     * initializeState: 0x8084B970
     * executeState:    0x8084B9A0
     * finalizeState:   0x8084B980
     */
    sState_Extern(0x8099BD68, daLiftSlideKinoko_c, StretchReady);

    /*
     * initializeState: 0x8084BA30
     * executeState:    0x8084BA50
     * finalizeState:   0x8084BA40
     */
    sState_Extern(0x8099BDA8, daLiftSlideKinoko_c, StretchReadyWait);
};
