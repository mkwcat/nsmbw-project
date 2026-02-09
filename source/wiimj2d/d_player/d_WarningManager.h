#pragma once

class dWarningManager_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8010E710 */
    void onControllerCut(int player);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x000, 0xB8D);

    /* 0xB8D */ bool m0xB8D;
    /* 0xB8E */ bool m0xB8E;

public:
    // Static Methods
    // ^^^^^^

    // Normally inline
    [[nsmbw(0x800B3B20)]]
    static bool isWarning();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A5B8 */ static dWarningManager_c* m_instance;
    /* 0x8042A5C0 */ static s32 m_WarningForbid;
};
