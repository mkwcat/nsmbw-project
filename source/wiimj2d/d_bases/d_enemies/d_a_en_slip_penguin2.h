#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnSlipPenguin2_c : public dEn_c {
    SIZE_ASSERT(0x10C0);
    VTABLE(0x0060, fBase_c, 0x80B08980);
    // 0x80B088C0 g_profile_EN_SLIP_PENGUIN2
    // 0x80AA2430 daEnSlipPenguin2_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSlipPenguin2_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x10C0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AA4A30
     * executeState:    0x80AA4A50
     * finalizeState:   0x80AA4A40
     */
    sState_Extern(0x80B1B120, daEnSlipPenguin2_c, Wait);

    /*
     * initializeState: 0x80AA4B10
     * executeState:    0x80AA4BC0
     * finalizeState:   0x80AA4BB0
     */
    sState_Extern(0x80B1B160, daEnSlipPenguin2_c, Pipe);

    /*
     * initializeState: 0x80AA4C20
     * executeState:    0x80AA4CE0
     * finalizeState:   0x80AA4CC0
     */
    sState_Extern(0x80B1B1A0, daEnSlipPenguin2_c, Slide);

    /*
     * initializeState: 0x80AA5040
     * executeState:    0x80AA50D0
     * finalizeState:   0x80AA50C0
     */
    sState_Extern(0x80B1B1E0, daEnSlipPenguin2_c, Damage);

    /*
     * initializeState: 0x80AA5260
     * executeState:    0x80AA52C0
     * finalizeState:   0x80AA52B0
     */
    sState_Extern(0x80B1B220, daEnSlipPenguin2_c, Slow);

    /*
     * initializeState: 0x80AA52D0
     * executeState:    0x80AA5360
     * finalizeState:   0x80AA5350
     */
    sState_Extern(0x80B1B260, daEnSlipPenguin2_c, IceSlow);

    /*
     * initializeState: 0x80AA5470
     * executeState:    0x80AA5500
     * finalizeState:   0x80AA54F0
     */
    sState_Extern(0x80B1B2A0, daEnSlipPenguin2_c, IceFast);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x16C 0x80AA5680
     * executeState:    VT+0x170 0x80AA5700
     * finalizeState:   VT+0x174 0x80AA56F0
     */
    sState_ExternVirtual(0x80B1B2DC, daEnSlipPenguin2_c, DieFumi);

    /*
     * initializeState: VT+0x178 0x80AA5750
     * executeState:    VT+0x17C 0x80AA57D0
     * finalizeState:   VT+0x180 0x80AA57C0
     */
    sState_ExternVirtual(0x80B1B31C, daEnSlipPenguin2_c, DieFall);
};
