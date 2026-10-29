//
//  slu/address_mapper.hpp
//  supplemental-language-utilities
//

#pragma once

#include "revision.hpp"
#include <cstddef>
#include <cstdint>

namespace slu {

constexpr char address_map_file[] = {
// This is standardized in C++ but still warns in Clang
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc23-extensions"
#if is_nsmbw
#  embed "../../address-map.txt"
#elif is_mkw
#  embed "../../address-map-mkw.txt"
#endif
#pragma clang diagnostic pop
};

class address_mapper;

static constexpr const address_mapper& get_address_mapper(revision r);

/**
 * Compile-time address mapper.
 */
class address_mapper {
#if 1
private:
    struct address_range {
        std::uint32_t low;
        std::uint32_t high;
        std::int32_t  offset;
    };

    revision      m_region       = revision::error;
    revision      m_extend       = revision::error;
    address_range m_ranges[1024] = {};
    std::size_t   m_range_count  = 0;

public:
    constexpr address_mapper(
        revision r
    ) {
        // Cycle through the address map file to find the revision
        std::size_t index = 0;
        for (; index < sizeof(address_map_file); index = next_line(index)) {
            revision region_marker = consume_region_marker(index);
            if (region_marker == r) {
                m_region = r;
                break;
            }
        }

        // If the revision was not found, return
        if (m_region == revision::error) {
            return;
        }

        std::size_t first_line = 0;
        // Cycle through the address map file to find the extend revision and first line
        for (index = next_line(index); index < sizeof(address_map_file); index = next_line(index)) {
            revision extend = consume_extend(index);
            if (extend != revision::error) {
                m_extend = extend;
                continue;
            }

            std::size_t currentLine = index;
            index                   = skip_whitespace(index);
            if (is_hex_digit(address_map_file[index])) {
                first_line = currentLine;
                break;
            }
        }

        local_assert(first_line != 0);

        // Cycle through the address map file to find the address ranges
        for (index = first_line; index < sizeof(address_map_file); index = next_line(index)) {
            index = skip_whitespace(index);

            // If we reach a revision marker then that's the end of our section
            if (address_map_file[index] == '[') {
                break;
            }

            // Check if we have a digit
            if (!is_hex_digit(address_map_file[index])) {
                continue;
            }

            // Parse the low range address
            address_range& range = m_ranges[m_range_count++];
            range.low            = parse_uint(index);

            local_assert(address_map_file[index++] == '-');

            // Parse the high range address
            if (address_map_file[index] == '*') {
                range.high = 0xFFFFFFFF;
                index++;
            } else {
                range.high = parse_uint(index);
            }

            index = skip_whitespace(index);
            local_assert(address_map_file[index++] == ':');
            index         = skip_whitespace(index);

            // Parse the offset
            bool negative = false;
            if (address_map_file[index] == '-') {
                negative = true;
            } else if (address_map_file[index] != '+') {
                continue;
            }

            index++;
            local_assert(address_map_file[index++] == '0');
            local_assert(address_map_file[index++] == 'x');
            range.offset = parse_uint(index);
            if (negative) {
                range.offset = -range.offset;
            }
        }
    }

private:
    static void assert_fail();

    static constexpr void local_assert(
        bool condition
    ) {
        if (!condition) {
            assert_fail();
        }
    }

    static constexpr bool is_hex_digit(
        char c
    ) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f');
    }

    static constexpr std::uint32_t parse_uint(
        std::size_t& index
    ) {
        std::uint32_t value = 0;
        for (; is_hex_digit(address_map_file[index]); index++) {
            value <<= 4;
            if (address_map_file[index] >= 'a') {
                value |= address_map_file[index] - 'a' + 10;
            } else if (address_map_file[index] >= 'A') {
                value |= address_map_file[index] - 'A' + 10;
            } else {
                value |= address_map_file[index] - '0';
            }
        }

        return value;
    }

    static constexpr std::size_t next_line(
        std::size_t index
    ) {
        for (std::size_t i = index; i < sizeof(address_map_file); i++) {
            if (address_map_file[i] == '\n') {
                return i + 1;
            }
        }

        return sizeof(address_map_file);
    }

    static constexpr std::size_t skip_whitespace(
        std::size_t index
    ) {
        for (std::size_t i = index; i < sizeof(address_map_file); i++) {
            if (address_map_file[i] != ' ' && address_map_file[i] != '\t') {
                return i;
            }
        }

        return sizeof(address_map_file);
    }

    static constexpr revision consume_region(
        std::size_t index
    ) {
        switch (address_map_file[index]) {
#  if is_nsmbw
        case 'P':
            return address_map_file[index + 1] == '1' ? revision::pal1 : revision::pal2;
        case 'E':
            return address_map_file[index + 1] == '1' ? revision::usa1 : revision::usa2;
        case 'J':
            return address_map_file[index + 1] == '1' ? revision::jpn1 : revision::jpn2;
        case 'K':
            return revision::kor;
        case 'W':
            return revision::twn;
        case 'C':
            return revision::chn_shield;
#  elif is_mkw
        case 'P':
            return revision::pal;
        case 'E':
            return revision::usa;
        case 'J':
            return revision::jpn;
        case 'K':
            return revision::kor;
#  endif
        default:
            return revision::error;
        }
    }

    static constexpr revision consume_region_marker(
        std::size_t index
    ) {
        index = skip_whitespace(index);
        if (address_map_file[index] != '[') {
            return revision::error;
        }

        return consume_region(index + 1);
    }

