// d_exception.cpp
// nsmbw-project

#include "d_exception.h"

#include "d_base_dump.h"
#include "d_system/d_system.h"
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
#include <variant>

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
    std::variant<nw4r::db::ConsoleHandle, AssertInfo_s> info
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

    std::fprintf(
        pipe,
        "########### %s encountered a fatal error ###########\r\n"
        "\r\n"
        "Please submit this file under the relevant issue at\r\n"
        "%s\r\n"
        "or create a new issue if a relevant entry does not already exist.\r\n"
        "\r\n"
        "---Version Info---\r\n"
        "%s\r\n" // nsmbw-project version
        "%s\r\n" // Game revision string
        "\r\n",
        c_projectName, c_issueUrl, getProjectVersion(), getRegionInfo()
    );

    if (std::holds_alternative<nw4r::db::ConsoleHandle>(info)) {
        std::fprintf(
            pipe, "---nw4r::db Exception Report---\r\n"
                  "```\r\n"
        );
        auto& console   = std::get<nw4r::db::ConsoleHandle>(info);
        int   lineCount = nw4r::db::Console_GetTotalLines(console);
        for (int line = 0; line < lineCount - 1; line++) {
            const u8* textBuf = &console->textBuf[(console->width + 1) * line + 0];
            std::fprintf(pipe, "%s\r\n", textBuf);
        }
        std::fprintf(
            pipe, "```\r\n"
                  "\r\n"
        );
    } else if (std::holds_alternative<AssertInfo_s>(info)) {
        const auto& assertInfo = std::get<AssertInfo_s>(info);
        std::fprintf(
            pipe,
            "---Assertion failed---\r\n"
            "At:   %s:%d\r\n"
            "With: (%s)\r\n"
            "\r\n",
            assertInfo.file, assertInfo.line, assertInfo.expr
        );

        std::fprintf(pipe, "---Back trace---\r\n");
        printTrace(pipe, __builtin_frame_address(0));
        std::fprintf(pipe, "\r\n");
    }

    std::fprintf(
        pipe, "---Thread listing---\r\n"
              "\r\n"
    );

    OSThreadQueue* threads = reinterpret_cast<OSThreadQueue*>(0x800000DC);
    int            i       = 0;
    for (OSThread* thread = threads->head; thread != nullptr; thread = thread->nextActive, i++) {
        std::fprintf(
            pipe,
            "-----Thread %d-----\r\n"
            "At:      0x%08lX\r\n"
            "State:   0x%04X",
            i, reinterpret_cast<std::size_t>(&thread), thread->state
        );

        const char* stateName = nullptr;
        switch (thread->state) {
        case OS_THREAD_STATE_EXITED:
            stateName = "EXITED";
            break;
        case OS_THREAD_STATE_READY:
            stateName = "READY";
            break;
        case OS_THREAD_STATE_RUNNING:
            stateName = "RUNNING";
            break;
        case OS_THREAD_STATE_SLEEPING:
            stateName = "SLEEPING";
            break;
        case OS_THREAD_STATE_MORIBUND:
            stateName = "MORIBUND";
            break;
        }

        if (stateName) {
            std::fprintf(pipe, "    (%s)\r\n", stateName);
        } else {
            std::fprintf(pipe, "\r\n");
        }

        std::fprintf(
            pipe,
            "Prio:    %lu (%lu)\r\n"
            "Suspend: %ld\r\n"
            "Flags:   0x%04X\r\n"
            "Stack:   0x%08lX - 0x%08lX\r\n", //
            thread->base, thread->priority,   //
            thread->suspend,                  //
            thread->flags,                    //
            reinterpret_cast<std::size_t>(thread->stackBegin),
            reinterpret_cast<std::size_t>(thread->stackEnd)
        );

        std::fprintf(
            pipe,
            "-------Context-------\r\n"
            "SRR0:    0x%08lX   SRR1: 0x%08lX\r\n"
            "LR:      0x%08lX   CTR:  0x%08lX\r\n"
            "CR:      0x%08lX   XER:  0x%08lX\r\n"
            "State:   0x%04X       Mode: 0x%04X\r\n",   //
            thread->context.srr0, thread->context.srr1, //
            thread->context.lr, thread->context.ctr,    //
            thread->context.cr, thread->context.xer,    //
            thread->context.state, thread->context.mode
        );

        const u32* const gpr = thread->context.gprs;
        std::fprintf(
            pipe,
            "-------GPR listing-------\r\n"
            "R00: 0x%08lX  R11: 0x%08lX  R22: 0x%08lX\r\n"
            "R01: 0x%08lX  R12: 0x%08lX  R23: 0x%08lX\r\n"
            "R02: 0x%08lX  R13: 0x%08lX  R24: 0x%08lX\r\n"
            "R03: 0x%08lX  R14: 0x%08lX  R25: 0x%08lX\r\n"
            "R04: 0x%08lX  R15: 0x%08lX  R26: 0x%08lX\r\n"
            "R05: 0x%08lX  R16: 0x%08lX  R27: 0x%08lX\r\n"
            "R06: 0x%08lX  R17: 0x%08lX  R28: 0x%08lX\r\n"
            "R07: 0x%08lX  R18: 0x%08lX  R29: 0x%08lX\r\n"
            "R08: 0x%08lX  R19: 0x%08lX  R30: 0x%08lX\r\n"
            "R09: 0x%08lX  R20: 0x%08lX  R31: 0x%08lX\r\n"
            "R10: 0x%08lX  R21: 0x%08lX\r\n",
            gpr[0], gpr[11], gpr[22], //
            gpr[1], gpr[12], gpr[23], //
            gpr[2], gpr[13], gpr[24], //
            gpr[3], gpr[14], gpr[25], //
            gpr[4], gpr[15], gpr[26], //
            gpr[5], gpr[16], gpr[27], //
            gpr[6], gpr[17], gpr[28], //
            gpr[7], gpr[18], gpr[29], //
            gpr[8], gpr[19], gpr[30], //
            gpr[9], gpr[20], gpr[31], //
            gpr[10], gpr[21]
        );

        std::fprintf(pipe, "-------Back trace-------\r\n");
        printTrace(pipe, reinterpret_cast<void*>(gpr[1]));
        std::fprintf(pipe, "\r\n");
    }

    std::fprintf(
        pipe, "\r\n"
              "---Base object listing---\r\n"
              "\r\n"
    );

    dBaseDump::dumpAll(pipe);

    std::fprintf(
        pipe, "\r\n"
              "#################################\r\n"
    );
    std::fclose(pipe);
}

