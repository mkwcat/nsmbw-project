// d_NumberOfPeopleChange.cpp
// NSMBW d_bases.text: 0x8079F630 - 0x807A2CF0

#include "d_NumberOfPeopleChange.h"

#include "d_bases/d_CharacterChangeIndicator.h"
#include "d_bases/d_CharacterChangeSelectArrow.h"
#include "d_bases/d_CharacterChangeSelectBase.h"
#include "d_bases/d_CharacterChangeSelectContents.h"
#include "d_bases/d_a_wm_2DPlayer.h"
#include "d_player/d_WarningManager.h"
#include "d_profile/d_profile.h"
#include "d_static/d_a_player_manager.h"
#include "d_static/d_game_common.h"
#include "d_static/d_game_key.h"
#include "d_static/d_game_key_core.h"
#include "d_static/d_info.h"
#include "d_static/d_message.h"
#include "d_static/d_mj2d_game.h"
#include "d_static/d_remocon_mng.h"
#include "d_static/d_scene.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"

static const float l_2d_player_offset = 50.0f;

[[nsmbw(0x8079F630)]]
fBase_c* dNumberOfPeopleChange_c_classInit() {
    return new dNumberOfPeopleChange_c();
}

[[nsmbw(0x8079F660)]]
dNumberOfPeopleChange_c::dNumberOfPeopleChange_c() {}

EXTERN_SYMBOL(0x8079F780, "__dt__33sFState_c<23dNumberOfPeopleChange_c>Fv");
EXTERN_SYMBOL(0x8079F7C0, "__dt__36sFStateFct_c<23dNumberOfPeopleChange_c>Fv");
EXTERN_SYMBOL(
    0x8079F800,
    "__dt__89sStateMgr_c<23dNumberOfPeopleChange_c,20sStateMethodUsr_FI_c,12sFStateFct_c,"
    "13sStateIDChk_c>Fv"
);
EXTERN_SYMBOL(
    0x8079F860, "__dt__59sFStateMgr_c<23dNumberOfPeopleChange_c,20sStateMethodUsr_FI_c>Fv"
);

[[nsmbw(0x8079F8D0)]]
dNumberOfPeopleChange_c::~dNumberOfPeopleChange_c() {
    // [clang-dt-m-bug]
    mLayout.~LytBase_c();
    mBaseLytRes.~ResAccMultLoader_c();
    mContentsLytRes.~ResAccMultLoader_c();
    mArrowLytRes.~ResAccMultLoader_c();
    mIndicatorLytRes.~ResAccMultLoader_c();
}

