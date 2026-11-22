// d_mj2d_json.cpp
// nsmbw-project

#include "d_mj2d_json.h"

#include "c_json.h"
#include "d_mj2d_data.h"
#include "d_mj2d_game.h"
#include "d_nand_thread.h"
#include <cstdlib>
#include <cstring>
#include <revolution/os/OSContext.h>
#include <revolution/os/OSError.h>
#include <slu/array.hpp>
#include <slu/concepts.hpp>
#include <slu/djb2a.hpp>
#include <slu/identity.hpp>
#include <slu/pointer.hpp>
#include <slu/to_string.hpp>
#include <string_view>
#include <utility>

std::optional<int> dMj2dJson_c::decodeNumber(
    const std::string_view& str, bool allowNegative
) {
    int  number   = 0;
    bool negative = false;
    for (char c : str) {
        if (std::exchange(allowNegative, false) && c == '-') {
            negative = true;
            continue;
        }
        if (c < '0' || c > '9') {
            return std::nullopt;
        }
        number = (number * 10) + (c - '0');
    }
    return negative ? -number : number;
}

template <>
WORLD_e dMj2dJson_c::Type_c<WORLD_e>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
) {
    std::optional<int> number = decodeNumber(t.string, false);
    r.userError(!number || !isValidWorldNo(*number - 1));
    return static_cast<WORLD_e>(*number - 1);
}

template <>
STAGE_e dMj2dJson_c::Type_c<STAGE_e>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
) {
    if (t.is_null() || t.string == "none") {
        return STAGE_e::COUNT;
    }
    t.number--;
    std::optional<STAGE_e> value = dMj2dJson_c::readEnum<STAGE_e>(t);
    r.userError(!value || !isValidStageNo(+*value));
    return *value;
}

const char* dMj2dJson_c::encodeStageNo(
    StageNo_s stageNo, const std::span<char>& buffer
) {
    std::snprintf(
        buffer.data(), buffer.size(), "%u-%s", +(+stageNo.world) + 1, toString(stageNo.stage)
    );
    return buffer.data();
}

StageNo_s dMj2dJson_c::decodeStageNo(
    const std::string_view& str
) {
    std::size_t dashIndex = std::find(str.begin(), str.end(), '-') - str.begin();

    if (dashIndex == str.size()) {
        // Invalid stage; ignore
        DEBUG_REPORT("E: Invalid stage: %.*s\n", static_cast<int>(str.size()), str.data());
        return StageNo_s::invalid();
    }

    std::optional<int> world = decodeNumber(str.substr(0, dashIndex), false);

    if (!world || !isValidWorldNo(*world - 1)) {
        return StageNo_s::invalid();
    }

    std::string_view strStage = str.substr(dashIndex + 1);
    if (std::optional<STAGE_e> stage = fromString<STAGE_e>(strStage)) {
        return {
            .world = static_cast<WORLD_e>(*world - 1),
            .stage = *stage,
        };
    }

    // Try to decode the stage as a number
    std::optional<int> stage = decodeNumber(str.substr(dashIndex + 1), false);
    if (!stage || !isValidStageNo(*stage - 1)) {
        DEBUG_REPORT("E: Invalid stage number: %.*s\n", static_cast<int>(str.size()), str.data());
        return StageNo_s::invalid();
    }
    return {
        .world = static_cast<WORLD_e>(*world - 1),
        .stage = static_cast<STAGE_e>(*stage - 1),
    };
}

template <>
StageNo_s dMj2dJson_c::Type_c<StageNo_s>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
) {
    r.userError(!t.is_string());
    StageNo_s stage = decodeStageNo(t);
    r.userError(!stage.isValid());
    return stage;
}

template <>
dMj2dGame_c::Revision_s dMj2dJson_c::Type_c<dMj2dGame_c::Revision_s>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
) {
    r.userError(!t.is_string());
    auto&       str      = t.string;

    std::size_t dotIndex = std::find(str.begin(), str.end(), '.') - str.begin();
    r.userError(dotIndex == str.size());

    std::optional<int> major = decodeNumber(str.substr(0, dotIndex), false);
    std::optional<int> minor = decodeNumber(str.substr(dotIndex + 1), false);
    r.userError(!major || !minor);

    return {static_cast<u8>(*major), static_cast<u8>(*minor)};
}

