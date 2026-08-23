#pragma once

namespace EGG {

class Disposer {
    SIZE_ASSERT(0x10);

    /* 0x00 VTABLE 0x80350160 */

public:
    Disposer(const Disposer&)     = delete;
    Disposer(Disposer&&) noexcept = delete;

    /* 0x802BA410 */
    Disposer();

    /* VT+0x8 0x802BA470 */
    virtual ~Disposer();

private:
    FILL(0x04, 0x10);
};

} // namespace EGG
