#pragma once

#include "System.h"
#include <revolution/gx/GXStruct.h>

namespace nw4r::ut
{

struct Color : GXColor {
    constexpr Color(u8 r = 0, u8 g = 0, u8 b = 0, u8 a = 255)
    {
        r = r;
        g = g;
        b = b;
        a = a;
    }

    constexpr Color(const char (&colorCode)[8], u8 alpha = 255)
    {
        a = alpha;

        if (colorCode[0] != '#') {
            r = 0;
            g = 0;
            b = 0;
            return;
        }

        u32 color = 0;
        for (int i = 1; i < 7; i++) {
            color <<= 4;
            char c = colorCode[i];
            if (c >= '0' && c <= '9') {
                color |= c - '0';
            } else if (c >= 'A' && c <= 'F') {
                color |= c - 'A' + 10;
            } else if (c >= 'a' && c <= 'f') {
                color |= c - 'a' + 10;
            }
        }

        r = (color >> 16) & 0xFF;
        g = (color >> 8) & 0xFF;
        b = color & 0xFF;
    }

    constexpr Color(const char (&colorCode)[10])
    {
        if (colorCode[0] != '#') {
            r = 0;
            g = 0;
            b = 0;
            a = 0;
            return;
        }

        u32 color = 0;
        for (int i = 1; i < 9; i++) {
            color <<= 4;
            char c = colorCode[i];
            if (c >= '0' && c <= '9') {
                color |= c - '0';
            } else if (c >= 'A' && c <= 'F') {
                color |= c - 'A' + 10;
            } else if (c >= 'a' && c <= 'f') {
                color |= c - 'a' + 10;
            }
        }

        r = (color >> 24) & 0xFF;
        g = (color >> 16) & 0xFF;
        b = (color >> 8) & 0xFF;
        a = color & 0xFF;
    }

    constexpr operator GXColorS10() const
    {
        return {r, g, b, a};
    }
};

} // namespace nw4r::ut