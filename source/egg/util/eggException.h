#pragma once

#include <nw4r/db/db_console.h>

namespace EGG {

class Exception {
public:
    /* 0x802D74E0 */
    static bool ExceptionCallback_(nw4r::db::ConsoleHandle console, void* userdata);
};

} // namespace EGG
