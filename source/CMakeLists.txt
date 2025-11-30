add_executable(project "")

target_compile_options(project PRIVATE
    -include System.h
    -fstack-protector-all
)

target_link_options(project PRIVATE
    -T "${CMAKE_SOURCE_DIR}/source/Module.ld"
    -r
    -Wl,--force-group-allocation
)

file(GLOB_RECURSE C_SOURCE_FILES "${CMAKE_SOURCE_DIR}/*.c")
set_source_files_properties(${C_SOURCE_FILES} PROPERTIES LANGUAGE CXX)

target_sources(project PRIVATE
# Note: Uppercase letters are always sorted before lowercase

# Root source files
    Module.cpp
    Four.cpp

#
# wiimj2d/d_system
# NSMBW          .text:  0x80006790 - 0x800FFF80
# NSMBW   d_bases.text:  0x8092F020 - 0x80932F60
#

# NSMBW          .text:  0x80006790 - 0x80007510
    wiimj2d/d_system/d_2d.cpp
# NSMBW          .text:  0x80007510 - 0x8000D740
  # wiimj2d/d_system/d_3d.cpp
# NSMBW          .text:  0x8000D740 - 0x8000FC30
  # wiimj2d/d_system/d_3d_disp.cpp
# NSMBW          .text:  0x8000FC30 - 0x80014330
    wiimj2d/d_system/d_CourseSelectGuide.cpp
# NSMBW   d_bases.text:  0x8092F020 - 0x80932F60
    wiimj2d/d_system/d_CourseSelectManager.cpp
# NSMBW          .text:  0x80014330 - 0x800145B0
  # wiimj2d/d_system/d_GXStateSave.cpp
# NSMBW          .text:  0x800145B0 - 0x80014820
  # wiimj2d/d_system/d_PanelObjList.cpp
# NSMBW          .text:  0x80014820 - 0x80014970
  # wiimj2d/d_system/d_PanelObjMgr.cpp
# NSMBW          .text:  0x80014970 - 0x80014B30
  # wiimj2d/d_system/d_SimpleCapture.cpp
# NSMBW          .text:  0x80014B30 - 0x80014F10
  # wiimj2d/d_system/d_SimpleCaptureDraw.cpp
# NSMBW          .text:  0x80014F10 - 0x80015D60
    wiimj2d/d_system/d_SmallScore.cpp
# NSMBW          .text:  0x80015D60 - 0x80016F70
  # wiimj2d/d_system/d_WarningBattery.cpp
# NSMBW          .text:  0x80016F70 - 0x80018CA0
  # wiimj2d/d_system/d_WarningErrorInfo.cpp
# NSMBW          .text:  0x80018CA0 - 0x80019990
  # wiimj2d/d_system/d_WarningNunchuk.cpp
# NSMBW          .text:  0x80019990 - 0x8001A6B0
  # wiimj2d/d_system/d_WarningOther.cpp
# NSMBW          .text:  0x8001A6B0 - 0x8001B3A0
  # wiimj2d/d_system/d_WarningYoKo.cpp
# NSMBW          .text:  0x8001B3A0 - 0x8001BB90
  # wiimj2d/d_system/d_WipeCircle.cpp
# NSMBW          .text:  0x8001BB90 - 0x8001C170
  # wiimj2d/d_system/d_WipeDokan.cpp
# NSMBW          .text:  0x8001C170 - 0x8001C690
  # wiimj2d/d_system/d_WipeKuppa.cpp
# NSMBW          .text:  0x8001C690 - 0x8001CBB0
  # wiimj2d/d_system/d_WipeMario.cpp
# NSMBW          .text:  0x8001CBB0 - 0x8001DA50
  # wiimj2d/d_system/d_a_boss_demo.cpp
# NSMBW          .text:  0x8001DA50 - 0x8001F6C0
  # wiimj2d/d_system/d_a_bullet.cpp
# NSMBW          .text:  0x8001F6C0 - 0x800208B0
  # wiimj2d/d_system/d_a_en_bigpile.cpp
# NSMBW          .text:  0x800208B0 - 0x80023C60
    wiimj2d/d_system/d_a_en_blockmain.cpp
# NSMBW          .text:  0x80023C60 - 0x80026BB0
  # wiimj2d/d_system/d_a_en_bros_base.cpp
# NSMBW          .text:  0x80026BB0 - 0x800272F0
  # wiimj2d/d_system/d_a_en_carry.cpp
# NSMBW          .text:  0x800272F0 - 0x800281C0
  # wiimj2d/d_system/d_a_en_coin_main.cpp
# NSMBW          .text:  0x800281C0 - 0x8002AB40
  # wiimj2d/d_system/d_a_en_dfpakkun.cpp
# NSMBW          .text:  0x8002AB40 - 0x8002BE40
  # wiimj2d/d_system/d_a_en_door.cpp
# NSMBW          .text:  0x8002BE40 - 0x8002CB70
  # wiimj2d/d_system/d_a_en_dpakkun.cpp
# NSMBW          .text:  0x8002CB70 - 0x8002EF50
    wiimj2d/d_system/d_a_en_dpakkun_base.cpp
# NSMBW          .text:  0x8002EF50 - 0x800311E0
    wiimj2d/d_system/d_a_en_jimen_pakkun_base.cpp
# NSMBW          .text:  0x800311E0 - 0x800331E0
  # wiimj2d/d_system/d_a_en_kuribo_base.cpp
# NSMBW          .text:  0x800331E0 - 0x800356D0
  # wiimj2d/d_system/d_a_en_lkuribo_base.cpp
# NSMBW          .text:  0x800356D0 - 0x80036930
  # wiimj2d/d_system/d_a_en_net_nokonoko_base.cpp
# NSMBW          .text:  0x80036930 - 0x80037EA0
  # wiimj2d/d_system/d_a_en_obj_coinblock.cpp
# NSMBW          .text:  0x80037EA0 - 0x8003C9F0
    wiimj2d/d_system/d_a_en_shell.cpp
# NSMBW          .text:  0x8003C9F0 - 0x8003DBD0
  # wiimj2d/d_system/d_a_en_super_bigpile.cpp
# NSMBW          .text:  0x8003DBD0 - 0x80040920
  # wiimj2d/d_system/d_a_en_togezo_base.cpp
# NSMBW          .text:  0x80040920 - 0x80041C00
  # wiimj2d/d_system/d_a_en_fireball_base.cpp
# NSMBW          .text:  0x80041C00 - 0x80042480
  # wiimj2d/d_system/d_a_fly_dokan.cpp
# NSMBW          .text:  0x80042480 - 0x80042A70
  # wiimj2d/d_system/d_a_ice_ashiba_base.cpp
# NSMBW          .text:  0x80042A70 - 0x80042AE0
  # wiimj2d/d_system/d_a_kawanagare_obj.cpp
# NSMBW          .text:  0x80042AE0 - 0x80042AE0
  # wiimj2d/d_system/d_a_kawanagare_obj.cpp
# NSMBW          .text:  0x800437D0 - 0x80044460
    wiimj2d/d_system/d_a_lift_remocon_main.cpp
# NSMBW          .text:  0x80044460 - 0x80044940
  # wiimj2d/d_system/d_a_move_pipe.cpp
# NSMBW          .text:  0x80044940 - 0x800451F0
  # wiimj2d/d_system/d_a_net_enemy.cpp
# NSMBW          .text:  0x800451F0 - 0x80045600
  # wiimj2d/d_system/d_a_obj_move_on_base.cpp
# NSMBW          .text:  0x80045600 - 0x80045650
  # wiimj2d/d_system/d_a_obj_pipe.cpp
# NSMBW          .text:  0x80045650 - 0x80045D20
  # wiimj2d/d_system/d_a_obj_pipe_base.cpp
# NSMBW          .text:  0x80045D20 - 0x800460D0
  # wiimj2d/d_system/d_a_obj_spin_child_base.cpp
# NSMBW          .text:  0x800460D0 - 0x8005B3A0
    wiimj2d/d_system/d_a_player_base.cpp
# NSMBW          .text:  0x8005B3A0 - 0x8005D7E0
    wiimj2d/d_system/d_a_player_demo_manager.cpp
# NSMBW          .text:  0x8005D7E0 - 0x8005DFD0
  # wiimj2d/d_system/d_a_player_hio.cpp # @unofficial
# NSMBW          .text:  0x8005DFD0 - 0x8005E9A0
    wiimj2d/d_system/d_a_player_key.cpp
# NSMBW          .text:  0x8005E9A0 - 0x800613B0
    wiimj2d/d_system/d_a_player_manager.cpp
# NSMBW          .text:  0x800613B0 - 0x800620F0
  # wiimj2d/d_system/d_a_right_base.cpp
# NSMBW          .text:  0x800620F0 - 0x800622A0
  # wiimj2d/d_system/d_a_rot_block.cpp
# NSMBW          .text:  0x800622A0 - 0x80062F00
  # wiimj2d/d_system/d_a_rot_objs_base.cpp
# NSMBW          .text:  0x80062F00 - 0x80063820
  # wiimj2d/d_system/d_a_sink_dokan.cpp
# NSMBW          .text:  0x80063820 - 0x80063F80
  # wiimj2d/d_system/d_a_spin_child_base.cpp
# NSMBW          .text:  0x80063F80 - 0x80064110
  # wiimj2d/d_system/d_a_zoom_pipe_base.cpp
# NSMBW          .text:  0x80064110 - 0x800660C0
    wiimj2d/d_system/d_actor.cpp
# NSMBW          .text:  0x800660C0 - 0x80066380
    wiimj2d/d_system/d_actor_groupid_mng.cpp
# NSMBW          .text:  0x80066380 - 0x80066FB0
    wiimj2d/d_system/d_actor_mng.cpp
# NSMBW          .text:  0x80066FB0 - 0x80068040
    wiimj2d/d_system/d_actor_state.cpp
# NSMBW          .text:  0x80068040 - 0x80069020
    wiimj2d/d_system/d_actorcreate_mng.cpp
# NSMBW          .text:  0x80069020 - 0x800690F0
  # wiimj2d/d_system/d_allocator.cpp
# NSMBW          .text:  0x800690F0 - 0x80069500
    wiimj2d/d_system/d_attention.cpp
# NSMBW          .text:  0x80069500 - 0x8006C0B0
# NSMBW          .bss:   0x803561E8 - 0x80356208
    wiimj2d/d_system/d_audio.cpp
# NSMBW          .text:  0x8006C0B0 - 0x8006C420
    wiimj2d/d_system/d_balloon_mng.cpp
# NSMBW          .text:  0x8006C420 - 0x8006C6D0
    wiimj2d/d_system/d_base.cpp
# NSMBW          .text:  0x8006C6D0 - 0x8006CF40
    wiimj2d/d_system/d_base_actor.cpp
# NSMBW          .text:  0x8006CF40 - 0x80076BC0
  # wiimj2d/d_system/d_bc.cpp
# NSMBW          .text:  0x80076BC0 - 0x80076FD0
    wiimj2d/d_system/d_beans_kuribo_mng.cpp
# NSMBW          .text:  0x80076FD0 - 0x8007E180
    wiimj2d/d_system/d_bg.cpp
# NSMBW          .text:  0x8007E180 - 0x8007F7A0
  # wiimj2d/d_system/d_bg_actor_mng.cpp
# NSMBW          .text:  0x8007F7A0 - 0x80081070
    wiimj2d/d_system/d_bg_ctr.cpp
# NSMBW          .text:  0x80081070 - 0x800818E0
  # wiimj2d/d_system/d_bg_global.cpp
# NSMBW          .text:  0x800818E0 - 0x80081D20
  # wiimj2d/d_system/d_bg_panel.cpp
# NSMBW          .text:  0x80081D20 - 0x800822E0
    wiimj2d/d_system/d_bg_parameter.cpp
# NSMBW          .text:  0x800822E0 - 0x80083490
  # wiimj2d/d_system/d_bg_texture.cpp
# NSMBW          .text:  0x80083490 - 0x800872E0
  # wiimj2d/d_system/d_bg_unit.cpp
# NSMBW          .text:  0x800872E0 - 0x80087F40
  # wiimj2d/d_system/d_bgtex_mng.cpp
# NSMBW          .text:  0x80087F40 - 0x80088D90
    wiimj2d/d_system/d_block_mng.cpp
# NSMBW          .text:  0x80088D90 - 0x80088FD0
  # wiimj2d/d_system/d_boat_log.cpp
# NSMBW          .text:  0x80088FD0 - 0x8008A230
  # wiimj2d/d_system/d_capture_mng.cpp
# NSMBW          .text:  0x8008A230 - 0x8008C200
  # wiimj2d/d_system/d_capturecoin.cpp
# NSMBW          .text:  0x8008C200 - 0x8008DC80
    wiimj2d/d_system/d_cc.cpp
# NSMBW          .text:  0x8008DC80 - 0x8008DED0
  # wiimj2d/d_system/d_center_save_mng.cpp
# NSMBW          .text:  0x8008DED0 - 0x8008DFF0
    wiimj2d/d_system/d_coin.cpp
# NSMBW          .text:  0x8008DFF0 - 0x8008ECC0
    wiimj2d/d_system/d_course_data.cpp
# NSMBW          .text:  0x8008ECC0 - 0x8008ED70
  # wiimj2d/d_system/d_curtain_mng.cpp
# NSMBW          .text:  0x8008ED70 - 0x8008F110
    wiimj2d/d_system/d_cyuukan.cpp
# NSMBW          .text:  0x8008F110 - 0x8008F460
  # wiimj2d/d_system/d_dvd.cpp
# NSMBW          .text:  0x8008F460 - 0x8008F920
  # wiimj2d/d_system/d_dylink.cpp
# NSMBW          .text:  0x8008F920 - 0x8008FE30
  # wiimj2d/d_system/d_ef.cpp
# NSMBW          .text:  0x8008FE30 - 0x800909A0
  # wiimj2d/d_system/d_eff_big_block_fragment.cpp
# NSMBW          .text:  0x800909A0 - 0x80091100
  # wiimj2d/d_system/d_eff_block_fragment.cpp
# NSMBW          .text:  0x80091100 - 0x80091860
  # wiimj2d/d_system/d_eff_ice_fragment.cpp
# NSMBW          .text:  0x80091860 - 0x80091F60
  # wiimj2d/d_system/d_eff_wan_chain.cpp
# NSMBW          .text:  0x80091F60 - 0x80092290
  # wiimj2d/d_system/d_eff_water_splash.cpp
# NSMBW          .text:  0x80092290 - 0x80092300
  # wiimj2d/d_system/d_effactor.cpp
# NSMBW          .text:  0x80092300 - 0x80092C00
    wiimj2d/d_system/d_effactor_mng.cpp
# NSMBW          .text:  0x80092C00 - 0x80092F10
  # wiimj2d/d_system/d_effect_proc.cpp
# NSMBW          .text:  0x80092F10 - 0x80094E80
  # wiimj2d/d_system/d_effectmanager.cpp
# NSMBW          .text:  0x80094E80 - 0x800983C0
    wiimj2d/d_system/d_enemy.cpp
# NSMBW          .text:  0x800983C0 - 0x8009AD30
    wiimj2d/d_system/d_enemy_boss.cpp
# NSMBW          .text:  0x8009AD30 - 0x8009EA30
  # wiimj2d/d_system/d_enemy_boss_koopa_jr_base.cpp
# NSMBW          .text:  0x8009EA30 - 0x8009EAF0
    wiimj2d/d_system/d_enemy_boyon_mng.cpp
# NSMBW          .text:  0x8009EAF0 - 0x8009F5F0
    wiimj2d/d_system/d_enemy_carry.cpp
# NSMBW          .text:  0x8009F5F0 - 0x800A2870
    wiimj2d/d_system/d_enemy_death.cpp
# NSMBW          .text:  0x800A2870 - 0x800A2B70
    wiimj2d/d_system/d_enemy_fumi.cpp
# NSMBW          .text:  0x800A2B70 - 0x800A7450
    wiimj2d/d_system/d_enemy_jr_clown_base.cpp
# NSMBW          .text:  0x800A7450 - 0x800A7DA0
    wiimj2d/d_system/d_enemy_manager.cpp
# NSMBW          .text:  0x800A7DA0 - 0x800A8710
  # wiimj2d/d_system/d_enemy_state.cpp
# NSMBW          .text:  0x800A8710 - 0x800B0A20
  # wiimj2d/d_system/d_enemy_toride_kokoopa.cpp
# NSMBW          .text:  0x800B0A20 - 0x800B0EA0
    wiimj2d/d_system/d_fader.cpp
# NSMBW          .text:  0x800B0EA0 - 0x800B11D0
  # wiimj2d/d_system/d_flag_ctrl.cpp
# NSMBW          .text:  0x800B11D0 - 0x800B14E0
  # wiimj2d/d_system/d_font_manager.cpp
# NSMBW          .text:  0x800B14E0 - 0x800B2D20
    wiimj2d/d_system/d_fukidashiInfo.cpp
# NSMBW          .text:  0x800B2D20 - 0x800B2E70
  # wiimj2d/d_system/d_funsui_act.cpp
# NSMBW          .text:  0x800B2E70 - 0x800B5930
    wiimj2d/d_system/d_game_common.cpp
# NSMBW          .text:  0x800B5930 - 0x800B5B50
    wiimj2d/d_system/d_game_key.cpp
# NSMBW          .text:  0x800B5B50 - 0x800B64A0
    wiimj2d/d_system/d_game_key_core.cpp
# NSMBW          .text:  0x800B64A0 - 0x800B6570
  # wiimj2d/d_system/d_graph.cpp
# NSMBW          .text:  0x800B6570 - 0x800B8130
  # wiimj2d/d_system/d_hana_body.cpp
# NSMBW          .text:  0x800B8130 - 0x800B8490
  # wiimj2d/d_system/d_ice_effect_maker.cpp
# NSMBW          .text:  0x800B8490 - 0x800B8FF0
  # wiimj2d/d_system/d_ice_manager.cpp
# NSMBW          .text:  0x800B8FF0 - 0x800B90A0
  # wiimj2d/d_system/d_ice_param.cpp
# NSMBW          .text:  0x800B90A0 - 0x800BAC00
  # wiimj2d/d_system/d_iggy_wan_kusari.cpp
# NSMBW          .text:  0x800BAC00 - 0x800BB0E0
  # wiimj2d/d_system/d_iggy_wan_kusari_piece.cpp
# NSMBW          .text:  0x800BB0E0 - 0x800BBD80
# NSMBW          .data:  0x80315E90 - 0x80315EB0
# NSMBW          .bss:   0x80359054 - 0x803590F0
# NSMBW          .sbss:  0x8042A25C - 0x8042A268
    wiimj2d/d_system/d_info.cpp
# NSMBW          .text:  0x800BBD80 - 0x800BC330
  # wiimj2d/d_system/d_ka_draw.cpp
# NSMBW          .text:  0x800BC330 - 0x800BC9A0
  # wiimj2d/d_system/d_kinoko_kasa_draw.cpp
# NSMBW          .text:  0x800BC9A0 - 0x800BCBD0
  # wiimj2d/d_system/d_kinoko_lift_draw.cpp
# nsmbw-project
    wiimj2d/d_system/d_kinopico_model.cpp
# NSMBW          .text:  0x800BCBD0 - 0x800BD7F0
    wiimj2d/d_system/d_kinopio_model.cpp
# NSMBW          .text:  0x800BD7F0 - 0x800C0060
  # wiimj2d/d_system/d_lift_all_hit_draw.cpp
# NSMBW          .text:  0x800C0060 - 0x800C0360
  # wiimj2d/d_system/d_lift_down_on_normal_draw.cpp
# NSMBW          .text:  0x800C0360 - 0x800C0B30
  # wiimj2d/d_system/d_lift_normal_model_draw.cpp
# NSMBW          .text:  0x800C0B30 - 0x800C0DC0
  # wiimj2d/d_system/d_light.cpp
# NSMBW          .text:  0x800C0DC0 - 0x800C89A0
  # wiimj2d/d_system/d_line_mng.cpp
# NSMBW          .text:  0x800C89A0 - 0x800C9B50
    wiimj2d/d_system/d_lytbase.cpp
# NSMBW          .text:  0x800C9B50 - 0x800CA000
    wiimj2d/d_system/d_lyttextbox.cpp
# NSMBW          .text:  0x800CA000 - 0x800CA150
  # wiimj2d/d_system/d_main.cpp
# NSMBW          .text:  0x800CA150 - 0x800CAC00
  # wiimj2d/d_system/d_mario_model.cpp
# NSMBW          .text:  0x800CAC00 - 0x800CD290
  # wiimj2d/d_system/d_mask_draw.cpp
# NSMBW          .text:  0x800CD290 - 0x800CD800
    wiimj2d/d_system/d_mask_mng.cpp
# NSMBW          .text:  0x800CD800 - 0x800CDB60
  # wiimj2d/d_system/d_md_actor.cpp
# NSMBW          .text:  0x800CDB60 - 0x800CDFB0
    wiimj2d/d_system/d_message.cpp
# NSMBW          .text:  0x800CDFB0 - 0x800CE660
    wiimj2d/d_system/d_mj2d_game.cpp
# NSMBW          .text:  0x800CE660 - 0x800CE7F0
    wiimj2d/d_system/d_mj2d_header.cpp
# nsmbw-project
    wiimj2d/d_system/d_mj2d_json_handler.cpp
# NSMBW          .text:  0x800CE7F0 - 0x800CE8F0
  # wiimj2d/d_system/d_msgres.cpp
# NSMBW          .text:  0x800CE8F0 - 0x800CED00
    wiimj2d/d_system/d_multi_manager.cpp
# NSMBW          .text:  0x800CED00 - 0x800CFCE0
    wiimj2d/d_system/d_nand_thread.cpp
# NSMBW          .text:  0x800CFCE0 - 0x800D03C0
    wiimj2d/d_system/d_next.cpp
# NSMBW          .text:  0x800D03C0 - 0x800D0700
  # wiimj2d/d_system/d_objblock_mng.cpp
# NSMBW          .text:  0x800D0700 - 0x800D0A90
  # wiimj2d/d_system/d_pad.cpp
# NSMBW          .text:  0x800D0A90 - 0x800D15F0
    wiimj2d/d_system/d_pause_manager.cpp
# NSMBW          .text:  0x800D15F0 - 0x800D2480
  # wiimj2d/d_system/d_pc.cpp
# NSMBW          .text:  0x800D2480 - 0x800D2600
  # wiimj2d/d_system/d_pole_ctr.cpp
# NSMBW          .text:  0x800D2600 - 0x800D2AE0
  # wiimj2d/d_system/d_pole_rope.cpp
# NSMBW          .text:  0x800D2AE0 - 0x800D2D10
    wiimj2d/d_system/d_player_effect.cpp
# NSMBW          .text:  0x800D2D10 - 0x800D2EC0
    wiimj2d/d_system/d_player_effect_mng.cpp
# NSMBW          .text:  0x800D2EC0 - 0x800D5420
    wiimj2d/d_system/d_player_model.cpp
# NSMBW          .text:  0x800D5420 - 0x800D6DB0
    wiimj2d/d_system/d_player_model_base.cpp
# NSMBW          .text:  0x800D6DB0 - 0x800D7190
    wiimj2d/d_system/d_player_model_manager.cpp
# NSMBW          .text:  0x800D7190 - 0x800D7440
  # wiimj2d/d_system/d_player_orchestra.cpp
# NSMBW          .text:  0x800D7440 - 0x800D81A0
  # wiimj2d/d_system/d_pos_go_and_come_exe_frm.cpp
# NSMBW          .text:  0x800D81A0 - 0x800D82D0
  # wiimj2d/d_system/d_pos_shake.cpp
# NSMBW          .text:  0x800D81A0 - 0x800D86C0
  # wiimj2d/d_system/d_propel_parts.cpp
# NSMBW          .text:  0x800D86C0 - 0x800D8940
  # wiimj2d/d_system/d_pswitch_manager.cpp
# NSMBW          .text:  0x800D8940 - 0x800D91B0
    wiimj2d/d_system/d_quake.cpp
# NSMBW          .text:  0x800D91B0 - 0x800D9850
  # wiimj2d/d_system/d_rail.cpp
# NSMBW          .text:  0x800D9850 - 0x800D9950
  # wiimj2d/d_system/d_random.cpp
# NSMBW          .text:  0x800D9950 - 0x800DBDB0
  # wiimj2d/d_system/d_rc.cpp
# NSMBW          .text:  0x800DBDB0 - 0x800DBFD0
  # wiimj2d/d_system/d_remocon_fukidashi.cpp
# NSMBW          .text:  0x800DBFD0 - 0x800DDA40
    wiimj2d/d_system/d_remocon_mng.cpp
# NSMBW          .text:  0x800DDA40 - 0x800DEA30
  # wiimj2d/d_system/d_replay_play.cpp
# NSMBW          .text:  0x800DDA40 - 0x800DF770
  # wiimj2d/d_system/d_res.cpp
# NSMBW          .text:  0x800DF770 - 0x800DF950
# NSMBW          .sbss:  0x8042A318 - 0x8042A31C
    wiimj2d/d_system/d_resource_mng.cpp
# NSMBW          .text:  0x800DF950 - 0x800DFA80
  # wiimj2d/d_system/d_rot_shake.cpp
# NSMBW          .text:  0x800DFA80 - 0x800E0270
  # wiimj2d/d_system/d_rs_node.cpp
# NSMBW          .text:  0x800E0270 - 0x800E1AA0
    wiimj2d/d_system/d_save_manager.cpp
# NSMBW          .text:  0x800E1AA0 - 0x800E2070
# NSMBW          .sdata: 0x80428A40 - 0x80428A50
    wiimj2d/d_system/d_scene.cpp
# NSMBW          .text:  0x800E2070 - 0x800E2670
    wiimj2d/d_system/d_score_mng.cpp
# NSMBW          .text:  0x800E2670 - 0x800E2BC0
  # wiimj2d/d_system/d_screen.cpp
# NSMBW          .text:  0x800E2BC0 - 0x800E3370
  # wiimj2d/d_system/d_spline.cpp
# NSMBW          .text:  0x800E3370 - 0x800E3730
  # wiimj2d/d_system/d_square_rail.cpp
# NSMBW          .text:  0x800E3730 - 0x800E38E0
  # wiimj2d/d_system/d_stage.cpp
# NSMBW          .text:  0x800E38E0 - 0x800E3BA0
    wiimj2d/d_system/d_stage_timer.cpp
# NSMBW          .text:  0x800E3BA0 - 0x800E3BD0
    wiimj2d/d_system/d_start_info.cpp
# NSMBW          .text:  0x800E3BD0 - 0x800E46E0
    wiimj2d/d_system/d_switchflag_mng.cpp
# NSMBW          .text:  0x800E46E0 - 0x800E5510
    wiimj2d/d_system/d_system.cpp
# NSMBW          .text:  0x800E5510 - 0x800E75D0
  # wiimj2d/d_system/d_tag_processor.cpp
# NSMBW          .text:  0x800E75D0 - 0x800E78D0
    wiimj2d/d_system/d_tencoin_mng.cpp
# NSMBW          .text:  0x800E78D0 - 0x800E8BC0
  # wiimj2d/d_system/d_ut_boss_demo.cpp
# NSMBW          .text:  0x800E8BC0 - 0x800E8C40
  # wiimj2d/d_system/d_video.cpp
# NSMBW          .text:  0x800E8C40 - 0x800EA740
  # wiimj2d/d_system/d_wan_kusari.cpp
# NSMBW          .text:  0x800EA740 - 0x800EAB10
  # wiimj2d/d_system/d_wan_kusari_piece.cpp
# NSMBW          .text:  0x800EAB10 - 0x800EB5D0
  # wiimj2d/d_system/d_water_draw.cpp
# NSMBW          .text:  0x800EB5D0 - 0x800EBCF0
  # wiimj2d/d_system/d_water_entry_mng.cpp
# NSMBW          .text:  0x800EBCF0 - 0x800EE030
  # wiimj2d/d_system/d_water_wave.cpp
# NSMBW          .text:  0x800EE030 - 0x800EE3C0
  # wiimj2d/d_system/d_wipe_fader.cpp
# NSMBW          .text:  0x800EE3C0 - 0x800F1A50
  # wiimj2d/d_system/d_wm_MapModel.cpp
# NSMBW          .text:  0x800F1A50 - 0x800F24A0
  # wiimj2d/d_system/d_wm_Map_ExRouteAnim.cpp
# NSMBW          .text:  0x800F24A0 - 0x800F2820
  # wiimj2d/d_system/d_wm_ShadowVolume.cpp
# NSMBW          .text:  0x800F2820 - 0x800F2C00
    wiimj2d/d_system/d_wm_actor.cpp
# NSMBW          .text:  0x800F2C00 - 0x800F3570
  # wiimj2d/d_system/d_wm_connect.cpp
# NSMBW          .text:  0x800F3570 - 0x800F60E0
  # wiimj2d/d_system/d_wm_csvdata.cpp
# NSMBW          .text:  0x800F60E0 - 0x800F7050
    wiimj2d/d_system/d_wm_demo_actor.cpp
# NSMBW          .text:  0x800F7050 - 0x800F7510
  # wiimj2d/d_system/d_wm_en_path.cpp
# NSMBW          .text:  0x800F7510 - 0x800F9380
  # wiimj2d/d_system/d_wm_enemy.cpp
# NSMBW          .text:  0x800F9380 - 0x800FD6A0
    wiimj2d/d_system/d_wm_lib.cpp
# NSMBW          .text:  0x800FD6A0 - 0x800FD8F0
  # wiimj2d/d_system/d_wm_material.cpp
# NSMBW          .text:  0x800FD8F0 - 0x800FDB60
  # wiimj2d/d_system/d_wm_material.cpp
# NSMBW          .text:  0x800FDB60 - 0x800FDC40
    wiimj2d/d_system/d_wm_path.cpp
# NSMBW          .text:  0x800FDC40 - 0x800FE140
    wiimj2d/d_system/d_wm_player_base.cpp
# NSMBW          .text:  0x800FE140 - 0x800FE160
  # wiimj2d/d_system/d_wm_viewclip.cpp
# NSMBW          .text:  0x800FE160 - 0x800FE2E0
  # wiimj2d/d_system/d_world.cpp
# NSMBW          .text:  0x800FE2E0 - 0x800FFF80
    wiimj2d/d_system/d_yoshi_model.cpp

#
# wiimj2d/d_stage
# NSMBW          .text:  0x800FFF80 - 0x801000F0
#

# NSMBW          .text:  0x800FFF80 - 0x801000F0
  # wiimj2d/d_stage/d_stage_field.cpp

#
# wiimj2d/d_bases
# NSMBW          .text:  0x801000F0 - 0x80106F00
# NSMBW   d_bases.text:  0x8076D880 - 0x8092F020
#

# NSMBW   d_bases.text:  0x8076D880 - 0x8076DEE0
    wiimj2d/d_bases/d_CharacterChangeIndicator.cpp
# NSMBW   d_bases.text:  0x8076DEE0 - 0x8076F350
    wiimj2d/d_bases/d_CharacterChangeSelectArrow.cpp
# NSMBW   d_bases.text:  0x8076F350 - 0x80772A50
    wiimj2d/d_bases/d_CharacterChangeSelectBase.cpp
# NSMBW   d_bases.text:  0x80772A50 - 0x80773F30
    wiimj2d/d_bases/d_CharacterChangeSelectContents.cpp
# NSMBW   d_bases.text:  0x80773F30 - 0x80776150
  # wiimj2d/d_bases/d_CollectionCoin.cpp
# NSMBW   d_bases.text:  0x80776150 - 0x80776570
  # wiimj2d/d_bases/d_CollectionCoinBase.cpp
# NSMBW   d_bases.text:  0x80776570 - 0x807775E0
  # wiimj2d/d_bases/d_CollectionCoinDate.cpp
# NSMBW   d_bases.text:  0x807775E0 - 0x80779650
  # wiimj2d/d_bases/d_Continue.cpp
# NSMBW   d_bases.text:  0x80779650 - 0x8077A750
  # wiimj2d/d_bases/d_CourseClear.cpp
# NSMBW   d_bases.text:  0x8077A750 - 0x8077BB00
  # wiimj2d/d_bases/d_CourseSelectMenu.cpp
# NSMBW   d_bases.text:  0x8077BB00 - 0x8077CAE0
  # wiimj2d/d_bases/d_CourseTimeUp.cpp
# NSMBW   d_bases.text:  0x8077CAE0 - 0x8077E590
  # wiimj2d/d_bases/d_DateFile.cpp
# NSMBW   d_bases.text:  0x8077E590 - 0x8077F450
  # wiimj2d/d_bases/d_DemoMessage.cpp
# NSMBW   d_bases.text:  0x8077F450 - 0x807801F0
  # wiimj2d/d_bases/d_DrawGame.cpp
# NSMBW   d_bases.text:  0x807801F0 - 0x80781980
  # wiimj2d/d_bases/d_EasyPairing.cpp
# NSMBW   d_bases.text:  0x80781980 - 0x80782AB0
  # wiimj2d/d_bases/d_EventOpeningTitle.cpp
# NSMBW   d_bases.text:  0x80782AB0 - 0x80788510
  # wiimj2d/d_bases/d_FileSelect.cpp
# NSMBW   d_bases.text:  0x80788510 - 0x80789810
  # wiimj2d/d_bases/d_GameOver.cpp
# NSMBW   d_bases.text:  0x80789810 - 0x80789BB0
  # wiimj2d/d_bases/d_InfoWindow.cpp
# NSMBW   d_bases.text:  0x80789BB0 - 0x8078AD30
  # wiimj2d/d_bases/d_LetterWindow.cpp
# NSMBW   d_bases.text:  0x8078AD30 - 0x8078BC60
  # wiimj2d/d_bases/d_MessageWindow.cpp
# NSMBW   d_bases.text:  0x8078BC60 - 0x8078DA20
    wiimj2d/d_bases/d_MiniGameCannon.cpp
# NSMBW   d_bases.text:  0x8078DA20 - 0x80790450
  # wiimj2d/d_bases/d_MiniGameWire.cpp
# NSMBW   d_bases.text:  0x80790450 - 0x807916F0
  # wiimj2d/d_bases/d_ModeSelect.cpp
# NSMBW   d_bases.text:  0x807916F0 - 0x80792B00
  # wiimj2d/d_bases/d_ModelPlayArrow.cpp
# NSMBW   d_bases.text:  0x80792B00 - 0x80793E60
  # wiimj2d/d_bases/d_ModelPlayBase.cpp
# NSMBW   d_bases.text:  0x80793E60 - 0x80794F90
  # wiimj2d/d_bases/d_ModelPlayDate.cpp
# NSMBW   d_bases.text:  0x80794F90 - 0x80795290
  # wiimj2d/d_bases/d_ModelPlayGuide.cpp
# NSMBW   d_bases.text:  0x80795290 - 0x80798920
  # wiimj2d/d_bases/d_ModelPlayManager.cpp
# NSMBW   d_bases.text:  0x80798920 - 0x8079D540
  # wiimj2d/d_bases/d_MultiCourseSelect.cpp
# NSMBW   d_bases.text:  0x8079D540 - 0x8079F630
  # wiimj2d/d_bases/d_MultiCourseSelectContents.cpp
# NSMBW   d_bases.text:  0x8079F630 - 0x807A2CF0
    wiimj2d/d_bases/d_NumberOfPeopleChange.cpp
# NSMBW   d_bases.text:  0x807A2CF0 - 0x807A3F50
  # wiimj2d/d_bases/d_OtehonClear.cpp
# NSMBW   d_bases.text:  0x807A3F50 - 0x807A7770
  # wiimj2d/d_bases/d_PointResultDateFile.cpp
# NSMBW   d_bases.text:  0x807A7770 - 0x807A89C0
  # wiimj2d/d_bases/d_PointResultDateFileFree.cpp
# NSMBW   d_bases.text:  0x807A89C0 - 0x807ABE10
  # wiimj2d/d_bases/d_PointResultMulti.cpp
# NSMBW   d_bases.text:  0x807ABE10 - 0x807AD5F0
    wiimj2d/d_bases/d_SelectPlayer.cpp
# NSMBW   d_bases.text:  0x807AD5F0 - 0x807ADAD0
  # wiimj2d/d_bases/d_SequenceBG.cpp
# NSMBW   d_bases.text:  0x807ADAD0 - 0x807AF370
  # wiimj2d/d_bases/d_StaffCreditScore.cpp
# NSMBW   d_bases.text:  0x807AF370 - 0x807B2030
    wiimj2d/d_bases/d_StockItem.cpp
# NSMBW   d_bases.text:  0x807B2030 - 0x807B2540
  # wiimj2d/d_bases/d_StockItemShadow.cpp
# NSMBW   d_bases.text:  0x807B2540 - 0x807B32D0
  # wiimj2d/d_bases/d_TheEnd.cpp
# NSMBW   d_bases.text:  0x807B32D0 - 0x807B40A0
  # wiimj2d/d_bases/d_TimeUp.cpp
# NSMBW   d_bases.text:  0x807B40A0 - 0x807B77D0
  # wiimj2d/d_bases/d_a_bg_polygon.cpp

# NSMBW   d_bases.text:  0x807D0070 - 0x807D2AC0
    wiimj2d/d_bases/d_a_boss_koopa_jr_demo.cpp

# NSMBW   d_bases.text:  0x807DAC10 - 0x807DCD80
    wiimj2d/d_bases/d_a_castle_kokoopa_demo_1st.cpp
# NSMBW   d_bases.text:  0x807DCD80 - 0x807DDCC0
    wiimj2d/d_bases/d_a_castle_kokoopa_demo_2nd.cpp

# NSMBW   d_bases.text:  0x807E2040 - 0x807E38A0
    wiimj2d/d_bases/d_a_chukan_point.cpp

# NSMBW   d_bases.text:  0x807F1A00 - 0x807F2D30
    wiimj2d/d_bases/d_a_floor_jr_C.cpp

# NSMBW   d_bases.text:  0x8080F910 - 0x80813760
    wiimj2d/d_bases/d_a_jr_clown_for_player.cpp

# NSMBW   d_bases.text:  0x80830690 - 0x80830C40
    wiimj2d/d_bases/d_a_last_actor_stage.cpp

# NSMBW   d_bases.text:  0x80837370 - 0x80838020
    wiimj2d/d_bases/d_a_lift_fall.cpp

# NSMBW   d_bases.text:  0x8083EBC0 - 0x8083FEC0
    wiimj2d/d_bases/d_a_lift_remocon_seesaw.cpp

# NSMBW   d_bases.text:  0x80845940 - 0x808468E0
    wiimj2d/d_bases/d_a_lift_ride_move.cpp

# NSMBW   d_bases.text:  0x80857490 - 0x808581A0
    wiimj2d/d_bases/d_a_line_kinoko_block.cpp

# NSMBW   d_bases.text:  0x80859440 - 0x8085BCB0
    wiimj2d/d_bases/d_a_line_train.cpp

# NSMBW   d_bases.text:  0x808660F0 - 0x808672B0
    wiimj2d/d_bases/d_a_mini_game_gun_battery_mgr.cpp

# NSMBW:  d_bases.text:  0x808681B0 - 0x8086A040
    wiimj2d/d_bases/d_a_mini_game_wire_mesh.cpp
# NSMBW   d_bases.text:  0x8086A040 - 0x8086C8F0
    wiimj2d/d_bases/d_a_mini_game_wire_mesh_mgr.cpp

# NSMBW   d_bases.text:  0x8086E670 - 0x8086EEA0
    wiimj2d/d_bases/d_a_next_goto_block.cpp
# NSMBW   d_bases.text:  0x8086EEA0 - 0x808724E0
    wiimj2d/d_bases/d_a_nice_boat.cpp

# NSMBW   d_bases.text:  0x808760E0 - 0x80877510
    wiimj2d/d_bases/d_a_obj_grass.cpp

# NSMBW   d_bases.text:  0x80897F60 - 0x808984D0
    wiimj2d/d_bases/d_a_reverse_block.cpp

# NSMBW   d_bases.text:  0x808C5100 - 0x808C7D10
    wiimj2d/d_bases/d_a_wm_2DPlayer.cpp

# NSMBW   d_bases.text:  0x808D4890 - 0x808D50B0
    wiimj2d/d_bases/d_a_wm_Item.cpp
# NSMBW   d_bases.text:  0x808D50B0 - 0x808D5E50
    wiimj2d/d_bases/d_a_wm_Killer.cpp
# NSMBW   d_bases.text:  0x808D5E50 - 0x808D78C0
    wiimj2d/d_bases/d_a_wm_KillerBullet.cpp
# NSMBW   d_bases.text:  0x808D78C0 - 0x808D8860
    wiimj2d/d_bases/d_a_wm_KinoBalloon.cpp

# NSMBW   d_bases.text:  0x808DBCB0 - 0x808DE620
    wiimj2d/d_bases/d_a_wm_KoopaShip.cpp
# NSMBW   d_bases.text:  0x808DE620 - 0x808DEA90
    wiimj2d/d_bases/d_a_wm_Manta.cpp
# NSMBW   d_bases.text:  0x808DEA90 - 0x808E3700
    wiimj2d/d_bases/d_a_wm_Map.cpp
# NSMBW          .text:  0x80100140 - 0x80100A10
    wiimj2d/d_bases/d_a_wm_Map_static.cpp
# NSMBW   d_bases.text:  0x808E3700 - 0x808E3DA0
    wiimj2d/d_bases/d_a_wm_Note.cpp
# NSMBW   d_bases.text:  0x808E3DA0 - 0x808E4440
    wiimj2d/d_bases/d_a_wm_Peach.cpp
# NSMBW   d_bases.text:  0x808E4440 - 0x808E4E00
    wiimj2d/d_bases/d_a_wm_PeachCastle.cpp

# NSMBW   d_bases.text:  0x808E8AA0 - 0x808EF8D0
    wiimj2d/d_bases/d_a_wm_SubPlayer.cpp

# NSMBW   d_bases.text:  0x80902790 - 0x8090D220
    wiimj2d/d_bases/d_a_wm_player.cpp
# NSMBW          .text:  0x80100A10 - 0x801016B0
# NSMBW          .sbss:  0x8042A47E - 0x8042A484
    wiimj2d/d_bases/d_a_wm_player_static.cpp

# NSMBW          .text:  0x801018C0 - 0x801018E0
    wiimj2d/d_bases/d_profile_static.cpp

# NSMBW   d_bases.text:  0x80910F00 - 0x809125E0
    wiimj2d/d_bases/d_a_yoshi_egg.cpp

# NSMBW   d_bases.text:  0x80917960 - 0x8091A2F0
    wiimj2d/d_bases/d_s_GameSetup.cpp

# NSMBW   d_bases.text:  0x8091CB70 - 0x8091EB60
    wiimj2d/d_bases/d_s_World9DeMo.cpp

# NSMBW   d_bases.text:  0x8091EC10 - 0x80921060
    wiimj2d/d_bases/d_s_crsin.cpp
# NSMBW          .sbss:  0x8042A490 - 0x8042A498
    wiimj2d/d_bases/d_s_crsin_static.cpp
# NSMBW   d_bases.text:  0x80921060 - 0x80922060
    wiimj2d/d_bases/d_s_game_over.cpp
# NSMBW   d_bases.text:  0x80922060 - 0x80923970
    wiimj2d/d_bases/d_s_movie.cpp
# NSMBW   d_bases.text:  0x80923970 - 0x80923B60
    wiimj2d/d_bases/d_s_restart_crsin.cpp
# NSMBW   d_bases.text:  0x80923B60 - 0x80923C10
    wiimj2d/d_bases/d_s_select.cpp
# NSMBW   d_bases.text:  0x80923C10 - 0x80926740
    wiimj2d/d_bases/d_s_stage.cpp
# NSMBW          .text:  0x80101A50 - 0x80102770
    wiimj2d/d_bases/d_s_stage_static.cpp
# NSMBW   d_bases.text:  0x80926740 - 0x80928810
    wiimj2d/d_bases/d_s_world_map.cpp
# NSMBW          .text:  0x80102770 - 0x80102DB0
    wiimj2d/d_bases/d_s_world_map_static.cpp
# NSMBW   d_bases.text:  0x80928810 - 0x8092B3E0
    wiimj2d/d_bases/d_wm_WorldSelect.cpp
# NSMBW   d_bases.text:  0x8092B3E0 - 0x8092B8B0
    wiimj2d/d_bases/d_wm_WorldSelectGuide.cpp
# NSMBW          .text:  0x80103020 - 0x801038D0
    wiimj2d/d_bases/d_wm_effectManager.cpp
# NSMBW          .text:  0x80103F50 - 0x801060E0
    wiimj2d/d_bases/d_wm_seManager.cpp
# NSMBW   d_bases.text:  0x8092B8B0 - 0x8092F020
    wiimj2d/d_bases/d_world_camera.cpp
# NSMBW          .text:  0x80106E70 - 0x80106F00
# NSMBW          .sbss:  0x8042A560 - 0x8042A568
    wiimj2d/d_bases/d_world_camera_static.cpp

#
# wiimj2d/d_player
# NSMBW          .text:  0x8010A3D0 - 0x8015F270
#

# NSMBW          .text:  0x8010A3D0 - 0x8010B050
  # wiimj2d/d_player/<UNKNOWN>
# NSMBW          .text:  0x8010B050 - 0x8010C130
  # wiimj2d/d_player/d_GoalManager.cpp
# NSMBW          .text:  0x8010C130 - 0x8010CAE0
    wiimj2d/d_player/d_SelectCursor.cpp
# NSMBW          .text:  0x8010CAE0 - 0x8010D270
    wiimj2d/d_player/d_SmallScoreManager.cpp
# NSMBW          .text:  0x8010D270 - 0x8010F080
    wiimj2d/d_player/d_WarningManager.cpp
# NSMBW          .text:  0x8010F080 - 0x8010F530
    wiimj2d/d_player/d_WiiStrap.cpp
# NSMBW          .text:  0x8010F530 - 0x8010F9A0
    wiimj2d/d_player/d_a_cursor.cpp
# NSMBW          .text:  0x8010F9A0 - 0x801102B0
    wiimj2d/d_player/d_a_en_eat_coin.cpp
# NSMBW          .text:  0x801102B0 - 0x80114C00
    wiimj2d/d_player/d_a_en_hatena_balloon.cpp
# NSMBW          .text:  0x80114C00 - 0x80115BD0
    wiimj2d/d_player/d_a_enemy_ice.cpp
# NSMBW          .text:  0x80115BD0 - 0x8011A5B0
    wiimj2d/d_player/d_a_farBG.cpp
# NSMBW          .text:  0x8011A5B0 - 0x8011B640
    wiimj2d/d_player/d_a_fireball_player.cpp
# NSMBW          .text:  0x8011B640 - 0x801233F0
    wiimj2d/d_player/d_a_ice.cpp
# NSMBW          .text:  0x801233F0 - 0x80124D40
    wiimj2d/d_player/d_a_iceball.cpp
# NSMBW          .text:  0x80124D40 - 0x80124EB0
    wiimj2d/d_player/d_a_last_actor.cpp
# NSMBW          .text:  0x80124EB0 - 0x80126650
    wiimj2d/d_player/d_a_mask.cpp
# NSMBW          .text:  0x80126650 - 0x8014A830
    wiimj2d/d_player/d_a_player.cpp
# NSMBW          .text:  0x8014A830 - 0x8014B400
    wiimj2d/d_player/d_a_player_ice.cpp
# NSMBW          .text:  0x8014B400 - 0x80154800
    wiimj2d/d_player/d_a_yoshi.cpp
# NSMBW          .text:  0x80154800 - 0x80156FE0
    wiimj2d/d_player/d_bg_gm.cpp
# nsmbw-project
    wiimj2d/d_player/d_death_message_mgr.cpp
# NSMBW          .text:  0x80156FE0 - 0x80157820
    wiimj2d/d_player/d_fukidashiManager.cpp
# NSMBW          .text:  0x80157820 - 0x8015A480
    wiimj2d/d_player/d_gamedisplay.cpp
# NSMBW          .text:  0x8015A480 - 0x8015BA70
    wiimj2d/d_player/d_pausewindow.cpp
# NSMBW          .text:  0x8015BA70 - 0x8015F270
    wiimj2d/d_player/d_s_boot.cpp

#
# wiimj2d/d_enemies
#

# NSMBW d_enemies.text:  0x809B88C0 - 0x809B9DF0
    wiimj2d/d_enemies/d_a_en_big_block.cpp

# NSMBW d_enemies.text:  0x809B1EC0 - 0x809B4200
    wiimj2d/d_enemies/d_a_en_big_hanachan.cpp

# NSMBW d_enemies.text:  0x809BED80 - 0x809C0770
    wiimj2d/d_enemies/d_a_en_block.cpp

# NSMBW d_enemies.text:  0x809C8D30 - 0x809CDE70
    wiimj2d/d_enemies/d_a_en_bomhei.cpp

# NSMBW d_enemies.text:  0x809D0090 - 0x809D0450
    wiimj2d/d_enemies/d_a_en_brick_block.cpp

# NSMBW d_enemies.text:  0x80A096E0 - 0x80A0BE30
    wiimj2d/d_enemies/d_a_en_goalpole.cpp

# NSMBW d_enemies.text:  0x80A26A80 - 0x80A2D610
    wiimj2d/d_enemies/d_a_en_item.cpp

# NSMBW d_enemies.text:  0x80A38A00 - 0x80A3AEF0
    wiimj2d/d_enemies/d_a_en_jumpdai.cpp

# NSMBW d_enemies.text:  0x80A64110 - 0x80A67470
    wiimj2d/d_enemies/d_a_en_mecha_koopa.cpp

# NSMBW d_enemies.text:  0x80A926A0 - 0x80A93990
    wiimj2d/d_enemies/d_a_en_red_ring.cpp
# NSMBW d_enemies.text:  0x80A93990 - 0x80A94D90
    wiimj2d/d_enemies/d_a_en_redcoin.cpp
# NSMBW d_enemies.text:  0x80A94D90 - 0x80A97B30
    wiimj2d/d_enemies/d_a_en_remocon_cannon.cpp

# NSMBW d_enemies.text:  0x80AC7800 - 0x80AC8270
    wiimj2d/d_enemies/d_a_en_water_stream.cpp

#
# wiimj2d/state
# NSMBW          .text:  0x8015F270 - 0x8015FF80
#

# NSMBW          .text:  0x8015F270 - 0x8015F280
    wiimj2d/state/s_Crc.cpp
# NSMBW          .text:  0x8015F280 - 0x8015F740
    wiimj2d/state/s_Lib.cpp
# NSMBW          .text:  0x8015F740 - 0x8015F810
    wiimj2d/state/s_Phase.cpp
# NSMBW          .text:  0x8015F810 - 0x8015F900
    wiimj2d/state/s_Print.cpp
# NSMBW          .text:  0x8015F900 - 0x8015FAE0
    wiimj2d/state/s_StateID.cpp
# NSMBW          .text:  0x8015FAE0 - 0x8015FDD0
    wiimj2d/state/s_StateMethod.cpp
# NSMBW          .text:  0x8015FDD0 - 0x8015FF80
    wiimj2d/state/s_StateMethodUsr_FI.cpp

#
# wiimj2d/d_en_boss
#

# NSMBW d_en_boss.text:  0x80B6BCC0 - 0x80B6D1C0
    wiimj2d/d_en_boss/d_pregamelyt.cpp

#
# wiimj2d
# NSMBW          .text:  0x8015FF80 - 0x80160C10
#

# NSMBW          .text:  0x8015FF80 - 0x8015FF90
    wiimj2d/Counter.cpp
# NSMBW          .text:  0x8015FF90 - 0x80160C10
    wiimj2d/DynamicLink.cpp

#
# wiimj2d/component
# NSMBW          .text:  0x80160C10 - 0x80161A60
#

# NSMBW          .text:  0x80160C10 - 0x80161050
    wiimj2d/component/c_lib.cpp
# NSMBW          .text:  0x80161050 - 0x801611A0
    wiimj2d/component/c_list.cpp
# NSMBW          .text:  0x801611A0 - 0x801615A0
    wiimj2d/component/c_math.cpp
# NSMBW          .text:  0x801615A0 - 0x80161670
    wiimj2d/component/c_random.cpp
# NSMBW          .text:  0x80161670 - 0x80161880
    wiimj2d/component/c_tree.cpp
# NSMBW          .text:  0x80161880 - 0x80161A60
    wiimj2d/component/c_unary_tree.cpp
#
# wiimj2d/framework
# NSMBW          .text:  0x80161A60 - 0x801632B0
#

# NSMBW          .text:  0x80161880 - 0x80161A60
    wiimj2d/framework/f_ba_helper.cpp
# NSMBW          .text:  0x80161A60 - 0x80162C80
    wiimj2d/framework/f_base.cpp
# nsmbw-project
    wiimj2d/framework/f_feature.cpp
# NSMBW          .text:  0x80162C80 - 0x80162E30
    wiimj2d/framework/f_list.cpp
# NSMBW          .text:  0x80162E30 - 0x80163140
    wiimj2d/framework/f_manager.cpp
# NSMBW          .text:  0x80163140 - 0x801632B0
    wiimj2d/framework/f_tree.cpp

#
# wiimj2d/machine
# NSMBW          .text:  0x801632B0 - 0x80171500
#

# NSMBW          .text:  0x801632B0 - 0x80164630
    wiimj2d/machine/m_2d.cpp
# NSMBW          .text:  0x80164630 - 0x80165210
    wiimj2d/machine/m_3d.cpp
# NSMBW          .text:  0x80165210 - 0x80165660
    wiimj2d/machine/m_3d_anmchr.cpp
# NSMBW          .text:  0x80165660 - 0x80165960
    wiimj2d/machine/m_3d_anmchrblend.cpp
# NSMBW          .text:  0x80165960 - 0x80166560
    wiimj2d/machine/m_3d_anmmatclr.cpp
# NSMBW          .text:  0x80166560 - 0x80167140
    wiimj2d/machine/m_3d_anmtexpat.cpp
# NSMBW          .text:  0x80167140 - 0x80167D80
    wiimj2d/machine/m_3d_anmtexsrt.cpp
# NSMBW          .text:  0x80167D80 - 0x80168000
    wiimj2d/machine/m_3d_anmvis.cpp
# NSMBW          .text:  0x80168000 - 0x80168240
    wiimj2d/machine/m_3d_banm.cpp
# NSMBW          .text:  0x80168240 - 0x80168C80
    wiimj2d/machine/m_3d_bmdl.cpp
# NSMBW          .text:  0x80168C80 - 0x80168E50
    wiimj2d/machine/m_3d_calcratio.cpp
# NSMBW          .text:  0x80168E50 - 0x80169360
    wiimj2d/machine/m_3d_fanm.cpp
# NSMBW          .text:  0x80169360 - 0x801696A0
    # wiimj2d/machine/<UNKNOWN>
# NSMBW          .text:  0x801696A0 - 0x8016A150
    wiimj2d/machine/m_3d_mdl.cpp
# NSMBW          .text:  0x8016A150 - 0x8016A430
    wiimj2d/machine/m_3d_scnleaf.cpp
# NSMBW          .text:  0x8016A430 - 0x8016A5A0
    wiimj2d/machine/m_3d_smdl.cpp

# NSMBW          .text:  0x8016B090 - 0x8016C540
    wiimj2d/machine/m_dvd.cpp

# NSMBW          .text:  0x8016DBE0 - 0x8016DD40
# NSMBW          .sbss:  0x8042A720 - 0x8042A728
    wiimj2d/machine/m_fader.cpp

# NSMBW  .bss: 0x80377F48 - 0x80377F58
    wiimj2d/machine/m_heap.cpp

# NSMBW          .text:  0x8016F330 - 0x8016F880
    wiimj2d/machine/m_pad.cpp

# NSMBW          .text:  0x80170AC0 - 0x80170D90
# NSMBW          .bss:   0x803780C8 - 0x803780F8
    wiimj2d/machine/m_vec.cpp

#
# wiimj2d/sound
# NSMBW          .text:  0x80194A10 - 0x8019F1F0
#

# NSMBW          .text:  0x80194A10 - 0x80197440
    wiimj2d/sound/SndAudioMgr.cpp
# NSMBW:         .text:  0x80197440 - 0x80197790
    wiimj2d/sound/SndObjectBase.cpp
# NSMBW          .text:  0x80197790 - 0x80198CF0
    wiimj2d/sound/SndObjectEnemy.cpp
# NSMBW          .text:  0x80198CF0 - 0x80199A20
    wiimj2d/sound/SndObjectMap.cpp

# NSMBW          .text:  0x8019A0F0 - 0x8019B240
    wiimj2d/sound/SndObjectPlayer.cpp

# NSMBW          .text:  0x8019B500 - 0x8019DE90
    wiimj2d/sound/SndSceneMgr.cpp

#
# revolution/ai
# NSMBW          .text:  0x8019F1F0 - 0x8019F7A0
#

#
# revolution/arc
# NSMBW          .text:  0x8019F7A0 - 0x801A0190
#

# NSMBW          .text:  0x8019F7A0 - 0x801A0190
    revolution/arc/arc.c

#
# revolution/ax
# NSMBW          .text:  0x801A0190 - 0x801A9C60
#

#
# revolution/base
# NSMBW          .text:  0x801A9C60 - 0x801A9E80
#

# NSMBW          .text:  0x801A9C60 - 0x801A9E80
    revolution/base/PPCArch.c

#
# revolution/os
# NSMBW          .text:  0x801A9E80 - 0x801B8B70
#

# NSMBW          .text:  0x801AC560 - 0x801ACC10
    revolution/os/OSCache.c

# NSMBW          .text:  0x801AD620 - 0x801ADCE0
    revolution/os/OSError.c

# NSMBW          .text:  0x801AF2C0 - 0x801AFEF0
    revolution/os/OSFatal.c

# NSMBW          .text:  0x801B1280 - 0x801B1A50
    revolution/os/OSInterrupt.c
# NSMBW          .text:  0x801B1A50 - 0x801B24D0
    revolution/os/OSLink.c

# NSMBW          .text:  0x801B2F60 - 0x801B3380
    revolution/os/OSMutex.c

# NSMBW          .text:  0x801B4950 - 0x801B60C0
    revolution/os/OSThread.c
# NSMBW          .text:  0x801B60C0 - 0x801B64F0
    revolution/os/OSTime.c


#
# revolution/si
# NSMBW          .text:  0x801BA940 - 0x801BBA70
#

# NSMBW          .text:  0x801BA940 - 0x801BB980
    revolution/si/SIBios.c
# NSMBW          .text:  0x801BB980 - 0x801BBA70
    revolution/si/SISamplingRate.c

#
# revolution/vi
#

# NSMBW          .text:  0x801BBB70 - 0x801BE5C0
    revolution/vi/vi.c
# NSMBW          .text:  0x801BE5C0 - 0x801BEEE0
    revolution/vi/i2c.c
# NSMBW          .text:  0x801BEEE0 - 0x801C0610
    revolution/vi/vi3in1.c

#
# revolution/mtx
#

# NSMBW          .text:  0x801C1530 - 0x801C17C0
    revolution/mtx/vec.c

#
# revolution/dvd
#

# NSMBW          .text:  0x801CA790 - 0x801CADA0
    revolution/dvd/dvdfs.c

#
# revolution/nand
# NSMBW          .text:  0x801D8620 - 0x801DB980
#

# NSMBW           .text: 0x801D8620 - 0x801D95E0
    revolution/nand/nand.c
# NSMBW           .text: 0x801D95E0 - 0x801DA250
    revolution/nand/NANDOpenClose.c
# NSMBW           .text: 0x801DA250 - 0x801DB280
    revolution/nand/NANDCore.c
# NSMBW           .text: 0x801DB1C0 - 0x801DB3F0
    revolution/nand/NANDCheck.c
# NSMBW           .text: 0x801DB3F0 - 0x801DB980
    revolution/nand/NANDLogging.c
# NSMBW           .text: 0x801DB980 - 0x801DB980
    revolution/nand/NANDErrorMessage.c

#
# revolution/pad
#

# NSMBW          .text:  0x801DDB10 - 0x801DDB70
    revolution/pad/Pad.c
# nsmbw-project
    revolution/pad/PadClamp.c

#
# revolution/wpad
#

# NSMBW          .text:  0x801DDC90 - 0x801E55A0
    revolution/wpad/WPAD.c

#
# revolution/kpad
#

# NSMBW          .text:  0x801EAA80 - 0x801EEAE0
    revolution/kpad/KPAD.c

#
# revolution/fs
# NSMBW          .text:  0x802265D0 - 0x80227CB0

# NSMBW          .text:  0x802265D0 = 0x80227CB0
    revolution/fs/fs.c

#
# nw4r/g3d
#

# NSMBW          .text:  0x80239F70 - 0x8023B2F0
    nw4r/g3d/ResFile.cpp

#
# nw4r/snd
#

# NSMBW          .text:  0x80269130 - 0x802697A0
    nw4r/snd/DvdSoundArchive.cpp

# NSMBW: 0x80275530 - 0x80275780
    nw4r/snd/SoundActor.cpp
# NSMBW          .text:  0x80275780 - 0x80275E80
    nw4r/snd/SoundArchive.cpp
# NSMBW          .text:  0x80275E80 - 0x80277190
    nw4r/snd/SoundArchiveFile.cpp
# NSMBW          .text:  0x80277190 - 0x802777F0
    nw4r/snd/SoundArchiveLoader.cpp

# NSMBW          .text:  0x802836F0 - 0x80283BD0
    nw4r/snd/Util.cpp

#
# egg/core
#

# NSMBW          .text:  0x802B7C00 - 0x802B8010
    egg/core/eggDvdFile.cpp
# NSMBW          .text:  0x802B8010 - 0x802B8560
    egg/core/eggDvdRipper.cpp
# NSMBW          .text:  0x802B8560 - 0x802B8BB0
    egg/core/eggStreamDecomp.cpp

# NSMBW          .text:  0x802B8C80 - 0x802B93E0
    egg/core/eggHeap.cpp
# NSMBW          .text:  0x802B93E0 - 0x802B98C0
    egg/core/eggExpHeap.cpp

# NSMBW          .text:  0x802BA410 - 0x802BA4F0
    egg/core/eggDisposer.cpp

# NSMBW          .text:  0x802BC9D0 - 0x802BE710
    egg/core/eggController.cpp

#
# egg/math
#

# NSMBW          .text:  0x802BE760 - 0x802BE820
    egg/math/eggMath.cpp

#
# egg/gfx
#

# NSMBW          .text:  0x802D0D90 - 0x802D2060
    egg/gfx/eggScreen.cpp

#
# egg/util
#

# NSMBW          .text:  0x802D7D90 - 0x802D8BC0
    egg/util/eggEffect.cpp

#
# msl/runtime
#

# NSMBW          .init:  0x80004364 - 0x800046E4
# NSMBW          .text:  0x802DC98C - 0x802DC9A8
    msl/runtime/__mem.c

# cxa.c
# nsmbw-project
    msl/runtime/cxa.c

# NSMBW          .text:  0x802DCA70 - 0x802DCAD0
    msl/runtime/global_destructor_chain.c

# NSMBW          .text:  0x802DCF3C - 0x802DD5D0
    msl/runtime/runtime.c

# stack_chk.c
# nsmbw-project
    msl/runtime/stack_chk.c

#
# PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src
#

# NSMBW          .text:  0x802DEC0C - 0x802DEDFC
    msl/msl_c/file_io.c

# NSMBW          .text:  0x802DF06C - 0x802DF264
    msl/msl_c/mbstring.c
# NSMBW          .text:  0x802DF264 - 0x802DF3D4
    msl/msl_c/mem.c

# NSMBW          .text:  0x802DF7A8 - 0x802E1BA0
    msl/msl_c/printf.c
# NSMBW          .text:  0x802E1BA0 - 0x802E1C28
    msl/msl_c/scanf.c
# NSMBW          .text:  0x802E1C28 - 0x802E4FC8
    msl/msl_c/string.c
# NSMBW          .text:  0x802E1FE4 - 0x802E24BC
    msl/msl_c/strtoul.c

# NSMBW          .text:  0x802E47E8 - 0x802E4860
    msl/msl_c/wchar_io.c

#
# PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision
#

# NSMBW .text: 0x802E8B58 - 0x802E8B5C
    msl/msl_c/math/w_sqrt.c

)
