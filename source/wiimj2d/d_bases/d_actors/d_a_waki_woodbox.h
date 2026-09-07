#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWakiWoodBox_c : public dActorState_c {
    SIZE_ASSERT(0x520);
    VTABLE(0x060, fBase_c, 0x8097F5D8);
    // 0x8097F598 g_profile_AC_WAKI_WOODBOX
    // 0x808BBC70 daWakiWoodBox_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWakiWoodBox_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x520);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BC070
     * executeState:    0x808BC090
     * finalizeState:   0x808BC080
     */
    sState_Extern(0x8099F958, daWakiWoodBox_c, Move);
};
