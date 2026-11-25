#pragma once

#include <framework/f_feature.h>

// Plain-old-data struct containing all of the game rules
struct dGameRule_s {
    static dGameRule_s current;

    using death_messages_e                         = fFeat::death_messages_e;
    using fukidashi_mode_e                         = fFeat::fukidashi_mode_e;
    using yoshi_color_mode_e                       = fFeat::yoshi_color_mode_e;
    using liftable_mode_e                          = fFeat::liftable_mode_e;

    bool               all_worlds_available        = fFeat::unlocked_all_worlds;
    bool               all_paths_available         = fFeat::all_paths_available;
    bool               always_can_exit_course      = fFeat::always_can_exit_course;
    bool               shake_with_button           = fFeat::shake_with_button;
    bool               disable_mode_change_pause   = fFeat::disable_mode_change_pause;
    bool               infinite_lives              = fFeat::infinite_lives;
    fukidashi_mode_e   fukidashi_mode              = fFeat::fukidashi_mode;
    yoshi_color_mode_e yoshi_color_mode            = fFeat::yoshi_color_mode;
    death_messages_e   death_messages              = fFeat::death_messages;
    liftable_mode_e    liftable_mode               = liftable_mode_e::actors_clone;
    bool               bubble_swarm_mode           = fFeat::bubble_swarm_mode;
    bool               deadly_1up                  = fFeat::deadly_1up;
    bool               mega_bowser_in_every_course = fFeat::mega_bowser_in_every_course;
};
