#pragma once

namespace EGG {

class AudioRmtSpeaker {
public:
    // Static Methods
    // ^^^^^^

    [[nsmbw(0x802D6D50)]]
    static void setup(s32 channel, void (*)(s32, s32));
};

} // namespace EGG
