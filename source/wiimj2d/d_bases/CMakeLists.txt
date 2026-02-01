
#
# WIIMJ2D.dol
# NSMBW          .text:  0x801000F0 - 0x80106F00
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80100140 - 0x80100A10
    d_a_wm_Map_static.cpp
# NSMBW          .text:  0x80100A10 - 0x801016B0
# NSMBW          .sbss:  0x8042A47E - 0x8042A484
    d_a_wm_player_static.cpp

# NSMBW          .text:  0x801018C0 - 0x801018E0
    # d_profile_static.cpp # Moved to d_profile
# NSMBW          .sbss:  0x8042A490 - 0x8042A498
    d_s_crsin_static.cpp
# NSMBW          .text:  0x801018E0 - 0x80101A50
    d_s_restart_crsin_static.cpp
# NSMBW          .text:  0x80101A50 - 0x80102770
    d_s_stage_static.cpp
# NSMBW          .text:  0x80101A50 - 0x80102770
    d_s_world_map.cpp
# NSMBW          .text:  0x80102770 - 0x80102DB0
    d_s_world_map_static.cpp
# NSMBW          .text:  0x80103020 - 0x801038D0
    d_wm_effectManager.cpp
# NSMBW          .text:  0x80103F50 - 0x801060E0
    d_wm_seManager.cpp
# NSMBW          .text:  0x801060E0 - 0x80106F00
# NSMBW          .sbss:  0x8042A560 - 0x8042A568
    d_world_camera_static.cpp
)

