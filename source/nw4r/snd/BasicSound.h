#pragma once


namespace nw4r::snd
{

struct SoundParam;

}

namespace nw4r::snd::detail
{

class BasicSound
{
    friend class SoundHandle;

public:
    // Constants and Types
    // ^^^^^^

    struct AmbientParamUpdateCallback {
        enum ParamUpdateFlags {
            PARAM_UPDATE_VOLUME = 0_bit,
            PARAM_UPDATE_PAN = 1_bit,
            PARAM_UPDATE_SURROUND_PAN = 2_bit,
            PARAM_UPDATE_PRIORITY = 3_bit,
        };

        virtual void detail_Update(
          SoundParam* pParam, u32 id, BasicSound* pSound, const void* pArg, u32 flags
        ) = 0;
    };

    struct AmbientArgUpdateCallback {
        virtual void detail_Update(void* pArg, const BasicSound* pSound) = 0;
    };

    struct AmbientArgAllocaterCallback {
        virtual void* detail_AllocAmbientArg(u32 size) = 0;

        virtual void detail_FreeAmbientArg(void* pArg, const BasicSound* pSound) = 0;
    };

    struct AmbientArgInfo {
        SIZE_ASSERT(0x14);

        /* 0x00 */ AmbientParamUpdateCallback* paramUpdateCallback;
        /* 0x04 */ AmbientArgUpdateCallback* argUpdateCallback;
        /* 0x08 */ AmbientArgAllocaterCallback* argAllocaterCallback;
        /* 0x0C */ void* arg;
        /* 0x10 */ u32 argSize;
    };

    static constexpr u32 INVALID_ID = 0xFFFFFFFF;
    static constexpr int PRIORITY_MAX = 127;

public:
    // Instance Methods
    // ^^^^^^

    [[nsmbw(0x80267560)]]
    void SetVolume(f32 volume, int);

    [[nsmbw(0x802675F0)]]
    void SetPitch(f32 pitch);
};

} // namespace nw4r::snd::detail
