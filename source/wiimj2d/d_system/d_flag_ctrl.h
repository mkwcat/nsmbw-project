#pragma once

class dFlagCtrl_c {
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800B0FD0 */
    u16 getFlagData(u16 courseNum, float x, float y);

    /* 0x800B1100 */
    void setFlagData(u16 courseNum, float x, float y, u16 data);

public:
    // Static Variables

    /* 0x8042A210 */ static dFlagCtrl_c* m_instance;
};
