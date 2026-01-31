// d_PanelObjList.cpp
// NSMBW .text: 0x80014820 - 0x80014970

#include "d_PanelObjList.h"

[[nsmbw(0x800145B0)]]
dPanelObjList_c::dPanelObjList_c();

[[nsmbw(0x800145F0)]]
dPanelObjList_c::~dPanelObjList_c();

[[nsmbw(0x800146B0)]]
void dPanelObjList_c::setPos(float x, float y, float z);

[[nsmbw(0x800146D0)]]
void dPanelObjList_c::setScaleFoot(float scale);

[[nsmbw(0x800146F0)]]
void dPanelObjList_c::setScaleAngle(float scale, short angle);

[[nsmbw(0x80014710)]]
float dPanelObjList_c::getScale();