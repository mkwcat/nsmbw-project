#pragma once

#include "d_mj2d_game.h"

namespace dDebugOpt {

inline constinit bool print_base_creation                 = false;
inline constinit bool print_state_changes                 = false;
inline constinit bool print_worldmap_demo                 = false;

inline constinit bool one_player_special_hip_attack_quake = false;
inline constinit bool end_battles_immediately             = false;
inline constinit bool force_all_wm_subplayers_present     = false;
inline constinit bool disable_no_collide                  = false;

namespace autoboot {
inline constinit WORLD_e       world                = WORLD_e::COUNT;
inline constinit STAGE_e       stage                = STAGE_e::COUNT;
inline constinit u8            area                 = 1;
inline constinit u8            entrance             = 0;
inline constinit u8            num_players          = 1;
inline constinit u8            player_index         = 0;
inline constinit PLAYER_TYPE_e player_type_order[8] = {
    PLAYER_TYPE_e::MARIO,       PLAYER_TYPE_e::LUIGI,      PLAYER_TYPE_e::YELLOW_TOAD,
    PLAYER_TYPE_e::BLUE_TOAD,   PLAYER_TYPE_e::TOADETTE,   PLAYER_TYPE_e::PURPLE_TOADETTE,
    PLAYER_TYPE_e::ORANGE_TOAD, PLAYER_TYPE_e::BLACK_TOAD,
};
inline constinit PLAYER_MODE_e player_mode     = PLAYER_MODE_e::NONE;
inline constinit bool          in_star         = false;
inline constinit bool          on_yoshi        = false;

inline constinit bool          staffroll       = false;

inline constinit u8            movie           = 0xFF;

inline constinit u8            title_demo      = 0xFF;
inline constinit u8            hint_movie_demo = 0XFF;
} // namespace autoboot

void readConfig();

} // namespace dDebugOpt
