#pragma once

#include <framework/f_feature.h>

// Plain-old-data struct containing all of the game rules
struct dGameRule_s {
    static dGameRule_s current;

    using DEATH_MESSAGES_MODE_e                       = fFeat::DEATH_MESSAGES_MODE_e;
    using FUKIDASHI_MODE_e                            = fFeat::FUKIDASHI_MODE_e;
    using YOSHI_COLOR_MODE_e                          = fFeat::YOSHI_COLOR_MODE_e;

    bool                  all_worlds_available        = fFeat::unlocked_all_worlds;
    bool                  all_paths_available         = fFeat::all_paths_available;
    bool                  always_can_exit_course      = fFeat::always_can_exit_course;
    bool                  shake_with_button           = fFeat::shake_with_button;
    bool                  disable_mode_change_pause   = fFeat::disable_mode_change_pause;
    bool                  infinite_lives              = fFeat::infinite_lives;
    FUKIDASHI_MODE_e      fukidashi_mode              = fFeat::fukidashi_mode;

    YOSHI_COLOR_MODE_e    yoshi_color_mode            = fFeat::yoshi_color_mode;
    DEATH_MESSAGES_MODE_e death_messages              = fFeat::death_messages;
    bool                  liftable_tiles              = fFeat::liftable_tiles;
    bool                  bubble_swarm_mode           = fFeat::bubble_swarm_mode;
    bool                  deadly_1up                  = fFeat::deadly_1up;
    bool                  mega_bowser_in_every_course = fFeat::mega_bowser_in_every_course;
};
