#pragma once

namespace Util {

class dDisp_c {
    SIZE_ASSERT(0xC);
    VTABLE(0x0, dDisp_c, 0x8031B4C0);

public:
    // Structors
    // ^^^^^^

    /* 0x800E7CB0 */
    dDisp_c();

    /* VT+0x8 0x800E7D80 */
    virtual ~dDisp_c();

private:
    // Instance Variables
    // ^^^^^^

    /* 0x4, 0x8 */ float x, y;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800E7EF0 */
    void setSizeY(float);

    /* 0x800E7F30 */
    float getSizeY();

    /* 0x800E7F40 */
    float getSizeX();

    /* 0x800E7F50 */
    float getPosX();

    /* 0x800E7F60 */
    bool chaseBaseX(float, float);

    /* 0x800E7FE0 */
    void setBaseX(float);

    /* 0x800E7FF0 */
    float getBaseX();

    /* 0x800E8030 */
    void resetBaseX();

    /* 0x800E8090 */
    float getOrgX();

    /* 0x800E80A0 */
    bool chaseOfsX(float, float);

    /* 0x800E8120 */
    void setOfsX(float);

    /* 0x800E8130 */
    float getOfsX();

    /* 0x800E8140 */
    bool chaseBaseY(float, float);

    /* 0x800E81C0 */
    float getPosY();

    /* 0x800E81D0 */
    void setBaseY(float);

    /* 0x800E81E0 */
    float getBaseY();

    /* 0x800E8220 */
    void setOfsY(float);

    /* 0x800E8230 */
    float getOfsY();
};

} // namespace Util
