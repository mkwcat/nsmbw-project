
#
# WIIMJ2D.dol
# NSMBW          .text:  0x80006790 - 0x800FFF80
#
target_sources(project PRIVATE
# NSMBW          .text:  0x80006790 - 0x80007510
    d_2d.cpp
# NSMBW          .text:  0x80007510 - 0x8000D740
  # d_3d.cpp
# NSMBW          .text:  0x8000D740 - 0x8000FC30
  # d_3d_disp.cpp
# NSMBW          .text:  0x8000FC30 - 0x80014330
    d_CourseSelectGuide.cpp
# NSMBW          .text:  0x80014330 - 0x800145B0
  # d_GXStateSave.cpp
# NSMBW          .text:  0x800145B0 - 0x80014820
    d_PanelObjList.cpp
# NSMBW          .text:  0x80014820 - 0x80014970
    d_PanelObjMgr.cpp
# NSMBW          .text:  0x80014970 - 0x80014B30
  # d_SimpleCapture.cpp
# NSMBW          .text:  0x80014B30 - 0x80014F10
  # d_SimpleCaptureDraw.cpp
# NSMBW          .text:  0x80014F10 - 0x80015D60
    d_SmallScore.cpp
# NSMBW          .text:  0x80015D60 - 0x80016F70
  # d_WarningBattery.cpp
# NSMBW          .text:  0x80016F70 - 0x80018CA0
  # d_WarningErrorInfo.cpp
# NSMBW          .text:  0x80018CA0 - 0x80019990
  # d_WarningNunchuk.cpp
# NSMBW          .text:  0x80019990 - 0x8001A6B0
  # d_WarningOther.cpp
# NSMBW          .text:  0x8001A6B0 - 0x8001B3A0
  # d_WarningYoKo.cpp
# NSMBW          .text:  0x8001B3A0 - 0x8001BB90
  # d_WipeCircle.cpp
# NSMBW          .text:  0x8001BB90 - 0x8001C170
  # d_WipeDokan.cpp
# NSMBW          .text:  0x8001C170 - 0x8001C690
  # d_WipeKuppa.cpp
# NSMBW          .text:  0x8001C690 - 0x8001CBB0
  # d_WipeMario.cpp
# NSMBW          .text:  0x8001CBB0 - 0x8001DA50
  # d_a_boss_demo.cpp
# NSMBW          .text:  0x8001DA50 - 0x8001F6C0
  # d_a_bullet.cpp
# NSMBW          .text:  0x8001F6C0 - 0x800208B0
  # d_a_en_bigpile.cpp
# NSMBW          .text:  0x800208B0 - 0x80023C60
    d_a_en_blockmain.cpp
# NSMBW          .text:  0x80023C60 - 0x80026BB0
  # d_a_en_bros_base.cpp
# NSMBW          .text:  0x80026BB0 - 0x800272F0
  # d_a_en_carry.cpp
# NSMBW          .text:  0x800272F0 - 0x800281C0
  # d_a_en_coin_main.cpp
# NSMBW          .text:  0x800281C0 - 0x8002AB40
  # d_a_en_dfpakkun.cpp
# NSMBW          .text:  0x8002AB40 - 0x8002BE40
  # d_a_en_door.cpp
# NSMBW          .text:  0x8002BE40 - 0x8002CB70
  # d_a_en_dpakkun.cpp
# NSMBW          .text:  0x8002CB70 - 0x8002EF50
    d_a_en_dpakkun_base.cpp
# NSMBW          .text:  0x8002EF50 - 0x800311E0
    d_a_en_jimen_pakkun_base.cpp
# NSMBW          .text:  0x800311E0 - 0x800331E0
  # d_a_en_kuribo_base.cpp
# NSMBW          .text:  0x800331E0 - 0x800356D0
  # d_a_en_lkuribo_base.cpp
# NSMBW          .text:  0x800356D0 - 0x80036930
  # d_a_en_net_nokonoko_base.cpp
# NSMBW          .text:  0x80036930 - 0x80037EA0
  # d_a_en_obj_coinblock.cpp
# NSMBW          .text:  0x80037EA0 - 0x8003C9F0
    d_a_en_shell.cpp
# NSMBW          .text:  0x8003C9F0 - 0x8003DBD0
  # d_a_en_super_bigpile.cpp
# NSMBW          .text:  0x8003DBD0 - 0x80040920
  # d_a_en_togezo_base.cpp
# NSMBW          .text:  0x80040920 - 0x80041C00
  # d_a_en_fireball_base.cpp
# NSMBW          .text:  0x80041C00 - 0x80042480
  # d_a_fly_dokan.cpp
# NSMBW          .text:  0x80042480 - 0x80042A70
  # d_a_ice_ashiba_base.cpp
# NSMBW          .text:  0x80042A70 - 0x80042AE0
  # d_a_kawanagare_obj.cpp
# NSMBW          .text:  0x80042AE0 - 0x80042AE0
  # d_a_kawanagare_obj.cpp
# NSMBW          .text:  0x800437D0 - 0x80044460
    d_a_lift_remocon_main.cpp
# NSMBW          .text:  0x80044460 - 0x80044940
  # d_a_move_pipe.cpp
# NSMBW          .text:  0x80044940 - 0x800451F0
  # d_a_net_enemy.cpp
# NSMBW          .text:  0x800451F0 - 0x80045600
  # d_a_obj_move_on_base.cpp
# NSMBW          .text:  0x80045600 - 0x80045650
  # d_a_obj_pipe.cpp
# NSMBW          .text:  0x80045650 - 0x80045D20
  # d_a_obj_pipe_base.cpp
# NSMBW          .text:  0x80045D20 - 0x800460D0
  # d_a_obj_spin_child_base.cpp
# NSMBW          .text:  0x800460D0 - 0x8005B3A0
    d_a_player_base.cpp
# NSMBW          .text:  0x8005B3A0 - 0x8005D7E0
    d_a_player_demo_manager.cpp
# NSMBW          .text:  0x8005D7E0 - 0x8005DFD0
  # d_a_player_hio_ADJ.cpp
# NSMBW          .text:  0x8005DFD0 - 0x8005E9A0
    d_a_player_key.cpp
# NSMBW          .text:  0x8005E9A0 - 0x800613B0
    d_a_player_manager.cpp
# NSMBW          .text:  0x800613B0 - 0x800620F0
  # d_a_right_base.cpp
# NSMBW          .text:  0x800620F0 - 0x800622A0
  # d_a_rot_block.cpp
# NSMBW          .text:  0x800622A0 - 0x80062F00
  # d_a_rot_objs_base.cpp
# NSMBW          .text:  0x80062F00 - 0x80063820
  # d_a_sink_dokan.cpp
# NSMBW          .text:  0x80063820 - 0x80063F80
  # d_a_spin_child_base.cpp
# NSMBW          .text:  0x80063F80 - 0x80064110
  # d_a_zoom_pipe_base.cpp
# NSMBW          .text:  0x80064110 - 0x800660C0
    d_actor.cpp
# NSMBW          .text:  0x800660C0 - 0x80066380
    d_actor_groupid_mng.cpp
# NSMBW          .text:  0x80066380 - 0x80066FB0
    d_actor_mng.cpp
# NSMBW          .text:  0x80066FB0 - 0x80068040
    d_actor_state.cpp
# NSMBW          .text:  0x80068040 - 0x80069020
    d_actorcreate_mng.cpp
# NSMBW          .text:  0x80069020 - 0x800690F0
    d_allocator.cpp
# NSMBW          .text:  0x800690F0 - 0x80069500
    d_attention.cpp
# NSMBW          .text:  0x80069500 - 0x8006C0B0
# NSMBW          .bss:   0x803561E8 - 0x80356208
    d_audio.cpp
# NSMBW          .text:  0x8006C0B0 - 0x8006C420
    d_balloon_mng.cpp
# NSMBW          .text:  0x8006C420 - 0x8006C6D0
    d_base.cpp
# NSMBW          .text:  0x8006C6D0 - 0x8006CF40
    d_base_actor.cpp
# NSMBW          .text:  0x8006CF40 - 0x80076BC0
    d_bc.cpp
# NSMBW          .text:  0x80076BC0 - 0x80076FD0
    d_beans_kuribo_mng.cpp
# NSMBW          .text:  0x80076FD0 - 0x8007E180
    d_bg.cpp
# NSMBW          .text:  0x8007E180 - 0x8007F7A0
  # d_bg_actor_mng.cpp
# NSMBW          .text:  0x8007F7A0 - 0x80081070
    d_bg_ctr.cpp
# NSMBW          .text:  0x80081070 - 0x800818E0
  # d_bg_global.cpp
# NSMBW          .text:  0x800818E0 - 0x80081D20
  # d_bg_panel.cpp
# NSMBW          .text:  0x80081D20 - 0x800822E0
    d_bg_parameter.cpp
# NSMBW          .text:  0x800822E0 - 0x80083490
    d_bg_texture.cpp
# NSMBW          .text:  0x80083490 - 0x800872E0
  # d_bg_unit.cpp
# NSMBW          .text:  0x800872E0 - 0x80087F40
  # d_bgtex_mng.cpp
# NSMBW          .text:  0x80087F40 - 0x80088D90
    d_block_mng.cpp
# NSMBW          .text:  0x80088D90 - 0x80088FD0
  # d_boat_log.cpp
# NSMBW          .text:  0x80088FD0 - 0x8008A230
  # d_capture_mng.cpp
# NSMBW          .text:  0x8008A230 - 0x8008C200
  # d_capturecoin.cpp
# NSMBW          .text:  0x8008C200 - 0x8008DC80
    d_cc.cpp
# NSMBW          .text:  0x8008DC80 - 0x8008DED0
  # d_center_save_mng.cpp
# NSMBW          .text:  0x8008DED0 - 0x8008DFF0
    d_coin.cpp
# NSMBW          .text:  0x8008DFF0 - 0x8008ECC0
    d_course_data.cpp
# NSMBW          .text:  0x8008ECC0 - 0x8008ED70
  # d_curtain_mng.cpp
# NSMBW          .text:  0x8008ED70 - 0x8008F110
    d_cyuukan.cpp
# NSMBW          .text:  0x8008F110 - 0x8008F460
  # d_dvd.cpp
# NSMBW          .text:  0x8008F460 - 0x8008F920
  # d_dylink.cpp
# NSMBW          .text:  0x8008F920 - 0x8008FE30
    d_ef.cpp
# NSMBW          .text:  0x8008FE30 - 0x800909A0
  # d_eff_big_block_fragment.cpp
# NSMBW          .text:  0x800909A0 - 0x80091100
  # d_eff_block_fragment.cpp
# NSMBW          .text:  0x80091100 - 0x80091860
  # d_eff_ice_fragment.cpp
# NSMBW          .text:  0x80091860 - 0x80091F60
  # d_eff_wan_chain.cpp
# NSMBW          .text:  0x80091F60 - 0x80092290
  # d_eff_water_splash.cpp
# NSMBW          .text:  0x80092290 - 0x80092300
  # d_effactor.cpp
# NSMBW          .text:  0x80092300 - 0x80092C00
    d_effactor_mng.cpp
# NSMBW          .text:  0x80092C00 - 0x80092F10
  # d_effect_proc.cpp
# NSMBW          .text:  0x80092F10 - 0x80094E80
  # d_effectmanager.cpp
# NSMBW          .text:  0x80094E80 - 0x800983C0
    d_enemy.cpp
# NSMBW          .text:  0x800983C0 - 0x8009AD30
    d_enemy_boss.cpp
# NSMBW          .text:  0x8009AD30 - 0x8009EA30
  # d_enemy_boss_koopa_jr_base.cpp
# NSMBW          .text:  0x8009EA30 - 0x8009EAF0
    d_enemy_boyon_mng.cpp
# NSMBW          .text:  0x8009EAF0 - 0x8009F5F0
    d_enemy_carry.cpp
# NSMBW          .text:  0x8009F5F0 - 0x800A2870
    d_enemy_death.cpp
# NSMBW          .text:  0x800A2870 - 0x800A2B70
    d_enemy_fumi.cpp
# NSMBW          .text:  0x800A2B70 - 0x800A7450
    d_enemy_jr_clown_base.cpp
# NSMBW          .text:  0x800A7450 - 0x800A7DA0
    d_enemy_manager.cpp
# NSMBW          .text:  0x800A7DA0 - 0x800A8710
    d_enemy_state.cpp
# NSMBW          .text:  0x800A8710 - 0x800B0A20
  # d_enemy_toride_kokoopa.cpp
# NSMBW          .text:  0x800B0A20 - 0x800B0EA0
    d_fader.cpp
# NSMBW          .text:  0x800B0EA0 - 0x800B11D0
  # d_flag_ctrl.cpp
# NSMBW          .text:  0x800B11D0 - 0x800B14E0
  # d_font_manager.cpp
# NSMBW          .text:  0x800B14E0 - 0x800B2D20
    d_fukidashiInfo.cpp
# NSMBW          .text:  0x800B2D20 - 0x800B2E70
  # d_funsui_act.cpp
# NSMBW          .text:  0x800B2E70 - 0x800B5930
    d_game_common.cpp
# NSMBW          .text:  0x800B5930 - 0x800B5B50
    d_game_key.cpp
# NSMBW          .text:  0x800B5B50 - 0x800B64A0
    d_game_key_core.cpp
# NSMBW          .text:  0x800B64A0 - 0x800B6570
  # d_graph.cpp
# NSMBW          .text:  0x800B6570 - 0x800B8130
  # d_hana_body.cpp
# NSMBW          .text:  0x800B8130 - 0x800B8490
  # d_ice_effect_maker.cpp
# NSMBW          .text:  0x800B8490 - 0x800B8FF0
  # d_ice_manager.cpp
# NSMBW          .text:  0x800B8FF0 - 0x800B90A0
  # d_ice_param.cpp
# NSMBW          .text:  0x800B90A0 - 0x800BAC00
  # d_iggy_wan_kusari.cpp
# NSMBW          .text:  0x800BAC00 - 0x800BB0E0
  # d_iggy_wan_kusari_piece.cpp
# NSMBW          .text:  0x800BB0E0 - 0x800BBD80
# NSMBW          .data:  0x80315E90 - 0x80315EB0
# NSMBW          .bss:   0x80359054 - 0x803590F0
# NSMBW          .sbss:  0x8042A25C - 0x8042A268
    d_info.cpp
# NSMBW          .text:  0x800BBD80 - 0x800BC330
  # d_ka_draw.cpp
# NSMBW          .text:  0x800BC330 - 0x800BC9A0
  # d_kinoko_kasa_draw.cpp
# NSMBW          .text:  0x800BC9A0 - 0x800BCBD0
  # d_kinoko_lift_draw.cpp
# nsmbw-project
    d_kinopico_model.cpp
# NSMBW          .text:  0x800BCBD0 - 0x800BD7F0
    d_kinopio_model.cpp
# NSMBW          .text:  0x800BD7F0 - 0x800C0060
  # d_lift_all_hit_draw.cpp
# NSMBW          .text:  0x800C0060 - 0x800C0360
  # d_lift_down_on_normal_draw.cpp
# NSMBW          .text:  0x800C0360 - 0x800C0B30
  # d_lift_normal_model_draw.cpp
# NSMBW          .text:  0x800C0B30 - 0x800C0DC0
  # d_light.cpp
# NSMBW          .text:  0x800C0DC0 - 0x800C89A0
  # d_line_mng.cpp
# NSMBW          .text:  0x800C89A0 - 0x800C9B50
    d_lytbase.cpp
# NSMBW          .text:  0x800C9B50 - 0x800CA000
    d_lyttextbox.cpp
# NSMBW          .text:  0x800CA000 - 0x800CA150
  # d_main.cpp
# NSMBW          .text:  0x800CA150 - 0x800CAC00
  # d_mario_model.cpp
# NSMBW          .text:  0x800CAC00 - 0x800CD290
  # d_mask_draw.cpp
# NSMBW          .text:  0x800CD290 - 0x800CD800
    d_mask_mng.cpp
# NSMBW          .text:  0x800CD800 - 0x800CDB60
  # d_md_actor.cpp
# NSMBW          .text:  0x800CDB60 - 0x800CDFB0
    d_message.cpp
# NSMBW          .text:  0x800CDFB0 - 0x800CE660
    d_mj2d_game.cpp
# NSMBW          .text:  0x800CE660 - 0x800CE7F0
    d_mj2d_header.cpp
# nsmbw-project
    d_mj2d_json_handler.cpp
# NSMBW          .text:  0x800CE7F0 - 0x800CE8F0
  # d_msgres.cpp
# NSMBW          .text:  0x800CE8F0 - 0x800CED00
    d_multi_manager.cpp
# NSMBW          .text:  0x800CED00 - 0x800CFCE0
    d_nand_thread.cpp
# NSMBW          .text:  0x800CFCE0 - 0x800D03C0
    d_next.cpp
# NSMBW          .text:  0x800D03C0 - 0x800D0700
  # d_objblock_mng.cpp
# NSMBW          .text:  0x800D0700 - 0x800D0A90
  # d_pad.cpp
# NSMBW          .text:  0x800D0A90 - 0x800D15F0
    d_pause_manager.cpp
# NSMBW          .text:  0x800D15F0 - 0x800D2480
  # d_pc.cpp
# NSMBW          .text:  0x800D2480 - 0x800D2600
  # d_pole_ctr.cpp
# NSMBW          .text:  0x800D2600 - 0x800D2AE0
  # d_pole_rope.cpp
# NSMBW          .text:  0x800D2AE0 - 0x800D2D10
    d_player_effect.cpp
# NSMBW          .text:  0x800D2D10 - 0x800D2EC0
    d_player_effect_mng.cpp
# NSMBW          .text:  0x800D2EC0 - 0x800D5420
    d_player_model.cpp
# NSMBW          .text:  0x800D5420 - 0x800D6DB0
    d_player_model_base.cpp
# NSMBW          .text:  0x800D6DB0 - 0x800D7190
    d_player_model_manager.cpp
# NSMBW          .text:  0x800D7190 - 0x800D7440
  # d_player_orchestra.cpp
# NSMBW          .text:  0x800D7440 - 0x800D81A0
  # d_pos_go_and_come_exe_frm.cpp
# NSMBW          .text:  0x800D81A0 - 0x800D82D0
  # d_pos_shake.cpp
# NSMBW          .text:  0x800D81A0 - 0x800D86C0
  # d_propel_parts.cpp
# NSMBW          .text:  0x800D86C0 - 0x800D8940
  # d_pswitch_manager.cpp
# NSMBW          .text:  0x800D8940 - 0x800D91B0
    d_quake.cpp
# NSMBW          .text:  0x800D91B0 - 0x800D9850
  # d_rail.cpp
# NSMBW          .text:  0x800D9850 - 0x800D9950
  # d_random.cpp
# NSMBW          .text:  0x800D9950 - 0x800DBDB0
  # d_rc.cpp
# NSMBW          .text:  0x800DBDB0 - 0x800DBFD0
  # d_remocon_fukidashi.cpp
# NSMBW          .text:  0x800DBFD0 - 0x800DDA40
    d_remocon_mng.cpp
# NSMBW          .text:  0x800DDA40 - 0x800DEA30
  # d_replay_play.cpp
# NSMBW          .text:  0x800DDA40 - 0x800DF770
    d_res.cpp
# NSMBW          .text:  0x800DF770 - 0x800DF950
# NSMBW          .sbss:  0x8042A318 - 0x8042A31C
    d_resource_mng.cpp
# NSMBW          .text:  0x800DF950 - 0x800DFA80
  # d_rot_shake.cpp
# NSMBW          .text:  0x800DFA80 - 0x800E0270
  # d_rs_node.cpp
# NSMBW          .text:  0x800E0270 - 0x800E1AA0
    d_save_manager.cpp
# NSMBW          .text:  0x800E1AA0 - 0x800E2070
# NSMBW          .sdata: 0x80428A40 - 0x80428A50
    d_scene.cpp
# NSMBW          .text:  0x800E2070 - 0x800E2670
    d_score_mng.cpp
# NSMBW          .text:  0x800E2670 - 0x800E2BC0
  # d_screen.cpp
# NSMBW          .text:  0x800E2BC0 - 0x800E3370
  # d_spline.cpp
# NSMBW          .text:  0x800E3370 - 0x800E3730
  # d_square_rail.cpp
# NSMBW          .text:  0x800E3730 - 0x800E38E0
  # d_stage.cpp
# NSMBW          .text:  0x800E38E0 - 0x800E3BA0
    d_stage_timer.cpp
# NSMBW          .text:  0x800E3BA0 - 0x800E3BD0
    d_start_info.cpp
# NSMBW          .text:  0x800E3BD0 - 0x800E46E0
    d_switchflag_mng.cpp
# NSMBW          .text:  0x800E46E0 - 0x800E5510
    d_system.cpp
# NSMBW          .text:  0x800E5510 - 0x800E75D0
  # d_tag_processor.cpp
# NSMBW          .text:  0x800E75D0 - 0x800E78D0
    d_tencoin_mng.cpp
# NSMBW          .text:  0x800E78D0 - 0x800E8BC0
  # d_ut_boss_demo.cpp
# NSMBW          .text:  0x800E8BC0 - 0x800E8C40
  # d_video.cpp
# NSMBW          .text:  0x800E8C40 - 0x800EA740
  # d_wan_kusari.cpp
# NSMBW          .text:  0x800EA740 - 0x800EAB10
  # d_wan_kusari_piece.cpp
# NSMBW          .text:  0x800EAB10 - 0x800EB5D0
  # d_water_draw.cpp
# NSMBW          .text:  0x800EB5D0 - 0x800EBCF0
  # d_water_entry_mng.cpp
# NSMBW          .text:  0x800EBCF0 - 0x800EE030
  # d_water_wave.cpp
# NSMBW          .text:  0x800EE030 - 0x800EE3C0
  # d_wipe_fader.cpp
# NSMBW          .text:  0x800EE3C0 - 0x800F1A50
  # d_wm_MapModel.cpp
# NSMBW          .text:  0x800F1A50 - 0x800F24A0
  # d_wm_Map_ExRouteAnim.cpp
# NSMBW          .text:  0x800F24A0 - 0x800F2820
  # d_wm_ShadowVolume.cpp
# NSMBW          .text:  0x800F2820 - 0x800F2C00
    d_wm_actor.cpp
# NSMBW          .text:  0x800F2C00 - 0x800F3570
  # d_wm_connect.cpp
# NSMBW          .text:  0x800F3570 - 0x800F60E0
    d_wm_csvdata.cpp
# NSMBW          .text:  0x800F60E0 - 0x800F7050
    d_wm_demo_actor.cpp
# NSMBW          .text:  0x800F7050 - 0x800F7510
  # d_wm_en_path.cpp
# NSMBW          .text:  0x800F7510 - 0x800F9380
  # d_wm_enemy.cpp
# NSMBW          .text:  0x800F9380 - 0x800FD6A0
    d_wm_lib.cpp
# NSMBW          .text:  0x800FD6A0 - 0x800FD8F0
  # d_wm_material.cpp
# NSMBW          .text:  0x800FD8F0 - 0x800FDB60
  # d_wm_material.cpp
# NSMBW          .text:  0x800FDB60 - 0x800FDC40
    d_wm_path.cpp
# NSMBW          .text:  0x800FDC40 - 0x800FE140
    d_wm_player_base.cpp
# NSMBW          .text:  0x800FE140 - 0x800FE160
  # d_wm_viewclip.cpp
# NSMBW          .text:  0x800FE160 - 0x800FE2E0
  # d_world.cpp
# NSMBW          .text:  0x800FE2E0 - 0x800FFF80
    d_yoshi_model.cpp
)

#
# d_bases.rel
# NSMBW   d_bases.text:  0x8092F020 - 0x80932F60
#
target_sources(project PRIVATE
# NSMBW   d_bases.text:  0x8092F020 - 0x80932F60
    d_CourseSelectManager.cpp
)