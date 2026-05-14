#pragma once

#include <cstdio>
#include <nw4r/db/db_console.h>
#include <variant>

class dException_c {
public:
    struct AssertInfo_s {
        const char* expr;
        const char* file;
        int         line;
    };

    static bool callback(nw4r::db::ConsoleHandle console, void* userdata);
    static void dumpFile(std::variant<nw4r::db::ConsoleHandle, AssertInfo_s> info);
    static void** checkStackAddr(void* stackPtr);
    static void printTrace(std::FILE* file, void* stackPtr);
    static const char* getProjectVersion();
    static const char* getRegionInfo();

    static constexpr char c_projectName[] = "nsmbw-project";
    static constexpr char c_issueUrl[]    = "https://github.com/mkwcat/nsmbw-project/issues";
};
