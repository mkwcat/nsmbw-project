// d_cs_seq_mng.cpp
// NSMBW d_bases.text: 0x80914680 - 0x80915690

#include "d_cs_seq_mng.h"

#include "d_debug_option.h"
#include <revolution/os/OSError.h>
#include <slu/to_string.hpp>
#include <utility>

[[nsmbw(0x80914BD0)]]
void dCsSeqMng_c::resetCut();

[[nsmbw(0x809153F0)]]
bool dCsSeqMng_c::checkCutEndAll();

[[nsmbw(0x80915590)]]
void dCsSeqMng_c::executeCut() {
    cut_name_e name = GetCutName();
    if (name == cut_name_e::end) {
        resetCut();
        return;
    }

    if (name == cut_name_e::pause || !checkCutEndAll()) {
        return;
    }

    m_cutNow++;

    if (dDebugOpt::print_worldmap_demo) {
        name = GetCutName();
        OS_REPORT(
            "Cut: %d '%s' %d\n", std::to_underlying(name), slu::to_string(name), GetCutArg0()
        );
    }
}

[[nsmbw(0x80915600)]]
bool dCsSeqMng_c::UNDEF_80915600();

[[nsmbw(0x80915630)]]
u32 dCsSeqMng_c::UNDEF_80915630();
