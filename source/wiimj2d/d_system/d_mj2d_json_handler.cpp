// d_mj2d_json_handler.cpp
// NSMBW: ----

#include "d_mj2d_json_handler.h"

#include "component/c_json.h"
#include "d_system/d_info.h"
#include "d_system/d_mj2d_data.h"
#include "d_system/d_mj2d_game.h"
#include "d_system/d_nand_thread.h"
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <mkwcat/ToString.hpp>
#include <revolution/os/OSError.h>
#include <string_view>
#include <variant>

namespace {

template <mkwcat::Enum T> struct DataString;

template <mkwcat::Enum T>
inline constexpr const char* encode(
    T value
) {
    const std::integral auto integral = static_cast<std::underlying_type_t<T>>(value);
    if (integral < 0 || integral >= std::size(DataString<T>::mapping)) {
        return nullptr;
    }
    return DataString<T>::mapping[integral];
}

template <mkwcat::Enum T>
inline constexpr T decode(
    const char* string
) {
    std::size_t i;
    for (i = 0; i < std::size(DataString<T>::mapping); i++) {
        if (std::strcmp(DataString<T>::mapping[i], string) == 0) {
            break;
        }
    }
    return static_cast<T>(i);
}

template <> struct DataString<PLAYER_TYPE_e> {
    static constexpr const char* mapping[] = {
        "mario",    "luigi",           "blue_toad",   "yellow_toad",
        "toadette", "purple_toadette", "orange_toad", "black_toad",
    };
};

template <> struct DataString<STAGE_e> {
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

template <> struct DataString<PLAYER_MODE_e> {
    static constexpr const char* mapping[] = {
        "small", "mushroom", "fire", "mini", "propeller", "penguin", "ice",
    };
};

template <> struct DataString<STOCK_ITEM_e> {
    static constexpr const char* mapping[] = {
        "mushroom",      "fire_flower", "propeller_shroom", "ice_flower", "penguin_suit",
        "mini_mushroom", "star",
    };
};

template <> struct DataString<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e> {
    static constexpr const char* mapping[] = {
        "disabled",
        "per_game",
        "per_course",
        "per_exit",
    };
};

template <> struct DataString<dMj2dGame_c::START_KINOKO_KIND_e> {
    static constexpr const char* mapping[] = {
        "none", "yellow", "red", "green", "yellow_r", "red_r", "green_r",
    };
};

template <> struct DataString<PATH_DIRECTION_e> {
    static constexpr const char* mapping[] = {
        "normal",
        "reverse",
        "initial",
    };
};

} // namespace

static inline constexpr u32 strHash(
    const char* str, std::size_t length
) {
    u32 hash = 0;
    for (std::size_t i = 0; i < length; ++i) {
        hash = (hash * 9) + static_cast<u32>(str[i]);
    }
    return hash & 0xffff;
}

template <u32 N>
static inline consteval u32 strHash(
    const char (&str)[N]
) {
    return strHash(str, N - 1);
}

static STAGE_e decodeStageName(
    const char* str, std::size_t length, u32 hash
) {
    bool notNumber = false;
    for (size_t i = 0; i < length; i++) {
        if (str[i] < '0' || str[i] > '9') {
            notNumber = true;
            break;
        }
    }

    if (!notNumber) {
        int index = std::atoi(str) - 1;
        if (index < 0 || index >= STAGE_COUNT) {
            OS_REPORT(
                "SAVE WARNING!! Unable to decode course name \"%.*s\"", static_cast<int>(length),
                str
            );
            return STAGE_e::COUNT;
        }

        return static_cast<STAGE_e>(index);
    }

    switch (hash) {
#define CASE(key, id)                                                                              \
    case strHash(key):                                                                             \
        return STAGE_e::id;                                                                        \
        break;
        CASE("coin", COIN_BATTLE)
        CASE("ghost_house", GHOST_HOUSE)
        CASE("tower", TOWER)
        CASE("tower_2nd", TOWER_2)
        CASE("castle", CASTLE)
        CASE("castle_2nd", CASTLE_2)
        CASE("toad_house_1", KINOKO_HOUSE)
        CASE("toad_house_2", KINOKO_HOUSE_2)
        CASE("toad_house_3", KINOKO_HOUSE_3)
        CASE("toad_house_4", KINOKO_HOUSE_4)
        CASE("toad_house_5", KINOKO_HOUSE_5)
        CASE("toad_house_6", KINOKO_HOUSE_6)
        CASE("toad_house_7", KINOKO_HOUSE_7)
        CASE("ambush_1", ENEMY)
        CASE("ambush_2", ENEMY_2)
        CASE("ambush_3", ENEMY_3)
        CASE("cannon", CANNON)
        CASE("airship", DOOMSHIP)
        CASE("rescue", RESCUE)
        CASE("title", TITLE)
        CASE("peach_castle", PEACH_CASTLE)
        CASE("staff_roll", STAFFROLL)
        CASE("none", COUNT)
#undef CASE
    default:
        OS_REPORT(
            "SAVE WARNING!! Unable to decode course name \"%.*s\"", static_cast<int>(length), str
        );
        return STAGE_e::COUNT;
    }
}

static const char* encodeStageName(
    STAGE_e stage
) {
    if (stage >= STAGE_e::COUNT || stage < STAGE_e::STAGE_1) {
        return "none";
    }

    using StringArray = const char* const[];
    return StringArray{
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
        "staff_roll"
    }[static_cast<size_t>(stage)];
}

static dInfo_c::StageNo_s decodeFullStageName(
    const char* str, std::size_t length, u32 hash
) {
    std::size_t dashIndex = -1;
    for (int i = 0; i < length; i++) {
        if (str[i] < '0' || str[i] > '9') {
            if (dashIndex == -1 && str[i] == '-') {
                dashIndex = i;
                break;
            }
        }
    }

    if (dashIndex == -1) {
        // Invalid course, ignore
        OS_REPORT("Unknown course: %.*s", static_cast<int>(length), str);
        return dInfo_c::StageNo_s::invalid();
    }

    char* estr      = const_cast<char*>(str);
    estr[dashIndex] = '\0';
    int world       = std::atoi(str);
    estr[dashIndex] = '.';
    if (world < 1 || world > WORLD_COUNT) {
        return dInfo_c::StageNo_s::invalid();
    }

    return {
        .world = static_cast<WORLD_e>(world - 1),
        .stage = decodeStageName(
            str + dashIndex + 1, length - dashIndex - 1,
            strHash(str + dashIndex + 1, length - dashIndex - 1)
        ),
    };
}

static PLAYER_TYPE_e decodePlayerType(
    const char* str, std::size_t length, u32 hash
) {
    switch (hash) {
    case strHash("mario"):
        return PLAYER_TYPE_e::MARIO;
    case strHash("luigi"):
        return PLAYER_TYPE_e::LUIGI;
    case strHash("yellow_toad"):
        return PLAYER_TYPE_e::YELLOW_TOAD;
    case strHash("blue_toad"):
        return PLAYER_TYPE_e::BLUE_TOAD;
    case strHash("toadette"):
        return PLAYER_TYPE_e::TOADETTE;
    case strHash("purple_toadette"):
        return PLAYER_TYPE_e::PURPLE_TOADETTE;
    case strHash("orange_toad"):
        return PLAYER_TYPE_e::ORANGE_TOAD;
    case strHash("black_toad"):
        return PLAYER_TYPE_e::BLACK_TOAD;

    default:
        OS_REPORT("Unknown player type: %.*s\n", static_cast<int>(length), str);
        return PLAYER_TYPE_e::COUNT;
    }
}

bool dMj2dJsonHandler_c::value(
    s64 number
) {
    u32 value = static_cast<u32>(number);

    if (!expectValue()) {
        return mFlags & UNKNOWN_OBJECT;
    }

    if (mFlags & SUBTRACT_1) {
        value--;
    }

    if (mFlags & BIT_FLAGS_LE) {
#define CASE(type)                                                                                 \
    if (std::holds_alternative<type*>(mpValue)) {                                                  \
        *std::get<type*>(mpValue) |= static_cast<type>(1) << (value - 1);                          \
    }

        CASE(u8) else CASE(u16) else CASE(u32) else return false;
#undef CASE
        return true;
    }

    if (mObject == Object_e::HINT_MOVIE_ARRAY) {
        if (!std::holds_alternative<std::bitset<HINT_MOVIE_COUNT>*>(mpValue)) {
            return false;
        }
        if (value >= 0 && value < HINT_MOVIE_COUNT) {
            (*std::get<std::bitset<HINT_MOVIE_COUNT>*>(mpValue))[value] = true;
        }
        return true;
    } else if (mObject == Object_e::STAR_COIN_ARRAY) {
        if (!std::holds_alternative<dMj2dGame_c::COURSE_COMPLETION_e*>(mpValue)) {
            return false;
        }
        if (value < 1 || value > 3) {
            return false;
        }

        *std::get<dMj2dGame_c::COURSE_COMPLETION_e*>(mpValue) |=
            static_cast<dMj2dGame_c::COURSE_COMPLETION_e>(1 << (value - 1));
        return true;
    } else if (mObject == Object_e::PLAY_COUNT_ARRAY) {
        if (!std::holds_alternative<u16*>(mpValue)) {
            return false;
        }
        if (mWorld == WORLD_e::COUNT || mCourse == STAGE_e::COUNT) {
            // Ignore
            return true;
        }

        *(std::get<u16*>(mpValue) + static_cast<size_t>(mWorld) * STAGE_COUNT +
          static_cast<size_t>(mCourse)) = value;
        return true;
    }

    if (std::holds_alternative<dMj2dGame_c::WORLD_COMPLETION_e*>(mpValue)) {
        *std::get<dMj2dGame_c::WORLD_COMPLETION_e*>(mpValue) =
            static_cast<dMj2dGame_c::WORLD_COMPLETION_e>(!!value);
        return true;
    }

#define CASE(type)                                                                                 \
    if (std::holds_alternative<type*>(mpValue)) {                                                  \
        *std::get<type*>(mpValue)++ = static_cast<type>(value);                                    \
    }

    CASE(s8)
    else CASE(u8) else CASE(u16) else CASE(u32) else CASE(s32) else CASE(bool) else CASE(STAGE_e) //
#undef CASE
        else if (std::holds_alternative<dMj2dGame_c::PLAYER_TYPE_u8_e*>(mpValue)) {
        if (value >= PLAYER_COUNT || mPlayer == PLAYER_TYPE_e::COUNT) {
            // Ignore excess index
            return true;
        }
        *(std::get<dMj2dGame_c::PLAYER_TYPE_u8_e*>(mpValue) + value) =
            static_cast<dMj2dGame_c::PLAYER_TYPE_u8_e>(mPlayer);
    }
    else return false;

    return true;
}

bool dMj2dJsonHandler_c::string(
    std::string_view string
) {
    const char* str    = string.data();
    std::size_t length = string.length();

    if (!expectValue()) {
        OS_REPORT(
            "Not expecting string() (UNKNOWN_OBJECT=%s)\n",
            mkwcat::ToString(!!(mFlags & UNKNOWN_OBJECT))
        );
        return mFlags & UNKNOWN_OBJECT;
    }

    u32 hash = strHash(str, length);

    if (std::holds_alternative<dMj2dGame_c::Revision_s*>(mpValue)) {
        std::size_t dotIndex = -1;
        for (int i = 0; i < length; i++) {
            if (str[i] < '0' || str[i] > '9') {
                if (dotIndex == -1 && str[i] == '.') {
                    dotIndex = i;
                } else {
                    // Invalid version
                    return false;
                }
            }
        }

        if (dotIndex == -1) {
            // Invalid version
            return false;
        }

        char* estr     = const_cast<char*>(str);
        estr[dotIndex] = '\0';
        int major      = std::atoi(str);
        estr[dotIndex] = '.';
        if (major < 0 || major > 255) {
            return false;
        }

        char old     = estr[length];
        estr[length] = '\0';
        int minor    = std::atoi(str + dotIndex + 1);
        estr[length] = old;
        if (minor < 0 || minor > 255) {
            return false;
        }

        *std::get<dMj2dGame_c::Revision_s*>(mpValue)++ = {
            static_cast<u8>(major), static_cast<u8>(minor)
        };
    } else if (std::holds_alternative<bool*>(mpValue)) {
        if (length == 4 && hash == strHash("true")) {
            mValueCount++;
            HandlerIf_c::value(true);
        } else if (length == 5 && hash == strHash("false")) {
            mValueCount++;
            HandlerIf_c::value(false);
        } else {
            return false;
        }
    } else if (std::holds_alternative<dMj2dGame_c::GAME_COMPLETION_e*>(mpValue)) {
        auto& value = *std::get<dMj2dGame_c::GAME_COMPLETION_e*>(mpValue);
        switch (hash) {
        case strHash("created"):
            value &= ~dMj2dGame_c::GAME_COMPLETION_e::SAVE_EMPTY;
            break;
        case strHash("final_boss_beaten"):
            value |= dMj2dGame_c::GAME_COMPLETION_e::FINAL_BOSS_BEATEN;
            break;
        case strHash("all_goals"):
            value |= dMj2dGame_c::GAME_COMPLETION_e::GOAL_ALL;
            break;
        case strHash("all_star_coins"):
            value |= dMj2dGame_c::GAME_COMPLETION_e::COIN_ALL;
            break;
        case strHash("all_star_coins_w9"):
            value |= dMj2dGame_c::GAME_COMPLETION_e::COIN_ALL_SPECIAL;
            break;
        case strHash("completed"):
            value |= dMj2dGame_c::GAME_COMPLETION_e::GAME_COMPLETED;
            break;
        case strHash("super_guide_triggered"):
            value |= dMj2dGame_c::GAME_COMPLETION_e::SUPER_GUIDE_TRIGGERED;
            break;
        }
    } else if (std::holds_alternative<dMj2dGame_c::START_KINOKO_KIND_e*>(mpValue)) {
        auto& value = *std::get<dMj2dGame_c::START_KINOKO_KIND_e*>(mpValue);
        switch (hash) {
        case strHash("none"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::NONE;
            break;
        case strHash("yellow"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::YELLOW;
            break;
        case strHash("red"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::RED;
            break;
        case strHash("green"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::GREEN;
            break;
        case strHash("yellow_r"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::YELLOW_R;
            break;
        case strHash("red_r"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::RED_R;
            break;
        case strHash("green_r"):
            value = dMj2dGame_c::START_KINOKO_KIND_e::GREEN_R;
            break;
        }
    } else if (std::holds_alternative<dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e*>(mpValue)) {
        auto&                out   = *std::get<dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e*>(mpValue);
        PLAYER_CREATE_ITEM_e value = static_cast<PLAYER_CREATE_ITEM_e>(out);
        switch (hash) {
        case strHash("star_power"):
            value |= PLAYER_CREATE_ITEM_e::STAR_POWER;
            break;
        case strHash("yoshi"):
            value |= PLAYER_CREATE_ITEM_e::YOSHI;
            break;
        case strHash("bubble"):
            value |= PLAYER_CREATE_ITEM_e::BUBBLE;
            break;
        case strHash("rescue_toad"):
            value |= PLAYER_CREATE_ITEM_e::RESCUE_TOAD;
            break;
        }
        out = static_cast<dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e>(value);
    } else if (std::holds_alternative<dMj2dGame_c::PLAYER_MODE_u8_e*>(mpValue)) {
        auto&         out   = *std::get<dMj2dGame_c::PLAYER_MODE_u8_e*>(mpValue);
        PLAYER_MODE_e value = static_cast<PLAYER_MODE_e>(out);
        switch (hash) {
        case strHash("small"):
            value = PLAYER_MODE_e::NONE;
            break;
        case strHash("mushroom"):
            value = PLAYER_MODE_e::MUSHROOM;
            break;
        case strHash("fire"):
            value = PLAYER_MODE_e::FIRE_FLOWER;
            break;
        case strHash("ice"):
            value = PLAYER_MODE_e::ICE_FLOWER;
            break;
        case strHash("penguin"):
            value = PLAYER_MODE_e::PENGUIN_SUIT;
            break;
        case strHash("mini"):
            value = PLAYER_MODE_e::MINI_MUSHROOM;
            break;
        case strHash("propeller"):
            value = PLAYER_MODE_e::PROPELLER_SHROOM;
            break;
        }
        out = static_cast<dMj2dGame_c::PLAYER_MODE_u8_e>(value);
    } else if (std::holds_alternative<dMj2dGame_c::WORLD_COMPLETION_e*>(mpValue)) {
        if (hash == strHash("true")) {
            *std::get<dMj2dGame_c::WORLD_COMPLETION_e*>(mpValue) =
                dMj2dGame_c::WORLD_COMPLETION_e::WORLD_UNLOCKED;
        } else if (hash == strHash("false")) {
            *std::get<dMj2dGame_c::WORLD_COMPLETION_e*>(mpValue) =
                static_cast<dMj2dGame_c::WORLD_COMPLETION_e>(0);
        } else {
            return false;
        }
    } else if (std::holds_alternative<PLAYER_TYPE_e*>(mpValue)) {
        *std::get<PLAYER_TYPE_e*>(mpValue)++ = decodePlayerType(str, length, hash);
    } else if (std::holds_alternative<PATH_DIRECTION_e*>(mpValue)) {
        auto&            out   = *std::get<PATH_DIRECTION_e*>(mpValue);
        PATH_DIRECTION_e value = static_cast<PATH_DIRECTION_e>(out);
        switch (hash) {
        case strHash("normal"):
            value = PATH_DIRECTION_e::NORMAL;
            break;
        case strHash("reverse"):
            value = PATH_DIRECTION_e::REVERSE;
            break;
        case strHash("initial"):
            value = PATH_DIRECTION_e::INITIAL;
            break;
        }
        out = static_cast<PATH_DIRECTION_e>(value);
    } else if (std::holds_alternative<dMj2dGame_c::COURSE_COMPLETION_e*>(mpValue) &&
               mObject != Object_e::STAR_COIN_ARRAY) {
        auto& out = *std::get<dMj2dGame_c::COURSE_COMPLETION_e*>(mpValue);
        dMj2dGame_c::COURSE_COMPLETION_e value = static_cast<dMj2dGame_c::COURSE_COMPLETION_e>(out);
        switch (hash) {
        case strHash("normal"):
            value |= dMj2dGame_c::COURSE_COMPLETION_e::GOAL_NORMAL;
            break;
        case strHash("secret"):
            value |= dMj2dGame_c::COURSE_COMPLETION_e::GOAL_SECRET;
            break;
        case strHash("super_guide_normal"):
            value |= dMj2dGame_c::COURSE_COMPLETION_e::SUPER_GUIDE_GOAL_NORMAL;
            break;
        case strHash("super_guide_secret"):
            value |= dMj2dGame_c::COURSE_COMPLETION_e::SUPER_GUIDE_GOAL_SECRET;
            break;
        }
        out = static_cast<dMj2dGame_c::COURSE_COMPLETION_e>(value);
    } else if (std::holds_alternative<STAGE_e*>(mpValue)) {
        *std::get<STAGE_e*>(mpValue)++ = decodeStageName(str, length, hash);
    } else if (std::holds_alternative<StageNo_s*>(mpValue)) {
        *std::get<StageNo_s*>(mpValue)++ = decodeFullStageName(str, length, hash);
    } else if (std::holds_alternative<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e*>(mpValue)) {
        auto& out = *std::get<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e*>(mpValue);
        dMj2dGame_c::PIPE_RANDOMIZER_MODE_e value =
            static_cast<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e>(out);
        switch (hash) {
        case strHash("disabled"):
            value = dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::DISABLED;
            break;
        case strHash("per_game"):
            value = dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::PER_GAME;
            break;
        case strHash("per_course"):
            value = dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::PER_COURSE;
            break;
        case strHash("per_exit"):
            value = dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::PER_EXIT;
            break;
        }
        out = static_cast<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e>(value);
    } else {
        return false;
    }

    return true;
}

bool dMj2dJsonHandler_c::null() {
    if (!expectValue()) {
        OS_REPORT(
            "Not expecting null() (UNKNOWN_OBJECT=%s)\n",
            mkwcat::ToString(!!(mFlags & UNKNOWN_OBJECT))
        );
        return mFlags & UNKNOWN_OBJECT;
    }

    if (std::holds_alternative<PLAYER_TYPE_e*>(mpValue)) {
        *std::get<PLAYER_TYPE_e*>(mpValue)++ = PLAYER_TYPE_e::COUNT;
    } else if (std::holds_alternative<STAGE_e*>(mpValue)) {
        *std::get<STAGE_e*>(mpValue)++ = STAGE_e::COUNT;
    } else {
        OS_REPORT("Not expecting null!!!\n");
        return false;
    }

    return true;
}

bool dMj2dJsonHandler_c::key(
    std::string_view string
) {
    const char* str    = string.data();
    std::size_t length = string.length();

    u32         hash   = strHash(str, length);

    if (length == 0 || mValueCount != 0 ||
        mFlags & (EXPECT_ARRAY_START | EXPECT_ARRAY_END | EXPECT_OBJECT_START)) {
        OS_REPORT("Unexpected key: %.*s\n", static_cast<int>(length), str);
        return false;
    }

    if (mFlags & UNKNOWN_OBJECT) {
        if (mUnknownNest > 0) {
            return true;
        }
        mFlags &= ~UNKNOWN_OBJECT;
    }

    mFlags &= ~SUBTRACT_1;

    if (mObject == Object_e::BASE) {
        bool temp = false;
        if (length > 4 &&
            (!std::strncmp(str, "file", 4) || (temp = !std::strncmp(str, "temp", 4)))) {
            for (int i = 4; i < length; i++) {
                if (str[i] < '0' || str[i] > '9') {
                    // Invalid slot, ignore
                    mFlags |= Flag_e::UNKNOWN_OBJECT;
                    return true;
                }
            }
            int slot = std::atoi(str + 4) - 1;
            if (slot < 0 || slot >= SAVE_SLOT_COUNT) {
                // Invalid slot, ignore
                mFlags |= Flag_e::UNKNOWN_OBJECT;
                return true;
            }

            mSaveSlot = slot;
            mFlags    = Flag_e::EXPECT_OBJECT_START;
            if (temp) {
                mFlags |= TEMP_SAVE;
            }
            mObject = Object_e::FILE;
            return true;
        }

        dMj2dHeader_c& header = dNandThread_c::getSaveData()->mHeader;
        mValueCount           = 1;

        switch (hash) {
        case strHash("version"):
            mpValue = &header.mRevision;
            break;

        case strHash("last_selected_file"):
            mpValue = &header.mLastSelectedFile;
            break;

        case strHash("play_count_free_mode"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mpValue = &header.mPlayCountFreeMode[0][0];
            mObject = Object_e::PLAY_COUNT_ARRAY;
            break;

        case strHash("play_count_coin_battle"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mpValue = &header.mPlayCountCoinBattle[0][0];
            mObject = Object_e::PLAY_COUNT_ARRAY;
            break;

        case strHash("available_worlds"):
            mpValue     = &header.mMultiWorldOpenFlag;
            mValueCount = WORLD_COUNT;
            mFlags |= EXPECT_ARRAY_START | BIT_FLAGS_LE;
            break;

        default:
            OS_REPORT("Unknown object\n");
            mFlags |= UNKNOWN_OBJECT;
            mValueCount = 0;
            break;
        }
        return true;
    }

    dMj2dGame_c& game = !(mFlags & TEMP_SAVE) ? dNandThread_c::getSaveData()->mSaveGames[mSaveSlot]
                                              : dNandThread_c::getSaveData()->mTempGames[mSaveSlot];

    switch (mObject) {
    case Object_e::PLAY_COUNT_ARRAY: {
        dInfo_c::StageNo_s course = decodeFullStageName(str, length, hash);
        if (!course.isValid()) {
            // Invalid course, ignore
            mFlags |= Flag_e::UNKNOWN_OBJECT;
            return true;
        }
        mValueCount = 1;
        return true;
    }

    case Object_e::FILE: {
        mValueCount = 1;
        switch (hash) {
        case strHash("version"):
            mpValue = &game.mRevision;
            break;

        case strHash("completion"):
            mValueCount = 8;
            mFlags |= EXPECT_ARRAY_START;
            mpValue = &game.mGameCompletion;
            break;

        case strHash("score"):
            mpValue = &game.mScore;
            break;

        case strHash("staff_roll_high_score"):
            mpValue = &game.mStaffRollHighScore;
            break;

        case strHash("current_world"):
            mFlags |= SUBTRACT_1;
            mpValue = &game.mCurrentWorld;
            break;

        case strHash("current_sub_world"):
            mpValue = &game.mCurrentSubWorld;
            break;

        case strHash("path_node"):
            mpValue = &game.mCurrentPathNode;
            break;

        case strHash("stock_item"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mObject = Object_e::STOCK_ITEM;
            break;

        case strHash("hint_movie_bought"):
            mValueCount = HINT_MOVIE_COUNT;
            mFlags |= EXPECT_ARRAY_START;
            mObject = Object_e::HINT_MOVIE_ARRAY;
            mpValue = &game.mOtehonMenuOpen;
            break;

        case strHash("player"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mObject = Object_e::PLAYER_KEY;
            mPlayer = PLAYER_TYPE_e::COUNT;
            break;

        case strHash("world"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mObject = Object_e::WORLD_KEY;
            mWorld  = WORLD_e::COUNT;
            break;

        case strHash("checkpoint"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mObject = Object_e::CHECKPOINT;
            break;

        case strHash("pipe_randomizer_mode"):
            mValueCount = 1;
            mpValue     = &game.mPipeRandomizerMode;
            break;

        case strHash("pipe_randomizer_seed"):
            mValueCount = 1;
            mpValue     = &game.mPipeRandomizerSeed;
            break;

        default:
            OS_REPORT("Unknown object\n");
            mValueCount = 0;
            mFlags |= UNKNOWN_OBJECT;
            break;
        }
        return true;
    }

    case Object_e::STOCK_ITEM: {
        STOCK_ITEM_e item;
        switch (hash) {
        case strHash("mushroom"):
            item = STOCK_ITEM_e::MUSHROOM;
            break;
        case strHash("fire_flower"):
            item = STOCK_ITEM_e::FIRE_FLOWER;
            break;
        case strHash("ice_flower"):
            item = STOCK_ITEM_e::ICE_FLOWER;
            break;
        case strHash("propeller_shroom"):
            item = STOCK_ITEM_e::PROPELLER_SHROOM;
            break;
        case strHash("penguin_suit"):
            item = STOCK_ITEM_e::PENGUIN_SUIT;
            break;
        case strHash("mini_mushroom"):
            item = STOCK_ITEM_e::MINI_MUSHROOM;
            break;
        case strHash("star"):
            item = STOCK_ITEM_e::STAR;
            break;

        default:
            OS_REPORT("Unknown object\n");
            mValueCount = 0;
            mFlags |= UNKNOWN_OBJECT;
            return true;
        }

        mpValue     = &game.mStockItemCount[static_cast<int>(item)];
        mValueCount = 1;
        return true;
    }

    case Object_e::PLAYER_KEY: {
        mPlayer = decodePlayerType(str, length, hash);
        if (mPlayer == PLAYER_TYPE_e::COUNT) {
            mFlags |= UNKNOWN_OBJECT;
            return true;
        }
        mFlags |= EXPECT_OBJECT_START;
        mObject = Object_e::PLAYER;
        return true;
    }

    case Object_e::PLAYER: {
        int index   = static_cast<int>(mPlayer);
        mValueCount = 1;

        switch (hash) {
        case strHash("continues"):
            mpValue = &game.mPlayerContinue[index];
            break;
        case strHash("coins"):
            mpValue = &game.mPlayerCoin[index];
            break;
        case strHash("lives"):
            mpValue = &game.mPlayerLife[index];
            break;
        case strHash("equip"):
            mValueCount = 8;
            mFlags |= EXPECT_ARRAY_START;
            game.mPlayerCreateItem[index] = static_cast<dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e>(0);
            mpValue                       = &game.mPlayerCreateItem[index];
            break;
        case strHash("powerup"):
            mpValue = &game.mPlayerPowerup[index];
            break;
        case strHash("player"):
            mValueCount = 1;
            mpValue     = &game.mPlayerCharacter[0];
            break;

        default:
            OS_REPORT("Unknown object\n");
            mValueCount = 0;
            mFlags |= UNKNOWN_OBJECT;
            return true;
        }
        return true;
    }

    case Object_e::ENEMY_KEY: {
        for (size_t i = 0; i < length; i++) {
            if (str[i] < '0' || str[i] > '9') {
                // Invalid enemy, ignore
                OS_REPORT("Unknown object\n");
                mFlags |= Flag_e::UNKNOWN_OBJECT;
                return true;
            }
        }

        int enemyIndex = atoi(str);
        if (enemyIndex < 0 || enemyIndex >= AMBUSH_ENEMY_COUNT) {
            // Invalid enemy, ignore
            OS_REPORT("Unknown object\n");
            mFlags |= Flag_e::UNKNOWN_OBJECT;
            return true;
        }

        mFlags |= EXPECT_OBJECT_START;
        mObject  = Object_e::ENEMY;
        mWmEnemy = enemyIndex;
        return true;
    }

    case Object_e::ENEMY: {
        int wmIndex = static_cast<int>(mWorld);

        mValueCount = 1;
        switch (hash) {
        case strHash("revival_count"):
            mpValue = &game.mEnemyRevivalCount[wmIndex][mWmEnemy];
            break;
        case strHash("sub_world"):
            mpValue = &game.mEnemySceneNo[wmIndex][mWmEnemy];
            break;
        case strHash("path_node"):
            mpValue = &game.mEnemyPosIndex[wmIndex][mWmEnemy];
            break;
        case strHash("walk_direction"):
            mpValue = &game.mEnemyWalkDir[wmIndex][mWmEnemy];
            break;
        default:
            OS_REPORT("Unknown object\n");
            mValueCount = 0;
            mFlags |= UNKNOWN_OBJECT;
            break;
        }
        return true;
    }

    case Object_e::COURSE_KEY: {
        mCourse = decodeStageName(str, length, hash);
        if (mCourse == STAGE_e::COUNT) {
            // Invalid course, ignore
            OS_REPORT("Unknown object\n");
            mFlags |= Flag_e::UNKNOWN_OBJECT;
            return true;
        }

        mFlags |= EXPECT_OBJECT_START;
        mObject = Object_e::COURSE;
        return true;
    }

    case Object_e::COURSE: {
        int wmIndex = static_cast<int>(mWorld);
        int index   = static_cast<int>(mCourse);

        mValueCount = 1;
        switch (hash) {
        case strHash("goal"):
            mValueCount = 4;
            mFlags |= EXPECT_ARRAY_START;
            mpValue = &game.mCourseCompletion[wmIndex][index];
            break;

        case strHash("star_coin"):
            mValueCount = 3;
            mFlags |= EXPECT_ARRAY_START;
            mObject = Object_e::STAR_COIN_ARRAY;
            mpValue = &game.mCourseCompletion[wmIndex][index];
            break;

        case strHash("deaths"):
            mpValue = &game.mDeathCount[wmIndex][index];
            break;

        case strHash("deaths_switch"):
            if (mWorld != WORLD_e::WORLD_3 || mCourse != STAGE_e::STAGE_4) {
                OS_REPORT("Unknown object\n");
                mValueCount = 0;
                mFlags |= UNKNOWN_OBJECT;
                return true;
            }
            mpValue = &game.mDeathCountSwitch;
            break;

        default:
            OS_REPORT("Unknown object\n");
            mValueCount = 0;
            mFlags |= UNKNOWN_OBJECT;
            break;
        }
        return true;
    }

    case Object_e::WORLD_KEY: {
        for (std::size_t i = 0; i < length; i++) {
            if (str[i] < '0' || str[i] > '9') {
                // Invalid world, ignore
                OS_REPORT("Invalid world: %s\n", str);
                mFlags |= Flag_e::UNKNOWN_OBJECT;
                return true;
            }
        }

        int worldIndex = std::atoi(str) - 1;
        if (worldIndex < 0 || worldIndex >= static_cast<int>(WORLD_e::COUNT)) {
            // Invalid world, ignore
            OS_REPORT("Invalid world: %d\n", worldIndex + 1);
            mFlags |= Flag_e::UNKNOWN_OBJECT;
            return true;
        }

        mFlags |= EXPECT_OBJECT_START;
        mObject = Object_e::WORLD;
        mWorld  = static_cast<WORLD_e>(worldIndex);
        return true;
    }

    case Object_e::WORLD: {
        int index   = static_cast<int>(mWorld);
        mValueCount = 1;
        switch (hash) {
        case strHash("open"):
            mpValue = &game.mWorldCompletion[index];
            break;

        case strHash("toad_rescue_course"):
            mpValue = &game.mKinopioCourseNo[index];
            break;

        case strHash("start_minigame_type"):
            mpValue = &game.mStartKinokoType[index];
            break;

        case strHash("ambush_enemy"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mObject = Object_e::ENEMY_KEY;
            break;

        case strHash("course"):
            mValueCount = 0;
            mFlags |= EXPECT_OBJECT_START;
            mObject = Object_e::COURSE_KEY;
            break;

        case strHash("vine_counter"):
            if (mWorld != WORLD_e::WORLD_5) {
                OS_REPORT("Unknown object\n");
                mValueCount = 0;
                mFlags |= UNKNOWN_OBJECT;
                return true;
            }

            mpValue = &game.mIbaraNow;
            break;

        case strHash("switch"):
            if (mWorld != WORLD_e::WORLD_3) {
                OS_REPORT("Unknown object\n");
                mValueCount = 0;
                mFlags |= UNKNOWN_OBJECT;
                return true;
            }

            mpValue = &game.mSwitchOn;
            break;

        default:
            OS_REPORT("Unknown object\n");
            mValueCount = 0;
            mFlags |= UNKNOWN_OBJECT;
            break;
        }
        return true;
    }

    case Object_e::CHECKPOINT: {
        mValueCount                  = 1;
        dMj2dGame_c::Cyuukan_s& ckpt = game.mCheckpoint;
        switch (hash) {
        case strHash("stage"):
            mpValue = &ckpt.stage;
            break;

        case strHash("area"):
            mpValue = &ckpt.area;
            mFlags |= SUBTRACT_1;
            break;

        case strHash("entrance"):
            mpValue = &ckpt.entrance;
            break;

        case strHash("coin"):
            mpValue     = ckpt.coin;
            mValueCount = STAR_COIN_COUNT;
            mFlags |= EXPECT_ARRAY_START;
            break;

        case strHash("flag"):
            mpValue     = ckpt.flag;
            mValueCount = std::size(ckpt.flag);
            mFlags |= EXPECT_ARRAY_START;
            break;

        case strHash("face_left"):
            mpValue = &ckpt.face_left;
            break;

        case strHash("index"):
            mpValue = &ckpt.index;
            break;
        }

        return true;
    }

    default:
        return false;
    }
}

bool dMj2dJsonHandler_c::startObject() {
    if (mFlags & UNKNOWN_OBJECT) {
        mUnknownNest++;
        return true;
    }

    if (mFlags & EXPECT_OBJECT_START) {
        mFlags &= ~EXPECT_OBJECT_START;
        return true;
    }

    OS_REPORT("Unexpected start of object\n");
    return false;
}

bool dMj2dJsonHandler_c::endObject() {
    if (mFlags & UNKNOWN_OBJECT) {
        if (mUnknownNest == 0) {
            return false;
        }

        if (--mUnknownNest == 0) {
            mFlags &= ~UNKNOWN_OBJECT;
        }
        return true;
    }

    if (mFlags & EXPECT_OBJECT_START || mFlags & JSON_END) {
        // Expected an object start
        return false;
    }

    if (mObject == Object_e::PLAYER) {
        mObject = Object_e::PLAYER_KEY;
        mPlayer = PLAYER_TYPE_e::COUNT;
        return true;
    } else if (mObject == Object_e::PLAYER_KEY) {
        mObject = Object_e::FILE;
        return true;
    } else if (mObject == Object_e::STOCK_ITEM) {
        mObject = Object_e::FILE;
        return true;
    } else if (mObject == Object_e::CHECKPOINT) {
        mObject = Object_e::FILE;
        return true;
    } else if (mObject == Object_e::ENEMY) {
        mObject  = Object_e::ENEMY_KEY;
        mWmEnemy = AMBUSH_ENEMY_COUNT;
        return true;
    } else if (mObject == Object_e::ENEMY_KEY) {
        mObject = Object_e::WORLD;
        return true;
    } else if (mObject == Object_e::COURSE) {
        mObject = Object_e::COURSE_KEY;
        mCourse = STAGE_e::COUNT;
        return true;
    } else if (mObject == Object_e::COURSE_KEY) {
        mObject = Object_e::WORLD;
        return true;
    } else if (mObject == Object_e::WORLD) {
        mObject = Object_e::WORLD_KEY;
        mWorld  = WORLD_e::COUNT;
        return true;
    } else if (mObject == Object_e::WORLD_KEY) {
        mObject = Object_e::FILE;
        return true;
    } else if (mObject == Object_e::FILE) {
        mObject   = Object_e::BASE;
        mSaveSlot = -1;
        return true;
    } else if (mObject == Object_e::PLAY_COUNT_ARRAY) {
        mObject = Object_e::BASE;
        return true;
    } else if (mObject == Object_e::BASE) {
        mFlags = JSON_END;
        return true;
    }

    OS_REPORT("Unexpected end of object\n");
    return false;
}

bool dMj2dJsonHandler_c::startArray() {
    if (mFlags & UNKNOWN_OBJECT) {
        mUnknownNest++;
        return true;
    }

    if (mFlags & EXPECT_ARRAY_START) {
        mFlags &= ~EXPECT_ARRAY_START;
        mFlags |= EXPECT_ARRAY_END;
        return true;
    }

    return false;
}

bool dMj2dJsonHandler_c::endArray() {
    if (mFlags & UNKNOWN_OBJECT) {
        if (mUnknownNest == 0) {
            return false;
        }

        if (--mUnknownNest == 0) {
            mFlags &= ~UNKNOWN_OBJECT;
        }
        return true;
    }

    if (mFlags & EXPECT_ARRAY_END) {
        mFlags &= ~(EXPECT_ARRAY_END | BIT_FLAGS_LE);
        mValueCount = 0;
    }
    if (mObject == Object_e::STAR_COIN_ARRAY) {
        mObject = Object_e::COURSE;
    }
    if (mObject == Object_e::HINT_MOVIE_ARRAY) {
        mObject = Object_e::FILE;
    }

    return true;
}

bool dMj2dJsonHandler_c::writeJSON(
    std::FILE* f
) {
    dMj2dData_c*    data   = dNandThread_c::getSaveData();
    dMj2dHeader_c&  header = data->mHeader;
    cJson::Writer_c w(f);

    // clang-format off
    bool result = w.startObject() && (
        w.fieldFmt("version", "%d.%d", header.mRevision.mMajor, header.mRevision.mMinor) &&
        w.field("last_selected_file", header.mLastSelectedFile) &&
        w.key("play_count_free_mode")   && marshalPlayCounts(w, header.mPlayCountFreeMode) &&
        w.key("play_count_coin_battle") && marshalPlayCounts(w, header.mPlayCountCoinBattle) &&
        w.key("available_worlds")       && w.startArray() &&
            marshalAvailableWorlds(w, header)
        && w.endArray() &&
        marshalFileData(w, data)
    ) && w.endObject();
    // clang-format on

    if (!result) {
        OS_REPORT("Error during saving at position %lu\n", w.getTotalSize());
    }
    return result;
}

bool dMj2dJsonHandler_c::marshalPlayCounts(
    cJson::Writer_c& w, const u16 (&counts)[WORLD_COUNT][STAGE_COUNT]
) {
    if (!w.startObject()) {
        return false;
    }
    for (int world = 0; world < WORLD_COUNT; world++) {
        for (int stage = 0; stage < STAGE_COUNT; stage++) {
            u16 v = counts[world][stage];
            if (v == 0) {
                continue;
            }

            if (!w.keyFmt("%d-%s", world + 1, encodeStageName(static_cast<STAGE_e>(stage))) ||
                !w.value(static_cast<s64>(v))) {
                return false;
            }
        }
    }
    return w.endObject();
}

bool dMj2dJsonHandler_c::marshalAvailableWorlds(
    cJson::Writer_c& w, const dMj2dHeader_c& header
) {
    int world = 0;
    for (; world < WORLD_COUNT; world++) {
        if (header.mMultiWorldOpenFlag & (1 << world)) {
            if (!w.value(static_cast<s64>(world + 1))) {
                return false;
            }
        }
    }
    return true;
}

bool dMj2dJsonHandler_c::marshalFileData(
    cJson::Writer_c& w, const dMj2dData_c* data
) {
    dMj2dGame_c default_game{};
    default_game.initialize();

    bool result = true;
    for (int slot = 0; slot < SAVE_SLOT_COUNT * 2 && result; slot++) {
        const dMj2dGame_c& g      = slot < SAVE_SLOT_COUNT ? data->mSaveGames[slot]
                                                           : data->mTempGames[slot - SAVE_SLOT_COUNT];
        const char*        format = slot < SAVE_SLOT_COUNT ? "file%d" : "temp%d";

        using enum dMj2dGame_c::GAME_COMPLETION_e;
        using enum STOCK_ITEM_e;

        if (std::memcmp(&g, &default_game, sizeof(dMj2dGame_c)) == 0) {
            continue;
        }

        // clang-format off
        result &= w.keyFmt(format, slot + 1) && w.startObject() && (
            w.fieldFmt("version", "%d.%d", g.mRevision.mMajor, g.mRevision.mMinor) &&
            w.key("completion") && w.startArray() && (
                (g.isFlag(SAVE_EMPTY)             || w.string("created"))           &&
                (!g.isFlag(FINAL_BOSS_BEATEN)     || w.string("final_boss_beaten")) &&
                (!g.isFlag(GOAL_ALL)              || w.string("all_goals"))         &&
                (!g.isFlag(COIN_ALL)              || w.string("all_star_coins"))    &&
                (!g.isFlag(COIN_ALL_SPECIAL)      || w.string("all_star_coins_w9")) &&
                (!g.isFlag(GAME_COMPLETED)        || w.string("completed"))         &&
                (!g.isFlag(SUPER_GUIDE_TRIGGERED) || w.string("super_gude_triggered"))
            ) && w.endArray() &&
            w.field("score",                 g.mScore)              &&
            w.field("staff_roll_high_score", g.mStaffRollHighScore) &&
            w.field("current_world",         g.mCurrentWorld + 1)   &&
            w.field("current_sub_world",     g.mCurrentSubWorld)    &&
            w.field("path_node",             g.mCurrentPathNode)    &&
            (g.mPipeRandomizerMode == dMj2dGame_c::PIPE_RANDOMIZER_MODE_e::DISABLED || (
                w.field("pipe_randomizer_mode", encode(g.mPipeRandomizerMode)) &&
                w.field("pipe_randomizer_seed", static_cast<s32>(g.mPipeRandomizerSeed)))
            ) &&
            w.key("stock_item") && w.startObject() && (
                marshalStockItem(w, g)
            ) && w.endObject() &&
            (g.mCheckpoint.index < 0 || (w.key("checkpoint") && w.startObject() && (
                w.field("index",    g.mCheckpoint.index)                  &&
                w.field("stage",    encodeStageName(g.mCheckpoint.stage)) &&
                w.field("area",     g.mCheckpoint.area + 1)               &&
                w.field("entrance", g.mCheckpoint.entrance)               &&
                w.key("flag") && w.startArray() && (
                    marshalPlayerType(w, g.mCheckpoint.flag[0]) &&
                    marshalPlayerType(w, g.mCheckpoint.flag[1], false)
                ) && w.endArray() &&
                w.key("coin") && w.startArray() && (
                    marshalPlayerType(w, g.mCheckpoint.coin[0]) &&
                    marshalPlayerType(w, g.mCheckpoint.coin[1]) &&
                    marshalPlayerType(w, g.mCheckpoint.coin[2])
                )) && w.endObject())) &&
            w.key("hint_movie_bought") && w.startArray() &&
                marshalBitIndices(w, g.mOtehonMenuOpen)
            && w.endArray() &&
            w.key("player") && w.startObject() &&
                marshalPlayerData(w, g)
            && w.endObject() &&
            w.key("world") && w.startObject() &&
                marshalWorldData(w, g)
            && w.endObject()
        ) && w.endObject();
        // clang-format on
    }
    return result;
}

bool dMj2dJsonHandler_c::marshalStockItem(
    cJson::Writer_c& w, const dMj2dGame_c& g
) {
    const char*                          name = nullptr;
    std::underlying_type_t<STOCK_ITEM_e> i    = 0;
    while ((name = encode(static_cast<STOCK_ITEM_e>(i++))) != nullptr) {
        if (auto value = g.mStockItemCount[i]; value != 0) {
            if (!w.field(name, value)) {
                return false;
            }
        }
    }
    return true;
}

bool dMj2dJsonHandler_c::marshalPlayerData(
    cJson::Writer_c& w, const dMj2dGame_c& g
) {
    for (std::size_t i = 0; i < std::size(dMj2dGame_c::scDefaultPlayerTypes); i++) {
        if (!marshalPlayerData(w, g, dMj2dGame_c::scDefaultPlayerTypes[i])) {
            return false;
        }
    }
    return true;
}

bool dMj2dJsonHandler_c::marshalPlayerData(
    cJson::Writer_c& w, const dMj2dGame_c& g, PLAYER_TYPE_e player
) {
    if (player < PLAYER_TYPE_e::MARIO || player >= PLAYER_TYPE_e::COUNT) {
        return false;
    }

    const int index         = static_cast<int>(player);

    int       player_number = PLAYER_COUNT;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (static_cast<PLAYER_TYPE_e>(g.mPlayerCharacter[i]) == player) {
            player_number = i;
            break;
        }
    }

    using enum PLAYER_CREATE_ITEM_e;
    const PLAYER_CREATE_ITEM_e equip =
        static_cast<PLAYER_CREATE_ITEM_e>(g.mPlayerCreateItem[index]);

    // clang-format off
    return w.key(encode(player)) && w.startObject() && (
        w.field("lives",     g.mPlayerLife[index])     &&
        w.field("coins",     g.mPlayerCoin[index])     &&
        w.field("continues", g.mPlayerContinue[index]) &&
        w.key("equip") && w.startArray() && (
            (!(equip & STAR_POWER) || w.string("star_power"))
        ) && w.endArray() &&
        w.field("powerup",   encode(static_cast<PLAYER_MODE_e>(g.mPlayerPowerup[index]))) &&
        w.field("player", player_number)
    ) && w.endObject();
    // clang-format on
}

bool dMj2dJsonHandler_c::marshalWorldData(
    cJson::Writer_c& w, const dMj2dGame_c& g
) {
    bool result = true;
    for (int world = 0; world < WORLD_COUNT && result; world++) {
        // clang-format off
        const bool open = !!(g.mWorldCompletion[world] & dMj2dGame_c::WORLD_COMPLETION_e::WORLD_UNLOCKED);
        result = w.keyFmt("%d", world + 1) && w.startObject() && (
            w.field("open", open) &&
            w.field("toad_rescue_course",  encode(g.mKinopioCourseNo[world])) &&
            w.field("start_minigame_type", encode(g.mStartKinokoType[world])) &&
            w.key("ambush_enemy") && w.startObject() &&
                marshalWorldAmbushEnemyData(w, g, world)
            && w.endObject() &&
            w.key("course") && w.startObject() &&
                marshalWorldCourseData(w, g, world)
            && w.endObject()
        ) && w.endObject();
        // clang-format on
    }
    return result;
}

bool dMj2dJsonHandler_c::marshalWorldAmbushEnemyData(
    cJson::Writer_c& w, const dMj2dGame_c& g, int world
) {
    bool result = true;
    for (int enemy = 0; enemy < AMBUSH_ENEMY_COUNT && result; enemy++) {
        struct AmbushEnemy_s {
            constexpr bool operator==(const AmbushEnemy_s&) const = default;

            u8               revival_count                        = 0;
            u8               sub_world                            = 0;
            s8               path_node                            = -1;
            PATH_DIRECTION_e walk_direction                       = PATH_DIRECTION_e::INITIAL;
        };

        AmbushEnemy_s entry = {
            .revival_count  = g.mEnemyRevivalCount[world][enemy],
            .sub_world      = g.mEnemySceneNo[world][enemy],
            .path_node      = g.mEnemyPosIndex[world][enemy],
            .walk_direction = g.mEnemyWalkDir[world][enemy],
        };

        if (entry == AmbushEnemy_s{}) {
            continue;
        }

        // clang-format off
        result &= w.keyFmt("%d", enemy) && w.startObject() && (
            w.field("revival_count",  entry.revival_count) &&
            w.field("sub_world",      entry.sub_world)     &&
            w.field("path_node",      entry.path_node)     &&
            w.field("walk_direction", encode(entry.walk_direction))
        ) && w.endObject();
        // clang-format on
    }
    return result;
}

bool dMj2dJsonHandler_c::marshalWorldCourseData(
    cJson::Writer_c& w, const dMj2dGame_c& g, int world
) {
    bool result = true;
    for (int stage = 0; stage < STAGE_COUNT && result; stage++) {
        struct StageData_s {
            constexpr bool operator==(const StageData_s&) const = default;

            bool goal_normal                                    = false;
            bool goal_secret                                    = false;
            bool goal_super_guide_normal                        = false;
            bool goal_super_guide_secret                        = false;
            bool star_coin[3]                                   = {false, false, false};
            u8   deaths                                         = 0;
            u8   deaths_switch                                  = 0;
        };

        using enum dMj2dGame_c::COURSE_COMPLETION_e;
        auto        completion      = g.mCourseCompletion[world][stage];
        bool        is_switch_stage = world == +WORLD_e::WORLD_3 && stage == +STAGE_e::STAGE_4;

        StageData_s entry{
            .goal_normal             = !!(completion & GOAL_NORMAL),
            .goal_secret             = !!(completion & GOAL_SECRET),
            .goal_super_guide_normal = !!(completion & SUPER_GUIDE_GOAL_NORMAL),
            .goal_super_guide_secret = !!(completion & SUPER_GUIDE_GOAL_SECRET),
            .star_coin =
                {
                    !!(completion & COIN1_COLLECTED),
                    !!(completion & COIN2_COLLECTED),
                    !!(completion & COIN3_COLLECTED),
                },
            .deaths        = g.mDeathCount[world][stage],
            .deaths_switch = is_switch_stage ? g.mDeathCountSwitch : static_cast<u8>(0),
        };

        StageData_s stage_default = {};
        if (stage == +STAGE_e::RESCUE) {
            stage_default.goal_normal = true;
            stage_default.goal_secret = true;
        }

        if (entry == stage_default) {
            continue;
        }

        // clang-format off
        result &= w.key(encode(static_cast<STAGE_e>(stage))) && w.startObject() && (
            w.key("goal") && w.startArray() && (
                (!entry.goal_normal             || w.string("normal"))            &&
                (!entry.goal_secret             || w.string("secret"))            &&
                (!entry.goal_super_guide_normal || w.string("super_guide_normal")) &&
                (!entry.goal_super_guide_secret || w.string("super_guide_secret"))
            ) && w.endArray() &&
            w.key("star_coin") && w.startArray() && (
                (!entry.star_coin[0] || w.value(1ll)) &&
                (!entry.star_coin[1] || w.value(2ll)) &&
                (!entry.star_coin[2] || w.value(3ll))
            ) && w.endArray() &&
            w.field("deaths", entry.deaths) &&
            (!is_switch_stage || w.field("deaths_switch", entry.deaths_switch))
        ) && w.endObject();
        // clang-format on
    }
    return result;
}

bool dMj2dJsonHandler_c::marshalPlayerType(
    cJson::Writer_c& w, PLAYER_TYPE_e type, bool null
) {
    if (type < PLAYER_TYPE_e::MARIO || type >= PLAYER_TYPE_e::COUNT) {
        return !null || w.null();
    }
    return w.string(encode(type));
}

template <std::size_t N>
bool dMj2dJsonHandler_c::marshalBitIndices(
    cJson::Writer_c& w, const std::bitset<N>& bits
) {
    for (std::size_t i = 0; i < N; i++) {
        if (bits[i] && !w.value(static_cast<s64>(i))) {
            return false;
        }
    }
    return true;
}
