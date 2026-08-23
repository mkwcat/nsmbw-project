target_include_directories(project PRIVATE
    .
    d_actors
    d_layouts
    d_scenes
)

#
# WIIMJ2D.dol
# NSMBW          .text:  0x8010A3D0 - 0x8015F270
#
target_sources(project PRIVATE
# NSMBW          .text:  0x8010A3D0 - 0x8010B050
  # <UNKNOWN>
# NSMBW          .text:  0x8010B050 - 0x8010C130
  # d_layouts/d_GoalManager.cpp
# NSMBW          .text:  0x8010C130 - 0x8010CAE0
    d_layouts/d_SelectCursor.cpp
# NSMBW          .text:  0x8010CAE0 - 0x8010D270
    d_layouts/d_SmallScoreManager.cpp
# NSMBW          .text:  0x8010D270 - 0x8010F080
    d_layouts/d_WarningManager.cpp
# NSMBW          .text:  0x8010F080 - 0x8010F530
    d_layouts/d_WiiStrap.cpp
# NSMBW          .text:  0x8010F530 - 0x8010F9A0
    d_actors/d_a_cursor.cpp
# NSMBW          .text:  0x8010F9A0 - 0x801102B0
    d_actors/d_a_en_eat_coin.cpp
# NSMBW          .text:  0x801102B0 - 0x80114C00
    d_actors/d_a_en_hatena_balloon.cpp
# NSMBW          .text:  0x80114C00 - 0x80115BD0
    d_actors/d_a_enemy_ice.cpp
# NSMBW          .text:  0x80115BD0 - 0x8011A5B0
    d_actors/d_a_farBG.cpp
# NSMBW          .text:  0x8011A5B0 - 0x8011B640
    d_actors/d_a_fireball_player.cpp
# NSMBW          .text:  0x8011B640 - 0x801233F0
    d_actors/d_a_ice.cpp
# NSMBW          .text:  0x801233F0 - 0x80124D40
    d_actors/d_a_iceball.cpp
# NSMBW          .text:  0x80124D40 - 0x80124EB0
    d_actors/d_a_last_actor.cpp
# NSMBW          .text:  0x80124EB0 - 0x80126650
    d_actors/d_a_mask.cpp
# NSMBW          .text:  0x80126650 - 0x8014A830
    d_actors/d_a_player.cpp
# NSMBW          .text:  0x8014A830 - 0x8014B400
    d_actors/d_a_player_ice.cpp
# NSMBW          .text:  0x8014B400 - 0x80154800
    d_actors/d_a_yoshi.cpp
# NSMBW          .text:  0x80154800 - 0x80156FE0
    d_bg_gm.cpp
# nsmbw-project
    d_layouts/d_death_message_mgr.cpp
# NSMBW          .text:  0x80156FE0 - 0x80157820
    d_layouts/d_fukidashiManager.cpp
# NSMBW          .text:  0x80157820 - 0x8015A480
    d_layouts/d_gamedisplay.cpp
# NSMBW          .text:  0x8015A480 - 0x8015BA70
    d_layouts/d_pausewindow.cpp
# NSMBW          .text:  0x8015BA70 - 0x8015F270
    d_scenes/d_s_boot.cpp
)
