#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daKameckMagic_c : public dActorState_c {
    SIZE_ASSERT(0x6E0);
    VTABLE(0x060, fBase_c, 0x80961CE8);
    // 0x80961C00 g_profile_KAMECK_MAGIC
    // 0x8081B7B0 daKameckMagic_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daKameckMagic_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6E0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0xE0 0x8081BF10
     * executeState:    VT+0xE4 0x8081BF20
     * finalizeState:   VT+0xE8 0x8081BFD0
     */
    sState_ExternVirtual(0x80999CC4, daKameckMagic_c, Wait);

    /*
     * initializeState: VT+0xEC 0x8081BFE0
     * executeState:    VT+0xF0 0x8081C050
     * finalizeState:   VT+0xF4 0x8081C190
     */
    sState_ExternVirtual(0x80999D04, daKameckMagic_c, Move);
};
