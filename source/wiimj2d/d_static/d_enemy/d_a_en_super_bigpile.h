#pragma once

#include "d_enemy.h"

class daEnSuperBigPile_c : public dEn_c {
    SIZE_ASSERT(0x6A0);
    VTABLE(0x60, fBase_c, 0x80306210);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6A0);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8003D250
     * executeState:    VT+0x284 0x8003D290
     * finalizeState:   VT+0x288 0x8003D280
     */
    sState_ExternVirtual(0x80353EA4, daEnSuperBigPile_c, GoWait);

    /*
     * initializeState: VT+0x28C 0x8003D2C0
     * executeState:    VT+0x290 0x8003D2E0
     * finalizeState:   VT+0x294 0x8003D2D0
     */
    sState_ExternVirtual(0x80353EE4, daEnSuperBigPile_c, GoMove);

    /*
     * initializeState: VT+0x298 0x8003D2F0
     * executeState:    VT+0x29C 0x8003D380
     * finalizeState:   VT+0x2A0 0x8003D370
     */
    sState_ExternVirtual(0x80353F24, daEnSuperBigPile_c, RetWait);

    /*
     * initializeState: VT+0x2A4 0x8003D3B0
     * executeState:    VT+0x2A8 0x8003D3D0
     * finalizeState:   VT+0x2AC 0x8003D3C0
     */
    sState_ExternVirtual(0x80353F64, daEnSuperBigPile_c, RetMove);
};
