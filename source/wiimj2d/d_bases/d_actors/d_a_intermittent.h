#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daIntermittent_c : public dActorState_c {
    SIZE_ASSERT(0x1678);
    VTABLE(0x0060, fBase_c, 0x8095DE60);
    // 0x8095DDC0 g_profile_INTERMITTENT
    // 0x80801CC0 daIntermittent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIntermittent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x1678);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80802EB0
     * executeState:    0x80802FE0
     * finalizeState:   0x80802FD0
     */
    sState_Extern(0x80999120, daIntermittent_c, Appear);

    /*
     * initializeState: 0x80802FF0
     * executeState:    0x808030A0
     * finalizeState:   0x80803010
     */
    sState_Extern(0x80999160, daIntermittent_c, Wait);

    /*
     * initializeState: 0x808031A0
     * executeState:    0x808032A0
     * finalizeState:   0x80803290
     */
    sState_Extern(0x809991A0, daIntermittent_c, SplushBegin);

    /*
     * initializeState: 0x80803440
     * executeState:    0x80803480
     * finalizeState:   0x80803470
     */
    sState_Extern(0x809991E0, daIntermittent_c, Splush);

    /*
     * initializeState: 0x808036D0
     * executeState:    0x80803770
     * finalizeState:   0x80803760
     */
    sState_Extern(0x80999220, daIntermittent_c, SplushEnd);
};
