#pragma once

#include "d_mj2d_game.h"
#include "m_vec.h"

class dActor_c;
class dPole_ctr_c;

class dPc_c {
public:
    // Structors
    // ^^^^^^

    dPc_c()
        : mCtr(nullptr) {}

    /* VT+0x8 */
    virtual ~dPc_c() {}

public:
    // Instance Methods
    // ^^^^^^

    void release();
    bool check(int);
    void set(dActor_c*, u8);
    void set(int);
    void chkTimer();

    /* 0x800D2360 */ short getAngle() const;

    mVec2_c getPos() { return mPos; }

    void move(float);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c*    mParent;
    /* 0x08 */ dPc_c*       mNext;
    /* 0x0C */ dPole_ctr_c* mCtr;
    /* 0x10 */ dPole_ctr_c* mCtr2;
    /* 0x14 */ mVec2_c      mPos;
    /* 0x1C */ float        m0x1C;
    /* 0x20 */ float        m0x20;
    /* 0x24 */ float        m0x24;
    FILL(0x28, 0x2A);
    /* 0x2A */ u8 m0x2A;
    FILL(0x2B, 0x2D);
    /* 0x2D */ u8      m0x2D;
    /* 0x2E */ u8      mAngIdx;
    /* 0x30 */ mVec3_c m0x30;
};

class dPole_ctr_c {
    SIZE_ASSERT(0x3D);

public:
    // Structors
    // ^^^^^^

    dPole_ctr_c() { init(); }

    /* VT+0x8 0x8082E2F0 (weak) */
    virtual ~dPole_ctr_c() { release(); }

    // Structors
    // ++++++

    dPole_ctr_c(
        short (&plrAngle)[PLAYER_COUNT]
    ) {
        init();
        mPlrAngle = plrAngle;
    }

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D2480 */ void init();
    /* 0x800D24A0 */ void entry();
    /* 0x800D24F0 */ void release();

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0xC 0x8082ECA0 (weak) */
    virtual short getAngle() { return 0; }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c*    mParent;
    /* 0x08 */ dPole_ctr_c* mPrev;
    /* 0x0C */ dPole_ctr_c* mNext;
    /* 0x10 */ dPc_c*       mPc;

    FILL(0x14, 0x1E);

    /* 0x1E */ short        m0x1E;
    /* 0x20 */ u8           mMode;
    /* 0x21 */ bool         mIsLink;
    /* 0x22 */ bool         m0x22;
    /* 0x23 */ u8           mFlags;
    /* 0x24 */ int          m0x24;
    /* 0x28 */ mVec3_c*     m0x28;
    /* 0x2C */ const float* mAngFlt;
    /* 0x30 */ short*       mAngle;

    union {
        /* 0x34 */ short  REMOVED(mPlrAngle)[4];
        /* 0x34 */ short* mPlrAngle;
    };

    /* 0x3C */ u8 mAngCount;
};

class dPoleRope_c : public dPole_ctr_c {
    SIZE_ASSERT(0x3D);

public:
    // Structors
    // ^^^^^^

    dPoleRope_c() {}

    /* VT+0x8 0x8082E350 (weak) */
    virtual ~dPoleRope_c() override {}

    // Structors
    // ++++++

    dPoleRope_c(
        short (&plrAngle)[PLAYER_COUNT]
    )
        : dPole_ctr_c(plrAngle) {}

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0xC 0x8082EC90 (weak) */
    virtual short getAngle() override { return mAngle[0]; }

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D2600 */ void calcLength();
    /* 0x800D2700 @unofficial */
    void init(
        dActor_c* parent, u8 count, mVec3_c* v0x28, const float* floats, short* angles, int mode,
        bool v0x22, u8 flags
    );
    /* 0x800D2780 */ void calc();
};
