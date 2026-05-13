#pragma once

#include "db_console.h"

namespace nw4r::db {

[[nsmbw(0x80235810)]]
void Exception_SetUserCallback(bool (*)(ConsoleHandle, void*), void*);

} // namespace nw4r::db
