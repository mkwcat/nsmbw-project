#pragma once

#include "d_static/d_base.h"

class dPanelObjMgr_c;

class dBg_c : public dBase_c {
    SIZE_ASSERT(0x90AAC);

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80077520 */
    u16* UNDEF_80077520(u16, u16, u8, int*, bool);

    /* 0x80077860 */
    void BgUnitChange(u16, u16, int, u16);

    /* 0x80078520 */
    dPanelObjMgr_c* getPanelObjMgr(int idx);

    /* 0x800785E0 */
    bool UNDEF_800785E0();

    /* 0x8007BEF0 */
    void initScroll();

    bool isAutoscroll() const { return mIsAutoscroll; }

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00070, 0x900C6);

    /* 0x900C6 */ bool mIsAutoscroll;

    FILL(0x900C7, 0x90110);

    /* 0x90110 */ float m0x90110;
    /* 0x90114 */ u8    m0x90114;

    FILL(0x90115, 0x90AAC);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A0B0 */
    static dBg_c* m_bg_p;
};
