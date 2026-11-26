// d_debug_option.cpp
// nsmbw-project

#include "d_debug_option.h"

#include "c_json.h"
#include "d_mj2d_game.h"
#include "d_mj2d_json.h"
#include <revolution/os/OSError.h>
#include <slu/concepts.hpp>
#include <slu/djb2a.hpp>
#include <slu/pointer.hpp>

namespace dDebugOpt {

namespace {

constexpr dMj2dJson_c::Field_c cAutobootFields[] = {
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

constexpr dMj2dJson_c::Field_c cFields[] = {
    {"print_base_creation", print_base_creation},
    {"print_state_changes", print_state_changes},
    {"print_worldmap_demo", print_worldmap_demo},
    {"one_player_special_hip_attack_quake", one_player_special_hip_attack_quake},
    {"end_battles_immediately", end_battles_immediately},
    {"force_all_wm_subplayers_present", force_all_wm_subplayers_present},
    {"disable_no_collide", disable_no_collide},
};

constexpr auto cDebugConfigName = "mkwcat-nsmbw-debug.json";

} // namespace

void readConfig() {
    cJson::DvdReader_c r(cDebugConfigName);

    OSContext          context;
    if (OSSaveContext(&context) != 0) {
        DEBUG_REPORT("Terminating debug config JSON reader\n");
        return;
    }

    r.setUserErrorCallback(
        [](void* userData) {
            auto* context = static_cast<OSContext*>(userData);
            OSLoadContext(context);
            std::unreachable();
        },
        &context
    );

    if (r.end()) {
        OS_REPORT("No %s present\n", cDebugConfigName);
        return;
    }

    r.startObject();

    while (auto key = r.key<cJson::ErrorPolicy_e::pass>()) {
        if (key == "autoboot") {
            r.startObject();
            while (auto key = r.key<cJson::ErrorPolicy_e::pass>()) {
                dMj2dJson_c::visitFields(r, cAutobootFields, key);
            }
            r.endObject();
        } else {
            dMj2dJson_c::visitFields(r, cFields, key);
        }
    }

    r.endObject();

    OS_REPORT("Loaded %s\n", cDebugConfigName);
}

} // namespace dDebugOpt
