#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daKameckForCastleDemo_c : public dEn_c {
    SIZE_ASSERT(0x968);
    VTABLE(0x060, fBase_c, 0x80961670);
    // 0x809615B8 g_profile_KAMECK_FOR_CASTLE_DEMO
    // 0x80818D00 daKameckForCastleDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80818D60 */
    daKameckForCastleDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x968);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80819B80
     * executeState:    VT+0x284 0x80819C80
     * finalizeState:   VT+0x288 0x80819C70
     */
    sState_ExternVirtual(0x80999C04, daKameckForCastleDemo_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x80819D10
     * executeState:    VT+0x290 0x80819F40
     * finalizeState:   VT+0x294 0x80819F30
     */
    sState_ExternVirtual(0x80999C44, daKameckForCastleDemo_c, DemoSt);

    /*
     * initializeState: VT+0x298 0x8081A090
     * executeState:    VT+0x29C 0x8081A350
     * finalizeState:   VT+0x2A0 0x8081A340
     */
    sState_ExternVirtual(0x80999C84, daKameckForCastleDemo_c, DemoSt2);
};