const char* dException_c::getRegionInfo() {
    switch (dSys_c::m_codeRegion) {
    default:
        return "Unknown";

    case mkwcat::Region::P1:
        return "PAL Rev 1";
    case mkwcat::Region::P2:
        return "PAL Rev 2";

    case mkwcat::Region::E1:
        return "USA Rev 1";
    case mkwcat::Region::E2:
        return "USA Rev 2";

    case mkwcat::Region::J1:
        return "JPN Rev 1";
    case mkwcat::Region::J2:
        return "JPN Rev 2";

    case mkwcat::Region::K:
        return "KOR";

    case mkwcat::Region::W:
        return "TWN";

    case mkwcat::Region::C:
        return "CHN";
    }
}

const char* dException_c::getProjectVersion() {
    return "nsmbw-project unreported version";
}

[[gnu::noinline]]
void dException_c::printTrace(
    std::FILE* file, void* stackPtr
) {
    std::fprintf(file, "Address:     Back Chain  LR Save\r\n");

    bool first = true;
    for (void** stack = checkStackAddr(stackPtr); stack != nullptr;
         stack        = checkStackAddr(stack[0])) {
        if (first) {
            std::fprintf(
                file, "0x%08X:  0x%08X  ----------\r\n", reinterpret_cast<unsigned>(stack),
                reinterpret_cast<unsigned>(stack[0])
            );
            first = false;
        } else {
            std::fprintf(
                file, "0x%08X:  0x%08X  0x%08X\r\n", reinterpret_cast<unsigned>(stack),
                reinterpret_cast<unsigned>(stack[0]), reinterpret_cast<unsigned>(stack[1])
            );
        }
    }
}

void** dException_c::checkStackAddr(
    void* stackPtr
) {
    u32 stackAddr = reinterpret_cast<u32>(stackPtr);

    if ((stackAddr >= 0x80003F00 && stackAddr <= 0x817FFFF8) ||
        (stackAddr >= 0x90000020 && stackAddr <= 0x935FFFF8)) {
        return static_cast<void**>(stackPtr);
    }

    return nullptr;
}
