// d_SmallScore.cpp
// NSMBW .text: 0x80014F10 - 0x80015D60

#include "d_SmallScore.h"

#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_info.h"
#include "d_static/d_mj2d/d_mj2d_game.h"
#include <nw4r/lyt/Material.h>
#include <nw4r/ut/Color.h>

[[nsmbw(0x80014FF0)]]
void dSmallScore_c::createLayout(d2d::ResAccMultLoader_c* res);

[[nsmbw(0x80015160)]]
void dSmallScore_c::execute();

[[nsmbw(0x800151D0)]]
void dSmallScore_c::draw();

[[nsmbw(0x800151F0)]]
void dSmallScore_c::doDelete();

[[nsmbw(0x80015200)]]
void dSmallScore_c::setPlayer1upColor(int player);

[[nsmbw(0x80015210)]]
void dSmallScore_c::setPlayer1000Color(
    int player
) {
    static constinit const nw4r::ut::Color l_PLY_COLOR_0[] = {
        "#FF7800", // Mario
        "#32FA32", // Luigi
        "#00B9DC", // Blue Toad
        "#FFFF00", // Yellow Toad
        "#FA8CFA", // Toadette
        "#B751FF", // Purple Toadette
        "#FC834C", // Orange Toad
        "#4E4E4E", // Black Toad
        "#FFFFFF",
    };

    static constinit const nw4r::ut::Color l_PLY_COLOR_2[] = {
        "#FFC828", // Mario
        "#FFFF00", // Luigi
        "#D2FFFA", // Blue Toad
        "#FFFFB4", // Yellow Toad
        "#FFD1FF", // Toadette
        "#8121C4", // Purple Toadette
        "#CE7046", // Orange Toad
        "#323232", // Black Toad
        "#FFFFFF",
    };

    int index = PLAYER_COUNT;
    if (player < PLAYER_COUNT) {
        index = daPyMng_c::getPlayerColorType(static_cast<PLAYER_TYPE_e>(player));
    }

    mpTextBoxes[T_1000_00]->SetVtxColor(0, l_PLY_COLOR_0[index]);
    mpTextBoxes[T_1000_00]->SetVtxColor(2, l_PLY_COLOR_2[index]);
}

[[nsmbw(0x800153B0)]]
void dSmallScore_c::setPlayer100Color(
    int player
) {
    static constinit const nw4r::ut::Color l_PLY_COLOR[] = {
        "#FF9655", // Mario
        "#46FA46", // Luigi
        "#46C8E6", // Blue Toad
        "#FAFF50", // Yellow Toad
        "#FA7AEF", // Toadette
        "#AD49EE", // Purple Toadette
        "#CE4F16", // Orange Toad
        "#383838", // Black Toad
        "#FAFFFF",
    };

    int index = PLAYER_COUNT;
    if (player < PLAYER_COUNT) {
        index = daPyMng_c::getPlayerColorType(static_cast<PLAYER_TYPE_e>(player));
    }

    mpTextBoxes[T_100_00]->GetMaterial()->SetTevColor(1, l_PLY_COLOR[index]);
}

[[nsmbw(0x800154E0)]]
void dSmallScore_c::chgColor() {
    if (!mEnableColorChange) {
        return;
    }
    if (++mChgColorCounter < 10) {
        return;
    }
    mChgColorCounter = 0;

    int type         = mPlayerColor;

    while (true) {
        if (++type >= PLAYER_COUNT) {
            type = 0;
            break;
        }

        if (dInfo_c::m_instance->getPlyConnectStage(type) == dInfo_c::PlyConnectStage_e::ENTER) {
            break;
        }
    }

    setPlayer1upColor(type);
    mPlayerColor = type;
}

[[nsmbw(0x80015580)]]
void dSmallScore_c::setNormalOrBlueColor();

[[nsmbw(0x800156B0)]]
void dSmallScore_c::ScissorMaskSet();

[[nsmbw(0x80015780)]]
void dSmallScore_c::BigSmallAnime();

[[nsmbw(0x80015860)]]
void dSmallScore_c::MakeStart();

[[nsmbw(0x80015A50)]]
void dSmallScore_c::UpMove();

[[nsmbw(0x80015AD0)]]
void dSmallScore_c::DispWait() {
    if (mEnableBigSmallAnim) {
        BigSmallAnime();
    }

    chgColor();

    mDispWaitCounter++;
    if (mPlayerType == PLAYER_COUNT) {
        if (mDispWaitCounter < 60) {
            return;
        }
    } else if (mDispWaitCounter < mDispWaitTime) {
        return;
    }

    mDispWaitCounter = 0;
    mpRootPane->SetVisible(false);
    mpTextBoxes[T_100_00]->SetVisible(false);
    mpTextBoxes[T_1000_00]->SetVisible(false);
    mpTextBoxes[T_red2_00]->SetVisible(false);
    mpTextBoxes[T_1UP_00]->SetVisible(false);
    mpTextBoxes[T_coin_x_00]->SetVisible(false);
    mpTextBoxes[T_coinPoint_00]->SetVisible(false);
    mpNullPanes[N_coin_00]->SetVisible(false);
    mEnableBigSmallAnim = false;
    mpTextBoxes[mCurTextbox]->SetScale(mScale);
    mState = dSmallScore_c::STATE_e::NONE;
}

[[nsmbw(0x80015C00)]]
void dSmallScore_c::GoalScoreDisp();

[[nsmbw(0x80015C10)]]
void dSmallScore_c::PositionSet();

[[nsmbw(0x80015CE0)]]
void dSmallScore_c::CreateSmallScore(const mVec3_c&, int, int);

[[nsmbw(0x80015D40)]]
void dSmallScore_c::PosSet(const mVec3_c&);
