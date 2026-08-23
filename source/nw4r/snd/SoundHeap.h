#pragma once

namespace nw4r::snd {

class SoundHeap {
public:
    // Virtual Functions
    // ^^^^^^

    /* VT+0x8 0x8027A3E0 */
    virtual ~SoundHeap();

    /* VT+0xC */
    [[nsmbw(0x8027A470)]]
    virtual void* Alloc(u32 size);
};

} // namespace nw4r::snd