[[nsmbw(0x8079F990)]]
fBase_c::PACK_RESULT_e dNumberOfPeopleChange_c::create() {
    if (mReady) {
        return PACK_RESULT_e::SUCCEEDED;
    }

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        if (!mpCcSelBase[cc] || !mpCcSelContents[cc] || !mpCcSelArrow[cc] || !mpCcIndicator[cc]) {
            return PACK_RESULT_e::NOT_READY;
        }
    }

    if (!mIndicatorLytResReady) {
        if (!mIndicatorLytRes.request(
                "Layout/characterChangeIndicator/characterChangeIndicator.arc"
            )) {
            return PACK_RESULT_e::NOT_READY;
        }
        for (std::size_t cc = 0; cc < mCcCount; cc++) {
            mpCcIndicator[cc]->mLayout.setResAccessor(&mIndicatorLytRes);
        }
    }
    if (!mBaseLytResReady) {
        if (!mBaseLytRes.request("Layout/charaChangeSelectBase/charaChangeSelectBase.arc")) {
            return PACK_RESULT_e::NOT_READY;
        }
        for (std::size_t cc = 0; cc < mCcCount; cc++) {
            mpCcSelBase[cc]->mLayout.setResAccessor(&mBaseLytRes);
        }
    }
    if (!mContentsLytResReady) {
        if (!mContentsLytRes.request(
                "Layout/charaChangeSelectContents/charaChangeSelectContents.arc"
            )) {
            return PACK_RESULT_e::NOT_READY;
        }
        for (std::size_t cc = 0; cc < mCcCount; cc++) {
            mpCcSelContents[cc]->mLayout.setResAccessor(&mContentsLytRes);
        }
    }
    if (!mArrowLytResReady) {
        if (!mArrowLytRes.request("Layout/charaChangeSelectArrow/charaChangeSelectArrow.arc")) {
            return PACK_RESULT_e::NOT_READY;
        }
        for (std::size_t cc = 0; cc < mCcCount; cc++) {
            mpCcSelArrow[cc]->mLayout.setResAccessor(&mArrowLytRes);
        }
    }

    if (!createLayout()) {
        return PACK_RESULT_e::NOT_READY;
    }

    MsgRes_c* msgRes = dMessage_c::getMesRes();

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        mPlyPlrBaseIndex[cc] = 10;
    }
    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        mCcPlrBaseIndex[ply] = 10;
    }

    mpPBase[0]->SetVisible(true);
    mpPBase[1]->SetVisible(true);
    mpPBase[2]->SetVisible(false);

    if (dScene_c::m_nowScene == dProf::WORLD_MAP) {
        mpTGuideS->setMessage(msgRes, 2, 14, 0);
        if (dGameCom::GetAspectRatio() == SCAspectRatio::STANDARD) {
            mpPBase[0]->SetVisible(false);
            mpPBase[1]->SetVisible(false);
            mpPBase[2]->SetVisible(true);
        }
    } else {
        mpTGuideS->setMessage(msgRes, 2, 29, 0);
    }

    m0x68C = 0;
    mpRootPane->SetVisible(false);
    mReady           = true;
    m0x67E           = false;
    mEasyPairingWait = false;
    mCancelAllowed   = false;
    mPlayerCount     = MAX_CC_COUNT;

    for (std::size_t connect = 0; connect < PLAYER_COUNT; connect++) {
        mConnectPlrNo[connect] = -2;
    }
    for (std::size_t cc = 0; cc < std::size(mSetupPlayers); cc++) {
        mSetupPlayers[cc] = -1;
    }

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x8079FCD0)]]
bool dNumberOfPeopleChange_c::createLayout() {
    if (!mLayout.ReadResource("characterChange/characterChange.arc", false)) {
        return false;
    }

    mLayout.build("characterChange_70.brlyt");

    enum {
        inWindow,
        inYesNoButtons,
        onYesNoButtons,
        idleYesNoButtons,
        hitYesNoButtons,
        offYesNoButtons,
        outWindow,
        outWindowInCourseSelectMenu,
    };

    mLayout.AnimeResRegister({
        "characterChange_70_inWindow.brlan",
        "characterChange_70_inYesNoButtons.brlan",
        "characterChange_70_onYesNoButtons.brlan",
        "characterChange_70_idleYesNoButtons.brlan",
        "characterChange_70_hitYesNoButtons.brlan",
        "characterChange_70_offYesNoButtons.brlan",
        "characterChange_70_outWindow.brlan",
        "characterChange_70_outWindowInCourseSelectMenu.brlan",
    });

    mLayout.GroupRegister({
        {"A00_Window", inWindow},
        {"D00_guide", inWindow},
        {"C00_yesButton", inYesNoButtons},
        {"C01_noButton", inYesNoButtons},
        {"D00_guide", inYesNoButtons},
        {"D00_guide", inYesNoButtons},
        {"C00_yesButton", onYesNoButtons},
        {"C01_noButton", onYesNoButtons},
        {"C00_yesButton", idleYesNoButtons},
        {"C01_noButton", idleYesNoButtons},
        {"C00_yesButton", hitYesNoButtons},
        {"C01_noButton", hitYesNoButtons},
        {"C00_yesButton", offYesNoButtons},
        {"C01_noButton", offYesNoButtons},
        {"A00_Window", outWindow},
        {"D00_guide", outWindow},
        {"A00_Window", outWindowInCourseSelectMenu},
        {"D00_guide", outWindowInCourseSelectMenu},
    });

    mpRootPane = mLayout.getRootPane();

    mLayout.NPaneRegister(
        mpNPlayerBasePos, //
        {
            "N_pos1P_00",
            "N_pos2P_00",
            "N_pos3P_00",
            "N_pos4P_00",
            "N_pos1P_01",
            "N_pos2P_01",
            "N_pos3P_01",
            "N_pos1P_02",
            "N_pos2P_02",
            "N_pos2P_01",
        }
    );

    mLayout.TPaneNameRegister(
        2, //
        {
            {"T_guide_01", 11},
            {"T_yes_00", 25},
            {"T_yes_01", 25},
            {"T_no_01", 26},
            {"T_no_00", 26},
            {"T_titleNinzuMenu", 27},
        }
    );

    mLayout.TPaneRegister(
        &mpTTitleNinzuMenu, //
        {
            "T_titleNinzuMenu",
            "T_titleNinzu_00",
            "T_guide_01",
            "T_guideS_02",
        }
    );

    mLayout.PPaneRegister(
        mpPYesNoBase, //
        {
            "P_yesBase_00",
            "P_noBase_00",
            "P_bgShadowST_00",
            "P_bgST_00",
            "P_stripeMLT_00",
            "P_remo1P_Light",
            "P_remo2P_Light",
            "P_remo3P_Light",
            "P_remo4P_Light",
            "P_base_00",
            "P_base_01",
            "P_base01_Menu43",
        }
    );

    mLayout.WPaneRegister(
        mpWButton, //
        {
            "W_button_00",
            "W_button_00",
        }
    );

    mLayout.mPriority = 10;

    return true;
}

[[nsmbw(0x8079FE40)]]
fBase_c::PACK_RESULT_e dNumberOfPeopleChange_c::preExecute();

[[nsmbw(0x8079FEA0)]]
fBase_c::PACK_RESULT_e dNumberOfPeopleChange_c::execute();

[[nsmbw(0x8079FF90)]]
fBase_c::PACK_RESULT_e dNumberOfPeopleChange_c::draw();

[[nsmbw(0x8079FFD0)]]
fBase_c::PACK_RESULT_e dNumberOfPeopleChange_c::doDelete();

std::size_t dNumberOfPeopleChange_c::getCcFromPly(
    std::size_t ply
) const {
    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        if (mpCcSelBase[cc]->mPlayerNo == ply) {
            return cc;
        }
    }
    return mCcCount;
}

