#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBarrel_c : public dEn_c {
    SIZE_ASSERT(0x5D8);
    VTABLE(0x060, fBase_c, 0x80AD6FC0);
    // 0x80AD6F90 g_profile_EN_BARREL
    // 0x809AB100 daEnBarrel_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBarrel_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5D8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809AC650
     * executeState:    0x809AC670
     * finalizeState:   0x809AC660
     */
    sState_Extern(0x80B118F8, daEnBarrel_c, Waki);

    /*
     * initializeState: 0x809ABC60
     * executeState:    0x809ABC90
     * finalizeState:   0x809ABC80
     */
    sState_Extern(0x80B11938, daEnBarrel_c, Wait);

    /*
     * initializeState: 0x809ABD10
     * executeState:    0x809ABD40
     * finalizeState:   0x809ABD30
     */
    sState_Extern(0x80B11978, daEnBarrel_c, Wait2);

    /*
     * initializeState: 0x809ABE00
     * executeState:    0x809ABE50
     * finalizeState:   0x809ABE40
     */
    sState_Extern(0x80B119B8, daEnBarrel_c, Down);

    /*
     * initializeState: 0x809ABF50
     * executeState:    0x809ABFB0
     * finalizeState:   0x809ABFA0
     */
    sState_Extern(0x80B119F8, daEnBarrel_c, Up);

    /*
     * initializeState: 0x809AC0D0
     * executeState:    0x809AC100
     * finalizeState:   0x809AC0F0
     */
    sState_Extern(0x80B11A38, daEnBarrel_c, Fall);

    /*
     * initializeState: 0x809AC260
     * executeState:    0x809AC280
     * finalizeState:   0x809AC270
     */
    sState_Extern(0x80B11A78, daEnBarrel_c, Fall2);

    /*
     * initializeState: 0x809AC2D0
     * executeState:    0x809AC2F0
     * finalizeState:   0x809AC2E0
     */
    sState_Extern(0x80B11AB8, daEnBarrel_c, Rise);

    /*
     * initializeState: 0x809AC410
     * executeState:    0x809AC430
     * finalizeState:   0x809AC420
     */
    sState_Extern(0x80B11AF8, daEnBarrel_c, Rise2);

    /*
     * initializeState: 0x809AC490
     * executeState:    0x809AC520
     * finalizeState:   0x809AC510
     */
    sState_Extern(0x80B11B38, daEnBarrel_c, Stop);
};
