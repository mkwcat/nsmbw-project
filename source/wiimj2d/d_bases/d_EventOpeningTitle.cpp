// d_EventOpeningTitle.cpp
// NSMBW d_bases.text: 0x80781980 - 0x80782AB0

#include "d_EventOpeningTitle.h"

#include "d_bases/d_s_restart_crsin.h"
#include "d_bases/d_s_stage.h"
#include "d_profile/d_profile.h"
#include "d_system/d_game_common.h"
#include "d_system/d_info.h"

[[nsmbw(0x80781D00)]]
bool dEventOpeningTitle_c::createLayout();

[[nsmbw(0x80781C50)]]
fBase_c::PACK_RESULT_e dEventOpeningTitle_c::create() {
    if (m_created) {
        return PACK_RESULT_e::SUCCEEDED;
    }

    if (!createLayout()) {
        return PACK_RESULT_e::NOT_READY;
    }
    m_visible = m_created = true;

    m_tE3VerCheck->SetVisible(true);
    m_rootPane->SetVisible(false);

    nw4r::math::VEC2 scale;
    dGameCom::DispSizeScale(scale);
    m_nProportionC->SetScale(scale);

    m_tE3VerCheck->SetString(L"mkwcat-nsmbw v0.6.0", 0);

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80782340)]]
void dEventOpeningTitle_c::executeState_PressButtonExitAnimeEndWait() {
    if (dScStage_c::m_gameMode == dScStage_c::GAME_MODE_e::UNKNOWN_2 && m_layout.isAnime()) {
        return;
    }

    if (dScStage_c::m_gameMode == dScStage_c::GAME_MODE_e::UNKNOWN_2) {
        return dScStage_c::setNextScene(
            dProf::GAME_SETUP, 0, dScStage_c::Exit_e(0), dFader_c::fader_type_e::UNKNOWN_5
        );
    }

    dInfo_c::clearGameFlag(dInfo_c::GameFlag_e::MULTI_MODE);
    dScRestartCrsin_c::startTitle(false, false);
}
