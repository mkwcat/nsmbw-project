#pragma once

#include "d_lytbase.h"
#include "m_vec.h"
#include "s_State.h"
#include "s_StateMgrDefault.h"
#include <nw4r/lyt/Picture.h>

class dfukidashiInfo_c {
    SIZE_ASSERT(0x23C);
    VTABLE(0x060, fBase_c, 0x80315658);

    friend class dfukidashiManager_c;

public:
    // Structors
    // ^^^^^^

    /* 0x800B14E0 */
    dfukidashiInfo_c();

    /* 0x800B16E0 */
    virtual ~dfukidashiInfo_c();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800B1990 */
    void draw();

    /* 0x800B1A50 */
    void SetPosOffset(int plrColorType, int playerMode);

    /* 0x800B1BD0 */
    void ColorSet();

public:
    // Instance Inline Methods
    // ++++++

    bool isDispOn() const { return mDispOn; }

    bool isVisible() const { return mVisible; }

    int getAction() const { return mAction; }

    bool isAction(
        int action
    ) const {
        return mAction == action;
    }

    void reSetTimer() {
        m0x224 = m0x228;
        m0x234 = 0;
    }

public:
    // Static Inline Methods
    // ++++++

    static bool isPerformForAllAction(
        int action
    ) {
        return action == 8;
    }

protected:
    // Instance Variables
    // ^^^^^^

    /* 0x004 */ LytBase_c                            mLayout;
    /* 0x19C */ sStateMgrDefault_c<dfukidashiInfo_c> mStateMgr;

    FILL(0x1D8, 0x1DC);

    /* 0x1DC */ mVec3_c mPosOffset;

    FILL(0x1E8, 0x1F4);

    /* 0x1F4 */ nw4r::lyt::Pane* mpPane;

    FILL(0x1F8, 0x1FC);

    /* 0x1FC */ nw4r::lyt::Picture* mpAfterImgUD;
    /* 0x200 */ nw4r::lyt::Picture* mpUpDownImg01;
    /* 0x204 */ nw4r::lyt::Picture* mpAfterImgK;
    /* 0x208 */ nw4r::lyt::Picture* mpKatamukiHand;
    /* 0x20C */ nw4r::lyt::Picture* mpArrow;
    /* 0x210 */ nw4r::lyt::Picture* mpUpDownImg02;

    FILL(0x214, 0x21C);

    /* 0x21C */ int mPlrNo;
    /* 0x220 */ int mAction;
    /* 0x224 */ int m0x224;
    /* 0x228 */ int m0x228;
    /* 0x22C */ int m0x22C;
    /* 0x230 */ int m0x230;
    /* 0x234 */ int m0x234;

    FILL(0x238, 0x239);

    /* 0x239 */ bool mDispOn;
    /* 0x23A */ bool mVisible;

    FILL(0x23B, 0x23C);

public:
    // State IDs
    // ^^^^^^

    /*
     * initializeState: 0x800B1F80
     * executeState:    0x800B1FD0
     * finalizeState:   0x800B2030
     */
    sState_Extern(0x80358C58, dfukidashiInfo_c, StartWait);

    /*
     * initializeState: 0x800B2070
     * executeState:    0x800B2180
     * finalizeState:   0x800B21E0
     */
    sState_Extern(0x80358C98, dfukidashiInfo_c, OnStageStart);

    /*
     * initializeState: 0x800B21F0
     * executeState:    0x800B2230
     * finalizeState:   0x800B2370
     */
    sState_Extern(0x80358CD8, dfukidashiInfo_c, Move);

    /*
     * initializeState: 0x800B2440
     * executeState:    0x800B2450
     * finalizeState:   0x800B24B0
     */
    sState_Extern(0x80358D18, dfukidashiInfo_c, Exit);
};
