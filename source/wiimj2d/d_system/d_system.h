#pragma once

#include <egg/core/eggExpHeap.h>
#include <mkwcat/Region.hpp>
#include <nw4r/ut/Color.h>
#include <revolution/arc.h>

class dSys_c {
public:
    // Constants and Types
    // ^^^^^^

    using CODE_REGION_e = mkwcat::Region;

public:
    // Static Methods
    // ^^^^^^

    /* 0x800E4940 */
    static void setClearColor(nw4r::ut::Color color);

    /* 0x800E4920 */
    static void setFrameRate(u8 rate);

    static CODE_REGION_e findCodeRegion();

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042A370 */
    static EGG::ExpHeap* ms_RootHeapMem1;

    /* 0x8042A374 */
    static EGG::ExpHeap*       ms_RootHeapMem2;

    static const CODE_REGION_e m_codeRegion;
};
