#pragma once

#include <nw4r/db/console.h>

namespace EGG {

class Heap;

class Exception {
public:
    static void create(u16, u16, u16, EGG::Heap*, int);
    static void setPadInfo(const u16*);
    static bool ExceptionCallback_(nw4r::db::ConsoleHandle console, void* userdata);
};

} // namespace EGG
