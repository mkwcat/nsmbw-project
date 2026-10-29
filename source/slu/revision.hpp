//
//  slu/revision.hpp
//  supplemental-language-utilities
//

#pragma once

#include "macro.hpp"

namespace slu {

enum class revision {
#if is_nsmbw
    pal1,       // Europe, Australia (PAL) revision 1
    pal2,       // Europe, Australia (PAL) revision 2
    usa1,       // Americas (NTSC-U) revision 1
    usa2,       // Americas (NTSC-U) revision 2
    jpn1,       // Japan (NTSC-J) revision 1
    jpn2,       // Japan (NTSC-J) revision 2
    kor,        // South Korea (NTSC-K)
    twn,        // Taiwan (NTSC-W)
    chn_shield, // China (Nvidia Shield TV)
#elif is_mkw
    pal,    // Europe, Australia (PAL) disc
    usa,    // Americas (NTSC-U) disc
    jpn,    // Japan (NTSC-J) disc
    kor,    // South Korea (NTSC-K) disc
    pal_ch, // Europe, Australia (PAL) channel
    usa_ch, // Americas (NTSC-U) channel
    jpn_ch, // Japan (NTSC-J) channel
    kor_ch, // South Korea (NTSC-K) channel
    jpn_tr, // Japan (NTSC-J) kiosk demo
#endif
    error,

#if is_nsmbw
    base = pal1,
#elif is_mkw
    base = pal,
#else
    base = error,
#endif
};

inline void determine_revision();
[[gnu::pure]]
inline revision get_revision();

class revision_value {
    revision_value()             = delete;
    static inline revision value = revision::error;

    friend void determine_revision();
    friend revision get_revision();
};

[[error_if_not_nsmbw]] [[gnu::pure]]
inline revision determine_revision_nsmbw_static() {
#if is_nsmbw
    switch (*reinterpret_cast<volatile u8*>(0x8000423A)) {
    case 0xFF:
        // PAL (P)
        if (*reinterpret_cast<volatile u8*>(0x800CF287) == 0x30) {
            return revision::pal1;
        }
        return revision::pal2; // c == 0x38
    case 0xFC:
        // USA (E)
        if (*reinterpret_cast<volatile u8*>(0x800CF197) == 0x30) {
            return revision::usa1;
        }
        return revision::usa2; // c == 0x38
    case 0xF9:
        // JPN (J)
        if (*reinterpret_cast<volatile u8*>(0x800CF117) == 0x30) {
            return revision::jpn1;
        }
        return revision::jpn2; // c == 0x38
    case 0xC8:
        return revision::kor;
    case 0xAC:
        return revision::twn;
    case 0x55:
        return revision::chn_shield;
    }
#endif
    return revision::error;
}

[[error_if_not_mkw]] [[gnu::pure]]
inline revision determine_revision_mkw_static() {
#if is_mkw
    // TODO: Detect channel
    switch (*reinterpret_cast<volatile u16*>(0x80006292)) {
    case 0xEFA0:
        return revision::pal;
    case 0xAC20:
        return revision::usa;
    case 0xE920:
        return revision::jpn;
    case 0xCFC0:
        return revision::kor;
    }
#endif
    return revision::error;
}

[[gnu::pure]]
inline revision determine_revision_static() {
    NSMBW_ONLY(return determine_revision_nsmbw_static();)
    MKW_ONLY(return determine_revision_mkw_static();)
    return revision::error;
}

inline void determine_revision() {
    revision_value::value = determine_revision_static();
}

[[gnu::pure]]
inline revision get_revision() {
    return revision_value::value;
}

[[gnu::const]]
constexpr bool is_pal(
    revision rev = get_revision()
) {
    return false NSMBW_ONLY(|| rev == revision::pal1 || rev == revision::pal2)
        MKW_ONLY(|| rev == revision::pal);
}

[[gnu::const]]
constexpr bool is_usa(
    revision rev = get_revision()
) {
    return false NSMBW_ONLY(|| rev == revision::usa1 || rev == revision::usa2)
        MKW_ONLY(|| rev == revision::usa);
}

constexpr u32 get_r2_address(
    revision r
) {
    switch (r) {
#if is_nsmbw
    case revision::pal1:
    case revision::pal2:
        return 0x80433360;

    case revision::usa1:
    case revision::usa2:
        return 0x80433080;
    case revision::jpn1:
    case revision::jpn2:
        return 0x80432DA0;

    case revision::kor:
        return 0x8043FD20;

    case revision::twn:
        return 0x8043E120;

    case revision::chn_shield:
        return 0x80438900;
#elif is_mkw
    case revision::pal:
        return 0x8038EFA0ul;
    case revision::usa:
        return 0x8038AC20ul;
    case revision::jpn:
        return 0x8038E920ul;
    case revision::kor:
        return 0x8037CFC0ul;
#endif

    default:
        return 0;
    }
}

constexpr u32 get_r13_address(
    revision r
) {
    switch (r) {
#if is_nsmbw
    case revision::pal1:
    case revision::pal2:
        return 0x8042F980;

    case revision::usa1:
    case revision::usa2:
        return 0x8042F680;

    case revision::jpn1:
    case revision::jpn2:
        return 0x8042F400;

    case revision::kor:
        return 0x8043C380;

    case revision::twn:
        return 0x8043A780;

    case revision::chn_shield:
        return 0x80434F00;
#elif is_mkw
    case revision::pal:
        return 0x8038CC00ul;
    case revision::usa:
        return 0x80388880ul;
    case revision::jpn:
        return 0x8038C580ul;
    case revision::kor:
        return 0x8037AC00ul;
#endif

    default:
        return 0;
    }
}

} // namespace slu