[[nsmbw(0x807A0060)]]
void dNumberOfPeopleChange_c::setCcAnimFrame() {
    float frame = 0.0f;
    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        float f = mpCcIndicator[cc]->mLayout.isAnime(inWindow_Window)
                      ? mpCcIndicator[cc]->mLayout.mpAnmGroups[0].mpFrameCtrl->m0x08
                      : -1.0f;

        if (f >= 0.0f) {
            frame = f;
            break;
        }
    }

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        mpCcSelBase[cc]->m0x2EC     = frame;
        mpCcSelContents[cc]->m0x2B4 = frame;
    }
}

[[nsmbw(0x807A0170)]]
void dNumberOfPeopleChange_c::setCcLytPosition() {
    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        std::size_t posIndex = mCcPlrBaseIndex[cc];
        if (posIndex == std::size(mpNPlayerBasePos)) {
            continue;
        }

        const nw4r::math::MTX34& mtx   = mpNPlayerBasePos[posIndex]->GetGlobalMtx();
        mVec3_c                  pos   = {mtx[0][3], mtx[1][3], 0.0f};
        mVec2_c                  scale = {mtx[0][0], mtx[1][1]};
        if (mPlayerCount > 4) {
            scale *= 0.8f;
        }

        if (mPlayerCount <= 4) {
            pos.y += 107.0f;
        } else if (!isBottomIndex(cc)) {
            pos.y += 195.0f;
        } else {
            pos.y += 40.0f;
        }

        dCharacterChangeSelectBase_c*     base      = mpCcSelBase[cc];
        dCharacterChangeSelectContents_c* contents  = mpCcSelContents[cc];
        dCharacterChangeSelectArrow_c*    arrow     = mpCcSelArrow[cc];
        dCharacterChangeIndicator_c*      indicator = mpCcIndicator[cc];

        base->mpRootPane->SetTranslate(pos);
        if (mPlayerCount > 4) {
            base->mpRootPane->SetScale({0.8f, 0.8f});
        } else {
            base->mpRootPane->SetScale({1.0f, 1.0f});
        }
        arrow->mp0x244->SetTranslate(pos);
        indicator->mpRootPane->SetTranslate(pos);
        indicator->mpRootPane->SetScale(scale);

        const nw4r::math::MTX34& mtx2   = base->mp0x270->GetGlobalMtx();
        const nw4r::math::MTX34& mtx3   = base->mp0x268->GetGlobalMtx();
        mVec3_c                  pos2   = {mtx2[0][3], mtx2[1][3], 0.0f};
        mVec2_c                  scale3 = {mtx3[0][0], mtx3[1][1]};

        contents->mpaSelectConPane[1]->SetTranslate(pos2);
        contents->mpaSelectConPane[1]->SetScale(scale3);

        const nw4r::math::MTX34& mtx4 = base->mp0x26C->GetGlobalMtx();
        mVec3_c                  pos4 = {mtx4[0][3], mtx4[1][3], 0.0f};

        contents->mpaSelectConPane[0]->SetTranslate(pos4);
        contents->mpaSelectConPane[0]->SetScale(scale3);

        arrow->mp0x244->SetScale(scale3);
    }
}

[[nsmbw(0x807A0440)]]
void dNumberOfPeopleChange_c::set2dPlyPosition() {
    if (dScene_c::m_nowScene != dProf::WORLD_MAP) {
        mVec3_c                  pos      = mVec3_c::Zero;
        mVec3_c                  scale    = mVec3_c::Zero;
        const nw4r::math::MTX34& mtx      = mpNPlayerBasePos[mPlyPlrBaseIndex[0]]->GetGlobalMtx();
        pos.x                             = mtx[0][3];
        pos.y                             = mtx[1][3];
        pos                               = dGameCom::ScalePosForAspectRatio(pos);
        const nw4r::math::VEC2& paneScale = mpNPlayerBasePos[mPlyPlrBaseIndex[0]]->GetScale();
        scale.x                           = paneScale.x;
        scale.y                           = paneScale.y;
        for (std::size_t i = 0; i < CHARACTER_COUNT; i++) {
            PLAYER_TYPE_e type     = static_cast<PLAYER_TYPE_e>(i);
            mp2DPlayer[type]->mPos = {mp2DPlayer[type]->mPos.x, pos.y, mp2DPlayer[type]->mPos.z};
            mp2DPlayer[type]->mBaseScale = scale;
            mp2DPlayer[type]->mAddY      = l_2d_player_offset;
        }
        return;
    }

    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        if (mPlyDecidedPlayerType[ply] < PLAYER_TYPE_e::MARIO ||
            mPlyConnectStage[ply] != dInfo_c::PlyConnectStage_e::ENTER) {
            continue;
        }

        mVec3_c pos   = mVec3_c::Zero;
        mVec3_c scale = mVec3_c::Zero;
        if (mPlyPlrBaseIndex[ply] != std::size(mpNPlayerBasePos)) {
            const nw4r::math::MTX34& mtx = mpNPlayerBasePos[mPlyPlrBaseIndex[ply]]->GetGlobalMtx();
            pos.x                        = mtx[0][3];
            pos.y                        = mtx[1][3];
            pos                          = dGameCom::ScalePosForAspectRatio(pos);
            const nw4r::math::VEC2& paneScale = mpNPlayerBasePos[mPlyPlrBaseIndex[ply]]->GetScale();
            scale.x                           = paneScale.x;
            scale.y                           = paneScale.y;
            scale.z                           = 1.0f;
        }
        PLAYER_TYPE_e type           = mPlyDecidedPlayerType[ply];
        mp2DPlayer[type]->mPos       = pos;
        mp2DPlayer[type]->mBaseScale = scale;
        mp2DPlayer[type]->mAddY      = l_2d_player_offset;
    }
}

