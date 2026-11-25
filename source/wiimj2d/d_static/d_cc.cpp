// d_cc.cpp
// NSMBW .text: 0x8008C200 - 0x8008DC80

#include "d_cc.h"

#include "d_actor.h"

[[nsmbw_data(0x8042A140)]]
dCc_c* dCc_c::mEntryN;

[[nsmbw_data(0x8042A144)]]
dCc_c* dCc_c::mEntryB;

[[nsmbw(0x8008C200)]]
dCc_c::dCc_c();

[[nsmbw(0x8008C260)]]
dCc_c::~dCc_c();

[[nsmbw(0x8008C2C0)]]
void dCc_c::clear();

[[nsmbw(0x8008C330)]]
void dCc_c::entry();

[[nsmbw(0x8008C380)]]
void dCc_c::release();

[[nsmbw(0x8008C3E0)]]
void dCc_c::set(dActor_c* actor, sCcDatNewF* collInfo);

[[nsmbw(0x8008C440)]]
void dCc_c::set(dActor_c* actor, sCcDatNewF* collInfo, u8 amiLine);

[[nsmbw(0x8008C6E0)]]
bool dCc_c::checkCollision(dCc_c* c1, dCc_c* c2, int active);

[[nsmbw(0x8008C9E0)]]
void dCc_c::execute() {
    for (dCc_c* c1 = mEntryN; c1 != nullptr; c1 = c1->mpNext) {
        for (dCc_c* c2 = c1->mpNext; c2 != nullptr; c2 = c2->mpNext) {
            c1->mpOwner->checkNoCollide(c2->mpOwner) || checkCollision(c1, c2, 1);
        }
    }
}
