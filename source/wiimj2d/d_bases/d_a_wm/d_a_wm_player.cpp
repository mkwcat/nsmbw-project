// d_a_wm_player.cpp
// NSMBW d_bases.text: 0x80902790 - 0x8090D220

#include "d_a_wm_player.h"

#include "d_CourseSelectManager.h"
#include "d_a_player_manager.h"
#include "d_a_wm_KinoBalloon.h"
#include "d_a_wm_SubPlayer.h"
#include "d_cs_seq_mng.h"
#include "d_game_key_core.h"
#include "d_gamerule.h"
#include "d_info.h"
#include "d_mj2d_game.h"
#include "d_profile.h"
#include "d_s_world_map.h"
#include "d_wm_lib.h"
#include "d_wm_player_camera_base.h"
#include "d_world_camera.h"
#include "m_pad.h"
#include <egg/core/eggController.h>
#include <revolution/os.h>

/* 0x809A0DB8 */
dInfo_c::PlyConnectStage_e daWmPlayer_c::ms_plyConnectStage[SUBPLAYER_COUNT];

[[nsmbw(0x809027C0)]]
daWmPlayer_c::daWmPlayer_c()
    : dWmPlayerBase_c()
    , mModelManager(dPyMdlMng_c::ModelType_e::MODEL_NONE)
    , m0x1F0(mVec3_c::Zero)
    , m0x23C(6)
    , m0x240(6)
    , m0x25A(0)
    , m0x25B(0)
    , m0x27C(0)
    , m0x298(1.0)
    , m0x2E0(2)
    , m0x2FC(0) {
    ms_instance = this;
    mPyCamera   = nullptr;
}

[[nsmbw(0x80902890)]]
daWmPlayer_c::~daWmPlayer_c() {
    ms_instance          = nullptr;

    // This object doesn't belong to this class, so null it so it doesn't get deleted
    mModelManager.mModel = nullptr;

    if (mPyCamera) {
        delete mPyCamera;
    }

#ifndef __has_macintosh_dt_fix
    mModelManager.~dPyMdlMng_c();
#endif // !__has_macintosh_dt_fix
}

