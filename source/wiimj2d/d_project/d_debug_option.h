#pragma once

#include "d_mj2d_game.h"

namespace dDebugOpt {

#define X(...) inline constinit __VA_ARGS__

bool X(one_player_special_hip_attack_quake) = false;
bool X(end_battles_immediately)             = false;
bool X(force_all_wm_subplayers_present)     = false;

bool X(print_base_creation)                 = false;
bool X(print_state_changes)                 = false;

namespace autoboot {
WORLD_e       X(world)                = WORLD_e::COUNT;
STAGE_e       X(stage)                = STAGE_e::COUNT;
u8            X(area)                 = 1;
u8            X(entrance)             = 0;
u8            X(num_players)          = 1;
u8            X(player_index)         = 0;
PLAYER_TYPE_e X(player_type_order)[8] = {
    PLAYER_TYPE_e::MARIO,       PLAYER_TYPE_e::LUIGI,      PLAYER_TYPE_e::YELLOW_TOAD,
    PLAYER_TYPE_e::BLUE_TOAD,   PLAYER_TYPE_e::TOADETTE,   PLAYER_TYPE_e::PURPLE_TOADETTE,
    PLAYER_TYPE_e::ORANGE_TOAD, PLAYER_TYPE_e::BLACK_TOAD,
};
PLAYER_MODE_e X(player_mode)     = PLAYER_MODE_e::NONE;
bool          X(in_star)         = false;
bool          X(on_yoshi)        = false;

bool          X(staffroll)       = false;

u8            X(movie)           = 0xFF;

u8            X(title_demo)      = 0xFF;
u8            X(hint_movie_demo) = 0XFF;
} // namespace autoboot

#undef X

void readConfig();

} // namespace dDebugOpt
