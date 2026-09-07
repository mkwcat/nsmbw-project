#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnKopone_c : public dEn_c {
    SIZE_ASSERT(0x9A8);
    VTABLE(0x060, fBase_c, 0x80AF7968);
    // 0x80AF7830 g_profile_EN_KOPONE
    // 0x80A530B0 daEnKopone_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnKopone_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x9A8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A54CD0
     * executeState:    0x80A54CF0
     * finalizeState:   0x80A54CE0
     */
    sState_Extern(0x80B17EF0, daEnKopone_c, Swim);

    /*
     * initializeState: 0x80A54E40
     * executeState:    0x80A54E70
     * finalizeState:   0x80A54E60
     */
    sState_Extern(0x80B17F30, daEnKopone_c, Turn);

    /*
     * initializeState: 0x80A54F20
     * executeState:    0x80A54F70
     * finalizeState:   0x80A54F60
     */
    sState_Extern(0x80B17F70, daEnKopone_c, Attack_wait);

    /*
     * initializeState: 0x80A55090
     * executeState:    0x80A55100
     * finalizeState:   0x80A550F0
     */
    sState_Extern(0x80B17FB0, daEnKopone_c, Attack_swim);

    /*
     * initializeState: 0x80A552C0
     * executeState:    0x80A55340
     * finalizeState:   0x80A55330
     */
    sState_Extern(0x80B17FF0, daEnKopone_c, AttackRevivalWait);

    /*
     * initializeState: 0x80A554E0
     * executeState:    0x80A55660
     * finalizeState:   0x80A55650
     */
    sState_Extern(0x80B18030, daEnKopone_c, Die);
};
