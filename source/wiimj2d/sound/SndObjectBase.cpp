// SndObjectBase.cpp
// NSMBW: 0x80197440 - 0x80197790

#include "SndObjectBase.h"

[[nsmbw(0x80197440)]]
NMSndObjectBase::NMSndObjectBase(
    OBJ_TYPE objType, nw4r::snd::SoundArchivePlayer& soundArchivePlayer
);

/* VT+0x08 */
[[nsmbw(0x801974C0)]]
NMSndObjectBase::~NMSndObjectBase();

/* VT+0x1C */
[[nsmbw(0x801976B0)]] s8 NMSndObjectBase::VT_0x1C(s32 param1, s32 param2);
