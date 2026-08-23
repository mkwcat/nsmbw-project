#pragma once

class dRotShake_c {
    SIZE_ASSERT(0x14);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x00 */ short m_angle0;
    /* 0x02 */ short m_angle1;
    /* 0x04 */ short m_angle2;
    /* 0x06 */ short m_angle3;
    /* 0x08 */ short m_angle4;
    /* 0x0A */ short m_angle5;
    /* 0x0C */ short m_angle6;
    /* 0x0E */ short m_angle7;
    /* 0x10 */ int   m_0x10;
};
