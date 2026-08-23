// d_a_reverse_block.cpp
// NSMBW d_bases.text: 0x80897F60 - 0x808984D0

#include "d_a_reverse_block.h"

#include "d_player/d_a_player.h"

[[nsmbw(0x80897F60)]]
daReverseBlock_c* daReverseBlock_c_classInit()
{
    return new daReverseBlock_c();
}

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x80897FD0)]]
fBase_c::PACK_RESULT_e daReverseBlock_c::create();

/**
 * VT+0x20
 * do method for the execute operation.
 */
[[nsmbw(0x80898190)]]
fBase_c::PACK_RESULT_e daReverseBlock_c::execute()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (auto player = daPyMng_c::getPlayer(i); player && !player->isStatus(50)) {
            updatePlayer(player, i);
        }
    }
    resetPlayerData();

    return PACK_RESULT_e::SUCCEEDED;
}

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[nsmbw(0x80898230)]]
fBase_c::PACK_RESULT_e daReverseBlock_c::doDelete()
{
    mCc0.release();
    mCc1.release();
    mCc2.release();

    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x80898280)]]
void daReverseBlock_c::resetPlayerData()
{
    mPlayerData.fill(0);
}

[[nsmbw(0x808983E0)]]
void daReverseBlock_c::updatePlayer(dAcPy_c* player, int index);

/**
 * VT+0x48
 * Destroys the base.
 */
[[nsmbw(0x80898450)]]
daReverseBlock_c::~daReverseBlock_c()
{
    mCc0.~dCc_c();
    mCc1.~dCc_c();
    mCc2.~dCc_c();
}