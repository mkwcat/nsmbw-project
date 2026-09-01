// d_a_ship_gear.cpp
// NSMBW d_bases.text: 0x808A1FD0 - 0x808A2940

#include "d_a_ship_gear.h"

#include "d_a_player_base.h"
#include <algorithm>
#include <iterator>
#include <mkwcat/VTable.hpp>
#include <nw4r/math/triangular.h>
#include <nw4r/math/types.h>

[[nsmbw(0x808A1FD0)]]
fBase_c* daShipGear_c_classInit() {
    return new daShipGear_c;
}

daShipGear_c::daShipGear_c() {
    mkwcat::VTable::Fix<fBase_c>(this);
}

[[nsmbw(0x808A2380)]]
void daShipGear_c::setRideOn(
    dActor_c* actor
) {
    if (daPlBase_c* pl = actor->DynamicCast<daPlBase_c>()) {
        m_plrRideOn[pl->getPlrNo()] = true;
    }
}

[[nsmbw(0x808A24B0)]]
void daShipGear_c::executeRide() {
    m_exitRide = false;

    std::fill(std::begin(m_plrOffset), std::end(m_plrOffset), 0.0);

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(!m_plrRideOn[i] && m_plrRideOnPrev[i])) {
            continue;
        }
        float f = m_bgScale * 160.0;
        f *= nw4r::math::SinIdx(m_rotSpeed);
        if (mDirection == 0) {
            f = -f;
        }
        m_plrOffset[i] = f / 2.0;
        m_exitRide     = true;
    }

    std::copy(std::begin(m_plrRideOn), std::end(m_plrRideOn), std::begin(m_plrRideOnPrev));
}
