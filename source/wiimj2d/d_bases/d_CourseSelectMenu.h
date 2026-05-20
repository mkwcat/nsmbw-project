#pragma once

#include "d_system/d_base.h"
#include "d_system/d_lytbase.h"
#include "nw4r/lyt/Picture.h"
#include "state/s_StateMgrDefault.h"

class dCourseSelectMenu_c : public dBase_c {
    SIZE_ASSERT(0x278);

    /* 0x060 VTABLE 0x809415D8 */

public:
    // Virtual Methods
    // ^^^^^^

    /* 0x8077AA10 */
    PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8077AB70 */
    bool createLayout();

public:
    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */
    sStateMgrDefault_c<dCourseSelectMenu_c> mStateMgr;

    /* 0x244 */ nw4r::lyt::Pane*            m_rootPane;
    /* 0x248 */ nw4r::lyt::Picture*         m_pSBBase[4];
    /* 0x258 */ nw4r::lyt::Picture*         m_pBack;
    /* 0x25C */ nw4r::lyt::Picture*         m_pBackWhite;
    /* 0x260 */ LytTextBox_c*               m_tCourseSelectS;
    /* 0x264 */ LytTextBox_c*               m_tCourseSelect;

    FILL(0x268, 0x270);

    /* 0x270 */ bool m_created;
    /* 0x271 */ bool m0x271;
    /* 0x272 */ bool m0x272;
    /* 0x273 */ bool m0x273;

    FILL(0x274, 0x278);
};
