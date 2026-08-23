#pragma once

#include "eggFrustum.h"

namespace EGG {

class Screen : public Frustum {
#ifndef CLANGD
    SIZE_ASSERT(0x88);
#endif

    /* 0x38 VTABLE */

public:
    // Structors
    // ^^^^^^

    /* 0x802D0FB0 */
    Screen();

    /* VT+0x08 */
    virtual ~Screen() {}

public:
    // Constants and Types
    // ^^^^^^

    enum TVMode {
        TV_MODE_4_3,
        TV_MODE_16_9,
        TV_MODE_UNK_3,
        TV_MODE_MAX,
    };

    struct TVModeInfo {
        u16              width;
        u16              height;
        nw4r::math::VEC2 ratios;
    };

public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x0C 0x802D1230 */
    virtual void SetProjectionGX() const;

public:
    // Instance Variables
    // ^^^^^^

    FILL(0x3C, 0x88);

public:
    // Static Methods
    // ^^^^^^

    static u16 GetSizeXMax(
        TVMode mode
    ) {
        return sTVModeInfo[mode].width;
    }

    static u16 GetSizeYMax(
        TVMode mode
    ) {
        return sTVModeInfo[mode].height;
    }

    static u16 GetSizeXMax() { return sTVModeInfo[sTVMode].width; }

    static u16 GetSizeYMax() { return sTVModeInfo[sTVMode].height; }

    static inline f32 GetAdjustScale() {
        return f64(sTVModeInfo[0].width) / f64(sTVModeInfo[Screen::sTVMode].width);
    }

    static inline f32 GetAdjustScale(
        TVMode mode
    ) {
        return f64(sTVModeInfo[0].width) / f64(sTVModeInfo[mode].width);
    }

    static inline f32 GetAdjustScale(
        TVMode rmode, TVMode lmode
    ) {
        return f64(sTVModeInfo[rmode].width) / f64(sTVModeInfo[lmode].width);
    }

    static TVMode GetTVMode() { return sTVMode; }

public:
    // Static Variables
    // ^^^^^^

    /* 0x8042B1E8 */ static TVMode     sTVMode;
    /* 0x80350820 */ static TVModeInfo sTVModeInfo[TVMode::TV_MODE_MAX];
};

} // namespace EGG
