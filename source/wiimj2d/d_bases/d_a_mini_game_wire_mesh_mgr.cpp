// d_a_mini_game_wire_mesh_mgr.cpp
// NSMBW d_bases.text: 0x8086A040 - 0x8086C8F0

#include "d_a_mini_game_wire_mesh_mgr.h"

#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_player_model_base.h"
#include "d_system/d_save_manager.h"
#include "egg/util/eggEffect.h"
#include "machine/m_mtx.h"
#include "machine/m_vec.h"
#include "nw4r/math/vec.h"
#include "nw4r/ut/Color.h"
#include "revolution/gx/GXStruct.h"

/* todo list:
 * 0x8086B910 - getInitialTurnPlayerID() [needs to support 8 players]
 * 0x8086B990 - setTurnPlayer()
 * 0x8086BEE0 - executeState_ShowResult()
*/

static constinit const nw4r::ut::Color PLY_CURSOR_EFF_COLOR_1[] = {
    "#FFAB00", // Mario
    "#66FF00", // Luigi
    "#00FFFF", // Blue Toad
    "#FFFF44", // Yellow Toad
    "#F09BE2", // Toadette
    "#A472F8", // Purple Toadette
    "#FFC642", // Orange Toad
    "#999999", // Black Toad
};

static constinit const nw4r::ut::Color PLY_CURSOR_EFF_COLOR_2[] = {
    "#FF1B00", // Mario
    "#00FF15", // Luigi
    "#006CFF", // Blue Toad
    "#FFC000", // Yellow Toad
    "#CC1BFF", // Toadette
    "#6F00FF", // Purple Toadette
    "#FF6600", // Orange Toad
    "#1C1C1C", // Black Toad
};

[[address(0x8086AB90)]]
void daMiniGameWireMeshMgrObj_c::EffectCursor2d() {
    GXColor fillClr, edgeClr;

    if (daPyMng_c::getPlayer(mTurnPlayer) != nullptr) {
        int playerType = daPyMng_c::mPlayerType[mTurnPlayer];
        if (playerType >= PLAYER_COUNT) {
            fillClr = {0xFF, 0xFF, 0xFF, 0xFF};
            edgeClr = {0xFF, 0xFF, 0xFF, 0xFF};
        } else {
            fillClr = PLY_CURSOR_EFF_COLOR_1[playerType];
            edgeClr = PLY_CURSOR_EFF_COLOR_2[playerType];
        }

        const mVec3_c pos(0.0, 0.0, 0.0);
        dGameCom::MiniGameWireFacePosEffect(pos);

        mEffectCursor2d.createEffect("Wm_mg_cursor_2d", 0, &pos, nullptr, nullptr);
        mEffectCursor2d.setRegisterColor(fillClr, edgeClr, 0, EGG::Effect::ERecursive::RECURSIVE_3);
        mEffectCursor2d.setRegisterAlpha(fillClr.a, edgeClr.a, 0, EGG::Effect::ERecursive::RECURSIVE_3);
        mEffectCursor2d.update();
    }
}

[[address(0x8086AEA0)]]
void daMiniGameWireMeshMgrObj_c::EffectPlayerCursor() {
    dAcPy_c *ply = daPyMng_c::getPlayer(mTurnPlayer);

    if ((((mPlayNum > 1) && mUpdateCursor) && !mIsGameFail) && (!mIsBadPanelFlip && ply)) {
        GXColor fillClr, edgeClr;

        // Set the color
        int playerType = daPyMng_c::mPlayerType[mTurnPlayer];
        if (playerType >= PLAYER_COUNT) {
            fillClr = {0xFF, 0xFF, 0xFF, 0xFF};
            edgeClr = {0xFF, 0xFF, 0xFF, 0xFF};
        } else {
            fillClr = PLY_CURSOR_EFF_COLOR_1[playerType];
            edgeClr = PLY_CURSOR_EFF_COLOR_2[playerType];
        }

        // Now position it on the player
        dPyMdlBase_c *mdl = ply->getModel();
        mMtx_c jointMtx;
        mdl->getJointMtx(&jointMtx, 1);

        nw4r::math::VEC3 transMtx;
        mVec3_c effPos;

        jointMtx.multVecZero(transMtx);
        effPos.x = transMtx.x;
        effPos.z = 5500.0f;

        float modifier, smallModifier;
        if (ply->mPlayerType >= BLUE_TOAD) {
            modifier = 8.0f;
            smallModifier = modifier;
        } else {
            smallModifier = 6.5f;
            modifier = 7.0f;
        }

        PLAYER_MODE_e mode = ply->mPlayerMode;
        mVec3_c effScale;
        float newPosY;

        if (mode == PLAYER_MODE_e::MINI_MUSHROOM) {
            smallModifier -= 2.0f;
        }
        if ((mode == PLAYER_MODE_e::NONE) || (mode == PLAYER_MODE_e::MINI_MUSHROOM)) {
            newPosY = transMtx.y + smallModifier;
            effScale = {0.6f, 0.6f, 0.6f};
        } else {
            newPosY = transMtx.y + modifier;
            effScale = {1.0f, 1.0f, 1.0f};
        }

        effPos.y = newPosY;

        mEffectCursor.createEffect("Wm_mg_cursor", 0, &effPos, 0, &effScale);
        mEffectCursor.setRegisterColor(fillClr, edgeClr, 0, EGG::Effect::ERecursive::RECURSIVE_3);
        mEffectCursor.setRegisterAlpha(fillClr.a, edgeClr.a, 0, EGG::Effect::ERecursive::RECURSIVE_3);

        if (!mHasPlayedCursorSt) {
            mEffectCursorSt.createEffect("Wm_mg_cursor_st", 0, &effPos, 0, &effScale);
            mEffectCursorSt.setRegisterColor(fillClr, edgeClr, 0, EGG::Effect::ERecursive::RECURSIVE_3);
            mEffectCursorSt.setRegisterAlpha(fillClr.a, edgeClr.a, 0, EGG::Effect::ERecursive::RECURSIVE_3);
            mEffectCursorSt.update();
            mHasPlayedCursorSt = true;
        }
    }
}

[[address(0x8086B230)]]
void daMiniGameWireMeshMgrObj_c::updateStockItem()
{
    dMj2dGame_c* save = dSaveMng_c::m_instance->getSaveGame();

    if (mWinItemCount < 1) {
        return;
    }

    for (int i = 0; i < STOCK_ITEM_COUNT; i++) {
        if (mWinStockItem[i] > 0) {
            save->setStockItem(i, save->getStockItem(i) + mWinStockItem[i]);
        }
    }
}