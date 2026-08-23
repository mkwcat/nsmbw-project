#pragma once

#include "d_static/d_actor/d_actor_state.h"
#include "d_static/d_rc.h"

class daLiftFall_c : public dActorState_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x808377B0 */
    bool checkRideStart() const;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x508);

    /* 0x508 */ dRideRoll_c mRc;
};
