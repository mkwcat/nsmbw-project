// d_actor_state.cpp
// NSMBW .text: 0x80066FB0 - 0x80068040

#include "d_actor_state.h"

[[nsmbw(0x80066FC0)]]
dActorState_c::dActorState_c();

/* VT+0x48 */
[[nsmbw(0x800671B0)]]
dActorState_c::~dActorState_c();

/* VT+0xD4 */
[[nsmbw(0x80067230)]]
void dActorState_c::initializeState_Gegneric();

/* VT+0xD8 */
[[nsmbw(0x80067250)]]
void dActorState_c::executeState_Gegneric();

/* VT+0xDC */
[[nsmbw(0x80067240)]]
void dActorState_c::finalizeState_Gegneric();

/* VT+0xD4 */
[[nsmbw(0x800675C0)]]
void dActorMultiState_c::changeState(const sStateIDIf_c& state)
{
    return mStateMgr.changeState(state);
}

/* VT+0xD8 */
[[nsmbw(0x80067590)]]
void dActorMultiState_c::initializeState_GegnericMulti();

/* VT+0xDC */
[[nsmbw(0x800675B0)]]
void dActorMultiState_c::executeState_GegnericMulti();

/* VT+0xE0 */
[[nsmbw(0x800675A0)]]
void dActorMultiState_c::finalizeState_GegnericMulti();