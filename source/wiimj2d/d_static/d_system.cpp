// d_system.cpp
// NSMBW .text: 0x800E46E0 - 0x800E5510

#include "d_system.h"

#include "slu/revision.hpp"
#include <egg/core/eggController.h>
#include <revolution/dvd.h>
#include <revolution/pad.h>

[[nsmbw_data(0x8042A370)]]
EGG::ExpHeap* dSys_c::ms_RootHeapMem1;

[[nsmbw_data(0x8042A374)]]
EGG::ExpHeap*               dSys_c::ms_RootHeapMem2;

const dSys_c::CODE_REGION_e dSys_c::m_codeRegion = findCodeRegion();

[[nsmbw_symbol(0x800E46E0, "#CAE882A9")]];

[[nsmbw_symbol(0x800E4750, "beginRender__6dSys_cFv")]];

[[nsmbw_symbol(0x800E4770, "endRender__6dSys_cFv")]];

[[nsmbw_symbol(0x800E47D0, "beginFrame__6dSys_cFv")]];

[[nsmbw_symbol(0x800E4820, "onBeginFrame__Q23EGG17ConfigurationDataFv")]];

[[nsmbw_symbol(0x800E4830, "endFrame__6dSys_cFv")]];

[[nsmbw_symbol(0x800E4880, "onEndFrame__Q23EGG17ConfigurationDataFv")]];

[[nsmbw_symbol(0x800E4890, "setBlack__6dSys_cFb")]];

[[nsmbw_symbol(0x800E4910, "calcAudio__6dSys_cFv")]];

[[nsmbw_symbol(0x800E4920, "setFrameRate__6dSys_cFUc")]];

[[nsmbw_symbol(0x800E4940, "setClearColor__6dSys_cFQ34nw4r2ut5Color")]];

[[nsmbw_symbol(0x800E4990, "getClearColor__6dSys_cFv")]];

[[nsmbw_symbol(0x800E49C0, "create__6dSys_cFv")]];

[[nsmbw_symbol(0x800E4C40, "setPosParam__Q23EGG14CoreControllerFff")]];

[[nsmbw_symbol(
    0x800E4C50, "initialize__Q33EGG126TSystem<Q23EGG5Video,Q23EGG12AsyncDisplay,Q23EGG10XfbManager,"
                "Q23EGG14SimpleAudioMgr,Q23EGG12SceneManager,Q23EGG12ProcessMeter>13ConfigurationFv"
)]];

[[nsmbw_symbol(0x800E4EC0, "myDylinkInitPhase_0__22@unnamed@d_system_cpp@FPv")]];

[[nsmbw_symbol(0x800E4EF0, "myDylinkInitPhase_1__22@unnamed@d_system_cpp@FPv")]];

[[nsmbw_symbol(0x800E4F20, "myDylinkInitPhase_4__22@unnamed@d_system_cpp@FPv")]];

[[nsmbw_symbol(0x800E4F50, "execute__6dSys_cFv")]];

namespace dSystem {

[[nsmbw_symbol(0x800E50C0, "createEffectManagerPhase1__7dSystemFPv")]];

[[nsmbw_symbol(0x800E5170, "createEffectManagerPhase2__7dSystemFPv")]];

[[nsmbw_symbol(0x800E51E0, "createFontManagerPhase__7dSystemFPv")]];

[[nsmbw_symbol(0x800E5220, "createMessageManagerPhase__7dSystemFPv")]];

[[nsmbw_symbol(0x800E52B0, "fixArena__7dSystemFv")]];

[[nsmbw_symbol(0x800E5310, "fixHeapsSub__7dSystemFPQ23EGG7ExpHeapi")]];

[[nsmbw_symbol(0x800E53E0, "fixHeaps__7dSystemFv")]];

} // namespace dSystem

dSys_c::CODE_REGION_e dSys_c::findCodeRegion() {
    slu::determine_revision();
    return slu::get_revision();
}

[[nsmbw_symbol(0x800E5440, "__sinit_\\d_system_cpp")]];
