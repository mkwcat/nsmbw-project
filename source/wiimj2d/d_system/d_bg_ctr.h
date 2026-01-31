#pragma once

#include "d_system/d_bc.h"
#include "machine/m_vec.h"

typedef void (*callbackF)(dActor_c* self, dActor_c* other);
typedef void (*callbackH)(dActor_c* self, dActor_c* other);
typedef void (*callbackW)(dActor_c* self, dActor_c* other, u8 direction);

typedef bool (*checkF)(dActor_c* self, dActor_c* other);
typedef bool (*checkH)(dActor_c* self, dActor_c* other);
typedef bool (*checkW)(dActor_c* self, dActor_c* other, u8 direction);

struct sBgSetInfo {
    /* 0x00 */ mVec2_c mLeftTop;
    /* 0x08 */ mVec2_c mRightBottom;
    /* 0x10 */ callbackF mBelowCallback;
    /* 0x14 */ callbackH mAboveCallback;
    /* 0x18 */ callbackW mAdjCallback;
};

class dBg_ctr_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x8007F7A0 */
    dBg_ctr_c();

    /* 0x8007F810 */
    ~dBg_ctr_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8007F900 */
    void entry();

    /* 0x8007F950 */
    void release();

    /* 0x8007FDA0 */
    void calc();

    /* 0x8007F9B0 */
    void set_common(dActor_c*, callbackF, callbackH, callbackW, u8, u8);

    /* 0x8007FA40 */
    void
    set(dActor_c*, float, float, float, float, callbackF, callbackH, callbackW, u8, u8, mVec3_c*);

    /* 0x8007FAD0 */
    void set(dActor_c*, mVec2_c, mVec2_c, callbackF, callbackH, callbackW, u8, u8, mVec3_c*);

    /* 0x8007FB10 */
    void set(dActor_c*, const sBgSetInfo*, u8, u8, mVec3_c*);

    /* 0x8007FB80 */
    void set_circle(dActor_c*, float, float, float, callbackF, callbackH, callbackW, u8, u8);

    /* 0x8007FD80 */
    void setAngleY3(short*);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ dActor_c* mpOwner;

    /* 0x04 */ dBg_ctr_c* mpNext;
    /* 0x08 */ dBg_ctr_c* mpPrev;

    /* 0x0C */ dBc_c* mpTriggeredBelowSensor;
    /* 0x10 */ dBc_c* mpTriggeredAboveSensor;
    /* 0x14 */ dBc_c* mpTriggeredAdjSensor;
    /* 0x18 */ dBc_c* mpTriggeredPlayerFenceSensors[4];
    /* 0x28 */ dBc_c* mpTriggeredPlayerWallSlideSensors[4];

    /* 0x38 */ dActor_c* mpCarryingActor;

    /* 0x3C */ u32 mIsCalced;

    /* 0x40 */ checkF mBelowCheckFunc;
    /* 0x44 */ checkH mAboveCheckFunc;
    /* 0x48 */ checkW mAdjCheckFunc;

    /* 0x4C */ callbackF mBelowCallback;
    /* 0x50 */ callbackH mAboveCallback;
    /* 0x54 */ callbackW mAdjCallback;

    /* 0x58 */ mVec2_c mLastPos;
    /* 0x60 */ mVec2_c mCalcedPos[4];

    /* 0x80 */ float mOffsetLeft;
    /* 0x84 */ float mOffsetTop;
    /* 0x88 */ float mOffsetRight;
    /* 0x8C */ float mOffsetBottom;

    /* 0x90 */ float mRadius;

    /* 0x94 */ mVec3_c mOwnerPos;
    /* 0xA0 */ mVec2_c mDiagonalSize;
    /* 0xA8 */ mVec2_c mPrevDiagonalSize;
    /* 0xB0 */ mVec3_c mDisplacement;

    /* 0xBC */ s16* mRotationPtr;
    /* 0xC0 */ s16 mRotation;
    /* 0xC2 */ s16 mRotationDelta;
    /* 0xC4 */ s16 mRotationDelta2;

    /* 0xC8 */ u32 mIsRound;
    /* 0xCC */ u32 m0xCC;
    /* 0xD0 */ u32 mFlags;
    /* 0xD4 */ s32 m0xD4;
    /* 0xD8 */ u32 m0xD8;

    /* 0xDC */ bool mLinked;

    /* 0xDD */ u8 mChainlinkMode;
    /* 0xDE */ u8 mLayer;

    /* 0xE0 */ s32 mId;

public:
    // Static Methods
    // ^^^^^^

    /* 0x80080630 */
    static void updateObjBg();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A0C0 */
    static dBg_ctr_c* mEntryN;

    /* 0x8042A0C4 */
    static dBg_ctr_c* mEntryB;
};
