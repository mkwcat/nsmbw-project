#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daFloorDokanEight_c : public dActorState_c {
    SIZE_ASSERT(0x3758);
    VTABLE(0x0060, fBase_c, 0x8095A358);
    // 0x8095A1B8 g_profile_AC_FLOOR_DOKAN_EIGHT
    // 0x807ECB50 daFloorDokanEight_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daFloorDokanEight_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x03D0, 0x3758);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807EE630
     * executeState:    0x807EE650
     * finalizeState:   0x807EE640
     */
    sState_Extern(0x80998628, daFloorDokanEight_c, Move);
};
