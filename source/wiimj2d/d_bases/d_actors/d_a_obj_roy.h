#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjRoy_c : public dEn_c {
    SIZE_ASSERT(0xA10);
    VTABLE(0x060, fBase_c, 0x80975AC0);
    // 0x809759C8 g_profile_OBJ_ROY
    // 0x80886290 daObjRoy_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjRoy_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xA10);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80886AB0
     * executeState:    0x80886AC0
     * finalizeState:   0x80886AD0
     */
    sState_Extern(0x8099DE28, daObjRoy_c, Wait);

    /*
     * initializeState: 0x80886AE0
     * executeState:    0x80886C20
     * finalizeState:   0x80886E20
     */
    sState_Extern(0x8099DE68, daObjRoy_c, Appear);

    /*
     * initializeState: 0x80886E30
     * executeState:    0x80886E40
     * finalizeState:   0x80886E50
     */
    sState_Extern(0x8099DEA8, daObjRoy_c, Stop);
};
