#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daManta_c : public dActorState_c {
    SIZE_ASSERT(0x968);
    VTABLE(0x060, fBase_c, 0x8096C410);
    // 0x8096C3B8 g_profile_MANTA
    // 0x8085D570 daManta_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daManta_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x968);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8085E890
     * executeState:    0x8085E9C0
     * finalizeState:   0x8085E9B0
     */
    sState_Extern(0x8099C7B0, daManta_c, Fly_Rise);

    /*
     * initializeState: 0x8085EAD0
     * executeState:    0x8085EB00
     * finalizeState:   0x8085EAF0
     */
    sState_Extern(0x8099C7F0, daManta_c, Fly_Wait);

    /*
     * initializeState: 0x8085EB70
     * executeState:    0x8085EBE0
     * finalizeState:   0x8085EBD0
     */
    sState_Extern(0x8099C830, daManta_c, Fly_Fall);

    /*
     * initializeState: 0x8085EC70
     * executeState:    0x8085EC90
     * finalizeState:   0x8085EC80
     */
    sState_Extern(0x8099C870, daManta_c, Wait);
};
