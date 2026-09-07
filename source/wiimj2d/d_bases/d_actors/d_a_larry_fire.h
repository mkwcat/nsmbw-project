#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daLarryFire_c : public dActorState_c {
    SIZE_ASSERT(0x6D8);
    VTABLE(0x060, fBase_c, 0x80965408);
    // 0x80965110 g_profile_LARRY_FIRE
    // 0x8082ED60 daLarryFire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLarryFire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6D8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x0E0 0x8082FAD0
     * executeState:    VT+0x0E4 0x8082FB00
     * finalizeState:   VT+0x0E8 0x8082FAF0
     */
    sState_ExternVirtual(0x8099AA04, daLarryFire_c, Wait);

    /*
     * initializeState: VT+0x0EC 0x8082FBB0
     * executeState:    VT+0x0F0 0x8082FC40
     * finalizeState:   VT+0x0F4 0x8082FC30
     */
    sState_ExternVirtual(0x8099AA44, daLarryFire_c, Move);

    /*
     * initializeState: VT+0x0F8 0x8082FD00
     * executeState:    VT+0x0FC 0x8082FDA0
     * finalizeState:   VT+0x100 0x8082FD90
     */
    sState_ExternVirtual(0x8099AA84, daLarryFire_c, MagniMove);

    /*
     * initializeState: VT+0x104 0x8082FEF0
     * executeState:    VT+0x108 0x8082FF60
     * finalizeState:   VT+0x10C 0x8082FF50
     */
    sState_ExternVirtual(0x8099AAC4, daLarryFire_c, Hit);
};
