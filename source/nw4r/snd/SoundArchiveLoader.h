#pragma once

#include "SoundArchive.h"
#include <revolution/os/OSMutex.h>

namespace nw4r::snd {

class SoundMemoryAllocatable;

namespace detail {

class SoundArchiveLoader {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80277210 */
    void*
    LoadGroup(u32 id, SoundMemoryAllocatable* pAllocatable, void** ppWaveBuffer, u32 blockSize);

private:
    /* 0x80277210 */
    void* LoadGroupInternal(
        u32 id, SoundMemoryAllocatable* pAllocatable, void** ppWaveBuffer, u32 blockSize
    );

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ OSMutex             mMutex;
    /* 0x18 */ const SoundArchive* mArc;
};

} // namespace detail

} // namespace nw4r::snd
