#pragma once

#include "d_allocator.h"
#include "d_enemy.h"
#include "d_profile.h"
#include "s_State.h"

class daEnItem_c : public dEn_c, public dProf::Info<daEnItem_c, dProf::EN_ITEM> {
    SIZE_ASSERT(0xE68);
    VTABLE(0x060, fBase_c, 0x80AF11D0);
    // 0x80AF0E08 g_profile_EN_ITEM
    // 0x80A26A80 daEnItem_c_classInit

public:
    // Nested Types
    // ^^^^^^

    struct Param_s {
        /*  0 */ u32 facing           : 1 = 0;
        /*  1 */ u32 create_type      : 7 = 0;
        /*  8 */ u32 appear_type      : 2 = 0;
        /* 10 */ u32 unk10            : 2 = 0;
        /* 12 -- */ // u32 direction : 2 = 0;
        /* 14 -- */ // u32 player_type : 2 = 0;
        /* 12 ++ */ u32 player_type   : 4 = 0;
        /* 16 -- */ // u32 : 1; // Unused
        /* 17 -- */ // u32 wait : 1 = 0;
        /* 16 ++ */ u32 direction     : 2 = 0;
        /* 18 */ u32    red_coin_drop : 1 = 0;
        /* 19 */ u32    unk19         : 1 = 0;
        /* 20 */ u32    z_order       : 1 = 0;
        /* 21 */ u32    meter_drop    : 1 = 0;
        /* 22 */ u32    unk22         : 1 = 0; // No speed?
        /* 23 -- */                            // u32 : 1; // Unused
        /* 23 ++ */ u32 wait          : 1 = 0;
        /* 24 */ u32    unk24         : 1 = 0;
        /* 25 */ u32    unk25         : 2 = 0;
        /* 27 */ u32    type          : 5 = 0;
    };

public:
    // Constants
    // ^^^^^^

    enum class AppearType_e : int {
        RND_1ST_SET = 0,
        FIXED_SET   = 1,
        RND_2ND_SET, // +++
        RND_3RD_SET, // +++
    };

public:
    // Virtual Methods
    // ^^^^^^

    PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A282F0 */
    bool collectItem();

    /* 0x80A28240 */
    void playGetItemEffect();

    /* 0x80A289C0 */
    float calcZPos();

    /* 0x80A29070 */
    void playGetItemQuake();

    /* 0x80A290A0 */
    void startGetItemShock();

    /* 0x80A290C0 */
    bool checkWater();

private:
    // Instance Variables
    // ^^^^^^

    /* 0x524 */ dHeapAllocator_c mAllocator;

    FILL(0x540, 0xBEC);

    /* 0xBEC */ dAcPy_c* mpCollectPlayer;

    FILL(0xBF0, 0xD74);

    /* 0xD74 */ int m0xD74;
    /* 0xD78 */ int m0xD78;
    /* 0xD7C */ int mPropellerWaitTime;

    FILL(0xD80, 0xDA8);

    /* 0xDA8 */ AppearType_e mAppearType;
    /* 0xDAC */ int          m0xDAC;

    FILL(0xDB0, 0xDBC);

    /* 0xDBC */ int m0xDBC;

    FILL(0xDC0, 0xDC8);

    /* 0xDC8 */ u16 m0xDC8;
    /* 0xDCA */ u16 mItemType;

    FILL(0xDCC, 0xDF2);

    /* 0xDF2 */ u8 mStoredDirection;

    FILL(0xDF3, 0xDFF);

    /* 0xDFF */ s8 mCollectPlayerNo;

    FILL(0xE00, 0xE02);

    /* 0xE02 */ u8 m0xE02;

    FILL(0xE03, 0xE68);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A29690
     * executeState:    0x80A296F0
     * finalizeState:   0x80A296E0
     */
    sState_Extern(0x80B165D8, daEnItem_c, UpMove);

    /*
     * initializeState: 0x80A297A0
     * executeState:    0x80A29800
     * finalizeState:   0x80A297F0
     */
    sState_Extern(0x80B16618, daEnItem_c, DownMove);

    /*
     * initializeState: 0x80A29890
     * executeState:    0x80A29A10
     * finalizeState:   0x80A29A00
     */
    sState_Extern(0x80B16658, daEnItem_c, DropMove);

