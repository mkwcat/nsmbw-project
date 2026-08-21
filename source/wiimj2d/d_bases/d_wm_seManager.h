#pragma once

#include "d_static/d_a_player_manager.h"
#include "d_static/d_mj2d_game.h"
#include "d_static/d_player_model_manager.h"
#include "machine/m_vec.h"
#include "sound/SndObjectPlayer.h"

class SndObjctEmy;
class SndObjctCmnEmy;
class SndObjctCmnMap;

namespace dAudio
{
class SndObjctCSPly_c;
}

class dWmSeManager_c
{
    /* 0x000 VTABLE 0x80321E78 */

public:
    // Structors
    // ^^^^^^

    dWmSeManager_c()
    {
    }

    /* VT+0x8 0x801041E0 */
    virtual ~dWmSeManager_c();

public:
    // Constants and Types
    // ^^^^^^

    /* @unofficial */
    enum class WmSound_e {
        DUMMY = 0,

        /*
         * WmSoundType_e::PLAYER
         */
        TYPE_PLAYER_BEGIN = 1,

        PLY_JUMP = 1,
        PLY_JUMP_S = 2,
        PLY_JUMP_SS = 3,
        SYS_COURSE_IN = 4,
        PLY_ENEMY_CONTACT = 5,
        PLY_PLAYER_BYE = 6,
        PLY_DOKAN_IN_OUT = 7,
        PLY_LAND_POINT = 8,
        PLY_MOVE_IVY = 9,
        PLY_CHANGE_SMALL = 10,
        PLY_SLIP = 11,
        BGM_STAR = 12,
        PLY_LAND_PNGN = 13,

        TYPE_PLAYER_END = 14,

        /*
         * WmSoundType_e::FOOTNOTE
         */
        TYPE_FOOTNOTE_BEGIN = 16,

        PLY_FOOTNOTE_DIRT = 16,
        PLY_FOOTNOTE_WOOD = 17,
        PLY_FOOTNOTE_ROCK = 18,
        PLY_FOOTNOTE_SAND = 19,
        PLY_FOOTNOTE_SAND2 = 20,
        PLY_FOOTNOTE_SNOW = 21,
        PLY_FOOTNOTE_WATER = 22,
        PLY_FOOTNOTE_CLOUD = 23,
        PLY_FOOTNOTE_PNGN = 24,
        PLY_FOOTNOTE_HASHIGO_NAWA = 25,
        PLY_FOOTNOTE_HASHIGO_FE = 26,
        PLY_FOOTNOTE_ROCK_CLIMB = 27,

        TYPE_FOOTNOTE_END = 28,

        /*
         * WmSoundType_e::ACTOR
         */
        TYPE_ACTOR_BEGIN = 30,

        OBJ_GEN_LOAD = 30,
        OBJ_GEN_NEW_COURSE = 31,
        OBJ_DOOR_OPEN = 32,
        OBJ_DOOR_OPEN_STRONG = 33,
        OBJ_DOOR_CLOSE = 34,
        OBJ_HATA = 35,
        OBJ_PROPELLER = 36,
        OBJ_KINOHOUSE_APPEAR = 37,
        OBJ_KINOHOUSE_DISAPP = 38,
        OBJ_DOOR_OPEN_WOOD = 39,
        OBJ_DOOR_OPEN_STRONG_WOOD = 40,
        OBJ_DOOR_CLOSE_WOOD = 41,
        OBJ_SWITCH = 42,
        OBJ_BLOCK_GEN = 43,
        OBJ_BLOCK_DISAPP = 44,
        OBJ_DOKAN = 45,
        OBJ_DOOR_OPEN_KOOPA = 46,
        OBJ_DOOR_OPEN_STRONG_KOOPA = 47,
        OBJ_DOOR_CLOSE_KOOPA = 48,
        OBJ_DOOR_OPEN_PEACH = 49,
        OBJ_DOOR_CLOSE_PEACH = 50,
        OBJ_WINDOW_OPEN_TERESA = 51,
        OBJ_WINDOW_CLOSE_TERESA = 52,
        VOC_ITEM_KO_INFO = 53,
        OBJ_KINOPIO_HERE = 54,
        VOC_ITEM_KO_HELP_ME_HERE = 55,
        OBJ_KCASTLE_BRIDGE_APP = 56,
        OBJ_KCASTLE_BRIDGE_APP_F = 57,
        OBJ_KCASTLE_RUMBLE = 58,
        OBJ_MOUNTAIN_DISAPP = 59,
        BOSS_LAND_SHIRO2 = 60,
        OBJ_GEN_LODA_YOUGAN = 61,
        OBJ_GEN_LODA_TSUTA = 62,
        VOC_JR_FALL_OUT_CASTLE = 63,
        BOSS_JR_LAND = 64,
        BOSS_JR_FOOT = 65,
        BOSS_JR_JUMP_S = 66,
        VOC_JR_SURPRISE = 67,
        BOSS_JR_JUMP_L = 68,
        VOC_JR_JUMP = 69,

