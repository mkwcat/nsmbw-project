#pragma once

#include "d_system/d_a_lift_remocon_main.h"

class daLiftRemoconSeesaw_c : public daLiftRemoconMain_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8083F550 */
    short CalculateInitialAngle();

    /* 0x8083F4F0 */
    short CalculateAngle();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x454, 0x54A);

    /* 0x54A */ short mCurrentAngle;

    FILL(0x54A, 0x560);
};
