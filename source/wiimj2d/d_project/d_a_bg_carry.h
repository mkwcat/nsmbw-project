#pragma once

#include "d_system/d_PanelObjList.h"
#include "d_system/d_actor_state.h"
#include "d_system/d_bg_ctr.h"
#include "state/s_State.h"

class daBgCarry_c : public dActorMultiState_c
{
public:
    // Structors
    // ^^^^^^

    daBgCarry_c();

    /* VT+0x48 */
    virtual ~daBgCarry_c();

public:
    // Virtual Functions
    // ^^^^^^

    /**
     * VT+0x08
     * do method for the create operation.
     */
    virtual PACK_RESULT_e create() override;

    /**
     * VT+0x14
     * do method for the delete operation. This method was renamed due to conflict with the delete
     * C++ keyword.
     */
    virtual PACK_RESULT_e doDelete() override;

    /**
     * VT+0x20
     * do method for the execute operation.
     */
    virtual PACK_RESULT_e execute() override;

    /**
     * VT+0x5C
     * Code to be executed after all actors' execute operation has run.
     */
    virtual void finalUpdate() override;

    /* VT+0x78 */
    virtual void setSpinLiftUpActor(dActor_c* actor) override;

public:
    // Instance Methods
    // ^^^^^^

    mVec3_c calcCarryPos(const mVec3_c& offset);

    void placeTile();
    
    void destroyBrick();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x414 */ u16 mTileNum;
    /* 0x418 */ dPanelObjList_c mPanelObj;
    /* 0x438 */ int mCarryNo;
    /* 0x43C */ mVec3_c mCarryOffset;
    /* 0x448 */ dBg_ctr_c mBg;

public:
    // Static Methods
    // ^^^^^^

    static void callBackF(dActor_c* self, dActor_c* other);
    static void callBackH(dActor_c* self, dActor_c* other);
    static void callBackW(dActor_c* self, dActor_c* other, u8 direction);

    static bool checkRevFoot(dActor_c* self, dActor_c* other);
    static bool checkRevHead(dActor_c* self, dActor_c* other);
    static bool checkRevWall(dActor_c* self, dActor_c* other, u8 direction);

    static void collisionCallback(dCc_c* self, dCc_c* other);

public:
    // Static Variables
    // ^^^^^^

    static const float smc_THROW_SPEED_X;

private:
    // State IDs
    // ^^^^^^

    sState(daBgCarry_c, Carry);
    sState(daBgCarry_c, Throw);
};