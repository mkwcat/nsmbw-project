// d_a_lift_remocon_seesaw.cpp
// NSMBW .text: 0x8083EBC0 - 0x8083FEC0

#include "d_a_lift_remocon_seesaw.h"
#include "d_static/d_game_common.h"
#include "d_static/d_game_key/d_game_key.h"
#include "d_static/d_mj2d/d_mj2d_game.h"
#include <algorithm>

short sSeesawAngle[PLAYER_COUNT];

[[nsmbw(0x8083F550)]]
short daLiftRemoconSeesaw_c::CalculateInitialAngle()
{
    dGameKeyCore_c* currentCore = dGameKey_c::m_instance->mpCores[mRemotePlayerID];
    if (currentCore->isClassic() || currentCore->isDolphin()) {
        short LR = currentCore->getTiltLR();
        sSeesawAngle[mRemotePlayerID] =
          std::clamp<short>(sSeesawAngle[mRemotePlayerID] + LR, -0x1a2c, 0x1a2c);
        short returnAng = sSeesawAngle[mRemotePlayerID];
        sSeesawAngle[mRemotePlayerID] = 0;
        return returnAng;
    } else {
        return dGameCom::CalculateTilt(mRemotePlayerID, 5.0, 1.0);
    }
}

[[nsmbw(0x8083F4F0)]]
short daLiftRemoconSeesaw_c::CalculateAngle()
{
    dGameKeyCore_c* currentCore = dGameKey_c::m_instance->mpCores[mRemotePlayerID];
    short angle;
    if (currentCore->isClassic() || currentCore->isDolphin()) {
        short LR = currentCore->getTiltLR();
        sSeesawAngle[mRemotePlayerID] =
          std::clamp<short>(sSeesawAngle[mRemotePlayerID] + LR, -0x1a2c, 0x1a2c);
        angle = sSeesawAngle[mRemotePlayerID];
    } else {
        angle = dGameCom::CalculateTilt(mRemotePlayerID, 5.0, 1.0);
    }
    return std::clamp<short>(angle, -0x1a2c, 0x1a2c);
}
