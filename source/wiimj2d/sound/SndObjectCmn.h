#pragma once

#include "SndObjectBase.h"
#include <nw4r/math/vec.h>
#include <nw4r/snd/SoundHandle.h>

template <int TParam>
class NMSndObjectCmn : public NMSndObjectBase {
    SIZE_ASSERT(0x17C);

public:
    // Structors
    // ^^^^^^

    NMSndObjectCmn(
        nw4r::snd::SoundArchivePlayer& soundArchivePlayer
    )
        : NMSndObjectBase(OBJ_TYPE::TYPE_1, soundArchivePlayer) {
        mNumHandles = 14;
    }

public:
    // Constants and Types
    // ^^^^^^

    /* @unofficial */
    class SoundHandlePrm : public nw4r::snd::SoundHandle {
        SIZE_ASSERT(0x14);

    public:
        // Structors
        // ^^^^^^

        /* [0x800699D0 with TParam = 12] */
        SoundHandlePrm()
            : nw4r::snd::SoundHandle()
            , m0x04(-1)
            , m0x0C(1.0)
            , m0x10(64) {}

        /* [0x80069A00 with TParam = 12] */
        ~SoundHandlePrm() {}

    public:
        // Instance Variables
        // ^^^^^^

        /* 0x04 */ s32 m0x04;
        /* 0x08 */ s32 m0x08;
        /* 0x0C */ f32 m0x0C;
        /* 0x10 */ s32 m0x10;
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x20 [0x8006B330 with TParam = 12] */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

    /* VT+0x24 [0x8006B6C0 with TParam = 12] */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask);

    /* VT+0x28 [0x8006BA90 with TParam = 12] */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

    /* VT+0x2C [0x8006BBA0 with TParam = 12] */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, int, const nw4r::math::VEC2& position, u32 remoteMask);

    /* VT+0x30 [0x8006BDB0 with TParam = 12] */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, int, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask);

public:
    // Instance Variables
    // ^^^^^^
    SoundHandlePrm maHandles[14];
};

// Template Specializations
// ^^^^^^

/* VT+0x20 */
template <>
[[nsmbw(0x8006B330)]]
nw4r::snd::SoundHandle*
NMSndObjectCmn<12>::startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x24 */
template <>
[[nsmbw(0x8006B6C0)]]
nw4r::snd::SoundHandle* NMSndObjectCmn<12>::startSound(
    u32 soundId, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
);

/* VT+0x28 */
template <>
[[nsmbw(0x8006BA90)]]
nw4r::snd::SoundHandle*
NMSndObjectCmn<12>::holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x2C */
template <>
[[nsmbw(0x8006BBA0)]]
nw4r::snd::SoundHandle*
NMSndObjectCmn<12>::holdSound(u32 soundId, int, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x30 */
template <>
[[nsmbw(0x8006BDB0)]]
nw4r::snd::SoundHandle* NMSndObjectCmn<12>::holdSound(
    u32 soundId, int, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
);
