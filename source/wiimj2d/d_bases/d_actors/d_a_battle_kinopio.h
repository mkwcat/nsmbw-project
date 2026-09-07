#pragma once

#include "d_actor.h"

class daBattleKinopio_c : public dActor_c {
    SIZE_ASSERT(0x4A0);
    VTABLE(0x060, fBase_c, 0x809518EC);
    // 0x80951878 g_profile_AC_BATTLE_KINOPIO
    // 0x807B9A20 daBattleKinopio_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBattleKinopio_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x4A0);
};
