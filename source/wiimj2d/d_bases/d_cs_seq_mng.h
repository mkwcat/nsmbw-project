#pragma once

#include "d_allocator.h"
#include "d_wm_actor.h"
#include "d_wm_demo_actor.h"
#include <magic_enum/enum_range.hpp>
#include <utility>

class daWmDirector_c;

class dCsSeqMng_c : public dWmActor_c {
    SIZE_ASSERT(0x1D4);
    VTABLE(0x060, fBase_c, 0x8098A9C0);
    // 0x8098A98C g_profile_WM_CS_SEQ_MNG
    // 0x80914680 dCsSeqMng_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x809146B0 */
    dCsSeqMng_c();

public:
    // Constants
    // ^^^^^^

    /* @unofficial */
    enum class cut_name_e {
        wait                       = 0,
        end                        = 5,

        castle_enter               = 10,
        castle_fail                = 11,

        castle_door_open           = 19,
        castle_door_close          = 20,

        show_wm_note               = 31,
        move_wm_note               = 32,
        show_treasure_ship         = 33,
        animate_treasure_ship      = 34,

        pause                      = 39,

        set_dir_north              = 51,
        set_dir_south              = 52,

        kinoko_out                 = 60,

        player_land_wait           = 76,

        show_continues             = 80,

        start_kinoko_in            = 97,

        kinoko_help_demo_start     = 112,
        kinoko_help_balloon_in     = 113,

        lock_guide                 = 128,
        unlock_guide               = 129,

        bgm_stop                   = 140,
        bgm_start                  = 141,

        kinoko_help_voice_end_wait = 155,

    };

    /* @unofficial */
    enum class demo_name_e {
        default_clr         = 0,
        default_fail        = 1,
        enemy_clr           = 2,
        enemy_fail          = 3,
        toride_in           = 4,
        toride_clr          = 5,
        toride_fail         = 6,
        toride_fail2        = 7,
        castle_in           = 8,
        castle_clr          = 9,
        castle_fail         = 10,
        castle_fail2        = 11,
        ghost_in            = 12,
        ghost_clr           = 13,
        ghost_fail          = 14,
        ghost_fail2         = 15,
        cannon              = 16,
        trship_appear       = 17,
        dokan               = 18,
        dokan_warp          = 19,
        dokan_start         = 20,
        W_Walking_in        = 21,
        W_Walking_in_Normal = 22,
        W_Flying_in         = 23,
        W_Cannon_in         = 24,
        W_Cannon_in_Normal  = 25,
        W1_toride_clr       = 26,
        W1_castle_clr       = 27,
        W3_castle_clr       = 28,
        fade_test           = 29,
        view_world          = 30,
        course_in           = 31,
        kinoko_out          = 32,
        airship_course_in   = 33,
        airship_course_out  = 34,
        start_kinoko_in     = 35,
        airship_gonext      = 36,
        W36_Clear_Normal    = 37,
        null                = 38,
        antlion             = 39,
        killer              = 40,
        start_battle        = 41,
        Switch              = 42,
        KoopaCastleAppear   = 43,
        KinopioStart        = 44,
        WorldIn_NoShip      = 45,
        WorldIn_Jump_NoShip = 46,
        Pause_Menu          = 47,
        airship_clear       = 48,
        Stock_Menu          = 49,
        WorldSelect_Menu    = 50,
        antlion_star        = 51,
        GameStart           = 52,
    };

public:
    // Nested Types
    // ^^^^^^

    class order_c {
        friend class dCsSeqMng_c;

        /* 0x00 */ demo_name_e     m_demo;
        /* 0x04 */ int             m_priority;
        /* 0x08 */ dWmDemoActor_c* m_actor1;
        /* 0x0C */ dWmDemoActor_c* m_actor2;

        /* 0x80101780 */ void init();
        /* 0x801017A0 @unofficial */
        void set(demo_name_e demo, dWmDemoActor_c* actor1, dWmDemoActor_c* actor2, int priority);
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x801016F0 */
    [[nodiscard]] cut_name_e GetCutName();

    /* 0x80101740 */
    [[nodiscard]] int GetCutArg0();

    /* 0x801017C0 @unofficial */
    bool
    requestNextDemo(demo_name_e demo, dWmDemoActor_c* actor1, dWmDemoActor_c* actor2, int priority);

    /* 0x80914BD0 */
    void resetCut();

    /* 0x809153F0 */
    [[nodiscard]] bool checkCutEndAll();

    /* 0x80915590 */
    void executeCut();

    /* 0x80915600 */
    bool UNDEF_80915600();

    /* 0x80915630 */
    u32 UNDEF_80915630();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x138 */ dHeapAllocator_c m_allocator;
    /* 0x154 */ int              m_demoNow;
    /* 0x158 */ int              m_cutNow;
    /* 0x15C */ int              m_cutPrev;
    /* 0x160 */ int              m_0x160;
    /* 0x164 */ bool             m_0x164;
    /* 0x165 */ bool             m_0x165;
    /* 0x168 */ order_c          m_order[4];
    /* 0x1A8 */ order_c          m_orderNow;
    /* 0x1B8 */ int              m_0x1B8;
    /* 0x1BC */ int              m_0x1BC;
    /* 0x1C0 */ mVec3_c          m_0x1C0;
    /* 0x1CC */ daWmDirector_c*  m_director;

    /* 0x1D0 */ u8               FILL(0x1D0, 0x1D4);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A48C */ static dCsSeqMng_c* ms_instance;
};

template <>
struct magic_enum::customize::enum_range<dCsSeqMng_c::demo_name_e> {
    static constexpr int min = std::to_underlying(dCsSeqMng_c::demo_name_e::default_clr);
    static constexpr int max = std::to_underlying(dCsSeqMng_c::demo_name_e::GameStart);
};

template <>
struct magic_enum::customize::enum_range<dCsSeqMng_c::cut_name_e> {
    static constexpr int min = 0;
    static constexpr int max = 169;
};
