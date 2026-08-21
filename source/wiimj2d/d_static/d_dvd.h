#pragma once

namespace EGG
{
class Heap;
}

namespace dDvd
{

/* 0x8008F110 */
void create(s32, EGG::Heap*, EGG::Heap*);

class loader_c
{
public:
    // Structors
    // ^^^^^^

    /* 0x8008F140 */
    loader_c();

    /* VT+0x8 0x8008F170 */
    virtual ~loader_c();

public:
    // Virtual Methods
    // ^^^^^^

    /* VT+0xC 9x8008F380 */
    virtual void freeHeap();

public:
    // Instance Methods
    // ^^^^^^

    /* 0x8008F1B0 */
    void* request(const char* path, u8 direction, EGG::Heap* heap);

    /* 0x8008F2B0 */
    bool remove();

public:
    // Inline Instance Methods
    // ^^^^^^

    constexpr u32 getSize() const
    {
        return mSize;
    }

private:
    u32 mSize;
    u32 mCommand;
    EGG::Heap* mpHeap;
    void* mpBuffer;
};

} // namespace dDvd