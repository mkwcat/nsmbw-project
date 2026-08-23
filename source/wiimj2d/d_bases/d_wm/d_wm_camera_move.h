#pragma once

#include "machine/m_vec.h"

class dWmCameraMove_c {
public:
    /* 0x00 */ mVec3_c mTarget;
    /* 0x0C */ mVec3_c mPos;
    /* 0x18 */ mVec3_c mPrevChange;
    /* 0x24 */ float   m0x24;
    /* 0x28 */ bool    mIsMove;
    /* 0x29 */ bool    m0x29;
    /* 0x2C */ mVec3_c mSpeed;
    /* 0x38 */ float   m0x38;
};
