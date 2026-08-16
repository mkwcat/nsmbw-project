// s_Lib.cpp
// NSMBW .text: 0x8015F280 - 0x8015F740

#include "s_Lib.h"

namespace sLib {

[[nsmbw(0x8015F340)]]
short addCalcAngle(short* target_var, short target_value, short div, short accel, short min);

[[nsmbw(0x8015F480)]]
int chase(short* value, short target, short step);

template <>
[[nsmbw(0x8015F490)]]
int chaseT<short>(short* value, short target, short step);

[[nsmbw(0x8015F500)]]
int chase(int* value, int target, int step);

template <>
[[nsmbw(0x8015F560)]]
int chaseT<int>(int* value, int target, int step);

[[nsmbw(0x8015F550)]]
int chase(long* value, long target, long step);

template <>
[[nsmbw(0x8015F490)]]
int chaseT<long>(long* value, long target, long step);

[[nsmbw(0x8015F5B0)]]
int chase(float* value, float target, float step);

template <>
[[nsmbw(0x8015F5C0)]]
int chaseT<float>(float* value, float target, float step);

[[nsmbw(0x8015F630)]]
bool chaseAngle(short* target_var, short target_value, short increment);

} // namespace sLib
