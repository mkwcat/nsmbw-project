#pragma once

#include "d_system/d_a_player_manager.h"
#include "d_system/d_enemy.h"

class daEnGlpole_c : public dEn_c
{
public:
    // Constants and Types
    // ^^^^^^

    struct UNKPlayerPos {
        FILL(0x00, 0x10);
    };

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
    bool isTopOfFlagPole(u32 mask, int player);

    /* 0x80A0B020 */
    bool isAllPlayerOnPole();

public:
    // Static Methods
    // ^^^^^^

    /* 0x80A0A550 */
    static void ccCallBackForPole2(dCc_c* self, dCc_c* other);

    /* 0x80A0A5E0 */
    static void ccCallBackForPole(dCc_c* self, dCc_c* other);

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0xAAC);

    /* 0x0AAC */ u8 mPlrOnPoleFlag;
    /* 0x0AAD */ u8 mPlrTouchPoleFlag;
    /* 0x0AAE */ u8 mPlrTouchPoleFlag2;

    FILL(0xAAF, 0xAB0);
    OFFSET_ASSERT(0xAB0);

#define daEnGlpole_c_OFFSET_mPlayerPos (0xAB0)
#define daEnGlpole_c_ADJUST_mPlayerPos (0xAB0 - 0xA38)
    /* 0x0AB0 */ UNKPlayerPos mPlayerPos[PLAYER_COUNT];
};
