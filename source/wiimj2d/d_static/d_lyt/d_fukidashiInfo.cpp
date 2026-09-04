// d_fukidashiInfo.cpp
// NSMBW .text: 0x800B14E0 - 0x800B2D20

#include "d_fukidashiInfo.h"

#include "d_a_player_hio_ADJ.h"
#include "d_a_player_manager.h"
#include "d_gamerule.h"
#include "d_info.h"
#include "d_mj2d_game.h"
#include "d_pause_manager.h"
#include <nw4r/lyt/Material.h>
#include <nw4r/ut/Color.h>

[[nsmbw(0x800B1990)]]
void dfukidashiInfo_c::draw() {
    if (!mDispOn) {
        return;
    }
    switch (dGameRule_s::current.fukidashi_mode) {
    case dGameRule_s::FUKIDASHI_MODE_e::ALWAYS_SHOW:
        return mLayout.entry();
    case dGameRule_s::FUKIDASHI_MODE_e::HIDE_IF_5_TO_8_PLAYER:
        if (daPyMng_c::getNumInGame() < 5) {
            return mLayout.entry();
        }
        break;
    case dGameRule_s::FUKIDASHI_MODE_e::ALWAYS_HIDE:
        return;
    }
}

[[nsmbw(0x800B1A50)]]
void dfukidashiInfo_c::SetPosOffset(
    int plrColorType, int playerMode
) {
    const auto& hio = dPyStatic_HIO_c::get(static_cast<PLAYER_TYPE_e>(plrColorType));
    mPosOffset.x    = 0.0;
    mPosOffset.y    = hio.mFukidashiYOffset[playerMode];
    mPosOffset.z    = 0.0;
}

[[nsmbw(0x800B1BD0)]]
void dfukidashiInfo_c::ColorSet() {
    PLAYER_TYPE_e playerType = daPyMng_c::mPlayerType[mPlrNo];
    if (mAction == 8 && !PauseManager_c::m_OtasukeAfter) {
        playerType = PLAYER_TYPE_e::MARIO;
    }

    int             plrColorType = daPyMng_c::getPlayerColorType(playerType);

    const auto&     hio          = dPyStatic_HIO_c::get(static_cast<PLAYER_TYPE_e>(plrColorType));

    nw4r::ut::Color color1 = hio.mFukidashiColor[0], color2 = hio.mFukidashiColor[1],
                    color3 = hio.mFukidashiColor[2];

    auto setPictureColor   = [&](nw4r::lyt::Picture* picture) {
        for (int i = 0; i < 2; i++) {
            picture->SetVtxColor(i, color1);
        }
        for (int i = 2; i < 4; i++) {
            picture->SetVtxColor(i, color2);
        }
    };

    setPictureColor(mpAfterImgUD);
    setPictureColor(mpUpDownImg01);
    setPictureColor(mpAfterImgK);
    setPictureColor(mpKatamukiHand);

    nw4r::lyt::Material* material = mpArrow->GetMaterial();

    material->SetTevColor(1, color3);
}

[[nsmbw(0x800B2230)]]
void dfukidashiInfo_c::executeState_Move() {
    dInfo_c* info = dInfo_c::m_instance;
    if (m0x224 != 0) {
        m0x224 += m0x234;
    }
    if (m0x230 >= 0) {
        m0x224 = m0x230;
        m0x234 = -1;
    }
    if (mVisible) {
        m0x224 = 0;
    }
    if (mAction == 1 && dInfo_c::getStageNo() == StageNo_s{WORLD_e::WORLD_1, STAGE_e::STAGE_1}) {
        if (m0x230 < 0) {
            return;
        }
        m0x224 = 0;
    }
    if (m0x230 >= 0) {
        m0x230 = -1;
    }
    if (m0x224 == 0) {
        if (mAction == 1 && !mVisible) {
            info->setFukidashiHidePropeller(mPlrNo, true);
        }
        mStateMgr.changeState(StateID_Exit);
    }
}

[[nsmbw(0x800B2370)]]
void dfukidashiInfo_c::finalizeState_Move() {
    mLayout.AnimeEndSetup(m0x22C);

    if (mVisible == false) {
        return;
    }

    dInfo_c* info = dInfo_c::m_instance;
    if (dInfo_c::getStageNo() != StageNo_s{WORLD_e::WORLD_1, STAGE_e::STAGE_1}) {
        info->setFukidashiActionPerformed(mPlrNo, mAction, true);
    }
    if (isPerformForAllAction(mAction)) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            info->setFukidashiActionPerformed(i, mAction, true);
        }
    }

    mVisible = false;
}

[[nsmbw(0x800B24B0)]]
void dfukidashiInfo_c::finalizeState_Exit() {
    if (dInfo_c::getStageNo() == StageNo_s{WORLD_e::WORLD_1, STAGE_e::STAGE_1} || m0x230 >= 0) {
        dInfo_c::m_instance->setFukidashiHidePropeller(mPlrNo, false);
    }

    m0x234  = 0;
    mDispOn = false;
    mLayout.AllAnimeEndSetup();
    mpPane->SetVisible(false);
}
