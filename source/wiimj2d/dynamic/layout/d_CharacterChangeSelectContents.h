#pragma once

#include "System.h"
#include <dynamic/d_base.h>
#include <dynamic/d_lytbase.h>
#include <nw4r/lyt/Pane.h>
#include <state/s_State.h>
#include "d_CharacterChangeSelectBase.h"

class dCharacterChangeSelectContents_c : public dBase_c
{
public:
    //
    // Functions
    //

    /* 0x80772A80 */
    dCharacterChangeSelectContents_c();

    /* 0x80772E30 */
    bool createLayout();

    void setMarioIconVisible(u32 param_2);

    /* 0x80773220 */
    void UNDEF_80773220();

    //
    // Member Data
    //
    OFFSET_ASSERT(0x070);

    /* 0x070 */ LytBase_c mLayout;

    FILL(0x208, 0x248);

    /* 0x248 */ nw4r::lyt::Pane* mpRootPane;

    /* 0x24C */ nw4r::lyt::Pane* mpaSelectConPane[2];
    /* 0x254 */ nw4r::lyt::Picture* mpaPictures[8];
    /* 0x274 */ LytTextBox_c* mpaTextBoxes[4];

    u32 m0x284; // Set to m0x288 in create
    u32 m0x288;
    dCharacterChangeSelectBase_c::Icon_e m0x28C; // Set 6 in create
    dCharacterChangeSelectBase_c::Icon_e m0x290; // Set 6 in create
    dCharacterChangeSelectBase_c::Icon_e m0x294; // Set 6 in create
    dCharacterChangeSelectBase_c::Icon_e m0x298; // Set 2 in create

    u8 m0x29C; // Set 1 in create
    u8 m0x29D; // Set 0 in create
    u8 m0x29E; // Set 0 in create
    u8 m0x29F; // Set 0 in create
    u8 m0x2A0; // Set 0 in create

    /* 0x2A4 */ u32 mLives[4];

    /* 0x2B4 */ float m0x2B4;

    //
    // Added Member Data
    //
    OFFSET_ASSERT(0x2B8);

    /* 0x2B8 */ nw4r::lyt::Picture* mpaMarioPictures[2];

    //
    // State IDs
    //

    sState_Extern(0x80990E60, dCharacterChangeSelectContents_c, OnStageWait);
    sState_Extern(0x80990EA0, dCharacterChangeSelectContents_c, AnimeWait);
    sState_Extern(0x80990EE0, dCharacterChangeSelectContents_c, HitAnimeEndWait);
};