void dMj2dJson_c::unmarshalArray(
    cJson::Reader_c& r, const cJson::token_s& startT, void* ptr, std::size_t n, std::size_t vs,
    UnmarshalFunc* func
) {
    r.userError(!startT.is_array_start());

    while (cJson::token_s t = r.next()) {
        if (t.is_array_end()) {
            return;
        }
        if (n-- == 0) {
            DEBUG_REPORT("E: Array overflow\n");
            r.userError();
        }
        (*func)(r, t, ptr);
        ptr = slu::pointer::offset<void>(ptr, vs);
    }

    r.userError();
}

bool dMj2dJson_c::readJSON(
    cJson::Reader_c& r
) {
    OSContext context;
    if (OSSaveContext(&context) != 0) {
        OSLoadFPUContext(&context);
        DEBUG_REPORT("Terminating JSON reader due to errors\n");
        return false;
    }
    OSSaveFPUContext(&context);

    r.setUserErrorCallback(
        [](void* userData) {
            auto* context = static_cast<OSContext*>(userData);
            OSLoadContext(context);
            std::unreachable();
        },
        &context
    );

    static constinit dMj2dJson_c::Field_c cRootFields[] = {
        {"version", slu::value_identity<&dMj2dHeader_c::mRevision>{}},
        {"last_selected_file", slu::value_identity<&dMj2dHeader_c::mLastSelectedFile>{}},
        {"play_count_free_mode", slu::value_identity<&dMj2dHeader_c::mPlayCountFreeMode>{},
         unmarshalPlayCounts},
        {"play_count_coin_battle", slu::value_identity<&dMj2dHeader_c::mPlayCountCoinBattle>{},
         unmarshalPlayCounts},
        {"available_worlds", slu::value_identity<&dMj2dHeader_c::mMultiWorldOpenFlag>{},
         unmarshalAvailableWorlds}
    };

    dMj2dData_c* data = dNandThread_c::getSaveData();
    r.startObject();

    while (cJson::token_s key = r.key<pass>()) {
        bool file = key.string.starts_with("file");
        bool temp = !file && key.string.starts_with("temp");
        if (!file && !temp) {
            visitFields(r, cRootFields, key.string, &data->mHeader);
            continue;
        }

        std::optional<int> number = decodeNumber(key.string.substr(4), false);
        if (!number || !isValidSaveSlotNo(*number - 1)) {
            return DEBUG_REPORT("E: Invalid file number\n"), false;
        }

        unmarshalFileData(r, temp ? data->mTempGames[*number - 1] : data->mSaveGames[*number - 1]);
    }
    r.endObject();

    OS_REPORT("JSON file loaded with no errors\n");

    return true;
}

void dMj2dJson_c::visitFields(
    cJson::Reader_c& r, std::span<const Field_c> fields, const std::string_view& key,
    void* getterObj
) {
    const u32 hash = slu::djb2a(key.data(), key.length());
    for (const Field_c& field : fields) {
        if (field.hash != hash || field.name != key) {
            continue;
        }

        cJson::token_s t = r.next();
        r.userError(!t);
        if (t.is_null()) {
            // Skip this value
            return;
        }

        field.func(
            r, t,
            (field.getter && field.ptr.getter != nullptr) ? field.ptr.getter(getterObj)
                                                          : field.ptr.ptr
        );
        return;
    }

    DEBUG_REPORT("E: Unknown key \"%.*s\"\n", static_cast<int>(key.size()), key.data());
    r.userError();
}

bool dMj2dJson_c::writeJSON(
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

bool dMj2dJson_c::marshalPlayCounts(
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

            char temp[64];
            if (!w.key(
                    encodeStageNo({static_cast<WORLD_e>(world), static_cast<STAGE_e>(stage)}, temp)
                ) ||
                !w.number(static_cast<s64>(v))) {
                return false;
            }
        }
    }
    return w.endObject();
}

void dMj2dJson_c::unmarshalPlayCounts(
    cJson::Reader_c& r, cJson::token_s& t, void* ptr
) {
    auto& counts = *static_cast<u16(*)[WORLD_COUNT][STAGE_COUNT]>(ptr);

    r.userError(!t.is_object_start());
    while (cJson::token_s key = r.key<pass>()) {
        StageNo_s stage = decodeStageNo(key.string);
        r.userError(!stage.isValid());
        counts[+stage.world][+stage.stage] = r.number().number;
    }
    r.endObject();
}

bool dMj2dJson_c::marshalAvailableWorlds(
    cJson::Writer_c& w, const dMj2dHeader_c& header
) {
    int world = 0;
    for (; world < WORLD_COUNT; world++) {
        if (header.mMultiWorldOpenFlag & (1 << world)) {
            if (!w.number(world + 1)) {
                return false;
            }
        }
    }
    return true;
}

