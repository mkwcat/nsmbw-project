#pragma once

#include "GXStruct.h"

struct GXLightObj {
    char UNK_0x0[0xC];
    GXColor color; // at 0xC
    f32 aa; // at 0x10
    f32 ab; // at 0x14
    f32 ac; // at 0x18
    f32 ka; // at 0x1C
    f32 kb; // at 0x20
    f32 kc; // at 0x24
    f32 posX; // at 0x28
    f32 posY; // at 0x2C
    f32 posZ; // at 0x30
    f32 dirX; // at 0x34
    f32 dirY; // at 0x38
    f32 dirZ; // at 0x3C
};