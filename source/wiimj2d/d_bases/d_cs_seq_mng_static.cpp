// d_cs_seq_mng_static.cpp
// NSMBW .text: 0x801016B0 - 0x801018C0

#include "d_cs_seq_mng.h"

[[nsmbw_data(0x8042A48C)]]
dCsSeqMng_c* dCsSeqMng_c::ms_instance;

[[nsmbw(0x801017C0)]]
bool dCsSeqMng_c::addScriptToQueue(u32 id, void*, void*, u32);
