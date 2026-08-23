#pragma once

#include "d_static/d_base.h"
#include "d_static/d_lyt/d_lytbase.h"
#include "state/s_State.h"
#include <nw4r/lyt/Pane.h>

class dCharacterChangeSelectArrow_c : public dBase_c
{
public:
    sState_Extern(0x80990818, dCharacterChangeSelectArrow_c, OnStageWait);
    sState_Extern(0x80990858, dCharacterChangeSelectArrow_c, OnStageAnimeEndWait);
    sState_Extern(0x80990898, dCharacterChangeSelectArrow_c, ExitWait);
    sState_Extern(0x809908D8, dCharacterChangeSelectArrow_c, HitAnimeEndWait);
    sState_Extern(0x80990918, dCharacterChangeSelectArrow_c, ExitAnimeEndWait);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x244);

    /* 0x244 */ nw4r::lyt::Pane* mp0x244;

    FILL(0x248, 0x258);

    /* 0x258 */ int mMoveDir;

    FILL(0x25C, 0x264);

    /* 0x264 */ int mOption;

    /* 0x268 */ bool m0x268;
    /* 0x269 */ bool m0x269;
    /* 0x26A */ bool m0x26A;
    /* 0x26B */ bool m0x26B;
    /* 0x26C */ bool m0x26C;
};
