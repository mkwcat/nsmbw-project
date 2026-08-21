#pragma once

#include "d_static/d_actor_state.h"
#include "d_static/d_rc.h"

class daLiftRemoconMain_c : public dActorState_c
{
    SIZE_ASSERT(0x454);

public:
    // Structors
    // ^^^^^^

    daLiftRemoconMain_c()
    {
    }

    /* VT+0x08 0x80044390 */
    virtual ~daLiftRemoconMain_c() override;

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0xE0 0x80043A30 */
    virtual void VT_0xE0();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x800439B0 */
    void MultiRemoconShockSet(u8 playerMask);

    /* 0x80043CA0 */
    void PlayerNoRideClear();

    /* 0x80043CD0 @unofficial */
    bool ContainsPlayerNoRide(u8 playerNo);

    /* 0x80043DA0 */
    void PlayerNoRideEntry(u8 playerNo);

    /* 0x80043DC0 */
    void PlayerNoRideSort(int amount);

    /* 0x80043EB0 */
    void PlayerNoRideDelete(u8 playerNo);

    /* 0x80043F10 */
    void PlayerNoEntryHead(u8 playerNo);

    /* 0x800440C0 */
    u8 PlayerNoRideCheck(u8 playerMask);

    /* 0x800441E0 @unofficial */
    u8 UpdateControlPlayerNo(u8* rideCheck);

public:
    // Instance Variables
    // ^^^^^^

    /* 0x3D0 */ dRideRoll_c mRideRoll;
    /* 0x430 */ s8 mRemotePlayerID;
    /* 0x434 */ u32 m0x434;
    /* 0x438 */ f32 m0x438;
    /* 0x43C */ u32 m0x43C;
    /* 0x440 */ u8 mPlayerMask;
    /* 0x441 */ u8 m0x441;
    /* 0x442 */ s8 mPlayerNo[8];
    /* 0x44C */ u32 m0x44C;
    // /* 0x450 */ s8 mControlPlayerTimer[4];
    /* 0x450 */ s8* mpControlPlayerTimer;
};
