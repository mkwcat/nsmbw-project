// eggDisposer.cpp
// NSMBW .text: 0x802BA410 - 0x802BA4F0

#include "eggDisposer.h"

namespace EGG {

[[nsmbw(0x802BA410)]] [[mkw(0x8021A0F0)]]
Disposer::Disposer();

[[nsmbw(0x802BA470)]] [[mkw(0x8021A144)]]
Disposer::~Disposer();

} // namespace EGG