    static constexpr revision consume_extend(
        std::size_t index
    ) {
        index = skip_whitespace(index);
        for (std::size_t i = 0; i < sizeof("extend ") - 1; i++) {
            if (address_map_file[index++] != "extend "[i]) {
                return revision::error;
            }
        }

        return consume_region(skip_whitespace(index));
    }

public:
    constexpr std::uint32_t map_address(
        std::uint32_t src_address
    ) const {
        if (m_extend != revision::error && m_extend != revision::base) {
            src_address = get_address_mapper(m_extend).map_address(src_address);
        }

        // Binary search for the address range
        std::size_t low  = 0;
        std::size_t high = m_range_count;
        while (low < high) {
            std::size_t          mid   = (low + high) / 2;
            const address_range& range = m_ranges[mid];
            if (src_address >= range.low && src_address <= range.high) {
                return src_address + range.offset;
            }

            if (src_address < range.low) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return 0;
    }
#else
public:
    constexpr address_mapper(
        revision r
    ) {}

    constexpr std::uint32_t map_address(
        std::uint32_t src_address
    ) const {
        return src_address;
    }
#endif
};

#if is_nsmbw
constexpr address_mapper address_mapper_pal2(revision::pal2);
constexpr address_mapper address_mapper_usa1(revision::usa1);
constexpr address_mapper address_mapper_usa2(revision::usa2);
constexpr address_mapper address_mapper_jpn1(revision::jpn1);
constexpr address_mapper address_mapper_jpn2(revision::jpn2);
constexpr address_mapper address_mapper_kor(revision::kor);
constexpr address_mapper address_mapper_twn(revision::twn);
constexpr address_mapper address_mapper_chn(revision::chn_shield);
#elif is_mkw
constexpr address_mapper address_mapper_usa(revision::usa);
constexpr address_mapper address_mapper_jpn(revision::jpn);
constexpr address_mapper address_mapper_kor(revision::kor);
#endif

static constexpr const address_mapper& get_address_mapper(
    revision r
) {
    switch (r) {
#if is_nsmbw
    case revision::pal2:
        return address_mapper_pal2;
    case revision::usa1:
        return address_mapper_usa1;
    case revision::usa2:
        return address_mapper_usa2;
    case revision::jpn1:
        return address_mapper_jpn1;
    case revision::jpn2:
        return address_mapper_jpn2;
    case revision::kor:
        return address_mapper_kor;
    case revision::twn:
        return address_mapper_twn;
    case revision::chn_shield:
        return address_mapper_chn;

#elif is_mkw
    case revision::usa:
        return address_mapper_usa;
    case revision::jpn:
        return address_mapper_jpn;
    case revision::kor:
        return address_mapper_kor;
#endif

    default:
        __builtin_unreachable();
    }
}

template <std::uint32_t BaseAddr>
static constexpr std::uint32_t auto_port(
    revision r
) {
#if is_nsmbw
    static constexpr std::uint32_t pal2_addr =
        get_address_mapper(revision::pal2).map_address(BaseAddr);
    static constexpr std::uint32_t usa1_addr =
        get_address_mapper(revision::usa1).map_address(BaseAddr);
    static constexpr std::uint32_t usa2_addr =
        get_address_mapper(revision::usa2).map_address(BaseAddr);
    static constexpr std::uint32_t jpn1_addr =
        get_address_mapper(revision::jpn1).map_address(BaseAddr);
    static constexpr std::uint32_t jpn2_addr =
        get_address_mapper(revision::jpn2).map_address(BaseAddr);
    static constexpr std::uint32_t kor_addr =
        get_address_mapper(revision::kor).map_address(BaseAddr);
    static constexpr std::uint32_t twn_addr =
        get_address_mapper(revision::twn).map_address(BaseAddr);
    static constexpr std::uint32_t chn_addr =
        get_address_mapper(revision::chn_shield).map_address(BaseAddr);
#elif is_mkw
    static constexpr std::uint32_t usa_addr =
        get_address_mapper(revision::usa).map_address(BaseAddr);
    static constexpr std::uint32_t jpn_addr =
        get_address_mapper(revision::jpn).map_address(BaseAddr);
    static constexpr std::uint32_t kor_addr =
        get_address_mapper(revision::kor).map_address(BaseAddr);
#endif

    switch (r) {
#if is_nsmbw
    case revision::pal1:
        return BaseAddr;
    case revision::pal2:
        return pal2_addr;
    case revision::usa1:
        return usa1_addr;
    case revision::usa2:
        return usa2_addr;
    case revision::jpn1:
        return jpn1_addr;
    case revision::jpn2:
        return jpn2_addr;
    case revision::kor:
        return kor_addr;
    case revision::twn:
        return twn_addr;
    case revision::chn_shield:
        return chn_addr;
#elif is_mkw
    case revision::pal:
        return BaseAddr;
    case revision::usa:
        return usa_addr;
    case revision::jpn:
        return jpn_addr;
    case revision::kor:
        return kor_addr;
#endif

    default:
        __builtin_unreachable();
    }
}

// Some tests
#if !defined(CLANGD) && is_nsmbw
static_assert(get_address_mapper(revision::pal2).map_address(0x8005EA6A) == 0x8005EA6A);
static_assert(get_address_mapper(revision::usa1).map_address(0x8010F234) == 0x8010F100);
static_assert(get_address_mapper(revision::usa1).map_address(0x800CF6F8) == 0x800CF608);
static_assert(get_address_mapper(revision::usa2).map_address(0x800CF6F8) == 0x800CF610);
static_assert(get_address_mapper(revision::jpn1).map_address(0x80779C1C) == 0x80779AEC);
static_assert(get_address_mapper(revision::twn).map_address(0x800B34D0) == 0x800B3650);
#endif

} // namespace slu