[[nsmbw(0x807A07C0)]]
void dNumberOfPeopleChange_c::disableInactiveControllers() {
    dRemoconMng_c* remoconMng = dRemoconMng_c::m_instance;
    dInfo_c*       info       = dInfo_c::m_instance;

    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        if (mPlyConnectStage[ply] == dInfo_c::PlyConnectStage_e::ENTER) {
            remoconMng->mpConnect[ply]->setAllowConnect(true);
            info->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::ENTER);
        } else {
            remoconMng->mpConnect[ply]->setAllowConnect(false);
        }
    }
}

[[nsmbw(0x807A0870)]]
void dNumberOfPeopleChange_c::checkRemoConnect() {
    dRemoconMng_c* remocons = dRemoconMng_c::m_instance;
    dInfo_c*       info     = dInfo_c::m_instance;
    for (std::size_t connect = 0; connect < REMOCON_CONNECT_COUNT; connect++) {
        dRemoconMng_c::dConnect_c* pConnect = remocons->mpConnectAll[connect];
        int                        ply      = pConnect->getPlayerNo();
        if (ply == mConnectPlrNo[connect]) {
            continue;
        }

        std::size_t channel = pConnect->getCoreChannel();
        if (nw4r::lyt::Picture* remoLight = getControllerLight(channel)) {
            remoLight->SetVisible(ply >= 0);
        }

        if (ply >= 0 && info->getPlyConnectStage(ply) < dInfo_c::PlyConnectStage_e::SETUP) {
            info->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::SETUP);
        } else if (ply < 0 && mAllowControllerCut) {
            info->setPlyConnectStage(mConnectPlrNo[connect], dInfo_c::PlyConnectStage_e::OFF);
        }

        mConnectPlrNo[connect] = ply;
    }
}

[[nsmbw(0x807A09B0)]]
int dNumberOfPeopleChange_c::getBaseForPlayerCount(int playerCount, int player) const;

[[nsmbw(0x807A09D0)]]
void dNumberOfPeopleChange_c::calcBasesForPlayerCount() {
    int playerCount = mPlayerCount;

    // Cap the player count to 4 currently
    // TODO
    if (playerCount > 4) {
        playerCount = 4;
    }

    for (std::size_t i = 0; i < mCcCount; i++) {
        mCcPlrBaseIndex[i] = mPlyPlrBaseIndex[i] = getBaseForPlayerCount(playerCount - 1, i % 4);
    }
}

[[nsmbw(0x807A0A50)]]
void dNumberOfPeopleChange_c::setPlayerSelectPos() {
    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        mVec3_c pos = mVec3_c::Zero;
        if (mCcPlrBaseIndex[cc] != std::size(mpNPlayerBasePos)) {
            const nw4r::math::MTX34& mtx = mpNPlayerBasePos[mCcPlrBaseIndex[cc]]->GetGlobalMtx();
            pos.x                        = mtx[0][3];
            pos.y                        = mtx[1][3];
            pos                          = dGameCom::ScalePosForAspectRatio(pos);
        }

        if (mPlayerCount > 4) {
            if (!isBottomIndex(cc)) {
                pos.y += 100.0f;
            } else {
                pos.y -= 54.0f;
            }
        }

        for (std::size_t i = 0; i < std::size(mpCcSelBase[cc]->mAllBasePos); i++) {
            mpCcSelBase[cc]->mAllBasePos[i] = pos;
        }
    }
}

[[nsmbw(0x807A0BF0)]]
void dNumberOfPeopleChange_c::setupPlayerTypes() {
    bool typeActive[PLAYER_COUNT] = {};

    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        if (mPlyConnectStage[ply] == dInfo_c::PlyConnectStage_e::ENTER) {
            daPyMng_c::mPlayerType[ply] = mPlyDecidedPlayerType[ply];
            typeActive[static_cast<std::size_t>(daPyMng_c::mPlayerType[ply])] = true;
        }
    }

    // All indices need to have a unique player type, regardless of whether that player type is even
    // used
    for (std::size_t type = 0, ply = 0; type < CHARACTER_COUNT; type++) {
        if (typeActive[type]) {
            continue;
        }

        // Find the next unused player index
        while (mPlyConnectStage[ply] == dInfo_c::PlyConnectStage_e::ENTER) {
            ply++;
        }

        daPyMng_c::mPlayerType[ply++] = static_cast<PLAYER_TYPE_e>(type);
    }
}

