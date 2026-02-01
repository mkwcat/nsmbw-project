#pragma once

#include "d_system/d_actor.h"
#include "state/s_FStateMgr.h"
#include "state/s_FStateStateMgr.h"
#include "state/s_StateMethodUsr_FI.h"

class dActorState_c : public dActor_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x80066FC0 */
    dActorState_c();

    /* VT+0x48 0x800671B0 */
    virtual ~dActorState_c();

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0xD4 0x80067230 */
    virtual void initializeState_Gegneric();

    /* VT+0xD8 0x80067250 */
    virtual void executeState_Gegneric();

    /* VT+0xDC 0x80067240 */
    virtual void finalizeState_Gegneric();

public:
    // Instance Variables
    // ^^^^^^

    /* 0x394 */
    sFStateMgr_c<dActorState_c, sStateMethodUsr_FI_c> stateMgr;
};

class dActorMultiState_c : public dActor_c
{
public:
    // Structors
    // ^^^^^^

    dActorMultiState_c()
      : mStateMgr(*this)
    {
    }

    /* VT+0x48 */
    virtual ~dActorMultiState_c()
    {
    }

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0xD4 0x800675C0 */
    virtual void changeState(const sStateIDIf_c& state);

    /* VT+0xD8 0x80067590 */
    virtual void initializeState_GegnericMulti();

    /* VT+0xDC 0x800675B0 */
    virtual void executeState_GegnericMulti();

    /* VT+0xE0 0x800675A0 */
    virtual void finalizeState_GegnericMulti();

public:
    // Instance Methods
    // ^^^^^^
    
    bool isState(const sStateIDIf_c& other) const
    {
        return *mStateMgr.getStateID() == other;
    }

public:
    // Instance Variables
    // ^^^^^^

    /* 0x394 */
    sFStateStateMgr_c<dActorMultiState_c, sStateMethodUsr_FI_c, sStateMethodUsr_FI_c> mStateMgr;
};
