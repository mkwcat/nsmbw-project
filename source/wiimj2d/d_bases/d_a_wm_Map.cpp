// d_a_wm_Map.cpp
// NSMBW d_bases.text: 0x808DEA90 - 0x808E3700

#include "d_a_wm_Map.h"

#include "d_bases/d_s_world_map.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_wm_connect.h"
#include "d_system/d_wm_lib.h"
#include "framework/f_feature.h"

[[nsmbw(0x808DFE50)]]
void daWmMap_c::createEnemyActors();

[[nsmbw(0x808E1750)]]
void daWmMap_c::createMapActors();

EXTERN_REPL(0x808E2250, bool daWmMap_c::IsRouteOpen2(const char* routeName));

[[nsmbw(0x808E2250)]]
bool daWmMap_c::IsRouteOpen(
    const char* routeName
) {
    if (fFeat::all_paths_available) {
        return true;
    }
    return IsRouteOpen2(routeName);
}

EXTERN_REPL(
    0x808E2380, bool daWmMap_c::IsIbaraRouteOpen2(const char* subRoute1, const char* subRoute2)
);

[[nsmbw(0x808E2380)]]
bool daWmMap_c::IsIbaraRouteOpen(
    const char* subRoute1, const char* subRoute2
) {
    if (fFeat::all_paths_available) {
        return true;
    }

    return IsIbaraRouteOpen2(subRoute1, subRoute2);
}

void daWmMap_c::setNodeRndizer() {
    if (m_setStageRndizer == STAGE_e::COUNT) {
        return;
    }

    const dInfo_c::StageNo_s stage = {dScWMap_c::m_WorldNo, m_setStageRndizer};
    m_setStageRndizer              = STAGE_e::COUNT;
    if (stage.isEnemy()) {
        return;
    }

    dInfo_c* info         = dInfo_c::m_instance;
    info->mCurrentWorldNo = static_cast<int>(stage.world);
    info->mCurrentStageNo = static_cast<int>(stage.stage);

    if (dWmConnect_c::dPnt_c* point = mConnect[mCurrentMap].GetConnectFromCourseNo(
            static_cast<dWmLib::CourseNo>(stage.stage)
        )) {
        info->mWmNode = point->GetIndex();
    }
}
