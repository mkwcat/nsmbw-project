#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daRotarionGhostParent_c : public dActorState_c {
    SIZE_ASSERT(0x460);
    VTABLE(0x060, fBase_c, 0x8097A9C0);
    // 0x8097A9B0 g_profile_AC_ROTATION_GHOST_PARENT
    // 0x8089FE50 daRotarionGhostParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daRotarionGhostParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x460);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808A02E0
     * executeState:    0x808A0300
     * finalizeState:   0x808A02F0
     */
    sState_Extern(0x8099EC20, daRotarionGhostParent_c, RotetionSmallWait);

    /*
     * initializeState: 0x808A0360
     * executeState:    0x808A0380
     * finalizeState:   0x808A0370
     */
    sState_Extern(0x8099EC60, daRotarionGhostParent_c, RotetionBigZoom);

    /*
     * initializeState: 0x808A0400
     * executeState:    0x808A0420
     * finalizeState:   0x808A0410
     */
    sState_Extern(0x8099ECA0, daRotarionGhostParent_c, RotetionBigWait);

    /*
     * initializeState: 0x808A0480
     * executeState:    0x808A04A0
     * finalizeState:   0x808A0490
     */
    sState_Extern(0x8099ECE0, daRotarionGhostParent_c, RotetionSmallZoom);
};
