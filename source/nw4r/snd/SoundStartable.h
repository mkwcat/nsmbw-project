#pragma once

namespace nw4r::snd
{

class SoundHandle;

namespace detail
{

class ExternalSoundPlayer;

} // namespace detail

class SoundStartable
{
public:
    // Constants and Types
    // ^^^^^^

    enum class StartResult {
        START_SUCCESS,
        START_ERR_LOW_PRIORITY,
        START_ERR_INVALID_LABEL_STRING,
        START_ERR_INVALID_SOUNDID,
        START_ERR_NOT_DATA_LOADED,
        START_ERR_NOT_ENOUGH_PLAYER_HEAP,
        START_ERR_CANNOT_OPEN_FILE,
        START_ERR_NOT_AVAILABLE,
        START_ERR_CANNOT_ALLOCATE_TRACK,
        START_ERR_NOT_ENOUGH_INSTANCE,
        START_ERR_INVALID_PARAMETER,
        START_ERR_INVALID_SEQ_START_LOCATION_LABEL,

        START_ERR_USER = 128,
        START_ERR_UNKNOWN = 255,
    };

    struct StartInfo {
        SIZE_ASSERT(0x18);

        enum class EnableFlag {
            ENABLE_START_OFFSET = 0_bit,
            ENABLE_PLAYER_ID = 1_bit,
            ENABLE_PLAYER_PRIORITY = 2_bit
        };

        enum class StartOffsetType {
            START_OFFSET_TYPE_MILLISEC,
            START_OFFSET_TYPE_TICK,
            START_OFFSET_TYPE_SAMPLE
        };

        /* 0x00 */ u32 enableFlag;
        /* 0x04 */ StartOffsetType startOffsetType;
        /* 0x08 */ int startOffset;
        /* 0x0C */ u32 playerId;
        /* 0x10 */ int playerPriority;
        /* 0x14 */ int voiceOutCount;
    };

public:
    // Structors
    // ^^^^^^

    /* VT+0x08 */
    virtual ~SoundStartable();

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C */
    virtual StartResult
    detail_SetupSound(SoundHandle* pHandle, u32 id, bool hold, const StartInfo* pStartInfo) = 0;

    /* VT+0x10 */
    virtual u32 detail_ConvertLabelStringToSoundId(const char* pLabel) = 0;
};

} // namespace nw4r::snd
