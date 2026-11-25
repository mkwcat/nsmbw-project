// d_a_fireball_player.cpp
// NSMBW .text: 0x8011A5B0 - 0x8011B640

#include "d_a_fireball_player.h"

#include "d_gamerule.h"
#include "d_mj2d_game.h"
#include "f_param.h"
#include <algorithm>
#include <slu/relocate.hpp>

/* 0x80375840 */
int daFireBall_Player_c::sm_FireBallCnt[PLAYER_COUNT];

/* 0x80375850 */
int daFireBall_Player_c::sm_AliveFireBallCnt[PLAYER_COUNT];

[[nsmbw(0x8011A6B0)]]
bool daFireBall_Player_c::createCheck() {
    fParam_c<daFireBall_Player_c> param = mParam;
    bool enable = isFireBallEnable(param.plrNo, static_cast<CreateKind_e>(param.createKind));

    mPlrNo = m_PlayerNo = param.plrNo;
    sm_AliveFireBallCnt[param.plrNo]++;
    sm_FireBallCnt[param.plrNo]++;
    m_Counter = 60;

    return enable;
}

[[nsmbw(0x8011AC90)]]
fBase_c::PACK_RESULT_e daFireBall_Player_c::doDelete() {
    sm_FireBallCnt[m_PlayerNo] = std::max(sm_FireBallCnt[m_PlayerNo] - 1, 0);
    if (m_Counter != 0) {
        sm_AliveFireBallCnt[m_PlayerNo] = std::max(sm_AliveFireBallCnt[m_PlayerNo] - 1, 0);
    }
    return daFireBall_Base_c::doDelete();
}

[[nsmbw(0x8011B060)]]
bool daFireBall_Player_c::isFireBallEnable(
    int plrNo, CreateKind_e createKind
) {
    if (dGameRule_s::current.no_projectile_limits) {
        return true;
    }

    return sm_FireBallCnt[plrNo] < 6 &&
           (createKind == CreateKind_e::Fast || sm_AliveFireBallCnt[plrNo] < 2);
}

PATCH_REFERENCES(
    &daFireBall_Player_c::sm_AliveFireBallCnt, //
    {
        {0x8011AD46, R_PPC_ADDR16_HA},
        {0x8011AD4A, R_PPC_ADDR16_LO},
    }
);
