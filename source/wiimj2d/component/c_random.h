#pragma once

// @unofficial
class cRnd_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x801615A0 */
    u32 next(u32 limit = -1);

    // +++
    float nextFloat()
    {
        return static_cast<float>(next() & 0xFFFFFF) / static_cast<float>(0xFFFFFF);
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x0 */ u32 mSeed;
};