[[nsmbw(0x80902960)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::create() {
    mAngle.y = 0;

    mPad::setCurrentChannel(mPad::CH_e::CHAN_0);

    initStartPoint();

    mModelManager.mModel = nullptr;
    // Create subplayer models
    CreateSubPlayers();
    ASSERT(mModelManager.mModel != nullptr);

    // Some shadow related thing maybe?
    UNDEF_80906FE0(0, -1);
    CreateShadowModel("character_SV", "g3d/model.brres", "character_SV", 1);
    mVisible = true;

    initCamera();
    initDemo();
    PlayerEntryInit();
    updateCourseNode();

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x809029E0)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::execute();

[[nsmbw(0x80902AC0)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::draw();

[[nsmbw(0x80902B30)]]
fBase_c::PACK_RESULT_e daWmPlayer_c::doDelete();

[[nsmbw(0x80902BD0)]]
void daWmPlayer_c::CreateSubPlayers() {
    mPrevPlayer                 = nullptr;
    dWmPlayerBase_c* prevPlayer = this;

    for (u32 i = 0; i < SUBPLAYER_COUNT; i++) {
        daWmSubPlayer_c* player =
            reinterpret_cast<daWmSubPlayer_c*>(dWmActor_c::construct(dProf::WM_SUBPLAYER, this, i));

        prevPlayer->mNextPlayer = player;
        player->mPrevPlayer     = prevPlayer;

        prevPlayer              = player;

        // Set player 1's model if this is player 1's character
        PLAYER_TYPE_e type      = dMj2dGame_c::scDefaultPlayerTypes[i % PLAYER_COUNT];
        if (type == daPyMng_c::mPlayerType[0]) {
            mModelManager.mModel = player->mModelManager->mModel;
        }
    }

    prevPlayer->mNextPlayer = nullptr;
}

daWmSubPlayer_c* daWmPlayer_c::GetSubPlayer() const {
    return static_cast<daWmSubPlayer_c*>(mNextPlayer);
}

[[nsmbw(0x80902C50)]]
void daWmPlayer_c::PlayerEntryInit();

[[nsmbw(0x80902CA0)]]
void daWmPlayer_c::PlayerEntryUpdate() {
    bool singleEntry = dWmLib::IsSingleEntry();

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        SetPlayerEntry(i, false, false);
        daPyMng_c::mPlayerEntry[0] = 0;
    }

    daPyMng_c::mPlayerEntry[0] = 1;
    dInfo_c* info              = dInfo_c::m_instance;

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        bool active = info->getPlyConnectStage(i) == dInfo_c::PlyConnectStage_e::ENTER;
        if (active) {
            std::size_t index          = static_cast<std::size_t>(daPyMng_c::mPlayerType[i]);
            daPyMng_c::mPlayerEntry[i] = 1;
            SetPlayerEntry(
                index, i != 0, ms_plyConnectStage[index] != dInfo_c::PlyConnectStage_e::ENTER
            );
        }
    }

    if (singleEntry != dWmLib::IsSingleEntry()) {
        if (singleEntry) {
            daWmKinoBalloon_c::balloonRemove();
        } else {
            dWmLib::RestoreKinopioHelpGameInfo();
            daWmKinoBalloon_c::balloonAppear();
        }
    }

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        ms_plyConnectStage[static_cast<std::size_t>(daPyMng_c::mPlayerType[i])] =
            info->getPlyConnectStage(i);
    }

    for (daWmSubPlayer_c* player = GetSubPlayer(); player; player = player->Next()) {
        player->mp0x294 = &dWmLib::sc_0x8031D6B4;
    }
}

[[nsmbw(0x80902E30)]]
void daWmPlayer_c::SetPlayerEntry(int plr, bool update, bool enter);

[[nsmbw(0x80902ED0)]]
void daWmPlayer_c::updateSubPlayerModel(
    PLAYER_TYPE_e type, PLAYER_MODE_e mode, bool star
) {
    daWmSubPlayer_c* player;
    for (player = GetSubPlayer(); player; player = player->Next()) {
        if (player->isPlayerType(type)) {
            break;
        }
    }
    if (player == nullptr) {
        return;
    }

    dPyMdlBase_c* model = player->mModelManager->mModel;

    if (daPyMng_c::mPlayerType[0] == type) {
        // Update player 1 model
        mModelManager.mModel = model;
    }

    model->setPlayerMode(+mode);
    if (star) {
        model->onStarAnm();
        model->onStarEffect();
    }
}

[[nsmbw(0x80902FA0)]]
void daWmPlayer_c::updatePlayerMode() {
    dInfo_c* info = dInfo_c::m_instance;

    for (u32 i = 0; i < PLAYER_COUNT; i++) {
        if (info->getPlyConnectStage(i) != dInfo_c::PlyConnectStage_e::ENTER) {
            continue;
        }

        PLAYER_TYPE_e type = daPyMng_c::mPlayerType[i];
        PLAYER_MODE_e mode = dCourseSelectManager_c::m_instance->getPlayerPowerup(i);
        updateSubPlayerModel(
            type, mode, !!(daPyMng_c::mCreateItem[type] & PLAYER_CREATE_ITEM_e::STAR_POWER)
        );
    }
}

[[nsmbw(0x80903380)]]
void daWmPlayer_c::initCamera();

[[nsmbw(0x80903930)]]
void daWmPlayer_c::initStartPoint();

[[nsmbw(0x80903ED0)]]
void daWmPlayer_c::initDemo();

[[nsmbw(0x80904120)]]
u32 daWmPlayer_c::checkCsGuideKey() {
    if (!UNDEF_809087A0()) {
        return 0;
    }

    if (dCsSeqMng_c::ms_instance->UNDEF_80915630() == 0 &&
        !dCsSeqMng_c::ms_instance->UNDEF_80915600()) {
        dGameKeyCore_c::Type_e contType = dWmLib::isYokoCon(0);
        bool                   openWorldView;
        switch (contType) {
        case dGameKeyCore_c::Type_e::FREESTYLE:
            openWorldView = mPad::g_currentCore->downTrigger(EGG::cCORE_BUTTON_FS_C);
            break;
        case dGameKeyCore_c::Type_e::CLASSIC:
            openWorldView =
                mPad::g_currentCore->getClassicController()->mTrig & EGG::cCLASSIC_BUTTON_Y;
            break;
        case dGameKeyCore_c::Type_e::DOLPHIN:
            openWorldView = mPad::g_currentCore->getGCController()->mTrig & EGG::cDOLPHIN_BUTTON_Y;
            break;
        default:
            openWorldView = mPad::g_currentCore->downTrigger(EGG::cCORE_BUTTON_A);
            break;
        }

        if (openWorldView) {
            if (dCourseSelectManager_c::m_instance->mEndedMsgChange ||
                dCourseSelectManager_c::m_instance->mpMessageWindow->mVisible) {
                dCourseSelectManager_c::m_instance->mStartedMsgChange = true;
            }
            daWmKinoBalloon_c::UNDEF_808D8720();
            // SMC_DEMO_VIEW_WORLD
            return dCsSeqMng_c::ms_instance->addScriptToQueue(
                0x1E, this, dWCamera_c::m_instance, 0x80
            );
        }
        // Omitting some unused dWmLib::isYokoCon calls here...
        if (mPad::g_currentCore->downTrigger(EGG::cCORE_BUTTON_PLUS)) {
            // SMC_DEMO_PAUSE_MENU
            return dCsSeqMng_c::ms_instance->addScriptToQueue(0x2F, nullptr, nullptr, 0x80);
        }

        u32 checkButton;
        switch (contType) {
        case dGameKeyCore_c::Type_e::CORE:
            checkButton = EGG::cCORE_BUTTON_1;
            break;
        default:
            checkButton = (EGG::cCORE_BUTTON_1 | EGG::cCORE_BUTTON_B);
            break;
        }

        if (mPad::g_currentCore->downTrigger(checkButton)) {
            // SMC_DEMO_STOCK_MENU
            return dCsSeqMng_c::ms_instance->addScriptToQueue(0x31, nullptr, nullptr, 0x80);
        }

        if (mPad::g_currentCore->downTrigger(EGG::cCORE_BUTTON_MINUS)) {
            // SMC_DEMO_WORLDSELECT_MENU
            return dCsSeqMng_c::ms_instance->addScriptToQueue(0x32, nullptr, nullptr, 0x80);
        }
    }

    u32 uVar6 = m0x288;
    m0x28C    = 4;
    m0x288    = 4;
    u32 uVar5 = UNDEF_80908DA0();
    u32 uVar3 = UNDEF_80904370(uVar5);
    if ((m0x259 & 0x10) == 0) {
        if (m0x288 != 4) {
            m0x300 = 0;
            uVar3  = UNDEF_80904810();
        }
    } else {
        uVar3 = UNDEF_80904440();
    }
    if (m0x288 == 4) {
        m0x288 = uVar6;
    }
    return uVar3;
}

[[nsmbw(0x80904370)]]
u32 daWmPlayer_c::UNDEF_80904370(u32);

[[nsmbw(0x80904440)]]
u32 daWmPlayer_c::UNDEF_80904440();

[[nsmbw(0x80904810)]]
u32 daWmPlayer_c::UNDEF_80904810();

[[nsmbw(0x80907590)]]
void daWmPlayer_c::updateCourseNode();

EXTERN_REPL(0x80907D10, bool daWmPlayer_c::isRouteClosedByGate2(int node));

[[nsmbw(0x80907D10)]]
bool daWmPlayer_c::isRouteClosedByGate(
    int node
) {
    if (dGameRule_s::current.all_paths_available) {
        return false;
    }
    return isRouteClosedByGate2(node);
}

[[nsmbw(0x80907A60)]]
dWmLib::Dir_e daWmPlayer_c::getMovementDirection();

[[nsmbw(0x809087A0)]]
bool daWmPlayer_c::UNDEF_809087A0();

[[nsmbw(0x80908DA0)]]
u32 daWmPlayer_c::UNDEF_80908DA0();

/* VT+0x60 0x80909940 */
[[nsmbw(0x80909940)]]
void daWmPlayer_c::VT_0x60();

[[nsmbw(0x809093D0)]]
void daWmPlayer_c::initActiveCharaFlags() {
    dInfo_c* info = dInfo_c::m_instance;

    for (u32 i = 0; i < SUBPLAYER_COUNT; i++) {
        auto flag = info->getPlyConnectStage(i);
        if (flag != dInfo_c::PlyConnectStage_e::ENTER) {
            flag = dInfo_c::PlyConnectStage_e::OFF;
        }
        ms_plyConnectStage[+daPyMng_c::mPlayerType[i] % SUBPLAYER_COUNT] = flag;
    }
}

[[nsmbw(0x8090BE30)]]
void daWmPlayer_c::VT_0x70();

[[nsmbw(0x8090C160)]]
void daWmPlayer_c::VT_0x74();

[[nsmbw(0x8090C8C0)]]
void daWmPlayer_c::VT_0x80();

[[nsmbw(0x8090C8E0)]]
void daWmPlayer_c::VT_0x78();

[[nsmbw(0x8090C940)]]
void daWmPlayer_c::procDemoLose();

[[nsmbw(0x8090CE10)]]
bool daWmPlayer_c::startGame(
    dWmLib::WorldNo world, dWmLib::CourseNo stage, u8 nextGotoNo
) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (dInfo_c::m_instance->getPlyConnectStage(i) == dInfo_c::PlyConnectStage_e::ENTER) {
            daPyMng_c::mPlayerEntry[i] = 1;
            daPyMng_c::mPlayerMode[daPyMng_c::mPlayerType[i]] =
                dCourseSelectManager_c::m_instance->getPlayerPowerup(i);
        } else {
            daPyMng_c::mPlayerEntry[i] = 0;
        }
    }

    updateCourseNode();

    dInfo_c* info         = dInfo_c::m_instance;
    info->mCurrentWorldNo = +world;
    info->mCurrentStageNo = +stage;
    info->m_isOtasuke     = false;
    if (dWmLib::IsSingleEntry()) {
        info->mKinopioCourseInvalid[world] = true;
        info->mKinopioCourseNo[world]      = STAGE_e::COUNT;
    }

    StageNo_s stageNo;
    dWmLib::getWorldStageFromCourseNum(world, stage, stageNo.world, stageNo.stage);

    dScWMap_c::setPrevCollectionCoinNum();

    info->startGame({
        .demoTime   = 0,
        .otehonType = {},
        .nextGotoNo = nextGotoNo,
        .courseNo   = 0,
        .isDemo     = false,
        .demoType   = {},
        .stage1     = {static_cast<WORLD_e>(world), static_cast<STAGE_e>(stage)},
        .stage2     = stageNo,
    });

    return true;
}
