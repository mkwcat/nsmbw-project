#pragma once

#include "c_json.h"
#include "d_mj2d_data.h"
#include "d_mj2d_game.h"
#include "d_mj2d_header.h"
#include <bit>
#include <cstdio>
#include <memory>
#include <optional>
#include <revolution/os/OSError.h>
#include <slu/concepts.hpp>
#include <slu/djb2a.hpp>
#include <slu/identity.hpp>
#include <slu/member_pointer.hpp>
#include <span>
#include <type_traits>

class dMj2dJson_c final : dMj2dGame_c {
public:
    dMj2dJson_c() = delete;

    using enum cJson::ErrorPolicy_e;

public:
    // Static Methods
    // ^^^^^^

    static bool readJSON(cJson::Reader_c& r);
    static bool writeJSON(std::FILE* f);

private:
    // Internal Static Methods
    // ^^^^^^

    static bool marshalPlayerType(cJson::Writer_c& w, PLAYER_TYPE_e type, bool null = true);

    static bool marshalStockItem(cJson::Writer_c& w, const dMj2dGame_c& g);
    static void unmarshalStockItem(cJson::Reader_c& r, cJson::token_s& t, void* ptr);

    static bool
    marshalPlayCounts(cJson::Writer_c& w, const u16 (&counts)[WORLD_COUNT][STAGE_COUNT]);
    static void unmarshalPlayCounts(cJson::Reader_c& r, cJson::token_s& t, void* ptr);

    static bool marshalAvailableWorlds(cJson::Writer_c& w, const dMj2dHeader_c& header);
    static void unmarshalAvailableWorlds(cJson::Reader_c& r, cJson::token_s& t, void* ptr);

    static bool marshalFileData(cJson::Writer_c& w, const dMj2dData_c* data);
    static void unmarshalFileData(cJson::Reader_c& r, dMj2dGame_c& g);

    static void unmarshalCheckpoint(cJson::Reader_c& r, cJson::token_s& t, void* ptr);

    static bool marshalPlayerData(cJson::Writer_c& w, const dMj2dGame_c& g, PLAYER_TYPE_e player);
    static bool marshalPlayerData(cJson::Writer_c& w, const dMj2dGame_c& g);
    static void unmarshalPlayerData(cJson::Reader_c& r, dMj2dGame_c& g);

    static bool marshalWorldData(cJson::Writer_c& w, const dMj2dGame_c& g);
    static void unmarshalWorldData(cJson::Reader_c& r, dMj2dGame_c& g);

    static bool marshalWorldAmbushEnemyData(cJson::Writer_c& w, const dMj2dGame_c& g, int world);
    static bool marshalWorldCourseData(cJson::Writer_c& w, const dMj2dGame_c& g, int world);

    template <std::size_t N>
    static bool marshalBitIndices(cJson::Writer_c& w, const std::bitset<N>& bits);

public:
    // Inline Static Methods
    // ^^^^^^

    static constexpr bool isValidSaveSlotNo(
        unsigned no
    ) {
        return no < SAVE_SLOT_COUNT;
    }

    static constexpr bool isValidWorldNo(
        unsigned no
    ) {
        return no < WORLD_COUNT;
    }

    static constexpr bool isValidStageNo(
        unsigned no
    ) {
        return no < STAGE_COUNT;
    }

    static constexpr bool isValidStockItemNo(
        unsigned no
    ) {
        return no < STOCK_ITEM_COUNT;
    }

    static constexpr bool isValidPlayerTypeNo(
        unsigned no
    ) {
        return no < CHARACTER_COUNT;
    }

    static constexpr bool isValidPlayerModeNo(
        unsigned no
    ) {
        return no < PLAYER_MODE_COUNT;
    }

    static constexpr bool isValidAmbushEnemyNo(
        unsigned no
    ) {
        return no < AMBUSH_ENEMY_COUNT;
    }

public:
    // JSON Game Structure Types
    // ^^^^^^

    struct StageData_s {
        constexpr bool operator==(const StageData_s&) const = default;

        bool goal_normal                                    = false;
        bool goal_secret                                    = false;
        bool goal_super_guide_normal                        = false;
        bool goal_super_guide_secret                        = false;
        bool star_coin[3]                                   = {false, false, false};
        u8   deaths                                         = 0;
        u8   deaths_switch                                  = 0;

        static StageData_s fromGame(
            const dMj2dGame_c& g, StageNo_s stage
        ) {
            using enum COURSE_COMPLETION_e;
            auto completion = g.mCourseCompletion[+stage.world][+stage.stage];

            return {
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
                .deaths        = g.mDeathCount[+stage.world][+stage.stage],
                .deaths_switch = stage.isW3SwitchStage() ? g.mDeathCountSwitch : static_cast<u8>(0),
            };
        }

