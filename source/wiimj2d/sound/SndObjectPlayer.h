#pragma once

#include "SndObject.h"

class SndObjctPly : public NMSndObject<4> {
    SIZE_ASSERT(0xB5);

public:
    // Constants and Types
    // ^^^^^^

    /* @unofficial */
    enum class PLAYER_VOICE_e {
        PLAYER_JOIN        = 0,
        PJ_JUMP            = 1,
        PJ_SPIN_JUMP       = 2,
        PLAYER_DECIDE      = 3,
        CS_FALL_INTO_MAP   = 4,
        CS_COURSE_IN       = 5,
        CS_COURSE_IN_MULTI = 6,
        CS_COURSE_IN_HARD  = 7,
        CS_COURSE_MISS     = 8,
        CS_JUMP            = 9,
        CS_DECIDE_JOIN     = 10,
        CS_ENCOUNT         = 11,
        CS_SHOVED          = 12,
        CS_CHASE_SHIP      = 13,
        CS_NOTICE_JR       = 14,
        GAME_OVER          = 15,
        CONTINUE           = 16,
        CONTINUE_COURSE    = 17,
        MOTIAGE            = 18,
        NAGERU             = 19,
        MOTIAGE_PLAYER     = 20,
        JUMP_2ND           = 21,
        JUMP_3RD           = 22,
        YOSHI_JUMP         = 23,
        JR_A_BATTLE_APP    = 24,
        WALL_KICK          = 25,
        PRPL_JUMP          = 26,
        PNGN_SLIDE         = 27,
        ROPE_CATCH         = 28,
        ROPE_RELEASE       = 29,
        ROPE_FALL          = 30,
        GOAL_POLE_CATCH    = 31,
        CLIFF_DIVE         = 32,
        CLIFF_UP           = 33,
        CLIFF_DOWN         = 34,
        CANNON_SHOT_S      = 35,
        CANNON_SHOT        = 36,
        BALLOON_HELP       = 37,
        BALLOON_HELP_2     = 38,
        HUKKATSU           = 39,
        DAMAGE_LAST        = 40,
        DAMAGE_LAST_2      = 41,
        TIMEUP             = 42,
        TIMEUP_MULTI       = 43,
        SCROLL_OUT         = 44,
        DAMAGE_FIRE        = 45,
        DAMAGE_FREEZE      = 46,
        DAMAGE_POISON      = 47,
        DAMAGE_ELEC        = 48,
        DAMAGE_EATEN       = 49,
        INTO_SANDPILLAR    = 50,
        QUAKE              = 51,
        STOMPED            = 52,
        HIP_ATTACKED       = 53,
        TYUKAN             = 54,
        GET_STAR           = 55,
        ITEM_COMPLETE      = 56,
        CLEAR_NORMAL       = 57,
        CLEAR_ANOTHER      = 58,
        CLEAR_MULTI        = 59,
        CLEAR_HELPED       = 60,
        CLEAR_BOSS         = 61,
        CLEAR_LAST_BOSS    = 62,
        SAVE_PRINCESS      = 63,
        CS_COMPLETE_DEMO   = 64,
        GET_PRIZE          = 65,
        FLOOR_FALL         = 66,
        NOTICE             = 67,
        MISS_PRINCESS      = 68,
        MG_ACTIVE_TV       = 69,
        MG_ACTIVE_RC       = 70,

        COUNT,
    };

    static constexpr s32 PLAYER_VOICE_COUNT = static_cast<s32>(PLAYER_VOICE_e::COUNT);

    /* @unofficial */
    enum class PLAYER_SOUND_INDEX_e {
        MA  = 0,
        LU  = 1,
        KO  = 2,
        KO2 = 3,
        KC  = 4,
        KC2 = 5,
        KO3 = 6,
        KO4 = 7,

        COUNT,
    };

    static constexpr s32 PLAYER_SOUND_INDEX_COUNT = static_cast<s32>(PLAYER_SOUND_INDEX_e::COUNT);

public:
    // Structors
    // ^^^^^^

    SndObjctPly(
        nw4r::snd::SoundArchivePlayer& soundArchivePlayer
    )
        : NMSndObject<4>(soundArchivePlayer)
        , mPlayerSndIndex(PLAYER_SOUND_INDEX_e::COUNT)
        , mSoundPlyMode(6)
        , m0xB4(0) {}

    virtual ~SndObjctPly() override;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x24 0x8019A0F0 */
    virtual nw4r::snd::SoundHandle* startSound(u32 soundId, u32 remoteMask) override;

    /* VT+0x28 0x8019A1E0 */
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, u32 remoteMask) override;

    /* VT+0x30 0x8019A330 */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, short seqParam, u32 remoteMask) override;

    /* VT+0x34 0x8019A450 */
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, short seqParam, u32 remoteMask) override;

    /* VT+0x38 0x8019A5D0 */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) override;

    /* VT+0x3C 0x8019A6C0 */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8019A810 */
    nw4r::snd::SoundHandle* startFootSound(u32 soundId, f32 param2, u32 remoteMask);

    /* 0x8019AAB0 */
    nw4r::snd::SoundHandle* startVoiceSound(PLAYER_VOICE_e voice, u32 remoteMask);

    /* 0x8019ABB0 */
    nw4r::snd::SoundHandle* holdVoiceSound(PLAYER_VOICE_e voice, u32 remoteMask);

public:
    // Instance Variables
    // ^^^^^^

    /* 0xAC */ PLAYER_SOUND_INDEX_e mPlayerSndIndex;
    /* 0xB0 */ s32                  mSoundPlyMode;
    /* 0xB4 */ u8                   m0xB4;
};
