#pragma once

#include <nw4r/lyt/TextBox.h>

class MsgRes_c;

class LytTextBox_c : public nw4r::lyt::TextBox
{
public:
    /* 0x800C9B50 */
    void setMessage(MsgRes_c* msgRes, u32 msgSect, u32 msg, s32, ...);
};
