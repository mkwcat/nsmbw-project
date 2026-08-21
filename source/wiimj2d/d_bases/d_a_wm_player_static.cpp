// d_a_wm_player_static.cpp
// NSMBW .text: 0x80100A10 - 0x801016B0
// NSMBW .sbss: 0x8042A47E - 0x8042A484

#include "component/c_lib.h"
#include "d_a_wm_player.h"
#include "d_bases/d_a_wm_Map.h"
#include "d_static/d_a_player/d_a_player_manager.h"
#include "d_static/d_mj2d/d_mj2d_game.h"
#include "d_static/d_wm/d_wm_lib.h"

[[nsmbw_data(0x8042A480)]]
daWmPlayer_c* daWmPlayer_c::ms_instance;

[[nsmbw(0x80100A50)]]
int daWmPlayer_c::getSubPlayerNum();

[[nsmbw(0x80100B60)]]
const char* daWmPlayer_c::getSkeletonRoot(dPyMdlMng_c::ModelType_e character)
{
    switch (character) {
    case dPyMdlMng_c::ModelType_e::MODEL_MARIO:
        return "mario_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_LUIGI:
        return "luigi_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLUE:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_YELLOW:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_RED:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_BLACK:
    case dPyMdlMng_c::ModelType_e::MODEL_TOAD_ORANGE:
        return "kinopio_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_TOADETTE:
    case dPyMdlMng_c::ModelType_e::MODEL_TOADETTE_PURPLE:
        return "kinopico_all_root";

    case dPyMdlMng_c::ModelType_e::MODEL_YOSHI:
        return "yoshi_all_root";

    default:
        return nullptr;
    }
}

[[nsmbw(0x80100C50)]]
dWmSeManager_c::WmPlyVoice_e daWmPlayer_c::getCourseInVoiceId(int node)
{
    int subPlayerCount = getSubPlayerNum();
    if (subPlayerCount < 1 && daPyMng_c::mPlayerType[0] == PLAYER_TYPE_e::MARIO) {
        char* nodeName =
          daWmMap_c::m_instance->mCsvData[daWmMap_c::m_instance->mCurrentMap].GetPointName(node);
        dWmLib::StageType_e stageType =
          dWmLib::GetCourseTypeFromCourseNo(dWmLib::GetCourseNoFromPointName(nodeName));
        if (cLib::isOneOf(
              stageType, dWmLib::StageType_e::GHOST, dWmLib::StageType_e::TOWER,
              dWmLib::StageType_e::CASTLE, dWmLib::StageType_e::DOOMSHIP
            )) {
            return dWmSeManager_c::WmPlyVoice_e::COURSE_IN_HARD;
        }
        return dWmSeManager_c::WmPlyVoice_e::COURSE_IN;
    }
    return dWmSeManager_c::WmPlyVoice_e::COURSE_IN_MULTI;
}

[[nsmbw(0x801011A0)]]
bool daWmPlayer_c::isPlayerStarMode();

[[nsmbw(0x80101220)]]
void daWmPlayer_c::startStarSound();
