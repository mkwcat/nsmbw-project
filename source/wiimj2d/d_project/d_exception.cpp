// d_exception.cpp
// nsmbw-project

#include "d_exception.h"

#include "d_base_dump.h"
#include "machine/m_nandfile.h"
#include "machine/m_pipe.h"
#include "nw4r/db/db_console.h"
#include "nw4r/db/db_exception.h"
#include "revolution/os/OSThread.h"
#include <cstdio>
#include <egg/util/eggException.h>
#include <iterator>
#include <revolution/nand.h>
#include <revolution/os/OSError.h>
#include <revolution/os/OSTime.h>

[[gnu::constructor]]
static void initCallback() {
    nw4r::db::Exception_SetUserCallback(dException_c::callback, nullptr);
}

bool dException_c::callback(
    nw4r::db::ConsoleHandle console, [[maybe_unused]] void* userdata
) {
    // Suspend all excepted threads
    OSThreadQueue* threads = reinterpret_cast<OSThreadQueue*>(0x800000DC);
    for (OSThread* thread = threads->head; thread != nullptr; thread = thread->nextActive) {
        if (thread->context.state & 2) {
            OSSuspendThread(thread);
        }
    }

    OS_REPORT("nsmbw-project exception handler\n");

    dumpFile(console);

    return EGG::Exception::ExceptionCallback_(console, nullptr);
}

void dException_c::dumpFile(
    nw4r::db::ConsoleHandle console
) {
    char homeDir[64];
    if (NANDGetHomeDir(homeDir) != NAND_RESULT_OK) {
        OS_REPORT("Failed to get home dir\n");
        return;
    }

    const OSTime   time = OSGetTime();
    OSCalendarTime calendar;
    OSTicksToCalendarTime(time, &calendar);

    char fileName[64];
    if (int len = std::snprintf(
            fileName, std::size(fileName), "%s/crash-%04ld-%02ld-%02ld_%02ld.%02ld.%02ld.txt",
            homeDir, calendar.year, calendar.month, calendar.mday, calendar.hour, calendar.min,
            calendar.sec
        );
        len < 0 || len >= 64) {
        OS_REPORT("Format string is too large\n");
        return;
    }

    if (NANDCreate(fileName, 0x3C, 0) != NAND_RESULT_OK) {
        OS_REPORT("Failed to create file\n");
        return;
    }

    mNandFile_c nandFile;
    if (!nandFile.open(fileName, 2)) {
        OS_REPORT("Failed to open file\n");
        return;
    }

    alignas(32) unsigned char buffer[0x400];
    mPipe_c                   pipe(&nandFile, "w", &buffer, std::size(buffer));

    int                       lineCount = nw4r::db::Console_GetTotalLines(console);
    for (int line = 0; line < lineCount - 1; line++) {
        const u8* textBuf = &console->textBuf[(console->width + 1) * line + 0];
        std::fprintf(pipe, "%s\n", textBuf);
    }

    std::fprintf(
        pipe, "---BASE_CONNECT_DUMP---\n"
              "-------------------------------- BASE\n"
    );

    dBaseDump::dumpAll(pipe);

    std::fprintf(pipe, "--------------------------------\n");
    std::fclose(pipe);
}