[[nsmbw(0x807A0D20)]]
bool dNumberOfPeopleChange_c::checkCancel() {
    bool p1Active = mpCcSelBase[0]->mDecided;

    if (dScene_c::m_nowScene == dProf::WORLD_MAP) {
        if (!p1Active) {
            // We can't allow the player to cancel when player 1 isn't even registered
            return false;
        }

        return dGameKey_c::getCurrentCore()->checkMenuConfirm() != 0;
    }

    // But here the cancel button is 1, and we prioritize player 1 cancelling over leaving the whole
    // menu
    if (p1Active) {
        return false;
    }

    return dGameCom::chkCancelButton(0);
}

void dNumberOfPeopleChange_c::setEasyPairingWait(
    bool enable
) {
    mEasyPairingWait = enable;
    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        mpCcSelBase[cc]->mEasyPairingWait     = enable;
        mpCcSelContents[cc]->mEasyPairingWait = enable;
    }
    for (std::size_t i = 0; i < CHARACTER_COUNT; i++) {
        PLAYER_TYPE_e type                 = static_cast<PLAYER_TYPE_e>(i);
        mp2DPlayer[type]->mEasyPairingWait = enable;
    }
}

[[nsmbw(0x807A0DA0)]]
void dNumberOfPeopleChange_c::initializeState_InitialSetup() {
    mExiting = mAllowControllerCut = false;
}

[[nsmbw(0x807A0DB0)]]
void dNumberOfPeopleChange_c::executeState_InitialSetup() {
    dInfo_c* info = dInfo_c::m_instance;

    if (!!(info->mGameFlag & dInfo_c::GameFlag_e::MULTI_MODE)) {
        info->PlayerStateInit();
    }
    info->m0xAFC = true;

    mEnterCount  = 0;
    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        mPlyDecidedPlayerType[ply] = mCcDecidedPlayerType[ply] = daPyMng_c::mPlayerType[ply];
        if ((mPlyConnectStage[ply] = info->getPlyConnectStage(ply)) ==
            dInfo_c::PlyConnectStage_e::ENTER) {
            mEnterCount++;
        }
    }
    calcBasesForPlayerCount();

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        dCharacterChangeSelectBase_c*     base      = mpCcSelBase[cc];
        dCharacterChangeSelectContents_c* contents  = mpCcSelContents[cc];
        dCharacterChangeSelectArrow_c*    arrow     = mpCcSelArrow[cc];
        dCharacterChangeIndicator_c*      indicator = mpCcIndicator[cc];

        base->mpNumPyConnectStage                   = mPlyConnectStage;
        base->mpNumPyEnterCount                     = &mEnterCount;
        base->mpCcSelContents                       = contents;
        base->mpCcSelArrow                          = arrow;
        base->mpCcIndicator                         = indicator;
        base->mPlayerCount                          = mPlayerCount;
        contents->mpCcIndicator                     = indicator;
        base->mp2DPlayer                            = &mp2DPlayer;
        mSetupPlayers[cc]                           = -1;
        indicator->mpPInfoBaseS->SetVisible(true);
        indicator->mpPInfoBase->SetVisible(true);
        base->m2dPlayerBaseY = l_2d_player_offset;
    }

    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        da2DPlayer_c* player = mp2DPlayer[daPyMng_c::mPlayerType[ply]];

        player->mAddY        = l_2d_player_offset;

        if (mPlyConnectStage[ply] == dInfo_c::PlyConnectStage_e::ENTER) {
            player->m0x261 = true;
            player->mPos.y += 200.0f;
        }

        player->m0x267 = true;
    }

    bool worldMap = dScene_c::m_nowScene == dProf::WORLD_MAP;
    mpPBgShadowST->SetVisible(worldMap);
    mpPBgST->SetVisible(worldMap);
    mpPStripeMLT->SetVisible(!worldMap);
    mpTTitleNinzuMenu->SetVisible(worldMap);
    mpTTitleNinzu->SetVisible(!worldMap);

    if (!worldMap) {
        info->mPlayerCount = mPlayerCount;
        mpTTitleNinzu->setMessage(dMessage_c::getMesRes(), 2, 28, 0);
    }

    mLayout.AllAnimeEndSetup();
    mLayout.ReverseAnimeStartSetup(2, false);
    mLayout.ReverseAnimeStartSetup(3, false);
    mpRootPane->SetVisible(true);
    mCancelAllowed = false;
    mStateMgr.changeState(StateID_OnStageAnimeEndWait);
}

[[nsmbw(0x807A1170)]]
void dNumberOfPeopleChange_c::finalizeState_InitialSetup() {
    dRemoconMng_c* remocons = dRemoconMng_c::m_instance;
    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        remocons->mpConnect[ply]->setAllowConnect(true);
    }
}

