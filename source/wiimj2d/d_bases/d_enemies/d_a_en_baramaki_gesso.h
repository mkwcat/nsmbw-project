#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBaramakiGesso_c : public dEn_c {
    SIZE_ASSERT(0x1168);
    VTABLE(0x0060, fBase_c, 0x80AD67B8);
    // 0x80AD67A8 g_profile_EN_BARAMAKI_GESSO
    // 0x809A8960 daEnBaramakiGesso_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBaramakiGesso_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x1168);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x280 0x809A97A0
     * executeState:    VT+0x284 0x809A9830
     * finalizeState:   VT+0x288 0x809A9820
     */
    sState_ExternVirtual(0x80B11814, daEnBaramakiGesso_c, Attack);
};
