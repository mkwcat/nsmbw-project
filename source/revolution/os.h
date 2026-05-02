#pragma once

#include "os/OSCache.h"
#include "os/OSContext.h"
#include "os/OSError.h"
#include "os/OSFatal.h"
#include "os/OSInterrupt.h"
#include "os/OSLink.h"
#include "os/OSMutex.h"
#include "os/OSReset.h"
#include "os/OSRtc.h"
#include "os/OSThread.h"
#include "os/OSTime.h"

EXTERN_C_START

void OSRegisterVersion(const char* string);

EXTERN_C_END
