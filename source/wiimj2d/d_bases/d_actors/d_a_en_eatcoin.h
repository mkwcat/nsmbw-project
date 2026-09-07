#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnEatCoin_c : public dEn_c {
    SIZE_ASSERT(0x5B8);
    VTABLE(0x060, fBase_c, 0x803232F0);
    // 0x80323288 g_profile_EN_EATCOIN
    // 0x8010F9A0 daEnEatCoin_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnEatCoin_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5B8);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x8010FC60
     * executeState:    VT+0x1E8 0x8010FC80
     * finalizeState:   VT+0x1EC 0x8010FC70
     */
    sState_ExternVirtual(0x803753C4, daEnEatCoin_c, EatOut);
};
