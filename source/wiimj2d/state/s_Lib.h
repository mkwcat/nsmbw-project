#pragma once

namespace sLib {

/**
 * Decrements a timer value. The timer is only decreased if it's non-zero.
 * @param value The timer value to be decremented.
 * @return The updated timer value.
 */
template <class T>
T calcTimer(
    T* value
) {
    if (*value != 0) {
        (*value)--;
    }
    return *value;
}

/* 0x8015F340 */
short addCalcAngle(short* target_var, short target_value, short div, short accel, short min);


template <class T>
int chaseT(T *value, T target, T step);
/* 0x8015F480 */
int chase(short *value, short target, short step);
/* 0x8015F4F0 */
int chase(int *value, int target, int step);
/* 0x8015F550 */
int chase(long *value, long target, long step);
/* 0x8015F5B0 */
int chase(float *value, float target, float step);

/* 0x8015F630 */
bool chaseAngle(short* target_var, short target_value, short increment);

} // namespace sLib
