// d_profile_static.cpp
// NSMBW .text: 0x801018C0 - 0x801018E0

#include "d_profile.h"

#include "d_player/d_a_player.h"
#include "d_player/d_a_yoshi.h"
#include "d_profile/d_profile.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_base.h"
#include "d_system/d_player_model_manager.h"
#include "d_system/d_yoshi_model.h"
#include <algorithm>
#include <array>
#include <cstring>
#include <iterator>
#include <numeric>
#include <utility>

namespace dProf
{

struct ActorName {
    consteval ActorName(const auto& profName, const auto& nameString)
      : profile(profName.StaticNonRegionalValue)
      , name()
    {
        for (unsigned i = 0; i < sizeof(nameString); i++) {
            name[i] = nameString[i];
        }
    }

    dProfName profile;
    char name[256];
}; // namespace dProfstruct ActorName

constexpr auto s_formatted_name_data = [] consteval {
    constexpr ActorName formatted_table[] = {
#include "d_profile_formatted_table.inc"
    };
    constexpr std::array<u32, std::size(formatted_table)> lengths = [formatted_table] {
        std::array<u32, std::size(formatted_table)> lengths;
        for (u32 i = 0; i < std::size(formatted_table); i++) {
            u32 j;
            for (j = 0; formatted_table[i].name[j] != '\0'; j++) {
            }
            lengths[i] = j;
        }
        return lengths;
    }();
    constexpr std::array<u32, std::size(formatted_table)> sorted_indices = [formatted_table,
                                                                            lengths] {
        std::array<u32, std::size(formatted_table)> indices;
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&](u32 a, u32 b) {
            return lengths[a] > lengths[b];
        });
        return indices;
    }();
    constexpr std::pair encoded = [formatted_table, lengths, sorted_indices]() {
        std::array<char, 0x1000> packed;
        u32 offset = 0;

        auto writeByte = [&](char byte) { packed[offset++] = byte; };

        for (u32 i = 0; i < std::size(formatted_table); i++) {
            const ActorName& name = formatted_table[sorted_indices[i]];
            writeByte(char(u16(name.profile) >> 2));
            writeByte(char(u16(name.profile) << 6));

            // Search back to see if we have a copy of the same name
            s32 foundOffset = -1;
            u32 myLength = lengths[sorted_indices[i]];
            for (u32 j = 0; j < offset - 2;) {
                if (packed[j + 1] & 0x20) {
                    j += 3;
                    continue;
                }
                u32 len = (packed[j + 1] << 8) & 0x1F;
                len |= packed[j + 2];
                u32 next = j + 3 + len;
                if (next > offset - 2) {
                    break;
                }
                u32 k = next - 1 - myLength;
                u32 l;
                for (l = 0; l < myLength; l++) {
                    if (packed[k + l] != name.name[l]) {
                        break;
                    }
                }
                if (l == myLength) {
                    foundOffset = s32(k);
                    break;
                }
                j = next;
            }

            if (foundOffset != -1) {
                packed[offset - 1] |= 0x20 | ((foundOffset >> 8) & 0x1F);
                writeByte(foundOffset);
                continue;
            }
            u32 loc = offset++;
            for (u32 j = 0; name.name[j] != '\0'; j++) {
                writeByte(name.name[j]);
            }
            writeByte('\0');
            packed[loc] = offset - loc - 1;
        }
        return std::pair{packed, offset};
    }();
    std::array<char, encoded.second> packed;
    for (u32 i = 0; i < encoded.second; i++) {
        packed[i] = encoded.first[i];
    }
    return packed;
}();

/* @renamed(@LOCAL@dProf_getName__FUs@s_table) */
[[nsmbw_data(0x80320B58)]]
const char* s_base_name_table[BASE_COUNT];

