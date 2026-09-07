#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnFireSnake_c : public dEn_c {
    SIZE_ASSERT(0x14E0);
    VTABLE(0x0060, fBase_c, 0x80AE95E0);
    // 0x80AE9478 g_profile_EN_FIRESNAKE
    // 0x809F9EC0 daEnFireSnake_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnFireSnake_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x0524, 0x14E0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809FB8D0
     * executeState:    0x809FB920
     * finalizeState:   0x809FB910
     */
    sState_Extern(0x80B14628, daEnFireSnake_c, Wait);

    /*
     * initializeState: 0x809FC0C0
     * executeState:    0x809FC190
     * finalizeState:   0x809FC180
     */
    sState_Extern(0x80B14668, daEnFireSnake_c, Move_St);

    /*
     * initializeState: 0x809FC320
     * executeState:    0x809FC440
     * finalizeState:   0x809FC430
     */
    sState_Extern(0x80B146A8, daEnFireSnake_c, Move);

    /*
     * initializeState: 0x809FC530
     * executeState:    0x809FC5E0
     * finalizeState:   0x809FC5D0
     */
    sState_Extern(0x80B146E8, daEnFireSnake_c, Move_Ed);

    /*
     * initializeState: 0x809FB9B0
     * executeState:    0x809FBA10
     * finalizeState:   0x809FBA00
     */
    sState_Extern(0x80B14728, daEnFireSnake_c, Shake);

    /*
     * initializeState: 0x809FBB50
     * executeState:    0x809FBC20
     * finalizeState:   0x809FBC00
     */
    sState_Extern(0x80B14768, daEnFireSnake_c, LargeWait);

    /*
     * initializeState: 0x809FC680
     * executeState:    0x809FC780
     * finalizeState:   0x809FC770
     */
    sState_Extern(0x80B147A8, daEnFireSnake_c, LargeMove);

    /*
     * initializeState: 0x809FC900
     * executeState:    0x809FC9E0
     * finalizeState:   0x809FC9D0
     */
    sState_Extern(0x80B147E8, daEnFireSnake_c, SmallMove);

    /*
     * initializeState: 0x809FCB80
     * executeState:    0x809FCBA0
     * finalizeState:   0x809FCB90
     */
    sState_Extern(0x80B14828, daEnFireSnake_c, SmallMove_Ed);

    /*
     * initializeState: 0x809FBEA0
     * executeState:    0x809FBED0
     * finalizeState:   0x809FBEC0
     */
    sState_Extern(0x80B14868, daEnFireSnake_c, Hide);

    /*
     * initializeState: 0x809FBFA0
     * executeState:    0x809FBFD0
     * finalizeState:   0x809FBFC0
     */
    sState_Extern(0x80B148A8, daEnFireSnake_c, Appear);

    /*
     * initializeState: 0x809FBD00
     * executeState:    0x809FBD60
     * finalizeState:   0x809FBD50
     */
    sState_Extern(0x80B148E8, daEnFireSnake_c, Vanish);

    /*
     * initializeState: 0x809FBE30
     * executeState:    0x809FBE80
     * finalizeState:   0x809FBE70
     */
    sState_Extern(0x80B14928, daEnFireSnake_c, Vanish_Ed);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809FB6D0
     * executeState:    VT+0x17C 0x809FB820
     * finalizeState:   VT+0x180 0x809FB810
     */
    sState_ExternVirtual(0x80B14964, daEnFireSnake_c, DieFall);
};
