// d_actor.cpp
// NSMBW .text: 0x80064110 - 0x800660C0

#include "d_actor.h"

#include "d_a_player.h"
#include "d_fukidashiManager.h"
#include "d_game_common.h"
#include "d_info.h"
#include "d_mj2d_game.h"
#include "d_s_stage.h"

[[nsmbw_data(0x80429FD8)]]
u8 dActor_c::mExecStopReq;

[[nsmbw_data(0x80429FDA)]]
u8 dActor_c::mExecStop;

[[nsmbw(0x80064110)]]
dActor_c::dActor_c();

[[nsmbw(0x800642B0)]]
dActor_c::~dActor_c();

[[nsmbw(0x80064350)]]
fBase_c::PACK_RESULT_e dActor_c::preCreate();

[[nsmbw(0x80064380)]]
void dActor_c::postCreate(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x80064390)]]
fBase_c::PACK_RESULT_e dActor_c::preDelete();

[[nsmbw(0x800643E0)]]
void dActor_c::postDelete(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800643F0)]]
fBase_c::PACK_RESULT_e dActor_c::preExecute();

[[nsmbw(0x80064490)]]
void dActor_c::postExecute(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x80064540)]]
fBase_c::PACK_RESULT_e dActor_c::preDraw();

[[nsmbw(0x800645E0)]]
void dActor_c::postDraw(fBase_c::MAIN_STATE_e status);

[[nsmbw(0x800645F0)]]
const char* dActor_c::getKindString() const;

[[nsmbw(0x80064600)]]
void dActor_c::setTmpCtData(u8);

[[nsmbw(0x80064610)]]
dActor_c* dActor_c::construct(
    u16 profile, u32 settings, const mVec3_c* position, const mAng3_c* rotation, u8 layer
);

[[nsmbw(0x80064680)]]
dActor_c* dActor_c::construct(
    u16 profile, dBase_c* owner, u32 settings, const mVec3_c* position, const mAng3_c* rotation,
    u8 layer
);

[[nsmbw(0x800646E0)]]
void dActor_c::setKind(u8);

[[nsmbw(0x80064720)]]
void dActor_c::setSearchNearPlayerFunc(int);

[[nsmbw(0x80064740)]]
dAcPy_c* dActor_c::searchNearPlayer(mVec2_c&);

[[nsmbw(0x80064790)]]
dAcPy_c* dActor_c::searchNearPlayer_Main(mVec2_c&, const mVec2_c&);

[[nsmbw(0x800647A0)]]
dAcPy_c* dActor_c::searchNearPlayerNormal(mVec2_c&, const mVec2_c&);

[[nsmbw(0x80064880)]]
dAcPy_c* dActor_c::searchNearPlayerLoop(mVec2_c&, const mVec2_c&);

[[nsmbw(0x80064A10)]]
void dActor_c::setGetTrgToSrcDirFunc(int);

[[nsmbw(0x80064A30)]]
bool dActor_c::getTrgToSrcDir_Main(f32, f32);

[[nsmbw(0x80064A40)]]
bool dActor_c::getTrgToSrcDirNormal(f32, f32);

[[nsmbw(0x80064A50)]]
bool dActor_c::getTrgToSrcDirLoop(f32, f32);

[[nsmbw(0x80064AF0)]]
void dActor_c::changePosAngle(mVec3_c*, mAng3_c*, int);

[[nsmbw(0x80064B00)]]
void dActor_c::setChangePosAngleFunc(int);

[[nsmbw(0x80064B10)]]
void dActor_c::setLoopFunc(int);

[[nsmbw(0x80064B50)]]
bool dActor_c::checkAreaNo();

[[nsmbw(0x80064BC0)]]
void dActor_c::setSoftLight_Player(m3d::bmdl_c&);

[[nsmbw(0x80064BD0)]]
void dActor_c::setSoftLight_Enemy(m3d::bmdl_c&);

[[nsmbw(0x80064BE0)]]
void dActor_c::setSoftLight_Map(m3d::bmdl_c&);

[[nsmbw(0x80064BF0)]]
void dActor_c::setSoftLight_MapObj(m3d::bmdl_c&);

