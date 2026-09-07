#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daIceLump_c : public dActorState_c {
    SIZE_ASSERT(0x5A0);
    VTABLE(0x060, fBase_c, 0x8095DC08);
    // 0x8095DBC0 g_profile_ICELUMP
    // 0x80800D30 daIceLump_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daIceLump_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5A0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80801790
     * executeState:    0x80801820
     * finalizeState:   0x80801810
     */
    sState_Extern(0x80999050, daIceLump_c, Wait);

    /*
     * initializeState: 0x80801870
     * executeState:    0x808018A0
     * finalizeState:   0x80801890
     */
    sState_Extern(0x80999090, daIceLump_c, Crack);
};
