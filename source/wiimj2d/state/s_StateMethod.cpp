// s_StateMethod.cpp
// NSMBW .text: 0x8015FAE0 - 0x8015FDD0

#include "s_StateMethod.h"
#include "revolution/os/OSError.h"

/**
 * Constructs a new sStateMethod_c instance.
 * @param checker The state checker to use.
 * @param factory The state factory to use.
 * @param initialState The initial state ID of this instance.
 */
[[nsmbw(0x8015FAE0)]]
sStateMethod_c::sStateMethod_c(
  sStateIDChkIf_c& checker, sStateFctIf_c& factory, const sStateIDIf_c& initialState
);

/**
 * VT+0x08
 * Destroys the sStateMethod_c instance.
 */
[[nsmbw(0x8015FB30)]]
sStateMethod_c::~sStateMethod_c();

/**
 * VT+0x0C 0x8015FE10
 * Initializes the current state.
 */
[[nsmbw(0x8015FB70)]]
void sStateMethod_c::initializeStateMethod();

/**
 * VT+0x10
 * Executes the current state.
 */
[[nsmbw(0x8015FC20)]]
void sStateMethod_c::executeStateMethod();

/**
 * VT+0x14
 * Prepares the current state for termination.
 */
[[nsmbw(0x8015FCC0)]]
void sStateMethod_c::finalizeStateMethod();

/**
 * VT+0x18
 * Transitions to a new state ID.
 * @param newStateID The new state ID to transition to.
 */
[[nsmbw(0x8015FD50)]]
void sStateMethod_c::changeStateMethod(const sStateIDIf_c& newStateID)
{
    if (newStateID.isNull()) {
        return;
    }

    OS_REPORT("%p: State change -> %s\n", this, newStateID.name());

    mpNewStateID = &newStateID;
    changeStateLocalMethod(newStateID);
    mStateChanged = true;
}