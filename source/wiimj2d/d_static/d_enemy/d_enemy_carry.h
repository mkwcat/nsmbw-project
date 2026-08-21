#pragma once

#include "d_static/d_enemy/d_enemy.h"
#include "state/s_State.h"

class dEnemyCarry_c : dEn_c {
public:
    // Instance Variables
    // ^^^^^^

    OFFSET_ASSERT(0x524);

    /* 0x524 */ bool m0x524;

public:
    // State IDs
    // ^^^^^^

    // Actually virtual states but leaving it like this for now

    /**
     * initializeState: VT+0x28C 0x8009ED10
     * executeState:    VT+0x290 0x8009EE30
     * finalizeState:   VT+0x294 0x8009EDB0
     */
    sState_Extern(0x80357E34, dEnemyCarry_c, Carry);

    /**
     * initializeState: VT+0x298 0x8009EF90
     * executeState:    VT+0x29C 0x8009F000
     * finalizeState:   VT+0x2A0 0x8009EFD0
     */
    sState_Extern(0x80357E74, dEnemyCarry_c, Throw);
};
