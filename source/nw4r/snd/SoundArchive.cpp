// snd_SoundArchive.cpp
// NSMBW .text: 0x80275780 - 0x80275E80

#include "SoundArchive.h"

namespace nw4r::snd {

[[nsmbw(0x80275860)]]
const char* SoundArchive::GetSoundLabelString(u32 id) const;

[[nsmbw(0x80275870)]]
u32 SoundArchive::ConvertLabelStringToSoundId(const char* pLabel) const;

[[nsmbw(0x80275880)]]
u32 SoundArchive::ConvertLabelStringToPlayerId(const char* pLabel) const;

[[nsmbw(0x80275890)]]
u32 SoundArchive::ConvertLabelStringToGroupId(const char* pLabel) const;

} // namespace nw4r::snd