void dMj2dJson_c::unmarshalAvailableWorlds(
    cJson::Reader_c& r, cJson::token_s& t, void* ptr
) {
    u16 flag = 0;

    r.userError(!t.is_array_start());
    while (auto value = r.number<pass>()) {
        r.userError(!isValidWorldNo(value.number - 1));
        flag |= (1 << (value.number - 1));
    }
    r.endArray();

    *static_cast<u16*>(ptr) = flag;
}

bool dMj2dJson_c::marshalFileData(
    cJson::Writer_c& w, const dMj2dData_c* data
) {
    dMj2dGame_c cDefaultGame{};
    cDefaultGame.initialize();

    bool result = true;
    for (int slot = 0; slot < SAVE_SLOT_COUNT * 2 && result; slot++) {
        const dMj2dGame_c& g      = slot < SAVE_SLOT_COUNT ? data->mSaveGames[slot]
                                                           : data->mTempGames[slot - SAVE_SLOT_COUNT];
        const char*        format = slot < SAVE_SLOT_COUNT ? "file%d" : "temp%d";

        using enum GAME_COMPLETION_e;
        using enum STOCK_ITEM_e;

        if (std::memcmp(&g, &cDefaultGame, sizeof(dMj2dGame_c)) == 0) {
            continue;
        }

        char temp[64];

        // clang-format off
        result &= w.keyFmt(format, (slot % SAVE_SLOT_COUNT) + 1) && w.startObject() && (
            w.fieldFmt("version", "%d.%d", g.mRevision.mMajor, g.mRevision.mMinor) &&
            w.key("completion") && w.startArray() && (
                (g.isFlag(SAVE_EMPTY)             || w.string("created"))           &&
                (!g.isFlag(FINAL_BOSS_BEATEN)     || w.string("final_boss_beaten")) &&
                (!g.isFlag(GOAL_ALL)              || w.string("all_goals"))         &&
                (!g.isFlag(COIN_ALL)              || w.string("all_star_coins"))    &&
                (!g.isFlag(COIN_ALL_SPECIAL)      || w.string("all_star_coins_w9")) &&
                (!g.isFlag(GAME_COMPLETED)        || w.string("completed"))         &&
                (!g.isFlag(SUPER_GUIDE_TRIGGERED) || w.string("super_guide_triggered"))
            ) && w.endArray() &&
            w.field("score",                 g.mScore)              &&
            w.field("staff_roll_high_score", g.mStaffRollHighScore) &&
            w.field("current_world",         +g.mCurrentWorld + 1)  &&
            w.field("current_sub_world",     g.mCurrentSubWorld)    &&
            w.field("path_node",             g.mCurrentPathNode)    &&
            (g.mPipeRandomizerMode == PIPE_RANDOMIZER_MODE_e::DISABLED || (
                w.field("pipe_randomizer_mode", toString(g.mPipeRandomizerMode)) &&
                w.field("pipe_randomizer_seed", static_cast<s32>(g.mPipeRandomizerSeed)))
            ) &&
            w.key("stock_item") && w.startObject() && (
                marshalStockItem(w, g)
            ) && w.endObject() &&
            (g.mCheckpoint.index < 0 || (w.key("checkpoint") && w.startObject() && (
                w.field("index",    g.mCheckpoint.index)                      &&
                w.field("stage",    encodeStageNo(g.mCheckpoint.stage, temp)) &&
                w.field("area",     g.mCheckpoint.area + 1)                   &&
                w.field("entrance", g.mCheckpoint.entrance)                   &&
                w.key("flag") && w.startArray() && (
                    marshalPlayerType(w, g.mCheckpoint.flag[0]) &&
                    marshalPlayerType(w, g.mCheckpoint.flag[1], false)
                ) && w.endArray() &&
                w.key("coin") && w.startArray() && (
                    marshalPlayerType(w, g.mCheckpoint.coin[0]) &&
                    marshalPlayerType(w, g.mCheckpoint.coin[1]) &&
                    marshalPlayerType(w, g.mCheckpoint.coin[2])
                ) && w.endArray()) && w.endObject())) &&
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

void dMj2dJson_c::unmarshalFileData(
    cJson::Reader_c& r, dMj2dGame_c& g
) {
    static constinit dMj2dJson_c::Field_c cGameFields[] = {
#define X(string, member, ...) \
    {string, slu::value_identity<&dMj2dGame_c::member>{} __VA_OPT__(, ) __VA_ARGS__}
        X("version", mRevision),
        X("completion", mGameCompletion),
        X("score", mScore),
        X("staff_roll_high_score", mStaffRollHighScore),
        X("current_world", mCurrentWorld),
        X("current_sub_world", mCurrentSubWorld),
        X("path_node", mCurrentPathNode),
        X("pipe_randomizer_mode", mPipeRandomizerMode),
        X("pipe_randomizer_seed", mPipeRandomizerSeed),
        X("stock_item", mStockItemCount, unmarshalStockItem),
        X("checkpoint", mCheckpoint, unmarshalCheckpoint),
        X("hint_movie_bought", mOtehonMenuOpen),
#undef X
    };

    r.startObject();
    while (auto key = r.key<pass>()) {
        if (key.string == "player") {
            unmarshalPlayerData(r, g);
        } else if (key.string == "world") {
            unmarshalWorldData(r, g);
        } else {
            visitFields(r, cGameFields, key.string, &g);
        }
    }
    r.endObject();
}

template <>
dMj2dGame_c::GAME_COMPLETION_e dMj2dJson_c::Type_c<dMj2dGame_c::GAME_COMPLETION_e>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
) {
    auto flag = GAME_COMPLETION_e::SAVE_EMPTY;

    if (!t.is_array_start()) {
        r.userError();
    }
    while (auto value = r.anyValue<pass>()) {
        if (auto e = readEnum<GAME_COMPLETION_e>(value)) {
            if (*e == GAME_COMPLETION_e::SAVE_EMPTY) {
                flag &= ~GAME_COMPLETION_e::SAVE_EMPTY;
            } else {
                flag |= *e;
            }
        } else if (value.string == "super_gude_triggered") {
            // Typo from previous versions
            flag |= GAME_COMPLETION_e::SUPER_GUIDE_TRIGGERED;
        } else {
            DEBUG_REPORT("W: Unknown game completion value\n");
        }
    }
    r.endArray();

    return flag;
}

bool dMj2dJson_c::marshalStockItem(
    cJson::Writer_c& w, const dMj2dGame_c& g
) {
    std::underlying_type_t<STOCK_ITEM_e> i = 0;
    while (const char* name = toString(static_cast<STOCK_ITEM_e>(i++))) {
        if (auto value = g.mStockItemCount[i]; value != 0) {
            if (!w.field(name, value)) {
                return false;
            }
        }
    }
    return true;
}

void dMj2dJson_c::unmarshalStockItem(
    cJson::Reader_c& r, cJson::token_s& t, void* ptr
) {
    u8(&counts)[STOCK_ITEM_COUNT] = *static_cast<u8(*)[STOCK_ITEM_COUNT]>(ptr);
    r.userError(!t.is_object_start());
    while (cJson::token_s key = r.key<pass>()) {
        std::optional<STOCK_ITEM_e> item = fromString<STOCK_ITEM_e>(key);
        r.userError(!item);
        counts[+*item] = r.number().number;
    }
    r.endObject();
}

void dMj2dJson_c::unmarshalCheckpoint(
    cJson::Reader_c& r, cJson::token_s& t, void* ptr
) {
    static constinit dMj2dJson_c::Field_c cCheckpointFields[] = {
#define X(string, member, ...) \
    {string, slu::value_identity<&dMj2dGame_c::Cyuukan_s::member>{} __VA_OPT__(, ) __VA_ARGS__}
        X("index", index),       X("stage", stage), X("area", area),
        X("entrance", entrance), X("flag", flag),   X("coin", coin),
#undef X
    };

    dMj2dGame_c::Cyuukan_s& checkpoint = *static_cast<dMj2dGame_c::Cyuukan_s*>(ptr);
    checkpoint.area                    = 1;

    r.userError(!t.is_object_start());
    while (cJson::token_s key = r.key<pass>()) {
        visitFields(r, cCheckpointFields, key, &checkpoint);
    }
    r.endObject();

    checkpoint.area--;
}

bool dMj2dJson_c::marshalPlayerData(
    cJson::Writer_c& w, const dMj2dGame_c& g
) {
    for (auto plrType : scDefaultPlayerTypes) {
        if (!marshalPlayerData(w, g, plrType)) {
            return false;
        }
    }
    return true;
}

bool dMj2dJson_c::marshalPlayerData(
    cJson::Writer_c& w, const dMj2dGame_c& g, PLAYER_TYPE_e player
) {
    if (player < PLAYER_TYPE_e::MARIO || player >= PLAYER_TYPE_e::COUNT) {
        return false;
    }

    using enum PLAYER_CREATE_ITEM_e;

    Player_s plr = g.mPlayer[player];

    // clang-format off
    return w.key(toString(player)) && w.startObject() && (
        w.field("lives",     plr.lives)     &&
        w.field("coins",     plr.coins)     &&
        w.field("continues", plr.continues) &&
        w.key("equip") && w.startArray() && (
            (!(plr.equip & STAR_POWER) || w.string("star_power"))
        ) && w.endArray() &&
        w.field("powerup",   toString(plr.powerup)) &&
        w.field("player", plr.player)
    ) && w.endObject();
    // clang-format on
}

void dMj2dJson_c::unmarshalPlayerData(
    cJson::Reader_c& r, dMj2dGame_c& g
) {
    static constinit dMj2dJson_c::Field_c cPlayerFields[] = {
#define X(string, member, ...) \
    {string, slu::value_identity<&dMj2dGame_c::Player_s::member>{} __VA_OPT__(, ) __VA_ARGS__}
        X("lives", lives), X("coins", coins),     X("continues", continues),
        X("equip", equip), X("powerup", powerup), X("player", player),
#undef X
    };

    r.startObject();
    while (auto key = r.key<pass>()) {
        std::optional<PLAYER_TYPE_e> type = readEnum<PLAYER_TYPE_e>(key);
        if (!type) {
            DEBUG_REPORT(
                "E: Unknown player type \"%.*s\"\n", static_cast<int>(key.string.size()),
                key.string.data()
            );
            r.userError();
        }

        r.startObject();
        while (auto key = r.key<pass>()) {
            visitFields(r, cPlayerFields, key.string, &g.mPlayer[*type]);
        }
        r.endObject();
    }
    r.endObject();
}

bool dMj2dJson_c::marshalWorldData(
    cJson::Writer_c& w, const dMj2dGame_c& g
) {
    bool result = true;
    for (int world = 0; world < WORLD_COUNT && result; world++) {
        // clang-format off
        const bool open = !!(g.mWorldCompletion[world] & WORLD_COMPLETION_e::WORLD_UNLOCKED);
        result = w.keyFmt("%d", world + 1) && w.startObject() && (
            w.field("open", open) &&
            w.field("toad_rescue_course",  toString(g.mKinopioCourseNo[world])) &&
            w.field("start_minigame_type", toString(g.mStartKinokoType[world])) &&
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

void dMj2dJson_c::unmarshalWorldData(
    cJson::Reader_c& r, dMj2dGame_c& g
) {
    r.startObject();
    while (auto key = r.key<pass>()) {
        WORLD_e world = Type_c<WORLD_e>::unmarshal(r, key);

        r.startObject();
        while (auto key = r.key<pass>()) {
            if (key == "open") {
                int number = r.anyNumber().number;
                g.mWorldCompletion[+world] &= WORLD_COMPLETION_e::WORLD_UNLOCKED;
                if (number) {
                    g.mWorldCompletion[+world] |= WORLD_COMPLETION_e::WORLD_UNLOCKED;
                }
            } else if (key == "toad_rescue_course") {
                auto value = r.anyValue();
                Type_c<STAGE_e>::unmarshal(r, value, &g.mKinopioCourseNo);
            } else if (key == "start_minigame_type") {
                auto value = r.anyValue();
                Type_c<START_KINOKO_KIND_e>::unmarshal(r, value, &g.mKinopioCourseNo);
            } else if (key == "ambush_enemy") {
                static constinit dMj2dJson_c::Field_c cAmbushEnemyFields[] = {
                    {"revival_count", slu::value_identity<&AmbushEnemy_s::revival_count>{}},
                    {"sub_world", slu::value_identity<&AmbushEnemy_s::sub_world>{}},
                    {"path_node", slu::value_identity<&AmbushEnemy_s::path_node>{}},
                    {"walk_direction", slu::value_identity<&AmbushEnemy_s::walk_direction>{}},
                };
                r.startObject();
                while (auto key = r.key<pass>()) {
                    std::optional<int> number = decodeNumber(key);
                    r.userError(!number || !isValidAmbushEnemyNo(*number));
                    int           enemy = *number;
                    AmbushEnemy_s ambushEnemy{};

                    r.startObject();
                    while (auto key = r.key<pass>()) {
                        visitFields(r, cAmbushEnemyFields, key, &ambushEnemy);
                    }
                    r.endObject();

                    ambushEnemy.toGame(g, +world, enemy);
                }
                r.endObject();
            } else if (key == "course") {
                r.startObject();
                while (auto key = r.key<pass>()) {
                    STAGE_e     stage     = Type_c<STAGE_e>::unmarshal(r, key);
                    StageData_s stageData = {};

                    r.startObject();
                    while (auto key = r.key<pass>()) {
                        if (key == "goal") {
                            constexpr std::pair<const char*, bool StageData_s::*>
                                cStageGoalFields[] = {
                                    {"normal", &StageData_s::goal_normal},
                                    {"secret", &StageData_s::goal_secret},
                                    {"super_guide_normal", &StageData_s::goal_super_guide_normal},
                                    {"super_guide_secret", &StageData_s::goal_super_guide_secret},
                                };

                            r.startArray();
                            while (auto flag = r.string<pass>()) {
                                if (!unmarshalFlag(r, stageData, flag, cStageGoalFields)) {
                                    DEBUG_REPORT(
                                        "W: Unknown goal type: %.*s\n",
                                        static_cast<int>(flag.string.size()), flag.string.data()
                                    );
                                }
                            }
                            r.endArray();
                        } else if (key == "star_coin") {
                            r.startArray();
                            while (auto num = r.number<pass>()) {
                                if (slu::valid_index(num.number - 1, stageData.star_coin)) {
                                    stageData.star_coin[num.number - 1] = true;
                                }
                            }
                            r.endArray();
                        } else if (key == "deaths") {
                            g.mDeathCount[+world][+stage] = r.number().number;
                        } else if (key == "deaths_switch") {
                            s64 deaths = r.number().number;
                            if (StageNo_s{world, stage}.isW3SwitchStage()) {
                                g.mDeathCountSwitch = deaths;
                            }
                        }
                    }
                    r.endObject();

                    stageData.toGame(g, {world, stage});
                }
                r.endObject();
            }
        }
        r.endObject();
    }
    r.endObject();
}

bool dMj2dJson_c::marshalWorldAmbushEnemyData(
    cJson::Writer_c& w, const dMj2dGame_c& g, int world
) {
    bool result = true;
    for (int enemy = 0; enemy < AMBUSH_ENEMY_COUNT && result; enemy++) {
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
            w.field("walk_direction", toString(entry.walk_direction))
        ) && w.endObject();
        // clang-format on
    }
    return result;
}

bool dMj2dJson_c::marshalWorldCourseData(
    cJson::Writer_c& w, const dMj2dGame_c& g, int world
) {
    bool result = true;
    for (int stage = 0; stage < STAGE_COUNT && result; stage++) {
        StageNo_s             stageNo = {static_cast<WORLD_e>(world), static_cast<STAGE_e>(stage)};
        StageData_s           entry   = StageData_s::fromGame(g, stageNo);

        constexpr StageData_s stageDefault       = {};
        constexpr StageData_s stageRescueDefault = {
            .goal_normal = true,
            .goal_secret = true,
        };
        if ((stage != +STAGE_e::RESCUE && entry == stageDefault) ||
            (stage == +STAGE_e::RESCUE && entry == stageRescueDefault)) {
            continue;
        }

        // clang-format off
        result &= w.key(toString(static_cast<STAGE_e>(stage))) && w.startObject() && (
            w.key("goal") && w.startArray() && (
                (!entry.goal_normal             || w.string("normal"))            &&
                (!entry.goal_secret             || w.string("secret"))            &&
                (!entry.goal_super_guide_normal || w.string("super_guide_normal")) &&
                (!entry.goal_super_guide_secret || w.string("super_guide_secret"))
            ) && w.endArray() &&
            w.key("star_coin") && w.startArray() && (
                (!entry.star_coin[0] || w.number(1ll)) &&
                (!entry.star_coin[1] || w.number(2ll)) &&
                (!entry.star_coin[2] || w.number(3ll))
            ) && w.endArray() &&
            w.field("deaths", entry.deaths) &&
            (!stageNo.isW3SwitchStage() || w.field("deaths_switch", entry.deaths_switch))
        ) && w.endObject();
        // clang-format on
    }
    return result;
}

bool dMj2dJson_c::marshalPlayerType(
    cJson::Writer_c& w, PLAYER_TYPE_e type, bool null
) {
    if (type < PLAYER_TYPE_e::MARIO || type >= PLAYER_TYPE_e::COUNT) {
        return !null || w.null();
    }
    return w.string(toString(type));
}

#undef ENSURE
