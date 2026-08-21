#pragma once

class daBossDemo_c;

class dActorMng_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x80066540 */
    bool envAllWaterCheck();

    /* 0x80066EC0 */
    void finalUpdate();

    /* 0x80066F70 */
    void execute();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x18);

    /* 0x18 */ daBossDemo_c* mpBossDemo;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A020 */ static dActorMng_c* m_instance;
};
