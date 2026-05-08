#pragma once

#include "d_system/d_a_lift_remocon_main.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_actor.h"

class daNiceBoat_c : public daLiftRemoconMain_c {
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
};
