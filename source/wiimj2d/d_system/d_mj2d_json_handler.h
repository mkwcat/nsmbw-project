#pragma once

#include "component/c_json.h"
#include "d_mj2d_game.h"
#include "d_mj2d_header.h"
#include <cstdio>
#include <variant>

class dMj2dJsonHandler_c final : public cJsonParser_c::HandlerIf_c
{
private:
    // Instance Methods
    // ^^^^^^

    bool expectValue()
    {
        if (mValueCount == 0 ||
            mFlags & (UNKNOWN_OBJECT | EXPECT_ARRAY_START | EXPECT_OBJECT_START | JSON_END)) {
            return false;
        }

        mValueCount--;
        return true;
    }

public:
    bool null() override
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool value(s64 number) override;

    bool rawNumber(const char* str, std::size_t length, bool copy) override
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool value(double number) override
    {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool string(const char* str, std::size_t length, bool copy) override;

    bool key(const char* str, std::size_t length, bool copy) override;

    bool startObject() override;
    bool endObject() override;

    bool startArray() override;
    bool endArray() override;

private:
    // Constants and Types
    // ^^^^^^

    enum Flag_e {
        UNKNOWN_OBJECT = 0_bit,
        EXPECT_ARRAY_START = 1_bit,
        EXPECT_ARRAY_END = 2_bit,
        EXPECT_OBJECT_START = 3_bit,
        TEMP_SAVE = 4_bit,
        BIT_FLAGS_LE = 5_bit,
        JSON_END = 6_bit,
        SUBTRACT_1 = 7_bit,
    };

    enum class Object_e {
        BASE,
        FILE,
        STOCK_ITEM,
        PLAYER_KEY,
        PLAYER,
        WORLD_KEY,
        WORLD,
        ENEMY_KEY,
        ENEMY,
        COURSE_KEY,
        COURSE,
        HINT_MOVIE_ARRAY,
        STAR_COIN_ARRAY,
        PLAY_COUNT_ARRAY,
    };

private:
    // Instance Variables
    // ^^^^^^

    u8 mFlags = EXPECT_OBJECT_START;
    Object_e mObject = Object_e::BASE;
    std::size_t mUnknownNest = 0;

    std::variant<
      s8*, u8*, u16*, u32*, bool*, dMj2dGame_c::Revision_s*, dMj2dGame_c::GAME_COMPLETION_e*,
      dMj2dGame_c::START_KINOKO_KIND_e*, dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e*,
      dMj2dGame_c::PLAYER_MODE_u8_e*, dMj2dGame_c::PLAYER_TYPE_u8_e*, STAGE_e*,
      dMj2dGame_c::WORLD_COMPLETION_e*, PATH_DIRECTION_e*, dMj2dGame_c::COURSE_COMPLETION_e*,
      cBitmask_c<HINT_MOVIE_COUNT>*>
      mpValue;
    std::size_t mValueCount = 0;

    s8 mSaveSlot = -1;
    PLAYER_TYPE_e mPlayer = PLAYER_TYPE_e::COUNT;
    WORLD_e mWorld = WORLD_e::COUNT;
    STAGE_e mCourse = STAGE_e::COUNT;
    u8 mWmEnemy = AMBUSH_ENEMY_COUNT;

public:
    // Static Methods
    // ^^^^^^

    static bool writeJSON(std::FILE* f);
};
