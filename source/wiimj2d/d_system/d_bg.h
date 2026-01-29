#pragma once

#include "d_PanelObjMgr.h"

class dBg_c
{
    SIZE_ASSERT(0x90AAC);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80078520 */
    dPanelObjMgr_c* getPanelObjMgr(int idx);

    /* 0x800785E0 */
    bool UNDEF_800785E0();

    /* 0x8007BEF0 */
    void initScroll();

    bool isAutoscroll() const
    {
        return mIsAutoscroll;
    }

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00000, 0x00110);

    /* 0x00110 */ float m0x00110;
    /* 0x00114 */ u8 m0x00114;

    FILL(0x00115, 0x900C6);

    /* 0x900C6 */ bool mIsAutoscroll;

    FILL(0x900C7, 0x90AAC);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A0B0 */
    static dBg_c* m_bg_p;
};
