#pragma once

#include "SndObjectCmn.h"

class SndObjctCmnMap : public NMSndObjectCmn<12> {
public:
    // Structors
    // ^^^^^^

    SndObjctCmnMap(
        nw4r::snd::SoundArchivePlayer& soundArchivePlayer
    )
        : NMSndObjectCmn<12>(soundArchivePlayer) {}

    /* VT+0x08 0x80198CF0 */
    virtual ~SndObjctCmnMap() override;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x20 0x80198D70 */
    virtual nw4r::snd::SoundHandle*
    startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask) override;

    /* VT+0x24 0x80199100 */
    virtual nw4r::snd::SoundHandle* startSound(
        u32 soundId, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
    ) override;

    /* VT+0x2C 0x801994D0 */
    virtual nw4r::snd::SoundHandle*
    holdSound(u32 soundId, int, const nw4r::math::VEC2& position, u32 remoteMask) override;

    /* VT+0x30 0x801996E0 */
    virtual nw4r::snd::SoundHandle* holdSound(
        u32 soundId, int, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
    ) override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80199950 */
    void stopSound(u32 soundId);
};
