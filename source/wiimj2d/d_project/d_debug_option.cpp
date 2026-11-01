// d_debug_option.cpp
// nsmbw-project

#include "d_debug_option.h"

#include "c_json.h"
#include "d_mj2d_game.h"
#include "d_mj2d_json_handler.h"
#include <concepts>
#include <cstring>
#include <revolution/os/OSError.h>
#include <slu/concepts.hpp>
#include <slu/djb2a.hpp>
#include <slu/pointer.hpp>
#include <span>
#include <type_traits>

namespace dDebugOpt {

namespace {

using ValueFunc = bool (*)(cJson::DvdReader_c& r, cJson::Reader_c::token_s& t, void* ptr);

template <class T>
struct Resolver_t {
    static bool value(
        cJson::DvdReader_c& r, cJson::Reader_c::token_s& t, void* ptr
    )
        requires std::integral<T>
    {
        if (t.has_number) {
            *static_cast<T*>(ptr) = t.number;
        }
        return t.has_number;
    }

    static bool value(
        cJson::DvdReader_c& r, cJson::Reader_c::token_s& t, void* ptr
    )
        requires slu::concepts::enumerator<T>
    {
        std::optional<std::size_t> underlyingValue = dMj2dJsonHandler_c::readEnum<T>(t);
        if (underlyingValue.has_value()) {
            *static_cast<T*>(ptr) = static_cast<T>(*underlyingValue);
        }
        return underlyingValue.has_value();
    }
};

template <>
struct Resolver_t<WORLD_e> {
    static bool value(
        cJson::DvdReader_c& r, cJson::Reader_c::token_s& t, void* ptr
    ) {
        if (t.has_number) {
            *static_cast<WORLD_e*>(ptr) = static_cast<WORLD_e>(t.number - 1);
        }
        return t.has_number;
    }
};

template <>
struct Resolver_t<STAGE_e> {
    static bool value(
        cJson::DvdReader_c& r, cJson::Reader_c::token_s& t, void* ptr
    ) {
        t.number--;
        std::optional<std::size_t> underlyingValue = dMj2dJsonHandler_c::readEnum<STAGE_e>(t);
        if (underlyingValue.has_value()) {
            *static_cast<STAGE_e*>(ptr) = static_cast<STAGE_e>(*underlyingValue);
        }
        return underlyingValue.has_value();
    }
};

bool iterateArrayValues(
    cJson::DvdReader_c& r, const cJson::Reader_c::token_s& startT, void* ptr, std::size_t n,
    std::size_t vs, ValueFunc func
) {
    if (!startT.is_array_start()) {
        return false;
    }

    while (cJson::Reader_c::token_s t = r.next()) {
        if (t.is_array_end()) {
            return true;
        }
        if (n-- == 0) {
            OS_REPORT("E: Array overflow\n");
            return false;
        }
        if (!(*func)(r, t, ptr)) {
            return false;
        }
        ptr = slu::pointer::offset<void>(ptr, vs);
    }
    return false;
}

template <class T, std::size_t N>
struct Resolver_t<T[N]> {
    static bool value(
        cJson::DvdReader_c& r, cJson::Reader_c::token_s& t, void* ptr
    ) {
        return iterateArrayValues(r, t, ptr, N, sizeof(T), &Resolver_t<T>::value);
    }
};

struct JsonField_s {
    template <class T>
    consteval JsonField_s(
        const char* name, T& object
    )
        : name(name)
        , hash(slu::djb2a(name))
        , ptr(&object)
        , func(&Resolver_t<T>::value) {}

    const char* name;
    u32         hash;
    void*       ptr;
    ValueFunc   func;
};

constexpr JsonField_s cAutobootFields[] = {
    {"world", autoboot::world},
    {"stage", autoboot::stage},
    {"area", autoboot::area},
    {"entrance", autoboot::entrance},
    {"num_players", autoboot::num_players},
    {"player_index", autoboot::player_index},
    {"player_type_order", autoboot::player_type_order},
    {"player_mode", autoboot::player_mode},
    {"in_star", autoboot::in_star},
    {"on_yoshi", autoboot::on_yoshi},

    {"staffroll", autoboot::staffroll},

    {"movie", autoboot::movie},

    {"title_demo", autoboot::title_demo},
    {"hint_movie_demo", autoboot::hint_movie_demo}
};

constexpr JsonField_s cFields[] = {
    {"one_player_special_hip_attack_quake", one_player_special_hip_attack_quake},
    {"end_battles_immediately", end_battles_immediately},
    {"force_all_wm_subplayers_present", force_all_wm_subplayers_present},
    {"print_base_creation", print_base_creation},
    {"print_state_changes", print_state_changes},
};

bool visitFields(
    cJson::DvdReader_c& r, std::span<const JsonField_s> fields, const std::string_view& key
) {
    const u32 hash = slu::djb2a(key.data(), key.length());
    for (const JsonField_s& field : fields) {
        if (field.hash != hash || field.name != key) {
            continue;
        }

        cJson::Reader_c::token_s t = r.next();
        if (!t) {
            OS_REPORT("E: !r.next()\n");
            return false;
        }
        if (t.is_null()) {
            // Skip this value
            return true;
        }

        if (!field.func(r, t, field.ptr)) {
            OS_REPORT(
                "E: \"%s\": \"%.*s\"\n", field.name, static_cast<int>(t.string.size()),
                t.string.data()
            );
            return false;
        }
        return true;
    }

    OS_REPORT("E: Unknown key \"%.*s\"\n", static_cast<int>(key.size()), key.data());
    return false;
}

constexpr auto cDebugConfigName = "mkwcat-nsmbw-debug.json";

} // namespace

void readConfig() {
    cJson::DvdReader_c r(cDebugConfigName);
    if (r.end()) {
        OS_REPORT("No %s present\n", cDebugConfigName);
        return;
    }

    if (!r.startObject()) {
        OS_REPORT("E: !r.startObject()\n");
        return;
    }

    while (auto key = r.key()) {
        if (key.string == "autoboot") {
            if (!r.startObject()) {
                OS_REPORT("E: autoboot !r.startObject()\n");
                return;
            }
            while (auto key = r.key()) {
                if (!visitFields(r, cAutobootFields, key.string)) {
                    return;
                }
            }
            if (!r.endObject()) {
                OS_REPORT("E: autoboot !r.endObject()\n");
            }
        } else {
            if (!visitFields(r, cFields, key.string)) {
                return;
            }
        }
    }

    if (!r.endObject()) {
        OS_REPORT("E: !r.endObject()\n");
        return;
    }

    OS_REPORT("Loaded %s\n", cDebugConfigName);
}

} // namespace dDebugOpt
