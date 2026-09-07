#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnUnizoo_c : public dEn_c {
    SIZE_ASSERT(0x670);
    VTABLE(0x060, fBase_c, 0x80B0CE08);
    // 0x80B0CAB8 g_profile_EN_UNIZOO
    // 0x80AB8A80 daEnUnizoo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnUnizoo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x670);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80ABA410
     * executeState:    0x80ABA440
     * finalizeState:   0x80ABA430
     */
    sState_Extern(0x80B1BDD8, daEnUnizoo_c, Wait);

    /*
     * initializeState: 0x80ABA450
     * executeState:    0x80ABA480
     * finalizeState:   0x80ABA470
     */
    sState_Extern(0x80B1BE18, daEnUnizoo_c, Udmove);

    /*
     * initializeState: 0x80ABA4D0
     * executeState:    0x80ABA500
     * finalizeState:   0x80ABA4F0
     */
    sState_Extern(0x80B1BE58, daEnUnizoo_c, Lrmove);

    /*
     * initializeState: 0x80ABA550
     * executeState:    0x80ABA670
     * finalizeState:   0x80ABA660
     */
    sState_Extern(0x80B1BE98, daEnUnizoo_c, IceBreakFall);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x80ABA950
     * executeState:    VT+0x17C 0x80ABA9F0
     * finalizeState:   VT+0x180 0x80ABA9E0
     */
    sState_ExternVirtual(0x80B1BED4, daEnUnizoo_c, DieFall);

    /*
     * initializeState: VT+0x1FC 0x80ABAA80
     * executeState:    VT+0x200 0x80ABAAD0
     * finalizeState:   VT+0x204 0x80ABAAC0
     */
    sState_ExternVirtual(0x80B1BF14, daEnUnizoo_c, Ice);
};

class daEnUnira_c : public daEnUnizoo_c {
    SIZE_ASSERT(0x670);
    VTABLE(0x060, fBase_c, 0x80B0CB88);
    // 0x80B0CAC4 g_profile_EN_UNIRA
    // 0x80AB8B90 daEnUnira_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnUnira_c();
};
