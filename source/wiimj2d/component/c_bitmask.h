#pragma once

#include <bit>
#include <concepts>
#include <iterator>

template <typename T>
concept cBitMaskType_x = requires(T a) {
    { a.checkBit(0) } -> std::same_as<bool>;
};

/**
 * Utility class for large bitmasks. Not from the base game.
 */
template <int Bits = 32>
class cBitmask_c {
private:
    static constexpr u32 testSizeType()
        requires(Bits > 16)
    {
        return 0;
    }

    static constexpr u16 testSizeType()
        requires(Bits > 8 && Bits <= 16)
    {
        return 0;
    }

    static constexpr u8 testSizeType()
        requires(Bits <= 8)
    {
        return 0;
    }

public:
    using value_type = decltype(testSizeType());

    static constexpr bool checkBit(
        cBitMaskType_x auto bitmask, u32 bit
    ) {
        return bitmask.checkBit(bit);
    }

    static constexpr bool checkBit(
        std::integral auto bitmask, u32 bit
    ) {
        return std::rotr(bitmask, bit) & 1;
    }

    constexpr bool checkBit(
        u32 bit
    ) const {
        if constexpr (Bits <= 32) {
            return std::rotr(mData[0], bit) & 1;
        } else if constexpr (Bits <= 64) {
            // OR optimization
            return (std::rotr(mData[0], bit) | std::rotr(mData[1], bit - 32)) & 1;
        } else if constexpr (Bits <= 96) {
            // OR optimization
            return (std::rotr(mData[0], bit) | std::rotr(mData[1], bit - 32) |
                    std::rotr(mData[2], bit - 64)) &
                   1;
        } else {
            // More than 96 bits, get index by divide
            u32 index = ((Bits >> 5) - 1) - (bit >> 5);
            return std::rotr(mData[index], bit & ~31) & 1;
        }
    }

    constexpr bool operator[](
        u32 bit
    ) const {
        return checkBit(bit);
    }

    constexpr void setBit(
        u32 bit
    ) {
        if constexpr (Bits <= 32) {
            mData[0] |= std::rotl(1u, bit);
        } else if constexpr (Bits <= 64) {
            mData[0] |= std::rotl(1u, bit);
            mData[1] |= std::rotl(1u, bit - 32);
        } else if constexpr (Bits <= 96) {
            mData[0] |= std::rotl(1u, bit);
            mData[1] |= std::rotl(1u, bit - 32);
            mData[2] |= std::rotl(1u, bit - 64);
        } else {
            u32 index = ((Bits >> 5) - 1) - (bit >> 5);
            mData[index] |= std::rotl(1u, bit - (bit & ~31));
        }
    }

    constexpr void clearBit(
        u32 bit
    ) {
        if constexpr (Bits <= 32) {
            mData[0] &= ~std::rotl(1u, bit);
        } else if constexpr (Bits <= 64) {
            mData[0] &= ~std::rotl(1u, bit);
            mData[1] &= ~std::rotl(1u, bit - 32);
        } else if constexpr (Bits <= 96) {
            mData[0] &= ~std::rotl(1u, bit);
            mData[1] &= ~std::rotl(1u, bit - 32);
            mData[2] &= ~std::rotl(1u, bit - 64);
        } else {
            u32 index = ((Bits >> 5) - 1) - (bit >> 5);
            mData[index] &= ~std::rotl(1u, bit - (bit & ~31));
        }
    }

    constexpr int popCount() const {
        int count = 0;
        for (std::size_t i = 0; i < std::size(mData); i++) {
            count += std::popcount(mData[i]);
        }
        return count;
    }

private:
    value_type mData[(Bits + 31) / 32] = {};
};

#define cBitmask_c_EXPR_TEST_COND(_Expr, _Result) (((_Expr) & 1) * (_Result))

#define cBitmask_c_SIZE_ASM(_Bits) \
    (cBitmask_c_EXPR_TEST_COND((_Bits) <= 8, 1) | \
     cBitmask_c_EXPR_TEST_COND((_Bits) > 8 && (_Bits) <= 16, 2) | \
     cBitmask_c_EXPR_TEST_COND((_Bits) > 16, ((_Bits + 31) >> 3) & ~3))

#define cBitmask_c_ASM_COPY(_Bits, _DestPtrReg, _DestOffset, _SrcPtrReg, _SrcOffset, _ScratchReg) \
    .if ((_Bits) <= 8); \
    lbz _ScratchReg, (_SrcOffset) (_SrcPtrReg); \
    stb _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 16); \
    lhz _ScratchReg, (_SrcOffset) (_SrcPtrReg); \
    sth _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 32); \
    lwz _ScratchReg, (_SrcOffset) (_SrcPtrReg); \
    stw _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .else; \
    lwzu _ScratchReg, (_SrcOffset) (_SrcPtrReg); \
    stwu _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .rept((_Bits) - 1) >> 5; \
    lwzu _ScratchReg, 4(_SrcPtrReg); \
    stwu _ScratchReg, 4(_DestPtrReg); \
    .endr; \
    subi _SrcPtrReg, _SrcPtrReg, (_SrcOffset) + 4 * (((_Bits) - 1) >> 5); \
    subi _DestPtrReg, _DestPtrReg, (_DestOffset) + 4 * (((_Bits) - 1) >> 5); \
    .endif;

