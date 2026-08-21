// d_wm_WorldSelect.cpp
// NSMBW d_bases.text: 0x80928810 - 0x8092B3E0

#include "d_wm_WorldSelect.h"

#include "d_bases/d_s_world_map.h"
#include "d_project/d_gamerule.h"
#include "d_static/d_game_key.h"
#include "sound/SndAudioMgr.h"
#include "sound/SndID.h"

[[nsmbw(0x80928EC0)]]
int dWorldSelect_c::wrapIsland(int island);

[[nsmbw(0x80928EF0)]]
float dWorldSelect_c::getIslandMoveAngle();

[[nsmbw(0x80928F50)]]
bool dWorldSelect_c::checkIslandMove(
    int island, bool isMoveRight
) {
    m_isMoveRight = isMoveRight;

    int toIsland  = isMoveRight ? island + 1 : island - 1;
    toIsland      = wrapIsland(toIsland);

    for (m_moveNum = 0; !dGameRule_s::current.all_worlds_available && !m_isWorldOpen[toIsland];
         m_moveNum++) {
        toIsland = isMoveRight ? toIsland + 1 : toIsland - 1;
        toIsland = wrapIsland(toIsland);
    }

    if (toIsland == m_currentIsland) {
        return false;
    }

    m_toIsland = toIsland;
    m_moveNum++;
    m_moveAngle = getIslandMoveAngle();
    if (!isMoveRight) {
        m_moveAngle = -m_moveAngle;
    }
    m_moveAngle2 = m_moveAngle.mAngle / 5;
    return true;
}

[[nsmbw(0x80929990)]]
void dWorldSelect_c::executeState_Select() {
    dGameKeyCore_c& core = *dGameKey_c::getCurrentCore();
    m_isMove             = false;

    if (core.checkMenuConfirm()) {
        if (dScWMap_c::getWorldNo() != static_cast<WORLD_e>(m_currentIsland)) {
            SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_SELECT_WORLD, 1);
            return m_stateMgr.changeState(StateID_DecisionAnimeEndWait);
        } else {
            SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_BACK, 1);
            return m_stateMgr.changeState(StateID_ExitAnimeEndWait);
        }
    } else if (core.checkMenuCancel() || core.isTrig(dGameKeyCore_c::MINUS)) {
        SndAudioMgr::sInstance->startSystemSe(SndID::SE_SYS_BACK, 1);
        return m_stateMgr.changeState(StateID_ExitAnimeEndWait);
    } else if (m_currentIsland == 9 - 1) {
        if (!core.checkDown()) {
            return;
        }
        m_toIsland = m_islandBeforeSpecialWorld;
        m_isMove   = true;
        return m_stateMgr.changeState(StateID_IsLandSizeDown);
    } else if ((m_isWorldOpen[9 - 1] || dGameRule_s::current.all_worlds_available) &&
               core.checkUp()) {
        m_islandBeforeSpecialWorld = m_currentIsland;
        m_toIsland                 = 9 - 1;
        m_isMove                   = true;
        return m_stateMgr.changeState(StateID_IsLandSizeDown);
    } else if (bool left = core.checkLeft();
               (left || core.checkRight()) && checkIslandMove(m_currentIsland, !left)) {
        m0x2B5 = m_moveNum / -2 < 0;
        return m_stateMgr.changeState(StateID_IsLandSizeDown);
    }
}
