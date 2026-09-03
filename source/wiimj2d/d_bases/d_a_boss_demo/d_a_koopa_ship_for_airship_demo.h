#pragma once

#include "d_actor_state.h"
#include "state/s_State.h"

class daKoopaShipForAirshipDemo_c : public dActorMultiState_c {
    SIZE_ASSERT(0x630);
    VTABLE(0x060, fBase_c, 0x8096479C);
    // 0x80964768 g_profile_KOOPA_SHIP_FOR_AIRSHIP_DEMO
    // 0x8082C1B0 daKoopaShipForAirshipDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8082C1E0 */
    daKoopaShipForAirshipDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x414, 0x630);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8082C940
     * executeState:    0x8082C9C0
     * finalizeState:   0x8082C9B0
     */
    sState_Extern(0x8099A948, daKoopaShipForAirshipDemo_c, DemoWait);
};
