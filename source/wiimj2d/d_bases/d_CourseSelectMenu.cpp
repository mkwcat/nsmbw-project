// d_CourseSelectMenu.cpp
// NSMBW d_bases.text: 0x8077A750 - 0x8077BB00

#include "d_CourseSelectMenu.h"

#include "d_system/d_game_common.h"
#include "d_system/d_message.h"
#include <revolution/sc.h>

[[nsmbw(0x8077AA10)]]
fBase_c::PACK_RESULT_e dCourseSelectMenu_c::create() {
    if (m_created) {
        return PACK_RESULT_e::SUCCEEDED;
    }

    if (!createLayout()) {
        return PACK_RESULT_e::NOT_READY;
    }

    const bool wide = dGameCom::GetAspectRatio() == SCAspectRatio::WIDESCREEN;
    m_pBack->SetVisible(wide);
    m_pBackWhite->SetVisible(!wide);

    MsgRes_c* res = dMessage_c::getMesRes();
    m_tCourseSelectS->setMessage(res, 2, 4, 0);
    m_tCourseSelect->setMessage(res, 2, 4, 0);

    m_rootPane->SetVisible(false);
    mLayout.mPriority = 3;
    m_created         = true;
    m0x273 = m0x272 = m0x271 = false;

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x8077AB70)]]
bool dCourseSelectMenu_c::createLayout();