    /*
     * initializeState: 0x80A29C90
     * executeState:    0x80A29CD0
     * finalizeState:   0x80A29CC0
     */
    sState_Extern(0x80B16698, daEnItem_c, Wait);

    /*
     * initializeState: 0x80A29FB0
     * executeState:    0x80A2A060
     * finalizeState:   0x80A2A050
     */
    sState_Extern(0x80B166D8, daEnItem_c, KinokoMove);

    /*
     * initializeState: 0x80A2A250
     * executeState:    0x80A2A2E0
     * finalizeState:   0x80A2A2D0
     */
    sState_Extern(0x80B16718, daEnItem_c, StarMove);

    /*
     * initializeState: 0x80A2A480
     * executeState:    0x80A2A580
     * finalizeState:   0x80A2A570
     */
    sState_Extern(0x80B16758, daEnItem_c, PropellerMove);

    /*
     * initializeState: 0x80A2A620
     * executeState:    0x80A2A730
     * finalizeState:   0x80A2A720
     */
    sState_Extern(0x80B16798, daEnItem_c, EggCreateUp);

    /*
     * initializeState: 0x80A2A850
     * executeState:    0x80A2A8E0
     * finalizeState:   0x80A2A8D0
     */
    sState_Extern(0x80B167D8, daEnItem_c, ObliquelyMove);

    /*
     * initializeState: 0x80A2A960
     * executeState:    0x80A2A9F0
     * finalizeState:   0x80A2A9E0
     */
    sState_Extern(0x80B16818, daEnItem_c, MeterDropMove);

    /*
     * initializeState: 0x80A2AA80
     * executeState:    0x80A2ABC0
     * finalizeState:   0x80A2ABB0
     */
    sState_Extern(0x80B16858, daEnItem_c, CoinJump);

    /*
     * initializeState: 0x80A2ACC0
     * executeState:    0x80A2ACE0
     * finalizeState:   0x80A2ACD0
     */
    sState_Extern(0x80B16898, daEnItem_c, ControlMove);

    /*
     * initializeState: 0x80A2AD30
     * executeState:    0x80A2ADF0
     * finalizeState:   0x80A2ADE0
     */
    sState_Extern(0x80B168D8, daEnItem_c, FreeDrop);

    /*
     * initializeState: 0x80A2AE70
     * executeState:    0x80A2AFA0
     * finalizeState:   0x80A2AF90
     */
    sState_Extern(0x80B16918, daEnItem_c, ObliquelyJumpMove);

    /*
     * initializeState: 0x80A2B120
     * executeState:    0x80A2B2A0
     * finalizeState:   0x80A2B290
     */
    sState_Extern(0x80B16958, daEnItem_c, BlockAppearMultiJumpUp);

    /*
     * initializeState: 0x80A2B2B0
     * executeState:    0x80A2B4B0
     * finalizeState:   0x80A2B4A0
     */
    sState_Extern(0x80B16998, daEnItem_c, BlockAppearMultiJumpDown);

    /*
     * initializeState: 0x80A2B560
     * executeState:    0x80A2B6C0
     * finalizeState:   0x80A2B6B0
     */
    sState_Extern(0x80B169D8, daEnItem_c, BigCoinJump);

    /*
     * initializeState: 0x80A2B760
     * executeState:    0x80A2B860
     * finalizeState:   0x80A2B850
     */
    sState_Extern(0x80B16A18, daEnItem_c, BigCoinBreak);

    /*
     * initializeState: 0x80A2B9D0
     * executeState:    0x80A2B9F0
     * finalizeState:   0x80A2B9E0
     */
    sState_Extern(0x80B16A58, daEnItem_c, AkoyaLinkWait);

    /*
     * initializeState: 0x80A29AE0
     * executeState:    0x80A29B70
     * finalizeState:   0x80A29B60
     */
    sState_Extern(0x80B16A98, daEnItem_c, RedCoinFlash);

public:
    // Virtual State IDs
    // ^^^^^^

    /*
     * initializeState: VT+0x1E4 0x80A2BAC0
     * executeState:    VT+0x1E8 0x80A2BCA0
     * finalizeState:   VT+0x1EC 0x80A2BC90
     */
    sState_ExternVirtual(0x80B16AD4, daEnItem_c, EatOut);
};
