// d_SelectCursor.cpp
// NSMBW .text: 0x8010C130 - 0x8010CAE0

#include "d_SelectCursor.h"

[[nsmbw_data(0x8042A5A8)]]
dSelectCursor_c* dSelectCursor_c::m_instance;

[[nsmbw(0x8010C890)]]
void dSelectCursor_c::Cancel(int param);