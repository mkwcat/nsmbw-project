#pragma once

#include "d_system/d_rc.h"
#include "egg/prim/eggBitFlag.h"

enum SensorFlags {
    SENSOR_IS_POINT = 0,
    SENSOR_IS_LINE = 1
};

struct sBcSensorBase {
    u32 mFlags;
};

class sBcPointData
{
public:
    u32 mFlags;
    int mOffsetX;
    int mOffsetY;
    int mDist;
};

/// @unofficial
struct sBcSensorPoint {
    operator const sBcSensorBase*() const
    {
        return &mBase;
    }

    sBcSensorBase mBase;
    int mX, mY;
};

/// @unofficial
struct sBcSensorLine {
    operator const sBcSensorBase*() const
    {
        return &mBase;
    }

    sBcSensorBase mBase;
    int mLineA, mLineB;
    int mDistanceFromCenter;
};

class dBg_ctr_c;

class dBc_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x8006CF40 */
    dBc_c();

    /* VT+0x08 */
    virtual ~dBc_c();

public:
    // Static Constants
    // ^^^^^^

    enum Flag_e {
        FLAG_0 = 0_bit,
        FLAG_1 = 1_bit,
        FLAG_2 = 2_bit,
        FLAG_3 = 3_bit,
        FLAG_4 = 4_bit,
        FLAG_5 = 5_bit,
        FLAG_6 = 6_bit,
        FLAG_7 = 7_bit,
        FLAG_8 = 8_bit,
        FLAG_9 = 9_bit,
        FLAG_10 = 10_bit,
        FLAG_11 = 11_bit,
        FLAG_12 = 12_bit,
        FLAG_13 = 13_bit,
        FLAG_14 = 14_bit,
        FLAG_15 = 15_bit,
        FLAG_16 = 16_bit,
        FLAG_17 = 17_bit,
        FLAG_18 = 18_bit,
        FLAG_19 = 19_bit,
        FLAG_20 = 20_bit,
        FLAG_21 = 21_bit,
        FLAG_22 = 22_bit,
        FLAG_23 = 23_bit,
        FLAG_24 = 24_bit,
        FLAG_25 = 25_bit,
        FLAG_26 = 26_bit,
        FLAG_27 = 27_bit,
        FLAG_28 = 28_bit,
        FLAG_29 = 29_bit,

        FLAG_WALL_R = FLAG_0 | FLAG_2 | FLAG_4,
        FLAG_WALL_L = FLAG_1 | FLAG_3 | FLAG_5,
        FLAG_FOOT = FLAG_13 | FLAG_14 | FLAG_15 | FLAG_16 | FLAG_14 | FLAG_15 | FLAG_16 | FLAG_17 |
                    FLAG_18 | FLAG_19 | FLAG_20,
        FLAG_HEAD = FLAG_26 | FLAG_27 | FLAG_28 | FLAG_29
    };

    enum WATER_TYPE_e {
        WATER_CHECK_NONE,
        WATER_CHECK_WATER,
        WATER_CHECK_WATER_BUBBLE,
        WATER_CHECK_YOGAN,
        WATER_CHECK_POISON
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8006d090 */
    void set(
      dActor_c*, const sBcSensorBase*, const sBcSensorBase*, const sBcSensorBase*
    ); ///< @unofficial

    /* 0x80075090 */
    void checkLink();

    /* 0x80070CA0 */
    bool checkRide();

    /* 0x8006EF40 */
    bool checkHead(u32);

    /* 0x800708C0 */
    s16 getSakaAngle(u8);

    /* 0x80070920 */
    int getSakaMoveAngle(u8);

    /* 0x8006FA40 */
    Flag_e checkWall(float*);

    /* 0x80072CB0 */
    Flag_e checkWallEnm(float*);

    /* 0x8006DB30 */
    Flag_e checkFoot();

    /* 0x80072BC0 */
    Flag_e checkFootEnm();

    /* 0x80070720 */
    u16 getFootAttr();

    bool hasSensorFoot()
    {
        return mpSensorFoot != nullptr;
    }

    bool hasSensorHead()
    {
        return mpSensorHead != nullptr;
    }

    bool hasSensorWall()
    {
        return mpSensorWall != nullptr;
    }

    u32 isWallR()
    {
        return mFlags & FLAG_WALL_R;
    }

    u32 isWallL()
    {
        return mFlags & FLAG_WALL_L;
    }

    u32 isFoot()
    {
        return mFlags & FLAG_FOOT;
    }

    u32 isHead()
    {
        return mFlags & FLAG_HEAD;
    }

    u32 isCollision()
    {
        return mFlags & (FLAG_WALL_L | FLAG_WALL_R | FLAG_FOOT | FLAG_HEAD);
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c* mpOwner;
    /* 0x08 */ sBcSensorBase* mpSensorFoot;
    /* 0x0C */ sBcSensorBase* mpSensorHead;
    /* 0x10 */ sBcSensorBase* mpSensorWall;
    /* 0x14 */ mVec3_c* mpOwnerPos;
    /* 0x18 */ mVec3_c* mpOwnerLastPos;
    /* 0x1C */ mVec3_c* mpOwnerSpeed;
    /* 0x20 */ mVec3_c mPushForce;
    /* 0x2C */ mVec2_c mOwnerPosDelta;
    /* 0x34 */ mVec2_c m0x34;
    /* 0x3C */ mVec2_c m0x3c;
    /* 0x44 */ float m0x44;
    /* 0x48 */ float m0x48;
    /* 0x4C */ float m0x4C;
    /* 0x50 */ dRc_c* mpRc;
    /* 0x54 */ dActor_c* mFriendActor;
    /* 0x58 */ dBg_ctr_c* mCollidedBelow;
    /* 0x5C */ dBg_ctr_c* mCollidedAbove;
    /* 0x60 */ dBg_ctr_c* mCollidedAdj;
    /* 0x64 */ dBg_ctr_c* mCollidedAdjForDirection[2];
    /* 0x6C */ dBc_c* mPrevTrigBelowSensor;
    /* 0x70 */ dBc_c* mPrevTrigAboveSensor;
    /* 0x74 */ dBc_c* mPrevTrigAdjSensor;
    /* 0x78 */ dBc_c* mPrevTrigAdjSensorForDirection[2];
    /* 0x80 */ dBg_ctr_c* mLinkW[2];
    /* 0x88 */ u32 mFlags;
    /* 0x8C */ u32 mPrevFlags;

    FILL(0x90, 0xE5);

    /* 0xE5 */ u8 mAmiLine;
    /* 0xE6 */ u8 m0xE6;
    /* 0xE7 */ u8 m0xE7;
    /* 0xE8 */ u8* mpLayer;
    /* 0xEC */ u8 mLayer;

public:
    // Static Methods
    // ^^^^^^

    /* 0x80076530 */
    static int checkWaterDepth(float, float, u8, u8, float*);

    /* 0x80075270 */
    static WATER_TYPE_e checkWater(float, float, u8, float*);

    /* 0x800709C0 */
    static u32 checkBg(float, float, u8, u8, unsigned long);

    /* 0x800767F0 */
    static u32 checkWireNet(float x, float y, unsigned char layer);

    /* 0x800757B0 */
    static u32 checkGround(const mVec3_c*, float*, u8, u8, signed char);

    /* 0x80075CA0 */
    static u32 checkTenjou(const mVec3_c*, float*, u8, u8);

    /* 0x80075FD0 */
    static u32 checkWall(const mVec3_c*, const mVec3_c*, float*, u8, u8, dActor_c**);
};
