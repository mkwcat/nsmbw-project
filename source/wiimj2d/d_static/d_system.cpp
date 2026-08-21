// d_system.cpp
// NSMBW .text: 0x800E46E0 - 0x800E5510

#include "d_system.h"

#include <egg/core/eggController.h>
#include <revolution/dvd.h>
#include <revolution/pad.h>

[[nsmbw_data(0x8042A370)]]
EGG::ExpHeap* dSys_c::ms_RootHeapMem1;

[[nsmbw_data(0x8042A374)]]
EGG::ExpHeap*               dSys_c::ms_RootHeapMem2;

const dSys_c::CODE_REGION_e dSys_c::m_codeRegion = findCodeRegion();

EXTERN_SYMBOL(0x800E46E0, "#CAE882A9");

EXTERN_SYMBOL(0x800E4750, "beginRender__6dSys_cFv");

EXTERN_SYMBOL(0x800E4770, "endRender__6dSys_cFv");

EXTERN_SYMBOL(0x800E47D0, "beginFrame__6dSys_cFv");

EXTERN_SYMBOL(0x800E4820, "onBeginFrame__Q23EGG17ConfigurationDataFv");

EXTERN_SYMBOL(0x800E4830, "endFrame__6dSys_cFv");

EXTERN_SYMBOL(0x800E4880, "onEndFrame__Q23EGG17ConfigurationDataFv");

EXTERN_SYMBOL(0x800E4890, "setBlack__6dSys_cFb");

EXTERN_SYMBOL(0x800E4910, "calcAudio__6dSys_cFv");

EXTERN_SYMBOL(0x800E4920, "setFrameRate__6dSys_cFUc");

EXTERN_SYMBOL(0x800E4940, "setClearColor__6dSys_cFQ34nw4r2ut5Color");

EXTERN_SYMBOL(0x800E4990, "getClearColor__6dSys_cFv");

EXTERN_SYMBOL(0x800E49C0, "create__6dSys_cFv");

EXTERN_SYMBOL(0x800E4C40, "setPosParam__Q23EGG14CoreControllerFff");

EXTERN_SYMBOL(
    0x800E4C50, "initialize__Q33EGG126TSystem<Q23EGG5Video,Q23EGG12AsyncDisplay,Q23EGG10XfbManager,"
                "Q23EGG14SimpleAudioMgr,Q23EGG12SceneManager,Q23EGG12ProcessMeter>13ConfigurationFv"
);

EXTERN_SYMBOL(0x800E4EC0, "myDylinkInitPhase_0__22@unnamed@d_system_cpp@FPv");

EXTERN_SYMBOL(0x800E4EF0, "myDylinkInitPhase_1__22@unnamed@d_system_cpp@FPv");

EXTERN_SYMBOL(0x800E4F20, "myDylinkInitPhase_4__22@unnamed@d_system_cpp@FPv");

EXTERN_SYMBOL(0x800E4F50, "execute__6dSys_cFv");

namespace dSystem {

EXTERN_SYMBOL(0x800E50C0, "createEffectManagerPhase1__7dSystemFPv");

EXTERN_SYMBOL(0x800E5170, "createEffectManagerPhase2__7dSystemFPv");

EXTERN_SYMBOL(0x800E51E0, "createFontManagerPhase__7dSystemFPv");

EXTERN_SYMBOL(0x800E5220, "createMessageManagerPhase__7dSystemFPv");

EXTERN_SYMBOL(0x800E52B0, "fixArena__7dSystemFv");

EXTERN_SYMBOL(0x800E5310, "fixHeapsSub__7dSystemFPQ23EGG7ExpHeapi");

EXTERN_SYMBOL(0x800E53E0, "fixHeaps__7dSystemFv");

} // namespace dSystem

dSys_c::CODE_REGION_e dSys_c::findCodeRegion() {
    switch (*reinterpret_cast<volatile u8*>(0x8000423A)) {
    case 0xFF:
        // PAL (P)
        if (*reinterpret_cast<volatile u8*>(0x800CF287) == 0x30) {
            return CODE_REGION_e::P1;
        } else /* if (c == 0x38) */ {
            return CODE_REGION_e::P2;
        }

    case 0xFC:
        // USA (E)
        if (*reinterpret_cast<volatile u8*>(0x800CF197) == 0x30) {
            return CODE_REGION_e::E1;
        } else /* if (c == 0x38) */ {
            return CODE_REGION_e::E2;
        }
        break;

    case 0xF9:
        // JPN (J)
        if (*reinterpret_cast<volatile u8*>(0x800CF117) == 0x30) {
            return CODE_REGION_e::J1;
        } else /* if (c == 0x38) */ {
            return CODE_REGION_e::J2;
        }

    case 0xC8:
        // KOR (K)
        return CODE_REGION_e::K;

    case 0xAC:
        // TWN (W)
        return CODE_REGION_e::W;

    case 0x55:
        // CHN (C)
        return CODE_REGION_e::C;
    }

    return CODE_REGION_e::Error;
}

EXTERN_SYMBOL(0x800E5440, "__sinit_\\d_system_cpp");
