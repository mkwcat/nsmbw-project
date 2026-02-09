#pragma once

#include "d_system/d_lytbase.h"

#include <nw4r/lyt/Pane.h>

class dPreGameLyt_c
{
public:
    // Structors
    // ^^^^^^

    ~dPreGameLyt_c()
    {
        if (mpExtra != nullptr) {
            delete mpExtra;
            mpExtra = nullptr;
        }
        mLayout.~LytBase_c();
    }

public:
    // Constants and Types
    // ^^^^^^

    static constexpr std::size_t LytPlayerCount = 8;

    struct Extra_s {
        ~Extra_s()
        {
        }

        LytTextBox_c* mpTRemainderOld1;
        LytTextBox_c* mpTRemainder0[LytPlayerCount - 4];
        LytTextBox_c* mpTRemainder1[LytPlayerCount - 4];
        nw4r::lyt::Pane* mpNPlayer[LytPlayerCount - 4];
    };

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80B6BCC0 */
    void setPlayerRest();

    /* 0x80B6C040 */
    void createLayout();

    void createLayoutExtra();

    /* 0x80B6C830 */
    void Phase0_Init();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x000 */ LytBase_c mLayout;
    /* 0x198 */ nw4r::lyt::Pane* mpRootPane;

    FILL(0x19C, 0x1B0);

    /* 0x1B0 */ LytTextBox_c* mpTRemainder0[4];
    /* 0x1C0 */ LytTextBox_c* mpTRemainder1[4];

    FILL(0x1D0, 0x1F8);

    /* 0x1F8 */ LytTextBox_c* mpTOtasukePlay0;
    /* 0x1FC */ LytTextBox_c* mpTOtasukePlay1;

    FILL(0x200, 0x204);

    /* 0x204 */ LytTextBox_c* mpTRemainderOld0;
    /* 0x208 */ // LytTextBox_c* mpTRemainderOld1;
    /* 0x208 */ Extra_s* mpExtra;

    FILL(0x20C, 0x238);

    /* 0x238 */ nw4r::lyt::Pane* mpOtherPane[20];

    /* 0x288 */ nw4r::lyt::Picture* mpPLuigiIcon[2];

    FILL(0x290, 0x294);

    /* 0x294 */ nw4r::lyt::Pane* mpNPlayer[4];
    /* 0x2A4 */ nw4r::lyt::Pane* mpNZankiPos[4];
    /* 0x2B4 */ nw4r::lyt::Pane* mpNZanki;
    /* 0x2B8 */ nw4r::lyt::Pane* mpNBatteryPos[4];
    /* 0x2C8 */ nw4r::lyt::Pane* mpNBatteryArray[4];
    /* 0x2D8 */ nw4r::lyt::Pane* mpNBattery;

    FILL(0x2DC, 0x2E1);

    /* 0x2E1 */ bool m0x2E1;
    /* 0x2E2 */ bool m0x2E2;
    /* 0x2E3 */ bool mSuperGuideDispDone;
    /* 0x2E4 */ int mPhase;

    FILL(0x2E2, 0x2F0);

    /* 0x2F0 */ int mNumPlayers;

    FILL(0x2F4, 0x300);

    /* 0x300 */ int m_dispEndTimer;
};
