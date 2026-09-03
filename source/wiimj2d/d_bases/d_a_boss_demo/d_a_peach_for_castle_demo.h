#pragma once

#include "d_enemy.h"

class daPeachForCastleDemo_c : public dEn_c {
    SIZE_ASSERT(0x5D0);
    VTABLE(0x060, fBase_c, 0x80977DA0);
    // 0x80977D38 g_profile_PEACH_FOR_CASTLE_DEMO
    // 0x8088FF80 daPeachForCastleDemo_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8088FFF0 */
    daPeachForCastleDemo_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5D0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x808905E0
     * executeState:    VT+0x284 0x808906A0
     * finalizeState:   VT+0x288 0x80890690
     */
    sState_ExternVirtual(0x8099E1CC, daPeachForCastleDemo_c, DemoWait);

    /*
     * initializeState: VT+0x28C 0x808906B0
     * executeState:    VT+0x290 0x80890750
     * finalizeState:   VT+0x294 0x80890740
     */
    sState_ExternVirtual(0x8099E20C, daPeachForCastleDemo_c, DemoSt);

    /*
     * initializeState: VT+0x298 0x808908B0
     * executeState:    VT+0x29C 0x808908D0
     * finalizeState:   VT+0x2A0 0x808908C0
     */
    sState_ExternVirtual(0x8099E24C, daPeachForCastleDemo_c, DemoSt2);

    /*
     * initializeState: VT+0x2A4 0x808909E0
     * executeState:    VT+0x2A8 0x80890A80
     * finalizeState:   VT+0x2AC 0x80890A70
     */
    sState_ExternVirtual(0x8099E28C, daPeachForCastleDemo_c, DemoHelpMe);
};
