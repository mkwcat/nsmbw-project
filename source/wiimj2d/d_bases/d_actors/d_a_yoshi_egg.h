#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daYoshiEgg_c : public dEn_c {
    SIZE_ASSERT(0x610);
    VTABLE(0x060, fBase_c, 0x80989DC0);
    // 0x80989D08 g_profile_AC_YOSHI_EGG
    // 0x80910F00 daYoshiEgg_c_classInit

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80911380 */
    void loadModel();

    /* 0x80911540 */
    void playAnimation(int);

    /* 0x80911610 */
    void spawnEggBreakEffect();

    /* 0x80911680 */
    void hatchYoshi();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x5F4);

    /* 0x5F4 */ int m0x5F4;
    /* 0x5F8 */ int mColor;

    FILL(0x5FC, 0x60C);

    /* 0x60C */ u16 m0x60C;
    /* 0x60E */ u8  m0x60E;

    FILL(0x60F, 0x610);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80911900
     * executeState:    0x80911930
     * finalizeState:   0x80911920
     */
    sState_Extern(0x809A0FE0, daYoshiEgg_c, UpMove);

    /*
     * initializeState: 0x809119B0
     * executeState:    0x809119E0
     * finalizeState:   0x809119D0
     */
    sState_Extern(0x809A1020, daYoshiEgg_c, DownMove);

    /*
     * initializeState: 0x80911AD0
     * executeState:    0x80911BC0
     * finalizeState:   0x80911BB0
     */
    sState_Extern(0x809A1060, daYoshiEgg_c, MultiJumpUp);

    /*
     * initializeState: 0x80911BD0
     * executeState:    0x80911CA0
     * finalizeState:   0x80911C90
     */
    sState_Extern(0x809A10A0, daYoshiEgg_c, MultiJumpDown);

    /*
     * initializeState: 0x80911CB0
     * executeState:    0x80911D00
     * finalizeState:   0x80911CF0
     */
    sState_Extern(0x809A10E0, daYoshiEgg_c, ItemMove);

    /*
     * initializeState: 0x80911DC0
     * executeState:    0x80911E20
     * finalizeState:   0x80911E10
     */
    sState_Extern(0x809A1120, daYoshiEgg_c, ItemCreate);
};
