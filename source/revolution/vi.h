#pragma once

#include "revolution/types.h"

EXTERN_C_START

void VIInit(void);

void VISetBlack(BOOL);

int VIEnableDimming(int enable);

bool __VIResetSIIdle();

EXTERN_C_END
