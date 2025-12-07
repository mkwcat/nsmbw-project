// d_a_wm_player_static.cpp
// NSMBW .text: 0x80100A10 - 0x801016B0
// NSMBW .sbss: 0x8042A47E - 0x8042A484

#include "d_a_wm_player.h"
#include "d_bases/d_a_wm_Map.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_wm_lib.h"

[[address_data(0x8042A480)]]
daWmPlayer_c* daWmPlayer_c::ms_instance;

[[address(0x80100A50)]]
int daWmPlayer_c::getSubPlayerNum();

[[address(0x80100B60)]]
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

    case dPyMdlMng_c::ModelType_e::MODEL_NONE:
        return nullptr;
    }

    return nullptr;
}

[[address(0x80100C50)]]
dWmSeManager_c::WmPlyVoice_e daWmPlayer_c::getCourseInVoiceId(int node)
{
    int subPlayerCount = getSubPlayerNum();
    if (subPlayerCount < 1 && daPyMng_c::mPlayerType[0] == MARIO) {
        char* nodeName =
          daWmMap_c::m_instance->mCsvData[daWmMap_c::m_instance->mCurrentMap].GetPointName(node);
        STAGE_e stage = dWmLib::GetCourseNoFromPointName(nodeName);
        STAGE_TYPE_e stageType = dWmLib::GetCourseTypeFromCourseNo(static_cast<int>(stage));
        if ((static_cast<u32>(stageType) - 1 < 3) || stageType == STAGE_TYPE_e::DOOMSHIP) {
            return dWmSeManager_c::WmPlyVoice_e::COURSE_IN_HARD;
        }
        return dWmSeManager_c::WmPlyVoice_e::COURSE_IN;
    }
    return dWmSeManager_c::WmPlyVoice_e::COURSE_IN_MULTI;
}

[[address(0x801011A0)]]
bool daWmPlayer_c::isPlayerStarMode();

[[address(0x80101220)]]
void daWmPlayer_c::startStarSound();