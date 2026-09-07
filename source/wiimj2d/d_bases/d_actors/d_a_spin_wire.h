#pragma once

#include "d_actor_state.h"

class daSpinWire_c : public dActorState_c {
    SIZE_ASSERT(0x410);
    VTABLE(0x060, fBase_c, 0x8097C1F0);
    // 0x8097C1A8 g_profile_SPIN_WIRE
    // 0x808A9920 daSpinWire_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daSpinWire_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x410);
};
