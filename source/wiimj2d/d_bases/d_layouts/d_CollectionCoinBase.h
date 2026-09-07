#pragma once

#include "d_base.h"

class dCollectionCoinBase_c : public dBase_c {
    SIZE_ASSERT(0x274);
    VTABLE(0x060, fBase_c, 0x8093FF60);
    // 0x8093FE28 g_profile_COLLECTION_COIN_BASE
    // 0x80776150 dCollectionCoinBase_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80776180 */
    dCollectionCoinBase_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x274);
};