[[nsmbw(0x80064C00)]]
void dActor_c::setSoftLight_Boss(m3d::bmdl_c&);

[[nsmbw(0x80064C10)]]
void dActor_c::setSoftLight_Item(m3d::bmdl_c& model);

[[nsmbw(0x80064D10)]]
void dActor_c::deleteActor(u8);

[[nsmbw(0x80064DA0)]]
bool dActor_c::checkOutOfArea(const mVec3_c& pos, const nw4r::ut::Rect& rect, u8 area);

[[nsmbw(0x80065080)]]
bool dActor_c::ActorDrawCullCheck();

[[nsmbw(0x80064F50)]]
void dActor_c::ActorScrOutCheck(u16);

[[nsmbw(0x800651C0)]]
bool dActor_c::carryFukidashiCheck(
    int fukidashiAction, mVec2_c fukidashiTriggerSize
) {
    mVec3_c centerPos = getCenterPos();

    mVec3_c minTriggerPos(
        centerPos.x - fukidashiTriggerSize.x, centerPos.y - fukidashiTriggerSize.y, mPos.z
    );
    mVec3_c maxTriggerPos(
        centerPos.x + fukidashiTriggerSize.x, centerPos.y + fukidashiTriggerSize.y, mPos.z
    );

    if (mCarryFukidashiPlayerNo < PLAYER_COUNT && dInfo_c::m_instance->getFukidashiActionPerformed(
                                                      mCarryFukidashiPlayerNo, fukidashiAction
                                                  )) {
        mCarryFukidashiPlayerNo = -1;
    }

    if (mCarryFukidashiPlayerNo < PLAYER_COUNT) {
        // Already displaying a fukidashi
        dAcPy_c* player = daPyMng_c::getPlayer(mCarryFukidashiPlayerNo);
        if (player != nullptr) {
            bool        canDrawFukidashi = player->isDrawingCarryFukidashi();

            sRangeDataF playerBoundBox;
            player->getCcBounds(&playerBoundBox);
            mVec3_c playerPos(
                dScStage_c::getLoopPosX(playerBoundBox.mOffset.x + player->mPos.x),
                playerBoundBox.mOffset.y + player->mPos.y, player->mPos.z
            );

            mVec3_c minPlayerPos = {
                playerPos.x - playerBoundBox.mSize.x - 2.0f, playerPos.y - playerBoundBox.mSize.y,
                playerPos.z
            };
            mVec3_c maxPlayerPos = {
                playerPos.x + playerBoundBox.mSize.x + 2.0f, playerPos.y + playerBoundBox.mSize.y,
                playerPos.z
            };

            if (!dfukidashiManager_c::m_instance->mInfo[mCarryFukidashiPlayerNo].isVisible()) {
                dGameCom::showFukidashi(mCarryFukidashiPlayerNo, fukidashiAction);
            }

            bool overlap = dGameCom::checkRectangleOverlap(
                minTriggerPos, maxTriggerPos, minPlayerPos, maxPlayerPos, 0.0f
            );
            if ((!canDrawFukidashi) || (!overlap)) {
                dGameCom::hideFukidashiTemporarily(mCarryFukidashiPlayerNo, fukidashiAction, 0);
                mCarryFukidashiPlayerNo = -1;
            }
        }
    } else {
        // Not displaying a fukidashi yet, search for a player to show it
        dAcPy_c* player = searchCarryFukidashiPlayer(fukidashiAction);
        if (player != nullptr) {
            bool        canDrawFukidashi = player->isDrawingCarryFukidashi();

            sRangeDataF playerBoundBox;
            player->getCcBounds(&playerBoundBox);
            mVec3_c playerPos(
                dScStage_c::getLoopPosX(playerBoundBox.mOffset.x + player->mPos.x),
                playerBoundBox.mOffset.y + player->mPos.y, player->mPos.z
            );

            mVec3_c minPlayerPos = {
                playerPos.x - playerBoundBox.mSize.x, playerPos.y - playerBoundBox.mSize.y,
                playerPos.z
            };
            mVec3_c maxPlayerPos = {
                playerPos.x + playerBoundBox.mSize.x, playerPos.y + playerBoundBox.mSize.y,
                playerPos.z
            };

            bool overlap = dGameCom::checkRectangleOverlap(
                minTriggerPos, maxTriggerPos, minPlayerPos, maxPlayerPos, 0.0f
            );
            if (canDrawFukidashi && overlap) {
                mCarryFukidashiPlayerNo = player->getPlrNo();
            }
        }
    }

    return false;
}

