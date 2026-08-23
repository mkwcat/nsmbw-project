// SndObjectEnemy.cpp
// NSMBW .text: 0x80197790 - 0x80198CF0

#include "SndObjectEnemy.h"

/* VT+0x08 0x800984B0 - Moved here */
SndObjctEmy::~SndObjctEmy() {}

/* VT+0x24 */
[[nsmbw(0x80197790)]]
nw4r::snd::SoundHandle* SndObjctEmy::startSound(u32 soundId, u32 remoteMask);

/* VT+0x28 */
[[nsmbw(0x801978E0)]]
nw4r::snd::SoundHandle* SndObjctEmy::holdSound(u32 soundId, u32 remoteMask);

/* VT+0x30 */
[[nsmbw(0x80197A30)]]
nw4r::snd::SoundHandle* SndObjctEmy::startSound(u32 soundId, short seqParam, u32 remoteMask);

/* VT+0x34 */
[[nsmbw(0x80197BB0)]]
nw4r::snd::SoundHandle* SndObjctEmy::holdSound(u32 soundId, short seqParam, u32 remoteMask);

/* VT+0x38 */
[[nsmbw(0x80197D30)]]
nw4r::snd::SoundHandle*
SndObjctEmy::startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x3C */
[[nsmbw(0x80197E20)]]
nw4r::snd::SoundHandle*
SndObjctEmy::holdSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x08 0x80069AE0 - Moved here */
SndObjctCmnEmy::~SndObjctCmnEmy() {}

/* VT+0x20 */
[[nsmbw(0x80198040)]]
nw4r::snd::SoundHandle*
SndObjctCmnEmy::startSound(u32 soundId, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x24 */
[[nsmbw(0x801983D0)]]
nw4r::snd::SoundHandle* SndObjctCmnEmy::startSound(
    u32 soundId, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
);

/* VT+0x2C */
[[nsmbw(0x801987A0)]]
nw4r::snd::SoundHandle*
SndObjctCmnEmy::holdSound(u32 soundId, int, const nw4r::math::VEC2& position, u32 remoteMask);

/* VT+0x30 */
[[nsmbw(0x801989B0)]]
nw4r::snd::SoundHandle* SndObjctCmnEmy::holdSound(
    u32 soundId, int, const nw4r::math::VEC2& position, short seqParam, u32 remoteMask
);
