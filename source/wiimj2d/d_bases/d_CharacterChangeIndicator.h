#pragma once

#include "d_static/d_base.h"
#include "d_static/d_lytbase.h"
#include "d_static/d_lyttextbox.h"
#include <nw4r/lyt/Picture.h>

class dCharacterChangeIndicator_c : public dBase_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8076DC80 */
    void UNDEF_8076DC80();

    inline void setLampPattern(u32 pattern)
    {
        mpPLamp[0]->SetVisible(pattern & 0b1000);
        mpPLamp[1]->SetVisible(pattern & 0b0100);
        mpPLamp[2]->SetVisible(pattern & 0b0010);
        mpPLamp[3]->SetVisible(pattern & 0b0001);
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x070 */ LytBase_c mLayout;
    /* 0x208 */ nw4r::lyt::Pane* mpRootPane;

    /* 0x20C */ nw4r::lyt::Picture* mpPLamp[4];
    /* 0x21C */ nw4r::lyt::Picture* mpPInfoBaseS;
    /* 0x220 */ nw4r::lyt::Picture* mpPInfoBase;

    /* 0x224 */ LytTextBox_c* mpTButtonInfo[2];
    /* 0x22C */ LytTextBox_c* mpTButton[2];

    /* 0x234 */ float m0x234;
    /* 0x238 */ u8 m0x238;
    /* 0x239 */ u8 m0x239;
    /* 0x23C */ int mPlayerNo;

    FILL(0x240, 0x248);

    /* 0x248 */ int m0x248;
    /* 0x24C */ int m0x24C;
};
