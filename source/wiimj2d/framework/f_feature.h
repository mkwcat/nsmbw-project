#pragma once

namespace fFeat {

// Use alignment padding space in .text functions for storing settings set by Riivolution

[[nsmbw_data(0x80006784)]]
bool unlocked_all_worlds;
[[nsmbw_data(0x80006785)]]
bool completed_all_levels;
[[nsmbw_data(0x80006786)]]
bool disable_mode_change_pause;
[[nsmbw_data(0x80006787)]]
bool infinite_lives;
[[nsmbw_data(0x80006788)]] enum class death_messages_e : u8 {
    disabled         = 0x00,
    death_and_damage = 0x01,
    death_only       = 0x02,
} death_messages;
[[nsmbw_data(0x80006789)]]
bool fall_damage;
[[nsmbw_data(0x8000678A)]]
bool disable_opening_movie;
[[nsmbw_data(0x8000678B)]]
bool always_can_exit_course;
[[nsmbw_data(0x8000678C)]]
bool shake_with_button;
[[nsmbw_data(0x8000678D)]] enum class fukidashi_mode_e : u8 {
    show_always            = 0x00,
    hide_if_5_plus_players = 0x01,
    hide_always            = 0x02,
} fukidashi_mode;
[[nsmbw_data(0x8000678E)]] enum class yoshi_color_mode_e : u8 {
    normal    = 0x00,
    random    = 0x01,
    all_green = 0x02,
} yoshi_color_mode;
[[nsmbw_data(0x8000678F)]] enum class liftable_mode_e : u8 {
    disabled     = 0x00,
    actors       = 0x01,
    actors_clone = 0x02,
    tiles        = 0x03,
} liftable_mode;
[[nsmbw_data(0x80006794)]]
bool bubble_swarm_mode;
[[nsmbw_data(0x80006795)]]
bool deadly_1up;
[[nsmbw_data(0x80006796)]]
bool all_paths_available;
[[nsmbw_data(0x80006797)]]
bool        no_projectile_limits;

inline bool mega_bowser_in_every_course = true;

} // namespace fFeat
