#pragma once

namespace fFeature
{

extern bool UNLOCKED_ALL_WORLDS;
extern bool COMPLETED_ALL_LEVELS;
extern bool DISABLE_POWERUP_CHANGE_PAUSE;

// Replace life counter with a death counter
extern bool INFINITE_LIVES;

// Enable death messages in the bottom left of the screen
extern enum class DEATH_MESSAGES_MODE_e : u8 {
    DISABLED = 0,
    DEATH_AND_DAMAGE = 1,
    DEATH_ONLY = 2,
} DEATH_MESSAGES;

// Enable fall damage mod
extern bool FALL_DAMAGE;

extern bool DISABLE_OPENING_MOVIE;

extern bool ALWAYS_CAN_EXIT_COURSE;

extern bool SHAKE_WITH_BUTTON;

extern enum class FUKIDASHI_MODE_e : u8 {
    ALWAYS_SHOW = 0,
    HIDE_IF_5_TO_8_PLAYER = 1,
    ALWAYS_HIDE = 2,
} FUKIDASHI_MODE;

extern enum class YOSHI_COLOR_MODE_e : u8 {
    NORMAL = 0,
    RANDOM = 1,
    ALL_GREEN = 2,
} YOSHI_COLOR_MODE;

} // namespace fFeature