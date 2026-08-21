// d_game_key.cpp
// NSMBW .text: 0x800B5930 - 0x800B5B50

#include "d_game_key.h"

#include "d_static/d_game_key/d_game_key_core.h"
#include "machine/m_heap.h"
#include "machine/m_pad.h"

[[nsmbw_data_noconstinit(0x8042A230)]]
dGameKey_c* dGameKey_c::m_instance = [](mHeap::ScopeHeap_c = 0) {
    return new dGameKey_c(m_instance);
}();

[[nsmbw(0x800B5930)]]
void dGameKey_c::createInstance(EGG::Heap* heap);

[[nsmbw(0x800B5980)]]
dGameKey_c::dGameKey_c() {
    static constexpr mPad::CH_e s_channels[8] = {
        mPad::CH_e::CHAN_0,    mPad::CH_e::CHAN_1,    mPad::CH_e::CHAN_2,    mPad::CH_e::CHAN_3,
        mPad::CH_e::CHAN_GC_0, mPad::CH_e::CHAN_GC_1, mPad::CH_e::CHAN_GC_2, mPad::CH_e::CHAN_GC_3,
    };

    for (int i = 0; i < CORE_COUNT; i++) {
        mpCores[i] = new dGameKeyCore_c(s_channels[i % std::size(s_channels)]);
    }
}

dGameKey_c::dGameKey_c(
    dGameKey_c* old
) {
    static constexpr mPad::CH_e s_channels[8] = {
        mPad::CH_e::CHAN_0,    mPad::CH_e::CHAN_1,    mPad::CH_e::CHAN_2,    mPad::CH_e::CHAN_3,
        mPad::CH_e::CHAN_GC_0, mPad::CH_e::CHAN_GC_1, mPad::CH_e::CHAN_GC_2, mPad::CH_e::CHAN_GC_3,
    };

    int i = 0;
    if (old) {
        for (; i < 4; i++) {
            mpCores[i] = old->mpCores[i];
        }
    }
    for (; i < CORE_COUNT; i++) {
        mpCores[i] = new dGameKeyCore_c(s_channels[i % std::size(s_channels)]);
    }

    operator delete(old);
}

/* VT+0x8 */
[[nsmbw(0x800B5A00)]]
dGameKey_c::~dGameKey_c() {
    for (int i = 0; i < CORE_COUNT; i++) {
        delete mpCores[i];
    }
}

[[nsmbw(0x800B5AB0)]]
void dGameKey_c::allclear() {
    for (int i = 0; i < CORE_COUNT; i++) {
        mpCores[i]->allclear();
    }
}

[[nsmbw(0x800B5B00)]]
int dGameKey_c::read() {
    for (int i = 0; i < CORE_COUNT; i++) {
        mpCores[i]->read();
    }
    return 0;
}