        TYPE_ACTOR_END = 70,

        /*
         * WmSoundType_e::BOSS
         */
        TYPE_BOSS_BEGIN = 72,

        BOSS_JUMP = 72,
        BOSS_LAND_SHIRO = 73,
        BOSS_INTO_SHIRO = 74,
        BOSS_KAMECK_FLY = 75,
        BOSS_KAMECK_FLY_SHIP = 76,
        BOSS_KAMECK_FLY_KCASTLE = 77,
        VOC_BOSS_FALL_INTO_MAP = 78,
        VOC_BOSS_BRING_IT = 79,
        VOC_BOSS_BEAT_YOU = 80,
        VOC_BOSS_SHOVED = 81,
        VOC_BOSS_JUMP = 82,
        VOC_BOSS_JUMP_F = 83,

        TYPE_BOSS_END = 84,

        /*
         * WmSoundType_e::ENEMY
         */
        TYPE_ENEMY_BEGIN = 86,

        EMY_ENEMY_BYE = 86,
        EMY_MOVE_W1_KURIBO = 87,
        EMY_MOVE_W2_SANDHALL = 88,
        EMY_MOVE_W3_ICEBROS = 89,
        EMY_MOVE_W4_PUKU = 90,
        EMY_MOVE_W5_PAKKUN = 91,
        EMY_MOVE_W6_KILLER = 92,
        EMY_MOVE_W7_JUGEM = 93,
        EMY_MOVE_W8_BUBBLE_APP = 94,
        EMY_MOVE_W8_BUBBLE_DISAPP = 95,
        EMY_TERESA_BRING_IT = 96,
        EMY_TERESA_BEAT_YOU = 97,
        VOC_KP_LAUGH = 98,
        EMY_KILLER = 99,
        PLY_GOTO_ENEMY_COURSE = 100,
        PLY_CSDEMO_KURI_APP = 101,
        PLY_CSDEMO_KURI_LOOK = 102,
        PLY_CSDEMO_KURI_TAKEAWAY = 103,
        PLY_CSDEMO_KURI_COURSE_IN = 104,

        TYPE_ENEMY_END = 105,

        /*
         * WmSoundType_e::SYSTEM
         */
        TYPE_SYSTEM_BEGIN = 107,

        SYS_MAP_VIEW_MODE = 107,
        SYS_MAP_VIEW_QUIT = 108,
        SYS_MAP_VIEW_MOVING = 109,
        OBJ_IBARA = 110,
        SYS_KINO_BALLOON = 111,
        SYS_KINO_BALLOON_DISAPP = 112,
        VOC_ITEM_KO_HELP_ME = 113,

        TYPE_SYSTEM_END = 114,

        /*
         * WmSoundType_e::BGM
         */
        TYPE_BGM_BEGIN = 116,

