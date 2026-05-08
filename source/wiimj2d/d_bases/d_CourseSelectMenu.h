#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "state/s_FStateFct.h"
#include "state/s_StateInterfaces.h"
#include "state/s_StateMethodUsr_FI.h"
#include "state/s_StateMgr.h"

class dCourseSelectMenu_c : public dBase_c {
    SIZE_ASSERT(0x278);

    /* 0x060 VTABLE 0x809415D8 */

public:
    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */
    sStateMgr_c<dCourseSelectMenu_c, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c> mStateMgr;

    FILL(0x244, 0x273);

    /* 0x273 */ u8 m0x273;

    FILL(0x274, 0x278);
};
