#pragma once

namespace EGG
{
class Heap;
}

class MsgRes_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800CE7F0 */
    MsgRes_c(const void*, EGG::Heap*);

    /* 0x800CE830 */
    ~MsgRes_c();

    /* 0x800CE890 */
    void getScale(u32, u32);

    /* 0x800CE8C0 */
    void getFont(u32, u32);
};
