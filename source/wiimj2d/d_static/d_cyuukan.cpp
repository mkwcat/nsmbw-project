// d_cyuukan.cpp
// NSMBW .text: 0x8008ED70 - 0x8008F110

#include "d_cyuukan.h"

[[nsmbw(0x8008ED70)]]
dCyuukan_c::dCyuukan_c();

[[nsmbw(0x8008EDB0)]]
void dCyuukan_c::clear() {
    mFlags             = 0;
    mWorld             = WORLD_e(-1);
    mStage             = STAGE_e(-1);
    mCourse            = -1;
    mIsKinopioInChukan = false;
    mPlayerSetPos      = {};
    mIndex             = -1;
    for (int i = 0; i < std::size(mCollectionCoin); i++) {
        mCollectionCoin[i] = PLAYER_TYPE_e::COUNT;
    }
    for (int i = 0; i < std::size(mOwner); i++) {
        mOwner[i] = PLAYER_TYPE_e::COUNT;
    }
}

[[nsmbw(0x8008EE00)]]
void dCyuukan_c::courseIN();

[[nsmbw(0x8008EEC0)]]
bool dCyuukan_c::checkEntry() {
    return true;
}

[[nsmbw(0x8008F000)]]
bool dCyuukan_c::isCyuukanStart(int index, WORLD_e world, STAGE_e stage);

[[nsmbw(0x8008F070)]]
s8 dCyuukan_c::getPlrNo(int index) const;
