// eggException.cpp
// NSMBW .text: 0x802D7460 - 0x802D7970

#include "eggException.h"

namespace EGG {

[[nsmbw(0x802D74E0)]] [[mkw(0x80226464)]]
bool Exception::ExceptionCallback_(nw4r::db::ConsoleHandle console, void* userdata);

[[mkw(0x80226734)]]
void Exception::create(u16, u16, u16, Heap*, int);

[[mkw(0x802267F0)]]
void Exception::setPadInfo(const u16*);

} // namespace EGG
