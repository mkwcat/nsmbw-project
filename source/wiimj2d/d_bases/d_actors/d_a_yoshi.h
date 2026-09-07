#pragma once

#include "d_a_player_base.h"
#include "d_player_model_manager.h"
#include "d_profile.h"

class dAcPy_c;

class daYoshi_c : public daPlBase_c, public dProf::Info<daYoshi_c, dProf::YOSHI> {
    SIZE_ASSERT(0x17C8);
    VTABLE(0x0060, fBase_c, 0x80326ADC);
    // 0x80326A50 g_profile_YOSHI
    // 0x8014B400 daYoshi_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x8014B430 */
    daYoshi_c();

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0DC 0x80150E10 */
    virtual void executeLastAll() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8014EAF0 */
    dAcPy_c* getPlayerRideOn() const;

    /* 0x80150420 */
    void setHitTongueReserve();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x14D4 */ dPyMdlMng_c mModelMng;

    FILL(0x14E0, 0x1524);

    /* 0x1524 */ int mEatStage;

    FILL(0x1528, 0x1564);

    /* 0x1564 */ int m_eatCount;

    FILL(0x1568, 0x17C8);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8014BC20
     * executeState:    0x8014BD30
     * finalizeState:   0x8014BD20
     */
    sState_Extern(0x80376DC8, daYoshi_c, AloneWait);

    /*
     * initializeState: 0x8014BF90
     * executeState:    0x8014C160
     * finalizeState:   0x8014C0F0
     */
    sState_Extern(0x80376E08, daYoshi_c, BlockOut);

    /*
     * initializeState: 0x8014C2B0
     * executeState:    0x8014C380
     * finalizeState:   0x8014C340
     */
    sState_Extern(0x80376E48, daYoshi_c, DamageRun);

    /*
     * initializeState: 0x8014C4E0
     * executeState:    0x8014C550
     * finalizeState:   0x8014C540
     */
    sState_Extern(0x80376E88, daYoshi_c, StartRideOn);

    /*
     * initializeState: 0x8014EE70
     * executeState:    0x8014EE90
     * finalizeState:   0x8014EE80
     */
    sState_Extern(0x80377188, daYoshi_c, EatNone);

    /*
     * initializeState: 0x8014F200
     * executeState:    0x8014FEA0
     * finalizeState:   0x8014F340
     */
    sState_Extern(0x803771C8, daYoshi_c, Eat);

    /*
     * initializeState: 0x80150040
     * executeState:    0x801501D0
     * finalizeState:   0x801500C0
     */
    sState_Extern(0x80377208, daYoshi_c, EatOut);

    /*
     * initializeState: 0x8014FEF0
     * executeState:    0x80150020
     * finalizeState:   0x8014FFA0
     */
    sState_Extern(0x80377248, daYoshi_c, EatMouth);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x2A4 0x8014C7D0
     * executeState:    VT+0x2A8 0x8014C8C0
     * finalizeState:   VT+0x2AC 0x8014C870
     */
    sState_ExternVirtual(0x80376EC4, daYoshi_c, Walk);

    /*
     * initializeState: VT+0x2B0 0x8014D5E0
     * executeState:    VT+0x2B4 0x8014D750
     * finalizeState:   VT+0x2B8 0x8014D710
     */
    sState_ExternVirtual(0x80376F04, daYoshi_c, Jump);

    /*
     * initializeState: VT+0x2C8 0x8014D810
     * executeState:    VT+0x2CC 0x8014D8A0
     * finalizeState:   VT+0x2D0 0x8014D860
     */
    sState_ExternVirtual(0x80376F44, daYoshi_c, Fall);

    /*
     * initializeState: VT+0x2D4 0x8014D910
     * executeState:    VT+0x2D8 0x8014D960
     * finalizeState:   VT+0x2DC 0x8014D950
     */
    sState_ExternVirtual(0x80376F84, daYoshi_c, Land);

    /*
     * initializeState: VT+0x2E0 0x8014DDA0
     * executeState:    VT+0x2E4 0x8014DF40
     * finalizeState:   VT+0x2E8 0x8014DEE0
     */
    sState_ExternVirtual(0x80376FC4, daYoshi_c, Crouch);

    /*
     * initializeState: VT+0x2BC 0x8014DA80
     * executeState:    VT+0x2C0 0x8014DBF0
     * finalizeState:   VT+0x2C4 0x8014DB60
     */
    sState_ExternVirtual(0x80377004, daYoshi_c, SitJump);

    /*
     * initializeState: VT+0x2EC 0x8014E180
     * executeState:    VT+0x2F0 0x8014E210
     * finalizeState:   VT+0x2F4 0x8014E190
     */
    sState_ExternVirtual(0x80377044, daYoshi_c, Slip);

    /*
     * initializeState: VT+0x2F8 0x8014E3B0
     * executeState:    VT+0x2FC 0x8014E4B0
     * finalizeState:   VT+0x300 0x8014E4A0
     */
    sState_ExternVirtual(0x80377084, daYoshi_c, Turn);

    /*
     * initializeState: VT+0x304 0x8014E760
     * executeState:    VT+0x308 0x8014E7E0
     * finalizeState:   VT+0x30C 0x8014E7A0
     */
    sState_ExternVirtual(0x803770C4, daYoshi_c, HipAttack);

    /*
     * initializeState: VT+0x334 0x8014EA50
     * executeState:    VT+0x338 0x8014EAD0
     * finalizeState:   VT+0x33C 0x8014EA90
     */
    sState_ExternVirtual(0x80377104, daYoshi_c, Funsui);

    /*
     * initializeState: VT+0x34C 0x8014E7F0
     * executeState:    VT+0x350 0x8014E960
     * finalizeState:   VT+0x354 0x8014E840
     */
    sState_ExternVirtual(0x80377144, daYoshi_c, Cloud);
};
