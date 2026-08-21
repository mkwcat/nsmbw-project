// d_CourseSelectGuide.cpp
// NSMBW .text: 0x8000FC30 - 0x80014330

#include "d_CourseSelectGuide.h"

#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_game_common.h"
#include <algorithm>

[[nsmbw_data(0x80429EDC)]]
dCourseSelectGuide_c* dCourseSelectGuide_c::m_instance;

[[nsmbw(0x80010140)]]
dCourseSelectGuide_c::~dCourseSelectGuide_c() {
    m_instance = nullptr;
    if (mpExtra) {
        delete mpExtra;
        mpExtra = nullptr;
    }
    mLayout.~LytBase_c();
}

EXTERN_REPL(0x80010290, bool dCourseSelectGuide_c::createBaseLayout());

[[nsmbw(0x80010290)]]
bool dCourseSelectGuide_c::createLayout() {
    mpExtra = nullptr;

    if (!createBaseLayout()) {
        return false;
    }

    mpExtra = new Extra_s;

    mLayout.NPaneRegister(
        mpExtra->mpNExIconPos, //
        {
            "N_IconPos5P_00",
            "N_IconPos6P_00",
            "N_IconPos7P_00",
            "N_IconPos8P_00",
        }
    );
    mLayout.PPaneRegister(
        &mpExtra->mpPKinopicoFace, //
        {
            "P_kinopiFace_00",
            "P_player_05",
            "P_player_06",
            "P_player_07",
        }
    );
    mLayout.TPaneRegister(
        mpExtra->mpTExLifeNumber, //
        {
            "T_lifeNumber_04",
            "T_lifeNumber_05",
            "T_lifeNumber_06",
            "T_lifeNumber_07",
        }
    );

    PlayerIconDisp();
    RestNumberDisp();

    return true;
}

[[nsmbw(0x80010690)]]
void dCourseSelectGuide_c::PlayerIconDisp() {
    if (mpExtra == nullptr) {
        return;
    }

    mpPMarioFace->SetVisible(false);
    mpPLuigiFace->SetVisible(false);
    mpPYKinoFace->SetVisible(false);
    mpPBKinoFace->SetVisible(false);
    auto* extra = mpExtra;
    extra->mpPKinopicoFace->SetVisible(false);
    extra->mpPPurpleKinopicoFace->SetVisible(false);
    extra->mpPOKinoFace->SetVisible(false);
    extra->mpPBlKinoFace->SetVisible(false);

    std::size_t count = 0;
    for (std::size_t i = 0; i < PLAYER_COUNT && count < LytPlayerCount; i++) {
        if (!dGameCom::PlayerEnterCheck(i)) {
            continue;
        }

        int playerType = static_cast<int>(daPyMng_c::mPlayerType[i]);
        if (playerType >= LytPlayerCount) {
            continue;
        }

        nw4r::lyt::Picture* face = playerType < 4 ? (&mpPMarioFace)[playerType]
                                                  : (&mpExtra->mpPKinopicoFace)[playerType - 4];
        nw4r::lyt::Pane*    pos  = count < 4 ? mpNIconPos[count] : mpExtra->mpNExIconPos[count - 4];

        face->SetTranslate(pos->GetTranslate());
        face->SetVisible(true);
        count++;
    }

    std::size_t i;
    for (i = 0; i < 4; i++) {
        mpNIconPos[i]->SetVisible(false);
    }
    for (; i < LytPlayerCount; i++) {
        mpExtra->mpNExIconPos[i - 4]->SetVisible(false);
    }

    if (count > 0) {
        if (count <= 4) {
            mpNIconPos[count - 1]->SetVisible(true);
        } else {
            mpExtra->mpNExIconPos[count - 5]->SetVisible(true);
        }
    }
}

[[nsmbw(0x80010800)]]
void dCourseSelectGuide_c::RestNumberDisp() {
    if (mpExtra == nullptr) {
        return;
    }

    for (std::size_t i = 0; i < LytPlayerCount; i++) {
        s16 rest = daPyMng_c::mRest[static_cast<PLAYER_TYPE_e>(i)];
        if (rest != mStoredRestNumber[i]) {
            mStoredRestNumber[i] = rest;
            dGameCom::LayoutDispNumber(
                rest, 2, i < 4 ? mpTLifeNumber[i] : mpExtra->mpTExLifeNumber[i - 4], true
            );
        }
    }

    mRestDispNeeded = false;
}

[[nsmbw(0x800108C0)]]
void dCourseSelectGuide_c::RestAlphaDisp() {
    if (mpExtra == nullptr) {
        return;
    }

    if (mRestAlpha == mRestAlphaTarget) {
        return;
    }

    if (mRestAlphaTarget < mRestAlpha) {
        mRestAlpha = std::max<int>(mRestAlpha - 20, mRestAlphaTarget);
    } else {
        mRestAlpha = std::min<int>(mRestAlpha + 20, mRestAlphaTarget);
    }

    u8          alpha = mRestAlpha;
    std::size_t i;
    for (i = 0; i < 4; i++) {
        mpNIconPos[i]->SetAlpha(alpha);
        (&mpPMarioFace)[i]->SetAlpha(alpha);
    }

    Extra_s* extra = mpExtra;
    for (; i < LytPlayerCount; i++) {
        extra->mpNExIconPos[i - 4]->SetAlpha(alpha);
        (&extra->mpPKinopicoFace)[i - 4]->SetAlpha(alpha);
    }
}
