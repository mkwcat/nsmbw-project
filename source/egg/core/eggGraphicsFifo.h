#pragma once

namespace EGG {

class Heap;

class GraphicsFifo {
public:
    [[mkw(0x80229540)]] static void create(u32 size, EGG::Heap* heap);
};

} // namespace EGG
