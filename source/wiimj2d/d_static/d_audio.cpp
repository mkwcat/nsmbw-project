// d_audio.cpp
// NSMBW .text: 0x80069500 - 0x8006C0B0
// NSMBW .bss:  0x803561E8 - 0x80356208

#include "d_audio.h"

#include "d_static/d_mj2d_game.h"
#include "machine/m_vec.h"
#include <mkwcat/Relocate.hpp>

namespace dAudio
{

[[nsmbw_data(0x8042A03C)]]
SndObjctCmnEmy_c* g_pSndObjEmy;

[[nsmbw_data(0x8042A040)]]
SndObjctCmnMap_c* g_pSndObjMap;

/* 0x803561F8 */
NonPosSndObjctPly_c* g_pNonPosSndObjctPly[PLAYER_COUNT];

[[nsmbw(0x80069520)]] [[nodiscard]]
bool isForbidRemoteSE();

[[nsmbw(0x80069530)]]
u32 getRemotePlayer(int player)
{
    if (isForbidRemoteSE()) {
        return 0;
    }

    if (player >= 4) {
        return 0;
    }

    return 0b10 << player;
}

[[nsmbw(0x8006A3F0)]]
mVec2_c cvtSndObjctPos(const mVec2_c& pos);

[[nsmbw(0x8006A4B0)]]
mVec2_c cvtSndObjctPos(const mVec3_c& pos);

[[nsmbw(0x8006A7D0)]]
void pauseMove(int player);

[[nsmbw(0x8006A7F0)]]
void pauseOffMove(int player);

/* VT+0x08 - Moved here */
[[nsmbw(0x80104160)]]
SndObjctCSPly_c::~SndObjctCSPly_c()
{
}

PATCH_REFERENCES(
  &g_pNonPosSndObjctPly, //
  {
    {0x80069E66, R_PPC_ADDR16_HA},
    {0x80069E76, R_PPC_ADDR16_LO},
    {0x8006A02A, R_PPC_ADDR16_HA},
    {0x8006A02E, R_PPC_ADDR16_LO},
    {0x800D72D2, R_PPC_ADDR16_HA},
    {0x800D72E2, R_PPC_ADDR16_LO},
    {0x800D7356, R_PPC_ADDR16_HA},
    {0x800D7366, R_PPC_ADDR16_LO},
    {0x800D73B6, R_PPC_ADDR16_HA},
    {0x800D73BA, R_PPC_ADDR16_LO},
  }
)

} // namespace dAudio
