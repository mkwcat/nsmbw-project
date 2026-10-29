//
//  slu/port.hpp
//  supplemental-language-utilities
//

#pragma once

#include <cstddef>

namespace slu {

extern char port_region[0xFFFFFFFF];

template <std::size_t Address> constexpr void* port() {
    constexpr void* address = &port_region[Address];
    return address;
}

} // namespace slu
