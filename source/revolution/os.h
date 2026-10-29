#pragma once

#include "revolution/os/OSCache.h"
#include "revolution/os/OSContext.h"
#include "revolution/os/OSError.h"
#include "revolution/os/OSFastCast.h"
#include "revolution/os/OSFatal.h"
#include "revolution/os/OSInterrupt.h"
#include "revolution/os/OSLink.h"
#include "revolution/os/OSMessage.h"
#include "revolution/os/OSMutex.h"
#include "revolution/os/OSReset.h"
#include "revolution/os/OSRtc.h"
#include "revolution/os/OSThread.h"
#include "revolution/os/OSTime.h"

EXTERN_C_START

void OSRegisterVersion(const char* string);

EXTERN_C_END
