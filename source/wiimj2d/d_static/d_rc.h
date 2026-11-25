#pragma once

#include "m_vec.h"

class dActor_c;
class dRide_ctr_c;
class dBc_c;

class dRc_c {
    SIZE_ASSERT(0x33);

public:
    /* VT+0x08 */
    virtual ~dRc_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D9BC0 */ void chkLink();

    /* 0x800D9A30 */ bool check(u32, u32, u32);

private:
    /* 0x800D9C70 */ bool _rideCheckNormal(dRide_ctr_c*, u32, u32, u32);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c*    mOwner;
    /* 0x08 */ mVec3_c*     mOwnerPos;
    /* 0x0C */ dRc_c*       mNext;
    /* 0x10 */ dRide_ctr_c* mRide[2];
    /* 0x18 */ dBc_c*       mBc;
    /* 0x1C */ float        m0x1C[4];
    /* 0x2C */ short        mRotation;
    /* 0x2E */ u8           mLineKind;
    /* 0x2F */ u8           mRideType;
    /* 0x30 */ u8           m0x30;
    /* 0x31 */ u8           m0x31;
    /* 0x32 */ u8           mLayer;

public:
    // Static Variables
    // ^^^^^^

private:
    /* 0x8042A2F0 */ static float        mSavePosY;
    /* 0x8042A2F4 */ static dRide_ctr_c* mRideLast;

    /* 0x80371B10 */ static bool (dRc_c::*_rideCheck)(dRide_ctr_c*, u32, u32, u32);
};

class dRide_ctr_c {
    SIZE_ASSERT(0x4C);

    /* 0x00 VTABLE 0x80319158 */

public:
    // Structors
    // ^^^^^^

    /* 0x800DAEA0 */
    dRide_ctr_c();

    /* VT+0x08 0x800DAEF0 */
    virtual ~dRide_ctr_c();

public:
    // Instance Methods
    // ^^^^^^

private:
    bool _rideCheckNormal(dRide_ctr_c*, u32, u32, u32);

    using _rideCheckFn = bool (dRide_ctr_c::*)(dRide_ctr_c*, u32, u32, u32);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c*    mOwner;
    /* 0x08 */ dRide_ctr_c* mNext;
    /* 0x0C */ dRide_ctr_c* mPrev;
    /* 0x10 */ dRc_c*       mChain;

    u8                      FILL(0x14, 0x4C);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A2FC */ static dRide_ctr_c* mEntryN;
    /* 0x8042A300 */ static dRide_ctr_c* mEntryB;
};

class dRideRoll_c : public dRide_ctr_c {
    SIZE_ASSERT(0x60);

public:
    // Structors
    // ^^^^^^

    dRideRoll_c();

    /* VT+0x08 */
    ~dRideRoll_c() override;

public:
    // Instance Variables
    // ^^^^^^

    u8 FILL(0x4C, 0x60);
};

class dRide2Point_c : public dRide_ctr_c {
    SIZE_ASSERT(0x5C);

public:
    // Structors
    // ^^^^^^

    /* 0x800DB540 */
    dRide2Point_c();

public:
    // Instance Variables
    // ^^^^^^

    u8 FILL(0x4C, 0x5C);
};
