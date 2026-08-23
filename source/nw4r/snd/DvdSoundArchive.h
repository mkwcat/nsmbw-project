#pragma once

#include "SoundArchive.h"

namespace nw4r::snd {

class DvdSoundArchive : public SoundArchive {
public:
    // Structors
    // ^^^^^^

    DvdSoundArchive();

    /* VT+0x08 */
    virtual ~DvdSoundArchive() override;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C 0x80269730 */
    virtual const void* detail_GetFileAddress(u32 id) const override;

    /* VT+0x10 0x80269720 */
    virtual const void* detail_GetWaveDataFileAddress(u32 id) const override;

    /* VT+0x18 */
    virtual ut::FileStream*
    OpenStream(void* pBuffer, int bufferSize, u32 offset, u32 length) const override;

    /* VT+0x1C */
    virtual ut::FileStream* OpenExtStream(
        void* pBuffer, int bufferSize, const char* pExtPath, u32 offset, u32 length
    ) const override;

public:
    // Static Methods
    // ^^^^^^

    static u32 RegisterTmpFile(const void* pFile, const void* pWaveDataFile);
};

} // namespace nw4r::snd
