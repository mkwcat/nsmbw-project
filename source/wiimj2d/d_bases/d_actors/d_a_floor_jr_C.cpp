// d_a_floor_jr_C.cpp
// NSMBW d_bases.text: 0x807F1A00 - 0x807F2D30

#include "d_a_floor_jr_C.h"

#include <mkwcat/Relocate.hpp>

[[nsmbw(0x807F1A00)]]
daFloorJrC_c* daFloorJrC_c_classInit()
{
    daFloorJrC_c* obj = new daFloorJrC_c;

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
#if PLAYER_COUNT > 7
        obj->m0x686[i] = false;
#endif
        obj->m0x68A[i] = false;
    }

    return obj;
}

[[nsmbw(0x807F20B0)]]
daFloorJrC_c::daFloorJrC_c();

[[nsmbw(0x807F28E0)]]
void daFloorJrC_c::clearPlayerInfo()
{
    m0x674 = m0x670;
    m0x670 = m0x66C;

    for (std::size_t i = 0; i < PLAYER_COUNT; i++) {
        m0x68A[i] = m0x686[i];
        m0x686[i] = false;
    }

    m0x685 = m0x684;
    m0x684 = 0;
}

[[nsmbw(0x807F2940)]]
bool daFloorJrC_c::checkPlayerFlag(int player)
{
    return m0x686[player] && !m0x68A[player];
}

#if PLAYER_COUNT > 7

PATCH_REFERENCES(
  offsetof(daFloorJrC_c, m0x686),
  {
    {0x807F1D68 + 2, R_PPC_ADDR16_LO},
  }
);

#endif
