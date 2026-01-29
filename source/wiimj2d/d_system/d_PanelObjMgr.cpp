// d_PanelObjMgr.cpp
// NSMBW .text: 0x80014970 - 0x80014B30

#include "d_PanelObjMgr.h"

[[nsmbw(0x800148F0)]]
dPanelObjMgr_c::dPanelObjMgr_c();

[[nsmbw(0x80014910)]]
dPanelObjMgr_c::~dPanelObjMgr_c();

[[nsmbw(0x80014820)]]
void dPanelObjMgr_c::addPanelObjList(dPanelObjList_c*);

[[nsmbw(0x80014860)]]
void dPanelObjMgr_c::removePanelObjList(dPanelObjList_c*);