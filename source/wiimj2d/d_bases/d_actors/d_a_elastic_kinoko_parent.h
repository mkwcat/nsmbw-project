#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daElasticKinokoParent_c : public dActorState_c {
    SIZE_ASSERT(0x3E0);
    VTABLE(0x060, fBase_c, 0x80959258);
    // 0x80959248 g_profile_ELASTIC_KINOKO_PARENT
    // 0x807E70F0 daElasticKinokoParent_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daElasticKinokoParent_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807E7200
     * executeState:    0x807E7230
     * finalizeState:   0x807E7220
     */
    sState_Extern(0x80998118, daElasticKinokoParent_c, Move);

    /*
     * initializeState: 0x807E7280
     * executeState:    0x807E72B0
     * finalizeState:   0x807E72A0
     */
    sState_Extern(0x80998158, daElasticKinokoParent_c, Wait);
};
