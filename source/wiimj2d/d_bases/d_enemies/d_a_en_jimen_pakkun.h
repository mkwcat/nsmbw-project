#pragma once

#include "d_a_en_jimen_pakkun_base.h"
#include "s_State.h"

class daEnJimenPakkun_c : public daEnJimenPakkunBase_c {
    SIZE_ASSERT(0x778);
    VTABLE(0x060, fBase_c, 0x80AF3198);
    // 0x80AF3180 g_profile_EN_JIMEN_PAKKUN
    // 0x80A337E0 daEnJimenPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJimenPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x76C, 0x778);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80A33990
     * executeState:    VT+0x290 0x80A33A30
     * finalizeState:   VT+0x294 0x80A33A20
     */
    sState_ExternVirtual(0x80B16DD4, daEnJimenPakkun_c, Attack);

    /*
     * initializeState: VT+0x298 0x80A33C20
     * executeState:    VT+0x29C 0x80A33C50
     * finalizeState:   VT+0x2A0 0x80A33C40
     */
    sState_ExternVirtual(0x80B16E14, daEnJimenPakkun_c, SakasaAttack);
};
