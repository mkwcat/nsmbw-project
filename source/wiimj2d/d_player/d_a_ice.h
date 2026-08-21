#pragma once

#include "d_profile/d_profile.h"
#include "d_static/d_actor/d_actor.h"

class daIce_c : public dActor_c, public dProf::Info<daIce_c, dProf::ICE_ACTOR>
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8011EFC0 */
    bool checkPlAttach_Head(int*);
};
