#pragma once

#include <revolution/gx/GXEnum.h>
#include <revolution/gx/GXStruct.h>

namespace EGG {

class StateGX {
public:
    // Static Methods
    // ^^^^^^

    [[nsmbw(0x802D34F0)]]
    static void GXSetViewport_(f32, f32, f32, f32, f32, f32);

    static GXPixelFmt getDefaultPixelFormat() { return s_pixFormat; }

    static void setDefaultPixelFormat(
        GXPixelFmt fmt
    ) {
        s_pixFormat = fmt;
    }

    static const GXColor& getEfbClearColor() { return s_clearEfb; }

    static void setEfbClearColor(
        const GXColor& rColor
    ) {
        s_clearEfb = rColor;
    }

private:
    [[mkw_data(0x80386F4C)]] static inline GXPixelFmt s_pixFormat;
    [[mkw_data(0x80386F5C)]] static inline GXColor    s_clearEfb{};
};

} // namespace EGG
