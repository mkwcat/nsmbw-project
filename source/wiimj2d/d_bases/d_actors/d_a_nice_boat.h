#pragma once

#include "d_a_lift_remocon_main.h"
#include "d_mj2d_game.h"
#include "s_State.h"

class daNiceBoat_c : public daLiftRemoconMain_c {
    // Original size: 0xE18
    VTABLE(0x060, fBase_c, 0x80971794);
    // 0x809716E8 g_profile_NICE_BOAT
    // 0x8086EEA0 daNiceBoat_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daNiceBoat_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x808710C0 */
    short calcLampAngle();

    /* 0x80871440 */
    int calcPlayerOnRide();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x454, 0xE0A);

    /* 0xE0A */ u8 REMOVED(mPlayerRideStatus)[4];

    FILL(0xE0E, 0xE18);
    OFFSET_ASSERT(0xE18);

#define OFFSET_mPlayerRideStatus 0xE18
    /* 0xE18 */ u8 mPlayerRideStatus[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80871C90
     * executeState:    0x80871CB0
     * finalizeState:   0x80871CA0
     */
    sState_Extern(0x8099D0E0, daNiceBoat_c, Wait);

    /*
     * initializeState: 0x80871D10
     * executeState:    0x80871D30
     * finalizeState:   0x80871D20
     */
    sState_Extern(0x8099D120, daNiceBoat_c, Move);

    /*
     * initializeState: 0x80871D70
     * executeState:    0x80871D90
     * finalizeState:   0x80871D80
     */
    sState_Extern(0x8099D160, daNiceBoat_c, RailWait);

    /*
     * initializeState: 0x80871DF0
     * executeState:    0x80871E10
     * finalizeState:   0x80871E00
     */
    sState_Extern(0x8099D1A0, daNiceBoat_c, Rail);
};
