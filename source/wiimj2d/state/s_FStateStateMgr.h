#pragma once

#include "s_FStateMgr.h"
#include "s_StateStateMgr.h"
#include <new>

/**
 * A wrapper for sStateStateMgr_c that uses sFStateMgr_c.
 */
template <class T, class Method, class Method2>
class sFStateStateMgr_c : public sStateStateMgr_c<T, sFStateMgr_c, Method, Method2>
{
public:
    sFStateStateMgr_c(T& owner)
      : sStateStateMgr_c<T, sFStateMgr_c, Method, Method2>(owner)
    {
        // sStateStateMgr_c's constructor does not work at all... like it just REFUSES to emit
        // whatsoever with the powerpc-eabi-kuribo target. This means we have to do all the work for
        // it here.....
        void* vtable = *reinterpret_cast<const void***>(this); // Save vtable pointer
        new (static_cast<sStateStateMgrIf_c*>(this)) sStateStateMgrIf_c(); // Base constructor

        // Construct member variables
        new (&this->mMgr1) sFStateMgr_c<T, Method>(owner, sStateID::null);
        new (&this->mMgr2) sFStateMgr_c<T, Method2>(owner, sStateID::null);
        this->mCurrentMgr = &this->mMgr1;

        *reinterpret_cast<const void***>(this) =
          reinterpret_cast<const void**>(vtable); // Restore vtable
    }
};