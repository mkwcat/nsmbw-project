#pragma once

#include "machine/m_vec.h"

class dActor_c;
class dRide_ctr_c;
class dBc_c;

class dRc_c
{
    SIZE_ASSERT(0x33);

public:
    /* VT+0x08 */
    virtual ~dRc_c();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c* mpOwner;
    /* 0x08 */ mVec3_c* mpOwnerPos;
    /* 0x0C */ dRc_c* mpNext;
    /* 0x10 */ dRide_ctr_c* mpRide[2];
    /* 0x18 */ dBc_c *mpBc;
    /* 0x1C */ float m0x1C[4];
    /* 0x2C */ short mRotation;
    /* 0x2E */ u8 mLineKind;
    /* 0x2F */ u8 mRideType;
    /* 0x30 */ u8 m0x30;
    /* 0x31 */ u8 m0x31;
    /* 0x32 */ u8 mLayer;
};

class dRide_ctr_c
{
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
    // Instance Variables
    // ^^^^^^

    /* 0x04 */ dActor_c* mpOwner;
    /* 0x08 */ dRide_ctr_c* mpPrev;
    /* 0x0C */ dRide_ctr_c* mpNext;
    /* 0x10 */ dRc_c* mpChain;

    FILL(0x14, 0x4C);
};

class dRideRoll_c : public dRide_ctr_c
{
    SIZE_ASSERT(0x60);

public:
    // Structors
    // ^^^^^^

    dRideRoll_c();

    /* VT+0x08 */
    virtual ~dRideRoll_c() override;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4C, 0x60);
};

class dRide2Point_c : public dRide_ctr_c
{
    SIZE_ASSERT(0x5C);

public:
    // Structors
    // ^^^^^^

    /* 0x800DB540 */
    dRide2Point_c();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x4C, 0x5C);
};
