#pragma once

#include "d_actor_state.h"

class daObjMoveOnBase_c : public dActorState_c {
    SIZE_ASSERT(0x4C0);
    VTABLE(0x060, fBase_c, 0x80307C10);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x4C0);
};
