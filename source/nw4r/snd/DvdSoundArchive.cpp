// snd_DvdSoundArchive.cpp
// NSMBW .text: 0x80269130 - 0x802697A0

#include "DvdSoundArchive.h"

namespace nw4r::snd {

constexpr u32 TMP_REPLACE_FILE         = 1000;

const void*   s_tmpReplaceFile         = nullptr;
const void*   s_tmpReplaceWaveDataFile = nullptr;

u32 DvdSoundArchive::RegisterTmpFile(
    const void* pFile, const void* pWaveDataFile
) {
    s_tmpReplaceFile         = pFile;
    s_tmpReplaceWaveDataFile = pWaveDataFile;

    return TMP_REPLACE_FILE;
}

/* VT+0x10 */
[[nsmbw(0x80269720)]]
const void* DvdSoundArchive::detail_GetWaveDataFileAddress(
    u32 id
) const {
    if (id != TMP_REPLACE_FILE) {
        return nullptr;
    }

    return s_tmpReplaceWaveDataFile;
}

/* VT+0x0C */
[[nsmbw(0x80269730)]]
const void* DvdSoundArchive::detail_GetFileAddress(
    u32 id
) const {
    if (id != TMP_REPLACE_FILE) {
        return nullptr;
    }

    return s_tmpReplaceFile;
}

} // namespace nw4r::snd
