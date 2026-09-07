#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnOnewayGate_c : public dEn_c {
    SIZE_ASSERT(0x640);
    VTABLE(0x060, fBase_c, 0x80B00AE0);
    // 0x80B00A98 g_profile_EN_ONEWAY_GATE
    // 0x80A7BCB0 daEnOnewayGate_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnOnewayGate_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x640);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A7C770
     * executeState:    0x80A7C7D0
     * finalizeState:   0x80A7C7B0
     */
    sState_Extern(0x80B19768, daEnOnewayGate_c, CloseWait);

    /*
     * initializeState: 0x80A7C7E0
     * executeState:    0x80A7C810
     * finalizeState:   0x80A7C800
     */
    sState_Extern(0x80B197A8, daEnOnewayGate_c, Open);

    /*
     * initializeState: 0x80A7C8E0
     * executeState:    0x80A7C920
     * finalizeState:   0x80A7C910
     */
    sState_Extern(0x80B197E8, daEnOnewayGate_c, OpenWait);

    /*
     * initializeState: 0x80A7C980
     * executeState:    0x80A7C9B0
     * finalizeState:   0x80A7C9A0
     */
    sState_Extern(0x80B19828, daEnOnewayGate_c, Close);
};
