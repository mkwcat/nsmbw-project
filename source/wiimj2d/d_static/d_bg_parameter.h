#pragma once

class dBgParameter_c
{
public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x38);

    /* 0x38 */ f32 mScreenLeft;
    /* 0x3C */ f32 mScreenTop;
    /* 0x40 */ f32 mScreenWidth;
    /* 0x44 */ f32 mScreenHeight;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A0E0 */ static dBgParameter_c* ms_Instance_p;
};
