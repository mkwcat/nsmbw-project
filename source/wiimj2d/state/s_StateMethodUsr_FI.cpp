// s_StateMethodUsr_FI.cpp
// NSMBW .text: 0x8015FDD0 - 0x8015FF80

#include "s_StateMethodUsr_FI.h"

[[nsmbw(0x8015FDD0)]]
sStateMethodUsr_FI_c::sStateMethodUsr_FI_c(
    sStateIDChkIf_c& checker, sStateFctIf_c& factory, const sStateIDIf_c& initialState
);

/**
 * VT+0x30
 * Performs the actual state initialization.
 */
[[nsmbw(0x8015FE10)]]
int sStateMethodUsr_FI_c::initializeStateLocalMethod();

/**
 * VT+0x34
 * Performs the actual state execution.
 */
[[nsmbw(0x8015FE80)]]
void sStateMethodUsr_FI_c::executeStateLocalMethod();

/**
 * VT+0x38
 * Performs the actual state termination.
 */
[[nsmbw(0x8015FED0)]]
void sStateMethodUsr_FI_c::finalizeStateLocalMethod();

/**
 * VT+0x3C
 * Performs the actual state transition.
 * @param newStateID The new state ID to transition to.
 */
[[nsmbw(0x8015FF30)]]
void sStateMethodUsr_FI_c::changeStateLocalMethod(const sStateIDIf_c& newStateID);
