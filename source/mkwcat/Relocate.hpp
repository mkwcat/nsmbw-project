//
//  mkwcat/Relocate.hpp
//  nsmbw-project
//

#pragma once

#include "BaseTypes.hpp"
#include "Macro.hpp"
#include "Port.hpp"
#include <revolution/os/OSLink.h>

namespace mkwcat::Relocate
{

struct Reference {
    consteval Reference()
      : type(0)
      , addend(0)
      , address(nullptr)
    {
    }

    consteval Reference(u32 _addrP1, u8 _type, u16 _addend = 0)
      : type(_type)
      , addend(_addend)
      , address(&mkwcat::PortRegion[_addrP1])
    {
    }

    u8 type;
    u16 addend;
    void* address;
};

template <u32 N>
struct Entry {
    constexpr Entry(u32 offset, const Reference (&_references)[N])
    {
        dest.offset = offset;
        for (unsigned i = 0; i < N; i++) {
            references[i] = _references[i];
        }
    }

    constexpr Entry(const void* const& addr, const Reference (&_references)[N])
    {
        dest.addr = addr;
        for (unsigned i = 0; i < N; i++) {
            references[i] = _references[i];
        }
    }

    union {
        const void* addr;
        u32 offset;
    } dest;

    u32 count = N;

    Reference references[N];
};

#define __PATCH_REFERENCES_EVAL(_COUNTER, _DEST, ...)                                              \
    SECTION("patch_references_array")                                                              \
    [[__gnu__::__used__]] static constinit ::mkwcat::Relocate::Entry __RelocateEntry_##_COUNTER =  \
      {_DEST, __VA_ARGS__};
#define __PATCH_REFERENCES(_COUNTER, _DEST, ...)                                                   \
    __PATCH_REFERENCES_EVAL(_COUNTER, _DEST, __VA_ARGS__)

#define PATCH_REFERENCES(_DEST, ...) __PATCH_REFERENCES(__COUNTER__, _DEST, __VA_ARGS__)

} // namespace mkwcat::Relocate
