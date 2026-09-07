#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daSlideBlock_c : public dActorState_c {
    SIZE_ASSERT(0xDE0);
    VTABLE(0x060, fBase_c, 0x8097B608);
    // 0x8097B5E0 g_profile_SLIDE_BLOCK
    // 0x808A51F0 daSlideBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daSlideBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0xDE0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A6530
     * executeState:    0x808A6580
     * finalizeState:   0x808A6570
     */
    sState_Extern(0x8099EE68, daSlideBlock_c, Wait);

    /*
     * initializeState: 0x808A6670
     * executeState:    0x808A6750
     * finalizeState:   0x808A6700
     */
    sState_Extern(0x8099EEA8, daSlideBlock_c, Carry);

    /*
     * initializeState: 0x808A6980
     * executeState:    0x808A6B30
     * finalizeState:   0x808A6AE0
     */
    sState_Extern(0x8099EEE8, daSlideBlock_c, Throw);

    /*
     * initializeState: 0x808A6C30
     * executeState:    0x808A6CD0
     * finalizeState:   0x808A6CC0
     */
    sState_Extern(0x8099EF28, daSlideBlock_c, Break);

    /*
     * initializeState: 0x808A6D20
     * executeState:    0x808A6D70
     * finalizeState:   0x808A6D60
     */
    sState_Extern(0x8099EF68, daSlideBlock_c, Drop);

    /*
     * initializeState: 0x808A6E10
     * executeState:    0x808A6E60
     * finalizeState:   0x808A6E50
     */
    sState_Extern(0x8099EFA8, daSlideBlock_c, Drop2);

    /*
     * initializeState: 0x808A6F00
     * executeState:    0x808A6FD0
     * finalizeState:   0x808A6FC0
     */
    sState_Extern(0x8099EFE8, daSlideBlock_c, Melt);
};
