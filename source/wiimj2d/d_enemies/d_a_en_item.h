#pragma once

#include "d_profile/d_profile.h"
#include "d_system/d_allocator.h"
#include "d_system/d_enemy.h"
#include "state/s_State.h"

class daEnItem_c : public dEn_c, public dProf::Info<daEnItem_c, dProf::EN_ITEM> {
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

    FILL(0xDE0, 0xE02);

    /* 0xE02 */ u8 m0xE02;

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80B165D8, daEnItem_c, UpMove);
    sState_Extern(0x80B16618, daEnItem_c, DownMove);
    sState_Extern(0x80B16658, daEnItem_c, DropMove);
    sState_Extern(0x80B16698, daEnItem_c, Wait);
    sState_Extern(0x80B166D8, daEnItem_c, KinokoMove);
    sState_Extern(0x80B16718, daEnItem_c, StarMove);
    sState_Extern(0x80B16758, daEnItem_c, PropellerMove);
    sState_Extern(0x80B16798, daEnItem_c, EggCreateUp);
    sState_Extern(0x80B167D8, daEnItem_c, ObliquelyMove);
    sState_Extern(0x80B16818, daEnItem_c, MeterDropMove);
    sState_Extern(0x80B16858, daEnItem_c, CoinJump);
    sState_Extern(0x80B16898, daEnItem_c, ControlMove);
    sState_Extern(0x80B168D8, daEnItem_c, FreeDrop);
    sState_Extern(0x80B16918, daEnItem_c, ObliquelyJumpMove);
    sState_Extern(0x80B16958, daEnItem_c, BlockAppearMultiJumpUp);
    sState_Extern(0x80B16998, daEnItem_c, BlockAppearMultiJumpDown);
    sState_Extern(0x80B169D8, daEnItem_c, BigCoinJump);
    sState_Extern(0x80B16A18, daEnItem_c, BigCoinBreak);
    sState_Extern(0x80B16A58, daEnItem_c, AkoyaLinkWait);
    sState_Extern(0x80B16A98, daEnItem_c, RedCoinFlash);
    sState_Extern(0x80B16AD4, daEnItem_c, EatOut);
};
