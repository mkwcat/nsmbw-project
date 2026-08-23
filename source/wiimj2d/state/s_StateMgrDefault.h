#pragma once

#include "s_FStateFct.h"
#include "s_StateInterfaces.h"
#include "s_StateMethodUsr_FI.h"
#include "s_StateMgr.h"

template <class T>
using sStateMgrDefault_c = sStateMgr_c<T, sStateMethodUsr_FI_c, sFStateFct_c, sStateIDChk_c>;
