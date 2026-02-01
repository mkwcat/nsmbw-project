#pragma once

#include "d_system/d_actor_state.h"
#include "d_system/d_rc.h"

class daLiftRideMove_c : public dActorState_c {
public:
    /* 0x80845D60 */
    bool isAllPlayerOnLift();

    FILL(0x3D0, 0x508);
    /* 0x508 */ dRideRoll_c mRideRoll;
};