[[nsmbw(0x807A11A0)]]
void dNumberOfPeopleChange_c::initializeState_OnStageAnimeEndWait() {
    mExiting       = true;
    mExitWithGuide = false;

    mLayout.AnimeStartSetup(inWindow_guide);
    mLayout.AnimeStartSetup(inWindow_Window);

    for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
        dCharacterChangeSelectBase_c* base      = mpCcSelBase[cc];
        dCharacterChangeIndicator_c*  indicator = mpCcIndicator[cc];
        base->m0x295                            = true;
        base->mpNumPySetupPlayers               = mSetupPlayers;
        base->mpNumPyCcDecidedPlayerType        = mCcDecidedPlayerType;
        base->mpNumPyPlyDecidedPlayerType       = mPlyDecidedPlayerType;
        base->mCcCount                          = mCcCount;
        indicator->mPlayerNo                    = 0;
        indicator->m0x239                       = true;
        indicator->m0x248                       = true;
        indicator->m0x24C                       = 0;
        indicator->m0x234                       = 0.0f;
    }

    for (std::size_t i = 0; i < CHARACTER_COUNT; i++) {
        PLAYER_TYPE_e type = static_cast<PLAYER_TYPE_e>(i);
        mp2DPlayer[type]->mModelMng->mModel->updateBonusCap();
    }
}

[[nsmbw(0x807A12D0)]]
void dNumberOfPeopleChange_c::executeState_OnStageAnimeEndWait() {
    if (!mLayout.isAnime(inWindow_guide) && !mLayout.isAnime(inWindow_Window)) {
        return mStateMgr.changeState(StateID_InfoOnStageAnimeEndWait);
    }
}

[[nsmbw(0x807A1340)]]
void dNumberOfPeopleChange_c::finalizeState_OnStageAnimeEndWait() {
    mExiting = false;
    for (std::size_t type = 0; type < CHARACTER_COUNT; type++) {
        mp2DPlayer[static_cast<PLAYER_TYPE_e>(type)]->m0x267 = 0;
    }
}

[[nsmbw(0x807A1370)]]
void dNumberOfPeopleChange_c::initializeState_InfoOnStageAnimeEndWait();

[[nsmbw(0x807A1380)]]
void dNumberOfPeopleChange_c::executeState_InfoOnStageAnimeEndWait() {
    bool isWorldMap = dScene_c::m_nowScene == dProf::WORLD_MAP;
    if (isWorldMap) {
        dRemoconMng_c* remocons = dRemoconMng_c::m_instance;
        for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
            if (!remocons->mpConnect[ply]->isSetup() && dGameCom::PlayerEnterCheck(ply)) {
                dWarningManager_c::m_instance->onControllerCut(ply);
            }
        }
    }

    const auto* state = &StateID_ButtonOnStageAnimeEndWait;
    if (mEnterCount < mPlayerCount) {
        state = &StateID_NowEntrantRecruit;
    } else if (isWorldMap) {
        setPlayerSelectPos();
        state = &StateID_StoryModeCourseSelectExitWait;
    }

    return mStateMgr.changeState(*state);
}

[[nsmbw(0x807A14C0)]]
void dNumberOfPeopleChange_c::finalizeState_InfoOnStageAnimeEndWait() {
    mAllowControllerCut = true;
}

[[nsmbw(0x807A14D0)]]
void dNumberOfPeopleChange_c::initializeState_NowEntrantRecruit() {
    mCancelAllowed = true;
    for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
        mpCcSelBase[cc]->m0x299 = true;
    }
    setPlayerSelectPos();
}

[[nsmbw(0x807A1510)]]
void dNumberOfPeopleChange_c::executeState_NowEntrantRecruit() {
    //
    dRemoconMng_c* remocon = dRemoconMng_c::m_instance;
    for (std::size_t plr = 0; plr < PLAYER_COUNT; plr++) {
        dRemoconMng_c::dConnect_c* con = remocon->mpConnect[plr];
        if (!con->isSetup() || con->getExtension()->isSplitChannel() ||
            con->getExtension()->getType() !=
                dRemoconMng_c::dConnect_c::dExtension_c::Type_e::CLASSIC) {
            continue;
        }
        dGameKeyCore_c* core = dGameKey_c::m_instance->mpCores[plr];
        if (core->isTrig(dGameKeyCore_c::MINUS)) {
            con->splitExtension();
        }
    }

    for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
        if (mpCcSelBase[cc]->m0x296) {
            return;
        }
    }

    bool isWorldMap = dScene_c::m_nowScene == dProf::WORLD_MAP;
    if (checkCancel()) {
        SndAudioMgr::sInstance->startSystemSe(
            isWorldMap ? SndID::SE_SYS_DECIDE : SndID::SE_SYS_BACK, 1
        );
        mOnButton = isWorldMap ? 0 : 1;

        for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
            mpCcSelBase[cc]->m0x29B = true;
        }
        return mStateMgr.changeState(StateID_ExitAnimeEndCheck);
    } else if (!isWorldMap) {
        for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
            if (!mpCcSelBase[cc]->mDecided) {
                return;
            }
        }

        for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
            mpCcSelBase[cc]->m0x29B = true;
        }
        return mStateMgr.changeState(StateID_InfoWindowExitWait);
    }
}

// Empty
[[nsmbw(0x807A16C0)]]
void dNumberOfPeopleChange_c::finalizeState_NowEntrantRecruit();

[[nsmbw(0x807A16D0)]]
void dNumberOfPeopleChange_c::initializeState_StoryModeCourseSelectExitWait() {
    mCancelAllowed = true;
    for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
        mpCcSelBase[cc]->m0x295 = true;
        mpCcSelBase[cc]->m0x299 = true;
    }
}

