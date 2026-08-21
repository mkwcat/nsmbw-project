// d_a_mask.cpp
// NSMBW .text: 0x80124EB0 - 0x80126650

#include "d_static/d_a_player_manager.h"

class daPlBase_c;

[[nsmbw(0x80126050)]]
daPlBase_c* daMask_c_GetPlayerP(void* this_) ASM_METHOD(
  // clang-format off
/* 80126060 88630392 */  lbz      r3, 0x392(r3);
/* 80126064          */  cmplwi   r3, PLAYER_COUNT;
/* 80126068          */  blt-     daMask_c_GetPlayerP_isPlayer;
/* 80126074 2C030007 */  cmpwi    r3, PLAYER_COUNT * 2;
/* 80126078          */  bge-     daMask_c_GetPlayerP_outNull;

daMask_c_GetPlayerP_isYoshi:;
/* 8012608C          */  subi     r3, r3, PLAYER_COUNT;
/* 80126090 4BF39AE1 */  b        UNDEF_8005Fb70; // getYoshiDirectP__9daPyMng_cFi
daMask_c_GetPlayerP_isPlayer:;
/* 80126080 4BF39881 */  b        getPlayer__9daPyMng_cFi;

daMask_c_GetPlayerP_outNull:;
                         li       r3, 0;
                         blr
  // clang-format on
);

[[nsmbw(0x801260B0)]]
bool daMask_c_isYoshi(u8* this_)
{
    return this_[0x392] >= PLAYER_COUNT && this_[0x392] < PLAYER_COUNT * 2;
}
