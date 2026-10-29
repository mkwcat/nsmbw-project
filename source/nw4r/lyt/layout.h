#pragma once

#include <nw4r/ut/Rect.h>

namespace nw4r::lyt {

class Layout {
public:
    // Structors
    // ^^^^^^

    /* VT+0x08 */
    virtual ~Layout() = 0;

public:
    // Instance Methods
    // ^^^^^^

    [[nsmbw(0x802AD660)]]
    nw4r::ut::Rect GetLayoutRect() const;
};

}; // namespace nw4r::lyt