[[nsmbw(0x807A1710)]]
void dNumberOfPeopleChange_c::executeState_StoryModeCourseSelectExitWait() {
    for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
        if (mpCcSelBase[cc]->m0x296) {
            return;
        }
    }

    if (checkCancel()) {
        SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_DECIDE, 1);
        mOnButton = 0;

        for (std::size_t cc = 0; cc < mPlayerCount; cc++) {
            mpCcSelBase[cc]->m0x29B = true;
        }
        return mStateMgr.changeState(StateID_ExitAnimeEndCheck);
    }
}

// Empty
[[nsmbw(0x807A1810)]]
void dNumberOfPeopleChange_c::finalizeState_StoryModeCourseSelectExitWait();

// Empty
[[nsmbw(0x807A1820)]]
void dNumberOfPeopleChange_c::initializeState_InfoWindowExitWait();

[[nsmbw(0x807A1830)]]
void dNumberOfPeopleChange_c::executeState_InfoWindowExitWait() {
    return mStateMgr.changeState(StateID_ButtonOnStageAnimeEndWait);
}

// Empty
[[nsmbw(0x807A1850)]]
void dNumberOfPeopleChange_c::finalizeState_InfoWindowExitWait();

[[nsmbw(0x807A1860)]]
void dNumberOfPeopleChange_c::initializeState_ButtonOnStageAnimeEndWait() {
    mLayout.AnimeStartSetup(inYesNoButtons_guideYes);
    mLayout.AnimeStartSetup(inYesNoButtons_yesButton);
    mLayout.AnimeStartSetup(inYesNoButtons_guideNo);
    mLayout.AnimeStartSetup(inYesNoButtons_noButton);

    for (std::size_t type = 0; type < CHARACTER_COUNT; type++) {
        mp2DPlayer[static_cast<PLAYER_TYPE_e>(type)]->m0x266 = 1;
    }

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        dCharacterChangeIndicator_c* indicator = mpCcIndicator[cc];
        indicator->mpPInfoBaseS->SetVisible(false);
        indicator->mpPInfoBase->SetVisible(false);
    }

    mExitWithGuide = true;
    mCancelAllowed = false;
}

[[nsmbw(0x807A1990)]]
void dNumberOfPeopleChange_c::executeState_ButtonOnStageAnimeEndWait() {
    if (!mLayout.isAnime(inYesNoButtons_guideYes) && !mLayout.isAnime(inYesNoButtons_yesButton) &&
        !mLayout.isAnime(inYesNoButtons_guideNo) && !mLayout.isAnime(inYesNoButtons_noButton)) {
        mOnButton  = 0;
        mOffButton = -1;
        return mStateMgr.changeState(StateID_ButtonChangeAnimeEndWait);
    }
}

// Empty
[[nsmbw(0x807A1A40)]]
void dNumberOfPeopleChange_c::finalizeState_ButtonOnStageAnimeEndWait();

[[nsmbw(0x807A1A50)]]
void dNumberOfPeopleChange_c::initializeState_ButtonChangeAnimeEndWait() {
    if (mOffButton > -1) {
        mLayout.AnimeStartSetup(offYesNoButtons_yesButton + mOffButton, false);
    }
    mLayout.AnimeStartSetup(onYesNoButtons_yesButton + mOnButton, false);
}

[[nsmbw(0x807A1AB0)]]
void dNumberOfPeopleChange_c::executeState_ButtonChangeAnimeEndWait() {
    if ((mOffButton < 0 || !mLayout.isAnime(offYesNoButtons_yesButton + mOffButton)) &&
        !mLayout.isAnime(onYesNoButtons_yesButton + mOnButton)) {
        return mStateMgr.changeState(StateID_ButtonSelect);
    }
}

// Empty
[[nsmbw(0x807A1B30)]]
void dNumberOfPeopleChange_c::finalizeState_ButtonChangeAnimeEndWait();

[[nsmbw(0x807A1B40)]]
void dNumberOfPeopleChange_c::initializeState_ButtonSelect() {
    dGameCom::SelectCursorSetup(mpPYesNoBase[mOnButton], 0, false);
}

[[nsmbw(0x807A1B60)]]
void dNumberOfPeopleChange_c::executeState_ButtonSelect() {
    dGameKeyCore_c* core   = dGameKey_c::getCurrentCore();

    int             newBtn = mOnButton;
    if (newBtn == 0 && core->checkLeft()) {
        newBtn = 1;
    }
    if (newBtn == 1 && core->checkRight()) {
        newBtn = 0;
    }

    if (newBtn != mOnButton) {
        SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_CURSOR, 1);
        mOffButton = mOnButton;
        mOnButton  = newBtn;
        mStateMgr.changeState(StateID_ButtonChangeAnimeEndWait);
        return;
    }

    if (core->checkMenuConfirm()) {
        if (mOnButton == 0) {
            SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_DECIDE, 1);
            if (!(dInfo_c::m_instance->mGameFlag & dInfo_c::GameFlag_e::MULTI_MODE)) {
                // TODO: Mini-mario pitch up
                static const u16 PlayerDecideSounds[] = {
                    SndID::SE_VOC_MA_PLAYER_DECIDE,  SndID::SE_VOC_LU_CS_DECIDE_JOIN,
                    SndID::SE_VOC_KO_CS_DECIDE_JOIN, SndID::SE_VOC_KO2_CS_DECIDE_JOIN,
                    SndID::SE_VOC_KC_PLAYER_DECIDE,  SndID::SE_VOC_KC_CS_DECIDE_JOIN,
                    SndID::SE_VOC_KO_CS_DECIDE_JOIN, SndID::SE_VOC_KO2_CS_DECIDE_JOIN,
                };

                u16 sound = PlayerDecideSounds[int(daPyMng_c::mPlayerType[0]) % 8];
                SndAudioMgr::sInstance->startSystemSe(sound, 1);
            }
        } else {
            SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_BACK, 1);
        }
        mStateMgr.changeState(StateID_ButtonDecision);
        return;
    }
}