const std::array<const char*, CUSTOM_COUNT + 1> s_extra_name_table = [] {
    std::array<const char*, CUSTOM_COUNT + 1> table{};
#define PROFILE(_ID, _NAME, _CLASS)                                                                \
    if constexpr (_ID >= dProf::BASE_COUNT) {                                                      \
        table[_ID - dProf::BASE_COUNT] = STRINGIFY(_NAME);                                         \
    }
#include "d_profile_table.inc"
#undef PROFILE
    return table;
}();

[[nsmbw(0x801018C0)]]
const char* getName(dProfName profile)
{
    if (profile >= dProf::BASE_COUNT) {
        return s_extra_name_table[profile - dProf::BASE_COUNT];
    }
    return s_base_name_table[profile];
}

const char* getFormattedName(dBase_c* actor)
{
    if (actor == nullptr) {
        return nullptr;
    }

    if (auto player = actor->DynamicCast<dAcPy_c>()) {
        if (player->isItemKinopio()) {
            return "Road";
        }

        int colorType = daPyMng_c::getPlayerColorType(player->mPlayerType);
        PLAYER_TYPE_e playerType = static_cast<PLAYER_TYPE_e>(colorType);

        switch (playerType) {
        default:
            return "Player";

        case PLAYER_TYPE_e::MARIO:
            return "Mario";
        case PLAYER_TYPE_e::LUIGI:
            return "Luigi";
        case PLAYER_TYPE_e::YELLOW_TOAD:
            return "Yoad";
        case PLAYER_TYPE_e::BLUE_TOAD:
            return "Bload";
        case PLAYER_TYPE_e::TOADETTE:
            return "Toadette";
        case PLAYER_TYPE_e::PURPLE_TOADETTE:
            return "Poadette";
        case PLAYER_TYPE_e::ORANGE_TOAD:
            return "Oroad";
        case PLAYER_TYPE_e::BLACK_TOAD:
            return "Blaod";
        }
    } else if (auto yoshi = actor->DynamicCast<daYoshi_c>()) {
        dYoshiMdl_c* yoshiMdl = static_cast<dYoshiMdl_c*>(yoshi->mpModelMng->mModel);
        switch (yoshiMdl->mColor) {
        default:
        case dYoshiMdl_c::COLOR_e::COLOR_GREEN:
            return "Yoshi";
        case dYoshiMdl_c::COLOR_e::COLOR_RED: // Pink
            return "Poshi";
        case dYoshiMdl_c::COLOR_e::COLOR_YELLOW:
            return "Yelloshi";
        case dYoshiMdl_c::COLOR_e::COLOR_BLUE: // Light blue
            return "Blueshi";
        case dYoshiMdl_c::COLOR_e::COLOR_CRIMSON: // Red
            return "Roshi";
        case dYoshiMdl_c::COLOR_e::COLOR_ORANGE:
            return "Oroshi";
        case dYoshiMdl_c::COLOR_e::COLOR_PURPLE:
            return "Purposhi";
        case dYoshiMdl_c::COLOR_e::COLOR_AZURE: // Blue
            return "Boshi";
        }
    }

    dProfName name = actor->mProfName;
    for (u32 i = 0; i < s_formatted_name_data.size();) {
        u32 info = *reinterpret_cast<const u32*>(s_formatted_name_data.data() + i);
        u32 len = (info >> 8) & 0x1FFF;
        bool match = name == dProfName(info >> 22);
        if (info & 0x200000) {
            if (match) {
                return &s_formatted_name_data[len];
            }
            i += 3;
            continue;
        }
        if (match) {
            return &s_formatted_name_data[i + 3];
        }
        i += 3 + len;
    }

    return actor && actor->mpNameString ? actor->mpNameString : "an unknown force";
}

dProfName getProfByName(const char* string)
{
    u32 lastActor = dProf::LASTACTOR;
    for (u32 i = 0; i < lastActor; i++) {
        if (std::strcmp(string, getName(i)) == 0) {
            return i;
        }
    }
    return -1;
}

} // namespace dProf
