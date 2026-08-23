// d_profile_table.cpp
// NSMBW d_profile.rodata: 0x8076A748 - 0x8076B300

#include "d_profile.h"
#include "f_profile.h"
#include <array>

namespace dProfTable
{

int meow();

[[nsmbw_data(0x8076A748)]]
extern const fProfileDat_c* const scBaseProfileList[dProf::BASE_COUNT]{};

constinit std::array<fProfileDat_c*, dProf::CUSTOM_COUNT + 1> scExtraProfileList = [] {
    std::array<fProfileDat_c*, dProf::CUSTOM_COUNT + 1> list{};

#define PROFILE(_ID, _NAME, _CLASS)                                                                \
    if constexpr (_ID >= dProf::BASE_COUNT) {                                                      \
        extern fProfileDat_c CONCAT(g_profile_accessor_, _NAME) asm(                               \
          STRINGIFY(CONCAT(g_profile_, _NAME))                                                     \
        );                                                                                         \
        list[_ID - dProf::BASE_COUNT] = &CONCAT(g_profile_accessor_, _NAME);                       \
    }
#include "d_profile_table.inc"
#undef PROFILE

    return list;
}();

std::array<fProfileDat_c*, dProf::COUNT> scProfileList = [] {
    std::array<fProfileDat_c*, dProf::COUNT> list{};
    for (std::size_t i = 0; i < dProf::BASE_COUNT; i++) {
        list[i] = const_cast<fProfileDat_c*>(scBaseProfileList[i]);
    }
    for (std::size_t i = 0; i < dProf::CUSTOM_COUNT; i++) {
        list[i + dProf::BASE_COUNT] = scExtraProfileList[i];
    }
    fProfileDat_c::sProfileList = scProfileList.data();
    return list;
}();

} // namespace dProfTable