[[nsmbw(0x807A1D00)]]
void dNumberOfPeopleChange_c::finalizeState_ButtonSelect();

[[nsmbw(0x807A1D10)]]
void dNumberOfPeopleChange_c::initializeState_ButtonDecision() {
    mLayout.AnimeStartSetup(hitYesNoButtons_yesButton + mOnButton, false);
}

[[nsmbw(0x807A1D30)]]
void dNumberOfPeopleChange_c::executeState_ButtonDecision() {
    if (!mLayout.isAnime()) {
        return mStateMgr.changeState(StateID_ExitAnimeEndCheck);
    }
}

// Empty
[[nsmbw(0x807A1D90)]]
void dNumberOfPeopleChange_c::finalizeState_ButtonDecision();

[[nsmbw(0x807A1DA0)]]
void dNumberOfPeopleChange_c::initializeState_ExitAnimeEndCheck() {
    mCancelAllowed = false;
    if (mOnButton == 1 || dScene_c::m_nowScene == dProf::WORLD_MAP) {
        if (!mExitWithGuide) {
            mLayout.AnimeStartSetup(outWindowInCourseSelectMenu_guide);
        }
        mLayout.AnimeStartSetup(outWindowInCourseSelectMenu_Window);
    } else {
        if (!mExitWithGuide) {
            mLayout.AnimeStartSetup(outWindow_guide);
        }
        mLayout.AnimeStartSetup(outWindow_Window);
    }
    mExiting = true;
}

[[nsmbw(0x807A1E80)]]
void dNumberOfPeopleChange_c::executeState_ExitAnimeEndCheck() {
    if (mLayout.isAnime()) {
        return;
    }

    mpRootPane->SetVisible(false);
    mStateMgr.changeState(StateID_InitialSetup);
    m0x67E        = false;
    dInfo_c* info = dInfo_c::m_instance;
    info->m0xAFC  = 0;

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        if (mOnButton == 1 && dScene_c::m_nowScene == dProf::GAME_SETUP) {
            PLAYER_TYPE_e type         = dMj2dGame_c::scDefaultPlayerTypes[cc];
            mCcDecidedPlayerType[cc]   = type;
            daPyMng_c::mPlayerType[cc] = dMj2dGame_c::scDefaultPlayerTypes[cc];
        }
        std::size_t type = static_cast<std::size_t>(daPyMng_c::mPlayerType[cc]);
        if (mp2DPlayer[static_cast<PLAYER_TYPE_e>(type)]->m0x261) {
            mp2DPlayer[static_cast<PLAYER_TYPE_e>(type)]->m0x269 = 1;
        }

        auto* indicator = mpCcIndicator[cc];
        for (std::size_t lamp = 0; lamp < std::size(indicator->mpPLamp); lamp++) {
            indicator->mpPLamp[lamp]->SetVisible(false);
        }
        indicator->m0x239    = 0;
        indicator->mPlayerNo = 0;
    }
    for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
        info->setPlyConnectStage(ply, dInfo_c::PlyConnectStage_e::OFF);
    }

    if (mOnButton == 1) {
        for (std::size_t ply = 0; ply < PLAYER_COUNT; ply++) {
            info->setPlyConnectStage(ply, mPlyConnectStage[ply]);
        }
    } else {
        setupPlayerTypes();
        disableInactiveControllers();
        dWarningManager_c::m_instance->m0xB8D = true;
    }

    if (!info->mCyuukan.checkEntry()) {
        info->mCyuukan.clear();
    }
}

[[nsmbw(0x807A2080)]]
void dNumberOfPeopleChange_c::finalizeState_ExitAnimeEndCheck() {
    for (std::size_t i = 0; i < CHARACTER_COUNT; i++) {
        PLAYER_TYPE_e type       = static_cast<PLAYER_TYPE_e>(i);
        mp2DPlayer[type]->m0x266 = 0;
        mp2DPlayer[type]->m0x269 = 1;

        if (dScene_c::isWorldMap()) {
            mp2DPlayer[type]->mForbidJump = false;
        }
    }

    for (std::size_t cc = 0; cc < mCcCount; cc++) {
        mpCcSelBase[cc]->m0x298     = 1;
        mpCcSelContents[cc]->m0x2A0 = 1;
        mpCcSelArrow[cc]->m0x26C    = 1;
    }

    mExitWithGuide = mExiting = false;
}
