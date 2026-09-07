#pragma once

#include "d_a_en_dpakkun_base.h"

class daEnDfpakkun_c : public daEnDpakkunBase_c {
    SIZE_ASSERT(0x758);
    VTABLE(0x60, fBase_c, 0x803033FC);

public:
    // Structors
    // ^^^^^^

    /* 0x800281C0 */
    daEnDfpakkun_c();

public:
    FILL(0x6E0, 0x758);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80029830
     * executeState:    VT+0x284 0x800298A0
     * finalizeState:   VT+0x288 0x80029890
     */
    sState_ExternVirtual(0x8035312C, daEnDfpakkun_c, Wait);

    /*
     * initializeState: VT+0x28C 0x80029990
     * executeState:    VT+0x290 0x80029A20
     * finalizeState:   VT+0x294 0x80029A10
     */
    sState_ExternVirtual(0x8035316C, daEnDfpakkun_c, Appear);

    /*
     * initializeState: VT+0x298 0x80029B40
     * executeState:    VT+0x29C 0x80029C20
     * finalizeState:   VT+0x2A0 0x80029C10
     */
    sState_ExternVirtual(0x803531AC, daEnDfpakkun_c, Attack);

    /*
     * initializeState: VT+0x2A4 0x80029FF0
     * executeState:    VT+0x2A8 0x8002A030
     * finalizeState:   VT+0x2AC 0x8002A020
     */
    sState_ExternVirtual(0x803531EC, daEnDfpakkun_c, Disappear);

    /*
     * initializeState: VT+0x2BC 0x80029670
     * executeState:    VT+0x2C0 0x80029720
     * finalizeState:   VT+0x2C4 0x80029710
     */
    sState_ExternVirtual(0x8035322C, daEnDfpakkun_c, DieVanish);

    /*
     * initializeState: VT+0x2B0 0x800297B0
     * executeState:    VT+0x2B4 0x800297D0
     * finalizeState:   VT+0x2B8 0x800297C0
     */
    sState_ExternVirtual(0x8035326C, daEnDfpakkun_c, DieIceBreak);
};
