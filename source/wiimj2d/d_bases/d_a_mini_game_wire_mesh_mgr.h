#pragma once

#include "d_system/d_base.h"
#include "d_system/d_ef.h"
#include "d_system/d_mj2d_game.h"
#include "machine/m_ef.h"

class daMiniGameWireMeshMgrObj_c : dBase_c
{
public:
    // Instance Methods
    // ^^^^^^

    /* 0x8086AB90 */
    void EffectCursor2d();

    /* 0x8086AEA0 */
    void EffectPlayerCursor();

    /* 0x8086B230 */
    void updateStockItem();

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x070, 0x1D5);

    /* 0x1D5 */ bool mIsGameFail;
    /* 0x1D6 */ bool mIsBadPanelFlip;

    FILL(0x1D7, 0x1E8);

    /* 0x1E8 */ int mWinItemCount;
    /* 0x1EC */ int mWinStockItem[STOCK_ITEM_COUNT];
    /* 0x208 */ int mTurnPlayer;
    /* 0x20C */ int mTurnPlayerBackup;
    /* 0x210 */ int mPlayNum;

    FILL(0x214, 0x220);

    /* 0x220 */ bool mUpdateCursor;

    FILL(0x221, 0x224);

    /* 0x224 */ dEf::dLevelEffect_c mEffectCursor;
    /* 0x34C */ mEf::effect_c mEffectCursorSt;

    /* 0x460 */ bool mHasPlayedCursorSt;

    FILL(0x461, 0x58C);

    /* 0x58C */ mEf::effect_c mEffectCursor2d;
};
