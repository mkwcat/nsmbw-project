#pragma once

#include "d_a_en_jimen_pakkun_base.h"
#include "s_State.h"

class daEnJimenFPakkun_c : public daEnJimenPakkunBase_c {
    SIZE_ASSERT(0x780);
    VTABLE(0x060, fBase_c, 0x80AF2D90);
    // 0x80AF2D50 g_profile_EN_JIMEN_FPAKKUN
    // 0x80A32970 daEnJimenFPakkun_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnJimenFPakkun_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x76C, 0x780);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A32ED0
     * executeState:    0x80A32EF0
     * finalizeState:   0x80A32EE0
     */
    sState_Extern(0x80B16D18, daEnJimenFPakkun_c, Wait);

    /*
     * initializeState: 0x80A32FB0
     * executeState:    0x80A32FD0
     * finalizeState:   0x80A32FC0
     */
    sState_Extern(0x80B16D58, daEnJimenFPakkun_c, AttackReady);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x28C 0x80A33110
     * executeState:    VT+0x290 0x80A33130
     * finalizeState:   VT+0x294 0x80A33120
     */
    sState_ExternVirtual(0x80B16D98, daEnJimenFPakkun_c, Attack);
};
