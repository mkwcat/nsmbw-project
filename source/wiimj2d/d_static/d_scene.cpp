// d_scene.cpp
// NSMBW .text: 0x800E1AA0 - 0x800E2070
// NSMBW .sdata: 0x80428A40 - 0x80428A50

#include "d_scene.h"

[[nsmbw_data(0x80428A42)]]
u16 dScene_c::m_nowScene;

[[nsmbw(0x800E1B10)]]
dScene_c::~dScene_c();

[[nsmbw(0x800E1F50)]]
void dScene_c::setNextScene(u16 profile, u32 param, bool param2);

[[nsmbw(0x800E2040)]]
void dScene_c::setFadeInFrame(u16 frames);

[[nsmbw(0x800E2050)]]
void dScene_c::setFadeOutFrame(u16 frames);
