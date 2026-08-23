#pragma once

#include "d_base.h"
#include "s_State.h"

class dGameOver_c : public dBase_c
{

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80992B00, dGameOver_c, ExitAnimeEndWait);
};