#define cBitmask_c_ASM_CLEAR(_Bits, _DestPtrReg, _DestOffset, _ZeroReg) \
    .if ((_Bits) <= 8); \
    stb _ZeroReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 16); \
    sth _ZeroReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 32); \
    stw _ZeroReg, (_DestOffset) (_DestPtrReg); \
    .else; \
    stwu _ZeroReg, (_DestOffset) (_DestPtrReg); \
    .rept((_Bits) - 1) >> 5; \
    stwu _ZeroReg, 4(_DestPtrReg); \
    .endr; \
    subi _DestPtrReg, _DestPtrReg, _DestOffset + 4 * (((_Bits) - 1) >> 5); \
    .endif;

#define cBitmask_c_ASM_SET_BIT_REG( \
    _Bits, _DestPtrReg, _DestOffset, _BitReg, _ScratchReg, _ScratchReg2, _ScratchReg3 \
) \
    .if ((_Bits) <= 8); \
    lbz _ScratchReg, (_DestOffset) (_DestPtrReg); \
    li  _ScratchReg2, 1; \
    slw _ScratchReg2, _ScratchReg2, _BitReg; \
    or _ScratchReg, _ScratchReg, _ScratchReg2; \
    stb _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 16); \
    lhz _ScratchReg, (_DestOffset) (_DestPtrReg); \
    li  _ScratchReg2, 1; \
    slw _ScratchReg2, _ScratchReg2, _BitReg; \
    or _ScratchReg, _ScratchReg, _ScratchReg2; \
    sth _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 32); \
    lwz _ScratchReg, (_DestOffset) (_DestPtrReg); \
    li  _ScratchReg2, 1; \
    slw _ScratchReg2, _ScratchReg2, _BitReg; \
    or _ScratchReg, _ScratchReg, _ScratchReg2; \
    stw _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .else; \
    li     _ScratchReg2, 1; \
    rlwinm _ScratchReg, _BitReg, 0, ~31; \
    slw    _ScratchReg2, _ScratchReg2, _BitReg; \
    rlwinm _ScratchReg, _BitReg, 32 - 3, ~3; \
    subfic _ScratchReg3, _ScratchReg, (((_Bits - 1) >> 3) & ~3) + (_DestOffset); \
    lwzx   _ScratchReg, _DestPtrReg, _ScratchReg3; \
    or _ScratchReg, _ScratchReg, _ScratchReg2; \
    stwx _ScratchReg, _DestPtrReg, _ScratchReg3; \
    .endif;

#define cBitmask_c_ASM_CLEAR_BIT_REG( \
    _Bits, _DestPtrReg, _DestOffset, _BitReg, _ScratchReg, _ScratchReg2, _ScratchReg3 \
) \
    .if ((_Bits) <= 8); \
    lbz _ScratchReg, (_DestOffset) (_DestPtrReg); \
    li  _ScratchReg2, 1; \
    slw _ScratchReg2, _ScratchReg2, _BitReg; \
    not _ScratchReg2, _ScratchReg2; \
    and _ScratchReg, _ScratchReg, _ScratchReg2; \
    stb _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 16); \
    lhz _ScratchReg, (_DestOffset) (_DestPtrReg); \
    li  _ScratchReg2, 1; \
    slw _ScratchReg2, _ScratchReg2, _BitReg; \
    not _ScratchReg2, _ScratchReg2; \
    and _ScratchReg, _ScratchReg, _ScratchReg2; \
    sth _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .elseif((_Bits) <= 32); \
    lwz _ScratchReg, (_DestOffset) (_DestPtrReg); \
    li  _ScratchReg2, 1; \
    slw _ScratchReg2, _ScratchReg2, _BitReg; \
    not _ScratchReg2, _ScratchReg2; \
    and _ScratchReg, _ScratchReg, _ScratchReg2; \
    stw _ScratchReg, (_DestOffset) (_DestPtrReg); \
    .else; \
    li     _ScratchReg2, 1; \
    rlwinm _ScratchReg, _BitReg, 0, ~31; \
    slw    _ScratchReg2, _ScratchReg2, _BitReg; \
    rlwinm _ScratchReg, _BitReg, 32 - 3, ~3; \
    subfic _ScratchReg3, _ScratchReg, (((_Bits - 1) >> 3) & ~3) + (_DestOffset); \
    lwzx   _ScratchReg, _DestPtrReg, _ScratchReg3; \
    not _ScratchReg2, _ScratchReg2; \
    and _ScratchReg, _ScratchReg, _ScratchReg2; \
    stwx _ScratchReg, _DestPtrReg, _ScratchReg3; \
    .endif;

#define cBitmask_c_ASM_CHECK_BIT_REG(_Bits, _DestPtrReg, _DestOffset, _BitReg, _ResultReg) \
    .if ((_Bits) <= 8); \
    lbz _ResultReg, (_DestOffset) (_DestPtrReg); \
    rlwnm._ResultReg, _ResultReg, _BitReg, 1; \
    .elseif((_Bits) <= 16); \
    lhz _ResultReg, (_DestOffset) (_DestPtrReg); \
    rlwnm._ResultReg, _ResultReg, _BitReg, 1; \
    .elseif((_Bits) <= 32); \
    lwz _ResultReg, (_DestOffset) (_DestPtrReg); \
    rlwnm._ResultReg, _ResultReg, _BitReg, 1; \
    .else; \
    rlwinm _ResultReg, _BitReg, 32 - 3, ~3; \
    subfic _ResultReg, _ResultReg, (((_Bits - 1) >> 3) & ~3) + (_DestOffset); \
    lwzx   _ResultReg, _DestPtrReg, _ResultReg; \
    rlwnm._ResultReg, _ResultReg, _BitReg, 1; \
    .endif;
