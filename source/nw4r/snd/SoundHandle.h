#pragma once

#include "BasicSound.h"

namespace nw4r::snd {

class SoundHandle {
    SIZE_ASSERT(0x4);

public:
    // Structors
    // ^^^^^^

    SoundHandle()
        : mpSound(nullptr) {}

    ~SoundHandle() { DetachSound(); }

public:
    // Instance Methods
    // ^^^^^^

    [[nsmbw(0x8027A340)]]
    void DetachSound();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x0 */ detail::BasicSound* mpSound;
};

} // namespace nw4r::snd
