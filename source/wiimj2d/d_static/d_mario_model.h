#pragma once

#include "d_player_model.h"

class dMarioMdl_c : public dPlayerMdl_c
{
    SIZE_ASSERT(0x874);

public:
    [[nsmbw(0x800CA150)]]
    dMarioMdl_c(u8 index);

    FILL(0x824, 0x874);
};