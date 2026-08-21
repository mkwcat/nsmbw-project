#pragma once

class dFader_c
{
public:
    // Constants and Types
    // ^^^^^^

    enum class fader_type_e {
        FADE = 0,
        CIRCLE = 1,
        BOWSER = 2,
        WAVY = 3,
        MARIO = 4,
        UNKNOWN_5 = 5,
        NONE = 6,
    };

public:
    // Static Methods
    // ^^^^^^

    /* 0x800B0DB0 */
    static bool setFader(fader_type_e faderType);
};
