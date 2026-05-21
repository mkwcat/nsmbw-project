#pragma once

#include "d_system/d_mj2d_game.h"
#include "machine/m_vec.h"

class dCyuukan_c {
    SIZE_ASSERT(0x34);

public:
    // Structors
    // ^^^^^^

    /* 0x8008ED70 */
    dCyuukan_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8008EDB0 */
    void clear();

    /* 0x8008EE00 */
    void courseIN();

    /* 0x8008EEC0 */
    bool checkEntry();

    /* 0x8008F000 @renamed */
    bool isCyuukanStart(int index, WORLD_e world, STAGE_e stage);

    /* 0x8008F070 */
    s8 getPlrNo(int index) const;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x04);

    /* 0x04 */ int           mIndex;
    /* 0x08 */ mVec3_c       mPlayerSetPos;
    /* 0x14 */ u32           mFlags;
    /* 0x18 */ WORLD_e       mWorld;
    /* 0x19 */ STAGE_e       mStage;
    /* 0x1A */ u8            mCourse; // A.k.a. Area
    /* 0x1B */ u8            mNextGoto;
    /* 0x1C */ bool          mIsKinopioInChukan;
    /* 0x20 */ PLAYER_TYPE_e mCollectionCoin[3];
    /* 0x2C */ PLAYER_TYPE_e mOwner[2];

public:
    // Constants
    // ^^^^^^

    enum : u32 {
        FLAG_FACE_LEFT = 0_bit,
    };
};
