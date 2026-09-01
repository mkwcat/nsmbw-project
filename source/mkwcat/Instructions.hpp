//
//  mkwcat/Instructions.hpp
//  nsmbw-project
//

#pragma once

namespace mkwcat {

ASM(
    .macro  psq_l D, d, A, W, IDX;
    .long   (56 << 26) |
            (\\D << 21) |
            (\\A << 16) |
            (\\W << 15) |
            (\\IDX << 20) |
            (\\d);
    .endm;

    .macro  psq_st S, d, A, W, IDX;
    .long   (60 << 26) |
            (\\S << 21) |
            (\\A << 16) |
            (\\W << 15) |
            (\\IDX << 20) |
            (\\d);
    .endm;
);

template <int W, int I>
inline f32 psq_l(
    const auto* A
) {
    f32 r;
    asm("psq_l %[D], %y[A], %[W], %[I]"
        : [D] "=f"(r)
        : [A] "Z"(*A), [W] "i"((W) & 0x1), [I] "i"((I) & 0x7));
    return r;
}

template <int d, int W, int I>
inline void psq_st(
    auto* A, f32 S
) {
    asm("psq_st %[S], %y[A], %[W], %[I]"
        : [A] "=Z"(*A)
        : [S] "f"(S), [W] "i"((W) & 0x1), [I] "i"((I) & 0x7));
}

#define MKWCAT_PS_ARITH(VA, VB, VC) \
    asm(".long (%[OPCD] << 26) | (%[D] << 21) | (%[A] << 16) | (%[B] << 11) | (%[C] << 6) | " \
        "(%[XO] << 1) | " \
        "(%[Rc])" \
        : [D] "=f"(r) \
        : [A] VA, [B] VB, [C] VC, [OPCD] "i"(OPCD), [XO] "i"(XO), [Rc] "i"(0))

inline f32 ps_add(
    f32 A, f32 B
) {
    static constexpr int OPCD = 4, XO = 21;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "f"(B), "i"(0));
    return r;
}

inline f32 ps_sel(
    f32 A, f32 B, f32 C
) {
    static constexpr int OPCD = 4, XO = 23;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "f"(B), "f"(C));
    return r;
}

inline f32 ps_res(
    f32 B
) {
    static constexpr int OPCD = 4, XO = 24;
    f32                  r;
    MKWCAT_PS_ARITH("i"(0), "f"(B), "i"(0));
    return r;
}

inline f32 ps_mul(
    f32 A, f32 C
) {
    static constexpr int OPCD = 4, XO = 25;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "i"(0), "f"(C));
    return r;
}

inline f32 ps_rsqrte(
    f32 B
) {
    static constexpr int OPCD = 4, XO = 26;
    f32                  r;
    MKWCAT_PS_ARITH("i"(0), "f"(B), "i"(0));
    return r;
}

inline f32 ps_msub(
    f32 A, f32 B, f32 C
) {
    static constexpr int OPCD = 4, XO = 28;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "f"(B), "f"(C));
    return r;
}

inline f32 ps_madd(
    f32 A, f32 B, f32 C
) {
    static constexpr int OPCD = 4, XO = 29;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "f"(B), "f"(C));
    return r;
}

inline f32 ps_nmsub(
    f32 A, f32 B, f32 C
) {
    static constexpr int OPCD = 4, XO = 30;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "f"(B), "f"(C));
    return r;
}

inline f32 ps_nmadd(
    f32 A, f32 B, f32 C
) {
    static constexpr int OPCD = 4, XO = 31;
    f32                  r;
    MKWCAT_PS_ARITH("f"(A), "f"(B), "f"(C));
    return r;
}

#undef MKWCAT_PS_ARITH

} // namespace mkwcat
