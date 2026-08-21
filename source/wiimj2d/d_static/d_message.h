#pragma once

namespace EGG
{
class Heap;
}

class MsgRes_c;

class dMessage_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x800CDB60 */
    dMessage_c();

    /* 0x800CDBA0 */
    ~dMessage_c();

    /* 0x800CDC20 */
    static bool create(EGG::Heap* heap);

    /* 0x800CDCE0 */
    void buildMsgRes(EGG::Heap* heap);

    /* 0x800CDD30 */
    static wchar_t* getMsg(u32 upper, u32 lower);

    /* 0x800CDD50 */
    static MsgRes_c* getMesRes();

    /* 0x800CDD60 @unofficial */
    static void itoa(int i, wchar_t* buffer, u32 buffer_size, int max_num_chars, int = 0);

    /* 0x800CDEA0 @unofficial */
    static void itoaCustom(int i, wchar_t* buffer, u32 buffer_size, int max_num_chars, int = 0);

    /* 0x800CDEE0 @unofficial */
    static void toCustomFont(wchar_t* ws);
};
