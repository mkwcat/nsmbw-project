target_include_directories(project PRIVATE
    d_a_boss_demo
    d_a_floor
    d_a_jr
    d_a_lift
    d_a_mini_game
    d_a_obj
    d_a_tarzan
    d_a_wm
    d_actors
    d_layouts
    d_scenes
    d_wm
)

#
# WIIMJ2D.dol
# NSMBW          .text:  0x801000F0 - 0x80106F00
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80100140 - 0x80100A10
    d_a_wm/d_a_wm_Map_static.cpp
# NSMBW          .text:  0x80100A10 - 0x801016B0
# NSMBW          .sbss:  0x8042A47E - 0x8042A484
    d_a_wm/d_a_wm_player_static.cpp

# NSMBW          .text:  0x801018C0 - 0x801018E0
  # d_profile_static.cpp # Moved to d_profile
# NSMBW          .sbss:  0x8042A490 - 0x8042A498
    d_scenes/d_s_crsin_static.cpp
# NSMBW          .text:  0x801018E0 - 0x80101A50
    d_scenes/d_s_restart_crsin_static.cpp
# NSMBW          .text:  0x80101A50 - 0x80102770
    d_scenes/d_s_stage_static.cpp
# NSMBW          .text:  0x80101A50 - 0x80102770
    d_scenes/d_s_world_map.cpp
# NSMBW          .text:  0x80102770 - 0x80102DB0
    d_scenes/d_s_world_map_static.cpp
# NSMBW          .text:  0x80103020 - 0x801038D0
    d_wm/d_wm_effectManager.cpp
# NSMBW          .text:  0x80103F50 - 0x801060E0
    d_wm/d_wm_seManager.cpp
# NSMBW          .text:  0x801060E0 - 0x80106F00
# NSMBW          .sbss:  0x8042A560 - 0x8042A568
    d_wm/d_world_camera_static.cpp
)

