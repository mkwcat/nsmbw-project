#pragma once

class PauseManager_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800D0C10 */
    void setPauseEnable(bool enable);

    /* 0x800D1350 */
    void setPause();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x00, 0x1D);

    /* 0x1D */ bool m_ForbidPause;

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A2B8 */ static PauseManager_c* m_instance;

    /* 0x8042A2C2 */ static bool m_OtasukeAfter;
};
