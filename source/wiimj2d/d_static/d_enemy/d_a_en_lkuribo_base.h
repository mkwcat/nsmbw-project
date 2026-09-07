#pragma once

#include "d_enemy.h"

class daEnLkuriboBase_c : public dEn_c {
    SIZE_ASSERT(0x770);
    VTABLE(0x060, fBase_c, 0x80305110);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x770);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80034520
     * executeState:    VT+0x284 0x800345E0
     * finalizeState:   VT+0x288 0x800345D0
     */
    sState_ExternVirtual(0x803538EC, daEnLkuriboBase_c, Walk);

    /*
     * initializeState: VT+0x28C 0x80034720
     * executeState:    VT+0x290 0x80034750
     * finalizeState:   VT+0x294 0x80034740
     */
    sState_ExternVirtual(0x8035392C, daEnLkuriboBase_c, Turn);

    /*
     * initializeState: VT+0x298 0x80034840
     * executeState:    VT+0x29C 0x800348C0
     * finalizeState:   VT+0x2A0 0x800348B0
     */
    sState_ExternVirtual(0x8035396C, daEnLkuriboBase_c, Press);

    /*
     * initializeState: VT+0x2A4 0x80034970
     * executeState:    VT+0x2A8 0x800349F0
     * finalizeState:   VT+0x2AC 0x800349E0
     */
    sState_ExternVirtual(0x803539AC, daEnLkuriboBase_c, Split);

    /*
     * initializeState: VT+0x2B0 0x80034A90
     * executeState:    VT+0x2B4 0x80034B10
     * finalizeState:   VT+0x2B8 0x80034B00
     */
    sState_ExternVirtual(0x803539EC, daEnLkuriboBase_c, HipSplit);

    /*
     * initializeState: VT+0x178 0x80034BC0
     * executeState:    VT+0x17C 0x80034C10
     * finalizeState:   VT+0x180 0x80034C00
     */
    sState_ExternVirtual(0x80353A2C, daEnLkuriboBase_c, DieFall);
};