#
# d_bases.rel
# NSMBW   d_bases.text:  0x8076D880 - 0x8092F020
#
target_sources(project PRIVATE
# NSMBW   d_bases.text:  0x8076D880 - 0x8076DEE0
    d_layouts/d_CharacterChangeIndicator.cpp
# NSMBW   d_bases.text:  0x8076DEE0 - 0x8076F350
    d_layouts/d_CharacterChangeSelectArrow.cpp
# NSMBW   d_bases.text:  0x8076F350 - 0x80772A50
    d_layouts/d_CharacterChangeSelectBase.cpp
# NSMBW   d_bases.text:  0x80772A50 - 0x80773F30
    d_layouts/d_CharacterChangeSelectContents.cpp
# NSMBW   d_bases.text:  0x80773F30 - 0x80776150
  # d_layouts/d_CollectionCoin.cpp
# NSMBW   d_bases.text:  0x80776150 - 0x80776570
  # d_layouts/d_CollectionCoinBase.cpp
# NSMBW   d_bases.text:  0x80776570 - 0x807775E0
  # d_layouts/d_CollectionCoinDate.cpp
# NSMBW   d_bases.text:  0x807775E0 - 0x80779650
    d_layouts/d_Continue.cpp
# NSMBW   d_bases.text:  0x80779650 - 0x8077A750
  # d_layouts/d_CourseClear.cpp
# NSMBW   d_bases.text:  0x8077A750 - 0x8077BB00
    d_layouts/d_CourseSelectMenu.cpp
# NSMBW   d_bases.text:  0x8077BB00 - 0x8077CAE0
  # d_layouts/d_CourseTimeUp.cpp
# NSMBW   d_bases.text:  0x8077CAE0 - 0x8077E590
  # d_layouts/d_DateFile.cpp
# NSMBW   d_bases.text:  0x8077E590 - 0x8077F450
  # d_layouts/d_DemoMessage.cpp
# NSMBW   d_bases.text:  0x8077F450 - 0x807801F0
  # d_layouts/d_DrawGame.cpp
# NSMBW   d_bases.text:  0x807801F0 - 0x80781980
  # d_layouts/d_EasyPairing.cpp
# NSMBW   d_bases.text:  0x80781980 - 0x80782AB0
    d_layouts/d_EventOpeningTitle.cpp
# NSMBW   d_bases.text:  0x80782AB0 - 0x80788510
  # d_layouts/d_FileSelect.cpp
# NSMBW   d_bases.text:  0x80788510 - 0x80789810
    d_layouts/d_GameOver.cpp
# NSMBW   d_bases.text:  0x80789810 - 0x80789BB0
  # d_layouts/d_InfoWindow.cpp
# NSMBW   d_bases.text:  0x80789BB0 - 0x8078AD30
  # d_layouts/d_LetterWindow.cpp
# NSMBW   d_bases.text:  0x8078AD30 - 0x8078BC60
  # d_layouts/d_MessageWindow.cpp
# NSMBW   d_bases.text:  0x8078BC60 - 0x8078DA20
    d_layouts/d_MiniGameCannon.cpp
# NSMBW   d_bases.text:  0x8078DA20 - 0x80790450
    d_layouts/d_MiniGameWire.cpp
# NSMBW   d_bases.text:  0x80790450 - 0x807916F0
  # d_layouts/d_ModeSelect.cpp
# NSMBW   d_bases.text:  0x807916F0 - 0x80792B00
  # d_layouts/d_ModelPlayArrow.cpp
# NSMBW   d_bases.text:  0x80792B00 - 0x80793E60
  # d_layouts/d_ModelPlayBase.cpp
# NSMBW   d_bases.text:  0x80793E60 - 0x80794F90
  # d_layouts/d_ModelPlayDate.cpp
# NSMBW   d_bases.text:  0x80794F90 - 0x80795290
  # d_layouts/d_ModelPlayGuide.cpp
# NSMBW   d_bases.text:  0x80795290 - 0x80798920
    d_layouts/d_ModelPlayManager.cpp
# NSMBW   d_bases.text:  0x80798920 - 0x8079D540
    d_layouts/d_MultiCourseSelect.cpp
# NSMBW   d_bases.text:  0x8079D540 - 0x8079F630
  # d_layouts/d_MultiCourseSelectContents.cpp
# NSMBW   d_bases.text:  0x8079F630 - 0x807A2CF0
    d_layouts/d_NumberOfPeopleChange.cpp
# NSMBW   d_bases.text:  0x807A2CF0 - 0x807A3F50
  # d_layouts/d_OtehonClear.cpp
# NSMBW   d_bases.text:  0x807A3F50 - 0x807A7770
    d_layouts/d_PointResultDateFile.cpp
# NSMBW   d_bases.text:  0x807A7770 - 0x807A89C0
  # d_layouts/d_PointResultDateFileFree.cpp
# NSMBW   d_bases.text:  0x807A89C0 - 0x807ABE10
  # d_layouts/d_PointResultMulti.cpp
# NSMBW   d_bases.text:  0x807ABE10 - 0x807AD5F0
    d_layouts/d_SelectPlayer.cpp
# NSMBW   d_bases.text:  0x807AD5F0 - 0x807ADAD0
  # d_layouts/d_SequenceBG.cpp
# NSMBW   d_bases.text:  0x807ADAD0 - 0x807AF370
    d_layouts/d_StaffCreditScore.cpp
# NSMBW   d_bases.text:  0x807AF370 - 0x807B2030
    d_layouts/d_StockItem.cpp
# NSMBW   d_bases.text:  0x807B2030 - 0x807B2540
  # d_layouts/d_StockItemShadow.cpp
# NSMBW   d_bases.text:  0x807B2540 - 0x807B32D0
  # d_layouts/d_TheEnd.cpp
# NSMBW   d_bases.text:  0x807B32D0 - 0x807B40A0
  # d_layouts/d_TimeUp.cpp
# NSMBW   d_bases.text:  0x807B40A0 - 0x807B77D0
  # d_actors/d_a_BG_polygon.cpp
# NSMBW   d_bases.text:  0x807B77D0 - 0x807B8840
  # d_actors/d_a_autoscrool_swich.cpp
# NSMBW   d_bases.text:  0x807B8840 - 0x807B8EA0
  # d_actors/d_a_awa.cpp
# NSMBW   d_bases.text:  0x807B8EA0 - 0x807B91B0
  # d_actors/d_a_barnar_mgr.cpp
# NSMBW   d_bases.text:  0x807B91B0 - 0x807B9A20
  # d_actors/d_a_battle_game.cpp
# NSMBW   d_bases.text:  0x807B9A20 - 0x807BA110
  # d_actors/d_a_battle_in_kinopio.cpp
# NSMBW   d_bases.text:  0x807BA110 - 0x807BAC60
  # d_actors/d_a_battle_item.cpp
# NSMBW   d_bases.text:  0x807BAC60 - 0x807BBC70
  # d_actors/d_a_belt_needle.cpp
# NSMBW   d_bases.text:  0x807BBC70 - 0x807BBDA0
  # d_actors/d_a_bg_center.cpp
# NSMBW   d_bases.text:  0x807BBDA0 - 0x807BD820
  # d_actors/d_a_bgm_interlocking_dummy_block.cpp
# NSMBW   d_bases.text:  0x807BD820 - 0x807BE0F0
  # d_actors/d_a_bgm_interlocking_dummy_block_mgr.cpp
# NSMBW   d_bases.text:  0x807BE0F0 - 0x807BEA10
  # d_actors/d_a_big_shell.cpp
# NSMBW   d_bases.text:  0x807BEA10 - 0x807BF760
  # d_actors/d_a_bighana_mgr.cpp
# NSMBW   d_bases.text:  0x807BF760 - 0x807BFDE0
  # d_actors/d_a_copyright.cpp
# NSMBW   d_bases.text:  0x807BFDE0 - 0x807C00A0
  # d_actors/d_a_block_coin.cpp
# NSMBW   d_bases.text:  0x807C00A0 - 0x807C0180
  # d_actors/d_a_block_group.cpp
# NSMBW   d_bases.text:  0x807C0180 - 0x807C0E60
  # d_actors/d_a_block_light.cpp
# NSMBW   d_bases.text:  0x807C0E60 - 0x807C1100
  # d_actors/d_a_block_oneup.cpp
# NSMBW   d_bases.text:  0x807C1100 - 0x807C35A0
  # d_actors/d_a_block_taru.cpp
# NSMBW   d_bases.text:  0x807C35A0 - 0x807C4370
  # d_actors/d_a_block_wind_tag.cpp
# NSMBW   d_bases.text:  0x807C4370 - 0x807C6AE0
  # d_actors/d_a_bomb_jr_c.cpp
# NSMBW   d_bases.text:  0x807C6AE0 - 0x807C7EF0
  # d_actors/d_a_boomerang.cpp
# NSMBW   d_bases.text:  0x807C7EF0 - 0x807C8BA0
  # d_a_boss_demo/d_a_boss_kameck_demo.cpp
# NSMBW   d_bases.text:  0x807C8BA0 - 0x807C9500
  # d_actors/d_a_boss_koopa_bg_effect.cpp
# NSMBW   d_bases.text:  0x807C9500 - 0x807D0070
    d_a_boss_demo/d_a_boss_koopa_demo.cpp
# NSMBW   d_bases.text:  0x807D0070 - 0x807D2AC0
    d_a_boss_demo/d_a_boss_koopa_jr_demo.cpp
# NSMBW   d_bases.text:  0x807D2AC0 - 0x807D40E0
  # d_actors/d_a_boss_koopa_rubble.cpp
# NSMBW   d_bases.text:  0x807D40E0 - 0x807D4E60
  # d_actors/d_a_boss_koopa_scaffold.cpp
# NSMBW   d_bases.text:  0x807D4E60 - 0x807D4F20
  # d_actors/d_a_branch.cpp
# NSMBW   d_bases.text:  0x807D4F20 - 0x807D5B00
  # d_actors/d_a_bros_iceball.cpp
# NSMBW   d_bases.text:  0x807D5B00 - 0x807D5C60
  # d_actors/d_a_bubble_water.cpp
# NSMBW   d_bases.text:  0x807D5C60 - 0x807D63E0
  # d_actors/d_a_cage_block.cpp
# NSMBW   d_bases.text:  0x807D63E0 - 0x807D8630
  # d_actors/d_a_cannon_pipe.cpp
# NSMBW   d_bases.text:  0x807D8630 - 0x807D94F0
  # d_actors/d_a_castle_boss_door.cpp
# NSMBW   d_bases.text:  0x807D94F0 - 0x807DAC10
  # d_actors/d_a_castle_boss_key.cpp
# NSMBW   d_bases.text:  0x807DAC10 - 0x807DCD80
    d_a_boss_demo/d_a_castle_kokoopa_demo_1st.cpp
# NSMBW   d_bases.text:  0x807DCD80 - 0x807DDCC0
    d_a_boss_demo/d_a_castle_kokoopa_demo_2nd.cpp
# NSMBW   d_bases.text:  0x807DDCC0 - 0x807E06A0
  # d_actors/d_a_castle_lemmy_ball.cpp
# NSMBW   d_bases.text:  0x807E06A0 - 0x807E1420
  # d_actors/d_a_castle_lemmy_throw_ball.cpp
# NSMBW   d_bases.text:  0x807E1420 - 0x807E1A00
  # d_actors/d_a_chenge_block.cpp
# NSMBW   d_bases.text:  0x807E1A00 - 0x807E2040
  # d_actors/d_a_choropoo_shadow.cpp
# NSMBW   d_bases.text:  0x807E2040 - 0x807E38A0
    d_actors/d_a_chukan_point.cpp
# NSMBW   d_bases.text:  0x807E38A0 - 0x807E3B50
  # d_actors/d_a_circle_right.cpp
# NSMBW   d_bases.text:  0x807E3B50 - 0x807E4DB0
  # d_actors/d_a_dokan_cannon.cpp
# NSMBW   d_bases.text:  0x807E4DB0 - 0x807E4E80
  # d_actors/d_a_dummy_actor.cpp
# NSMBW   d_bases.text:  0x807E4E80 - 0x807E5260
  # d_actors/d_a_dummy_door.cpp
# NSMBW   d_bases.text:  0x807E5260 - 0x807E5310
  # d_actors/d_a_dummy_door_child.cpp
# NSMBW   d_bases.text:  0x807E5310 - 0x807E53C0
  # d_actors/d_a_dummy_door_parent.cpp
# NSMBW   d_bases.text:  0x807E53C0 - 0x807E70F0
  # d_actors/d_a_elastic_kinoko.cpp
# NSMBW   d_bases.text:  0x807E70F0 - 0x807E7680
  # d_actors/d_a_elastic_kinoko_parent.cpp
# NSMBW   d_bases.text:  0x807E7680 - 0x807E84D0
  # d_actors/d_a_fall_fire.cpp
# NSMBW   d_bases.text:  0x807E84D0 - 0x807E90F0
  # d_actors/d_a_fire_blitz.cpp
# NSMBW   d_bases.text:  0x807E90F0 - 0x807E9D10
  # d_actors/d_a_fireball_bros.cpp
# NSMBW   d_bases.text:  0x807E9D10 - 0x807EAB70
    d_actors/d_a_fireball_pakkun.cpp
# NSMBW   d_bases.text:  0x807EAB70 - 0x807ECB50
  # d_actors/d_a_flag_obj.cpp
# NSMBW   d_bases.text:  0x807ECB50 - 0x807EEC80
    d_a_floor/d_a_floor_dokan_eight.cpp
# NSMBW   d_bases.text:  0x807EEC80 - 0x807EF7A0
  # d_a_floor/d_a_floor_gyration.cpp
# NSMBW   d_bases.text:  0x807EF7A0 - 0x807F0DA0
  # d_a_floor/d_a_floor_hole_dokan.cpp
# NSMBW   d_bases.text:  0x807F0DA0 - 0x807F1950
  # d_a_floor/d_a_floor_jr_a.cpp
# NSMBW   d_bases.text:  0x807F1950 - 0x807F1A00
  # d_a_floor/d_a_floor_jr_b.cpp
# NSMBW   d_bases.text:  0x807F1A00 - 0x807F2D30
    d_a_floor/d_a_floor_jr_c.cpp
# NSMBW   d_bases.text:  0x807F2D30 - 0x807F4ED0
  # d_a_floor/d_a_floor_jr_c_mgr.cpp
# NSMBW   d_bases.text:  0x807F4ED0 - 0x807F50D0
  # d_actors/d_a_flydokan_down.cpp
# NSMBW   d_bases.text:  0x807F50D0 - 0x807F53A0
  # d_actors/d_a_flydokan_left.cpp
# NSMBW   d_bases.text:  0x807F53A0 - 0x807F55B0
  # d_actors/d_a_flydokan_right.cpp
# NSMBW   d_bases.text:  0x807F55B0 - 0x807F5790
  # d_actors/d_a_flydokan_up.cpp
# NSMBW   d_bases.text:  0x807F5790 - 0x807F70C0
  # d_actors/d_a_foo_ball.cpp
# NSMBW   d_bases.text:  0x807F70C0 - 0x807F7A90
  # d_actors/d_a_freefall.cpp
# NSMBW   d_bases.text:  0x807F7A90 - 0x807F8A60
  # d_actors/d_a_freezer.cpp
# NSMBW   d_bases.text:  0x807F8A60 - 0x807FB4A0
  # d_actors/d_a_gabon_rock.cpp
# NSMBW   d_bases.text:  0x807FB4A0 - 0x807FC750
  # d_actors/d_a_gear_gyration.cpp
# NSMBW   d_bases.text:  0x807FC750 - 0x807FCBA0
  # d_actors/d_a_groupid.cpp
# NSMBW   d_bases.text:  0x807FCBA0 - 0x807FD830
  # d_actors/d_a_hammer.cpp
# NSMBW   d_bases.text:  0x807FD830 - 0x807FD930
  # d_actors/d_a_hana_mountain.cpp
# NSMBW   d_bases.text:  0x807FD930 - 0x807FEAD0
  # d_actors/d_a_hand_right.cpp
# NSMBW   d_bases.text:  0x807FEAD0 - 0x807FEE40
  # d_actors/d_a_ice_ashiba.cpp
# NSMBW   d_bases.text:  0x807FEE40 - 0x807FF230
  # d_actors/d_a_ice_ashiba_rail.cpp
# NSMBW   d_bases.text:  0x807FF230 - 0x807FFFA0
  # d_actors/d_a_ice_ashiba_water.cpp
# NSMBW   d_bases.text:  0x807FFFA0 - 0x80800D30
  # d_actors/d_a_icecube.cpp
# NSMBW   d_bases.text:  0x80800D30 - 0x80801CC0
  # d_actors/d_a_icelump.cpp
# NSMBW   d_bases.text:  0x80801CC0 - 0x80804030
  # d_actors/d_a_intermittent.cpp
# NSMBW   d_bases.text:  0x80804030 - 0x80804D50
  # d_actors/d_a_item_key.cpp
# NSMBW   d_bases.text:  0x80804D50 - 0x80804E70
  # d_actors/d_a_iwao_rock.cpp
# NSMBW   d_bases.text:  0x80804E70 - 0x80806930
  # d_a_jr/d_a_jr_clown_a.cpp
# NSMBW   d_bases.text:  0x80806930 - 0x8080B210
  # d_a_jr/d_a_jr_clown_b.cpp
# NSMBW   d_bases.text:  0x8080B210 - 0x8080EC40
  # d_a_jr/d_a_jr_clown_c.cpp
# NSMBW   d_bases.text:  0x8080EC40 - 0x8080F910
  # d_a_jr/d_a_jr_clown_for_jr_c_demo.cpp
# NSMBW   d_bases.text:  0x8080F910 - 0x80813760
    d_a_jr/d_a_jr_clown_for_player.cpp
# NSMBW   d_bases.text:  0x80813760 - 0x80815BE0
  # d_a_jr/d_a_jr_fire.cpp
# NSMBW   d_bases.text:  0x80815BE0 - 0x80816D50
  # d_a_jr/d_a_jr_floor_fire.cpp
# NSMBW   d_bases.text:  0x80816D50 - 0x80818D00
  # d_a_boss_demo/d_a_kameck_for_airship_demo.cpp
# NSMBW   d_bases.text:  0x80818D00 - 0x8081B7B0
  # d_a_boss_demo/d_a_kameck_for_castle_demo.cpp
# NSMBW   d_bases.text:  0x8081B7B0 - 0x8081C830
  # d_actors/d_a_kameck_magic.cpp
# NSMBW   d_bases.text:  0x8081C830 - 0x8081CF40
  # d_actors/d_a_kanban_arrow.cpp
# NSMBW   d_bases.text:  0x8081CF40 - 0x8081D8F0
  # d_actors/d_a_katamukiyuka.cpp
# NSMBW   d_bases.text:  0x8081D8F0 - 0x8081DA10
  # d_actors/d_a_kawanagare.cpp
# NSMBW   d_bases.text:  0x8081DA10 - 0x8081EB80
  # d_actors/d_a_kazan_mgr.cpp
# NSMBW   d_bases.text:  0x8081EB80 - 0x8081FDB0
  # d_actors/d_a_kazan_rock.cpp
# NSMBW   d_bases.text:  0x8081FDB0 - 0x80820A40
  # d_actors/d_a_keronpa_fire.cpp
# NSMBW   d_bases.text:  0x80820A40 - 0x80821EF0
  # d_actors/d_a_kinoko_lift.cpp
# NSMBW   d_bases.text:  0x80821EF0 - 0x80821FE0
  # d_actors/d_a_kinoko_lift_parent.cpp
# NSMBW   d_bases.text:  0x80821FE0 - 0x80824460
  # d_actors/d_a_kokoopa_ball.cpp
# NSMBW   d_bases.text:  0x80824460 - 0x808264F0
  # d_actors/d_a_kokoopa_ring.cpp
# NSMBW   d_bases.text:  0x808264F0 - 0x80827980
  # d_actors/d_a_kokoopa_search_fire.cpp
# NSMBW   d_bases.text:  0x80827980 - 0x80828020
  # d_actors/d_a_kokoopa_threeway_blitz.cpp
# NSMBW   d_bases.text:  0x80828020 - 0x80829C90
  # d_actors/d_a_koopa_fire.cpp
# NSMBW   d_bases.text:  0x80829C90 - 0x8082C1B0
  # d_a_boss_demo/d_a_koopa_jr_for_castle_demo.cpp
# NSMBW   d_bases.text:  0x8082C1B0 - 0x8082CCB0
  # d_a_boss_demo/d_a_koopa_ship_for_airship_demo.cpp
# NSMBW   d_bases.text:  0x8082CCB0 - 0x8082E1F0
  # d_a_boss_demo/d_a_koopa_ship_for_castle_demo.cpp
# NSMBW   d_bases.text:  0x8082E1F0 - 0x8082ED60
  # d_actors/d_a_ladder.cpp
# NSMBW   d_bases.text:  0x8082ED60 - 0x80830690
  # d_actors/d_a_larry_fire.cpp
# NSMBW   d_bases.text:  0x80830690 - 0x80830C40
    d_actors/d_a_lastactor_stage.cpp
# NSMBW   d_bases.text:  0x80830C40 - 0x80833400
  # d_actors/d_a_lemmy_ball.cpp
# NSMBW   d_bases.text:  0x80833400 - 0x80833430
  # d_actors/d_a_lemmy_foothold.cpp
# NSMBW   d_bases.text:  0x80833430 - 0x808349E0
  # d_actors/d_a_lemmy_foothold_main.cpp
# NSMBW   d_bases.text:  0x808349E0 - 0x80835A00
  # d_a_lift/d_a_lift_balance.cpp
# NSMBW   d_bases.text:  0x80835A00 - 0x80836700
  # d_a_lift/d_a_lift_dokan.cpp
# NSMBW   d_bases.text:  0x80836700 - 0x80836B20
  # d_a_lift/d_a_lift_down_on.cpp
# NSMBW   d_bases.text:  0x80836B20 - 0x80837370
  # d_a_lift/d_a_lift_down_on_normal.cpp
# NSMBW   d_bases.text:  0x80837370 - 0x80838020
    d_a_lift/d_a_lift_fall.cpp
# NSMBW   d_bases.text:  0x80838020 - 0x808392F0
  # d_a_lift/d_a_lift_huriko.cpp
# NSMBW   d_bases.text:  0x808392F0 - 0x808395C0
  # d_a_lift/d_a_lift_huriko_center.cpp
# NSMBW   d_bases.text:  0x808395C0 - 0x80839680
  # d_a_lift/d_a_lift_ice_spring.cpp
# NSMBW   d_bases.text:  0x80839680 - 0x8083A6D0
  # d_a_lift/d_a_lift_line.cpp
# NSMBW   d_bases.text:  0x8083A6D0 - 0x8083B4E0
  # d_a_lift/d_a_lift_objbg_hmove.cpp
# NSMBW   d_bases.text:  0x8083B4E0 - 0x8083C020
  # d_a_lift/d_a_lift_objbg_vmove.cpp
# NSMBW   d_bases.text:  0x8083C020 - 0x8083EAF0
    d_a_lift/d_a_lift_remocon_balance.cpp
# NSMBW   d_bases.text:  0x8083EAF0 - 0x8083EBC0
  # d_a_lift/d_a_lift_remocon_balance_clinch.cpp
# NSMBW   d_bases.text:  0x8083EBC0 - 0x8083EBF0
    d_a_lift/d_a_lift_remocon_seesaw.cpp
# NSMBW   d_bases.text:  0x8083EBF0 - 0x8083FEC0
  # d_a_lift/d_a_lift_remocon_seesaw_boss.cpp
# NSMBW   d_bases.text:  0x8083FEC0 - 0x80841B30
  # d_a_lift/d_a_lift_remocon_xline.cpp
# NSMBW   d_bases.text:  0x80841B30 - 0x80842910
  # d_a_lift/d_a_lift_ride_hmove.cpp
# NSMBW   d_bases.text:  0x80842910 - 0x80844BF0
  # d_a_lift/d_a_lift_ride_off.cpp
# NSMBW   d_bases.text:  0x80844BF0 - 0x80845940
  # d_a_lift/d_a_lift_ride_vmove.cpp
# NSMBW   d_bases.text:  0x80845940 - 0x808468E0
    d_a_lift/d_a_lift_ridemove.cpp
# NSMBW   d_bases.text:  0x808468E0 - 0x80848730
  # d_a_lift/d_a_lift_scales.cpp
# NSMBW   d_bases.text:  0x80848730 - 0x80849980
  # d_a_lift/d_a_lift_scales_step.cpp
# NSMBW   d_bases.text:  0x80849980 - 0x8084A4C0
  # d_a_lift/d_a_lift_seesaw.cpp
# NSMBW   d_bases.text:  0x8084A4C0 - 0x8084C300
  # d_a_lift/d_a_lift_slide_kinoko.cpp
# NSMBW   d_bases.text:  0x8084C300 - 0x8084DF20
    d_a_lift/d_a_lift_spin_rotation.cpp
# NSMBW   d_bases.text:  0x8084DF20 - 0x8084E8C0
  # d_a_lift/d_a_lift_spinrotation_sync.cpp
# NSMBW   d_bases.text:  0x8084E8C0 - 0x8084EE00
  # d_a_lift/d_a_lift_toride_roll.cpp
# NSMBW   d_bases.text:  0x8084EE00 - 0x8084F1A0
  # d_a_lift/d_a_lift_waki.cpp
# NSMBW   d_bases.text:  0x8084F1A0 - 0x8084F6A0
  # d_a_lift/d_a_lift_waki_step.cpp
# NSMBW   d_bases.text:  0x8084F6A0 - 0x80850FF0
  # d_a_lift/d_a_lift_waterwheel.cpp
# NSMBW   d_bases.text:  0x80850FF0 - 0x80851B30
  # d_a_lift/d_a_lift_wheel.cpp
# NSMBW   d_bases.text:  0x80851B30 - 0x80851EC0
  # d_a_lift/d_a_lift_zen_hammer.cpp
# NSMBW   d_bases.text:  0x80851EC0 - 0x80852230
  # d_a_lift/d_a_lift_zen_kaiten_kanaami.cpp
# NSMBW   d_bases.text:  0x80852230 - 0x80853140
  # d_a_lift/d_a_lift_zen_kaihei.cpp
# NSMBW   d_bases.text:  0x80853140 - 0x80854290
  # d_a_lift/d_a_lift_zen_shiro.cpp
# NSMBW   d_bases.text:  0x80854290 - 0x80854EF0
  # d_a_lift/d_a_lift_zen_shiro_yogan.cpp
# NSMBW   d_bases.text:  0x80854EF0 - 0x808552E0
  # d_a_lift/d_a_lift_zen_suisya.cpp
# NSMBW   d_bases.text:  0x808552E0 - 0x80857490
  # d_actors/d_a_light_block.cpp
# NSMBW   d_bases.text:  0x80857490 - 0x808581A0
    d_actors/d_a_line_kinoko_block.cpp
# NSMBW   d_bases.text:  0x808581A0 - 0x80859440
  # d_actors/d_a_line_spin_lift.cpp
# NSMBW   d_bases.text:  0x80859440 - 0x8085BCB0
    d_actors/d_a_line_train.cpp
# NSMBW   d_bases.text:  0x8085BCB0 - 0x8085CD20
  # d_actors/d_a_ludwig_blitz.cpp
# NSMBW   d_bases.text:  0x8085CD20 - 0x8085D570
  # d_actors/d_a_manhole.cpp
# NSMBW   d_bases.text:  0x8085D570 - 0x8085F330
  # d_actors/d_a_manta.cpp
# NSMBW   d_bases.text:  0x8085F330 - 0x8085FA10
  # d_actors/d_a_manta_mgr.cpp
# NSMBW   d_bases.text:  0x8085FA10 - 0x808604D0
  # d_actors/d_a_manta_mgr2.cpp
# NSMBW   d_bases.text:  0x808604D0 - 0x80861BD0
  # d_actors/d_a_md_actor.cpp
# NSMBW   d_bases.text:  0x80861BD0 - 0x808628A0
  # d_actors/d_a_mega_hammer.cpp
# NSMBW   d_bases.text:  0x808628A0 - 0x808638C0
  # d_actors/d_a_middle_bg_for_castle_ludwig.cpp
# NSMBW   d_bases.text:  0x808638C0 - 0x80864A80
    d_a_mini_game/d_a_mini_game_balloon.cpp
# NSMBW   d_bases.text:  0x80864A80 - 0x808660F0
  # d_a_mini_game/d_a_mini_game_balloon_stick.cpp
# NSMBW   d_bases.text:  0x808660F0 - 0x808672B0
    d_a_mini_game/d_a_mini_game_gun_battery_mgr.cpp
# NSMBW   d_bases.text:  0x808672B0 - 0x808681B0
  # d_a_mini_game/d_a_mini_game_kinopio.cpp
# NSMBW   d_bases.text:  0x808681B0 - 0x8086A040
    d_a_mini_game/d_a_mini_game_wire_mesh.cpp
# NSMBW   d_bases.text:  0x8086A040 - 0x8086C8F0
    d_a_mini_game/d_a_mini_game_wire_mesh_mgr.cpp
# NSMBW   d_bases.text:  0x8086C8F0 - 0x8086CAD0
  # d_actors/d_a_mist_intermittent.cpp
# NSMBW   d_bases.text:  0x8086CAD0 - 0x8086CE30
  # d_actors/d_a_mouse_hole.cpp
# NSMBW   d_bases.text:  0x8086CE30 - 0x8086CF50
  # d_actors/d_a_mt_hanachan.cpp
# NSMBW   d_bases.text:  0x8086CF50 - 0x8086E670
  # d_actors/d_a_needle_for_koopa_jr_b.cpp
# NSMBW   d_bases.text:  0x8086E670 - 0x8086EEA0
    d_actors/d_a_nextgoto_block.cpp
# NSMBW   d_bases.text:  0x8086EEA0 - 0x808724E0
    d_actors/d_a_nice_boat.cpp
# NSMBW   d_bases.text:  0x808724E0 - 0x80872530
  # d_actors/d_a_nice_coin.cpp
# NSMBW   d_bases.text:  0x80872530 - 0x80872BC0
  # d_actors/d_a_nice_coin_regular.cpp
# NSMBW   d_bases.text:  0x80872BC0 - 0x80873200
  # d_actors/d_a_noboribou_obake.cpp
# NSMBW   d_bases.text:  0x80873200 - 0x808743D0
  # d_actors/d_a_nut.cpp
# NSMBW   d_bases.text:  0x808743D0 - 0x80874670
  # d_a_obj/d_a_obj_center.cpp
# NSMBW   d_bases.text:  0x80874670 - 0x808753C0
  # d_a_obj/d_a_obj_center2.cpp
# NSMBW   d_bases.text:  0x808753C0 - 0x80875AD0
  # d_a_obj/d_a_obj_clear_block.cpp
# NSMBW   d_bases.text:  0x80875AD0 - 0x808760E0
  # d_a_obj/d_a_obj_fruittree.cpp
# NSMBW   d_bases.text:  0x808760E0 - 0x80877510
    d_a_obj/d_a_obj_grass.cpp
# NSMBW   d_bases.text:  0x80877510 - 0x80878720
  # d_a_obj/d_a_obj_iggy_sled.cpp
# NSMBW   d_bases.text:  0x80878720 - 0x8087C8F0
  # d_a_obj/d_a_obj_iggy_wanwan.cpp
# NSMBW   d_bases.text:  0x8087C8F0 - 0x8087F510
  # d_a_obj/d_a_obj_kameck.cpp
# NSMBW   d_bases.text:  0x8087F510 - 0x8087FE10
  # d_a_obj/d_a_obj_kinoko.cpp
# NSMBW   d_bases.text:  0x8087FE10 - 0x80881B10
  # d_a_obj/d_a_obj_larry.cpp
# NSMBW   d_bases.text:  0x80881B10 - 0x80882E90
  # d_a_obj/d_a_obj_ludwig.cpp
# NSMBW   d_bases.text:  0x80882E90 - 0x80885160
  # d_a_obj/d_a_obj_morton.cpp
# NSMBW   d_bases.text:  0x80885160 - 0x808856D0
  # d_a_obj/d_a_obj_move_on_ghost.cpp
# NSMBW   d_bases.text:  0x808856D0 - 0x808858E0
  # d_a_obj/d_a_obj_pipe_down.cpp
# NSMBW   d_bases.text:  0x808858E0 - 0x80885AF0
  # d_a_obj/d_a_obj_pipe_left.cpp
# NSMBW   d_bases.text:  0x80885AF0 - 0x80885D00
  # d_a_obj/d_a_obj_pipe_right.cpp
# NSMBW   d_bases.text:  0x80885D00 - 0x80885F10
  # d_a_obj/d_a_obj_pipe_up.cpp
# NSMBW   d_bases.text:  0x80885F10 - 0x80886290
  # d_a_obj/d_a_obj_pipe_up_ng.cpp
# NSMBW   d_bases.text:  0x80886290 - 0x80887380
  # d_a_obj/d_a_obj_roy.cpp
# NSMBW   d_bases.text:  0x80887380 - 0x80887940
  # d_a_obj/d_a_obj_seaweed.cpp
# NSMBW   d_bases.text:  0x80887940 - 0x80888530
  # d_a_obj/d_a_obj_snow.cpp
# NSMBW   d_bases.text:  0x80888530 - 0x80888ED0
  # d_a_obj/d_a_obj_sparks.cpp
# NSMBW   d_bases.text:  0x80888ED0 - 0x80889230
  # d_a_obj/d_a_obj_spin_ashiba.cpp
# NSMBW   d_bases.text:  0x80889230 - 0x80889530
  # d_a_obj/d_a_obj_spin_child.cpp
# NSMBW   d_bases.text:  0x80889530 - 0x80889DF0
  # d_a_obj/d_a_obj_spin_parent.cpp
# NSMBW   d_bases.text:  0x80889DF0 - 0x8088C2A0
  # d_a_obj/d_a_obj_wendy.cpp
# NSMBW   d_bases.text:  0x8088C2A0 - 0x8088CF00
  # d_actors/d_a_palm_tree.cpp
# NSMBW   d_bases.text:  0x8088CF00 - 0x8088DC50
  # d_actors/d_a_peach_castle_block.cpp
# NSMBW   d_bases.text:  0x8088DC50 - 0x8088E670
  # d_actors/d_a_peach_castle_sequence_mgr.cpp
# NSMBW   d_bases.text:  0x8088E670 - 0x8088FF80
  # d_a_boss_demo/d_a_peach_for_airship_demo.cpp
# NSMBW   d_bases.text:  0x8088FF80 - 0x808912B0
  # d_a_boss_demo/d_a_peach_for_castle_demo.cpp
# NSMBW   d_bases.text:  0x808912B0 - 0x80893940
  # d_actors/d_a_pow_block.cpp
# NSMBW   d_bases.text:  0x80893940 - 0x808958E0
  # d_actors/d_a_prop_block.cpp
# NSMBW   d_bases.text:  0x808958E0 - 0x80896270
  # d_actors/d_a_remo_door.cpp
# NSMBW   d_bases.text:  0x80896270 - 0x80897630
  # d_actors/d_a_remo_line_lift.cpp
# NSMBW   d_bases.text:  0x80897630 - 0x80897F60
  # d_actors/d_a_remo_slide_door.cpp
# NSMBW   d_bases.text:  0x80897F60 - 0x808984D0
  # d_actors/d_a_reverse_block.cpp
# NSMBW   d_bases.text:  0x808984D0 - 0x80898580
  # d_a_river/d_a_river_barrel.cpp
# NSMBW   d_bases.text:  0x80898580 - 0x80898630
  # d_a_river/d_a_river_coin.cpp
# NSMBW   d_bases.text:  0x80898630 - 0x808986E0
  # d_a_river/d_a_river_item.cpp
# NSMBW   d_bases.text:  0x808986E0 - 0x80898790
  # d_a_river/d_a_river_lift.cpp
# NSMBW   d_bases.text:  0x80898790 - 0x808988B0
  # d_a_river/d_a_river_mgr.cpp
# NSMBW   d_bases.text:  0x808988B0 - 0x80898960
  # d_a_river/d_a_river_paipo.cpp
# NSMBW   d_bases.text:  0x80898960 - 0x80898A10
  # d_a_river/d_a_river_pakkun.cpp
# NSMBW   d_bases.text:  0x80898A10 - 0x80898AC0
  # d_a_river/d_a_river_puku.cpp
# NSMBW   d_bases.text:  0x80898AC0 - 0x80898B70
  # d_a_river/d_a_river_starcoin.cpp
# NSMBW   d_bases.text:  0x80898B70 - 0x8089A030
  # d_a_rot/d_a_rot_barnar.cpp
# NSMBW   d_bases.text:  0x8089A030 - 0x8089A430
  # d_a_rot/d_a_rot_block_full_chika.cpp
# NSMBW   d_bases.text:  0x8089A430 - 0x8089A840
  # d_a_rot/d_a_rot_block_full_color.cpp
# NSMBW   d_bases.text:  0x8089A840 - 0x8089AB90
  # d_a_rot/d_a_rot_block_full_kinoko.cpp
# NSMBW   d_bases.text:  0x8089AB90 - 0x8089B280
  # d_a_rot/d_a_rot_bloom_house_light.cpp
# NSMBW   d_bases.text:  0x8089B280 - 0x8089C8D0
  # d_a_rot/d_a_rot_cannon.cpp
# NSMBW   d_bases.text:  0x8089C8D0 - 0x8089E170
  # d_a_rot/d_a_rot_dokan.cpp
# NSMBW   d_bases.text:  0x8089E170 - 0x8089FE50
  # d_a_rot/d_a_rot_dokan_cannon.cpp
# NSMBW   d_bases.text:  0x8089FE50 - 0x808A0A40
  # d_a_rot/d_a_rotation_ghost_parent.cpp
# NSMBW   d_bases.text:  0x808A0A40 - 0x808A1FD0
  # d_actors/d_a_ship_cannon.cpp
# NSMBW   d_bases.text:  0x808A1FD0 - 0x808A2940
    d_actors/d_a_ship_gear.cpp
# NSMBW   d_bases.text:  0x808A2940 - 0x808A2A60
  # d_actors/d_a_ship_window.cpp
# NSMBW   d_bases.text:  0x808A2A60 - 0x808A3460
  # d_actors/d_a_sinkdokan_down.cpp
# NSMBW   d_bases.text:  0x808A3460 - 0x808A3E30
  # d_actors/d_a_sinkdokan_left.cpp
# NSMBW   d_bases.text:  0x808A3E30 - 0x808A4810
  # d_actors/d_a_sinkdokan_right.cpp
# NSMBW   d_bases.text:  0x808A4810 - 0x808A51F0
  # d_actors/d_a_sinkdokan_up.cpp
# NSMBW   d_bases.text:  0x808A51F0 - 0x808A7970
  # d_actors/d_a_slide_block.cpp
# NSMBW   d_bases.text:  0x808A7970 - 0x808A8210
  # d_actors/d_a_slip_penguin2_glasses.cpp
# NSMBW   d_bases.text:  0x808A8210 - 0x808A8330
  # d_actors/d_a_slow_quick_tag.cpp
# NSMBW   d_bases.text:  0x808A8330 - 0x808A8C40
  # d_actors/d_a_snki_light_water.cpp
# NSMBW   d_bases.text:  0x808A8C40 - 0x808A9920
  # d_actors/d_a_spana.cpp
# NSMBW   d_bases.text:  0x808A9920 - 0x808A9BB0
  # d_actors/d_a_spin_wire.cpp
# NSMBW   d_bases.text:  0x808A9BB0 - 0x808AA2C0
  # d_actors/d_a_stand.cpp
# NSMBW   d_bases.text:  0x808AA2C0 - 0x808AC390
  # d_actors/d_a_strongbox.cpp
# NSMBW   d_bases.text:  0x808AC390 - 0x808AC620
  # d_a_tag/d_a_tag_envsound.cpp
# NSMBW   d_bases.text:  0x808AC620 - 0x808AC770
  # d_a_tag/d_a_tag_scroll.cpp
# NSMBW   d_bases.text:  0x808AC770 - 0x808AC870
  # d_a_tag/d_a_tag_thunder.cpp
# NSMBW   d_bases.text:  0x808AC870 - 0x808AC9A0
  # d_a_tag/d_a_tag_water.cpp
# NSMBW   d_bases.text:  0x808AC9A0 - 0x808ACCD0
  # d_a_tag/d_a_tag_wind.cpp
# NSMBW   d_bases.text:  0x808ACCD0 - 0x808ACD90
  # d_a_tarzan/d_a_tarzan_rope.cpp
# NSMBW   d_bases.text:  0x808ACD90 - 0x808ADFC0
  # d_a_tarzan/d_a_tarzan_tsuta.cpp
# NSMBW   d_bases.text:  0x808ADFC0 - 0x808AF830
    d_a_tarzan/d_a_tarzan_ivy.cpp
# NSMBW   d_bases.text:  0x808AF830 - 0x808B0000
  # d_actors/d_a_team_pukupuku.cpp
# NSMBW   d_bases.text:  0x808B0000 - 0x808B0C20
  # d_actors/d_a_top_bg_for_castle_ludwig.cpp
# NSMBW   d_bases.text:  0x808B0C20 - 0x808B15D0
  # d_actors/d_a_torchilight.cpp
# NSMBW   d_bases.text:  0x808B15D0 - 0x808B2190
  # d_a_boss_demo/d_a_toride_kokoopa_demo.cpp
# NSMBW   d_bases.text:  0x808B2190 - 0x808B2670
  # d_actors/d_a_unit_chikuwa.cpp
# NSMBW   d_bases.text:  0x808B2670 - 0x808B3100
  # d_actors/d_a_unit_rail.cpp
# NSMBW   d_bases.text:  0x808B3100 - 0x808B3880
  # d_actors/d_a_untei_rope.cpp
# NSMBW   d_bases.text:  0x808B3880 - 0x808B4EB0
  # d_a_waki/d_a_waki_ankoh.cpp
# NSMBW   d_bases.text:  0x808B4EB0 - 0x808B5620
  # d_a_waki/d_a_waki_fire.cpp
# NSMBW   d_bases.text:  0x808B5620 - 0x808B57E0
  # d_a_waki/d_a_waki_ice_ashiba.cpp
# NSMBW   d_bases.text:  0x808B57E0 - 0x808B5A20
  # d_a_waki/d_a_waki_ice_ashiba_water.cpp
# NSMBW   d_bases.text:  0x808B5A20 - 0x808B5F20
  # d_a_waki/d_a_waki_keronpa.cpp
# NSMBW   d_bases.text:  0x808B5F20 - 0x808B6800
  # d_a_waki/d_a_waki_killer.cpp
# NSMBW   d_bases.text:  0x808B6800 - 0x808B79B0
  # d_a_waki/d_a_waki_kokoopa_fire.cpp
# NSMBW   d_bases.text:  0x808B79B0 - 0x808B8C10
  # d_a_waki/d_a_waki_koopa_fire.cpp
# NSMBW   d_bases.text:  0x808B8C10 - 0x808B9730
  # d_a_waki/d_a_waki_parabom.cpp
# NSMBW   d_bases.text:  0x808B9730 - 0x808BA840
  # d_a_waki/d_a_waki_pukupuku.cpp
# NSMBW   d_bases.text:  0x808BA840 - 0x808BAD20
  # d_a_waki/d_a_waki_search_magkiller.cpp
# NSMBW   d_bases.text:  0x808BAD20 - 0x808BAED0
  # d_a_waki/d_a_waki_slip_penguin2.cpp
# NSMBW   d_bases.text:  0x808BAED0 - 0x808BB7A0
  # d_a_waki/d_a_waki_tobipuku.cpp
# NSMBW   d_bases.text:  0x808BB7A0 - 0x808BBC70
  # d_a_waki/d_a_waki_togetekkyu.cpp
# NSMBW   d_bases.text:  0x808BBC70 - 0x808BC430
  # d_a_waki/d_a_waki_woodbox.cpp
# NSMBW   d_bases.text:  0x808BC430 - 0x808BC550
  # d_actors/d_a_wallinsect_mgr.cpp
# NSMBW   d_bases.text:  0x808BC550 - 0x808BE270
  # d_actors/d_a_warp_cannon.cpp
# NSMBW   d_bases.text:  0x808BE270 - 0x808BEAE0
  # d_a_water/d_a_water_bubble_cannon.cpp
# NSMBW   d_bases.text:  0x808BEAE0 - 0x808BEF40
  # d_a_water/d_a_water_bubble_parent.cpp
# NSMBW   d_bases.text:  0x808BEF40 - 0x808BF780
  # d_a_water/d_a_water_lift.cpp
# NSMBW   d_bases.text:  0x808BF780 - 0x808BF820
  # d_a_water/d_a_water_move.cpp
# NSMBW   d_bases.text:  0x808BF820 - 0x808C0850
  # d_a_water/d_a_water_move_regular.cpp
# NSMBW   d_bases.text:  0x808C0850 - 0x808C1760
  # d_a_water/d_a_water_xinfinite_move.cpp
# NSMBW   d_bases.text:  0x808C1760 - 0x808C24B0
  # d_a_water/d_a_waterall_rail.cpp
# NSMBW   d_bases.text:  0x808C24B0 - 0x808C2BA0
  # d_a_wire/d_a_wire_circle.cpp
# NSMBW   d_bases.text:  0x808C2BA0 - 0x808C2FD0
  # d_a_wire/d_a_wire_foothold.cpp
# NSMBW   d_bases.text:  0x808C2FD0 - 0x808C3D80
  # d_a_wire/d_a_wire_move.cpp
# NSMBW   d_bases.text:  0x808C3D80 - 0x808C5100
  # d_a_wire/d_a_wire_remocon.cpp

# NSMBW   d_bases.text:  0x808C5100 - 0x808C7D10
    d_a_wm/d_a_wm_2DPlayer.cpp

# NSMBW   d_bases.text:  0x808D4890 - 0x808D50B0
    d_a_wm/d_a_wm_Item.cpp
# NSMBW   d_bases.text:  0x808D50B0 - 0x808D5E50
    d_a_wm/d_a_wm_Killer.cpp
# NSMBW   d_bases.text:  0x808D5E50 - 0x808D78C0
    d_a_wm/d_a_wm_KillerBullet.cpp
# NSMBW   d_bases.text:  0x808D78C0 - 0x808D8860
    d_a_wm/d_a_wm_KinoBalloon.cpp

# NSMBW   d_bases.text:  0x808DBCB0 - 0x808DE620
    d_a_wm/d_a_wm_KoopaShip.cpp
# NSMBW   d_bases.text:  0x808DE620 - 0x808DEA90
    d_a_wm/d_a_wm_Manta.cpp
# NSMBW   d_bases.text:  0x808DEA90 - 0x808E3700
    d_a_wm/d_a_wm_Map.cpp
# NSMBW   d_bases.text:  0x808E3700 - 0x808E3DA0
    d_a_wm/d_a_wm_Note.cpp
# NSMBW   d_bases.text:  0x808E3DA0 - 0x808E4440
    d_a_wm/d_a_wm_Peach.cpp
# NSMBW   d_bases.text:  0x808E4440 - 0x808E4E00
    d_a_wm/d_a_wm_PeachCastle.cpp

# NSMBW   d_bases.text:  0x808E8AA0 - 0x808EF8D0
    d_a_wm/d_a_wm_SubPlayer.cpp

# NSMBW   d_bases.text:  0x80902790 - 0x8090D220
    d_a_wm/d_a_wm_player.cpp

# NSMBW   d_bases.text:  0x80910F00 - 0x809125E0
    d_actors/d_a_yoshi_egg.cpp

# NSMBW   d_bases.text:  0x80914680 - 0x80915690
    d_wm/d_cs_seq_mng.cpp

# NSMBW   d_bases.text:  0x80917960 - 0x8091A2F0
    d_scenes/d_s_GameSetup.cpp
# NSMBW   d_bases.text:  0x8091A2F0 - 0x8091BA50
    d_scenes/d_s_Multi.cpp

# NSMBW   d_bases.text:  0x8091CB70 - 0x8091EB60
    d_scenes/d_s_World9DeMo.cpp

# NSMBW   d_bases.text:  0x8091EC10 - 0x80921060
    d_scenes/d_s_crsin.cpp
# NSMBW   d_bases.text:  0x80921060 - 0x80922060
    d_scenes/d_s_game_over.cpp
# NSMBW   d_bases.text:  0x80922060 - 0x80923970
    d_scenes/d_s_movie.cpp
# NSMBW   d_bases.text:  0x80923970 - 0x80923B60Ï
    d_scenes/d_s_restart_crsin.cpp
# NSMBW   d_bases.text:  0x80923B60 - 0x80923C10
    d_scenes/d_s_select.cpp
# NSMBW   d_bases.text:  0x80923C10 - 0x80926740
    d_scenes/d_s_stage.cpp
# NSMBW   d_bases.text:  0x80926740 - 0x80928810
    d_scenes/d_s_world_map.cpp
# NSMBW   d_bases.text:  0x80928810 - 0x8092B3E0
    d_layouts/d_wm_WorldSelect.cpp
# NSMBW   d_bases.text:  0x8092B3E0 - 0x8092B8B0
    d_layouts/d_wm_WorldSelectGuide.cpp
# NSMBW   d_bases.text:  0x8092B8B0 - 0x8092F020
    d_wm/d_world_camera.cpp
)

#
# d_en_boss.rel
# NSMBW d_en_boss.text:  0x80B6BCC0 - 0x80B73A3C
#
target_sources(project PRIVATE
# NSMBW d_en_boss.text:  0x80B6BCC0 - 0x80B6D1C0
    d_layouts/d_PreGame.cpp
# NSMBW d_en_boss.text:  0x80B6D1C0 - 0x80B6D3C0
  # d_wm/d_wm_camera_move.cpp
# NSMBW d_en_boss.text:  0x80B6D3C0 - 0x80B6E600
  # d_wm/d_wm_kameck_demo_camera.cpp
# NSMBW d_en_boss.text:  0x80B6E600 - 0x80B726D0
  # d_wm/d_wm_player_camera.cpp
# NSMBW d_en_boss.text:  0x80B726D0 - 0x80B73A3C
    d_wm/d_wm_player_camera_base.cpp
)
