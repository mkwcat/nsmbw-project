#pragma once

#include <mkwcat/Instructions.hpp>

// Inline Methods
// ^^^^^^

inline f32 __OSu8tof32(
    u8* in
) {
    return mkwcat::psq_l<1, 2>(in);
}

inline void OSu8tof32(
    u8* in, volatile f32* out
) {
    *out = __OSu8tof32(in);
}

inline f32 __OSu16tof32(
    u16* in
) {
    return mkwcat::psq_l<1, 3>(in);
}

inline void OSu16tof32(
    u16* in, volatile f32* out
) {
    *out = __OSu16tof32(in);
}

inline f32 __OSs16tof32(
    s16* in
) {
    return mkwcat::psq_l<1, 5>(in);
}

inline void OSs16tof32(
    s16* in, volatile f32* out
) {
    *out = __OSs16tof32(in);
}

inline u8 __OSf32tou8(
    f32 in
) {
    f32  a;
    f32* ptr = &a;
    u8   r;

    mkwcat::psq_st<0, 1, 2>(ptr, in);

    r = *reinterpret_cast<u8*>(ptr);
    return r;
}

inline void OSf32tou8(
    f32* in, volatile u8* out
) {
    *out = __OSf32tou8(*in);
}

inline u16 __OSf32tou16(
    f32 in
) {
    f32  a;
    f32* ptr = &a;
    u16  r;

    mkwcat::psq_st<0, 1, 3>(ptr, in);

    r = *reinterpret_cast<u16*>(ptr);
    return r;
}

inline void OSf32tou16(
    f32* in, volatile u16* out
) {
    *out = __OSf32tou16(*in);
}

inline s16 __OSf32tos16(
    f32 in
) {
    f32  a;
    f32* ptr = &a;
    s16  r;

    mkwcat::psq_st<0, 1, 5>(ptr, in);

    r = *reinterpret_cast<s16*>(ptr);
    return r;
}

inline void OSf32tos16(
    f32* in, volatile s16* out
) {
    *out = __OSf32tos16(*in);
}
