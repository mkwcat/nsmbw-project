#pragma once

#include <machine/m_vec.h>

class dPanelObjList_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x800145B0 */
    dPanelObjList_c();

    /* 0x800145F0 */
    ~dPanelObjList_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800146B0 */
    void setPos(float x, float y, float z);

    /* 0x800146D0 */
    void setScaleFoot(float scale);

    /* 0x800146F0 */
    void setScaleAngle(float scale, short angle);

    /* 0x80014710 */
    float getScale();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ dPanelObjList_c* mpPrev;
    /* 0x04 */ dPanelObjList_c* mpNext;
    /* 0x08 */ u16 mTileNumber;
    /* 0x0A */ u8 mType;
    /* 0x0B */ u8 mIsChange;
    /* 0x0C */ mVec3_c mPos;
    /* 0x18 */ float mScale;
    /* 0x1C */ s16 mAngle;
    /* 0x1E */ u8 mParts;
    /* 0x20 */ u32 m0x20;
};