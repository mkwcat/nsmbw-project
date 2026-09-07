#pragma once

#include "d_enemy.h"

class daEnGhostJugem_c : public dEn_c {
    SIZE_ASSERT(0x528);
    VTABLE(0x060, fBase_c, 0x80AEBDB0);
    // 0x80AEBDA0 g_profile_EN_GHOST_JUGEM
    // 0x80A09620 daEnGhostJugem_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnGhostJugem_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x528);
};
