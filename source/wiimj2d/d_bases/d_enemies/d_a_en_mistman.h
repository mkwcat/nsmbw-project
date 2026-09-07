#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnMistMan_c : public dEn_c {
    SIZE_ASSERT(0xBE0);
    VTABLE(0x060, fBase_c, 0x80AFCA28);
    // 0x80AFC910 g_profile_EN_MISTMAN
    // 0x80A6AC70 daEnMistMan_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnMistMan_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xBE0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A6C020
     * executeState:    0x80A6C080
     * finalizeState:   0x80A6C070
     */
    sState_Extern(0x80B18D50, daEnMistMan_c, Wait);

    /*
     * initializeState: 0x80A6C1E0
     * executeState:    0x80A6C270
     * finalizeState:   0x80A6C260
     */
    sState_Extern(0x80B18D90, daEnMistMan_c, Mist_St);

    /*
     * initializeState: 0x80A6C490
     * executeState:    0x80A6C510
     * finalizeState:   0x80A6C500
     */
    sState_Extern(0x80B18DD0, daEnMistMan_c, Mist);

    /*
     * initializeState: 0x80A6C6E0
     * executeState:    0x80A6C740
     * finalizeState:   0x80A6C730
     */
    sState_Extern(0x80B18E10, daEnMistMan_c, Mist_Ed);

    /*
     * initializeState: 0x80A6CA00
     * executeState:    0x80A6CBB0
     * finalizeState:   0x80A6CBA0
     */
    sState_Extern(0x80B18E50, daEnMistMan_c, Vanish);

    /*
     * initializeState: 0x80A6C8C0
     * executeState:    0x80A6C9A0
     * finalizeState:   0x80A6C990
     */
    sState_Extern(0x80B18E90, daEnMistMan_c, FumiDmg);

    /*
     * initializeState: 0x80A6CC90
     * executeState:    0x80A6CE70
     * finalizeState:   0x80A6CE60
     */
    sState_Extern(0x80B18ED0, daEnMistMan_c, IceBreak);
};