        void toGame(
            dMj2dGame_c& g, StageNo_s stage
        ) const {
            using enum COURSE_COMPLETION_e;
            COURSE_COMPLETION_e  none       = {};
            COURSE_COMPLETION_e& completion = g.mCourseCompletion[+stage.world][+stage.stage] = {};

            completion |= goal_normal ? GOAL_NORMAL : none;
            completion |= goal_secret ? GOAL_SECRET : none;
            completion |= goal_super_guide_normal ? SUPER_GUIDE_GOAL_NORMAL : none;
            completion |= goal_super_guide_secret ? SUPER_GUIDE_GOAL_SECRET : none;
            completion |= star_coin[0] ? COIN1_COLLECTED : none;
            completion |= star_coin[1] ? COIN2_COLLECTED : none;
            completion |= star_coin[2] ? COIN3_COLLECTED : none;

            g.mDeathCount[+stage.world][+stage.stage] = deaths;
            if (stage.isW3SwitchStage()) {
                g.mDeathCountSwitch = deaths_switch;
            }
        }
    };

    struct AmbushEnemy_s {
        constexpr bool operator==(const AmbushEnemy_s&) const = default;

        u8               revival_count                        = 0;
        u8               sub_world                            = 0;
        s8               path_node                            = -1;
        PATH_DIRECTION_e walk_direction                       = PATH_DIRECTION_e::INITIAL;

        static AmbushEnemy_s fromGame(
            const dMj2dGame_c& g, int world, int num
        ) {
            return {
                .revival_count  = g.mEnemyRevivalCount[world][num],
                .sub_world      = g.mEnemySceneNo[world][num],
                .path_node      = g.mEnemyPosIndex[world][num],
                .walk_direction = g.mEnemyWalkDir[world][num],
            };
        }

        void toGame(
            dMj2dGame_c& g, int world, int num
        ) const {
            g.mEnemyRevivalCount[world][num] = revival_count;
            g.mEnemySceneNo[world][num]      = sub_world;
            g.mEnemyPosIndex[world][num]     = path_node;
            g.mEnemyWalkDir[world][num]      = walk_direction;
        }
    };

public:
    // JSON type marshal/unmarshal
    // ^^^^^^

    template <class T>
    struct Type_c;

    struct Field_c;

    template <class Struct>
    struct MemberField_c;

    using UnmarshalFunc = void(cJson::Reader_c& r, cJson::token_s& t, void* ptr);

    static void unmarshalArray(
        cJson::Reader_c& r, const cJson::token_s& startT, void* ptr, std::size_t n, std::size_t vs,
        UnmarshalFunc* func
    );

    static void visitFields(
        cJson::Reader_c& r, std::span<const Field_c> fields, const std::string_view& key,
        void* getterObj = nullptr
    );

    template <class T>
    static bool unmarshalFlag(
        cJson::Reader_c& r, T& obj, const std::string_view& flag,
        const std::span<const std::pair<const char*, bool std::type_identity_t<T>::*>>& fields
    ) {
        for (auto& field : fields) {
            if (flag == field.first) {
                obj.*field.second = true;
                return true;
            }
        }
        return false;
    }

    template <class T>
    static bool unmarshalFlag(
        cJson::Reader_c& r, T& obj, int flag,
        const std::span<const std::pair<int, bool std::type_identity_t<T>::*>>& fields
    ) {
        for (auto& field : fields) {
            if (flag == field.first) {
                obj.*field.second = true;
                return true;
            }
        }
        return false;
    }

private:
    // JSON fields
    // ^^^^^^

    static dMj2dJson_c::Field_c cRootFields[];

public:
    // Enumerator utilities
    // ^^^^^^

    static std::optional<int> decodeNumber(const std::string_view& str, bool allowNegative = true);
    static const char* encodeStageNo(StageNo_s stageNo, const std::span<char>& buffer);
    static StageNo_s decodeStageNo(const std::string_view& str);

    using EnumMap = std::span<const char* const>;

private:
    template <class T>
    struct EnumMap_c {
        static constexpr std::pair<bool, T> cNull     = {false, {}};
        static constexpr const char*        cMap[]    = {nullptr};
        static constexpr const char*        cBitMap[] = {nullptr};
    };

public:
    template <slu::concepts::enumerator T>
    static constexpr EnumMap getEnumMap();

    template <slu::concepts::enumerator T>
    static constexpr bool hasEnumMap();

