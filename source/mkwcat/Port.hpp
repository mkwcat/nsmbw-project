#pragma once

#include <cstddef>

namespace mkwcat
{

extern char PortRegion[0xFFFFFFFF];

template <std::size_t Address>
constexpr void* Port()
{
    constexpr void* address = &PortRegion[Address];
    return address;
}

} // namespace mkwcat