[[nsmbw(0x80065480)]]
void dActor_c::carryFukidashiCancel(
    int fukidashiAction, int plrNo
) {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (i == plrNo) {
            dGameCom::hideFukidashiForLevel(i, fukidashiAction, 0);
            dGameCom::hideFukidashiForSession(i, fukidashiAction);
        } else {
            dGameCom::hideFukidashiTemporarily(i, fukidashiAction, 0);
        }
    }
    mCarryFukidashiPlayerNo = -1;
}

[[nsmbw(0x80065520)]]
dAcPy_c* dActor_c::searchCarryFukidashiPlayer(
    int fukidashiAction
) {
    mVec3_c  center        = getCenterPos();

    dAcPy_c* closestPlayer = nullptr;
    float    closestDist   = 1e9;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (daPyMng_c::isPlayerActive(i) &&
            !dInfo_c::m_instance->getFukidashiActionPerformed(i, fukidashiAction)) {
            dAcPy_c* player = daPyMng_c::getPlayer(i);
            if (player == nullptr) {
                continue;
            }

            float diffX = player->mPos.x + player->mCenterOffs.x - center.x;
            float diffY = player->mPos.y + player->mCenterOffs.y - center.y;
            float dist  = diffX * diffX + diffY * diffY;
            if (closestDist > dist) {
                closestPlayer = player;
                closestDist   = dist;
            }
        }
    }
    return closestPlayer;
}

[[nsmbw(0x80065620)]]
mVec3_c dActor_c::getLookatPos() const;

[[nsmbw(0x80065650)]]
void dActor_c::block_hit_init();

[[nsmbw(0x80065660)]]
bool dActor_c::allEnemyDeathEffSet();

[[nsmbw(0x80065820)]]
void dActor_c::setSpinLiftUpActor(dActor_c* actor);

[[nsmbw(0x80065830)]]
void dActor_c::setEatTongue(dActor_c* actor);

[[nsmbw(0x80065850)]]
void dActor_c::setEatTongueOff(dActor_c* actor);

[[nsmbw(0x80065860)]]
void dActor_c::setEatMouth(dActor_c* actor);

[[nsmbw(0x80065870)]]
bool dActor_c::setEatSpitOut(dActor_c* actor);

[[nsmbw(0x80065880)]]
bool dActor_c::setEatGlupDown(dActor_c* actor);

[[nsmbw(0x80065950)]]
void dActor_c::setAfterEatScale();

[[nsmbw(0x80065970)]]
void dActor_c::calcSpitOutPos(dActor_c* actor);

[[nsmbw(0x80065A00)]]
float dActor_c::calcEatScaleRate(dActor_c* yoshi);

[[nsmbw(0x80065A40)]]
void dActor_c::calcEatInScale(dActor_c* yoshi);

[[nsmbw(0x80065AC0)]]
void dActor_c::eatMove(dActor_c* actor);

[[nsmbw(0x80065B40)]]
void dActor_c::VT_0xB4();

[[nsmbw(0x80065B50)]]
void dActor_c::cancelFunsuiActUpper();

[[nsmbw(0x80065B60)]]
void dActor_c::cancelFunsuiActSide();

[[nsmbw(0x80065B70)]]
void dActor_c::cancelFunsuiActVanish();

[[nsmbw(0x80065CC0)]]
void dActor_c::waterSplashEffect(const mVec3_c& position, float scale);

[[nsmbw(0x80065DC0)]]
void dActor_c::yoganSplashEffect(const mVec3_c& position, float scale);

[[nsmbw(0x80065EC0)]]
void dActor_c::poisonSplashEffect(const mVec3_c& position, float scale);

[[nsmbw(0x80066080)]]
void dActor_c::removeCc();

[[nsmbw(0x80066090)]]
void dActor_c::reviveCc();

const u8 l_Ami_Line[] = {1, 2};
