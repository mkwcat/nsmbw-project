// eggEffect.cpp
// NSMBW .text: 0x802D7D90 - 0x802D8BC0

#include "eggEffect.h"

namespace EGG
{

[[address(0x802D7D90)]]
Effect::Effect();

[[address(0x802D7E10)]]
Effect::~Effect();

[[address(0x802D8470)]]
void Effect::setRegisterColor(const GXColor& regColor0, const GXColor& regColor1, u8 regIdx, ERecursive);

[[address(0x802D84B0)]]
void Effect::setRegisterAlpha(u8 regAlpha0, u8 regAlpha1, u8 regIdx, ERecursive);

[[address(0x802D88B0)]]
void Effect::update();

} // namespace EGG