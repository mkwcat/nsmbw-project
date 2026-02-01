#pragma once

namespace fFeat
{

// Use alignment padding space in .text functions for storing settings set by Riivolution

[[nsmbw_data(0x80006784)]] bool unlocked_all_worlds;
[[nsmbw_data(0x80006785)]] bool completed_all_levels;
[[nsmbw_data(0x80006786)]] bool disable_mode_change_pause;
[[nsmbw_data(0x80006787)]] bool infinite_lives;
[[nsmbw_data(0x80006788)]] enum class DEATH_MESSAGES_MODE_e : u8 {
    DISABLED = 0,
    DEATH_AND_DAMAGE = 1,
    DEATH_ONLY = 2,
} death_messages;
[[nsmbw_data(0x80006789)]] bool fall_damage;
[[nsmbw_data(0x8000678A)]] bool disable_opening_movie;
[[nsmbw_data(0x8000678B)]] bool always_can_exit_course;
[[nsmbw_data(0x8000678C)]] bool shake_with_button;
[[nsmbw_data(0x8000678D)]] enum class FUKIDASHI_MODE_e : u8 {
    ALWAYS_SHOW = 0,
    HIDE_IF_5_TO_8_PLAYER = 1,
    ALWAYS_HIDE = 2,
} fukidashi_mode;
[[nsmbw_data(0x8000678E)]] enum class YOSHI_COLOR_MODE_e : u8 {
    NORMAL = 0,
    RANDOM = 1,
    ALL_GREEN = 2,
} yoshi_color_mode;
constexpr bool bubble_swarm_mode = false;
constexpr bool deadly_1up = false;
constexpr bool pipe_randomizer = true;

// Debugging features
// ^^^^^^

constexpr u8 autoboot_world = 0;
constexpr u8 autoboot_stage = 0;
constexpr u8 autoboot_course = 0;
constexpr u8 autoboot_next_goto = 1 + 0;
constexpr u8 autoboot_player_count = 0;
constexpr u8 autoboot_player_index = 0;
constexpr u8 autoboot_powerup = 0;
constexpr bool autoboot_in_star = false;
constexpr bool autoboot_on_yoshi = false;

constexpr u8 autoboot_movie = 0;

constexpr bool autoboot_staffroll = false;

constexpr bool one_player_special_hip_attack_quake = false;

} // namespace fFeat