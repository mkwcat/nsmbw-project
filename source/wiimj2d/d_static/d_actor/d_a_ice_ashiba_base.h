#pragma once

#include "d_actor_state.h"

class daIceAshibaBase_c : public dActorState_c {
    SIZE_ASSERT(0x4E4);
    VTABLE(0x060, fBase_c, 0x80307278);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4E4);
};
