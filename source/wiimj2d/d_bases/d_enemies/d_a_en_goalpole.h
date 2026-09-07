#pragma once

#include "d_enemy.h"

class daEnGlpole_c : public dEn_c {
    // Original size: 0xAB0
    VTABLE(0x060, fBase_c, 0x80AEC0B8);
    // 0x80AEC030 g_profile_EN_GOALPOLE
    // 0x80A096E0 daEnGlpole_c_classInit

public:
    // Structors
    // ^^^^^^

    /* 0x80A09710 */
    daEnGlpole_c();

public:
    // Virtual Methods
    // ^^^^^^

    /**
     * VT+0x08 0x80A09980
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x80A0A700 */
    bool isTopOfFlagPole(u32 mask, int plrNo);

    /* 0x80A0A9F0 */
    void FUN_80A0A9F0();

    /* 0x80A0AB10 */
    void setPlayerBasePos();

    /* 0x80A0B020 */
    bool isAllPlayerOnPole();

public:
    // Static Methods
    // ^^^^^^

    /* 0x80A0A550 */
    static void ccCallBackForPole2(dCc_c* self, dCc_c* other);

    /* 0x80A0A5E0 */
    static void ccCallBackForPole(dCc_c* self, dCc_c* other);

    // Static Methods
    // ++++++

    static float getBasePlayerPos(int plrNo);

public:
    // Nested Types
    // ^^^^^^

    struct PlayerPos_s {
        FILL(0x00, 0x10);
    };

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xA38);
    /* 0xA38 */ PlayerPos_s REMOVED(mPlayerPos[4]);
    FILL(0xA78, 0xAAC);
    /* 0xAAC */ u8 mPlrOnPoleFlag;
    /* 0xAAD */ u8 mPlrTouchPoleFlag;
    /* 0xAAE */ u8 mPlrTouchPoleFlag2;

    FILL(0xAAF, 0xAB0);
    OFFSET_ASSERT(0xAB0);

    // Instance Variables
    // ++++++

#define daEnGlpole_c_OFFSET_mPlayerPos 0xAB0
    /* 0xAB0 */ PlayerPos_s mPlayerPos[PLAYER_COUNT];

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x80A0B590
     * executeState:    0x80A0B5B0
     * finalizeState:   0x80A0B5A0
     */
    sState_Extern(0x80B15470, daEnGlpole_c, Check);

    /*
     * initializeState: 0x80A0B5F0
     * executeState:    0x80A0B620
     * finalizeState:   0x80A0B610
     */
    sState_Extern(0x80B154B0, daEnGlpole_c, Jump);

    /*
     * initializeState: 0x80A0B660
     * executeState:    0x80A0B6F0
     * finalizeState:   0x80A0B6E0
     */
    sState_Extern(0x80B154F0, daEnGlpole_c, Flagdown);

    /*
     * initializeState: 0x80A0B7E0
     * executeState:    0x80A0B800
     * finalizeState:   0x80A0B7F0
     */
    sState_Extern(0x80B15530, daEnGlpole_c, Wait);
};
