#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daTeamPukuPuku_c : public dActorState_c {
    SIZE_ASSERT(0x3F8);
    VTABLE(0x060, fBase_c, 0x8097D460);
    // 0x8097D450 g_profile_AC_TEAM_PUKUPUKU
    // 0x808AF830 daTeamPukuPuku_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daTeamPukuPuku_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x3F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808AFC60
     * executeState:    0x808AFC80
     * finalizeState:   0x808AFC70
     */
    sState_Extern(0x8099F3C8, daTeamPukuPuku_c, DelWait);
};
