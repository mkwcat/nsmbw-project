// d_s_World9DeMo.cpp
// NSMBW d_bases.text: 0x8091CB70 - 0x8091EB60

#include "d_s_World9DeMo.h"

#include "d_bases/d_wm_effectManager.h"
#include "d_static/d_a_player_manager.h"
#include "d_static/d_fader.h"
#include "d_static/d_info.h"
#include "d_static/d_mj2d_game.h"
#include "d_static/d_save_manager.h"
#include "d_static/d_system.h"
#include "machine/m_pad.h"
#include <revolution/vi.h>

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x8091D350)]]
fBase_c::PACK_RESULT_e dScWorld9DeMo_c::create()
{
    dFader_c::setFader(dFader_c::fader_type_e::FADE);

    dSys_c::setClearColor(nw4r::ut::Color{0, 0, 0, 255});
    mPad::setCurrentChannel(mPad::CH_e::CHAN_0);

    initLight();

    dInfo_c::m_instance->m0xAFC = 0;

    dWmEffectManager_c::construct();

    dMj2dGame_c* saveGame = dSaveMng_c::m_instance->getSaveGame();
    mIsWorld9AlreadyOpen = !!saveGame->isWorldDataFlag(
      WORLD_e::WORLD_9, dMj2dGame_c::WORLD_COMPLETION_e::WORLD_UNLOCKED
    );

    saveGame->onWorldDataFlag(WORLD_e::WORLD_9, dMj2dGame_c::WORLD_COMPLETION_e::WORLD_UNLOCKED);

    // Make sure all players have at least 5 lives
    for (int& rest : daPyMng_c::mRest) {
        if (rest < 5) {
            rest = 5;
        }
    }

    VIEnableDimming(true);

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x8091DEC0)]]
void dScWorld9DeMo_c::initLight();
