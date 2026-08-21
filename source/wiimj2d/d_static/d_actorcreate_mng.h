#pragma once

class dActorCreateMng_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80068620 @unofficial */
    void execute();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x000, 0xBC8);

    /* 0xBC8 */ s16 m0xBC8;
    /* 0xBC9 */ bool m0xBC9;
    /* 0xBCA */ bool mIsEndingDemo;
    /* 0xBCB */ bool m_stopped;

    FILL(0xBCC, 0xBDC);

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A028 */ static dActorCreateMng_c* m_instance;
};
