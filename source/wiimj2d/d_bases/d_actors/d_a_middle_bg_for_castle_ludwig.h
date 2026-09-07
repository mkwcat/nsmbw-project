#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daMiddleBGForCastleLudwig_c : public dEn_c {
    SIZE_ASSERT(0x768);
    VTABLE(0x060, fBase_c, 0x8096EEBC);
    // 0x8096EB78 g_profile_MIDDLE_BG_FOR_CASTLE_LUDWIG
    // 0x808628A0 daMiddleBGForCastleLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80862930 */
    daMiddleBGForCastleLudwig_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x768);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x808630E0
     * executeState:    VT+0x290 0x80863100
     * finalizeState:   VT+0x294 0x808630F0
     */
    sState_ExternVirtual(0x8099C9AC, daMiddleBGForCastleLudwig_c, DemoWait);
};

class daBottomBGForCastleLudwig_c : public daMiddleBGForCastleLudwig_c {
    SIZE_ASSERT(0x768);
    VTABLE(0x060, fBase_c, 0x8096EC18);
    // 0x8096EB84 g_profile_BOTTOM_BG_FOR_CASTLE_LUDWIG
    // 0x808628D0 daBottomBGForCastleLudwig_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80862930 */
    daBottomBGForCastleLudwig_c() {}
};
