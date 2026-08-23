// snd_SoundArchiveLoader.cpp
// NSMBW .text: 0x80277190 - 0x802777F0

#include "SoundArchiveLoader.h"

#include <revolution/os.h>

namespace nw4r::snd::detail {

[[nsmbw(0x80277210)]]
void* SoundArchiveLoader::LoadGroup(
    u32 id, SoundMemoryAllocatable* pAllocatable, void** ppWaveBuffer, u32 blockSize
);

} // namespace nw4r::snd::detail
