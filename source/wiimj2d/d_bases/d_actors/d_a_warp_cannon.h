#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daWarpCannon_c : public dActorState_c {
    SIZE_ASSERT(0x6A8);
    VTABLE(0x060, fBase_c, 0x8097FA60);
    // 0x8097F9C0 g_profile_WARP_CANNON
    // 0x808BC550 daWarpCannon_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daWarpCannon_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x6A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808BD0E0
     * executeState:    0x808BD100
     * finalizeState:   0x808BD0F0
     */
    sState_Extern(0x8099F9B8, daWarpCannon_c, Wait);

    /*
     * initializeState: 0x808BD1A0
     * executeState:    0x808BD1C0
     * finalizeState:   0x808BD1B0
     */
    sState_Extern(0x8099F9F8, daWarpCannon_c, CanstWait);

    /*
     * initializeState: 0x808BD1F0
     * executeState:    0x808BD250
     * finalizeState:   0x808BD240
     */
    sState_Extern(0x8099FA38, daWarpCannon_c, CannonUp);

    /*
     * initializeState: 0x808BD2A0
     * executeState:    0x808BD310
     * finalizeState:   0x808BD300
     */
    sState_Extern(0x8099FA78, daWarpCannon_c, BodyRollWait);

    /*
     * initializeState: 0x808BD380
     * executeState:    0x808BD3E0
     * finalizeState:   0x808BD3D0
     */
    sState_Extern(0x8099FAB8, daWarpCannon_c, BodyRoll);

    /*
     * initializeState: 0x808BD470
     * executeState:    0x808BD4E0
     * finalizeState:   0x808BD4D0
     */
    sState_Extern(0x8099FAF8, daWarpCannon_c, GunUpWait);

    /*
     * initializeState: 0x808BD550
     * executeState:    0x808BD5B0
     * finalizeState:   0x808BD5A0
     */
    sState_Extern(0x8099FB38, daWarpCannon_c, GunUp);

    /*
     * initializeState: 0x808BD610
     * executeState:    0x808BD680
     * finalizeState:   0x808BD670
     */
    sState_Extern(0x8099FB78, daWarpCannon_c, ShootWait);

    /*
     * initializeState: 0x808BD6F0
     * executeState:    0x808BD710
     * finalizeState:   0x808BD700
     */
    sState_Extern(0x8099FBB8, daWarpCannon_c, Scroll);

    /*
     * initializeState: 0x808BD800
     * executeState:    0x808BD890
     * finalizeState:   0x808BD880
     */
    sState_Extern(0x8099FBF8, daWarpCannon_c, Shoot);
};
