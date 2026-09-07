#pragma once

#include "d_enemy.h"
#include "s_State.h"

class daCastleLemmyBall_c : public dEn_c {
    SIZE_ASSERT(0xC20);
    VTABLE(0x060, fBase_c, 0x80957580);
    // 0x80957440 g_profile_CASTLE_LEMMY_BALL
    // 0x807DDCC0 daCastleLemmyBall_c_classInit

public:
    // Structors
    // ^^^^^^

    /* Inlined */
    daCastleLemmyBall_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xC20);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x807DEB90
     * executeState:    0x807DECA0
     * finalizeState:   0x807DEC90
     */
    sState_Extern(0x80997A70, daCastleLemmyBall_c, FillAir);

    /*
     * initializeState: 0x807DEDC0
     * executeState:    0x807DEE90
     * finalizeState:   0x807DEE80
     */
    sState_Extern(0x80997AB0, daCastleLemmyBall_c, FillAirOnDamage);

    /*
     * initializeState: 0x807DF070
     * executeState:    0x807DF100
     * finalizeState:   0x807DF0F0
     */
    sState_Extern(0x80997B30, daCastleLemmyBall_c, Dent);

    /*
     * initializeState: 0x807DF200
     * executeState:    0x807DF250
     * finalizeState:   0x807DF240
     */
    sState_Extern(0x80997B70, daCastleLemmyBall_c, Jump);

    /*
     * initializeState: 0x807DF350
     * executeState:    0x807DF3F0
     * finalizeState:   0x807DF3E0
     */
    sState_Extern(0x80997BB0, daCastleLemmyBall_c, Jump_Ed);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x324 0x807DE9C0
     * executeState:    VT+0x328 0x807DEB10
     * finalizeState:   VT+0x32C 0x807DEB00
     */
    sState_ExternVirtual(0x80997A2C, daCastleLemmyBall_c, DemoWait);

    /*
     * initializeState: VT+0x2BC 0x807DF610
     * executeState:    VT+0x2C0 0x807DF700
     * finalizeState:   VT+0x2C4 0x807DF6F0
     */
    sState_ExternVirtual(0x80997AEC, daCastleLemmyBall_c, Wait);
};
