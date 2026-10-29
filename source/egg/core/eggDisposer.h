#pragma once

namespace EGG {

class Disposer {
    SIZE_ASSERT(0x10);

public:
    Disposer(const Disposer&)     = delete;
    Disposer(Disposer&&) noexcept = delete;

    Disposer();
    virtual ~Disposer();

private:
    u8 FILL(0x04, 0x10);
};

} // namespace EGG
