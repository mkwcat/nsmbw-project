#pragma once

#include "d_static/d_enemy.h"
#include "d_static/d_mj2d_game.h"
#include "state/s_State.h"

class daMiniGameWireMesh_c : public dEn_c
{
public:
    // Structors
    // ^^^^^^

    daMiniGameWireMesh_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08 0x808682B0
     * do method for the create operation.
     */
    PACK_RESULT_e create() override;

    /**
     * VT+0x20 0x80868420
     * do method for the execute operation.
     */
    PACK_RESULT_e execute() override;

public:
    // Instance Methods
    // ^^^^^^

    /* 0x808687B0 */
    void updatePlayerAmiRoll(int index);

    /* 0x80868880 */
    void updateAll();

    /* 0x80868F00 */
    void setAmiRollPos();

    /* 0x80868F90 */
    void endAmiRollAction();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x524, 0x6A4);

    /* 0x6A4 */ s32 m0x6A4[17];

    FILL(0x6E8, 0x744);

    /* 0x744 */ f32 REMOVED(mPlayerX)[4];
    /* 0x754 */ f32 REMOVED(mPlayerY)[4];
    /* 0x764 */ f32 REMOVED(mPlayerZ)[4];

    FILL(0x774, 0x8B0);

    /* 0x8B0 */ s32 m0x8B0;
    /* 0x8B4 */ s16 m0x8B4;
    /* 0x8B6 */ s16 m0x8B6;
    /* 0x8B8 */ s16 m0x8B8;
    /* 0x8BA */ s16 m0x8BA;
    /* 0x8BC */ bool REMOVED(mPlayers0x8BC)[4];
    /* 0x8C0 */ u8 REMOVED(mPlayerChainlinkMode)[4];
    /* 0x8C4 */ bool REMOVED(mPlayers0x8C4)[4];
    /* 0x8C8 */ s8 REMOVED(mPlayerIDs)[4];

    FILL(0x8CC, 0x908);
    OFFSET_ASSERT(0x908);

#define OFFSET_daMiniGameWireMesh_c_mPlayerIDs 0x908
    s8 mPlayerIDs[PLAYER_COUNT];

#define OFFSET_daMiniGameWireMesh_c_mPlayerX (OFFSET_daMiniGameWireMesh_c_mPlayerIDs + PLAYER_COUNT)
#define OFFSET_daMiniGameWireMesh_c_mPlayerY                                                       \
    (OFFSET_daMiniGameWireMesh_c_mPlayerX + 4 * PLAYER_COUNT)
#define OFFSET_daMiniGameWireMesh_c_mPlayerZ                                                       \
    (OFFSET_daMiniGameWireMesh_c_mPlayerY + 4 * PLAYER_COUNT)
    f32 mPlayerX[PLAYER_COUNT];
    f32 mPlayerY[PLAYER_COUNT];
    f32 mPlayerZ[PLAYER_COUNT];

#define OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC                                                   \
    (OFFSET_daMiniGameWireMesh_c_mPlayerZ + 4 * PLAYER_COUNT)
    bool mPlayer0x8BC[PLAYER_COUNT];

#define OFFSET_daMiniGameWireMesh_c_mPlayerChainlinkMode                                           \
    (OFFSET_daMiniGameWireMesh_c_mPlayer0x8BC + PLAYER_COUNT)
    u8 mPlayerChainlinkMode[PLAYER_COUNT];

#define OFFSET_daMiniGameWireMesh_c_mPlayer0x8C4                                                   \
    (OFFSET_daMiniGameWireMesh_c_mPlayerChainlinkMode + PLAYER_COUNT)
    bool mPlayer0x8C4[PLAYER_COUNT];

public:
    // Static Methods
    // ^^^^^^

    /* 0x80868590 */
    static void ccCallback(dCc_c* me, dCc_c* other);

public:
    // State IDs
    // ^^^^^^

    sState_Extern(0x8099CD08, daMiniGameWireMesh_c, ShowRuleWait);
    sState_Extern(0x8099CD48, daMiniGameWireMesh_c, PlayWait);
    sState_Extern(0x8099CD88, daMiniGameWireMesh_c, PlayMove);
    sState_Extern(0x8099CDC8, daMiniGameWireMesh_c, ForceTurnUp);
    sState_Extern(0x8099CE08, daMiniGameWireMesh_c, ShowResultWait);
};
