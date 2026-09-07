#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnPolter_c : public dEn_c {
    SIZE_ASSERT(0x6C8);
    VTABLE(0x060, fBase_c, 0x80B03108);
    // 0x80B03050 g_profile_EN_POLTER
    // 0x80A861E0 daEnPolter_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnPolter_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A871B0
     * executeState:    0x80A871D0
     * finalizeState:   0x80A871C0
     */
    sState_Extern(0x80B19EF0, daEnPolter_c, Wait);

    /*
     * initializeState: 0x80A87280
     * executeState:    0x80A872A0
     * finalizeState:   0x80A87290
     */
    sState_Extern(0x80B19F30, daEnPolter_c, WaitTime);

    /*
     * initializeState: 0x80A87320
     * executeState:    0x80A87430
     * finalizeState:   0x80A87420
     */
    sState_Extern(0x80B19F70, daEnPolter_c, UpMove);

    /*
     * initializeState: 0x80A87560
     * executeState:    0x80A87580
     * finalizeState:   0x80A87570
     */
    sState_Extern(0x80B19FB0, daEnPolter_c, StandAngleReset);

    /*
     * initializeState: 0x80A87650
     * executeState:    0x80A876F0
     * finalizeState:   0x80A876E0
     */
    sState_Extern(0x80B19FF0, daEnPolter_c, UpSwing);

    /*
     * initializeState: 0x80A87990
     * executeState:    0x80A879C0
     * finalizeState:   0x80A879B0
     */
    sState_Extern(0x80B1A030, daEnPolter_c, BlockUpWait);

    /*
     * initializeState: 0x80A87A90
     * executeState:    0x80A87AC0
     * finalizeState:   0x80A87AB0
     */
    sState_Extern(0x80B1A070, daEnPolter_c, UpWait);

    /*
     * initializeState: 0x80A87BB0
     * executeState:    0x80A87CC0
     * finalizeState:   0x80A87CB0
     */
    sState_Extern(0x80B1A0B0, daEnPolter_c, SearchMove);
};
