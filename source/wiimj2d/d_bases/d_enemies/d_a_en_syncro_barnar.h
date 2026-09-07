#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnSyncroBarnar_c : public dEn_c {
    SIZE_ASSERT(0xC08);
    VTABLE(0x060, fBase_c, 0x80B0A550);
    // 0x80B0A500 g_profile_EN_SYNCRO_BARNAR
    // 0x80AAD340 daEnSyncroBarnar_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnSyncroBarnar_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xC08);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80AADBD0
     * executeState:    0x80AADC00
     * finalizeState:   0x80AADBF0
     */
    sState_Extern(0x80B1B7A8, daEnSyncroBarnar_c, Syncro);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x80AADAD0
     * executeState:    VT+0x284 0x80AADB00
     * finalizeState:   VT+0x288 0x80AADAF0
     */
    sState_ExternVirtual(0x80B1B7E4, daEnSyncroBarnar_c, Wait);

    /*
     * initializeState: VT+0x28C 0x80AAD960
     * executeState:    VT+0x290 0x80AAD9D0
     * finalizeState:   VT+0x294 0x80AAD9C0
     */
    sState_ExternVirtual(0x80B1B824, daEnSyncroBarnar_c, Fire);
};
