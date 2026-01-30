// d_mj2d_json_handler.cpp
// NSMBW: ----

#include "d_mj2d_json_handler.h"

#include "component/c_json.h"
#include "d_system/d_mj2d_data.h"
#include "d_system/d_nand_thread.h"
#include <cstdlib>
#include <cstring>
#include <revolution/os/OSError.h>

static inline constexpr u32 strHash(const char* str, std::size_t length)
{
    u32 hash = 0;
    for (std::size_t i = 0; i < length; ++i) {
        hash = (hash * 9) + static_cast<u32>(str[i]);
    }
    return hash & 0xffff;
}

template <u32 N>
static inline consteval u32 strHash(const char (&str)[N])
{
    return strHash(str, N - 1);
}

static STAGE_e decodeStageName(const char* str, std::size_t length, u32 hash)
{
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
              "SAVE WARNING!! Unable to decode course name \"%.*s\"", static_cast<int>(length), str
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

static const char* encodeStageName(STAGE_e stage)
{
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

bool dMj2dJsonHandler_c::value(s64 number)
{
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
        if (!std::holds_alternative<cBitmask_c<HINT_MOVIE_COUNT>*>(mpValue)) {
            return false;
        }
        if (value >= 0 && value < HINT_MOVIE_COUNT) {
            std::get<cBitmask_c<HINT_MOVIE_COUNT>*>(mpValue)->setBit(value);
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
    else CASE(u8) else CASE(u16) else CASE(u32) else CASE(bool) else CASE(STAGE_e) //
      else if (std::holds_alternative<dMj2dGame_c::PLAYER_TYPE_u8_e*>(mpValue))
    {
        if (value >= PLAYER_COUNT || mPlayer == PLAYER_TYPE_e::COUNT) {
            // Ignore excess index
            return true;
        }
        *(std::get<dMj2dGame_c::PLAYER_TYPE_u8_e*>(mpValue) + value) =
          static_cast<dMj2dGame_c::PLAYER_TYPE_u8_e>(mPlayer);
    }
    else return false;
#undef CASE

    return true;
}

bool dMj2dJsonHandler_c::string(const char* str, std::size_t length, bool copy)
{
    // OS_REPORT("String: %.*s\n", (int) length, str);

    if (!expectValue()) {
        OS_REPORT("Not expecting String() %d\n", mFlags & UNKNOWN_OBJECT);
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

        char* estr = const_cast<char*>(str);
        estr[dotIndex] = '\0';
        int major = std::atoi(str);
        estr[dotIndex] = '.';
        if (major < 0 || major > 255) {
            return false;
        }

        char old = estr[length];
        estr[length] = '\0';
        int minor = std::atoi(str + dotIndex + 1);
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
        auto& out = *std::get<dMj2dGame_c::PLAYER_CREATE_ITEM_u8_e*>(mpValue);
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
        auto& out = *std::get<dMj2dGame_c::PLAYER_MODE_u8_e*>(mpValue);
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
    } else if (std::holds_alternative<PATH_DIRECTION_e*>(mpValue)) {
        auto& out = *std::get<PATH_DIRECTION_e*>(mpValue);
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
    } else {
        return false;
    }

    return true;
}

bool dMj2dJsonHandler_c::key(const char* str, std::size_t length, bool copy)
{
    u32 hash = strHash(str, length);

    if (length == 0 || mValueCount != 0 ||
        mFlags & (EXPECT_ARRAY_START | EXPECT_ARRAY_END | EXPECT_OBJECT_START)) {
        OS_REPORT("Unexpected key: %.*s\n", (int) length, str);
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
            mFlags = Flag_e::EXPECT_OBJECT_START;
            if (temp) {
                mFlags |= TEMP_SAVE;
            }
            mObject = Object_e::FILE;
            return true;
        }

        dMj2dHeader_c& header = dNandThread_c::getSaveData()->mHeader;
        mValueCount = 1;

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
            mpValue = &header.mMultiWorldOpenFlag;
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
            OS_REPORT("Unknown play count course: %.*s", length, str);
            mFlags |= Flag_e::UNKNOWN_OBJECT;
            return true;
        }

        char* estr = const_cast<char*>(str);
        estr[dashIndex] = '\0';
        int world = std::atoi(str);
        estr[dashIndex] = '.';
        if (world < 1 || world > WORLD_COUNT) {
            return false;
        }
        mWorld = static_cast<WORLD_e>(world - 1);

        mCourse = decodeStageName(
          str + dashIndex + 1, length - dashIndex - 1,
          strHash(str + dashIndex + 1, length - dashIndex - 1)
        );
        if (mCourse == STAGE_e::COUNT) {
            // Invalid course, ignore
            OS_REPORT("Unknown play count course: %.*s", length, str);
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
            mWorld = WORLD_e::COUNT;
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

        mpValue = &game.mStockItemCount[static_cast<int>(item)];
        mValueCount = 1;
        return true;
    }

    case Object_e::PLAYER_KEY: {
        switch (hash) {
        case strHash("mario"):
            mPlayer = PLAYER_TYPE_e::MARIO;
            break;
        case strHash("luigi"):
            mPlayer = PLAYER_TYPE_e::LUIGI;
            break;
        case strHash("yellow_toad"):
            mPlayer = PLAYER_TYPE_e::YELLOW_TOAD;
            break;
        case strHash("blue_toad"):
            mPlayer = PLAYER_TYPE_e::BLUE_TOAD;
            break;
        case strHash("toadette"):
            mPlayer = PLAYER_TYPE_e::TOADETTE;
            break;
        case strHash("purple_toadette"):
            mPlayer = PLAYER_TYPE_e::PURPLE_TOADETTE;
            break;
        case strHash("orange_toad"):
            mPlayer = PLAYER_TYPE_e::ORANGE_TOAD;
            break;
        case strHash("black_toad"):
            mPlayer = PLAYER_TYPE_e::BLACK_TOAD;
            break;

        default:
            OS_REPORT("Unknown object\n");
            mFlags |= UNKNOWN_OBJECT;
            return true;
        }

        mFlags |= EXPECT_OBJECT_START;
        mObject = Object_e::PLAYER;
        return true;
    }

    case Object_e::PLAYER: {
        int index = static_cast<int>(mPlayer);
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
            mpValue = &game.mPlayerCreateItem[index];
            break;
        case strHash("powerup"):
            mpValue = &game.mPlayerPowerup[index];
            break;
        case strHash("player"):
            mValueCount = 1;
            mpValue = &game.mPlayerCharacter[0];
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
        mObject = Object_e::ENEMY;
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
        int index = static_cast<int>(mCourse);

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
        mWorld = static_cast<WORLD_e>(worldIndex);
        return true;
    }

    case Object_e::WORLD: {
        int index = static_cast<int>(mWorld);
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

    default:
        return false;
    }
}

bool dMj2dJsonHandler_c::startObject()
{
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

bool dMj2dJsonHandler_c::endObject()
{
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
    } else if (mObject == Object_e::ENEMY) {
        mObject = Object_e::ENEMY_KEY;
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
        mWorld = WORLD_e::COUNT;
        return true;
    } else if (mObject == Object_e::WORLD_KEY) {
        mObject = Object_e::FILE;
        return true;
    } else if (mObject == Object_e::FILE) {
        mObject = Object_e::BASE;
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

bool dMj2dJsonHandler_c::startArray()
{
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

bool dMj2dJsonHandler_c::endArray()
{
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

bool dMj2dJsonHandler_c::writeJSON(std::FILE* f)
{
    dMj2dData_c* data = dNandThread_c::getSaveData();
    dMj2dHeader_c& header = data->mHeader;

    using StringArray = const char* const[];

#define W(field, fmt, ...) std::fprintf(f, #field ":" fmt ",", __VA_ARGS__)
    std::fprintf(f, "{");
    W("version", "\"%d.%d\"", header.mRevision.mMajor, header.mRevision.mMinor);
    W("last_selected_file", "%d", header.mLastSelectedFile);
    std::fprintf(f, "\"play_count_free_mode\":{");
    bool comma = false;
    for (int w = 0; w < WORLD_COUNT; w++) {
        for (int s = 0; s < STAGE_COUNT; s++) {
            u16 v = header.mPlayCountFreeMode[w][s];
            if (v == 0) {
                continue;
            }
            std::fprintf(
              f, "%s\"%d-%s\":%u", comma ? "," : "", w + 1,
              encodeStageName(static_cast<STAGE_e>(s)), v
            );
            comma = true;
        }
    }
    std::fprintf(f, "},\"play_count_coin_battle\":{");
    comma = false;
    for (int w = 0; w < WORLD_COUNT; w++) {
        for (int s = 0; s < STAGE_COUNT; s++) {
            u16 v = header.mPlayCountCoinBattle[w][s];
            if (v == 0) {
                continue;
            }
            std::fprintf(
              f, "%s\"%d-%s\":%u", comma ? "," : "", w + 1,
              encodeStageName(static_cast<STAGE_e>(s)), v
            );
            comma = true;
        }
    }
    std::fprintf(f, "},\"available_worlds\":[");
    int w = 0;
    for (; w < WORLD_COUNT; w++) {
        if (header.mMultiWorldOpenFlag & (1 << w)) {
            std::fprintf(f, "%d", w + 1);
            break;
        }
    }
    for (w++; w < WORLD_COUNT; w++) {
        if (header.mMultiWorldOpenFlag & (1 << w)) {
            std::fprintf(f, ",%d", w + 1);
        }
    }
    std::fprintf(f, "],");

    bool firstSlot = true;
    for (int i = 0; i < SAVE_SLOT_COUNT * 2; i++) {
        dMj2dGame_c& game =
          i < SAVE_SLOT_COUNT ? data->mSaveGames[i] : data->mTempGames[i - SAVE_SLOT_COUNT];

        std::fprintf(
          f, "%s\"%s%d\":{", !firstSlot ? "," : "", i < SAVE_SLOT_COUNT ? "file" : "temp",
          (i % SAVE_SLOT_COUNT) + 1
        );
        firstSlot = false;
        W("version", "\"%d.%d\"", game.mRevision.mMajor, game.mRevision.mMinor);
        std::fprintf(f, "\"completion\":[");
        bool comma = false;
        if (!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::SAVE_EMPTY)) {
            std::fprintf(f, "\"created\"");
            comma = true;
        }
        if (!!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::FINAL_BOSS_BEATEN)) {
            std::fprintf(f, "%s\"final_boss_beaten\"", comma ? "," : "");
            comma = true;
        }
        if (!!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::GOAL_ALL)) {
            std::fprintf(f, "%s\"all_goals\"", comma ? "," : "");
            comma = true;
        }
        if (!!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::COIN_ALL)) {
            std::fprintf(f, "%s\"all_star_coins\"", comma ? "," : "");
            comma = true;
        }
        if (!!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::COIN_ALL_SPECIAL)) {
            std::fprintf(f, "%s\"all_star_coins_w9\"", comma ? "," : "");
            comma = true;
        }
        if (!!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::GAME_COMPLETED)) {
            std::fprintf(f, "%s\"completed\"", comma ? "," : "");
            comma = true;
        }
        if (!!(game.mGameCompletion & dMj2dGame_c::GAME_COMPLETION_e::SUPER_GUIDE_TRIGGERED)) {
            std::fprintf(f, "%s\"super_guide_triggered\"", comma ? "," : "");
            comma = true;
        }
        std::fprintf(f, "],");

        W("score", "%u", game.mScore);
        W("staff_roll_high_score", "%u", game.mStaffRollHighScore);
        W("current_world", "%u", game.mCurrentWorld + 1);
        W("current_sub_world", "%u", game.mCurrentSubWorld);
        W("path_node", "%u", game.mCurrentPathNode);

        std::fprintf(f, "\"stock_item\":{");
        for (int i = 0; i < STOCK_ITEM_COUNT; i++) {
            std::fprintf(
              f, "\"%s\":%u%s",
              StringArray{
                "mushroom", "fire_flower", "propeller_shroom", "ice_flower", "penguin_suit",
                "mini_mushroom", "star"
              }[i],
              game.mStockItemCount[i], i + 1 < STOCK_ITEM_COUNT ? "," : "},"
            );
        }

        std::fprintf(f, "\"hint_movie_bought\":[");
        int m = 0;
        for (; m < HINT_MOVIE_COUNT; m++) {
            if (game.mOtehonMenuOpen[m]) {
                std::fprintf(f, "%d", m);
                break;
            }
        }
        for (m++; m < HINT_MOVIE_COUNT; m++) {
            if (game.mOtehonMenuOpen[m]) {
                std::fprintf(f, ",%d", m);
            }
        }
        std::fprintf(f, "],\"player\":{");
        for (int i = 0; i < PLAYER_COUNT; i++) {
            std::fprintf(
              f, "\"%s\":{",
              StringArray{
                "mario", "luigi", "yellow_toad", "blue_toad", "toadette", "purple_toadette",
                "orange_toad", "black_toad"
              }[i]
            );

            int index = static_cast<int>(game.scDefaultPlayerTypes[i]);
            W("lives", "%d", game.mPlayerLife[index]);
            W("coins", "%d", game.mPlayerCoin[index]);
            W("continues", "%d", game.mPlayerContinue[index]);
            W("equip", "[%s]",
              !!(
                static_cast<PLAYER_CREATE_ITEM_e>(game.mPlayerCreateItem[index]) &
                PLAYER_CREATE_ITEM_e::STAR_POWER
              )
                ? "\"star_power\""
                : "");
            u32 v = u32(game.mPlayerPowerup[index]);
            if (v >= PLAYER_MODE_COUNT) {
                OS_REPORT("SAVE WARNING!! Invalid player powerup for %d: %d\n", index, v);
                v = 0;
            }
            W("powerup", "\"%s\"",
              StringArray{"small", "mushroom", "fire", "mini", "propeller", "penguin", "ice"}[v]);
            int player = PLAYER_COUNT;
            for (int j = 0; j < PLAYER_COUNT; j++) {
                if (static_cast<PLAYER_TYPE_e>(game.mPlayerCharacter[j]) ==
                    game.scDefaultPlayerTypes[i]) {
                    player = j;
                    break;
                }
            }
            std::fprintf(
              f, "\"player\":%d}%s", player, i + 1 < PLAYER_COUNT ? "," : "},\"world\":{"
            );
        }

        for (int i = 0; i < WORLD_COUNT; i++) {
            std::fprintf(f, "\"%d\":{", i + 1);
            W("open", "%s",
              !!(game.mWorldCompletion[i] & dMj2dGame_c::WORLD_COMPLETION_e::WORLD_UNLOCKED)
                ? "true"
                : "false");
            W("toad_rescue_course", "\"%s\"", encodeStageName(game.mKinopioCourseNo[i]));
            u32 kinokoType = static_cast<u32>(game.mStartKinokoType[i]);
            if (kinokoType >= static_cast<u32>(dMj2dGame_c::START_KINOKO_KIND_e::COUNT)) {
                OS_REPORT(
                  "SAVE WARNING!! Invalid start toad house type for w%d: %d\n", i, kinokoType
                );
                kinokoType = 0;
            }
            W("start_minigame_type", "\"%s\"",
              StringArray{
                "none", "yellow", "red", "green", "yellow_r", "red_r", "green_r"
              }[kinokoType]);

            std::fprintf(f, "\"ambush_enemy\":{");
            for (int e = 0; e < AMBUSH_ENEMY_COUNT; e++) {
                std::fprintf(f, "\"%d\":{", e);
                W("revival_count", "%u", game.mEnemyRevivalCount[i][e]);
                W("sub_world", "%d", game.mEnemySceneNo[i][e]);
                W("path_node", "%d", game.mEnemyPosIndex[i][e]);
                u32 walkDir = static_cast<u32>(game.mEnemyWalkDir[i][e]);
                if (walkDir >= 3) {
                    OS_REPORT(
                      "SAVE WARNING!! Invalid enemy walk direction for w%de%d: %d\n", i, e, walkDir
                    );
                    walkDir = 2;
                }
                std::fprintf(
                  f, "\"walk_direction\":\"%s\"}%s",
                  StringArray{"normal", "reverse", "initial"}[walkDir],
                  e + 1 < AMBUSH_ENEMY_COUNT ? "," : "},\"course\":{"
                );
            }

            bool comma = false;
            for (int c = 0; c < STAGE_COUNT; c++) {
                if (!game.mCourseCompletion[i][c] && game.mDeathCount[i][c] == 0 &&
                    ((i != 2 && c != 3) || game.mDeathCountSwitch == 0)) {
                    continue;
                }

                std::fprintf(
                  f, "%s\"%s\":{\"goal\":[", comma ? "," : "",
                  encodeStageName(static_cast<STAGE_e>(c))
                );

                comma = true;
                bool goalcomma = false;

                if (!!(
                      game.mCourseCompletion[i][c] & dMj2dGame_c::COURSE_COMPLETION_e::GOAL_NORMAL
                    )) {
                    std::fprintf(f, "\"normal\"");
                    goalcomma = true;
                }
                if (!!(
                      game.mCourseCompletion[i][c] & dMj2dGame_c::COURSE_COMPLETION_e::GOAL_SECRET
                    )) {
                    std::fprintf(f, "%s\"secret\"", goalcomma ? "," : "");
                    goalcomma = true;
                }
                if (!!(
                      game.mCourseCompletion[i][c] &
                      dMj2dGame_c::COURSE_COMPLETION_e::SUPER_GUIDE_GOAL_NORMAL
                    )) {
                    std::fprintf(f, "%s\"super_guide_normal\"", goalcomma ? "," : "");
                    goalcomma = true;
                }
                if (!!(
                      game.mCourseCompletion[i][c] &
                      dMj2dGame_c::COURSE_COMPLETION_e::SUPER_GUIDE_GOAL_SECRET
                    )) {
                    std::fprintf(f, "%s\"super_guide_secret\"", goalcomma ? "," : "");
                }

                std::fprintf(f, "],\"star_coin\":[");
                goalcomma = false;
                if (!!(
                      game.mCourseCompletion[i][c] &
                      dMj2dGame_c::COURSE_COMPLETION_e::COIN1_COLLECTED
                    )) {
                    std::fprintf(f, "1");
                    goalcomma = true;
                }
                if (!!(
                      game.mCourseCompletion[i][c] &
                      dMj2dGame_c::COURSE_COMPLETION_e::COIN2_COLLECTED
                    )) {
                    std::fprintf(f, "%s2", goalcomma ? "," : "");
                    goalcomma = true;
                }
                if (!!(
                      game.mCourseCompletion[i][c] &
                      dMj2dGame_c::COURSE_COMPLETION_e::COIN3_COLLECTED
                    )) {
                    std::fprintf(f, "%s3", goalcomma ? "," : "");
                }
                std::fprintf(f, "],\"deaths\":%d", game.mDeathCount[i][c]);

                if (i == 2 && c == 3) {
                    std::fprintf(f, ",\"deaths_switch\":%d", game.mDeathCountSwitch);
                }

                std::fprintf(f, "}");
            }

            std::fprintf(f, "}}%s", i + 1 < WORLD_COUNT ? "," : "}}");
        }
    }
    std::fprintf(f, "}");

    return true;
}
