#pragma once

#include <nw4r/db/db_console.h>

class dException_c {
public:
    static bool callback(nw4r::db::ConsoleHandle console, void* userdata);
    static void dumpFile(nw4r::db::ConsoleHandle console);
};
