#pragma once

#include "s_FStateFct.h"
#include "s_StateMgr.h"
#include <new>

/**
 * A wrapper for sStateMgr_c that uses sFStateFct_c and sStateIDChk_c.
 * @tparam T The class that this state belongs to.
 * @tparam Method The method to use for the state manager.
 */
template <class T, class Method>
class sFStateMgr_c : public sStateMgr_c<T, Method, sFStateFct_c, sStateIDChk_c>
{
public:
    sFStateMgr_c(T& owner, const sStateIDIf_c& initializeState)
      : sStateMgr_c<T, Method, sFStateFct_c, sStateIDChk_c>(owner, initializeState)
    {
        // sStateStateMgr_c's constructor does not work at all... like it just REFUSES to emit
        // whatsoever with the powerpc-eabi-kuribo target. This means we have to do all the work for
        // it here.....
        void* vtable = *reinterpret_cast<const void***>(this); // Save vtable pointer

        new (static_cast<sStateMgrIf_c*>(this)) sStateMgrIf_c(); // Base constructor
        // Construct member variables
        new (&this->mFactory) sFStateFct_c<T>(owner);
        new (&this->mMethod) Method(this->mCheck, this->mFactory, initializeState);

        *reinterpret_cast<const void***>(this) =
          reinterpret_cast<const void**>(vtable); // Restore vtable
    }
};