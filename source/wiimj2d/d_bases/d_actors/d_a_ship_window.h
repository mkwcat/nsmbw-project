#pragma once

#include "d_actor_state.h"

class daShipWindow_c : public dActorState_c {
    SIZE_ASSERT(0x3D0);
    VTABLE(0x060, fBase_c, 0x8097B0E0);
    // 0x8097B0D0 g_profile_SHIP_WINDOW
    // 0x808A2940 daShipWindow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daShipWindow_c();
};
