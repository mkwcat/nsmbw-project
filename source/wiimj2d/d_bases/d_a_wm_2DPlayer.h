#pragma once

#include "d_static/d_base_actor.h"
#include "d_static/d_mj2d_game.h"

class dPyMdlMng_c;

class da2DPlayer_c : public dBaseActor_c
{
    SIZE_ASSERT(0x384);

    /* 0x060 VTABLE 0x809812E0 */

public:
    /* 0x808C5130 */
    da2DPlayer_c();

    /* 0x808C5690 */
    void calcPlayer();

    /* 0x808C5990 */
    void loadPlayer();

    /* 0x808C6EE0 */
    void FUN_808C6EE0(int);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x128 */ dPyMdlMng_c* mModelMng;

    FILL(0x12C, 0x220);

    /* 0x220 */ mVec3_c mBaseScale;
    /* 0x22C */ mVec3_c mBasePos;

    /* 0x238 */ PLAYER_MODE_e mPowerup;

    /* 0x23C */ s32 m0x23C;
    /* 0x240 */ s32 m0x240;
    /* 0x244 */ s32 m0x244;
    /* 0x248 */ int mPlayerNo;
    /* 0x24C */ float mSubZ;
    /* 0x250 */ f32 m0x250;

    FILL(0x254, 0x258);

    /* 0x258 */ float mAddZ;
    /* 0x25C */ float mAddY;

    /* 0x260 */ bool mReady;
    /* 0x261 */ bool m0x261;
    /* 0x262 */ bool m0x262;
    /* 0x263 */ bool m0x263;
    /* 0x264 */ bool mEasyPairingWait;
    /* 0x265 */ bool m0x265;
    /* 0x266 */ bool m0x266;
    /* 0x267 */ bool m0x267;
    /* 0x268 */ bool m0x268;
    /* 0x269 */ bool m0x269;
    /* 0x26A */ bool mForbidJump;

    FILL(0x26B, 0x384);
};
