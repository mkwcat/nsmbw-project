#pragma once

#include "component/c_json.h"
#include "d_mj2d_data.h"
#include "d_mj2d_game.h"
#include "d_mj2d_header.h"
#include <cstdio>
#include <variant>

class dMj2dJsonHandler_c final : public cJson::HandlerIf_c
{
private:
    // Instance Methods
    // ^^^^^^

    bool expectValue() {
        if (mValueCount == 0 ||
            mFlags & (UNKNOWN_OBJECT | EXPECT_ARRAY_START | EXPECT_OBJECT_START | JSON_END)) {
            return false;
        }

        mValueCount--;
        return true;
    }

public:
    bool null() override;

    bool value(s64 number) override;

    bool rawNumber(
        std::string_view str
    ) override {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool value(
        double number
    ) override {
        return mFlags & UNKNOWN_OBJECT;
    }

    bool string(std::string_view str) override;

    bool key(std::string_view str) override;

    bool startObject() override;
    bool endObject() override;

    bool startArray() override;
    bool endArray() override;

private:
    // Constants and Types
    // ^^^^^^

    enum Flag_e {
        UNKNOWN_OBJECT      = 0_bit,
        EXPECT_ARRAY_START  = 1_bit,
        EXPECT_ARRAY_END    = 2_bit,
        EXPECT_OBJECT_START = 3_bit,
        TEMP_SAVE           = 4_bit,
        BIT_FLAGS_LE        = 5_bit,
        JSON_END            = 6_bit,
        SUBTRACT_1          = 7_bit,
        EXPECT_NULL         = 8_bit,
    };

    enum class Object_e : u8 {
        BASE,
        FILE,
        STOCK_ITEM,
        CHECKPOINT,
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

    using ValueVariant = std::variant<
        s8*, u8*, u16*, u32*, s32*, bool*, dMj2dGame_c::Revision_s*,
        dMj2dGame_c::GAME_COMPLETION_e*, dMj2dGame_c::START_KINOKO_KIND_e*,
        dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e*, dMj2dGame_c::PLAYER_MODE_u8_e*,
        dMj2dGame_c::PLAYER_TYPE_u8_e*, PLAYER_TYPE_e*, STAGE_e*, StageNo_s*,
        dMj2dGame_c::WORLD_COMPLETION_e*, PATH_DIRECTION_e*, dMj2dGame_c::COURSE_COMPLETION_e*,
        std::bitset<HINT_MOVIE_COUNT>*, dMj2dGame_c::PIPE_RANDOMIZER_MODE_e*>;

private:
    // Instance Variables
    // ^^^^^^

    u16           mFlags       = EXPECT_OBJECT_START;
    Object_e      mObject      = Object_e::BASE;
    std::size_t   mUnknownNest = 0;

    ValueVariant  mpValue;
    std::size_t   mValueCount = 0;

    s8            mSaveSlot   = -1;
    PLAYER_TYPE_e mPlayer     = PLAYER_TYPE_e::COUNT;
    WORLD_e       mWorld      = WORLD_e::COUNT;
    STAGE_e       mCourse     = STAGE_e::COUNT;
    u8            mWmEnemy    = AMBUSH_ENEMY_COUNT;

public:
    // Static Methods
    // ^^^^^^

    static bool writeJSON(std::FILE* f);

private:
    static const char* getPlayerTypeString(PLAYER_TYPE_e type);
    static bool marshalPlayerType(cJson::Writer_c& w, PLAYER_TYPE_e type, bool null = true);
    static bool marshalStockItem(cJson::Writer_c& w, const dMj2dGame_c& g);
    static bool
    marshalPlayCounts(cJson::Writer_c& w, const u16 (&counts)[WORLD_COUNT][STAGE_COUNT]);
    static bool marshalAvailableWorlds(cJson::Writer_c& w, const dMj2dHeader_c& header);
    static bool marshalFileData(cJson::Writer_c& w, const dMj2dData_c* data);
    static bool marshalPlayerData(cJson::Writer_c& w, const dMj2dGame_c& g, PLAYER_TYPE_e player);
    static bool marshalPlayerData(cJson::Writer_c& w, const dMj2dGame_c& g);
    static bool marshalWorldData(cJson::Writer_c& w, const dMj2dGame_c& g);
    static bool marshalWorldAmbushEnemyData(cJson::Writer_c& w, const dMj2dGame_c& g, int world);
    static bool marshalWorldCourseData(cJson::Writer_c& w, const dMj2dGame_c& g, int world);

    template <std::size_t N>
    static bool marshalBitIndices(cJson::Writer_c& w, const std::bitset<N>& bits);
};
