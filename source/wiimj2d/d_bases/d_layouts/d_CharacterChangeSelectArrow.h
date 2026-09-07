#pragma once

#include "d_base.h"
#include "d_lytbase.h"
#include "s_State.h"
#include <nw4r/lyt/Pane.h>

class dCharacterChangeSelectArrow_c : public dBase_c {
    SIZE_ASSERT(0x26D);
    VTABLE(0x060, fBase_c, 0x8093E588);
    // 0x8093E448 g_profile_CHARACTER_CHANGE_SELECT_ARROW
    // 0x8076DEE0 dCharacterChangeSelectArrow_c_classInit

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x244);

    /* 0x244 */ nw4r::lyt::Pane* mp0x244;

    FILL(0x248, 0x258);

    /* 0x258 */ int mMoveDir;

    FILL(0x25C, 0x264);

    /* 0x264 */ int  mOption;

    /* 0x268 */ bool m0x268;
    /* 0x269 */ bool m0x269;
    /* 0x26A */ bool m0x26A;
    /* 0x26B */ bool m0x26B;
    /* 0x26C */ bool m0x26C;

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x8076E5D0
     * executeState:    0x8076E600
     * finalizeState:   0x8076E680
     */
    sState_Extern(0x80990818, dCharacterChangeSelectArrow_c, OnStageWait);

    /*
     * initializeState: 0x8076E690
     * executeState:    0x8076E770
     * finalizeState:   0x8076E810
     */
    sState_Extern(0x80990858, dCharacterChangeSelectArrow_c, OnStageAnimeEndWait);

    /*
     * initializeState: 0x8076E890
     * executeState:    0x8076E8F0
     * finalizeState:   0x8076E970
     */
    sState_Extern(0x80990898, dCharacterChangeSelectArrow_c, ExitWait);

    /*
     * initializeState: 0x8076E980
     * executeState:    0x8076EA00
     * finalizeState:   0x8076EB70
     */
    sState_Extern(0x809908D8, dCharacterChangeSelectArrow_c, HitAnimeEndWait);

    /*
     * initializeState: 0x8076EB80
     * executeState:    0x8076EC10
     * finalizeState:   0x8076EC70
     */
    sState_Extern(0x80990918, dCharacterChangeSelectArrow_c, ExitAnimeEndWait);
};
