// c_random.cpp
// NSMBW .text: 0x801615A0 - 0x80161670

#include "c_random.h"

[[nsmbw(0x801615A0)]]
u32 cRandom_c::getRandomByAsm(u32 limit);

[[nsmbw(0x801615D0)]]
float cRandom_c::getRandomFByAsm();

[[nsmbw(0x80161620)]]
float cRandom_c::getRandomF2ByAsm();
