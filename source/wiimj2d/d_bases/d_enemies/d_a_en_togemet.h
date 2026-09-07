#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnTogeMet_c : public dEn_c {
    SIZE_ASSERT(0x7F8);
    VTABLE(0x060, fBase_c, 0x80B0B898);
    // 0x80B0B850 g_profile_EN_TOGEMET
    // 0x80AB2A10 daEnTogeMet_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnTogeMet_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x7F8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AB4890
     * executeState:    0x80AB4990
     * finalizeState:   0x80AB4980
     */
    sState_Extern(0x80B1BA08, daEnTogeMet_c, Walk);

    /*
     * initializeState: 0x80AB4B30
     * executeState:    0x80AB4B60
     * finalizeState:   0x80AB4B40
     */
    sState_Extern(0x80B1BA48, daEnTogeMet_c, Turn);

    /*
     * initializeState: 0x80AB4C00
     * executeState:    0x80AB4C20
     * finalizeState:   0x80AB4C10
     */
    sState_Extern(0x80B1BA88, daEnTogeMet_c, WindTurn);

    /*
     * initializeState: 0x80AB5070
     * executeState:    0x80AB5110
     * finalizeState:   0x80AB5100
     */
    sState_Extern(0x80B1BAC8, daEnTogeMet_c, DieBreak);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1FC 0x80AB4D20
     * executeState:    VT+0x200 0x80AB4D70
     * finalizeState:   VT+0x204 0x80AB4D60
     */
    sState_ExternVirtual(0x80B1BB04, daEnTogeMet_c, Ice);

    /*
     * initializeState: VT+0x178 0x80AB4E90
     * executeState:    VT+0x17C 0x80AB4FC0
     * finalizeState:   VT+0x180 0x80AB4FB0
     */
    sState_ExternVirtual(0x80B1BB44, daEnTogeMet_c, DieFall);
};
