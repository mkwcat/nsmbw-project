#pragma once

#include "d_bases/d_MultiCourseSelect.h"
#include "d_system/d_scene.h"
#include "state/s_FStateFct.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"
#include "state/s_State.h"

class dMultiCourseSelect_c;

class dScMulti_c : public dScene_c
{
    SIZE_ASSERT(0x1DC);

public:
    // Structors
    // ^^^^^^

public:
    // Instance Methods
    // ^^^^^^

public:
    // Instance Variables
    // ^^^^^^

    /* 0x074 */ sStateMgr_c<dScMulti_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    FILL(0xB0, 0xBC);

    /* 0xBC */ dMultiCourseSelect_c *mpCourseSelect;

    FILL(0xC0, 0xD4);

    /* 0xD4 */ int m_D4;

    FILL(0xD8, 0x1DC);

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x809A17E0, dScMulti_c, SelectCourse);

    sState_Extern(0x809A1820, dScMulti_c, ReturnTitleFinalConfirm);
};