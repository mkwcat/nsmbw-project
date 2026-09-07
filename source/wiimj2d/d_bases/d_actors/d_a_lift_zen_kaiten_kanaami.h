#pragma once

#include "d_actor_state.h"

class daLiftZenKaiheiKanaami_c : public dActorState_c {
    SIZE_ASSERT(0x500);
    VTABLE(0x060, fBase_c, 0x8096A758);
    // 0x8096A710 g_profile_LIFT_ZEN_KAITEN_KANAAMI
    // 0x80851EC0 daLiftZenKaiheiKanaami_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daLiftZenKaiheiKanaami_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x500);
};
