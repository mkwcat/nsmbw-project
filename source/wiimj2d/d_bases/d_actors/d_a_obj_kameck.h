#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daObjKameck_c : public dEn_c {
    SIZE_ASSERT(0x1620);
    VTABLE(0x0060, fBase_c, 0x80973CB0);
    // 0x809733B8 g_profile_OBJ_KAMECK
    // 0x8087C8F0 daObjKameck_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daObjKameck_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x1620);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8087DBA0
     * executeState:    0x8087DC40
     * finalizeState:   0x8087DD00
     */
    sState_Extern(0x8099D688, daObjKameck_c, Wait);

    /*
     * initializeState: 0x8087DD10
     * executeState:    0x8087DF30
     * finalizeState:   0x8087E8E0
     */
    sState_Extern(0x8099D6C8, daObjKameck_c, Change);

    /*
     * initializeState: 0x8087E8F0
     * executeState:    0x8087EBA0
     * finalizeState:   0x8087EBC0
     */
    sState_Extern(0x8099D708, daObjKameck_c, Crash);

    /*
     * initializeState: 0x8087EBD0
     * executeState:    0x8087EC10
     * finalizeState:   0x8087ED20
     */
    sState_Extern(0x8099D748, daObjKameck_c, Die);

    /*
     * initializeState: 0x8087ED30
     * executeState:    0x8087ED40
     * finalizeState:   0x8087EE20
     */
    sState_Extern(0x8099D788, daObjKameck_c, Brake);
};
