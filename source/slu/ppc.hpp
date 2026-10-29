#pragma once

namespace slu::ppc {

enum {
    XER    = 1,
    LR     = 8,
    CTR    = 9,
    DSISR  = 18,
    DAR    = 19,
    DEC    = 22,
    SDR1   = 25,
    SRR0   = 26,
    SRR1   = 27,
    TBL    = 268,
    TBU    = 269,
    EAR    = 282,
    TBLW   = 284,
    TBUW   = 285,
    PVR    = 287,
    IBAT0U = 528,
    IBAT0L = 529,
    IBAT1U = 530,
    IBAT1L = 531,
    IBAT2U = 532,
    IBAT2L = 533,
    IBAT3U = 534,
    IBAT3L = 535,
    DBAT0U = 536,
    DBAT0L = 537,
    DBAT1U = 538,
    DBAT1L = 539,
    DBAT2U = 540,
    DBAT2L = 541,
    DBAT3U = 542,
    DBAT3L = 543,
    IBAT4U = 560,
    IBAT4L = 561,
    IBAT5U = 562,
    IBAT5L = 563,
    IBAT6U = 564,
    IBAT6L = 565,
    IBAT7U = 566,
    IBAT7L = 567,
    DBAT4U = 568,
    DBAT4L = 569,
    DBAT5U = 570,
    DBAT5L = 571,
    DBAT6U = 572,
    DBAT6L = 573,
    DBAT7U = 574,
    DBAT7L = 575,
    GQR0   = 912,
    GQR1   = 913,
    GQR2   = 914,
    GQR3   = 915,
    GQR4   = 916,
    GQR5   = 917,
    GQR6   = 918,
    GQR7   = 919,
    HID2   = 920,
    WPAR   = 921,
    DMAU   = 922,
    DMAL   = 923,
    UMMCR0 = 936,
    UPMC1  = 937,
    UPMC2  = 938,
    USIA   = 939,
    UMMCR1 = 940,
    UPMC3  = 941,
    UPMC4  = 942,
    HID5   = 944,
    BCR    = 949,
    MMCR0  = 952,
    PMC1   = 953,
    PMC2   = 954,
    SIA    = 955,
    MMCR1  = 956,
    PMC3   = 957,
    PMC4   = 958,
    HID0   = 1008,
    HID1   = 1009,
    IABR   = 1010,
    HID4   = 1011,
    TDCL   = 1012,
    DABR   = 1013,
    L2CR   = 1017,
    TDCU   = 1018,
    ICTC   = 1019,
    THRM1  = 1020,
    THRM2  = 1021,
    THRM3  = 1022,
};

struct bat {
    static constexpr int address_shift = 17;
    static constexpr u32 min_size      = 0x20000;

    /* U 0-14  */ u64    BEPI    : 15  = 0;
    /* U 15-18 */ u64    RESV15U : 4   = 0;
    /* U 19-29 */ u64    BL      : 11  = 0;
    /* U 30    */ u64    VS      : 1   = 0;
    /* U 31    */ u64    VP      : 1   = 0;
    /* L 0-14  */ u64    BRPN    : 15  = 0;
    /* L 15-24 */ u64    RESV15L : 10  = 0;
    /* L 25    */ u64    W       : 1   = 0;
    /* L 26    */ u64    I       : 1   = 0;
    /* L 27    */ u64    M       : 1   = 0;
    /* L 28    */ u64    G       : 1   = 0;
    /* L 29    */ u64    RESV29L : 1   = 0;
    /* L 30-31 */ u64    PP      : 2   = 0;

    enum pp {
        no_access          = 0,
        read_only          = 1,
        read_write         = 2,
        instruction_access = 2,
    };

    enum bl {
        bl_001ffff = 0b000'0000'0000,
        bl_003ffff = 0b000'0000'0001,
        bl_007ffff = 0b000'0000'0011,
        bl_00fffff = 0b000'0000'0111,
        bl_01fffff = 0b000'0000'1111,
        bl_03fffff = 0b000'0001'1111,
        bl_07fffff = 0b000'0011'1111,
        bl_0ffffff = 0b000'0111'1111,
        bl_1ffffff = 0b000'1111'1111,
        bl_3ffffff = 0b001'1111'1111,
        bl_7ffffff = 0b011'1111'1111,
        bl_fffffff = 0b111'1111'1111,
    };
};

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

} // namespace slu::ppc
