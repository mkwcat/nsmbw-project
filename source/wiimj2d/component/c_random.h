#pragma once

class cRandom_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x801615A0 */ u32 getRandomByAsm(u32 limit = -1);
    /* 0x801615D0 */ float getRandomFByAsm();
    /* 0x80161620 */ float getRandomF2ByAsm();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x0 */ u32 mSeed;
};