    template <slu::concepts::enumerator T>
    static constexpr bool hasEnumBitMap();

    template <slu::concepts::enumerator T>
    static constexpr bool isEnumBitMap();

    template <slu::concepts::enumerator T>
    static constexpr std::size_t getEnumMapIndex(T e);

    template <slu::concepts::enumerator T>
    static constexpr T getValueFromEnumMapIndex(std::size_t index);

    static constexpr std::optional<std::size_t>
    fromStringGeneric(const char* string, const EnumMap& mapping);

    static constexpr std::optional<std::size_t>
    fromStringGeneric(const std::string_view& string, const EnumMap& mapping);

    template <slu::concepts::enumerator T>
    static constexpr const char* toString(T value);

    template <slu::concepts::enumerator T>
    static constexpr std::optional<T> fromString(const char* string);

    template <slu::concepts::enumerator T>
    static constexpr std::optional<T> fromString(const std::string_view& string);

    static constexpr std::optional<std::size_t>
    readEnumGeneric(const cJson::token_s& t, const EnumMap& mapping);

    template <slu::concepts::enumerator T>
    static constexpr std::optional<T> readEnum(const cJson::token_s& t);

    template <slu::concepts::enumerator T, cJson::ErrorPolicy_e E = except>
    static std::optional<T> readEnum(cJson::Reader_c& r);
};

struct dMj2dJson_c::Field_c {
    using Getter = void*(void* object);

    template <class T>
    consteval Field_c(
        const char* name, T& object, UnmarshalFunc* func = &Type_c<T>::unmarshal
    )
        : name(name)
        , hash(slu::djb2a(name))
        , ptr(static_cast<void*>(&object))
        , func(func) {}

    template <class T = void>
    consteval Field_c(
        const char* name, std::type_identity<T>, UnmarshalFunc* func = &Type_c<T>::unmarshal,
        Getter* getter = nullptr
    )
        : name(name)
        , hash(slu::djb2a(name))
        , ptr{.getter = getter}
        , getter(true)
        , func(func) {}

    template <
        slu::concepts::member_object_pointer auto MemObjPtr,
        class Parts = slu::member_pointer_parts_obj<MemObjPtr>>
    consteval Field_c(
        const char*    name, slu::value_identity<MemObjPtr>,
        UnmarshalFunc* func = &Type_c<typename Parts::value_type>::unmarshal
    )
        : Field_c(
              name, std::type_identity<typename Parts::value_type>{}, func,
              [](void* object) -> void* {
                  return std::addressof(static_cast<Parts::class_type*>(object)->*MemObjPtr);
              }
          ) {}

    const char* name;
    u32         hash;

    union {
        void*   ptr;
        Getter* getter;
    } ptr;

