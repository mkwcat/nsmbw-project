#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daEnBigIcicle_c : public dEn_c {
    SIZE_ASSERT(0x9F0);
    VTABLE(0x060, fBase_c, 0x80AD8360);
    // 0x80AD82B0 g_profile_EN_BIG_ICICLE
    // 0x809B4200 daEnBigIcicle_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daEnBigIcicle_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x9F0);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x809B50A0
     * executeState:    0x809B50C0
     * finalizeState:   0x809B50B0
     */
    sState_Extern(0x80B11EB8, daEnBigIcicle_c, ParentWait);

    /*
     * initializeState: 0x809B5170
     * executeState:    0x809B51C0
     * finalizeState:   0x809B51B0
     */
    sState_Extern(0x80B11EF8, daEnBigIcicle_c, ParentChildDel);

    /*
     * initializeState: 0x809B5250
     * executeState:    0x809B5270
     * finalizeState:   0x809B5260
     */
    sState_Extern(0x80B11F38, daEnBigIcicle_c, ParentCreateWait);

    /*
     * initializeState: 0x809B5280
     * executeState:    0x809B52A0
     * finalizeState:   0x809B5290
     */
    sState_Extern(0x80B11F78, daEnBigIcicle_c, AnmWait);

    /*
     * initializeState: 0x809B5370
     * executeState:    0x809B5390
     * finalizeState:   0x809B5380
     */
    sState_Extern(0x80B11FB8, daEnBigIcicle_c, DownWait);

    /*
     * initializeState: 0x809B53F0
     * executeState:    0x809B5410
     * finalizeState:   0x809B5400
     */
    sState_Extern(0x80B11FF8, daEnBigIcicle_c, Vibration);

    /*
     * initializeState: 0x809B54C0
     * executeState:    0x809B5570
     * finalizeState:   0x809B5560
     */
    sState_Extern(0x80B12038, daEnBigIcicle_c, DownMove);

    /*
     * initializeState: 0x809B5860
     * executeState:    0x809B5880
     * finalizeState:   0x809B5870
     */
    sState_Extern(0x80B12078, daEnBigIcicle_c, DownMoveAgain);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x178 0x809B5920
     * executeState:    VT+0x17C 0x809B5970
     * finalizeState:   VT+0x180 0x809B5960
     */
    sState_ExternVirtual(0x80B120B4, daEnBigIcicle_c, DieFall);
};
