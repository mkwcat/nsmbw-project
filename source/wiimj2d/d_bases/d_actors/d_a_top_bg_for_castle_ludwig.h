#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daTopBGForCastleLudwig_c : public dEn_c {
    SIZE_ASSERT(0xAA0);
    VTABLE(0x060, fBase_c, 0x8097D600);
    // 0x8097D5C0 g_profile_TOP_BG_FOR_CASTLE_LUDWIG
    // 0x808B0000 daTopBGForCastleLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x808B0040 */
    daTopBGForCastleLudwig_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xAA0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x808B0720
     * executeState:    VT+0x284 0x808B0740
     * finalizeState:   VT+0x288 0x808B0730
     */
    sState_ExternVirtual(0x8099F404, daTopBGForCastleLudwig_c, DemoWait);
};
