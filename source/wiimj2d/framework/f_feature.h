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
[[nsmbw_data(0x80006788)]] enum class DEATH_MESSAGES_MODE_e : u8 {
    DISABLED         = 0x00,
    DEATH_AND_DAMAGE = 0x01,
    DEATH_ONLY       = 0x02,
} death_messages;
[[nsmbw_data(0x80006789)]]
bool fall_damage;
[[nsmbw_data(0x8000678A)]]
bool disable_opening_movie;
[[nsmbw_data(0x8000678B)]]
bool always_can_exit_course;
[[nsmbw_data(0x8000678C)]]
bool shake_with_button;
[[nsmbw_data(0x8000678D)]] enum class FUKIDASHI_MODE_e : u8 {
    ALWAYS_SHOW           = 0x00,
    HIDE_IF_5_TO_8_PLAYER = 0x01,
    ALWAYS_HIDE           = 0x02,
} fukidashi_mode;
[[nsmbw_data(0x8000678E)]] enum class YOSHI_COLOR_MODE_e : u8 {
    NORMAL    = 0x00,
    RANDOM    = 0x01,
    ALL_GREEN = 0x02,
} yoshi_color_mode;
[[nsmbw_data(0x8000678F)]]
bool liftable_tiles;
[[nsmbw_data(0x80006794)]]
bool bubble_swarm_mode;
[[nsmbw_data(0x80006795)]]
bool deadly_1up;
[[nsmbw_data(0x80006796)]]
bool        all_paths_available;

inline bool mega_bowser_in_every_course = true;

} // namespace fFeat
