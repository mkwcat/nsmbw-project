// d_a_reverseblock.cpp
// NSMBW d_bases.text: 0x80897F60 - 0x808984D0

#include "d_a_reverseblock.h"

#include "d_a_player.h"

[[nsmbw(0x80897F60)]]
daReverseBlock_c* daReverseBlock_c_classInit() {
    return new daReverseBlock_c();
}

[[nsmbw(0x80897FD0)]]
fBase_c::PACK_RESULT_e daReverseBlock_c::create();

[[nsmbw(0x80898190)]]
fBase_c::PACK_RESULT_e daReverseBlock_c::execute() {
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (auto player = daPyMng_c::getPlayer(i); player && !player->isStatus(50)) {
            updatePlayer(player, i);
        }
    }
    resetPlayerData();

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80898230)]]
fBase_c::PACK_RESULT_e daReverseBlock_c::doDelete() {
    mCc0.release();
    mCc1.release();
    mCc2.release();

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80898280)]]
void daReverseBlock_c::resetPlayerData() {
    mPlayerData.fill(0);
}

[[nsmbw(0x808983E0)]]
void daReverseBlock_c::updatePlayer(dAcPy_c* player, int index);

[[nsmbw(0x80898450)]]
daReverseBlock_c::~daReverseBlock_c() {
#ifndef __has_macintosh_dt_fix
    mCc0.~dCc_c();
    mCc1.~dCc_c();
    mCc2.~dCc_c();
#endif
}
