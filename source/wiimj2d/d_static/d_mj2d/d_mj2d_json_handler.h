#pragma once

#include "c_json.h"
#include "d_mj2d_data.h"
#include "d_mj2d_game.h"
#include "d_mj2d_header.h"
#include <cstdio>
#include <optional>
#include <slu/concepts.hpp>
#include <span>
#include <variant>

class dMj2dJsonHandler_c final : public cJson::HandlerIf_c {
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

public:
    // Data strings
    // ^^^^^^

    template <slu::concepts::enumerator T>
    struct DataString_c;

    static constexpr std::optional<std::size_t> fromStringGeneric(
        const char* string, std::span<const char*> mapping
    ) {
        std::size_t i;
        for (i = 0; i < mapping.size(); i++) {
            if (std::strcmp(mapping[i], string) == 0) {
                return i;
            }
        }
        return std::nullopt;
    }

    static constexpr std::optional<std::size_t> fromStringGeneric(
        const char* string, std::size_t length, const std::span<const char* const>& mapping
    ) {
        std::size_t i;
        for (i = 0; i < mapping.size(); i++) {
            const char* entry = mapping[i];
            if (std::strncmp(entry, string, length) == 0 && entry[length] == '\0') {
                return i;
            }
        }
        return std::nullopt;
    }

    template <slu::concepts::enumerator T>
    static constexpr const char* toString(
        T value
    ) {
        const std::integral auto integral = static_cast<std::underlying_type_t<T>>(value);
        if (integral < 0 || integral >= std::size(DataString_c<T>::mapping)) {
            return nullptr;
        }
        return DataString_c<T>::mapping[integral];
    }

    template <slu::concepts::enumerator T>
    static constexpr std::optional<T> fromString(
        const char* string
    ) {
        return fromStringGeneric(string, DataString_c<T>::mapping);
    }

    template <slu::concepts::enumerator T>
    static constexpr T fromString(
        const char* string, std::size_t length
    ) {
        return fromStringGeneric(string, length, DataString_c<T>::mapping);
    }

    static constexpr std::optional<std::size_t> readEnumGeneric(
        const cJson::Reader_c::token_s& t, const std::span<const char* const>& mapping
    ) {
        if (t.is_number()) {
            return t.number;
        } else if (t.is_string()) {
            return fromStringGeneric(t.string.data(), t.string.size(), mapping);
        }
        return std::nullopt;
    }

    template <slu::concepts::enumerator T>
    static constexpr std::optional<std::size_t> readEnum(
        const cJson::Reader_c::token_s& t
    ) {
        return readEnumGeneric(t, DataString_c<T>::mapping);
    }

    template <>
    struct DataString_c<PLAYER_TYPE_e> {
        static constexpr const char* mapping[] = {
            "mario",    "luigi",           "blue_toad",   "yellow_toad",
            "toadette", "purple_toadette", "orange_toad", "black_toad",
        };
    };

    template <>
    struct DataString_c<STAGE_e> {
        static constexpr const char* mapping[] = {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10",
            "11",
            "12",
            "13",
            "14",
            "15",
            "16",
            "17",
            "18",
            "19",
            "coin",
            "ghost_house",
            "tower",
            "tower_2nd",
            "castle",
            "castle_2nd",
            "toad_house_1",
            "toad_house_2",
            "toad_house_3",
            "toad_house_4",
            "toad_house_5",
            "toad_house_6",
            "toad_house_7",
            "ambush_1",
            "ambush_2",
            "ambush_3",
            "cannon",
            "37",
            "airship",
            "rescue",
            "title",
            "peach_castle",
            "staff_roll",
        };
    };

    template <>
    struct DataString_c<PLAYER_MODE_e> {
        static constexpr const char* mapping[] = {
            "small", "mushroom", "fire", "mini", "propeller", "penguin", "ice",
        };
    };

    template <>
    struct DataString_c<STOCK_ITEM_e> {
        static constexpr const char* mapping[] = {
            "mushroom",      "fire_flower", "propeller_shroom", "ice_flower", "penguin_suit",
            "mini_mushroom", "star",
        };
    };

    template <>
    struct DataString_c<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e> {
        static constexpr const char* mapping[] = {
            "disabled",
            "per_game",
            "per_course",
            "per_exit",
        };
    };

    template <>
    struct DataString_c<dMj2dGame_c::START_KINOKO_KIND_e> {
        static constexpr const char* mapping[] = {
            "none", "yellow", "red", "green", "yellow_r", "red_r", "green_r",
        };
    };

    template <>
    struct DataString_c<PATH_DIRECTION_e> {
        static constexpr const char* mapping[] = {
            "normal",
            "reverse",
            "initial",
        };
    };
};
