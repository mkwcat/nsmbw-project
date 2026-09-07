#pragma once

#include "d_actor.h"

class daBlockCoin_c : public dActor_c {
    SIZE_ASSERT(0x398);
    VTABLE(0x060, fBase_c, 0x80952D3C);
    // 0x80952D30 g_profile_AC_BLOCK_COIN
    // 0x807BFDE0 daBlockCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daBlockCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x392, 0x398);
};
