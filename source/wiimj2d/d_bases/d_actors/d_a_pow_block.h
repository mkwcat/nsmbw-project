#pragma once

#include "d_actor_state.h"
#include "s_State.h"

class daPowBlock_c : public dActorState_c {
    SIZE_ASSERT(0x5B8);
    VTABLE(0x060, fBase_c, 0x80978280);
    // 0x80978228 g_profile_POW_BLOCK
    // 0x808912B0 daPowBlock_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daPowBlock_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3D0, 0x5B8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x808921A0
     * executeState:    0x808921E0
     * finalizeState:   0x808921D0
     */
    sState_Extern(0x8099E2D8, daPowBlock_c, Wait);

    /*
     * initializeState: 0x80892280
     * executeState:    0x80892350
     * finalizeState:   0x80892300
     */
    sState_Extern(0x8099E318, daPowBlock_c, Carry);

    /*
     * initializeState: 0x808925B0
     * executeState:    0x80892610
     * finalizeState:   0x80892600
     */
    sState_Extern(0x8099E358, daPowBlock_c, Drop);

    /*
     * initializeState: 0x808926D0
     * executeState:    0x80892730
     * finalizeState:   0x80892720
     */
    sState_Extern(0x8099E398, daPowBlock_c, Drop2);

    /*
     * initializeState: 0x808927F0
     * executeState:    0x808928F0
     * finalizeState:   0x808928C0
     */
    sState_Extern(0x8099E3D8, daPowBlock_c, Throw);

    /*
     * initializeState: 0x80892C50
     * executeState:    0x80892E10
     * finalizeState:   0x80892E00
     */
    sState_Extern(0x8099E418, daPowBlock_c, Shock);

    /*
     * initializeState: 0x80892EB0
     * executeState:    0x80893060
     * finalizeState:   0x80893050
     */
    sState_Extern(0x8099E458, daPowBlock_c, Shock2);
};
