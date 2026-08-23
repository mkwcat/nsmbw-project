#pragma once

#include "Common.h"

namespace nw4r::ut {

class FileStream;

}

namespace nw4r::snd {

enum class SoundType {
    SOUND_TYPE_INVALID,
    SOUND_TYPE_SEQ,
    SOUND_TYPE_STRM,
    SOUND_TYPE_WAVE,
};

class SoundArchive {
public:
    // Structors
    // ^^^^^^

    SoundArchive();

    /* VT+0x08 */
    virtual ~SoundArchive();

public:
    // Constants and Types
    // ^^^^^^

    struct SoundInfo {
        SIZE_ASSERT(0x1C);
        /* 0x00 */ u32              fileId;
        /* 0x04 */ u32              playerId;
        /* 0x08 */ int              playerPriority;
        /* 0x0C */ int              volume;
        /* 0x10 */ int              remoteFilter;
        /* 0x14 */ detail::PanMode  panMode;
        /* 0x18 */ detail::PanCurve panCurve;
    };

    struct SeqSoundInfo {
        SIZE_ASSERT(0x14);
        /* 0x00 */ u32  dataOffset;
        /* 0x04 */ u32  bankId;
        /* 0x08 */ u32  allocTrack;
        /* 0x0C */ int  channelPriority;
        /* 0x10 */ bool releasePriorityFixFlag;
    };

    struct BankInfo {
        SIZE_ASSERT(0x4);
        /* 0x0 */ u32 fileId;
    };

    struct PlayerInfo {
        SIZE_ASSERT(0x8);
        /* 0x0 */ int playableSoundCount;
        /* 0x4 */ u32 heapSize;
    };

    struct GroupInfo {
        SIZE_ASSERT(0x18);
        /* 0x00 */ u32         itemCount;
        /* 0x04 */ const char* extFilePath;
        /* 0x08 */ u32         offset;
        /* 0x0C */ u32         size;
        /* 0x10 */ u32         waveDataOffset;
        /* 0x14 */ u32         waveDataSize;
    };

    struct GroupItemInfo {
        SIZE_ASSERT(0x14);
        /* 0x00 */ u32 fileId;
        /* 0x04 */ u32 offset;
        /* 0x08 */ u32 size;
        /* 0x0C */ u32 waveDataOffset;
        /* 0x10 */ u32 waveDataSize;
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C */
    virtual const void* detail_GetFileAddress(u32 id) const         = 0;

    /* VT+0x10 */
    virtual const void* detail_GetWaveDataFileAddress(u32 id) const = 0;

    /* VT+0x14 */
    virtual int detail_GetRequiredStreamBufferSize() const          = 0;

    /* VT+0x18 */
    virtual ut::FileStream*
    OpenStream(void* pBuffer, int bufferSize, u32 offset, u32 length) const = 0;

    /* VT+0x1C */
    virtual ut::FileStream* OpenExtStream(
        void* pBuffer, int bufferSize, const char* pExtPath, u32 offset, u32 length
    ) const = 0;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80275860 */
    const char* GetSoundLabelString(u32 id) const;

    /* 0x80275870 */
    u32 ConvertLabelStringToSoundId(const char* pLabel) const;

    /* 0x80275880 */
    u32 ConvertLabelStringToPlayerId(const char* pLabel) const;

    /* 0x80275890 */
    u32 ConvertLabelStringToGroupId(const char* pLabel) const;
};

} // namespace nw4r::snd
