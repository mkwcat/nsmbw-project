#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRemoLineLift_c : public dActorState_c {
    SIZE_ASSERT(0x5F8);
    VTABLE(0x060, fBase_c, 0x80978C48);
    // 0x80978BE0 g_profile_REMO_LINE_LIFT
    // 0x80896270 daRemoLineLift_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRemoLineLift_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80896A50
     * executeState:    0x80896A70
     * finalizeState:   0x80896A60
     */
    sState_Extern(0x8099E658, daRemoLineLift_c, Fall);

    /*
     * initializeState: 0x80896B10
     * executeState:    0x80896C40
     * finalizeState:   0x80896C30
     */
    sState_Extern(0x8099E698, daRemoLineLift_c, ChangePlayer);

    /*
     * initializeState: 0x80896CB0
     * executeState:    0x80896CD0
     * finalizeState:   0x80896CC0
     */
    sState_Extern(0x8099E6D8, daRemoLineLift_c, Wait);

    /*
     * initializeState: 0x80896DF0
     * executeState:    0x80896EA0
     * finalizeState:   0x80896E90
     */
    sState_Extern(0x8099E718, daRemoLineLift_c, Move);
};
