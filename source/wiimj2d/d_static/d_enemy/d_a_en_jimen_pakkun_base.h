#pragma once

#include "d_enemy.h"

class dCc_c;

class daEnJimenPakkunBase_c : public dEn_c {
    SIZE_ASSERT(0x76C);
    VTABLE(0x060, fBase_c, 0x8030478C);

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x8002F870 */
    void Normal_VsPlHitCheck(dCc_c* main, dCc_c* other) override;

    /* 0x8002F970 */
    bool hitCallback_YoshiHipAttk(dCc_c* main, dCc_c* other) override;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x76C);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1C0 0x80030440
     * executeState:    VT+0x1C4 0x800305A0
     * finalizeState:   VT+0x1C8 0x80030590
     */
    sState_ExternVirtual(0x803536EC, daEnJimenPakkunBase_c, DieOther);

    /*
     * initializeState: VT+0x280 0x80030680
     * executeState:    VT+0x284 0x800307B0
     * finalizeState:   VT+0x288 0x800307A0
     */
    sState_ExternVirtual(0x8035372C, daEnJimenPakkunBase_c, DieIceBreak);

    /*
     * initializeState: VT+0x28C 0x80030870
     * executeState:    VT+0x290 0x80030890
     * finalizeState:   VT+0x294 0x80030880
     */
    sState_ExternVirtual(0x8035376C, daEnJimenPakkunBase_c, Attack);

    /*
     * initializeState: VT+0x298 0x800308A0
     * executeState:    VT+0x29C 0x800308C0
     * finalizeState:   VT+0x2A0 0x800308B0
     */
    sState_ExternVirtual(0x803537AC, daEnJimenPakkunBase_c, SakasaAttack);
};