#
# d_bases.rel
# NSMBW   d_bases.text:  0x8076D880 - 0x8092F020
#
target_sources(project PRIVATE
# NSMBW   d_bases.text:  0x8076D880 - 0x8076DEE0
    d_CharacterChangeIndicator.cpp
# NSMBW   d_bases.text:  0x8076DEE0 - 0x8076F350
    d_CharacterChangeSelectArrow.cpp
# NSMBW   d_bases.text:  0x8076F350 - 0x80772A50
    d_CharacterChangeSelectBase.cpp
# NSMBW   d_bases.text:  0x80772A50 - 0x80773F30
    d_CharacterChangeSelectContents.cpp
# NSMBW   d_bases.text:  0x80773F30 - 0x80776150
  # d_CollectionCoin.cpp
# NSMBW   d_bases.text:  0x80776150 - 0x80776570
  # d_CollectionCoinBase.cpp
# NSMBW   d_bases.text:  0x80776570 - 0x807775E0
  # d_CollectionCoinDate.cpp
# NSMBW   d_bases.text:  0x807775E0 - 0x80779650
    d_Continue.cpp
# NSMBW   d_bases.text:  0x80779650 - 0x8077A750
  # d_CourseClear.cpp
# NSMBW   d_bases.text:  0x8077A750 - 0x8077BB00
  # d_CourseSelectMenu.cpp
# NSMBW   d_bases.text:  0x8077BB00 - 0x8077CAE0
  # d_CourseTimeUp.cpp
# NSMBW   d_bases.text:  0x8077CAE0 - 0x8077E590
  # d_DateFile.cpp
# NSMBW   d_bases.text:  0x8077E590 - 0x8077F450
  # d_DemoMessage.cpp
# NSMBW   d_bases.text:  0x8077F450 - 0x807801F0
  # d_DrawGame.cpp
# NSMBW   d_bases.text:  0x807801F0 - 0x80781980
  # d_EasyPairing.cpp
# NSMBW   d_bases.text:  0x80781980 - 0x80782AB0
  # d_EventOpeningTitle.cpp
# NSMBW   d_bases.text:  0x80782AB0 - 0x80788510
  # d_FileSelect.cpp
# NSMBW   d_bases.text:  0x80788510 - 0x80789810
    d_GameOver.cpp
# NSMBW   d_bases.text:  0x80789810 - 0x80789BB0
  # d_InfoWindow.cpp
# NSMBW   d_bases.text:  0x80789BB0 - 0x8078AD30
  # d_LetterWindow.cpp
# NSMBW   d_bases.text:  0x8078AD30 - 0x8078BC60
  # d_MessageWindow.cpp
# NSMBW   d_bases.text:  0x8078BC60 - 0x8078DA20
    d_MiniGameCannon.cpp
# NSMBW   d_bases.text:  0x8078DA20 - 0x80790450
    d_MiniGameWire.cpp
# NSMBW   d_bases.text:  0x80790450 - 0x807916F0
  # d_ModeSelect.cpp
# NSMBW   d_bases.text:  0x807916F0 - 0x80792B00
  # d_ModelPlayArrow.cpp
# NSMBW   d_bases.text:  0x80792B00 - 0x80793E60
  # d_ModelPlayBase.cpp
# NSMBW   d_bases.text:  0x80793E60 - 0x80794F90
  # d_ModelPlayDate.cpp
# NSMBW   d_bases.text:  0x80794F90 - 0x80795290
  # d_ModelPlayGuide.cpp
# NSMBW   d_bases.text:  0x80795290 - 0x80798920
  # d_ModelPlayManager.cpp
# NSMBW   d_bases.text:  0x80798920 - 0x8079D540
    d_MultiCourseSelect.cpp
# NSMBW   d_bases.text:  0x8079D540 - 0x8079F630
  # d_MultiCourseSelectContents.cpp
# NSMBW   d_bases.text:  0x8079F630 - 0x807A2CF0
    d_NumberOfPeopleChange.cpp
# NSMBW   d_bases.text:  0x807A2CF0 - 0x807A3F50
  # d_OtehonClear.cpp
# NSMBW   d_bases.text:  0x807A3F50 - 0x807A7770
    d_PointResultDateFile.cpp
# NSMBW   d_bases.text:  0x807A7770 - 0x807A89C0
  # d_PointResultDateFileFree.cpp
# NSMBW   d_bases.text:  0x807A89C0 - 0x807ABE10
  # d_PointResultMulti.cpp
# NSMBW   d_bases.text:  0x807ABE10 - 0x807AD5F0
    d_SelectPlayer.cpp
# NSMBW   d_bases.text:  0x807AD5F0 - 0x807ADAD0
  # d_SequenceBG.cpp
# NSMBW   d_bases.text:  0x807ADAD0 - 0x807AF370
  # d_StaffCreditScore.cpp
# NSMBW   d_bases.text:  0x807AF370 - 0x807B2030
    d_StockItem.cpp
# NSMBW   d_bases.text:  0x807B2030 - 0x807B2540
  # d_StockItemShadow.cpp
# NSMBW   d_bases.text:  0x807B2540 - 0x807B32D0
  # d_TheEnd.cpp
# NSMBW   d_bases.text:  0x807B32D0 - 0x807B40A0
  # d_TimeUp.cpp
# NSMBW   d_bases.text:  0x807B40A0 - 0x807B77D0
  # d_a_bg_polygon.cpp

# NSMBW   d_bases.text:  0x807D0070 - 0x807D2AC0
    d_a_boss_koopa_jr_demo.cpp

# NSMBW   d_bases.text:  0x807DAC10 - 0x807DCD80
    d_a_castle_kokoopa_demo_1st.cpp
# NSMBW   d_bases.text:  0x807DCD80 - 0x807DDCC0
    d_a_castle_kokoopa_demo_2nd.cpp

# NSMBW   d_bases.text:  0x807E2040 - 0x807E38A0
    d_a_chukan_point.cpp

# NSMBW   d_bases.text:  0x807F1A00 - 0x807F2D30
    d_a_floor_jr_C.cpp

# NSMBW   d_bases.text:  0x8080F910 - 0x80813760
    d_a_jr_clown_for_player.cpp

# NSMBW   d_bases.text:  0x80830690 - 0x80830C40
    d_a_last_actor_stage.cpp

# NSMBW   d_bases.text:  0x80837370 - 0x80838020
    d_a_lift_fall.cpp

# NSMBW   d_bases.text:  0x8083EBC0 - 0x8083FEC0
    d_a_lift_remocon_seesaw.cpp

# NSMBW   d_bases.text:  0x80845940 - 0x808468E0
    d_a_lift_ridemove.cpp

# NSMBW   d_bases.text:  0x80857490 - 0x808581A0
    d_a_line_kinoko_block.cpp

# NSMBW   d_bases.text:  0x80859440 - 0x8085BCB0
    d_a_line_train.cpp

# NSMBW   d_bases.text:  0x808638C0 - 0x80864A80
    d_a_mini_game_balloon.cpp

# NSMBW   d_bases.text:  0x808660F0 - 0x808672B0
    d_a_mini_game_gun_battery_mgr.cpp

# NSMBW:  d_bases.text:  0x808681B0 - 0x8086A040
    d_a_mini_game_wire_mesh.cpp
# NSMBW   d_bases.text:  0x8086A040 - 0x8086C8F0
    d_a_mini_game_wire_mesh_mgr.cpp

# NSMBW   d_bases.text:  0x8086E670 - 0x8086EEA0
    d_a_next_goto_block.cpp
# NSMBW   d_bases.text:  0x8086EEA0 - 0x808724E0
    d_a_nice_boat.cpp

# NSMBW   d_bases.text:  0x808760E0 - 0x80877510
    d_a_obj_grass.cpp

# NSMBW   d_bases.text:  0x80897F60 - 0x808984D0
    d_a_reverse_block.cpp

# NSMBW   d_bases.text:  0x808C5100 - 0x808C7D10
    d_a_wm_2DPlayer.cpp

# NSMBW   d_bases.text:  0x808D4890 - 0x808D50B0
    d_a_wm_Item.cpp
# NSMBW   d_bases.text:  0x808D50B0 - 0x808D5E50
    d_a_wm_Killer.cpp
# NSMBW   d_bases.text:  0x808D5E50 - 0x808D78C0
    d_a_wm_KillerBullet.cpp
# NSMBW   d_bases.text:  0x808D78C0 - 0x808D8860
    d_a_wm_KinoBalloon.cpp

# NSMBW   d_bases.text:  0x808DBCB0 - 0x808DE620
    d_a_wm_KoopaShip.cpp
# NSMBW   d_bases.text:  0x808DEA90 - 0x808E3700
    d_a_wm_Map.cpp
# NSMBW   d_bases.text:  0x808DE620 - 0x808DEA90
    d_a_wm_Manta.cpp
# NSMBW   d_bases.text:  0x808DEA90 - 0x808E3700
    d_a_wm_Map_static.cpp
# NSMBW   d_bases.text:  0x808E3700 - 0x808E3DA0
    d_a_wm_Note.cpp
# NSMBW   d_bases.text:  0x808E3DA0 - 0x808E4440
    d_a_wm_Peach.cpp
# NSMBW   d_bases.text:  0x808E4440 - 0x808E4E00
    d_a_wm_PeachCastle.cpp

# NSMBW   d_bases.text:  0x808E8AA0 - 0x808EF8D0
    d_a_wm_SubPlayer.cpp

# NSMBW   d_bases.text:  0x80902790 - 0x8090D220
    d_a_wm_player.cpp

# NSMBW   d_bases.text:  0x80910F00 - 0x809125E0
    d_a_yoshi_egg.cpp

# NSMBW   d_bases.text:  0x80914680 - 0x80915690
    d_cs_seq_mng.cpp

# NSMBW   d_bases.text:  0x80917960 - 0x8091A2F0
    d_s_GameSetup.cpp
# NSMBW   d_bases.text:  0x8091A2F0 - 0x8091BA50
    d_s_multi.cpp

# NSMBW   d_bases.text:  0x8091CB70 - 0x8091EB60
    d_s_World9DeMo.cpp

# NSMBW   d_bases.text:  0x8091EC10 - 0x80921060
    d_s_crsin.cpp
# NSMBW   d_bases.text:  0x80921060 - 0x80922060
    d_s_game_over.cpp
# NSMBW   d_bases.text:  0x80922060 - 0x80923970
    d_s_movie.cpp
# NSMBW   d_bases.text:  0x80923970 - 0x80923B60
    d_s_restart_crsin.cpp
# NSMBW   d_bases.text:  0x80923B60 - 0x80923C10
    d_s_select.cpp
# NSMBW   d_bases.text:  0x80923C10 - 0x80926740
    d_s_stage.cpp
# NSMBW   d_bases.text:  0x80926740 - 0x80928810
    d_s_world_map.cpp
# NSMBW   d_bases.text:  0x80928810 - 0x8092B3E0
    d_wm_WorldSelect.cpp
# NSMBW   d_bases.text:  0x8092B3E0 - 0x8092B8B0
    d_wm_WorldSelectGuide.cpp
# NSMBW   d_bases.text:  0x8092B8B0 - 0x8092F020
    d_world_camera.cpp
)