        BGM_LAST_CASTLE_APPEAR = 116,
        BGM_STAR_COIN_CMPLT_WORLD = 117,
        BGM_STAR_COIN_CMPLT_ALL = 118,
        BGM_ALL_CMPLT_5STARS = 119,

        TYPE_BGM_END = 120,
    };

    /* @unofficial */
    enum class WmSoundType_e {
        PLAYER = 0,
        FOOTNOTE = 1,
        ACTOR = 2,
        BOSS = 3,
        ENEMY = 4,
        SYSTEM = 5,
        BGM = 6,
        OTHER = 7,
    };

    /* @unofficial */
    enum class WmPlyVoice_e {
        JUMP = 0,
        ENCOUNT = 1,
        SHOVED = 2,
        CHASE_SHIP = 3,
        COURSE_IN = 4,
        COURSE_IN_MULTI = 5,
        COURSE_IN_HARD = 6,
        WALL_KICK = 7,
        FALL_INTO_MAP = 8,
        DECIDE_JOIN = 9,
        COURSE_MISS = 10,
        NOTICE_JR = 11,
        COMPLETE_DEMO = 12,
    };

    class SeParam_t
    {
        SIZE_ASSERT(0x34);

    public:
        // Structors
        // ^^^^^^

        /* 0x80103FD0 */
        SeParam_t();

        /* 0x80103FE0 */
        ~SeParam_t();

    public:
        // Instance Variables
        // ^^^^^^

        /* 0x00 */ s32 m0x00;
        /* 0x04 */ s32 m0x04;
        /* 0x08 */ s32 m0x08;
        /* 0x0C */ s32 m0x0C;
        /* 0x10 */ mVec3_c m0x10;
        /* 0x1C */ s32 m0x1C;
        /* 0x20 */ s32 m0x20;

        FILL(0x24, 0x2C);

        /* 0x2C */ u8 m0x2C;
        /* 0x30 */ s32 m0x30;
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80104250 */
    void initialize();

    /* 0x801046B0 */
    void execute();

    /* 0x80104DD0 */
    void UNDEF_80104dd0();

    /* 0x801050E0 @unofficial */
    void
    playPlyVoice(WmPlyVoice_e voice, dPyMdlMng_c::ModelType_e player, PLAYER_MODE_e playerMode);

    /* 0x80105170 @unofficial */
    void playPlySound(
      WmSound_e sound, dPyMdlMng_c::ModelType_e player, PLAYER_MODE_e playerMode, f32 param4
    );

    /* 0x801057D0 @unofficial */
    u32 getSoundId(WmSound_e sound) const;

    /* 0x80105B30 @unofficial */
    WmSoundType_e getSoundType(WmSound_e sound) const;

    /* 0x80105B30 @0x80105BC0 */
    SndObjctPly::PLAYER_VOICE_e getPlyVoiceId(WmPlyVoice_e voice) const;

    /* 0x80105CA0 @unofficial */
    s32 getSoundPlyMode(PLAYER_MODE_e playerMode) const;

    /* 0x80105D20 @unofficial */
    u32 getBossSoundId(WmSound_e sound) const;

public:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ SndObjctEmy* mpObjEmy;
    /* 0x008 */ SndObjctCmnEmy* mpObjCmnEmy;
    /* 0x00C */ SndObjctCmnMap* mpObjCmnMap;

    /* 0x010 */ dAudio::SndObjctCSPly_c* REMOVED(mpObjCSPlyArray)[4];
    /* 0x020 */ dAudio::SndObjctCSPly_c* mpObjCSPly;

    /* 0x024 */ SeParam_t mSeParam[30];

    OFFSET_ASSERT(0x63C);

#define OFFSET_dWmSeManager_c_mpObjCSPlyArray 0x63C
    /* 0x63C */ dAudio::SndObjctCSPly_c* mpObjCSPlyArray[PLAYER_COUNT];

public:
    // Static Methods
    // ^^^^^^

    /* 0x80103F50 */
    static dWmSeManager_c* construct();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A55C */ static dWmSeManager_c* m_pInstance;
};
