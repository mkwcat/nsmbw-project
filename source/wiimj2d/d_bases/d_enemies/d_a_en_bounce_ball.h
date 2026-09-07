#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBounceBall_c : public dEn_c {
    SIZE_ASSERT(0x708);
    VTABLE(0x060, fBase_c, 0x80ADE610);
    // 0x80ADE5C8 g_profile_EN_BOUNCE_BALL
    // 0x809CE6D0 daEnBounceBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBounceBall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x708);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2C8 0x809CEFA0
     * executeState:    VT+0x2CC 0x809CF0A0
     * finalizeState:   VT+0x2D0 0x809CF090
     */
    sState_ExternVirtual(0x80B12EEC, daEnBounceBall_c, Move);
};
