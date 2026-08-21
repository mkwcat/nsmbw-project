// d_course_data.cpp
// NSMBW .text: 0x8008DFF0 - 0x8008ECC0

#include "d_course_data.h"

[[nsmbw(0x8005EE70)]]
dCdFile_c* dCd_c::getFileP(int course);

[[nsmbw(0x8008E3D0)]]
dCdFile_c::NextGoto_s* dCdFile_c::getNextGotoP(u8);

[[nsmbw_data(0x8042A178)]]
dCd_c* dCd_c::m_instance;