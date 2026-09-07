#pragma once

#include "d_enemy.h"

class daEnKuriboBase_c : public dEn_c {
    SIZE_ASSERT(0x85C);
    VTABLE(0x060, fBase_c, 0x80304C38);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x85C);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x800320C0
     * executeState:    VT+0x284 0x80032170
     * finalizeState:   VT+0x288 0x80032160
     */
    sState_ExternVirtual(0x803537EC, daEnKuriboBase_c, Walk);

    /*
     * initializeState: VT+0x28C 0x80032370
     * executeState:    VT+0x290 0x800323F0
     * finalizeState:   VT+0x294 0x800323E0
     */
    sState_ExternVirtual(0x8035382C, daEnKuriboBase_c, Turn);

    /*
     * initializeState: VT+0x298 0x80032570
     * executeState:    VT+0x29C 0x800325C0
     * finalizeState:   VT+0x2A0 0x800325B0
     */
    sState_ExternVirtual(0x8035386C, daEnKuriboBase_c, TrplnJump);

    /*
     * initializeState: VT+0x1C0 0x800326F0
     * executeState:    VT+0x1C4 0x80032790
     * finalizeState:   VT+0x1C8 0x80032780
     */
    sState_ExternVirtual(0x803538AC, daEnKuriboBase_c, DieOther);
};
