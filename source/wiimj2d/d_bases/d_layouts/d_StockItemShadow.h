#pragma once

#include "d_base.h"
#include "d_lytbase.h"

class dStockItemShadow_c : public dBase_c {
    SIZE_ASSERT(0x280);
    VTABLE(0x060, fBase_c, 0x809503D8);
    // 0x809501B0 g_profile_STOCK_ITEM_SHADOW
    // 0x807B2030 dStockItemShadow_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x807B2060 */
    dStockItemShadow_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x260);

    /* 0x260 */ u8 m0x260;
    /* 0x261 */ u8 m0x261;

    FILL(0x262, 0x280);
};