    bool           getter = false;
    UnmarshalFunc* func;
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<PLAYER_TYPE_e>::cMap[] = {
    "mario",    "luigi",           "blue_toad",   "yellow_toad",
    "toadette", "purple_toadette", "orange_toad", "black_toad",
};

template <>
constexpr std::pair<bool, PLAYER_TYPE_e> dMj2dJson_c::EnumMap_c<PLAYER_TYPE_e>::cNull = {
    true, PLAYER_TYPE_e::COUNT
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<STAGE_e>::cMap[] = {
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

template <>
constexpr std::pair<bool, STAGE_e> dMj2dJson_c::EnumMap_c<STAGE_e>::cNull = {true, STAGE_e::COUNT};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<PLAYER_MODE_e>::cMap[] = {
    "small", "mushroom", "fire", "mini", "propeller", "penguin", "ice",
};

template <>
constexpr std::pair<bool, PLAYER_MODE_e> dMj2dJson_c::EnumMap_c<PLAYER_MODE_e>::cNull = {
    true, PLAYER_MODE_e::NONE
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<PLAYER_CREATE_ITEM_e>::cBitMap[] = {
    "star_power", "yoshi", "bubble", "rescue_toad"
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<STOCK_ITEM_e>::cMap[] = {
    "mushroom",      "fire_flower", "propeller_shroom", "ice_flower", "penguin_suit",
    "mini_mushroom", "star",
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<dMj2dGame_c::PIPE_RANDOMIZER_MODE_e>::cMap[] = {
    "disabled",
    "per_game",
    "per_course",
    "per_exit",
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<dMj2dGame_c::START_KINOKO_KIND_e>::cMap[] = {
    "none", "yellow", "red", "green", "yellow_r", "red_r", "green_r",
};

template <>
constexpr std::pair<bool, dMj2dGame_c::START_KINOKO_KIND_e>
    dMj2dJson_c::EnumMap_c<dMj2dGame_c::START_KINOKO_KIND_e>::cNull = {
        true, dMj2dGame_c::START_KINOKO_KIND_e::NONE
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<PATH_DIRECTION_e>::cMap[] = {
    "normal",
    "reverse",
    "initial",
};

template <>
constexpr const char* dMj2dJson_c::EnumMap_c<dMj2dGame_c::GAME_COMPLETION_e>::cBitMap[] = {
    "created",   "final_boss_beaten",     "all_goals", "all_star_coins", "all_star_coins_w9",
    "completed", "super_guide_triggered",
};

template <slu::concepts::enumerator T>
constexpr bool dMj2dJson_c::hasEnumMap() {
    return std::size(EnumMap_c<T>::cMap) > 1 || EnumMap_c<T>::cMap[0];
}

template <slu::concepts::enumerator T>
constexpr bool dMj2dJson_c::hasEnumBitMap() {
    return std::size(EnumMap_c<T>::cBitMap) > 1 || EnumMap_c<T>::cBitMap[0];
}

template <slu::concepts::enumerator T>
constexpr bool dMj2dJson_c::isEnumBitMap() {
    return !hasEnumMap<T>() && hasEnumBitMap<T>();
}

template <slu::concepts::enumerator T>
constexpr dMj2dJson_c::EnumMap dMj2dJson_c::getEnumMap() {
    return hasEnumMap<T>()      ? EnumMap_c<T>::cMap
           : hasEnumBitMap<T>() ? EnumMap_c<T>::cBitMap
                                : EnumMap{};
}

template <class T>
struct dMj2dJson_c::Type_c {
    static void unmarshal(cJson::Reader_c& r, cJson::token_s& t, void* ptr);

    static_assert(std::is_same_v<decltype(unmarshal), UnmarshalFunc>);

    static T unmarshal(cJson::Reader_c& r, cJson::token_s& t);

    static T unmarshal(
        cJson::Reader_c& r, cJson::token_s& t
    )
        requires std::integral<T>
    {
        r.userError(!t.has_number);
        return t.number;
    }

    static T unmarshal(
        cJson::Reader_c& r, cJson::token_s& t
    )
        requires(slu::concepts::enumerator<T> && hasEnumMap<T>())
    {
        std::optional<T> value = dMj2dJson_c::readEnum<T>(t);
        r.userError(!value, __PRETTY_FUNCTION__);
        return *value;
    }

    static T unmarshal(
        cJson::Reader_c& r, cJson::token_s& t
    )
        requires(slu::concepts::enumerator<T> && hasEnumBitMap<T>())
    {
        r.userError(!t.is_array_start());
        std::underlying_type_t<T> bits = 0;
        while (cJson::token_s t = r.anyValue<pass>()) {
            if (std::optional<T> value = dMj2dJson_c::readEnum<T>(t)) {
                bits |= static_cast<std::underlying_type_t<T>>(*value);
            } else {
                DEBUG_REPORT(
                    "W: Unknown value \"%.*s\" of type \"%s\"\n", static_cast<int>(t.string.size()),
                    t.string.data(), slu::type_name<T>().data()
                );
            }
        }
        r.endArray();

        return static_cast<T>(bits);
    }

    static T unmarshal(
        cJson::Reader_c& r, cJson::token_s& t
    )
        requires slu::concepts::same_value_templated_type<T, std::bitset>
    {
        r.userError(!t.is_array_start());

        // Unmarshal bit indices
        T bitset;
        while (cJson::token_s t = r.number<pass>()) {
            if (t.number < bitset.size()) {
                bitset.set(t.number);
            }
        }
        r.endArray();
        return bitset;
    }
};

template <>
WORLD_e dMj2dJson_c::Type_c<WORLD_e>::unmarshal(cJson::Reader_c& r, cJson::token_s& t);

template <>
STAGE_e dMj2dJson_c::Type_c<STAGE_e>::unmarshal(cJson::Reader_c& r, cJson::token_s& t);

template <>
StageNo_s dMj2dJson_c::Type_c<StageNo_s>::unmarshal(cJson::Reader_c& r, cJson::token_s& t);

template <>
dMj2dGame_c::GAME_COMPLETION_e dMj2dJson_c::Type_c<dMj2dGame_c::GAME_COMPLETION_e>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
);

template <>
dMj2dGame_c::WORLD_COMPLETION_e dMj2dJson_c::Type_c<dMj2dGame_c::WORLD_COMPLETION_e>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t
);

template <>
dMj2dGame_c::Revision_s
dMj2dJson_c::Type_c<dMj2dGame_c::Revision_s>::unmarshal(cJson::Reader_c& r, cJson::token_s& t);

template <class T>
void dMj2dJson_c::Type_c<T>::unmarshal(
    cJson::Reader_c& r, cJson::token_s& t, void* ptr
) {
    *static_cast<T*>(ptr) = unmarshal(r, t);
}

template <class T, std::size_t N>
struct dMj2dJson_c::Type_c<T[N]> {
    static void unmarshal(
        cJson::Reader_c& r, cJson::token_s& t, void* ptr
    ) {
        return unmarshalArray(r, t, ptr, N, sizeof(T), &Type_c<T>::unmarshal);
    }

    static_assert(std::is_same_v<decltype(unmarshal), UnmarshalFunc>);
};

template <std::size_t N>
inline bool dMj2dJson_c::marshalBitIndices(
    cJson::Writer_c& w, const std::bitset<N>& bits
) {
    for (std::size_t i = 0; i < N; i++) {
        if (bits[i] && !w.number(i)) {
            return false;
        }
    }
    return true;
}

template <slu::concepts::enumerator T>
constexpr std::size_t dMj2dJson_c::getEnumMapIndex(
    T e
) {
    std::integral auto index = static_cast<std::underlying_type_t<T>>(e);
    if constexpr (isEnumBitMap<T>()) {
        return std::countr_zero<std::make_unsigned_t<std::underlying_type_t<T>>>(index);
    } else {
        return index;
    }
}

template <slu::concepts::enumerator T>
constexpr T dMj2dJson_c::getValueFromEnumMapIndex(
    std::size_t index
) {
    if constexpr (isEnumBitMap<T>()) {
        return static_cast<T>(std::underlying_type_t<T>(1) << index);
    } else {
        return static_cast<T>(index);
    }
}

constexpr std::optional<std::size_t> dMj2dJson_c::fromStringGeneric(
    const char* string, const EnumMap& mapping
) {
    std::size_t i;
    for (i = 0; i < mapping.size(); i++) {
        if (std::strcmp(mapping[i], string) == 0) {
            return i;
        }
    }
    return std::nullopt;
}

constexpr std::optional<std::size_t> dMj2dJson_c::fromStringGeneric(
    const std::string_view& string, const EnumMap& mapping
) {
    std::size_t i;
    for (i = 0; i < mapping.size(); i++) {
        const char* entry = mapping[i];
        if (mapping[i] && std::strncmp(entry, string.data(), string.size()) == 0 &&
            entry[string.size()] == '\0') {
            return i;
        }
    }
    return std::nullopt;
}

template <slu::concepts::enumerator T>
constexpr const char* dMj2dJson_c::toString(
    T value
) {
    std::size_t index = getEnumMapIndex<T>(value);
    if (index < 0 || index >= std::size(getEnumMap<T>())) {
        return nullptr;
    }
    return getEnumMap<T>()[index];
}

template <slu::concepts::enumerator T>
constexpr std::optional<T> dMj2dJson_c::fromString(
    const char* string
) {
    return fromStringGeneric(string, getEnumMap<T>()).transform([](std::size_t index) {
        return getValueFromEnumMapIndex<T>(index);
    });
}

template <slu::concepts::enumerator T>
constexpr std::optional<T> dMj2dJson_c::fromString(
    const std::string_view& string
) {
    return fromStringGeneric(string, getEnumMap<T>()).transform([](std::size_t index) {
        return getValueFromEnumMapIndex<T>(index);
    });
}

constexpr std::optional<std::size_t> dMj2dJson_c::readEnumGeneric(
    const cJson::token_s& t, const EnumMap& mapping
) {
    if (t.has_number) {
        return t.number;
    }
    if (t.is_string() || t.is_key()) {
        return fromStringGeneric(t.string, mapping);
    }
    return std::nullopt;
}

template <slu::concepts::enumerator T>
constexpr std::optional<T> dMj2dJson_c::readEnum(
    const cJson::token_s& t
) {
    if (!t) {
        return std::nullopt;
    }
    if (EnumMap_c<T>::cNull.first && t.is_null()) {
        return EnumMap_c<T>::cNull.second;
    }
    return readEnumGeneric(t, getEnumMap<T>()).transform([](std::size_t index) {
        return getValueFromEnumMapIndex<T>(index);
    });
}

template <slu::concepts::enumerator T, cJson::ErrorPolicy_e E>
inline std::optional<T> dMj2dJson_c::readEnum(
    cJson::Reader_c& r
) {
    std::optional<T> value = readEnum<T>(r.anyValue());
    if constexpr (E == except) {
        r.userError(!value);
    }
    return value;
}
