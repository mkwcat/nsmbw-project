// eggMath.cpp
// NSMBW .text: 0x802BE760 - 0x802BE820

#include "eggMath.h"

namespace EGG {

template <>
[[nsmbw(0x802BE760)]] [[mkw(0x8022F80C)]]
float EGG::Math<float>::sqrt(float);

template <>
[[nsmbw(0x802BE790)]] [[mkw(0x8022F860)]]
float EGG::Math<float>::sin(float);

template <>
[[nsmbw(0x802BE7C0)]] [[mkw(0x8022F86C)]]
float EGG::Math<float>::cos(float);

template <>
[[nsmbw(0x802BE7F0)]] [[mkw(0x8022F878)]]
float EGG::Math<float>::tan(float);

} // namespace EGG
