#pragma once

#include "SndObject.h"
#include "SndObjectCmn.h"
#include "m_vec.h"

class SndObjctEmy : public NMSndObject<4> {
    SIZE_ASSERT(0xAC);

    /* 0x00 VTABLE 0x8032E380 */

public:
    // Structors
    // ^^^^^^

    SndObjctEmy(
        nw4r::snd::SoundArchivePlayer& soundArchivePlayer
    )
        : NMSndObject<4>(soundArchivePlayer) {}

    /* VT+0x08 0x800984B0 */
    virtual ~SndObjctEmy() override;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x24 0x80197790 */
    virtual nw4r::snd::SoundHandle* startSound(u32 soundId, u32 remoteMask) override;

    /* VT+0x28 0x801978E0 */
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, u32 remoteMask) override;

    /* VT+0x30 0x80197A30 */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, short seqParam, u32 remoteMask) override;

    /* VT+0x34 0x80197BB0 */
    virtual nw4r::snd::SoundHandle* holdSound(u32 soundId, short seqParam, u32 remoteMask) override;

    /* VT+0x38 0x80197D30 */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) override;

    /* VT+0x3C 0x80197E20 */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) override;
};

class SndObjctCmnEmy : public NMSndObjectCmn<12> {
    SIZE_ASSERT(0x17C);

    /* 0x00 VTABLE 0x8032E348 */

public:
    // Structors
    // ^^^^^^

    SndObjctCmnEmy(
        nw4r::snd::SoundArchivePlayer& soundArchivePlayer
    )
        : NMSndObjectCmn<12>(soundArchivePlayer) {}

    /* VT+0x08 0x80069AE0 */
    virtual ~SndObjctCmnEmy() override;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x20 0x80198040 */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) override;

    /* VT+0x24 0x801983D0 */
    virtual nw4r::snd::SoundHandle* startSound(
        u32 soundId, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
    ) override;

    /* VT+0x2C 0x801987A0 */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, int, const nw4r::math::VEC2& position, u32 remoteMask) override;

    /* VT+0x30 0x801989B0 */
    virtual nw4r::snd::SoundHandle* holdSound(
        u32 soundId, int, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
    ) override;
};
