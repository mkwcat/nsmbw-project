// d_cs_seq_mng_static.cpp
// NSMBW .text: 0x801016B0 - 0x801018C0

#include "d_cs_seq_mng.h"

#include "d_debug_option.h"
#include <revolution/os/OSError.h>
#include <slu/to_string.hpp>

[[nsmbw_data(0x8042A48C)]]
dCsSeqMng_c* dCsSeqMng_c::ms_instance;

[[nsmbw(0x801016F0)]]
dCsSeqMng_c::cut_name_e dCsSeqMng_c::GetCutName();

[[nsmbw(0x80101740)]]
int dCsSeqMng_c::GetCutArg0();

[[nsmbw(0x80101780)]]
void dCsSeqMng_c::order_c::init();

[[nsmbw(0x801017A0)]]
void dCsSeqMng_c::order_c::set(
    demo_name_e demo, dWmDemoActor_c* actor1, dWmDemoActor_c* actor2, int priority
);

[[nsmbw(0x801017C0)]]
bool dCsSeqMng_c::requestNextDemo(
    demo_name_e demo, dWmDemoActor_c* actor1, dWmDemoActor_c* actor2, int priority
) {
    if (dDebugOpt::print_worldmap_demo) {
        OS_REPORT(
            "Schedule demo '%s' from %p\n", slu::to_string(demo), __builtin_return_address(0)
        );
    }
    for (auto& order : m_order) {
        if (order.m_demo < demo_name_e::default_clr) {
            order.set(demo, actor1, actor2, priority);
            return true;
        }
    }
    return false;
}
