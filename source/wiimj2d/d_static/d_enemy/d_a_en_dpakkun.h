#pragma once

#include "d_a_en_dpakkun_base.h"

class daEnDpakkun_c : public daEnDpakkunBase_c {
    VTABLE(0x60, fBase_c, 0x80303D9C);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x8002BFF0
     * executeState:    VT+0x284 0x8002C070
     * finalizeState:   VT+0x288 0x8002C060
     */
    sState_ExternVirtual(0x8035340C, daEnDpakkun_c, Wait);

    /*
     * initializeState: VT+0x28C 0x8002C120
     * executeState:    VT+0x290 0x8002C150
     * finalizeState:   VT+0x294 0x8002C140
     */
    sState_ExternVirtual(0x8035344C, daEnDpakkun_c, Appear);

    /*
     * initializeState: VT+0x298 0x8002C200
     * executeState:    VT+0x29C 0x8002C230
     * finalizeState:   VT+0x2A0 0x8002C220
     */
    sState_ExternVirtual(0x8035348C, daEnDpakkun_c, Attack);

    /*
     * initializeState: VT+0x2A4 0x8002C2A0
     * executeState:    VT+0x2A8 0x8002C2C0
     * finalizeState:   VT+0x2AC 0x8002C2B0
     */
    sState_ExternVirtual(0x803534CC, daEnDpakkun_c, Disappear);
};
