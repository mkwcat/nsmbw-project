#pragma once

#include "d_CharacterChangeSelectBase.h"
#include "d_static/d_base.h"
#include "d_static/d_lytbase.h"
#include "state/s_State.h"
#include <nw4r/lyt/Pane.h>

class dCharacterChangeIndicator_c;

class dCharacterChangeSelectContents_c : public dBase_c
{
public:
    // Constants and Types
    // ^^^^^^

    using Icon_e = dCharacterChangeSelectBase_c::Icon_e;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80772A80 */
    dCharacterChangeSelectContents_c();

    /* 0x80772E30 */
    bool createLayout();

    void setMarioIconVisible(int index);

    /* 0x80773220 */
    void dispNextConPicture(Icon_e iconNext, int direction);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ dCharacterChangeIndicator_c* mpCcIndicator;

    FILL(0x20C, 0x248);

    /* 0x248 */ nw4r::lyt::Pane* mpRootPane;

    /* 0x24C */ nw4r::lyt::Pane* mpaSelectConPane[2];
    /* 0x254 */ nw4r::lyt::Picture* mpaPictures[8];
    /* 0x274 */ LytTextBox_c* mpaTextBoxes[4];

    /* 0x284 */ int mPlayerNo; // Set to m0x288 in create
    /* 0x288 */ int m0x288;
    /* 0x28C */ Icon_e m0x28C; // Set 6 in create
    /* 0x290 */ Icon_e m0x290; // Set 6 in create
    /* 0x294 */ Icon_e m0x294; // Set 6 in create
    /* 0x298 */ Icon_e m0x298; // Set 2 in create

    /* 0x29C */ bool m0x29C; // Set true in create
    /* 0x29D */ bool m0x29D; // Set false in create
    /* 0x29E */ bool m0x29E; // Set false in create
    /* 0x29F */ bool m0x29F; // Set false in create
    /* 0x2A0 */ bool m0x2A0; // Set false in create
    /* 0x2A1 */ bool mEasyPairingWait;

    /* 0x2A4 */ u32 mLives[4];

    /* 0x2B4 */ float m0x2B4;

public:
    // Instance Variables
    // ++++++
    OFFSET_ASSERT(0x2B8);

    /* 0x2B8 */ nw4r::lyt::Picture* mpaMarioPictures[2];

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x80990E60, dCharacterChangeSelectContents_c, OnStageWait);
    sState_Extern(0x80990EA0, dCharacterChangeSelectContents_c, AnimeWait);
    sState_Extern(0x80990EE0, dCharacterChangeSelectContents_c, HitAnimeEndWait);
};
