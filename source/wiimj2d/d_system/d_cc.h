#pragma once

#include "machine/m_vec.h"

class dActor_c;

///< @unofficial
enum CC_SHAPE_e {
    CC_SHAPE_BOX,
    CC_SHAPE_CIRCLE,
    CC_SHAPE_DAIKEI_UD,
    CC_SHAPE_DAIKEI_LR,
};

///< @unofficial
enum CC_STATUS_FLAG_e {
    CC_STATUS_NONE = 0,
    CC_STATUS_NO_REVISION = 0_bit,
    CC_STATUS_NO_PASS_INFO = 2_bit,
};

///< @unofficial
enum CC_INFO_e {
    CC_NO_HIT = 1_bit,
};

///< @unofficial
enum CC_KIND_e {
    CC_KIND_PLAYER,
    CC_KIND_PLAYER_ATTACK,
    CC_KIND_YOSHI,
    CC_KIND_ENEMY,
    CC_KIND_BALLOON,
    CC_KIND_ITEM,
    CC_KIND_TAMA,
    CC_KIND_KILLER,
    CC_KIND_GOAL_POLE
};

///< @unofficial
enum CC_ATTACK_e {
    CC_ATTACK_NONE,
    CC_ATTACK_FIREBALL,
    CC_ATTACK_ICEBALL,
    CC_ATTACK_STAR,
    CC_ATTACK_ICE_BREAK,
    CC_ATTACK_SLIP,
    CC_ATTACK_KOOPA_FIRE,
    CC_ATTACK_HIP_ATTACK,
    CC_ATTACK_WIRE_NET,
    CC_ATTACK_SHELL,
    CC_ATTACK_PENGUIN_SLIDE,
    CC_ATTACK_SPIN,
    CC_ATTACK_UNK12,
    CC_ATTACK_SPIN_FALL,
    CC_ATTACK_FIRE_2,
    CC_ATTACK_YOSHI_EAT,
    CC_ATTACK_YOSHI_MOUTH,
    CC_ATTACK_CANNON,
    CC_ATTACK_SPIN_LIFT_UP,
    CC_ATTACK_YOSHI_BULLET,
    CC_ATTACK_YOSHI_FIRE,
    CC_ATTACK_ICE_2,
    CC_ATTACK_SAND_PILLAR
};

class dCc_c;

struct sCcDatNewF {
    mVec2_c mOffset;

    mVec2_c mSize;

    u8 mKind;
    u8 mAttack;

    u32 mVsKind;

    u32 mVsDamage;

    u16 mStatus;

    void (*mCallback)(dCc_c* self, dCc_c* target);
};

class dCc_c
{
    SIZE_ASSERT(0xA4);

    /* 0x00 VTABLE 0x803110F0 */

public:
    // Structors
    // ^^^^^^

    /* 0x8008C200 */
    dCc_c();

    /* VT+0x8 0x8008C260 */
    virtual ~dCc_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8008C330 */
    void entry();

    /* 0x8008C380 */
    void release();

    /* 0x8008C3E0 */
    void set(dActor_c* actor, sCcDatNewF* collInfo);

public:
    // Static Methods
    // ^^^^^^

    /* 0x8008C9E0 */
    static void execute();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c* mpOwner;
    /* 0x08 */ dActor_c* mFriendActor;
    /* 0x0C */ u32 m0x0C;

    /* 0x10 */ dCc_c* mpNext;
    /* 0x14 */ dCc_c* mpPrev;

    /* 0x18 */ u32 mCanBounce;

    /* 0x1C */ sCcDatNewF mCcData;

    /* 0x40 */ float mTrpOffsets[4];
    /* 0x50 */ float mCollOffsetX[8];
    /* 0x70 */ float mCollOffsetY[8];

    /* 0x90 */ mVec2_c mCollPos;

    /* 0x98 */ u16 mCollidedWith;
    /* 0x9A */ u16 mAttSent;
    /* 0x9C */ u16 mAttReceived;

    /* 0x9E */ u8 mShape;

    /* 0x9F */ u8 mAmiLine;

    /* 0xA0 */ u8 mLayer;

    /* 0xA1 */ u8 mInfo;

    /* 0xA2 */ bool mIsLinked;

    FILL(0xA3, 0xA4);

public:
    // Static Variables
    // ^^^^^^

    typedef bool (*hitCheck)(dCc_c*, dCc_c*);

    static hitCheck _hitCheck[4][4];

    static dCc_c* mEntryN; ///< The first collider in the list.
    static dCc_c* mEntryB; ///< The last collider in the list.
};
